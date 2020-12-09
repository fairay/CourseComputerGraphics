/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDial>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGraphicsView *graphicsView;
    QPushButton *pushButton;
    QLabel *fps_count;
    QLabel *label;
    QFrame *cam_frame;
    QPushButton *cam_label;
    QPushButton *cam_info;
    QPushButton *cam_move_f;
    QPushButton *cam_move_b;
    QPushButton *cam_move_r;
    QPushButton *cam_move_l;
    QPushButton *cam_rot_l;
    QPushButton *cam_rot_r;
    QPushButton *cam_rot_u;
    QPushButton *cam_rot_d;
    QPushButton *cam_move_u;
    QPushButton *cam_move_d;
    QFrame *line;
    QFrame *line_2;
    QFrame *lig_frame;
    QPushButton *lig_label;
    QPushButton *lig_info;
    QPushButton *lig_move_f;
    QPushButton *lig_move_b;
    QPushButton *lig_move_r;
    QPushButton *lig_move_l;
    QDial *lig_i;
    QPushButton *lig_move_u;
    QPushButton *lig_move_d;
    QFrame *line_3;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1130, 665);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(10, 10, 800, 600));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(830, 560, 291, 41));
        fps_count = new QLabel(centralWidget);
        fps_count->setObjectName(QString::fromUtf8("fps_count"));
        fps_count->setGeometry(QRect(880, 530, 121, 20));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(830, 530, 35, 21));
        cam_frame = new QFrame(centralWidget);
        cam_frame->setObjectName(QString::fromUtf8("cam_frame"));
        cam_frame->setGeometry(QRect(820, 10, 301, 201));
        cam_frame->setFrameShape(QFrame::StyledPanel);
        cam_frame->setFrameShadow(QFrame::Raised);
        cam_label = new QPushButton(cam_frame);
        cam_label->setObjectName(QString::fromUtf8("cam_label"));
        cam_label->setGeometry(QRect(0, 0, 241, 61));
        cam_info = new QPushButton(cam_frame);
        cam_info->setObjectName(QString::fromUtf8("cam_info"));
        cam_info->setGeometry(QRect(250, 0, 41, 61));
        cam_move_f = new QPushButton(cam_frame);
        cam_move_f->setObjectName(QString::fromUtf8("cam_move_f"));
        cam_move_f->setGeometry(QRect(50, 70, 40, 40));
        QFont font;
        font.setPointSize(12);
        cam_move_f->setFont(font);
        cam_move_b = new QPushButton(cam_frame);
        cam_move_b->setObjectName(QString::fromUtf8("cam_move_b"));
        cam_move_b->setGeometry(QRect(50, 150, 40, 40));
        cam_move_b->setFont(font);
        cam_move_r = new QPushButton(cam_frame);
        cam_move_r->setObjectName(QString::fromUtf8("cam_move_r"));
        cam_move_r->setGeometry(QRect(90, 110, 40, 40));
        cam_move_r->setFont(font);
        cam_move_l = new QPushButton(cam_frame);
        cam_move_l->setObjectName(QString::fromUtf8("cam_move_l"));
        cam_move_l->setGeometry(QRect(10, 110, 40, 40));
        cam_move_l->setFont(font);
        cam_rot_l = new QPushButton(cam_frame);
        cam_rot_l->setObjectName(QString::fromUtf8("cam_rot_l"));
        cam_rot_l->setGeometry(QRect(180, 110, 40, 40));
        cam_rot_l->setFont(font);
        cam_rot_r = new QPushButton(cam_frame);
        cam_rot_r->setObjectName(QString::fromUtf8("cam_rot_r"));
        cam_rot_r->setGeometry(QRect(260, 110, 40, 40));
        cam_rot_r->setFont(font);
        cam_rot_u = new QPushButton(cam_frame);
        cam_rot_u->setObjectName(QString::fromUtf8("cam_rot_u"));
        cam_rot_u->setGeometry(QRect(220, 70, 40, 40));
        cam_rot_u->setFont(font);
        cam_rot_d = new QPushButton(cam_frame);
        cam_rot_d->setObjectName(QString::fromUtf8("cam_rot_d"));
        cam_rot_d->setGeometry(QRect(220, 150, 40, 40));
        cam_rot_d->setFont(font);
        cam_move_u = new QPushButton(cam_frame);
        cam_move_u->setObjectName(QString::fromUtf8("cam_move_u"));
        cam_move_u->setGeometry(QRect(140, 70, 31, 61));
        QFont font1;
        font1.setPointSize(25);
        cam_move_u->setFont(font1);
        cam_move_d = new QPushButton(cam_frame);
        cam_move_d->setObjectName(QString::fromUtf8("cam_move_d"));
        cam_move_d->setGeometry(QRect(140, 130, 31, 61));
        cam_move_d->setFont(font1);
        line = new QFrame(centralWidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(815, 202, 311, 31));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(centralWidget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(800, 0, 30, 611));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);
        lig_frame = new QFrame(centralWidget);
        lig_frame->setObjectName(QString::fromUtf8("lig_frame"));
        lig_frame->setGeometry(QRect(820, 220, 301, 211));
        lig_frame->setFrameShape(QFrame::StyledPanel);
        lig_frame->setFrameShadow(QFrame::Raised);
        lig_label = new QPushButton(lig_frame);
        lig_label->setObjectName(QString::fromUtf8("lig_label"));
        lig_label->setGeometry(QRect(0, 0, 241, 71));
        lig_info = new QPushButton(lig_frame);
        lig_info->setObjectName(QString::fromUtf8("lig_info"));
        lig_info->setGeometry(QRect(250, 0, 41, 71));
        lig_move_f = new QPushButton(lig_frame);
        lig_move_f->setObjectName(QString::fromUtf8("lig_move_f"));
        lig_move_f->setGeometry(QRect(50, 80, 40, 40));
        lig_move_f->setFont(font);
        lig_move_b = new QPushButton(lig_frame);
        lig_move_b->setObjectName(QString::fromUtf8("lig_move_b"));
        lig_move_b->setGeometry(QRect(50, 160, 40, 40));
        lig_move_b->setFont(font);
        lig_move_r = new QPushButton(lig_frame);
        lig_move_r->setObjectName(QString::fromUtf8("lig_move_r"));
        lig_move_r->setGeometry(QRect(90, 120, 40, 40));
        lig_move_r->setFont(font);
        lig_move_l = new QPushButton(lig_frame);
        lig_move_l->setObjectName(QString::fromUtf8("lig_move_l"));
        lig_move_l->setGeometry(QRect(10, 120, 40, 40));
        lig_move_l->setFont(font);
        lig_i = new QDial(lig_frame);
        lig_i->setObjectName(QString::fromUtf8("lig_i"));
        lig_i->setGeometry(QRect(180, 80, 121, 111));
        lig_i->setMaximum(99);
        lig_i->setSingleStep(1);
        lig_i->setValue(75);
        lig_i->setOrientation(Qt::Horizontal);
        lig_move_u = new QPushButton(lig_frame);
        lig_move_u->setObjectName(QString::fromUtf8("lig_move_u"));
        lig_move_u->setGeometry(QRect(140, 80, 31, 61));
        lig_move_u->setFont(font1);
        lig_move_d = new QPushButton(lig_frame);
        lig_move_d->setObjectName(QString::fromUtf8("lig_move_d"));
        lig_move_d->setGeometry(QRect(140, 140, 31, 61));
        lig_move_d->setFont(font1);
        line_3 = new QFrame(centralWidget);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setGeometry(QRect(815, 420, 311, 31));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1130, 17));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\320\230\320\263\321\200\320\260 \320\221\320\270\320\273\321\214\321\217\321\200\320\264", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\274\320\265\321\200 FPS", nullptr));
        fps_count->setText(QApplication::translate("MainWindow", "0", nullptr));
        label->setText(QApplication::translate("MainWindow", "FPS:", nullptr));
        cam_label->setText(QApplication::translate("MainWindow", "\320\237\320\225\320\240\320\225\320\234\320\225\320\251\320\225\320\235\320\230\320\225, \320\222\320\240\320\220\320\251\320\225\320\235\320\230\320\225 \n"
" \320\232\320\220\320\234\320\225\320\240\320\253", nullptr));
        cam_info->setText(QApplication::translate("MainWindow", "?", nullptr));
        cam_move_f->setText(QApplication::translate("MainWindow", "\360\237\241\271", nullptr));
        cam_move_b->setText(QApplication::translate("MainWindow", "\360\237\241\273", nullptr));
        cam_move_r->setText(QApplication::translate("MainWindow", "\360\237\241\272", nullptr));
        cam_move_l->setText(QApplication::translate("MainWindow", "\360\237\241\270", nullptr));
        cam_rot_l->setText(QApplication::translate("MainWindow", "\342\206\266", nullptr));
        cam_rot_r->setText(QApplication::translate("MainWindow", "\342\206\267", nullptr));
        cam_rot_u->setText(QApplication::translate("MainWindow", "\342\244\244", nullptr));
        cam_rot_d->setText(QApplication::translate("MainWindow", "\342\244\246", nullptr));
        cam_move_u->setText(QApplication::translate("MainWindow", "\342\206\237", nullptr));
        cam_move_d->setText(QApplication::translate("MainWindow", "\342\206\241", nullptr));
        lig_label->setText(QApplication::translate("MainWindow", "\320\237\320\225\320\240\320\225\320\234\320\225\320\251\320\225\320\235\320\230\320\225 \n"
" \320\230\320\235\320\242\320\225\320\235\320\241\320\230\320\222\320\235\320\236\320\241\320\242\320\254 \n"
" \320\230\320\241\320\242\320\236\320\247\320\235\320\230\320\232\320\220 \320\236\320\241\320\222\320\225\320\251\320\225\320\235\320\230\320\257", nullptr));
        lig_info->setText(QApplication::translate("MainWindow", "?", nullptr));
        lig_move_f->setText(QApplication::translate("MainWindow", "\360\237\241\271", nullptr));
        lig_move_b->setText(QApplication::translate("MainWindow", "\360\237\241\273", nullptr));
        lig_move_r->setText(QApplication::translate("MainWindow", "\360\237\241\272", nullptr));
        lig_move_l->setText(QApplication::translate("MainWindow", "\360\237\241\270", nullptr));
        lig_move_u->setText(QApplication::translate("MainWindow", "\342\206\237", nullptr));
        lig_move_d->setText(QApplication::translate("MainWindow", "\342\206\241", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
