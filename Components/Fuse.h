#pragma once
#include "Component.h"

class Fuse: public Component
{
public:
	Fuse(GraphicsInfo* r_GfxInfo); ////for Battery to Draw itself

	virtual void Draw(UI*);	//Draws Fuse
	virtual void Operate();
	virtual void Save();
	virtual void Load();
};
