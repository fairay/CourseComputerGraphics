# Анимация в pygame

import pygame
import sys
import random
import time
from math import *


xy_size = [1000, 600]
fps = 120
rotation_speed = radians(120 / fps)

# Цвета
code16 = {'0': 0, '1': 1, '2': 2, '3': 3, '4': 4, '5': 5, '6': 6, '7': 7,
          '8': 8, '9': 9, 'a': 10, 'b': 11, 'c': 12, 'd': 13, 'e': 14, 'f': 15}


def trans_color(code):
    r = code16[code[1]] * 16 + code16[code[2]]
    g = code16[code[3]] * 16 + code16[code[4]]
    b = code16[code[5]] * 16 + code16[code[6]]
    return (r, g, b)


bg_color = trans_color('#67e6dc')


pygame.init()
screen = pygame.display.set_mode(xy_size)
clock = pygame.time.Clock()

bg = pygame.Surface(xy_size)
bg.fill(bg_color)
screen.blit(bg, (0, 0))
pygame.display.update()


class Ball:
    r = 20
    x, y = 0, 0
    dx, dy = 0, 0
    mu = 1
    surf = None
    rect = None
    color = (200, 0, 0)

    def __init__(self, x, y, dx, dy):
        self.x, self.y = x, y
        self.dx, self.dy = dx, dy
        
        self.surf = pygame.Surface([self.r*2, self.r*2],pygame.SRCALPHA)
        # self.surf.fill(bg_color)
        self.surf.set_colorkey(bg_color)
        pygame.draw.circle(self.surf, self.color,
                           (self.r, self.r), self.r, self.r)
        self.rect = self.surf.get_rect(center=[self.x, self.y])
        
    def get_pos(self):
        return [self.x, self.y]
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

    def apply_borders(self, min_pos, max_pos):
        x_l = min_pos[0]
        x_r = max_pos[0]
        if self.x <= x_l + self.r:
            self.dx = -self.dx
            self.x += 2*(x_l+self.r - self.x)
        elif self.x >= x_r - self.r:
            self.dx = -self.dx
            self.x += 2*(x_r-self.r - self.x)

        y_d = min_pos[1]
        y_u = max_pos[1]

        if self.y <= y_d + self.r:
            self.dy = -self.dy
            self.y += 2*(y_d+self.r - self.y)
        elif self.y >= y_u - self.r:
            self.dy = -self.dy
            self.y += 2*(y_u-self.r - self.y)

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
    ball = Ball(100, xy_size[1]//2, 250, 0*random.randint(-40, 40))
    arr.append(ball)

    r = Ball.r
    st = xy_size[0]//7*5
    for i in range(5):
        for j in range(i+1):
            arr.append(Ball(st+i*sqrt(3)*r, xy_size[1]//2 - i*r + 2*j*r, 0, 0))
            #arr.append(Ball(st+i*sqrt(3)*r + i*5, xy_size[1]//2 - i*r + 2.1*j*r, 0, 0))
    
    return arr

balls = []
for i in range(20):
    flag = True
    while flag:
        flag = False
        ball = Ball(random.randint(30, xy_size[0]-30),
                    random.randint(30, xy_size[1]-30),
                    #random.randint(-40, 40), random.randint(-40, 40))
                    random.randint(-0, 0), random.randint(-0, 0))
        
        for other in balls:
            if ball.is_collide(other):
                flag = True
                break
    balls.append(ball)
balls[0].set_speed(random.randint(-200, 200), random.randint(-100, 100))


balls = billiard_start()
random.shuffle(balls)
# balls.append(Ball(100, 100, random.randint(-100, 100), random.randint(-100, 100)))

t = time.time()
while True:
    event_list = pygame.event.get()
    for event in event_list:
        if event.type == pygame.QUIT:
            pygame.quit()
            sys.exit()
    
    dt = time.time() - t
    t = time.time()
    

    pygame.display.update()

    screen.blit(bg, (0, 0))
    
    for ball in balls:
        ball.update(dt)
        ball.apply_borders((0, 0), xy_size)

    for i in range(len(balls)):
        for j in range(i+1, len(balls)):
            balls[i].collide(balls[j])

    for ball in balls:
        ball.draw(screen)
    
    clock.tick(fps)
