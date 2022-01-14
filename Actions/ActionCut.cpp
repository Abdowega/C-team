#include "ActionCut.h"
#include "..\ApplicationManager.h"
#include "..\UI\UI.h"



ActionCut::ActionCut(ApplicationManager* pApp) :Action(pApp)
{
}

ActionCut::~ActionCut(void)
{
}

void ActionCut::Execute()
{
	UI* pUI = pManager->GetUI();
	pUI->PrintMsg("Select the component to Cut");
	pUI->GetPointClicked(Cx, Cy);
	Component* cutcomp1 = pManager->GetComponentByCordinates(Cx, Cy);
	pUI->ClearStatusBar();
	if (cutcomp1 != 0)
	{
		pManager->copy(cutcomp1);
		pManager->DelComponent(cutcomp1);
		pManager->reArrange();
		pUI->PrintMsg("The component is cut");
		pUI->ClearDrawingArea();
		pManager->UpdateInterface();
	}
}

void ActionCut::Undo()
{
}

void ActionCut::Redo()
{
}
