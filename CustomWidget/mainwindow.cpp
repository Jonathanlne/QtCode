#include "mainwindow.h"
#include "KInputBox.h"
#include <QIntValidator>
#include <QDateEdit>
#include <QLineEdit>
#include "KGroupBox.h"
#include "KVGroupBox.h"
#include "KDataSourceWidget.h"
#include <QTableWidget>
#include <QtDebug>
#include "KDictionaryDialog.h"
#include "KReceivedImagesDialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    setMinimumSize(1200, 900);
    /*
    setBaseSize(1000, 600);
    setMinimumSize(1000, 600);
    QTableWidget *tableWidget = new QTableWidget(12, 3, this);
    tableWidget->setMinimumSize(1000, 600);
    tableWidget = new QTableWidget(this);
    tableWidget->setRowCount(10);
    tableWidget->setColumnCount(5);
    //tableWidget->resize(QSize(600, 400));
    tableWidget->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
    tableWidget->setStyleSheet("background: red");
    for(int row = 0; row < 10; row++)
    {
        for(int column = 0; column < 5; column ++)
        {
            QTableWidgetItem *newItem = new QTableWidgetItem(tr("%1").arg(
                                                                 (row+1)*(column+1)));
            tableWidget->setItem(row, column, newItem);
        }
    }
    */
    qDebug() << size() ;
    KReceivedImagesDialog dialog;
    dialog.exec();
    setCentralWidget(new KDataSourceWidget(this));
    setStyleSheet("background: yellow");
}

MainWindow::~MainWindow()
{

}
