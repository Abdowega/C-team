#pragma once
#include "Component.h"

class Ground: public Component
{
public:
	Ground(GraphicsInfo* r_GfxInfo, string txt = ""); ////for Battery to Draw itself

	virtual void Draw(UI*);	//Draws Bulb
	virtual void Operate();
	virtual void Save();
	virtual void Load();
};

