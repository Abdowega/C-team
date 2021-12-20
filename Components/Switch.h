#pragma once
#include "Component.h"

class Switch: public Component
{
public:
	Switch(GraphicsInfo* r_GfxInfo);

	virtual void Draw(UI*);
	virtual void Operate();
	virtual void Save();
	virtual void Load();
};