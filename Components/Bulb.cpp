#include "Bulb.h"

Bulb::Bulb(GraphicsInfo* r_GfxInfo,string txt):Component(r_GfxInfo)
{
	label = txt;

}

void Bulb::Draw(UI* pUI)
{
	//Call output class and pass Battery drawing info to it.
	pUI->DrawBulb(*m_pGfxInfo,label); //update to draw Battery.

}

void Bulb::Operate()
{
}

void Bulb::Save()
{
}

void Bulb::Load()
{
}