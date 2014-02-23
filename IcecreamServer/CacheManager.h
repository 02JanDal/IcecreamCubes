#pragma once

#include "BaseCacheManager.h"

namespace Cache
{
class CacheManager : public BaseCacheManager
{
	Q_OBJECT
public:
	CacheManager(QObject *parent = 0);
};
}
