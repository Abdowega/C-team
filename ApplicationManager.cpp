#include <iostream>
#include "ApplicationManager.h"
#include "Actions\ActionAddRes.h"
#include "Actions\ActionAddBuzzer.h"
#include "Actions\ActionAddBulb.h"
#include"Actions/ActionAddFuse.h"
#include"Actions/ActionAddGround.h"
#include"Actions/ActionAddBattery.h"
#include"Actions/ActionAddSwitch.h"
#include"Actions/ActionAddLabel.h"
#include"Actions/ActionAddConnection.h"
#include"Actions/ActionDelete.h"
#include"Actions/ActionSelect.h"
#include"Actions/ActionEdit.h"
#include"Actions/ActionSwitchSimulation.h"
#include"Actions/ExitAction.h"
#include "Actions/ActionMeasureVolt.h"
#include "Actions//ActionMeasureAmp.h"
#include "Actions/ActionMeasureVolt.h"

using namespace std;


ApplicationManager::ApplicationManager()
{
	CompCount = 0;
	ConnCount = 0;

	IsSimulation = 0;

	for (int i = 0; i < MaxCompCount; i++)
		CompList[i] = nullptr;
	for (int i = 0; i < MaxCompCount; i++)
		ConnList[i] = nullptr;
	pUI = new UI;
}



void ApplicationManager::AddComponent(Component* pComp)
{
	CompList[CompCount++] = pComp;
}
void ApplicationManager::DelSelected() {
	for (int i = 0; i < CompCount; i++) {
		if (CompList[i] != nullptr) {
			if (CompList[i]->isSelected()) {
				Connection** one = CompList[i]->getTermConnections(TERM1);
				Connection** two = CompList[i]->getTermConnections(TERM2);
				for (int j = 0; j < 20; j++) {
					DelConn(one[j]);
					DelConn(two[j]);
				}
				DelComponent(CompList[i]);
			}
		}
	}
	for (int i = 0; i < ConnCount; i++){
		if (ConnList[i] != nullptr)
			if (ConnList[i]->isSelected())
				DelConn(ConnList[i]);
	}

	reArrange();
	for (int i = 0; i < CompCount; i++)
			CompList[i]->reArrange();


}
void ApplicationManager::DelConn(Connection* pConn)
{
	for (int i = 0; i < ConnCount; i++) {

		if (ConnList[i] == pConn && pConn != nullptr) {
			Component* comp2 = ConnList[i]->getComp(1);
			Component* comp3 = ConnList[i]->getComp(2);
			comp2->deletecon(ConnList[i]);
			comp3->deletecon(ConnList[i]);
			ConnList[i]->deleteGraphics();
			delete ConnList[i];

			ConnList[i] = nullptr;

		}
	}

}
void ApplicationManager::DelComponent(Component* pComp)
{
	for (int i = 0; i < CompCount; i++) {
		if (CompList[i] == pComp) {
			CompList[i]->deleteGraphics();
			delete CompList[i];
			CompList[i] = nullptr;
			
			
		}
	}
	
}

void ApplicationManager::DelAll() {
	for (int i = 0; i < CompCount; i++) {
		DelComponent(CompList[i]);
	}

	for (int i = 0; i < ConnCount; i++) {
		DelConn(ConnList[i]);
	}
}
void ApplicationManager::AddConnection(Connection* pConn) {
	ConnList[ConnCount++] = pConn;
}
void ApplicationManager::UnselectAll(Component* pComp) {
	for (int i = 0; i < CompCount; i++){
		if(CompList[i]!=pComp&&CompList[i]!=nullptr)
			CompList[i]->unSelect();
}
	for (int i = 0; i < ConnCount; i++)
		if(ConnList[i]!=nullptr)
		ConnList[i]->unSelect();
}
void ApplicationManager::UnselectAll(Connection* pConn) {
	
	for (int i = 0; i < CompCount; i++)
		if(CompList[i]!=nullptr)
			CompList[i]->unSelect();
	for (int i = 0; i < ConnCount; i++) {
		if (ConnList[i] != nullptr&& ConnList[i] != pConn) 
			ConnList[i]->unSelect();
	
	}
}

