/********************************************************************************
** Form generated from reading UI file 'faq_hit.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FAQ_HIT_H
#define UI_FAQ_HIT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>

QT_BEGIN_NAMESPACE

class Ui_FAQ_Hit
{
public:
    QFrame *line;
    QFrame *frame;
    QLabel *label_2;
    QSlider *hit_power;
    QPushButton *pushButton;
    QFrame *frame_2;
    QLabel *label_4;

    void setupUi(QDialog *FAQ_Hit)
    {
        if (FAQ_Hit->objectName().isEmpty())
            FAQ_Hit->setObjectName(QString::fromUtf8("FAQ_Hit"));
        FAQ_Hit->resize(520, 324);
        line = new QFrame(FAQ_Hit);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(0, 149, 521, 21));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        frame = new QFrame(FAQ_Hit);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(10, 10, 501, 141));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        label_2 = new QLabel(frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 60, 481, 71));
        label_2->setScaledContents(false);
        hit_power = new QSlider(frame);
        hit_power->setObjectName(QString::fromUtf8("hit_power"));
        hit_power->setGeometry(QRect(20, 10, 471, 41));
        hit_power->setMinimum(1);
        hit_power->setValue(50);
        hit_power->setOrientation(Qt::Horizontal);
        pushButton = new QPushButton(FAQ_Hit);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(10, 270, 501, 51));
        frame_2 = new QFrame(FAQ_Hit);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(10, 160, 501, 101));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        label_4 = new QLabel(frame_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 10, 481, 81));

        retranslateUi(FAQ_Hit);

        QMetaObject::connectSlotsByName(FAQ_Hit);
    } // setupUi

    void retranslateUi(QDialog *FAQ_Hit)
    {
        FAQ_Hit->setWindowTitle(QApplication::translate("FAQ_Hit", "\320\237\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\213 \321\203\320\264\320\260\321\200\320\260", nullptr));
        label_2->setText(QApplication::translate("FAQ_Hit", "\320\237\320\276\320\273\320\267\321\203\320\275\320\276\320\272 \320\267\320\260\320\264\320\260\321\221\321\202 \321\201\320\270\320\273\321\203 \321\203\320\264\320\260\321\200\320\260 \320\237\320\265\321\200\320\265\321\202\320\260\321\201\320\272\320\270\320\262\320\260\320\275\320\270\320\265\320\274 \320\265\320\263\320\276 \320\273\320\265\320\262\320\262\320\265\320\265 \320\270 \n"
"\320\277\321\200\320\260\320\262\320\265\320\265 \320\274\320\276\320\266\320\275\320\276 \321\203\320\274\320\265\320\275\321\214\321\210\320\260\321\202\321\214 \320\270 \321\203\320\262\320\265\320\273\320\270\321\207\320\270\320\262\320\260\321\202\321\214 \321\201\320\272\320\276\321\200\320\276\321\201\321\202\321\214 \320\261\320\270\321\202\320\272\320\260 \n"
"\320\277\320\276\321\201\320\273\320\265 \321\203\320\264\320\260\321\200\320\260.", nullptr));
        pushButton->setText(QApplication::translate("FAQ_Hit", "\320\227\320\260\320\272\321\200\321\213\321\202\321\214", nullptr));
        label_4->setText(QApplication::translate("FAQ_Hit", "\320\235\320\260\320\277\321\200\320\260\320\262\320\273\320\265\320\275\320\270\320\265 \321\203\320\264\320\260\321\200\320\260 \320\267\320\260\320\264\320\260\321\221\321\202\321\201\321\217 \320\272\320\273\320\270\320\272\320\276\320\274 \320\275\320\260 \320\270\320\267\320\276\320\261\321\200\320\260\320\266\320\265\320\275\320\270\320\265. \320\243\320\264\320\260\321\200 \n"
"\320\261\321\203\320\264\320\265\321\202 \320\275\320\260\320\277\321\200\320\260\320\262\320\273\320\265\320\275 \320\276\321\202 \320\261\320\270\321\202\320\272\320\260 \320\262 \321\201\321\202\320\276\321\200\320\276\320\275\321\203 \321\203\320\272\320\260\320\267\320\260\320\275\320\275\320\276\320\271 \321\202\320\276\321\207\320\272\320\270. \n"
"\320\237\320\276 \320\277\321\200\320\260\320\262\320\270\320\273\320\260\320\274 \320\261\320\270\320\273\321\214\321\217\321\200\320\264\320\260, \321\203\320\264\320\260\321\200 \320\274\320\276\320\266\320\265\321\202 \321\201\320\276\320\262\320\265\321\200\321\210\320\260"
                        "\321\202\321\214\321\201\321\217 \321\202\320\276\320\273\321\214\320\272\320\276 \320\262 \n"
"\320\274\320\276\320\274\320\265\320\275\321\202 \320\277\320\276\320\273\320\275\320\276\320\271 \320\276\321\201\321\202\320\260\320\275\320\276\320\262\320\272\320\270 \320\262\321\201\320\265\321\205 \321\210\320\260\321\200\320\276\320\262 \320\275\320\260 \321\201\321\202\320\276\320\273\320\265.", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FAQ_Hit: public Ui_FAQ_Hit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FAQ_HIT_H
