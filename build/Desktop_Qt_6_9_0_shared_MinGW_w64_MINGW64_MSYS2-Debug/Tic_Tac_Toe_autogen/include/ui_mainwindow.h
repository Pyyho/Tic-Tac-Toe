/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *mainLayout;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *leftPanel;
    QSpacerItem *verticalSpacer_2;
    QPushButton *startButton;
    QLabel *label;
    QComboBox *sizeBox;
    QLabel *label_2;
    QComboBox *winBox;
    QLabel *label_3;
    QComboBox *symbolBox;
    QCheckBox *infiniteGameButton;
    QSpacerItem *verticalSpacer;
    QWidget *boardContainer;
    QGridLayout *gridLayout;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1000, 700);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        mainLayout = new QHBoxLayout(centralwidget);
        mainLayout->setObjectName("mainLayout");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        mainLayout->addItem(horizontalSpacer);

        leftPanel = new QVBoxLayout();
        leftPanel->setObjectName("leftPanel");
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        leftPanel->addItem(verticalSpacer_2);

        startButton = new QPushButton(centralwidget);
        startButton->setObjectName("startButton");

        leftPanel->addWidget(startButton);

        label = new QLabel(centralwidget);
        label->setObjectName("label");

        leftPanel->addWidget(label);

        sizeBox = new QComboBox(centralwidget);
        sizeBox->setObjectName("sizeBox");

        leftPanel->addWidget(sizeBox);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");

        leftPanel->addWidget(label_2);

        winBox = new QComboBox(centralwidget);
        winBox->setObjectName("winBox");

        leftPanel->addWidget(winBox);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");

        leftPanel->addWidget(label_3);

        symbolBox = new QComboBox(centralwidget);
        symbolBox->setObjectName("symbolBox");

        leftPanel->addWidget(symbolBox);

        infiniteGameButton = new QCheckBox(centralwidget);
        infiniteGameButton->setObjectName("infiniteGameButton");

        leftPanel->addWidget(infiniteGameButton);

        verticalSpacer = new QSpacerItem(20, 200, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        leftPanel->addItem(verticalSpacer);


        mainLayout->addLayout(leftPanel);

        boardContainer = new QWidget(centralwidget);
        boardContainer->setObjectName("boardContainer");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(1);
        sizePolicy.setHeightForWidth(boardContainer->sizePolicy().hasHeightForWidth());
        boardContainer->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(boardContainer);
        gridLayout->setSpacing(2);
        gridLayout->setObjectName("gridLayout");

        mainLayout->addWidget(boardContainer);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1000, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        startButton->setText(QCoreApplication::translate("MainWindow", "\320\230\320\263\321\200\320\260\321\202\321\214", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\240\320\260\320\267\320\274\320\265\321\200 \320\237\320\276\320\273\321\217", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260 \320\272\320\276\320\263\320\276 \320\270\320\263\321\200\320\260\321\202\321\214", nullptr));
        infiniteGameButton->setText(QCoreApplication::translate("MainWindow", "\320\221\320\265\321\201\320\272\320\276\320\275\320\265\321\207\320\275\320\260\321\217 \320\270\320\263\321\200\320\260", nullptr));
        (void)MainWindow;
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
