#pragma once
#include "Component.h"

class Resistor:public Component
{
public:
	Resistor(GraphicsInfo* r_GfxInfo, string txt = "");
	virtual void Operate();	//Calculates the volt on both terminals
	virtual void Draw(UI*);	//Draws the resistor

};
