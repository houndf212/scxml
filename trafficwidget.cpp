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

    QPushButton *btn = new QPushButton("Working");
    btn->setCheckable(true);

    m_machine->connectToState("red", red, &LightWidget::switchLight);
    m_machine->connectToState("green", green, &LightWidget::switchLight);
    m_machine->connectToState("yellow", yellow, &LightWidget::switchLight);
    m_machine->connectToState("yellow", green, &LightWidget::switchLight);
    m_machine->connectToState("blinking", yellow, &LightWidget::switchLight);

    connect(btn, &QPushButton::clicked,
                     [this, btn](bool b)
    {
        btn->setText(b ? "Broken" : "Wroking");
        m_machine->submitEvent(b ? "smash" : "repair");
    });

    vbox->addWidget(red);
    vbox->addWidget(yellow);
    vbox->addWidget(green);
    vbox->addWidget(btn);
    m_machine->setParent(this);
    m_machine->start();
}
