#pragma once

#include <QLoggingCategory>

#define LOG_GENERAL LogGeneral
#define LOG_AI LogAI
#define LOG_CACHE LogCache
#define LOG_ENTITY LogEntity
#define LOG_NETWORK LogNetwork
#define LOG_PERMISSION LogPermission
#define LOG_PHYSICS LogPhysics
#define LOG_PLUGIN LogPlugin
#define LOG_SAVE LogSave

Q_DECLARE_LOGGING_CATEGORY(LOG_GENERAL)
Q_DECLARE_LOGGING_CATEGORY(LOG_AI)
Q_DECLARE_LOGGING_CATEGORY(LOG_CACHE)
Q_DECLARE_LOGGING_CATEGORY(LOG_ENTITY)
Q_DECLARE_LOGGING_CATEGORY(LOG_NETWORK)
Q_DECLARE_LOGGING_CATEGORY(LOG_PERMISSION)
Q_DECLARE_LOGGING_CATEGORY(LOG_PHYSICS)
Q_DECLARE_LOGGING_CATEGORY(LOG_PLUGIN)
Q_DECLARE_LOGGING_CATEGORY(LOG_SAVE)

void loggingFilter(QLoggingCategory *category);
void messageHandler(QtMsgType type, const QMessageLogContext &context, const QString &msg);
