#include "Bulb.h"

Bulb::Bulb(GraphicsInfo* r_GfxInfo) :Component(r_GfxInfo)
{
}

void Bulb::Draw(UI* pUI)
{
	//Call output class and pass Battery drawing info to it.
	pUI->DrawBulb(*m_pGfxInfo); //update to draw Battery.

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