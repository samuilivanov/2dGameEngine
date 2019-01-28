#include "log.h"

namespace SFGE {

    void Log::init()
    {
        qInfo() << "Supreme Fiesta Game Engine! praise the random name generator of github";
    }

    void Log::getCoreLogger(QtMsgType type, const QString &msg)
    {
        switch (type) {
        case QtDebugMsg:
            //TODO: to log into file
            qDebug() << msg;
            break;
        case QtInfoMsg:
            qInfo() << msg;
            break;
        case QtFatalMsg:
            qDebug() << msg;
            qFatal("Fatal err");
        case QtWarningMsg:
            qWarning() << msg;
            break;
        case QtSystemMsg:
            qInfo() << msg;
            break;
        }
    }

    void Log::getClientLogger(QtMsgType type, const QString &msg)
    {
        switch (type) {
        case QtDebugMsg:
            //TODO: to log into file
            qDebug() << msg;
            break;
        case QtInfoMsg:
            qInfo() << msg;
            break;
        case QtFatalMsg:
            qFatal("giving up :(");
        case QtWarningMsg:
            qWarning() << msg;
            break;
        case QtSystemMsg:
            qInfo() << msg;
            break;
        }
    }
}
