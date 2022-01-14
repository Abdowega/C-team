#pragma once
#include "Action.h"
class ActionCut :
    public Action
{

		int C1, C2;
		int Cx;
		int Cy;
	public:
		ActionCut(ApplicationManager* pApp);
		virtual ~ActionCut(void);


		virtual void Execute();

		virtual void Undo();
		virtual void Redo();


};