void ApplicationManager::reArrange() {
	Component* tempCompList[MaxCompCount];	
	Connection* tempConnList[MaxConnCount];
	int counter = 0;
	for(int i=0;i<CompCount;i++)
		if (CompList[i] != nullptr) {
			tempCompList[counter] = CompList[i];
			counter++;
		}
	for (int i = 0; i < CompCount; i++) {
		CompList[i] = tempCompList[i];
		tempCompList[i] = nullptr;
		
	}
	CompCount = counter;
	counter = 0;
	for (int i = 0; i < ConnCount; i++)
		if (ConnList[i] != nullptr) {
			tempConnList[counter] = ConnList[i];
			counter++;
		}
	for (int i = 0; i < ConnCount; i++) {
		ConnList[i] = tempConnList[i];
		tempConnList[i] = nullptr;
	}
	ConnCount = counter;
	
}
ActionType ApplicationManager::GetUserAction()
{
	
	return pUI->GetUserAction();
}


void ApplicationManager::ExecuteAction(ActionType ActType)
{
	Action* pAct = nullptr;
	switch (ActType)
	{
	case ADD_RESISTOR:
		pAct = new ActionAddRes(this);
		break;
	case ADD_BULB:
		pAct = new ActionAddBulb(this);
		break;
	case ADD_BUZZER:
		pAct = new ActionAddBuzzer(this);
		break;
	case ADD_FUSE:
		pAct = new ActionAddFuse(this);
		break;
	case ADD_BATTERY:
		pAct = new ActionAddBattery(this);
		break;
	case ADD_SWITCH:
		pAct = new ActionAddSwitch(this);
		break;
	case ADD_GROUND:
		pAct = new ActionAddGround(this);
		break;
	case ADD_CONNECTION:
		pAct = new ActionAddConnection(this);
		break;
	case ADD_Label:
		pAct = new ActionAddLabel(this);
		break;
	case SELECT:
		pAct = new ActionSelect(this);
		break;
	case EDIT:
		pAct = new ActionEdit(this);
		break;

	case DEL:
		pAct = new ActionDelete(this);
		break;

	case SIM_MODE:
		pAct = new ActionSwitchSimulation(this);
		break;

	case EXIT:
		pAct = new ExitAction(this);
		break;

	case AMMETER:
		pAct = new ActionMeasureAmp(this);
		break;

	case VOLTMETER:
		pAct = new ActionMeasureVolt(this);
		break;

	}

	if (pAct)
	{
		pAct->Execute();

		delete pAct;
		pAct = nullptr;
	}
}


void ApplicationManager::UpdateInterface()
{
	pUI->ClearDrawingArea();
	for (int i = 0; i < CompCount; i++)
		if (CompList[i] != nullptr) {
			CompList[i]->Draw(pUI);
		}
	for (int i = 0; i < ConnCount; i++)
		if (ConnList[i] != nullptr) {
			ConnList[i]->Draw(pUI);
		}
	
}


UI* ApplicationManager::GetUI()
{
	return pUI;
}

bool ApplicationManager::ValidateCircuit(){
	bool validation = true;
	
	if (CompCount != ConnCount|| ConnCount == 1 || ConnCount == 0)
		return false;
	else {
		
		for (int i = 0; i < CompCount; i++) {
			if (!(CompList[i]->validate()))
				return false;
		}
		int counter = 0;
		
		for (int i = 0; i < CompCount; i++) {
			if (dynamic_cast<Ground*>(CompList[i]))
				counter++;
		}
		if (counter != 1)
			return false;
		

		for (int i = 0; i < ConnCount - 1; i++) {
			for (int j = i + 1; j < ConnCount; j++) {
				if (!(ConnList[i]->validate(ConnList[j])))
					return false;
			}
		}

		
		Connection* conn1;
		Component* comp1;
		counter = 0;
		int temp;
		for (int i = 0; i < CompCount; i++) {

			comp1 = CompList[i];

			conn1 = comp1->getTermConnections(TERM1)[0];
			temp = conn1->WhichComp(CompList[i]);
			switch (temp) {
			case 1:
				comp1 = conn1->getComp(2);
				break;
			case 2:
				comp1 = conn1->getComp(1);
			}
			counter = 1;
			
			while (comp1 != CompList[i]&& counter <= CompCount) {
			
				if (conn1 == comp1->getTermConnections(TERM1)[0])
					conn1 = comp1->getTermConnections(TERM2)[0];
				else {
					conn1 = comp1->getTermConnections(TERM1)[0];

				}
				temp = conn1->WhichComp(comp1);
				switch (temp) {
				case 1:
					comp1 = conn1->getComp(2);
					break;
				case 2:
					comp1 = conn1->getComp(1);
				}
				counter++;
				
			}

			if (counter != CompCount)
				return false;
		}
	
		return validation;
	}
}
Component* ApplicationManager::GetComponentByCordinates(int x, int y) {
	UI* pUI = GetUI();
	int  isExist = 0;
	int ydifference, xdifference;
	int compheight = pUI->getCompHeight();
	int compwidth = pUI->getCompWidth();
	for (int i = 0; i < CompCount; i++) {
		if (CompList[i] != nullptr) {
			ydifference = abs(y - CompList[i]->getCompCenterY(pUI));
			xdifference = abs(x - CompList[i]->getCompCenterX(pUI));
			if ((ydifference <= compheight / 2) && (xdifference <= compwidth / 2)) {
				isExist = 1;
				return CompList[i];

				break;
			}

		}
	}
	if (isExist == 0)
		return nullptr;
}

