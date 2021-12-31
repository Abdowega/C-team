#include "Actions/Action.h"
#include "Components/Connection.h"
#include"ApplicationManager.h"

//Class responsible for adding a new resistor action
class ActionSelect : public Action
{
private:
	ApplicationManager* pApp;
	int x1, y1, x2, y2;
	int NumOfComp;

public:
	ActionSelect(ApplicationManager* pApp);
	virtual ~ActionSelect(void);
	Component* WhatComp(int Sx, int Sy);
	virtual void Execute();
	virtual void Undo();
	virtual void Redo();


};
