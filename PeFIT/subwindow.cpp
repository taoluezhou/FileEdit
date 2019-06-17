#include "subwindow.h"
#include "ui_subwindow.h"

subwindow::subwindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::subwindow)
{
    ui->setupUi(this);
    setWindowTitle("请输入文件名：");
}

subwindow::~subwindow()
{
    delete ui;
}

void subwindow::on_OK_clicked()
{
    int check;
    QButtonGroup newQButtonGroup;
    newQButtonGroup.addButton(ui->check1);
    newQButtonGroup.setId(ui->check1,1);
    newQButtonGroup.addButton(ui->check2);
    newQButtonGroup.setId(ui->check2,2);
    newQButtonGroup.addButton(ui->check3);
    newQButtonGroup.setId(ui->check3,3);
    newQButtonGroup.setExclusive(true);
    QString file_name=ui->newfilename->toPlainText();
    QString file_type;
    if(newQButtonGroup.checkedId()==-1||file_name==NULL)
    {
        this->close();
        return;
    }
    //qDebug()<<newQButtonGroup.checkedId();
    if(newQButtonGroup.checkedId()==1)
    {
       file_type=".h";
       check=1;
    }
    else if(newQButtonGroup.checkedId()==2)
    {
       file_type=".cpp";
       check=2;
    }
    else if(newQButtonGroup.checkedId()==3)
    {
       file_type="";
       check=3;
    }
    QString file=file_name+file_type;
    //qDebug()<<file;
    emit sendFileName(file,check);
}
