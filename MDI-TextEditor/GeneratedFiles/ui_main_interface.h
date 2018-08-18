/********************************************************************************
** Form generated from reading UI file 'main_interface.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAIN_INTERFACE_H
#define UI_MAIN_INTERFACE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMdiArea>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_main_interfaceClass
{
public:
    QAction *actionNew;
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionSave_As;
    QAction *actionUndo;
    QAction *actionRedo;
    QAction *actionCut;
    QAction *actionCopy;
    QAction *actionPaste;
    QAction *actionShut_Current_Window;
    QAction *actionShut_All_Windows;
    QAction *actionTiled;
    QAction *actionStacked;
    QAction *actionAbout;
    QAction *actionAbout_Qt;
    QAction *actionPrevious;
    QAction *actionNext;
    QAction *actionExit;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QMdiArea *mdiArea;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuWindow;
    QMenu *menuHelp;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *main_interfaceClass)
    {
        if (main_interfaceClass->objectName().isEmpty())
            main_interfaceClass->setObjectName(QStringLiteral("main_interfaceClass"));
        main_interfaceClass->resize(592, 400);
        actionNew = new QAction(main_interfaceClass);
        actionNew->setObjectName(QStringLiteral("actionNew"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/main_interface/images/new.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionNew->setIcon(icon);
        actionOpen = new QAction(main_interfaceClass);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/main_interface/images/open.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpen->setIcon(icon1);
        actionSave = new QAction(main_interfaceClass);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/main_interface/images/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave->setIcon(icon2);
        actionSave_As = new QAction(main_interfaceClass);
        actionSave_As->setObjectName(QStringLiteral("actionSave_As"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/main_interface/images/saveAs.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave_As->setIcon(icon3);
        actionUndo = new QAction(main_interfaceClass);
        actionUndo->setObjectName(QStringLiteral("actionUndo"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/main_interface/images/undo.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionUndo->setIcon(icon4);
        actionRedo = new QAction(main_interfaceClass);
        actionRedo->setObjectName(QStringLiteral("actionRedo"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/main_interface/images/redo.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRedo->setIcon(icon5);
        actionCut = new QAction(main_interfaceClass);
        actionCut->setObjectName(QStringLiteral("actionCut"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/main_interface/images/cut.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCut->setIcon(icon6);
        actionCopy = new QAction(main_interfaceClass);
        actionCopy->setObjectName(QStringLiteral("actionCopy"));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/main_interface/images/copy.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCopy->setIcon(icon7);
        actionPaste = new QAction(main_interfaceClass);
        actionPaste->setObjectName(QStringLiteral("actionPaste"));
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/main_interface/images/paste.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPaste->setIcon(icon8);
        actionShut_Current_Window = new QAction(main_interfaceClass);
        actionShut_Current_Window->setObjectName(QStringLiteral("actionShut_Current_Window"));
        actionShut_All_Windows = new QAction(main_interfaceClass);
        actionShut_All_Windows->setObjectName(QStringLiteral("actionShut_All_Windows"));
        actionTiled = new QAction(main_interfaceClass);
        actionTiled->setObjectName(QStringLiteral("actionTiled"));
        actionStacked = new QAction(main_interfaceClass);
        actionStacked->setObjectName(QStringLiteral("actionStacked"));
        actionAbout = new QAction(main_interfaceClass);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        actionAbout_Qt = new QAction(main_interfaceClass);
        actionAbout_Qt->setObjectName(QStringLiteral("actionAbout_Qt"));
        actionPrevious = new QAction(main_interfaceClass);
        actionPrevious->setObjectName(QStringLiteral("actionPrevious"));
        QIcon icon9;
        icon9.addFile(QStringLiteral(":/main_interface/images/previous.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPrevious->setIcon(icon9);
        actionNext = new QAction(main_interfaceClass);
        actionNext->setObjectName(QStringLiteral("actionNext"));
        QIcon icon10;
        icon10.addFile(QStringLiteral(":/main_interface/images/next.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionNext->setIcon(icon10);
        actionExit = new QAction(main_interfaceClass);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        QIcon icon11;
        icon11.addFile(QStringLiteral(":/main_interface/images/exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionExit->setIcon(icon11);
        centralWidget = new QWidget(main_interfaceClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        mdiArea = new QMdiArea(centralWidget);
        mdiArea->setObjectName(QStringLiteral("mdiArea"));

        gridLayout->addWidget(mdiArea, 0, 0, 1, 1);

        main_interfaceClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(main_interfaceClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 592, 30));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        menuWindow = new QMenu(menuBar);
        menuWindow->setObjectName(QStringLiteral("menuWindow"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        main_interfaceClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(main_interfaceClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        main_interfaceClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(main_interfaceClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        main_interfaceClass->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuBar->addAction(menuWindow->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionNew);
        menuFile->addAction(actionOpen);
        menuFile->addSeparator();
        menuFile->addAction(actionSave);
        menuFile->addAction(actionSave_As);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);
        menuEdit->addAction(actionUndo);
        menuEdit->addAction(actionRedo);
        menuEdit->addSeparator();
        menuEdit->addAction(actionCut);
        menuEdit->addAction(actionCopy);
        menuEdit->addAction(actionPaste);
        menuWindow->addAction(actionShut_Current_Window);
        menuWindow->addAction(actionShut_All_Windows);
        menuWindow->addSeparator();
        menuWindow->addSeparator();
        menuWindow->addAction(actionPrevious);
        menuWindow->addAction(actionNext);
        menuHelp->addAction(actionAbout);
        menuHelp->addAction(actionAbout_Qt);
        mainToolBar->addAction(actionNew);
        mainToolBar->addAction(actionOpen);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionSave);
        mainToolBar->addAction(actionSave_As);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionCut);
        mainToolBar->addAction(actionCopy);
        mainToolBar->addAction(actionPaste);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionUndo);
        mainToolBar->addAction(actionRedo);

        retranslateUi(main_interfaceClass);

        QMetaObject::connectSlotsByName(main_interfaceClass);
    } // setupUi

    void retranslateUi(QMainWindow *main_interfaceClass)
    {
        main_interfaceClass->setWindowTitle(QApplication::translate("main_interfaceClass", "main_interface", Q_NULLPTR));
        actionNew->setText(QApplication::translate("main_interfaceClass", "New", Q_NULLPTR));
        actionOpen->setText(QApplication::translate("main_interfaceClass", "Open", Q_NULLPTR));
        actionSave->setText(QApplication::translate("main_interfaceClass", "Save", Q_NULLPTR));
        actionSave_As->setText(QApplication::translate("main_interfaceClass", "Save As", Q_NULLPTR));
        actionUndo->setText(QApplication::translate("main_interfaceClass", "Undo", Q_NULLPTR));
        actionRedo->setText(QApplication::translate("main_interfaceClass", "Redo", Q_NULLPTR));
        actionCut->setText(QApplication::translate("main_interfaceClass", "Cut", Q_NULLPTR));
        actionCopy->setText(QApplication::translate("main_interfaceClass", "Copy", Q_NULLPTR));
        actionPaste->setText(QApplication::translate("main_interfaceClass", "Paste", Q_NULLPTR));
        actionShut_Current_Window->setText(QApplication::translate("main_interfaceClass", "Shut Current Window", Q_NULLPTR));
        actionShut_All_Windows->setText(QApplication::translate("main_interfaceClass", "Shut All Windows", Q_NULLPTR));
        actionTiled->setText(QApplication::translate("main_interfaceClass", "Tiled", Q_NULLPTR));
        actionStacked->setText(QApplication::translate("main_interfaceClass", "Stacked", Q_NULLPTR));
        actionAbout->setText(QApplication::translate("main_interfaceClass", "About", Q_NULLPTR));
        actionAbout_Qt->setText(QApplication::translate("main_interfaceClass", "About Qt", Q_NULLPTR));
        actionPrevious->setText(QApplication::translate("main_interfaceClass", "Previous", Q_NULLPTR));
        actionNext->setText(QApplication::translate("main_interfaceClass", "Next", Q_NULLPTR));
        actionExit->setText(QApplication::translate("main_interfaceClass", "Exit", Q_NULLPTR));
        menuFile->setTitle(QApplication::translate("main_interfaceClass", "File", Q_NULLPTR));
        menuEdit->setTitle(QApplication::translate("main_interfaceClass", "Edit", Q_NULLPTR));
        menuWindow->setTitle(QApplication::translate("main_interfaceClass", "Window", Q_NULLPTR));
        menuHelp->setTitle(QApplication::translate("main_interfaceClass", "Help", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class main_interfaceClass: public Ui_main_interfaceClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAIN_INTERFACE_H
