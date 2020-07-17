# Анимация в pygame

import pygame
import sys
import random
import time
from math import *


def dist(p1, p2):
    return sqrt((p1[0] - p2[0])**2 + (p1[1] - p2[1]) ** 2)


xy_size = [1000, 600]
fps = 120
bg_color = (19, 151, 114)
ball_r = 20

pygame.init()
pygame.display.set_caption('Игра "Бильярд"')
screen = pygame.display.set_mode(xy_size)
clock = pygame.time.Clock()

bg = pygame.Surface(xy_size)
bg.fill(bg_color)
screen.blit(bg, (0, 0))
pygame.display.update()


class Border:
    pos = [0, 0]
    size = [0, 0]
    color = (103, 52, 0)

    def __init__(self, pos=[0, 0], size=[1, 1]):
        self.pos = pos
        self.size = size

        self.surf = pygame.Surface(self.size)
        self.surf.set_colorkey(bg_color)
        self.rect = self.surf.get_rect(center=self.pos)
        rect = (0, 0, self.size[0], self.size[1])
        pygame.draw.rect(self.surf, self.color, rect)

    def get_left(self):
        return self.pos[0]-self.size[0]/2
    def get_right(self):
        return self.pos[0]+self.size[0]/2
    def get_up(self):
        return self.pos[1]+self.size[1]/2
    def get_down(self):
        return self.pos[1]-self.size[1]/2

    def get_lu_corner(self):
        return [self.pos[0] - self.size[0]/2, self.pos[1] - self.size[1]/2]

    def get_collision_point(self, x, y, r):
        point = [None, None]
        if self.is_inside(x + r, y):
            point[0] = self.pos[0] - self.size[0] / 2
            point[1] = y
        elif self.is_inside(x - r, y):
            point[0] = self.pos[0] + self.size[0] / 2
            point[1] = y
        elif self.is_inside(x, y + r):
            point[0] = x
            point[1] = self.pos[1] - self.size[1] / 2
        elif self.is_inside(x, y - r):
            point[0] = x
            point[1] = self.pos[1] + self.size[1] / 2

        else:
            for p in self.get_corners():
                if dist(p, (x, y)) < r:
                    point = p
                    break

        return point

    def get_corners(self):
        return [[self.pos[0] - self.size[0]/2, self.pos[1] - self.size[1]/2],
                [self.pos[0] - self.size[0]/2, self.pos[1] + self.size[1]/2],
                [self.pos[0] + self.size[0]/2, self.pos[1] - self.size[1]/2],
                [self.pos[0] + self.size[0]/2, self.pos[1] + self.size[1]/2]]

    def is_inside(self, x, y):
        return abs(self.pos[0] - x) < self.size[0]/2 and \
               abs(self.pos[1] - y) < self.size[1]/2

    def draw(self, sc):
        sc.blit(self.surf, self.rect)


