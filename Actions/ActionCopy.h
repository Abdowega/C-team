#pragma once
#include "Actions/Action.h"
#include"ApplicationManager.h"
class ActionCopy :
    public Action
{
private:
	int Cx; 
	int Cy;


public:
	ActionCopy(ApplicationManager* pApp);
	virtual ~ActionCopy(void);

	virtual void Execute();
	virtual void Undo();
	virtual void Redo();



};

