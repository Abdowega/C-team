#include "Fuse.h"

Fuse::Fuse(GraphicsInfo* r_GfxInfo, string txt) :Component(r_GfxInfo)
{
	label = txt;
}

void Fuse::Draw(UI* pUI)
{
	//Call output class and pass Battery drawing info to it.
	pUI->DrawFuse(*m_pGfxInfo,label); //update to draw Battery.

}

void Fuse::Operate()
{
}

void Fuse::Save()
{
}

void Fuse::Load()
{
}
