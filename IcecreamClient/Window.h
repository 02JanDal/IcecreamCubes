#pragma once

#include "BaseWindow.h"

namespace GUI
{
class Window : public BaseWindow
{
	Q_OBJECT
public:
	explicit Window(QWindow *parent = 0);
};
}
