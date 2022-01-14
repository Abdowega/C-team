#pragma once
#include "..\ApplicationManager.h"
#include "..\UI\UI.h"
#include "ActionMove.h"
class ActionMove :
	public Action
{
	int cx, cy;


public:
	ActionMove(ApplicationManager* pApp);
	virtual ~ActionMove(void);


	virtual void Execute();

	virtual void Undo();
	virtual void Redo();

};
