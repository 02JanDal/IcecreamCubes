#pragma once

#include "BaseSaveManager.h"

namespace Saves
{
class SaveManager : public BaseSaveManager
{
	Q_OBJECT
public:
	SaveManager(QObject *parent, const QDir &savePath);
};
}
