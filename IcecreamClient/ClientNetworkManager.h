#pragma once

#include "BaseClientNetworkManager.h"

namespace Network
{
class ClientNetworkManager : public BaseClientNetworkManager
{
	Q_OBJECT
public:
	ClientNetworkManager(QObject *parent = 0);
};
}
