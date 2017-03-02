#include "lightwidget.h"
#include <QPainter>

LightWidget::LightWidget(QColor color, QWidget *parent)
    :QWidget(parent)
    ,m_color(color)
    ,m_on(false)
{
    setFixedSize(sizeHint());
}

void LightWidget::setOn(bool on)
{
    if (on == m_on)
        return;
    m_on = on;
    update();
}

void LightWidget::switchLight(bool onoff)
{
    setOn(onoff);
}

void LightWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    if (!m_on)
        return;

    QPainter p(this);
    p.setBrush(m_color);
    p.setRenderHint(QPainter::Antialiasing);
    p.drawEllipse(QRect(2, 2, this->width()-4, this->height()-4));
}

QSize LightWidget::sizeHint() const
{
    return QSize(100, 100);
}
