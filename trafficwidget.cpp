#include "trafficwidget.h"
#include <QtWidgets>

#include "lightwidget.h"

TrafficWidget::TrafficWidget(QScxmlStateMachine *m, QWidget *parent)
    :QWidget(parent)
    ,m_machine(m)
{
    QBoxLayout *vbox = new QVBoxLayout(this);

    LightWidget *red = new LightWidget(Qt::red);
    LightWidget *yellow = new LightWidget(Qt::yellow);
    LightWidget *green = new LightWidget(Qt::green);

    btn = new QPushButton("Broken");

    m_machine->connectToState("red", red, &LightWidget::switchLight);
    m_machine->connectToState("green", green, &LightWidget::switchLight);
    m_machine->connectToState("yellow", yellow, &LightWidget::switchLight);
    m_machine->connectToState("yellow", green, &LightWidget::switchLight);
    m_machine->connectToState("blinking", yellow, &LightWidget::switchLight);

    connect(btn, &QPushButton::clicked, this, &TrafficWidget::onBtnClicked);

    vbox->addWidget(red);
    vbox->addWidget(yellow);
    vbox->addWidget(green);
    vbox->addWidget(btn);
    m_machine->setParent(this);
    m_machine->start();
}

void TrafficWidget::onBtnClicked()
{
    if (m_machine->isActive("working"))
    {
        btn->setText("Working");
        m_machine->submitEvent("smash");
    }
    else
    {
        btn->setText("Broken");
        m_machine->submitEvent("repair");
    }
    qDebug() << m_machine->activeStateNames(false);
}
