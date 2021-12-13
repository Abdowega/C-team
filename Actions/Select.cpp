#include "Select.h"
#include "../ApplicationManager.h"


ActionSelect::ActionSelect(ApplicationManager* pApp) :Action(pApp)
{
}

ActionSelect::~ActionSelect(void)
{
}

void ActionSelect::Execute()
{
	//Get a Pointer to the user Interfaces
	UI* pUI = pManager->GetUI();

	//Print Action Message
	pUI->PrintMsg("Select: Click anywhere to select");

	//Get Center point of the area where the Comp should be drawn
	/*pUI->GetPointClicked(Cx, Cy);*/

	int x;
	int y;
	pUI->getPWind()->GetMouseCoord(x ,y);

	Component* ListOfComponents[200];

	pManager->getCompList(ListOfComponents);


	for (int i = 0; i < 200; i++) {
		
		GraphicsInfo* yg = nullptr;
		ListOfComponents[i]->getGraphics(yg);
		if (x > yg->PointsList[0].x && x < yg->PointsList[1].x && y > yg->PointsList[0].y && y < yg->PointsList[1].y) {
			pUI->PrintMsg("You clicked a component!");
		}
	}

	//Clear Status Bar
	//pUI->ClearStatusBar();

	
	
}

void ActionSelect::Undo()
{}

void ActionSelect::Redo()
{}

