#ifndef LIGHTWIDGET_H
#define LIGHTWIDGET_H
#include <QWidget>

class LightWidget : public QWidget
{
    Q_OBJECT
public:
    LightWidget(QColor color, QWidget *parent=0);
    void setOn(bool on);
    Q_SLOT void switchLight(bool onoff);
protected:
    virtual void paintEvent(QPaintEvent *event) override;
    virtual QSize sizeHint() const override;
private:
    QColor m_color;
    bool m_on;
};

#endif // LIGHTWIDGET_H
