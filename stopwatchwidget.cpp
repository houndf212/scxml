#include "stopwatchwidget.h"
#include <QHBoxLayout>

StopWatchWidget::StopWatchWidget(QScxmlStateMachine *m, QWidget *parent)
    :QWidget(parent)
    ,m_machine(m)
    ,all_time(0)
{

    createUI();

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &StopWatchWidget::onTimeout);
    timer->start(100);

    m_machine->connectToState("reset", this, &StopWatchWidget::onReset);
    m_machine->connectToState("run", this, &StopWatchWidget::onRunning);
    m_machine->connectToState("stop", this, &StopWatchWidget::onStop);
    m_machine->start();
    this->resize(360, 160);
}

void StopWatchWidget::createUI()
{
    m_txt = new QLCDNumber;
    m_txt->setDigitCount(9);

    m_reset = new QPushButton("reset");
    m_start = new QPushButton("start");

    connect(m_reset, &QPushButton::clicked, this, &StopWatchWidget::onBtnReset);
    connect(m_start, &QPushButton::clicked, this, &StopWatchWidget::onBtnStart);

    QBoxLayout* vlayout = new QVBoxLayout;
    vlayout->addWidget(m_txt);
    vlayout->addWidget(m_start);
    vlayout->addWidget(m_reset);
    setLayout(vlayout);
}

QString StopWatchWidget::getTextTime() const
{
    qint64 all = all_time;
    if (elaspe.isValid())
    {
       all += elaspe.elapsed();
    }

    qint64 min = all / 1000 / 60 % 60;
    qint64 sec = all / 1000 % 60;
    qint64 msec = all % 1000;
    static const QString tt = "%1:%2:%3";
    static const QChar fill_char('0');
    QString txt = tt
            .arg(min,2,10,fill_char)
            .arg(sec,2,10,fill_char)
            .arg(msec,3,10,fill_char);

    return txt;
}

void StopWatchWidget::onTimeout()
{
    if (m_machine->isActive("run"))
        m_txt->display(getTextTime());
}

void StopWatchWidget::onReset(bool b)
{
    if (!b) return;

    m_txt->display("00:00:000");
    all_time = 0;
    elaspe.invalidate();
    m_reset->setEnabled(false);
    m_start->setEnabled(true);
    m_start->setText("start");
}

void StopWatchWidget::onStop(bool b)
{
    if (!b) return;

    all_time += elaspe.elapsed();
    elaspe.invalidate();
    m_start->setText("start");
}

void StopWatchWidget::onRunning(bool b)
{
    if (!b) return;

    elaspe.restart();
    m_start->setText("stop");
    m_reset->setEnabled(true);
}

void StopWatchWidget::onBtnReset()
{
    m_machine->submitEvent("reset_click");
}

void StopWatchWidget::onBtnStart()
{
    m_machine->submitEvent("start_click");
}
