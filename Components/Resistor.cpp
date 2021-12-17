#include "Resistor.h"

Resistor::Resistor(GraphicsInfo *r_GfxInfo, string txt):Component(r_GfxInfo)
{
	label = txt;

}

void Resistor::Draw(UI* pUI)
{
	//Call output class and pass resistor drawing info to it.
	pUI->DrawResistor(*m_pGfxInfo,label); //update to draw resistor

}

void Resistor::Operate()
{

}