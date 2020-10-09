#pragma

#include <QWidget>
#include <QLabel>

class QSize;
class KDataSourceWidget : public QLabel
{
    Q_OBJECT
public:
    KDataSourceWidget(QWidget *parent = nullptr);

signals:

public slots:

protected:
    QSize sizeHint() const override;
private:
    QSize m_Size;
};

