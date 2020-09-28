#include "KInputBox.h"

#include <QLineEdit>
#include <QLabel>
#include <QHBoxLayout>
#include <QDateEdit>
#include <QCalendarWidget>
#include <QList>
#include <QComboBox>
#include <QDoubleValidator>
const int DEFAULT_WIDTH     = 300;
const int DEFAULT_HEIGHT    = 30;
const int DEFAULT_FONT_SIZE = 12;

KInputBox::KInputBox(const QString &tItemName, const InputType &type,
                         QWidget *parent):
    QWidget(parent),
    m_pLineEdit(nullptr),
    m_pItemName(nullptr),
    m_pDateEdit(nullptr),
    m_pComboBox(nullptr),
    m_FontSize(DEFAULT_FONT_SIZE)
{
    m_pLayout = new QHBoxLayout(this);

    if(tItemName.length() != 0)
    {
        m_pItemName = new QLabel(tItemName);
        m_pItemName->setAlignment(Qt::AlignVCenter | Qt::AlignRight);
        const int ITEM_NAME_WEIGHT = 1;
        m_pLayout->addWidget(m_pItemName, ITEM_NAME_WEIGHT);
    }

    if(type == Text)
    {
        m_pLineEdit = new QLineEdit();
        m_pLineEdit->setMinimumWidth(DEFAULT_WIDTH);
        m_pLayout->addWidget(m_pLineEdit);
        m_InputList.append(m_pLineEdit);
        m_WidgetList.append(m_pLineEdit);

    }
    else if(type == ComboBox)
    {
        m_pComboBox = new QComboBox();
        m_pLayout->addWidget(m_pComboBox);
        m_WidgetList.append(m_pComboBox);
    }
    else
    {
        m_pDateEdit = new QDateEdit();
        m_pDateEdit->setDate(QDate::currentDate());
        m_pDateEdit->setCalendarPopup(true);
        m_pDateEdit->setAlignment(Qt::AlignCenter);
        m_pDateEdit->setCalendarWidget(new QCalendarWidget());
        m_pDateEdit->setMinimumWidth(DEFAULT_WIDTH);
        m_pLayout->addWidget(m_pDateEdit);
        m_WidgetList.append(m_pDateEdit);
    }

    SetHeight(DEFAULT_HEIGHT);
    SetFontSize(m_FontSize);
    setLayout(m_pLayout);
}

std::string KInputBox::GetInput()
{
    if(m_pLineEdit)
        return m_pLineEdit->text().toStdString();
    return "";
}

int KInputBox::GetInputInt()
{
    if(m_pLineEdit == nullptr)
        return 0;
    return m_pLineEdit->text().toInt();
}

double KInputBox::GetInputDouble()
{
    if(m_pLineEdit == nullptr)
        return 0;
    return m_pLineEdit->text().toDouble();
}

QDate KInputBox::GetDate()
{
    if(m_pDateEdit == nullptr)
        return QDate();
    return m_pDateEdit->date();
}

void KInputBox::AddInputWidget(int num, const QList<int> &widths, const QList<int> &weights)
{
    for(int i = 0; i < num; i++)
    {
        if(widths.size() > i && weights.size() > i)
        {
            AppendWidget(new QLineEdit(), widths[i], weights[i]);
        }
        else if(widths.size() > i)
        {
            AppendWidget(new QLineEdit(), widths[i], 0);
        }
        else if(weights.size() > i)
        {
            AppendWidget(new QLineEdit(), 0, weights[i]);
        }
        else
        {
            AppendWidget(new QLineEdit());
        }
    }
}

void KInputBox::AddComboItem(const QString &item)
{
    if(m_pComboBox)
        m_pComboBox->addItem(item);
}

void KInputBox::AddComboItem(const QList<QString> &list)
{
    if(m_pComboBox)
        m_pComboBox->addItems(list);
}

void KInputBox::SetInput(const std::string &text)
{
    if(m_pLineEdit)
        m_pLineEdit->setText(QString(text.c_str()));
}

void KInputBox::SetInput(int number)
{
    if(m_pLineEdit)
        m_pLineEdit->setText(QString::number(number));
}

void KInputBox::SetInput(const QList<QString> &list)
{
    for(int i = 0; i < m_InputList.size(); i++)
    {
        if(i >= list.size())
            return;
        m_InputList[i]->setText(list[i]);
    }
}

void KInputBox::SetInput(const QList<int> &list)
{
    for(int i = 0; i < m_InputList.size(); i++)
    {
        if(i >= list.size())
            return;
        SetInput(list[i]);
    }
}

void KInputBox::SetInput(const QList<double> &list)
{
    for(int i = 0; i < m_InputList.size(); i++)
    {
        if(i >= list.size())
            return;
        SetInput(list[i]);
    }
}

void KInputBox::SetInput(double number)
{
    if(m_pLineEdit)
        m_pLineEdit->setText(QString::number(number));
}

