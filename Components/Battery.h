#pragma once
#include "Component.h"

class Battery :public Component
{
public :
		Battery(GraphicsInfo* r_GfxInfo,string txt =""); //for Battery to Draw itself

		virtual void Draw(UI*);	//Draws the Battery
		virtual void Operate();
		virtual void Save() ;
		virtual void Load() ;
};