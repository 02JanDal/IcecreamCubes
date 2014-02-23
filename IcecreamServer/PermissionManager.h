#pragma once

#include "BasePermissionManager.h"

namespace Permissions
{
class PermissionManager : public BasePermissionManager
{
	Q_OBJECT
public:
	PermissionManager(QObject *parent = 0);
};
}
