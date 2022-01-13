#include "ActionCopy.h"
#include "ApplicationManager.h"
#include "UI/UI.cpp"
#include "UI/UI.h" 

ActionCopy::ActionCopy(ApplicationManager* pApp) : Action(pApp)
{
}

ActionCopy::~ActionCopy(void)
{

}

void ActionCopy::Execute()
{


		UI * pUI = pManager->GetUI();
	pUI->PrintMsg("Select to copy component");
	pUI->GetPointClicked(Cx, Cy);
	pUI->ClearStatusBar();
	Component* copycomp1 = pManager->GetComponentByCordinates(Cx, Cy);
	if (copycomp1 != 0)
	{
	
	
		pManager->copy(copycomp1); 
		pUI->PrintMsg("Copied Component");
		
	}
}

void ActionCopy::Undo()
{
}

void ActionCopy::Redo()
{
}
