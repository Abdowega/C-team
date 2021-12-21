#include "Ground.h"

Ground::Ground(GraphicsInfo* r_GfxInfo, string txt) :Component(r_GfxInfo)
{
	label = txt;
}

void Ground::Draw(UI* pUI)
{
	//Call output class and pass Battery drawing info to it.
	pUI->DrawGround(*m_pGfxInfo,label); //update to draw Battery.

}

void Ground::Operate()
{
}

void Ground::Save()
{
}

void Ground::Load()
{
}
