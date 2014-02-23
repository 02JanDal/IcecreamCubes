#include "NetworkManager.h"

using namespace Network;

NetworkManager::NetworkManager(QObject *parent, const int port, const QString &player) : BaseNetworkManager(parent, port, player)
{
}
