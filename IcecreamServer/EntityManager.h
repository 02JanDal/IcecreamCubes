#pragma once

#include "BaseEntityManager.h"

namespace Entities
{
class EntityManager : public BaseEntityManager
{
	Q_OBJECT
public:
	EntityManager(QObject *parent = 0);
};
}
