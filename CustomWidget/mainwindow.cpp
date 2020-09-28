#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "KInputBox.h"
#include <QIntValidator>
#include <QDateEdit>
#include <QLineEdit>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    KInputBox *widget = new KInputBox("测试", KInputBox::Text);
    widget->SetWidth(1000);
    /*
    widget->AppendText("cm", 150);
    widget->AppendWidget(new QDateEdit(), 150, 1);
    widget->AppendWidget(new QLineEdit());
    widget->AppendWidget(new QLineEdit());
    widget->AppendWidget(new QLineEdit());
    widget->SetDate("2018-08-13");
    widget->AddInputWidget(4);

    //widget->AddComboItem();
    QList<QString> list;
    list.append("1");
    list.append("12");
    list.append("13");
    list.append("14");
    widget->AddComboItem(list);
    widget->SetLabelWidth(150);
    widget->SetInput(30);
    //widget->SetEditable(false);
    widget->SetInput(list);
    //widget->setEnabled(false);
    //widget->show();
    widget->SetFontSize(16);
    widget->SetValidator(new QIntValidator());
    */
    widget->AppendText("this is a demo", 0, 1);
    setCentralWidget(widget);
}

MainWindow::~MainWindow()
{
    delete ui;
}
