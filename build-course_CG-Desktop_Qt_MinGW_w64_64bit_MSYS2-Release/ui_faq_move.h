/********************************************************************************
** Form generated from reading UI file 'faq_move.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FAQ_MOVE_H
#define UI_FAQ_MOVE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_FAQ_Move
{
public:
    QPushButton *pushButton;
    QFrame *frame;
    QPushButton *cam_move_r;
    QPushButton *cam_move_d;
    QPushButton *cam_move_b;
    QPushButton *cam_move_f;
    QPushButton *cam_move_l;
    QPushButton *cam_move_u;
    QLabel *label;
    QFrame *frame_2;
    QPushButton *cam_rot_d;
    QPushButton *cam_rot_l;
    QPushButton *cam_rot_u;
    QPushButton *cam_rot_r;
    QLabel *label_2;
    QFrame *line;

    void setupUi(QDialog *FAQ_Move)
    {
        if (FAQ_Move->objectName().isEmpty())
            FAQ_Move->setObjectName(QString::fromUtf8("FAQ_Move"));
        FAQ_Move->resize(522, 399);
        FAQ_Move->setModal(true);
        pushButton = new QPushButton(FAQ_Move);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(10, 340, 501, 51));
        frame = new QFrame(FAQ_Move);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(10, 20, 501, 141));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        cam_move_r = new QPushButton(frame);
        cam_move_r->setObjectName(QString::fromUtf8("cam_move_r"));
        cam_move_r->setGeometry(QRect(120, 0, 40, 40));
        QFont font;
        font.setPointSize(12);
        cam_move_r->setFont(font);
        cam_move_d = new QPushButton(frame);
        cam_move_d->setObjectName(QString::fromUtf8("cam_move_d"));
        cam_move_d->setGeometry(QRect(200, 0, 41, 41));
        QFont font1;
        font1.setPointSize(25);
        cam_move_d->setFont(font1);
        cam_move_b = new QPushButton(frame);
        cam_move_b->setObjectName(QString::fromUtf8("cam_move_b"));
        cam_move_b->setGeometry(QRect(40, 0, 40, 40));
        cam_move_b->setFont(font);
        cam_move_f = new QPushButton(frame);
        cam_move_f->setObjectName(QString::fromUtf8("cam_move_f"));
        cam_move_f->setGeometry(QRect(0, 0, 40, 40));
        cam_move_f->setFont(font);
        cam_move_l = new QPushButton(frame);
        cam_move_l->setObjectName(QString::fromUtf8("cam_move_l"));
        cam_move_l->setGeometry(QRect(80, 0, 40, 40));
        cam_move_l->setFont(font);
        cam_move_u = new QPushButton(frame);
        cam_move_u->setObjectName(QString::fromUtf8("cam_move_u"));
        cam_move_u->setGeometry(QRect(160, 0, 41, 41));
        cam_move_u->setFont(font1);
        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 60, 481, 71));
        label->setScaledContents(false);
        frame_2 = new QFrame(FAQ_Move);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(10, 170, 501, 141));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        cam_rot_d = new QPushButton(frame_2);
        cam_rot_d->setObjectName(QString::fromUtf8("cam_rot_d"));
        cam_rot_d->setGeometry(QRect(50, 10, 40, 40));
        QFont font2;
        font2.setPointSize(15);
        font2.setBold(true);
        font2.setWeight(75);
        cam_rot_d->setFont(font2);
        cam_rot_l = new QPushButton(frame_2);
        cam_rot_l->setObjectName(QString::fromUtf8("cam_rot_l"));
        cam_rot_l->setGeometry(QRect(90, 10, 40, 40));
        cam_rot_l->setFont(font2);
        cam_rot_u = new QPushButton(frame_2);
        cam_rot_u->setObjectName(QString::fromUtf8("cam_rot_u"));
        cam_rot_u->setGeometry(QRect(10, 10, 40, 40));
        cam_rot_u->setFont(font2);
        cam_rot_r = new QPushButton(frame_2);
        cam_rot_r->setObjectName(QString::fromUtf8("cam_rot_r"));
        cam_rot_r->setGeometry(QRect(130, 10, 40, 40));
        cam_rot_r->setFont(font2);
        label_2 = new QLabel(frame_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(0, 60, 481, 71));
        line = new QFrame(FAQ_Move);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(0, 159, 521, 21));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        retranslateUi(FAQ_Move);

        QMetaObject::connectSlotsByName(FAQ_Move);
    } // setupUi

    void retranslateUi(QDialog *FAQ_Move)
    {
        FAQ_Move->setWindowTitle(QApplication::translate("FAQ_Move", "\320\240\320\260\320\261\320\276\321\202\320\260 \321\201 \320\272\320\260\320\274\320\265\321\200\320\276\320\271", nullptr));
        pushButton->setText(QApplication::translate("FAQ_Move", "\320\227\320\260\320\272\321\200\321\213\321\202\321\214", nullptr));
        cam_move_r->setText(QApplication::translate("FAQ_Move", "\360\237\241\272", nullptr));
        cam_move_d->setText(QApplication::translate("FAQ_Move", "\342\206\241", nullptr));
        cam_move_b->setText(QApplication::translate("FAQ_Move", "\360\237\241\273", nullptr));
        cam_move_f->setText(QApplication::translate("FAQ_Move", "\360\237\241\271", nullptr));
        cam_move_l->setText(QApplication::translate("FAQ_Move", "\360\237\241\270", nullptr));
        cam_move_u->setText(QApplication::translate("FAQ_Move", "\342\206\237", nullptr));
        label->setText(QApplication::translate("FAQ_Move", "\320\241\321\202\321\200\320\265\320\273\320\272\320\270 \321\201\320\273\321\203\320\266\320\260\321\202 \320\264\320\273\321\217 \320\270\320\267\320\274\320\265\320\275\320\265\320\275\320\270\321\217 \320\277\320\276\320\267\320\270\321\206\320\270\320\270 \320\272\320\260\320\274\320\265\321\200\321\213. \n"
"\320\236\320\275\320\270 \320\262\321\213\320\267\321\213\320\262\320\260\321\216\321\202 \320\277\320\265\321\200\320\265\320\274\320\265\321\211\320\265\320\275\320\270\320\265 \320\272\320\260\320\274\320\265\321\200\321\213 \320\262\320\277\320\265\321\200\321\221\320\264, \320\275\320\260\320\267\320\260\320\264, \320\262\320\277\321\200\320\260\320\262\320\276, \n"
"\320\262\320\273\320\265\320\262\320\276, \320\262\320\262\320\265\321\200\321\205 \320\270 \320\262\320\275\320\270\320\267 \321\201\320\276\320\276\321\202\320\262. \n"
"\320\235\320\260\320\277\321\200\320\260\320\262\320\273\320\265\320\275\320\270\321\217 \321\201\321\207\320\270\321\202\320\260\321\216\321\202\321\201\321\217 "
                        "\320\276\321\202\320\275\320\276\321\201\320\270\321\202\320\265\320\273\321\214\320\275\320\276 \320\275\320\260\320\277\321\200\320\260\320\262\320\273\320\265\320\275\320\270\320\265 \320\262\320\267\320\263\320\273\321\217\320\264\320\260", nullptr));
        cam_rot_d->setText(QApplication::translate("FAQ_Move", "\342\244\246", nullptr));
        cam_rot_l->setText(QApplication::translate("FAQ_Move", "\342\206\266", nullptr));
        cam_rot_u->setText(QApplication::translate("FAQ_Move", "\342\244\244", nullptr));
        cam_rot_r->setText(QApplication::translate("FAQ_Move", "\342\206\267", nullptr));
        label_2->setText(QApplication::translate("FAQ_Move", "\320\241\321\202\321\200\320\265\320\273\320\272\320\270 \321\201\320\273\321\203\320\266\320\260\321\202 \320\264\320\273\321\217 \320\270\320\267\320\274\320\265\320\275\320\265\320\275\320\270\321\217 \320\262\320\265\320\272\321\202\320\276\321\200\320\260 \320\262\320\267\320\273\321\217\320\264\320\260. \n"
"\320\236\320\275\320\270 \320\262\321\213\320\267\321\213\320\262\320\260\321\216\321\202 \320\277\320\276\320\262\320\276\321\200\320\276\321\202 \320\272\320\260\320\274\320\265\321\200\321\213 \320\262\320\262\320\265\321\200\321\205, \320\262\320\275\320\270\320\267 \320\262\320\273\320\265\320\262\320\276 \320\270 \n"
"\320\262\320\277\321\200\320\260\320\262\320\276 \321\201\320\276\320\276\321\202\320\262.", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FAQ_Move: public Ui_FAQ_Move {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FAQ_MOVE_H
