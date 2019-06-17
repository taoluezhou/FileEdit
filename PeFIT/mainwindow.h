#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTreeWidgetItem>
#include <QFile>
#include <QFileDialog>
#include <QDebug>
#include <QTextStream>
#include <QByteArray>
#include <QTextEdit>
#include <QMessageBox>
#include <QAction>
#include <QPlainTextEdit>
#include "subwindow.h"

#define MAXSUM 100

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void showptpfile(QStringList);
    void deleteptpbox();
    void deleteptp();



private slots:
    void on_ToolBar_open_triggered();

    void on_fileList_open_triggered();

    void on_fileWindow_open_triggered();

    void on_open_Item_triggered();

    void on_actionTest_triggered();

    void on_file_delete_triggered();

    void clickItem(QTreeWidgetItem* item);

    void removeThisTab(int);
    
    void on_save_file_triggered();

    void on_save_item_triggered();

    void textChangedFlag();

    void on_new_file_triggered();

    void new_file(QString,int);

private:
    Ui::MainWindow *ui;
    QString ptpPath;
    QString dirPath;
    QString ClickItemfilename;

    QStringList filelinelist;
    QStringList filelist;
    QStringList tabfilelist;
    QList<QTextEdit*> TabTextEdit;
    subwindow new_subwindow;
    QTreeWidgetItem *item_pro = new QTreeWidgetItem;
    QTreeWidgetItem *item_1 = new QTreeWidgetItem;
    QTreeWidgetItem *item_2 = new QTreeWidgetItem;
    QTreeWidgetItem *item_3 = new QTreeWidgetItem;
    //QList<QTabWidget*> TabSave;

    //QString texttabIndex[MAXSUM];
    //int tabNum;

    //int currentTreeItemIndex;
    //QString TreeItemIndex[TREEITEMMAX];
    //int currentTabIndex;
    // QString currentTabIndexflag[TREEITEMMAX];

};

#endif // MAINWINDOW_H
