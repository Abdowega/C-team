#pragma once
#include "Action.h"
class ActionPaste :
    public Action
{

private:
	int Cx;
	int Cy;
public:
	ActionPaste(ApplicationManager* pApp);
	virtual ~ActionPaste(void);


	virtual void Execute();

	virtual void Undo();
	virtual void Redo();
};
