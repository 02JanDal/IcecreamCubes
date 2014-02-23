#pragma once
#pragma GCC diagnostic ignored "-Wwrite-strings"

#include "BaseNetworkManager.h"

namespace Network
{
namespace ClientSentCodes
{
	static constexpr char *uiAction    = "UIA";
	static constexpr char *guiAction   = "GUI";
}
namespace ServerSentCodes
{
	static constexpr char *chunkUpdate     = "CUP";
	static constexpr char *chunkUnload     = "CUL";
	static constexpr char *chunkMetadata   = "CME";
	static constexpr char *blockUpdate     = "BUP";
	static constexpr char *guiAction       = "GUI";
	static constexpr char *entityUpdate    = "EUP";
	static constexpr char *entityUnload    = "EUL";
}

class NetworkManager : public BaseNetworkManager
{
	Q_OBJECT
public:
	NetworkManager(QObject *parent, const int port, const QString &player);
};
}
