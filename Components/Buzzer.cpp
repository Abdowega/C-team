#include "Buzzer.h"

Buzzer::Buzzer(GraphicsInfo* r_GfxInfo):Component(r_GfxInfo)
{

}

void Buzzer::Draw(UI* pUI)
{
	//Call output class and pass Battery drawing info to it.
	pUI->DrawBuzzer(*m_pGfxInfo); //update to draw Battery.

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
