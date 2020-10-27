#include "KReceivedImagesDialog.h"

#include <QDir>
#include <QFileInfo>
#include <QFile>
#include <QHeaderView>
#include <QCheckBox>

KReceivedImagesDialog::KReceivedImagesDialog(QWidget *parent):
    QDialog(parent)
{
    setWindowTitle("图像接收");
    setMinimumSize(900, 600);
    QVBoxLayout *pContentLayout = new QVBoxLayout();
    {
        m_pTableWidget = new QTableWidget(this);
        UpdateData();
        pContentLayout->addWidget(m_pTableWidget);
    }

    QHBoxLayout *pButtonLayout = new QHBoxLayout();
    {
        QPushButton *pCancelButton = new QPushButton("取消");
        connect(pCancelButton, &QPushButton::pressed, [=](){
            //UpdateData();
            this->close();
        });
        QPushButton *pAddToStudyButton = new QPushButton("添加到当前检查");
        connect(pAddToStudyButton, &QPushButton::pressed, [=](){
            //TODO

            int flag = 0;
            for(int i = 0;  i < m_pCheckBoxList.size(); i++)
            {
                if(m_pCheckBoxList[i]->isChecked())
                {
                    flag = 1;
                    break;
                }
            }
            if(flag == 0)
            {
                return;
            }

            {
                //TODO: Check Same Image
            }

            {
                //TODO: Copy && Delete Image

            }
            for(int i = 0;  i < m_pCheckBoxList.size(); i++)
            {
                if(!m_pCheckBoxList[i]->isChecked())
                {
                    continue;
                }
                QFile file(m_FilePathList[i]);
                file.remove();
            }

            this->close();
        });
        pButtonLayout->addWidget(new QLabel(""), 1);
        pButtonLayout->addWidget(pCancelButton);
        pButtonLayout->addWidget(pAddToStudyButton);
    }

    QVBoxLayout *pLayout = new QVBoxLayout(this);
    {
        pLayout->addLayout(pContentLayout, 1);
        pLayout->addLayout(pButtonLayout);
    }
    setLayout(pLayout);
    setStyleSheet("QPushButton {font-size : 15px; min-width: 100px; min-height: 30px}");
}

void KReceivedImagesDialog::UpdateData()
{
    m_pTableWidget->clear();
    m_pCheckBoxList.clear();
    m_FilePathList.clear();

    QString path = "./scp";
    QFileInfo fileinfo(path);
    QDir dir(path);
    if(!fileinfo.exists()){
        dir.mkdir(dir.absolutePath());
    }

    QFileInfoList infos = dir.entryInfoList();

     m_pTableWidget->setRowCount(infos.size() - 2);
     m_pTableWidget->setColumnCount(6);

     QStringList header;
     header << "one" << "two" << "three" << "four" << "five" << "six";
     m_pTableWidget->setHorizontalHeaderLabels(header);
    int row = 0;
    for(int i = 0; i < infos.size(); i++)
    {
        if(infos[i].fileName() == "." || infos[i].fileName() == "..")
        {
            continue;
        }

        {
            //TODO : Check If Dicom Image
        }
        m_FilePathList.append(infos[i].filePath());
        SetRow(row++, infos[i].fileName());
    }

    m_pTableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    m_pTableWidget->verticalHeader()->setVisible(false);

    m_pTableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    m_pTableWidget->horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents);
}

void KReceivedImagesDialog::SetRow(int row, const QString &path)
{
    //TODO
    QWidget *pWidget = new QWidget();
    QHBoxLayout *pLayout = new QHBoxLayout();
    QCheckBox *pCheckBox = new QCheckBox();
    m_pCheckBoxList.append(pCheckBox);
    pLayout->addWidget(m_pCheckBoxList[row]);
    pLayout->setAlignment(Qt::AlignCenter);
    pWidget->setLayout(pLayout);
    m_pTableWidget->setCellWidget(row, 0, pWidget);
    for(int i =  1; i < 6; i++)
    {
        QTableWidgetItem *pItem = new QTableWidgetItem(QString::number(i));
        pItem->setTextAlignment(Qt::AlignCenter);
        m_pTableWidget->setItem(row, i, pItem);
    }

}

