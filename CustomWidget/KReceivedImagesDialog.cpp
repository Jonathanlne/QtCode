#include "KReceivedImagesDialog.h"

#include <QDir>
#include <QFileInfo>
#include <QFile>
#include <QHeaderView>
#include <QCheckBox>
#include <QTimer>
#include <QMap>

KReceivedImagesDialog::KReceivedImagesDialog(QWidget *parent):
    QDialog(parent),
    m_Path("./scp")
{
    setWindowTitle("图像接收");
    setMinimumSize(900, 600);

    connect(&m_Timer, &QTimer::timeout, this, &KReceivedImagesDialog::CheckNewData);

    QVBoxLayout *pContentLayout = new QVBoxLayout();
    {
        m_pTableWidget = new QTableWidget(this);
        UpdateData();
        pContentLayout->addWidget(m_pTableWidget);
    }

    QHBoxLayout *pButtonLayout = new QHBoxLayout();
    {
        QPushButton *pSelectAllButton = new QPushButton("全选");
        connect(pSelectAllButton, &QPushButton::pressed, [=](){
            for(int i = 0; i < m_pCheckBoxList.size(); i++)
            {
                m_pCheckBoxList[i]->setChecked(true);
            }
        });

        QPushButton *pSelectZeroButton = new QPushButton("全不选");
        connect(pSelectZeroButton, &QPushButton::pressed, [=](){
            for(int i = 0; i < m_pCheckBoxList.size(); i++)
            {
                m_pCheckBoxList[i]->setChecked(false);
            }
        });

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
        pButtonLayout->addWidget(pSelectAllButton);
        pButtonLayout->addWidget(pSelectZeroButton);
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
    m_Timer.setInterval(100);
    m_Timer.start();
}

void KReceivedImagesDialog::UpdateData()
{
    m_pTableWidget->clear();
    m_pCheckBoxList.clear();
    m_FilePathList.clear();

    QFileInfo fileinfo(m_Path);
    QDir dir(m_Path);
    if(!fileinfo.exists()){
        dir.mkdir(dir.absolutePath());
    }

    QFileInfoList infos = dir.entryInfoList();

    int dicomFileCnt = 0;
    for(int i = 0; i < infos.size(); i++)
    {
        if(infos[i].fileName() == "." || infos[i].fileName() == ".." || infos[i].isDir())
        {
            continue;
        }

        {
            //TODO : Check If Dicom Image
            dicomFileCnt++;
            m_FilePathList.append(infos[i].filePath());
            m_FileNameSet.insert(infos[i].fileName());
        }
    }
     m_pTableWidget->setRowCount(dicomFileCnt);
     m_pTableWidget->setColumnCount(6);

     QStringList header;
     header << "one" << "two" << "three" << "four" << "five" << "six";
     m_pTableWidget->setHorizontalHeaderLabels(header);
    for(int i = 0; i < dicomFileCnt; i++)
    {
        SetRow(i);
    }

    m_pTableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    m_pTableWidget->verticalHeader()->setVisible(false);

    m_pTableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    m_pTableWidget->horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents);
}

void KReceivedImagesDialog::CheckNewData()
{
    QDir dir(m_Path);
    QFileInfoList infos = dir.entryInfoList();

    int dicomFileCnt = 0;
    for(QFileInfo info : infos)
    {
        if(info.isDir() || info.fileName() == "." || info.fileName() == "..")
        {
            continue;
        }
        if(m_FileNameSet.find(info.fileName()) == m_FileNameSet.end())
        {
            //TODO : ASK to reload data


            {
                //TODO : Check If Dicom Image
            }

            UpdateData();
            break;
        }
        dicomFileCnt ++;
    }

    if(dicomFileCnt < m_FileNameSet.size())
    {
        //TODO : ASK to reload data


        UpdateData();
        return;
    }
}

void KReceivedImagesDialog::SetRow(int row)
{
    //TODO
    QWidget *pWidget = new QWidget();
    QHBoxLayout *pLayout = new QHBoxLayout();
    QCheckBox *pCheckBox = new QCheckBox();
    pCheckBox->setChecked(true);
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

KReceivedImagesDialog::~KReceivedImagesDialog()
{
    m_Timer.stop();
}

