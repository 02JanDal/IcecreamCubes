#pragma once

#include "BaseResourceCacheManager.h"

namespace GUI
{
class ResourceCacheManager : public BaseResourceCacheManager
{
	Q_OBJECT
public:
	ResourceCacheManager(QObject *parent = 0);
};
}
