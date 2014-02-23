#pragma once

#include "BasePhysicsManager.h"

namespace Physics
{
class PhysicsManager : public BasePhysicsManager
{
	Q_OBJECT
public:
	PhysicsManager(QObject *parent = 0);
};
}
