#include "ActionPaste.h"
#include "..\ApplicationManager.h"
#include "..\UI\UI.h"
ActionPaste::ActionPaste(ApplicationManager* pApp) : Action(pApp)
{
}

ActionPaste::~ActionPaste(void)
{
}

void ActionPaste::Execute()
{

	UI* pUI = pManager->GetUI();
	pUI->ClearDrawingArea();
	pManager->UpdateInterface();

	pUI->PrintMsg("Choose where you want the copied comp1 to be drawn ");
	pUI->GetPointClicked(Cx, Cy);

	GraphicsInfo* pGInfo = new GraphicsInfo(2); //Gfx info to be used to construct the Comp
	int compWidth = pUI->getCompWidth();
	int compHeight = pUI->getCompHeight();
	pGInfo->PointsList[0].x = Cx - compWidth / 2;
	pGInfo->PointsList[0].y = Cy - compHeight / 2;
	pGInfo->PointsList[1].x = Cx + compWidth / 2;
	pGInfo->PointsList[1].y = Cy + compHeight / 2;
	Component* copycomp1 = pManager->getCopycomp1();
	copycomp1->set_GraphicsnewCordinates(pGInfo);
	copycomp1->get_GraphicsnewCordinates();
	pManager->AddComponent(copycomp1);
	pManager->UpdateInterface();
}

void ActionPaste::Undo()
{
}

void ActionPaste::Redo()
{
}
