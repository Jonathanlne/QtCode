#include <QWidget>

#include <QVBoxLayout>
class KVGroupBox : public QWidget
{
public:
    KVGroupBox(QWidget *parent = nullptr);
    void AddWidget(QWidget *widget);
private:
    QVBoxLayout *m_pLayout;
};

