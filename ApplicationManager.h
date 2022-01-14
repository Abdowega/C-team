 #ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H
#include<fstream>
#include<iosfwd >
#include "Components\Component.h"
#include "Actions\Action.h"
#include "Defs.h"
#include "UI\UI.h"


class ApplicationManager
{

	enum { 
		MaxCompCount = 200,
		MaxConnCount = 1000	};	
	
private:

	
	int CompCount;		//Actual number of Components
	int ConnCount;		//Actual number of Connections
	bool IsSimulation; // returns true when in simulation mode
	bool IsSeries;
	int drawningpenwidth;
	Component* copycomp1;
	Component* CompList[MaxCompCount];	//List of all Components 
	Connection* ConnList[MaxConnCount];	//List of all Connections 
	window* pW;
	UI* pUI; 


public:	
	ApplicationManager(); 


	ActionType GetUserAction();
	
	
	void ExecuteAction(ActionType);
	
	void UpdateInterface();	

	
	//Gets a pointer to UI Object
	UI* GetUI();
	
	
	void AddComponent(Component* pComp); //Add a new component to list of components
	void AddConnection(Connection* pConn);//Adds a new connection to list of connection
	void UnselectAll(Component* pComp);
	void UnselectAll(Connection* pConn);
	void DelSelected();
	void DelComponent(Component* pComp);//delete the pointer pComp from the CompList
	void DelConn(Connection* pConn);  //delete the pointer pconn from the connList
	void DelAll();   //Delete all of the components and connections
	void reArrange();
	Component* GetComponentByCordinates(int x, int y); 
	Connection* GetConnByCordinates(int x, int y);
	
	int ApplicationManager::getCompOrder(Component* comp);
	void copy(Component* Copiedcomp1);
	
	bool ValidateCircuit();
	void ToSimulation(window *pWind);
	
	~ApplicationManager();
};

#endif