class Ball:
    r = ball_r
    x, y = 0, 0
    dx, dy = 0, 0
    mu = 2
    surf = None
    rect = None
    # color = (200, 0, 0)
    color = (225, 226, 170)

    def __init__(self, x, y, dx, dy):
        self.x, self.y = x, y
        self.dx, self.dy = dx, dy
        
        self.surf = pygame.Surface([self.r*2, self.r*2], pygame.SRCALPHA)
        self.surf.set_colorkey(bg_color)
        pygame.draw.circle(self.surf, self.color,
                           (self.r, self.r), self.r, self.r)
        self.rect = self.surf.get_rect(center=[self.x, self.y])

    def set_color(self, color):
        self.color = color
        pygame.draw.circle(self.surf, self.color,
                           (self.r, self.r), self.r, self.r)

    def get_pos(self):
        return [self.x, self.y]
    def is_still(self):
        return self.dx + self.dy == 0
    def get_speed(self):
        return sqrt(self.dx**2 + self.dy**2)
    def get_speed_vector(self):
        return [self.dx, self.dy]
    def set_speed(self, dx, dy):
        self.dx = dx
        self.dy = dy
    
    def update(self, dt):
        speed = self.get_speed()
        if speed:
            self.x += dt*self.dx
            self.y += dt*self.dy

            slowdown = max(0, 1 - (dt*10*self.mu)/speed)
            self.dx *= slowdown
            self.dy *= slowdown

    def apply_screen_borders(self, min_pos, max_pos):
        x_l = min_pos[0]
        x_r = max_pos[0]
        if self.x <= x_l + self.r:
            self.dx = -self.dx
            self.x += 2*(x_l+self.r - self.x)
            return True
        elif self.x >= x_r - self.r:
            self.dx = -self.dx
            self.x += 2*(x_r-self.r - self.x)
            return True

        y_d = min_pos[1]
        y_u = max_pos[1]

        if self.y <= y_d + self.r:
            self.dy = -self.dy
            self.y += 2*(y_d+self.r - self.y)
            return True
        elif self.y >= y_u - self.r:
            self.dy = -self.dy
            self.y += 2*(y_u-self.r - self.y)
            return True
        return False

    def apply_border(self, border):
        x, y = border.get_collision_point(self.x, self.y, self.r)
        if x is None or y is None: return

        d = dist((self.x, self.y), (x, y))
        a = self.x - x
        b = self.y - y
        print("Collide!", a, b)

        p1 = a * b / (d ** 2)
        p2 = (a / d) ** 2
        p3 = (b / d) ** 2

        d1 = self.dy * p1 + self.dx * p2
        d2 = self.dx * p1 + self.dy * p3

        self.dx = self.dx - d1*2
        self.dy = self.dy - d2*2

        # Решение коллизии
        p3 = (self.r - d)
        p1 = p3 * (a / d)
        p2 = p3 * (b / d)

        self.x = self.x + p1
        self.y = self.y + p2

        """
        if border.is_inside(self.x + self.r, self.y):
            self.dx = -self.dx
            self.x += 2 * (border.get_left() - self.r - self.x)
        elif border.is_inside(self.x - self.r, self.y):
            self.dx = -self.dx
            self.x += 2 * (border.get_right() + self.r - self.x)
        elif border.is_inside(self.x, self.y + self.r):
            self.dy = -self.dy
            self.y += 2 * (border.get_down() - self.r - self.y)
        elif border.is_inside(self.x, self.y - self.r):
            self.dy = -self.dy
            self.y += 2 * (border.get_up() + self.r - self.y)
        else:
            x, y = border.get_lu_corner()
            dist = sqrt((self.x - x)**2 + (self.y - y)**2)
            if dist < self.r:
                print("Collide!")
                a = self.x - x
                b = self.y - y

                p1 = a * b / (dist ** 2)
                p2 = (a / dist) ** 2
                p3 = (b / dist) ** 2

                d1 = self.dy * p1 + self.dx * p2
                d2 = self.dx * p1 + self.dy * p3

                self.dx = self.dx - d1
                self.dy = self.dy - d2

                # Решение коллизии
                p3 = (self.r - dist)
                p1 = p3 * (a / dist)
                p2 = p3 * (b / dist)

                self.x = self.x + p1
                self.y = self.y + p2
        """


    def dist(self, other):
        return sqrt((self.x - other.x)**2 + (self.y - other.y)**2)
    def is_collide(self, other):
        return self.dist(other) <= self.r*2
    def collide(self, other):
        dist = self.dist(other)
        if self.is_collide(other):
            v_self = self.get_speed()
            v_other = other.get_speed()
            
            a = self.x - other.x
            b = self.y - other.y

            if v_self + v_other > 1e-5:
                p1 = a*b / (dist**2)
                p2 = (a/dist)**2
                p3 = (b/dist)**2

                d1 = self.dy*p1 + self.dx*p2 - other.dy*p1 - other.dx*p2
                d2 = self.dx*p1 + self.dy*p3 - other.dx*p1 - other.dy*p3
                
                self.dx = self.dx - d1
                self.dy = self.dy - d2
                other.dx = other.dx + d1
                other.dy = other.dy + d2

            # Решение коллизии
            p3 = (self.r*2-dist)
            p1 = p3*(a/dist)
            p2 = p3*(b/dist)
            if v_self + v_other:    k = v_self / (v_self + v_other)
            else: k = 1/2
            
            self.x = self.x + p1 * k
            self.y = self.y + p2 * k
            other.x = other.x - p1 * (1-k)
            other.y = other.y - p2 * (1-k)
            
    
    def draw(self, sc):
        self.rect = self.surf.get_rect(center=[self.x, self.y])
        sc.blit(self.surf, self.rect)


