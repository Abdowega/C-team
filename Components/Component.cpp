#include "Component.h"

Component::Component(GraphicsInfo *r_GfxInfo)
{
	m_pGfxInfo = r_GfxInfo;	
}

Component::Component()
{
	m_pGfxInfo = nullptr;
	term1_volt = term2_volt = 0;
	term1_conn_count = term2_conn_count = 0;

}

void Component::SetLabel( string mlabel) 
{
	m_Label = mlabel;
}

bool Component::InRegion(int x_x, int y_y) 
{
	if (x_x > m_pGfxInfo->PointsList[0].x && x_x < m_pGfxInfo->PointsList[1].x &&
		y_y > m_pGfxInfo->PointsList[0].y && y_y < m_pGfxInfo->PointsList[1].y)
	{
		return true;
	}
	return false;
}

Component::~Component()
{}

