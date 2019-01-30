#ifndef LOG_H
#define LOG_H

#include <QtGlobal>
#include <QDebug>
#include "src/core.h"

namespace SFGE {

    class SFGE_API Log
    {
    public:

        static void init();
        static void getCoreLogger(QtMsgType type, const QString &msg);
        static void getClientLogger(QtMsgType type, const QString &msg);

    private:
        //TODO:
    };
}
// TODO: be able to acept multiple arguments
// Core log macros
#define SFGE_CORE_INFO(x)       ::SFGE::Log::getCoreLogger(QtInfoMsg, x)
#define SFGE_CORE_WARN(x)       ::SFGE::Log::getCoreLogger(QtWarningMsg, x)
#define SFGE_CORE_ERROR(x)      ::SFGE::Log::getCoreLogger(QtDebugMsg, x)
#define SFGE_CORE_FATAL(x)      ::SFGE::Log::getCoreLogger(QtFatalMsg, x)

// Client log macros
#define SFGE_INFO(x)            ::SFGE::Log::getCoreLogger(QtInfoMsg, x)
#define SFGE_WARN(x)            ::SFGE::Log::getCoreLogger(QtWarningMsg, x)
#define SFGE_ERROR(x)           ::SFGE::Log::getCoreLogger(QtDebugMsg, x)
#define SFGE_FATAL(x)           ::SFGE::Log::getCoreLogger(QtFatalMsg, x)
#endif // LOG_H
