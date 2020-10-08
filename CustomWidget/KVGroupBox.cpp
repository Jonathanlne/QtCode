#include "KVGroupBox.h"

KVGroupBox::KVGroupBox(QWidget *parent)
{
    m_pLayout = new QVBoxLayout(this);
    setLayout(m_pLayout);
}

void KVGroupBox::AddWidget(QWidget *widget)
{
    m_pLayout->addWidget(widget);
}
