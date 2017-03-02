#ifndef TRAFFICWIDGET_H
#define TRAFFICWIDGET_H
#include <QWidget>
#include <QScxmlStateMachine>

class TrafficWidget : public QWidget
{
    Q_OBJECT
public:
    TrafficWidget(QScxmlStateMachine *m, QWidget* parent = 0);
private:
    QScxmlStateMachine *m_machine;
};

#endif // TRAFFICWIDGET_H