def billiard_start():
    arr = []
    ball = Ball(100, xy_size[1]//2, 0, 0)
    ball.set_color((115, 6, 14))
    arr.append(ball)

    r = Ball.r
    st = xy_size[0]//7*5
    for i in range(5):
        for j in range(i+1):
            arr.append(Ball(st+i*sqrt(3)*r, xy_size[1]//2 - i*r + 2*j*r, 0, 0))
            #arr.append(Ball(st+i*sqrt(3)*r + i*5, xy_size[1]//2 - i*r + 2.1*j*r, 0, 0))

    # random.shuffle(arr)
    return arr
def random_start():
    balls = []
    for i in range(20):
        flag = True
        while flag:
            flag = False
            ball = Ball(random.randint(30, xy_size[0] - 30),
                        random.randint(30, xy_size[1] - 30),
                        # random.randint(-40, 40), random.randint(-40, 40))
                        random.randint(-0, 0), random.randint(-0, 0))

            for other in balls:
                if ball.is_collide(other):
                    flag = True
                    break
        balls.append(ball)
    balls[0].set_speed(random.randint(-200, 200), random.randint(-100, 100))
    return balls
def test_start():
    balls = []
    balls.append(Ball(800, 429, 72, -79))
    return balls


def default_borders():
    arr = []
    wide = 25
    gap = 2*ball_r * 1.15

    v_size = xy_size[1] - 2*(gap*sqrt(2)/2 + wide)
    arr.append(Border((xy_size[0] - wide // 2, 300), (wide, v_size)))
    arr.append(Border((wide // 2, 300), (wide, v_size)))

    h_size = xy_size[0] / 2 - gap/2 - (gap*sqrt(2)/2 + wide)
    h_indent = gap/2 + h_size/2
    arr.append(Border((500-h_indent, wide // 2), (h_size, wide)))
    arr.append(Border((500+h_indent, wide // 2), (h_size, wide)))
    arr.append(Border((500-h_indent, xy_size[1] - wide // 2), (h_size, wide)))
    arr.append(Border((500+h_indent, xy_size[1] - wide // 2), (h_size, wide)))
    # arr.append(Border((xy_size[0] - wide // 2 - 50, 450), (wide, 260)))
    return arr


def is_balls_still(ball_arr):
    for ball in ball_arr:
        if not ball.is_still():
            return False
    return True


balls = billiard_start()
borders = default_borders()

t = time.time()
time_speed = 1.0
time_boost = 1.5

while True:
    pos = pygame.mouse.get_pos()
    event_list = pygame.event.get()
    for event in event_list:
        if event.type == pygame.QUIT:
            pygame.quit()
            sys.exit()

        elif event.type == pygame.KEYDOWN:
            if event.key == pygame.K_PAGEUP:
                time_speed *= time_boost
                print("Time speed:", time_speed)
            elif event.key == pygame.K_PAGEDOWN:
                time_speed /= time_boost
                print("Time speed:", time_speed)

        elif event.type == pygame.MOUSEBUTTONDOWN:
            print(pos)
            if is_balls_still(balls):
                d = dist(pos, balls[0].get_pos())
                v = d * 1.1

                dx = v * ((pos[0] - balls[0].get_pos()[0]) / d)
                dy = v * ((pos[1] - balls[0].get_pos()[1]) / d)
                balls[0].set_speed(dx, dy)
                print("Hit! Velocity = ", dx, dy)

    bg.fill(bg_color)
    if is_balls_still(balls):
        pygame.draw.line(bg, (0, 20, 100), balls[0].get_pos(), pos, 3)

    dt = time.time() - t
    t = time.time()

    pygame.display.update()

    screen.blit(bg, (0, 0))
    
    for ball in balls:
        ball.update(dt*time_speed)
        if ball.apply_screen_borders((0, 0), xy_size):
            balls.remove(ball)
        for bord in borders:
            ball.apply_border(bord)

    for i in range(len(balls)):
        for j in range(i+1, len(balls)):
            balls[i].collide(balls[j])

    for ball in balls:
        ball.draw(screen)
    for bord in borders:
        bord.draw(screen)
    
    clock.tick(fps)
