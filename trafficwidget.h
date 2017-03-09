#ifndef TRAFFICWIDGET_H
#define TRAFFICWIDGET_H
#include <QWidget>
#include <QScxmlStateMachine>
#include <QPushButton>

class TrafficWidget : public QWidget
{
    Q_OBJECT
public:
    TrafficWidget(QScxmlStateMachine *m, QWidget* parent = 0);
private:
    Q_SLOT void onBtnClicked();
private:
    QScxmlStateMachine *m_machine;
    QPushButton *btn;
};

#endif // TRAFFICWIDGET_H
