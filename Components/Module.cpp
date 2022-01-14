#include"Module.h"
#include"ApplicationManager.h"
#include"UI/UI.h"
#include"Actions/Action.h"
Module::Module(GraphicsInfo* r_GfxInfo) :Component(r_GfxInfo)
{
	resistance = 2;
	sourceVoltage = 0;
}

void Module::Draw(UI* pUI)
{
	int xlabel = m_pGfxInfo->PointsList[0].x;
	int ylabel = m_pGfxInfo->PointsList[0].y + 50;

	pUI->labelMsg(getlabel(), xlabel, ylabel);
	pUI->DrawModule(*m_pGfxInfo, selected);
}
void Module::SaveCircuit(ofstream& CircuitFile)
{
	string s = getlabel();
	if (getlabel() == "")
		setlabel("Module");
	CircuitFile << "MOD1" << "\t" << ID << "\t" << getLabel() << "\t" << resistance << "\t" << m_pGfxInfo->PointsList[0].x
		<< "\t" << m_pGfxInfo->PointsList[0].y << endl;
	ID++;
	setlabel(s);
}
void Module::Operate()
{

}
void Module::Load(int Value, string Label)
{
	resistance = Value;
	setlabel(Label);
}
ALLCOMPS Module::whichComponent()
{
	return 	MODULE_1;
}