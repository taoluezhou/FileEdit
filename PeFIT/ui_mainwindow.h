/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *open_Item;
    QAction *ToolBar_open;
    QAction *fileList_open;
    QAction *fileWindow_open;
    QAction *actionTest;
    QAction *file_delete;
    QAction *save_item;
    QAction *save_file;
    QAction *new_file;
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_2;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QDockWidget *filedockWidget;
    QWidget *dockWidgetContents;
    QHBoxLayout *horizontalLayout;
    QTreeWidget *filetree;
    QTextEdit *ptptext;
    QDockWidget *tabdockWidget;
    QWidget *dockWidgetContents_3;
    QHBoxLayout *horizontalLayout_2;
    QTabWidget *filetab;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(653, 446);
        open_Item = new QAction(MainWindow);
        open_Item->setObjectName(QStringLiteral("open_Item"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/new/prefix1/icon/itemopen.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        open_Item->setIcon(icon);
        ToolBar_open = new QAction(MainWindow);
        ToolBar_open->setObjectName(QStringLiteral("ToolBar_open"));
        ToolBar_open->setCheckable(false);
        ToolBar_open->setChecked(false);
        fileList_open = new QAction(MainWindow);
        fileList_open->setObjectName(QStringLiteral("fileList_open"));
        fileList_open->setCheckable(false);
        fileList_open->setChecked(false);
        fileWindow_open = new QAction(MainWindow);
        fileWindow_open->setObjectName(QStringLiteral("fileWindow_open"));
        actionTest = new QAction(MainWindow);
        actionTest->setObjectName(QStringLiteral("actionTest"));
        file_delete = new QAction(MainWindow);
        file_delete->setObjectName(QStringLiteral("file_delete"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/new/prefix1/icon/delete.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        file_delete->setIcon(icon1);
        save_item = new QAction(MainWindow);
        save_item->setObjectName(QStringLiteral("save_item"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/new/prefix1/icon/save.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        save_item->setIcon(icon2);
        save_file = new QAction(MainWindow);
        save_file->setObjectName(QStringLiteral("save_file"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/new/prefix1/icon/timg.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        save_file->setIcon(icon3);
        new_file = new QAction(MainWindow);
        new_file->setObjectName(QStringLiteral("new_file"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/new/prefix1/icon/file.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        new_file->setIcon(icon4);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 653, 23));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QStringLiteral("menu_2"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        filedockWidget = new QDockWidget(MainWindow);
        filedockWidget->setObjectName(QStringLiteral("filedockWidget"));
        filedockWidget->setMinimumSize(QSize(300, 111));
        filedockWidget->setMaximumSize(QSize(300, 524287));
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QStringLiteral("dockWidgetContents"));
        horizontalLayout = new QHBoxLayout(dockWidgetContents);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        filetree = new QTreeWidget(dockWidgetContents);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QStringLiteral("1"));
        filetree->setHeaderItem(__qtreewidgetitem);
        filetree->setObjectName(QStringLiteral("filetree"));

        horizontalLayout->addWidget(filetree);

        ptptext = new QTextEdit(dockWidgetContents);
        ptptext->setObjectName(QStringLiteral("ptptext"));
        ptptext->setEnabled(true);

        horizontalLayout->addWidget(ptptext);

        filedockWidget->setWidget(dockWidgetContents);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(1), filedockWidget);
        tabdockWidget = new QDockWidget(MainWindow);
        tabdockWidget->setObjectName(QStringLiteral("tabdockWidget"));
        tabdockWidget->setMinimumSize(QSize(300, 46));
        tabdockWidget->setMaximumSize(QSize(300, 524287));
        dockWidgetContents_3 = new QWidget();
        dockWidgetContents_3->setObjectName(QStringLiteral("dockWidgetContents_3"));
        horizontalLayout_2 = new QHBoxLayout(dockWidgetContents_3);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        filetab = new QTabWidget(dockWidgetContents_3);
        filetab->setObjectName(QStringLiteral("filetab"));

        horizontalLayout_2->addWidget(filetab);

        tabdockWidget->setWidget(dockWidgetContents_3);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(2), tabdockWidget);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menu->addAction(open_Item);
        menu->addAction(file_delete);
        menu_2->addAction(ToolBar_open);
        menu_2->addAction(fileList_open);
        menu_2->addAction(fileWindow_open);
        mainToolBar->addAction(open_Item);
        mainToolBar->addAction(save_item);
        mainToolBar->addAction(save_file);
        mainToolBar->addAction(file_delete);
        mainToolBar->addAction(actionTest);

        retranslateUi(MainWindow);

        filetab->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        open_Item->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200\351\241\271\347\233\256", 0));
        ToolBar_open->setText(QApplication::translate("MainWindow", "\345\267\245\345\205\267\346\240\217", 0));
        fileList_open->setText(QApplication::translate("MainWindow", "\346\226\207\344\273\266\345\210\227\350\241\250", 0));
        fileWindow_open->setText(QApplication::translate("MainWindow", "\346\226\207\344\273\266\347\252\227\345\217\243", 0));
        actionTest->setText(QApplication::translate("MainWindow", "test", 0));
        file_delete->setText(QApplication::translate("MainWindow", "\345\210\240\351\231\244\346\226\207\344\273\266", 0));
        save_item->setText(QApplication::translate("MainWindow", "\344\277\235\345\255\230\351\241\271\347\233\256", 0));
        save_file->setText(QApplication::translate("MainWindow", "\344\277\235\345\255\230\346\226\207\344\273\266", 0));
        new_file->setText(QApplication::translate("MainWindow", "\346\226\260\345\273\272\346\226\207\344\273\266", 0));
        menu->setTitle(QApplication::translate("MainWindow", "\346\226\207\344\273\266", 0));
        menu_2->setTitle(QApplication::translate("MainWindow", "\347\252\227\345\217\243", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
