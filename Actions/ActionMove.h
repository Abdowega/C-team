#pragma once
#include "Actions/Action.h"
#include "UI/UI.h"
#include"ApplicationManager.h"
class ActionMove :
	public Action
{
	int cx, cy;	
	int x1, y1, x2, y2;


public:
	ActionMove(ApplicationManager* pApp);
	virtual ~ActionMove(void);

	
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();

};