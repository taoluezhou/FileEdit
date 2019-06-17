#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->filetree->setColumnCount(1);
    ui->filetree->setHeaderLabel("项目");
    TabTextEdit.clear();//tab页textEdit列表
   // TabSave.clear();
    filelinelist.clear(); //ptp文件行列表
    filelist.clear(); //文件名列表
    tabfilelist.clear(); //tab文件名列表
    ui->filetab->setTabsClosable(true); //每个Tab上都有关闭按钮
    connect(ui->filetab,SIGNAL(tabCloseRequested(int)),this,SLOT(removeThisTab(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_ToolBar_open_triggered() //隐藏显示工具条
{
    if(!ui->mainToolBar->isHidden())
    ui->mainToolBar->setHidden(1);
    else
    ui->mainToolBar->setHidden(0);
}


void MainWindow::on_fileList_open_triggered() //隐藏显示文件列表
{
    if(!ui->filedockWidget->isHidden())
    ui->filedockWidget->setHidden(1);
    else
    ui->filedockWidget->setHidden(0);
}

void MainWindow::on_fileWindow_open_triggered() //隐藏显示tab文件窗口
{
    if(!ui-> tabdockWidget->isHidden())
    ui-> tabdockWidget->setHidden(1);
    else
    ui-> tabdockWidget->setHidden(0);
}

void MainWindow::on_open_Item_triggered() //打开项目
{
    ptpPath = QFileDialog::getOpenFileName(this,"选择项目文件","../file1","TXT(*.ptp)");

    if(ptpPath!=NULL)
    {
        dirPath = ptpPath;
        //*********************取ptp文件夹路径************************************//
        int ptpPathSum=0;
        for(ptpPathSum=0;ptpPath[ptpPathSum]!='\0';ptpPathSum++);
        int charcount;
        for(charcount = ptpPathSum-1;ptpPath[charcount]!='/';charcount--);
        //qDebug()<<charcount;
        dirPath.truncate(charcount);
        //*********************************************************************//
        ui->filetree->clear();
        filelinelist.clear();
        filelist.clear();
        tabfilelist.clear();
        TabTextEdit.clear();
        QFile ptpFile(ptpPath);
        QFileInfo fileInfo(ptpFile);

        item_pro->setText(0,fileInfo.fileName());
        ui->filetree->addTopLevelItem(item_pro);
        item_1->setText(0,"头文件");
        item_pro->addChild(item_1);
        item_2->setText(0,"源文件");
        item_pro->addChild(item_2);
        item_3->setText(0,"硬件文件");
        item_pro->addChild(item_3);

        if(!ptpFile.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            qDebug()<<QObject::tr("打开失败");
        }
        else
        {
            QByteArray array;
            QTextStream filedata(&ptpFile);
            QString line;
            do{
                line=filedata.readLine();
                filelinelist<<line;
                //qDebug()<<filelinelist;
                int i = 3;
                QString file_type;
                QString file_name;
                file_type[0]= line[0];
                file_type[1]= line[1];
                //qDebug()<<file_type;
                while(line[i]!='\0')
                {
                    file_name[i-3]=line[i];
                    i++;
                }
                //qDebug()<<file_name;
                if(file_type=="SF")
                {
                    array+=line+"\n";
                    QTreeWidgetItem *childitem = new QTreeWidgetItem();
                    childitem->setText(0, file_name);
                    filelist<<file_name;
                    item_1->addChild(childitem);
                    //int itemindex=item_1->indexOfChild(childitem);//返回索引值
                    //qDebug()<<itemindex;
                    connect(ui->filetree,SIGNAL(itemDoubleClicked(QTreeWidgetItem*,int)),this,SLOT(clickItem(QTreeWidgetItem*)));
                }
                else if(file_type=="HF")
                {
                    array+=line+"\n";
                    QTreeWidgetItem *childitem = new QTreeWidgetItem();
                    childitem->setText(0, file_name);
                    filelist<<file_name;
                    item_2->addChild(childitem);
                    //int itemindex=item_2->indexOfChild(childitem);//返回索引值
                    //qDebug()<<itemindex;
                    connect(ui->filetree,SIGNAL(itemDoubleClicked(QTreeWidgetItem*,int)),this,SLOT(clickItem(QTreeWidgetItem*)));
                }
                else if(file_type=="MF")
                {
                    array+=line+"\n";
                    QTreeWidgetItem *childitem = new QTreeWidgetItem();
                    childitem->setText(0, file_name);

                    filelist<<file_name;
                    item_3->addChild(childitem);
                    //int itemindex=item_3->indexOfChild(childitem);//返回索引值
                    //qDebug()<<itemindex;
                    connect(ui->filetree,SIGNAL(itemDoubleClicked(QTreeWidgetItem*,int)),this,SLOT(clickItem(QTreeWidgetItem*)));
                }
                else
                {
                    continue;
                }
            }while(!line.isNull());//寻找空白索引值
            showptpfile(filelinelist);
            ptpFile.close();
        }
    }
    else
        return;

}

void MainWindow::showptpfile(QStringList filelinelist) //ptp文件显示在textEdit中
{
    QByteArray array;
    ui->ptptext->clear();
    for(int i=0;i<filelinelist.count();i++)
    {
        array+=filelinelist[i]+"\n";
    }
    ui->ptptext->setText(array);
}


void MainWindow::on_file_delete_triggered() //删除文件槽函数
{
    if(ui->filetree->currentItem()->childCount()==0)
    {
        deleteptpbox(); //弹出删除确认窗口
    }
    else
    return;
}

void MainWindow::deleteptpbox() //删除确认窗口
{
    switch(QMessageBox::question(this,tr("删除确认"),tr("确定从项目中删除该文件?"),QMessageBox::Ok|QMessageBox::Cancel,QMessageBox::Cancel))
    {
        case QMessageBox::Ok:
            deleteptp();
            break;
        case QMessageBox::Cancel:
            break;
        default:
        break;
    }
    return;
}


void MainWindow::deleteptp() //删除文件操作中修改ptp文件
{
    QString currentItemName=ui->filetree->currentItem()->text(0);
    QString FileType;
    //qDebug()<<ui->filetree->currentItem()->parent()->parent()->indexOfChild(ui->filetree->currentItem()->parent());
    if(ui->filetree->currentItem()->parent()->parent()->indexOfChild(ui->filetree->currentItem()->parent())==0)
    {
        FileType="SF";
    }
    else if(ui->filetree->currentItem()->parent()->parent()->indexOfChild(ui->filetree->currentItem()->parent())==1)
    {
        FileType="HF";
    }
    else if(ui->filetree->currentItem()->parent()->parent()->indexOfChild(ui->filetree->currentItem()->parent())==2)
    {
        FileType="MF";
    }
    else
    {
        return;
    }

    int tab_index=0;
    //QString asfasf=ui->filetree->currentItem()->text(0);
    //*********************检索对应文件名的tab索引号************************************//
    while(tab_index<ui->filetab->count())
    {
        if(ui->filetab->tabText(tab_index)==currentItemName)
        {
           qDebug()<<ui->filetab->tabText(tab_index);
           qDebug()<<currentItemName;
           break;
        }
        tab_index++;
    }
    //******************************************************************************//
    ui->filetree->currentItem()->parent()->takeChild(ui->filetree->currentItem()->parent()->indexOfChild(ui->filetree->currentItem()));//文件列表中删除
    if(tab_index>=ui->filetab->count())
    {
    }
    else
    {
       ui->filetab->removeTab(tab_index);//tab中删除
    }
    filelinelist.removeOne(FileType+" "+currentItemName);
    filelist.removeOne(currentItemName);
    TabTextEdit.removeAt(tab_index);
    tabfilelist.removeAt(tab_index);
    QFile::remove(dirPath+"/"+currentItemName);
    showptpfile(filelinelist);
    if(ptpPath.isEmpty()==false)  //修改ptp文件
    {
         QFile file;
         file.setFileName(ptpPath);
         bool isOK=file.open(QIODevice::WriteOnly);
         if(isOK==true)
         {
              QString str=ui->ptptext->toPlainText();
              file.write(str.toUtf8());
         }
         file.close();
     }
    QMessageBox::warning(this,"删除文件","删除成功！");
    //qDebug()<<filelinelist;
    //qDebug()<<filelist;
    //qDebug()<<"delete "+currentTabIndexflag[tab_index];
    //qDebug()<<int(tab_index);
}


void MainWindow::clickItem(QTreeWidgetItem* item)  //点击文件列表中的文件，Tab中相应文件显示
{
    ClickItemfilename=item->text(0);
    //((QTabBar*)(ui->filetab->tabBar()))->setTabButton(ui->filetab->indexOf(0),QTabBar::RightSide,NULL);
    QTextEdit *filetext = new QTextEdit;
    //QWidget *tab = new QWidget;
    //QWidget *Tab1 = new QWidget(filetext);
    if(item->childCount()==0)
    {
        QString currentitemfile=dirPath+'/'+ClickItemfilename;
        //qDebug()<<currentitemfile;
        if(currentitemfile.isEmpty()==false&&!tabfilelist.contains(item->text(0)))
        {
           tabfilelist<<ClickItemfilename;
           QFile file(currentitemfile);
           bool isOK=file.open(QIODevice::ReadOnly);
           if(isOK==true)
           {
                QByteArray array;
                while(file.atEnd()==false)
                {
                    array+=file.readLine();
                }
                filetext->setText(array);
                QIcon icon("icon/file_cor.jpg");
                ui->filetab->setCurrentIndex(ui->filetab->addTab(filetext,icon,ClickItemfilename));
                TabTextEdit<<filetext;
                connect(filetext,SIGNAL(textChanged()),this,SLOT(textChangedFlag()));
           }
           file.close();
        }
        else   //若Tab中已有该标签，设置为当前显示
        {
           // QString currentitemfile=dirPath+'/'+ClickItemfilename;
            for(int i=0;i<tabfilelist.count();i++)
            {
                if(tabfilelist[i]==ClickItemfilename)
                {
                    ui->filetab->setCurrentIndex(i);
                }
            }
        }
    }
    else
    return;
}

void MainWindow::textChangedFlag()
{
     qDebug()<<ui->filetab->tabText(ui->filetab->currentIndex());
     ui->filetab->setTabText(ui->filetab->currentIndex(),"* "+tabfilelist[ui->filetab->currentIndex()]);
}

void MainWindow::removeThisTab(int Index) //点击Tab关闭按钮后的具体操作
{
     ui->filetab->removeTab(Index);
     TabTextEdit.removeAt(Index);
     tabfilelist.removeAt(Index);
}

void MainWindow::on_actionTest_triggered() //测试
{
    //qDebug()<<TabTextEdit[0]->toPlainText();
    //qDebug()<<ui->filetab->tabText(ui->filetab->currentIndex());
    //qDebug()<<TabTextEdit[ui->filetab->currentIndex()]->toPlainText();
    qDebug()<<dirPath;
}

void MainWindow::on_save_file_triggered()
{
    QString FilePath=dirPath+'/';
    int TabIndex=ui->filetab->currentIndex();
    FilePath=FilePath+tabfilelist[TabIndex];
    if(FilePath.isEmpty()==false)
    {
         QFile file;
         file.setFileName(FilePath);
         bool isOK=file.open(QIODevice::WriteOnly);
         if(isOK==true)
         {
              QString str=TabTextEdit[TabIndex]->toPlainText();
              file.write(str.toUtf8());
         }
         file.close();
     }
    ui->filetab->setTabText(ui->filetab->currentIndex(),tabfilelist[ui->filetab->currentIndex()]);
}

void MainWindow::on_save_item_triggered()  //保存所有文件
{
    int TabIndex=0;
    for(TabIndex=0;TabIndex<tabfilelist.count();TabIndex++)
    {
        QString FilePath = dirPath+'/'+tabfilelist[TabIndex];
        if(FilePath.isEmpty()==false)  //修改文件
        {
            QFile file;
            file.setFileName(FilePath);
            bool isOK=file.open(QIODevice::WriteOnly);
            if(isOK==true)
            {
               QString str=TabTextEdit[TabIndex]->toPlainText();
               file.write(str.toUtf8());
            }
            file.close();
        }
        ui->filetab->setTabText(TabIndex,tabfilelist[TabIndex]);
    }

}

void MainWindow::on_new_file_triggered()
{
    new_subwindow.show();
    connect(&new_subwindow,SIGNAL(sendFileName(QString,int)),this,SLOT(new_file(QString,int)));
}

void MainWindow::new_file(QString filename,int filetype)
{
    QString fileLineData;
    QTreeWidgetItem *childitem = new QTreeWidgetItem();
    childitem->setText(0, filename);
    if(filetype==1)
    {
        fileLineData="HF ";
        item_2->addChild(childitem);
        connect(ui->filetree,SIGNAL(itemDoubleClicked(QTreeWidgetItem*,int)),this,SLOT(clickItem(QTreeWidgetItem*)));
    }
    else if(filetype==2)
    {
        fileLineData="SF ";
    }
    else if(filetype==3)
    {
        fileLineData="MF ";
    }
    fileLineData+=filename+"\n";
    filelinelist<<fileLineData;
    showptpfile(filelinelist);
    qDebug()<<fileLineData;
}





