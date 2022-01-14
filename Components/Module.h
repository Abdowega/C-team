#pragma once
#include "Components/Component.h"

class Module :public Component
{
public:
	Module(GraphicsInfo* r_GfxInfo);
	virtual void Draw(UI*);
	virtual void Operate();
	virtual void Load(int Value, string);
	virtual void SaveCircuit(ofstream& CircuitFile);
	virtual ALLCOMPS whichComponent();
};