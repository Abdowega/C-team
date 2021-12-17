#pragma once
#include "Component.h"
#include "UI/UI.h"
class Battery :public Component
{
public :
		Battery(GraphicsInfo* r_GfxInfo); ////for Battery to Draw itself

		virtual void Draw(UI*);	//Draws the Battery
		virtual void Operate();
		virtual void Save() ;
		virtual void Load() ;
};