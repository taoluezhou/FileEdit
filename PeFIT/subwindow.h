#ifndef SUBWINDOW_H
#define SUBWINDOW_H

#include <QWidget>
#include <QButtonGroup>
#include <QDebug>

namespace Ui {
class subwindow;
}

class subwindow : public QWidget
{
    Q_OBJECT

public:
    explicit subwindow(QWidget *parent = 0);
    ~subwindow();

signals:
    void sendFileName(QString,int);

private slots:
    void on_OK_clicked();

private:
    Ui::subwindow *ui;    
};

#endif // SUBWINDOW_H
