#include "ActionAddFuze.h"
#include "..\ApplicationManager.h"
#include "UI/UI.cpp"
#include "UI/UI.h"

ActionAddFuze::ActionAddFuze(ApplicationManager* pApp) :Action(pApp)
{
}

ActionAddFuze::~ActionAddFuze(void)
{
}

void ActionAddFuze::Execute()
{
	//Get pointer to the use interface
	UI* pUI = pManager->GetUI();
	//Print Action Message
	pUI->PrintMsg("Adding a new Fuze: Click anywhere to add");
	//Get Center point of the area where the Comp should be drawn
	pUI->GetPointClicked(Cx, Cy);
	//Clear Status Bar
	pUI->ClearStatusBar();
	GraphicsInfo* pGInfo = new GraphicsInfo(2); //Gfx info to be used to construct the Comp

	//Calculate the rectangle Corners
	int compWidth = pUI->getCompWidth();
	int compHeight = pUI->getCompHeight();

	pGInfo->PointsList[0].x = Cx - compWidth / 2;
	pGInfo->PointsList[0].y = Cy - compHeight / 2;
	pGInfo->PointsList[1].x = Cx + compWidth / 2;
	pGInfo->PointsList[1].y = Cy + compHeight / 2;

	Fuse* pR = new Fuse(pGInfo);
	pManager->AddComponent(pR);

}
void ActionAddFuze::Undo()
{}

void ActionAddFuze::Redo()
{}
