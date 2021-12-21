#pragma once
#include "../Actions/Action.h"
#include "../Components/Component.h"

class ActionEditLabel : public Action
{

public:

	ActionEditLabel(ApplicationManager* pApp);
	~ActionEditLabel(void);

	virtual void Execute();

	virtual void Undo();
	virtual void Redo();

};
