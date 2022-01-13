#pragma once
#include"Actions/Action.h"
#include"ApplicationManager.h"
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

