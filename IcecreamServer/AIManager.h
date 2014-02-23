#pragma once

#include "BaseAIManager.h"

namespace AI
{
class AIManager : public BaseAIManager
{
	Q_OBJECT
public:
	AIManager(QObject *parent = 0);
};
}
