#pragma once
#include "Component.h"
#include "Switch.h"
#include "UI/UI.h"
class Switch  :
	public Component
{
public:
	Switch(GraphicsInfo* r_GfxInfo); ////for Battery to Draw itself

	virtual void Draw(UI*);	//Draws Bulb
	virtual void Operate();
	virtual void Save();
	virtual void Load();
};