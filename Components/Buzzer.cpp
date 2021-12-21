#include "Buzzer.h"

Buzzer::Buzzer(GraphicsInfo* r_GfxInfo, string txt):Component(r_GfxInfo)
{
	label = txt;
}

void Buzzer::Draw(UI* pUI)
{
	//Call output class and pass Battery drawing info to it.
	pUI->DrawBuzzer(*m_pGfxInfo, label); //update to draw Battery.

}

void Buzzer::Operate()
{
}

void Buzzer::Save()
{
}

void Buzzer::Load()
{
}
