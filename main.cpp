#include <QApplication>
#include <QtCore>
#include "trafficwidget.h"
#include "stopwatchwidget.h"

QScxmlStateMachine *init_traffic()
{
    QScxmlStateMachine *machine = QScxmlStateMachine::fromFile(":/light.scxml");
    if (!machine->parseErrors().isEmpty())
    {
        QTextStream errs(stderr, QIODevice::WriteOnly);
        const auto errors = machine->parseErrors();
        for (const QScxmlError &error : errors) {
            errs << error.toString();
        }

        exit(-1);
    }
    qDebug() << machine->name();
    return machine;
}

QScxmlStateMachine *init_stopwatch()
{

    int dd = 12;
    char b = dd;
    qDebug() << b ;


    QScxmlStateMachine *machine = QScxmlStateMachine::fromFile(":/stopwatch.scxml");
    if (!machine->parseErrors().isEmpty())
    {
        QTextStream errs(stderr, QIODevice::WriteOnly);
        const auto errors = machine->parseErrors();
        for (const QScxmlError &error : errors) {
            errs << error.toString();
        }

        exit(-2);
    }
    qDebug() << machine->name();
    return machine;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

//    TrafficWidget w(init_traffic());
//    w.show();
    StopWatchWidget stopwatch(init_stopwatch());
    stopwatch.show();

    return a.exec();
}
