#pragma once
#include "Component.h"
#include "UI/UI.h"
class Buzzer :
	public Component
{
public:
	Buzzer(GraphicsInfo* r_GfxInfo); ////for Battery to Draw itself

	virtual void Draw(UI*);	//Draws Bulb
	virtual void Operate();
	virtual void Save();
	virtual void Load();
};
