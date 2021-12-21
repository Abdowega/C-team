#include "ActionEditLabel.h"
#include "../Components/Component.h"
#include "../ApplicationManager.h"

ActionEditLabel::ActionEditLabel(ApplicationManager* pApp):Action(pApp)
{
}

ActionEditLabel::~ActionEditLabel(void)
{
}

void ActionEditLabel::Execute()
{


	int Cx, Cy;

	//Get a Pointer to the user Interfaces
	UI* pUI = pManager->GetUI();
	pUI->PrintMsg("Choose Item to lablel/edit its label..");

	//Get Center point of the Item
	pUI->GetPointClicked(Cx, Cy);

	if (pManager->GetComponentByCordinates(Cx, Cy) != NULL)
	{
		Component* item = pManager->GetComponentByCordinates(Cx, Cy);		// get pointer to component 
		pUI->ClearStatusBar();			// clear status bar from the previous printed msg.
		item->SetLabel(pUI->GetSrting());	// get the string from user to be the label
		pUI->ClearStatusBar();			// clear the status bar again after getting the user input.
	}
	else
		pUI->PrintMsg("You didnt choose any component/connection.");



}

void ActionEditLabel::Undo() {}
void ActionEditLabel::Redo() {}