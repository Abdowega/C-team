
#include "ActionMove.h"
#include "ApplicationManager.h"
#include "UI/UI.cpp"
#include "UI/UI.h" 
#include "ActionCopy.h"
ActionMove::ActionMove(ApplicationManager* pApp) : Action(pApp)
{
}

ActionMove::~ActionMove(void)
{

}

void ActionMove::Execute()
{
	UI* pUI = pManager->GetUI();
	pUI->ClearDrawingArea();
	pManager->UpdateInterface();
	pUI->PrintMsg("Select the component you want to drag");
	pUI->GetPointClicked(cx, cy);
	Component* component = pManager->GetComponentByCordinates(cx, cy);
	if (component != 0)
	{
		pUI->move(cx, cy);
	}
}

void ActionMove::Undo()
{
}

void ActionMove::Redo()
{
}
