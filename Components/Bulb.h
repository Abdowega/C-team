#pragma once
#include "Component.h"


class Bulb: public Component
{
public:
	Bulb(GraphicsInfo* r_GfxInfo); ////for Battery to Draw itself

	virtual void Draw(UI*);	//Draws Bulb
	virtual void Operate();
	virtual void Save();
	virtual void Load();
};
