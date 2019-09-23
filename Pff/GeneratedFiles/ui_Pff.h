/********************************************************************************
** Form generated from reading UI file 'Pff.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PFF_H
#define UI_PFF_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "scaledpixmap.h"

QT_BEGIN_NAMESPACE

class Ui_PffClass
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton;
    QLineEdit *lineEdit;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QSlider *horizontalSlider;
    QSlider *horizontalSlider_2;
    QLabel *SiderCount1;
    QLabel *SiderCount2;
    ScaledPixmap *widget;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QPushButton *changeImage;
    QTextEdit *normalLog;
    QPushButton *saveButton;
    QPushButton *pushButton_2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *PffClass)
    {
        if (PffClass->objectName().isEmpty())
            PffClass->setObjectName(QString::fromUtf8("PffClass"));
        PffClass->resize(1039, 823);
        centralWidget = new QWidget(PffClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(920, 30, 31, 21));
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setEnabled(false);
        lineEdit->setGeometry(QRect(272, 30, 651, 20));
        lineEdit->setMouseTracking(false);
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 10, 47, 13));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(80, 10, 47, 13));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(70, 10, 47, 13));
        horizontalSlider = new QSlider(centralWidget);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(770, 180, 161, 22));
        horizontalSlider->setMinimum(-255);
        horizontalSlider->setMaximum(255);
        horizontalSlider->setValue(0);
        horizontalSlider->setOrientation(Qt::Horizontal);
        horizontalSlider_2 = new QSlider(centralWidget);
        horizontalSlider_2->setObjectName(QString::fromUtf8("horizontalSlider_2"));
        horizontalSlider_2->setGeometry(QRect(770, 240, 160, 22));
        horizontalSlider_2->setMinimum(-100);
        horizontalSlider_2->setMaximum(100);
        horizontalSlider_2->setSingleStep(0);
        horizontalSlider_2->setTracking(true);
        horizontalSlider_2->setOrientation(Qt::Horizontal);
        SiderCount1 = new QLabel(centralWidget);
        SiderCount1->setObjectName(QString::fromUtf8("SiderCount1"));
        SiderCount1->setGeometry(QRect(950, 180, 47, 13));
        SiderCount2 = new QLabel(centralWidget);
        SiderCount2->setObjectName(QString::fromUtf8("SiderCount2"));
        SiderCount2->setGeometry(QRect(950, 240, 47, 13));
        widget = new ScaledPixmap(centralWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(30, 130, 701, 621));
        QPalette palette;
        QLinearGradient gradient(0, 0, 1, 0);
        gradient.setSpread(QGradient::PadSpread);
        gradient.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient.setColorAt(0, QColor(0, 0, 0, 255));
        gradient.setColorAt(1, QColor(0, 0, 0, 255));
        QBrush brush(gradient);
        palette.setBrush(QPalette::Active, QPalette::Button, brush);
        QBrush brush1(QColor(0, 0, 0, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush1);
        QLinearGradient gradient1(0, 0, 1, 0);
        gradient1.setSpread(QGradient::PadSpread);
        gradient1.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient1.setColorAt(0, QColor(0, 0, 0, 255));
        gradient1.setColorAt(1, QColor(0, 0, 0, 255));
        QBrush brush2(gradient1);
        palette.setBrush(QPalette::Active, QPalette::Base, brush2);
        QLinearGradient gradient2(0, 0, 1, 0);
        gradient2.setSpread(QGradient::PadSpread);
        gradient2.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient2.setColorAt(0, QColor(0, 0, 0, 255));
        gradient2.setColorAt(1, QColor(0, 0, 0, 255));
        QBrush brush3(gradient2);
        palette.setBrush(QPalette::Active, QPalette::Window, brush3);
        QLinearGradient gradient3(0, 0, 1, 0);
        gradient3.setSpread(QGradient::PadSpread);
        gradient3.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient3.setColorAt(0, QColor(0, 0, 0, 255));
        gradient3.setColorAt(1, QColor(0, 0, 0, 255));
        QBrush brush4(gradient3);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush1);
        QLinearGradient gradient4(0, 0, 1, 0);
        gradient4.setSpread(QGradient::PadSpread);
        gradient4.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient4.setColorAt(0, QColor(0, 0, 0, 255));
        gradient4.setColorAt(1, QColor(0, 0, 0, 255));
        QBrush brush5(gradient4);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush5);
        QLinearGradient gradient5(0, 0, 1, 0);
        gradient5.setSpread(QGradient::PadSpread);
        gradient5.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient5.setColorAt(0, QColor(0, 0, 0, 255));
        gradient5.setColorAt(1, QColor(0, 0, 0, 255));
        QBrush brush6(gradient5);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush6);
        QLinearGradient gradient6(0, 0, 1, 0);
        gradient6.setSpread(QGradient::PadSpread);
        gradient6.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient6.setColorAt(0, QColor(0, 0, 0, 255));
        gradient6.setColorAt(1, QColor(0, 0, 0, 255));
        QBrush brush7(gradient6);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush7);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush1);
        QLinearGradient gradient7(0, 0, 1, 0);
        gradient7.setSpread(QGradient::PadSpread);
        gradient7.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient7.setColorAt(0, QColor(0, 0, 0, 255));
        gradient7.setColorAt(1, QColor(0, 0, 0, 255));
        QBrush brush8(gradient7);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush8);
        QLinearGradient gradient8(0, 0, 1, 0);
        gradient8.setSpread(QGradient::PadSpread);
        gradient8.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient8.setColorAt(0, QColor(0, 0, 0, 255));
        gradient8.setColorAt(1, QColor(0, 0, 0, 255));
        QBrush brush9(gradient8);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush9);
        widget->setPalette(palette);
        widget->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(0, 0, 0, 255));"));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(770, 160, 47, 13));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(770, 210, 47, 13));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(670, 10, 81, 16));
        changeImage = new QPushButton(centralWidget);
        changeImage->setObjectName(QString::fromUtf8("changeImage"));
        changeImage->setGeometry(QRect(770, 280, 121, 23));
        normalLog = new QTextEdit(centralWidget);
        normalLog->setObjectName(QString::fromUtf8("normalLog"));
        normalLog->setGeometry(QRect(20, 60, 491, 61));
        saveButton = new QPushButton(centralWidget);
        saveButton->setObjectName(QString::fromUtf8("saveButton"));
        saveButton->setGeometry(QRect(770, 310, 121, 23));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(910, 280, 101, 23));
        PffClass->setCentralWidget(centralWidget);
        widget->raise();
        pushButton->raise();
        lineEdit->raise();
        label->raise();
        label_2->raise();
        label_3->raise();
        horizontalSlider->raise();
        horizontalSlider_2->raise();
        SiderCount1->raise();
        SiderCount2->raise();
        label_4->raise();
        label_5->raise();
        label_6->raise();
        changeImage->raise();
        normalLog->raise();
        saveButton->raise();
        pushButton_2->raise();
        menuBar = new QMenuBar(PffClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1039, 21));
        PffClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(PffClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        PffClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(PffClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        PffClass->setStatusBar(statusBar);

        retranslateUi(PffClass);

        QMetaObject::connectSlotsByName(PffClass);
    } // setupUi

    void retranslateUi(QMainWindow *PffClass)
    {
        PffClass->setWindowTitle(QCoreApplication::translate("PffClass", "Pff", nullptr));
        pushButton->setText(QCoreApplication::translate("PffClass", "...", nullptr));
        label->setText(QString());
        label_2->setText(QString());
        label_3->setText(QString());
        SiderCount1->setText(QCoreApplication::translate("PffClass", "0", nullptr));
        SiderCount2->setText(QCoreApplication::translate("PffClass", "0", nullptr));
        label_4->setText(QCoreApplication::translate("PffClass", "\320\257\321\200\320\272\320\276\321\201\321\202\321\214", nullptr));
        label_5->setText(QCoreApplication::translate("PffClass", "\320\232\320\276\320\275\321\202\321\200\320\260\321\201\321\202", nullptr));
        label_6->setText(QCoreApplication::translate("PffClass", "\320\230\320\267\320\276\320\261\321\200\320\260\320\266\320\265\320\275\320\270\320\265", nullptr));
        changeImage->setText(QCoreApplication::translate("PffClass", "\320\237\321\200\320\270\320\274\320\265\320\275\320\270\321\202\321\214 \320\267\320\275\320\260\321\207\320\265\320\275\320\270\321\217", nullptr));
        saveButton->setText(QCoreApplication::translate("PffClass", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
        pushButton_2->setText(QCoreApplication::translate("PffClass", "\320\236\320\261\321\200\320\260\320\261\320\276\321\202\320\272\320\260 \320\275\320\260 \320\223\320\243", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PffClass: public Ui_PffClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PFF_H
