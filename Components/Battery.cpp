#include "Battery.h"
Battery::Battery(GraphicsInfo* r_GfxInfo, string txt) :Component(r_GfxInfo)
{
	label = txt;

}

void Battery::Draw(UI* pUI)
{
	//Call output class and pass Battery drawing info to it.
	pUI->DrawBattery(*m_pGfxInfo,label); //update to draw Battery.

}

void Battery::Save()
{
}

void Battery::Load()
{
}

void Battery::Operate()
{

}
