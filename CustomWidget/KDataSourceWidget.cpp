#include "KDataSourceWidget.h"
#include <QAbstractTableModel>
#include <QTableView>
#include <QModelIndex>
#include <QStandardItemModel>
#include <QListView>
#include <QTableWidget>
#include <QSize>
#include <QSizePolicy>
#include <QtDebug>
#include <QHBoxLayout>
#include <QHeaderVIew>
#include <QVBoxLayout>
#include <QLabel>
KDataSourceWidget::KDataSourceWidget(QWidget *parent) : QLabel(parent), m_Size(1000, 400)
{

    //setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
    //setMinimumSize(1000, 400);
    //setStyleSheet("background: red");
    QVBoxLayout *layout = new QVBoxLayout(this);

    setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
    qDebug() << size() ;
    QTableWidget *tableWidget; //= new QTableWidget(12, 3, this);
    tableWidget = new QTableWidget(10, 5, this);
    tableWidget->setRowCount(10);
    tableWidget->setColumnCount(5);
    //tableWidget->resize(QSize(600, 400));
    tableWidget->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
    for(int row = 0; row < 10; row++)
    {
        for(int column = 0; column < 5; column ++)
        {
            QTableWidgetItem *newItem = new QTableWidgetItem(tr("%1").arg(
                                                                 (row+1)*(column+1)));
            tableWidget->setItem(row, column, newItem);
        }
    }
    tableWidget->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);
    setStyleSheet("background: red");
    layout->addWidget(new QLabel("x"), 1);
    layout->addWidget(tableWidget, 1);
    setLayout(layout);
}

QSize KDataSourceWidget::sizeHint() const
{
    return m_Size;
}