Connection* ApplicationManager::GetConnByCordinates(int x, int y) {
	
	UI* pUI = GetUI();
	int  isExist = 0;
	int x_1;
	int x_2;
	int y_1;
	int y_2;
	double slope;
	int right, left;
	for (int i = 0; i < ConnCount; i++) {
		if (ConnList[i] != nullptr) {
			x_1 = ConnList[i]->getgraphics()->PointsList[0].x;
			x_2 = ConnList[i]->getgraphics()->PointsList[1].x;
			y_1 = ConnList[i]->getgraphics()->PointsList[0].y;
			y_2 = ConnList[i]->getgraphics()->PointsList[1].y;
			slope = ConnList[i]->lineslope();
			
			for(int j=-5;j<=5;j++) {
				
				if ((x + j >= x_2 && x + j <= x_1) || (x + j >= x_1 && x + j <= x_2)) {
					for (int k = -4; k <= 4; k++){
						
						if(x_1!=x_2){
						right = slope*(x - (x_1+k));
						left = y - (y_1 + k);}
						else {
							right = x - (x_1 + k);
							left = 0;
						}
						if (left == right) {
							return ConnList[i];
							isExist = 1;
							break;
						}
					}
				}
			}
			
			
		}
	}
	if (isExist == 0)
		return nullptr;
}

int ApplicationManager::getCompOrder(Component* comp) {
	for (int i = 0; i < CompCount; i++) {
		if (comp == CompList[i])
			return i;
	}
}

void ApplicationManager::copy(Component* copiedComp1)
{
	Battery* copiedBattery = dynamic_cast <Battery*> (copiedComp1);
	Resistor* copiedResistor = dynamic_cast <Resistor*> (copiedComp1);
	Bulb* copiedBulb = dynamic_cast <Bulb*> (copiedComp1);
	Buzzer* copiedBuzzer = dynamic_cast <Buzzer*> (copiedComp1);
	Fuse* copiedFuse = dynamic_cast <Fuse*> (copiedComp1);
	Ground* copiedGround = dynamic_cast <Ground*> (copiedComp1);
	Switch* copiedSwitch = dynamic_cast <Switch*> (copiedComp1);

	for (int i = 0; i < CompCount; i++)
	{
		if (CompList[i] == copiedComp1)
		{
			if (copiedBattery != nullptr)
			{
				Battery* NewcopiedComp1 = new Battery(*copiedBattery);
				copycomp1 = NewcopiedComp1;
			}
			else if (copiedResistor != nullptr)
			{
				Resistor* NewcopiedComp1 = new Resistor(*copiedResistor);
				copycomp1 = NewcopiedComp1;
			}
			else if (copiedBulb != nullptr)
			{
				Bulb* NewcopiedComp1 = new Bulb(*copiedBulb);
				copycomp1 = NewcopiedComp1;
			}
			else if (copiedBuzzer != nullptr)
			{
				Buzzer* NewcopiedComp1 = new Buzzer(*copiedBuzzer);
				copycomp1 = NewcopiedComp1;
			}
			else if (copiedFuse != nullptr)
			{
				Fuse* NewcopiedComp1 = new Fuse(*copiedFuse);
				copycomp1 = NewcopiedComp1;
			}
			else if (copiedGround != nullptr)
			{
				Ground* NewcopiedComp1 = new Ground(*copiedGround);
				copycomp1 = NewcopiedComp1;
			}
			else if (copiedSwitch != nullptr)
			{
				Switch* NewcopiedComp1 = new Switch(*copiedSwitch);
				copycomp1 = NewcopiedComp1;
			}
		}
	}
}



void ApplicationManager::ToSimulation(window *pWind) {
	cout << "Hello";
	if (!ValidateCircuit()) {
		delete pWind;
		pWind = new window;

	}
	else {

		this->IsSimulation = true;
				delete pWind;
		pWind = new window;
		
		
	}
}


ApplicationManager::~ApplicationManager()
{
	delete pW;
	delete pUI;
}