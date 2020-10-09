#include "KDictionaryDialog.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QTextEdit>
#include <QGroupBox>
#include <QMenu>

KDictionaryDialog::KDictionaryDialog(QWidget *parent):
    QDialog(parent)
{
    setWindowTitle("知识库管理");
    setMinimumSize(1200, 900);

    //搜索栏布局
    QHBoxLayout *pSearchLayout = new QHBoxLayout();
    {
        QPushButton *pSearchButton = new QPushButton("搜索");
        QLineEdit *pSearchEdit = new QLineEdit();
        pSearchLayout->addWidget(pSearchEdit, 1);
        pSearchLayout->addWidget(pSearchButton);
    }

    //树状控件布局
    QVBoxLayout *pTreeLayout = new QVBoxLayout();
    {
        QTreeWidget *pTree = new QTreeWidget();
        for(int i = 0; i < 10; i++)
        {
            QStringList list;
            list.append(QString::number(i));
            QTreeWidgetItem *pItem = new QTreeWidgetItem(pTree, list);
            pTree->addTopLevelItem(pItem);
            for(int j = 0; j < 4; j++)
            {
                QStringList sub_list;
                sub_list.append(QString::number(j));
                QTreeWidgetItem *pSubItem = new QTreeWidgetItem( pItem, sub_list);
                pItem->addChild(pSubItem);
            }
        }
        pTreeLayout->addWidget(pTree);
    }

    //侧边栏布局
    QVBoxLayout *pSidebarLayout = new QVBoxLayout();
    {
        pSidebarLayout->addLayout(pSearchLayout);
        pSidebarLayout->addLayout(pTreeLayout, 1);
    }
    //详情标题布局
    QHBoxLayout *pDetailTitleLayout = new QHBoxLayout();
    {
        QLineEdit *pTitleEdit = new QLineEdit();
        pDetailTitleLayout->addWidget(new QLabel("节点名称"));
        pDetailTitleLayout->addWidget(pTitleEdit);
    }
    //详情内容布局
    QVBoxLayout *pDetailContentLayout = new QVBoxLayout();
    {
        pDetailContentLayout->addWidget(new QLabel("文本内容:"));
        QTextEdit *pDetailContentEdit = new QTextEdit();
        //pDetailContentEdit->setMinimumHeight();
        pDetailContentLayout->addWidget(pDetailContentEdit, 1);
    }
    //详情区布局
    QVBoxLayout *pDetailLayout = new QVBoxLayout();
    {
        pDetailLayout->addLayout(pDetailTitleLayout);
        pDetailLayout->addLayout(pDetailContentLayout, 1);
    }

    //内容布局

    QHBoxLayout *pContentLayout = new QHBoxLayout();
    {
        pContentLayout->addLayout(pSidebarLayout);
        pContentLayout->addLayout(pDetailLayout, 1);
    }

    //按钮布局
    QHBoxLayout *pButtonLayout = new QHBoxLayout();
    {
        QPushButton *pCancelButton = new QPushButton("取消");
        pCancelButton->setMaximumWidth(100);
        QPushButton *pSaveButton = new QPushButton("保存");
        pSaveButton->setMaximumWidth(100);
        pButtonLayout->addWidget(new QLabel(""));
        pButtonLayout->addWidget(pCancelButton);
        pButtonLayout->addWidget(pSaveButton);
    }

    //最外层布局
    QVBoxLayout *pLayout = new QVBoxLayout(this);
    {
        pLayout->addLayout(pContentLayout, 1);
        pLayout->addLayout(pButtonLayout);
    }
    setLayout(pLayout);

    QString qss = QString("QLineEdit {font-size: 20px; height : 25px }\n")
                + QString("QLabel {font-size: 20px}\n")
                + QString("QTreeWidgetItem {font-size: 20px}\n")
                + QString("QPushButton {font-size: 20px}");

    setStyleSheet(qss);
}
