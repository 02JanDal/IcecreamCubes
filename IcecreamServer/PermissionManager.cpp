#include "PermissionManager.h"

#include <QStringList>
#include <QCoreApplication>

#include "NetworkManager.h"
#include "Logging.h"

using namespace Permissions;

PermissionManager::PermissionManager(QObject *parent) : BasePermissionManager(parent)
{
}
