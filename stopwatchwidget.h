#ifndef STOPWATCHWIDGET_H
#define STOPWATCHWIDGET_H
#include <QtCore>
#include <QWidget>
#include <QScxmlStateMachine>
#include <QLCDNumber>
#include <QPushButton>

class StopWatchWidget : public QWidget
{
    Q_OBJECT
public:
    StopWatchWidget(QScxmlStateMachine *m, QWidget* parent = 0);
private:
    void createUI();
    QString getTextTime() const;
    Q_SLOT void onTimeout();

    Q_SLOT void onReset(bool b);
    Q_SLOT void onStop(bool b);
    Q_SLOT void onRunning(bool b);

    Q_SLOT void onBtnReset();
    Q_SLOT void onBtnStart();
private:
    QScxmlStateMachine* m_machine;
    QLCDNumber* m_txt;

    QPushButton* m_reset;
    QPushButton* m_start;

    qint64 all_time;
    QElapsedTimer elaspe;
    QTimer* timer;
};

#endif // STOPWATCHWIDGET_H
