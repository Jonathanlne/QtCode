#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "KInputBox.h"
#include <QIntValidator>
#include <QDateEdit>
#include <QLineEdit>
#include "KGroupBox.h"
#include "KVGroupBox.h"
#include "KDataSourceWidget.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setCentralWidget(new KDataSourceWidget());
}

MainWindow::~MainWindow()
{
    delete ui;
}
