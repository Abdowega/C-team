#include "Switch.h"


Switch::Switch(GraphicsInfo* r_GfxInfo,string txt) :Component(r_GfxInfo)
{
	label = txt;
}

void Switch::Draw(UI* pUI)
{
	//Call output class and pass Battery drawing info to it.
	pUI->DrawSwitch(*m_pGfxInfo,label); //update to draw Battery.

}

void Switch::Operate()
{
}

void Switch::Save()
{
}

void Switch::Load()
{
}
