#pragma once


#include "Action.h"


//Class responsible for adding a new resistor action
class ActionSelect : public Action
{
public:
	ActionSelect(ApplicationManager* pApp);
	virtual ~ActionSelect(void);

	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();


};
