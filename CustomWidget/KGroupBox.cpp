#include "KGroupBox.h"
#include "KVGroupBox.h"
KGroupBox::KGroupBox(const QString &title, QWidget *parent):
    QWidget(parent)
{

}

void KGroupBox::AddWidget(int colomn, QWidget *pWidget)
{
    if(colomn == 0)
    {
        m_pCentralWidget->AddWidget(pWidget);
    }
    else
    {
        m_pCentralWidget->AddWidget(pWidget);
    }
    update();
}

