#pragma once
#include "Action.h"
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