void KInputBox::SetEditable(bool editable)
{
    if(m_pLineEdit != nullptr)
    {
        m_pLineEdit->setEnabled(editable);
    }
    else if(m_pDateEdit != nullptr)
    {
        m_pDateEdit->setEnabled(editable);
    }
}

void KInputBox::SetDate(const QDate &date)
{
    if(m_pDateEdit)
        m_pDateEdit->setDate(date);
}

void KInputBox::SetDate(const QString &tDateString, const QString &format)
{
    if(m_pDateEdit)
        m_pDateEdit->setDate(QDate::fromString(tDateString, format));
}

void KInputBox::SetDate(int y, int m, int d)
{
    if(m_pDateEdit)
        m_pDateEdit->setDate(QDate(y, m, d));
}

void KInputBox::SetHeight(int tHeight)
{
    if(m_pLineEdit != nullptr)
    {
        m_pLineEdit->setMinimumHeight(tHeight);
        m_pLineEdit->setMaximumHeight(tHeight);
    }
    else if(m_pDateEdit != nullptr)
    {
        m_pDateEdit->setMinimumHeight(tHeight);
        m_pDateEdit->setMaximumHeight(tHeight);
    }
}

void KInputBox::SetInputWidth(int tWidth)
{
    if(m_pLineEdit != nullptr)
    {
        m_pLineEdit->setMinimumWidth(tWidth);
        m_pLineEdit->setMaximumWidth(tWidth);
    }
    else if(m_pDateEdit != nullptr)
    {
        m_pDateEdit->setMinimumWidth(tWidth);
        m_pDateEdit->setMaximumWidth(tWidth);
    }
    else if(m_pComboBox != nullptr)
    {
        m_pComboBox->setMinimumWidth(tWidth);
        m_pComboBox->setMaximumWidth(tWidth);
    }
}

void KInputBox::SetLabelWidth(int tWidth)
{
    if(m_pItemName != nullptr)
    {
        m_pItemName->setMinimumWidth(tWidth);
        m_pItemName->setMaximumWidth(tWidth);
    }
}

void KInputBox::SetWidth(int tWidth)
{
    //resize(tWidth, height());
    setMinimumWidth(tWidth);
}

void KInputBox::SetFontSize(int tSize)
{
    m_FontSize = tSize;
    if(m_pItemName != nullptr)
        m_pItemName->setFont(QFont((m_pItemName->font()).family(), tSize));
    if(m_pLineEdit)
    {
        m_pLineEdit->setFont(QFont((m_pLineEdit->font()).family(), tSize));
    }
    else if(m_pDateEdit)
    {
        m_pDateEdit->setFont(QFont((m_pDateEdit->font()).family(), tSize));
    }
    else if(m_pComboBox)
    {
        m_pComboBox->setFont(QFont((m_pComboBox->font()).family(), tSize));
    }
    for(int i = 0; i < m_InputList.size(); i++)
    {
        m_InputList[i]->setFont(QFont((m_InputList[i]->font()).family(), tSize));
    }
    for(int i = 0; i < m_WidgetList.size(); i++)
    {
        m_WidgetList[i]->setFont(QFont((m_WidgetList[i]->font()).family(), tSize));
    }
}

void KInputBox::AppendWidget(QLineEdit *pWidget, int width,  int weight)
{
    if(weight)
    {
        m_pLayout->addWidget(pWidget, weight);
    }
    else
    {
        m_pLayout->addWidget(pWidget);
    }
    if(width)
    {
        pWidget->setMinimumWidth(width);
        pWidget->setMaximumWidth(width);
    }
    pWidget->setFont(QFont(pWidget->font().family(), m_FontSize));
    m_InputList.append(pWidget);
    m_WidgetList.append(pWidget);
}

void KInputBox::AppendWidget(QWidget *pWidget, int width, int weight)
{
    if(weight)
    {
        m_pLayout->addWidget(pWidget, weight);
    }
    else
    {
        m_pLayout->addWidget(pWidget);
    }
    if(width)
    {
        pWidget->setMinimumWidth(width);
        pWidget->setMaximumWidth(width);
    }
    pWidget->setFont(QFont(pWidget->font().family(), m_FontSize));
    m_WidgetList.append(pWidget);
}

void KInputBox::AppendText(const QString &text, int width,  int weight)
{
    QLabel *tLabel = new QLabel(text);
    if(width)
    {
        tLabel->setMinimumWidth(width);
        tLabel->setMaximumWidth(width);
    }
    tLabel->setFont(QFont(tLabel->font().family(), m_FontSize));
    if(weight)
    {
        m_pLayout->addWidget(tLabel, weight);
    }
    else
    {
        m_pLayout->addWidget(tLabel);
    }
}

void KInputBox::InsertWidget(int index, QWidget *pWidget, int width, int weight)
{
    pWidget->setMinimumWidth(width);
    pWidget->setMaximumWidth(width);
    m_pLayout->insertWidget(index, pWidget, weight);
}

void KInputBox::SetValidator(const QValidator *validator)
{
    for(int i = 0; i < m_InputList.size(); i++)
    {
        m_InputList[i]->setValidator(validator);
    }
}

