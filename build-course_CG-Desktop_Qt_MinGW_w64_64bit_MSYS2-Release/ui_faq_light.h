/********************************************************************************
** Form generated from reading UI file 'faq_light.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FAQ_LIGHT_H
#define UI_FAQ_LIGHT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDial>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_FAQ_Light
{
public:
    QFrame *frame_2;
    QLabel *label_2;
    QDial *lig_i;
    QFrame *line;
    QPushButton *pushButton;
    QFrame *frame;
    QPushButton *cam_move_r;
    QPushButton *cam_move_d;
    QPushButton *cam_move_b;
    QPushButton *cam_move_f;
    QPushButton *cam_move_l;
    QPushButton *cam_move_u;
    QLabel *label;

    void setupUi(QDialog *FAQ_Light)
    {
        if (FAQ_Light->objectName().isEmpty())
            FAQ_Light->setObjectName(QString::fromUtf8("FAQ_Light"));
        FAQ_Light->resize(518, 391);
        frame_2 = new QFrame(FAQ_Light);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(10, 160, 501, 141));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        label_2 = new QLabel(frame_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(140, 10, 351, 121));
        lig_i = new QDial(frame_2);
        lig_i->setObjectName(QString::fromUtf8("lig_i"));
        lig_i->setGeometry(QRect(10, 10, 121, 111));
        lig_i->setMaximum(99);
        lig_i->setSingleStep(1);
        lig_i->setValue(75);
        lig_i->setOrientation(Qt::Horizontal);
        line = new QFrame(FAQ_Light);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(0, 149, 521, 21));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        pushButton = new QPushButton(FAQ_Light);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(10, 330, 501, 51));
        frame = new QFrame(FAQ_Light);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(10, 10, 501, 141));
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

        retranslateUi(FAQ_Light);

        QMetaObject::connectSlotsByName(FAQ_Light);
    } // setupUi

    void retranslateUi(QDialog *FAQ_Light)
    {
        FAQ_Light->setWindowTitle(QApplication::translate("FAQ_Light", "\320\240\320\260\320\261\320\276\321\202\320\260 \321\201 \321\201\320\262\320\265\321\202\320\276\320\274", nullptr));
        label_2->setText(QApplication::translate("FAQ_Light", "\320\237\320\276\320\273\320\267\321\203\320\275\320\276\320\272 \321\201\320\273\321\203\320\266\320\270\321\202 \320\264\320\273\321\217 \320\270\320\267\320\274\320\265\320\275\320\265\320\275\320\270\321\217 \n"
"\320\270\320\275\321\202\320\265\320\275\321\201\320\270\320\262\320\275\320\276\321\201\321\202\320\270 \320\270\321\201\321\202\320\276\321\207\320\275\320\270\320\272\320\260 \321\201\320\262\320\265\321\202\320\260. \320\224\320\262\320\270\320\266\320\265\320\275\320\270\320\265\320\274 \n"
"\320\277\320\276\320\273\320\267\321\203\320\275\320\272\320\260 \320\274\320\276\320\266\320\275\320\276 \320\274\320\265\320\275\321\217\321\202\321\214 \320\270\320\275\321\202\320\265\320\275\321\201\320\270\320\275\320\276\321\201\321\202\321\214 \320\276\321\202 \n"
"\320\274\320\270\320\275\320\270\320\274\320\260\320\273\321\214\320\275\320\276\320\263\320\276 \320\264\320\276 \320\274\320\260\320\272\321\201\320\270\320\274\320\260\320\273\321\214\320\275\320\276\320\263\320\276 \320\267\320\275\320"
                        "\260\321\207\320\265\320\275\320\270\321\217", nullptr));
        pushButton->setText(QApplication::translate("FAQ_Light", "\320\227\320\260\320\272\321\200\321\213\321\202\321\214", nullptr));
        cam_move_r->setText(QApplication::translate("FAQ_Light", "\360\237\241\272", nullptr));
        cam_move_d->setText(QApplication::translate("FAQ_Light", "\342\206\241", nullptr));
        cam_move_b->setText(QApplication::translate("FAQ_Light", "\360\237\241\273", nullptr));
        cam_move_f->setText(QApplication::translate("FAQ_Light", "\360\237\241\271", nullptr));
        cam_move_l->setText(QApplication::translate("FAQ_Light", "\360\237\241\270", nullptr));
        cam_move_u->setText(QApplication::translate("FAQ_Light", "\342\206\237", nullptr));
        label->setText(QApplication::translate("FAQ_Light", "\320\241\321\202\321\200\320\265\320\273\320\272\320\270 \321\201\320\273\321\203\320\266\320\260\321\202 \320\264\320\273\321\217 \320\270\320\267\320\274\320\265\320\275\320\265\320\275\320\270\321\217 \320\277\320\276\320\267\320\270\321\206\320\270\320\270 \320\270\321\201\321\202\320\276\321\207\320\275\320\270\320\272\320\260 \321\201\320\262\320\265\321\202\320\260. \n"
"\320\236\320\275\320\270 \320\262\321\213\320\267\321\213\320\262\320\260\321\216\321\202 \320\277\320\265\321\200\320\265\320\274\320\265\321\211\320\265\320\275\320\270\320\265 \320\270\321\201\321\202\320\276\321\207\320\275\320\270\320\272\320\260 \320\262\320\277\320\265\321\200\321\221\320\264, \320\275\320\260\320\267\320\260\320\264, \320\262\320\277\321\200\320\260\320\262\320\276, \n"
"\320\262\320\273\320\265\320\262\320\276, \320\262\320\262\320\265\321\200\321\205 \320\270 \320\262\320\275\320\270\320\267 \321\201\320\276\320\276\321\202\320\262.", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FAQ_Light: public Ui_FAQ_Light {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FAQ_LIGHT_H
