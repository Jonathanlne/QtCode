#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "InputWidget.h"

#include <QDateEdit>
#include <QLineEdit>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    InputWidget *widget = new InputWidget("测试", InputWidget::Date);
    widget->AppendText("cm", 150);
    widget->AppendWidget(new QDateEdit(), 150, 1);
    widget->AppendWidget(new QLineEdit());
    widget->AppendWidget(new QLineEdit());
    widget->AppendWidget(new QLineEdit());
    widget->SetDate("2018-08-13");
    QList<QString> list;
    list.append("1");
    list.append("12");
    list.append("13");
    list.append("14");

    widget->SetLabelWidth(150);
    widget->SetInput(30);
    widget->SetEditable(false);
    widget->SetInput(list);
    //widget->setEnabled(false);
    //widget->show();
    setCentralWidget(widget);
}

MainWindow::~MainWindow()
{
    delete ui;
}
