#pragma once

#include "BasePluginManager.h"

namespace Plugins
{
class PluginManager : public BasePluginManager
{
	Q_OBJECT
public:
	PluginManager(QObject *parent, const QDir &pluginPath);
};
}
