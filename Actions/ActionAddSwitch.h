#pragma once
#include "Action.h"
#include "..\Components\Switch.h"

class ActionAddSwitch :public Action
{
private:
	//Parameters for rectangular area to be occupied by the comp
	int Cx, Cy;	//Center point of the comp
	int x1, y1, x2, y2;	//Two corners of the rectangluar area
public:
	ActionAddSwitch(ApplicationManager* pApp);
	virtual ~ActionAddSwitch(void);

	//Execute action 
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();


};


