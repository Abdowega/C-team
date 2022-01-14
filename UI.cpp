#include "UI.h"
#include <iostream>

UI::UI()
{
	AppMode = DESIGN;	
	img = Schem;
	DrawColor = BLACK;
	SelectColor = BLUE;
	ConnColor = RED;
	MsgColor = BLACK;
	BkGrndColor = WHITE;

	pWind = new window(width, height, wx, wy);	


	ChangeTitle("Electric Circuit");

	CreateDesignToolBar();	
	CreateStatusBar();		
	xtemp = 0;
	ytemp = 0;
}

int UI::getToolBarHeight() {
	return ToolBarHeight;
}
int UI::Height()  {
	return height;
}
int UI::getWidth()  {
	return width;
}
int UI::getStatusBarHeight()  {
	return StatusBarHeight;
}
int UI::getCompWidth() 
{
	return COMP_WIDTH;
}

int UI::getCompHeight() 
{
	return COMP_HEIGHT;
}

//======================================================================================//
//								Input Functions 										//
//======================================================================================//

void UI::GetPointClicked(int &x, int &y)
{
	pWind->WaitMouseClick(x, y);	
}

string UI::GetSrting(string msg,string value)
{
	
	UI::PrintMsg(msg);
	string userInput;
	char Key;
	userInput = value;
	while(1)
	{
		pWind->WaitKeyPress(Key);

		switch(Key)
		{
		case 27: 
			PrintMsg("");
			return ""; 
		
		case 13:		
			return userInput;
		
		case 8:		
			if(userInput.size() > 0)
				userInput.resize(userInput.size() -1 );
			break;
		
		default:
			userInput+= Key;
		};
		
		PrintMsg(userInput);
	}

}

void UI::move(int&, int&)
{
}

ActionType UI::GetUserAction() 
{	
	int x,y;
	pWind->WaitMouseClick(x, y);	

	if(AppMode == DESIGN )	
	{
		
		if ( y >= 0 && y < ToolBarHeight)
		{	
			
			
			int ClickedItemOrder = (x / ToolItemWidth);

			switch (ClickedItemOrder)
			{
			case ITM_RES:	
				return ADD_RESISTOR;
			case ITM_BULB:		
				return ADD_BULB;
			case ITM_BUZZER:	
				return ADD_BUZZER;
			case ITM_FUSE:
				return ADD_FUSE;
			case ITM_SWITCH:
				return ADD_SWITCH;
			case ITM_BATTERY:
				return ADD_BATTERY;
			case ITM_GROUND:
				return ADD_GROUND;
			case ITM_CONNECTION:
				return ADD_CONNECTION;
			case ITM_LABEL:
				return ADD_Label;
			case ITM_EDIT:
				return EDIT;
			case ITM_DELETE:
				return DEL;
			case ITM_SIMU:
				return SIM_MODE;	
			case ITM_EXIT:	
				return EXIT;	
			default:
				return DSN_TOOL;	
			}
		}
	
			if (y >= ToolBarHeight && y < height - StatusBarHeight)
			{
				xtemp = x;
				ytemp = y;

				return SELECT;	
			}
		
		
		
		return STATUS_BAR;
	}
	else {

		if (y >= 0 && y < ToolBarHeight)
		{
			int ClickedItemOrder = (x / ToolItemWidth);
			switch (ClickedItemOrder)
			{
			case ITM_EXIT2: return EXIT;
			case ITM_DESIGN: return DESIGNN;
			case ITM_CIRC_SIM: return SIMU;
			case ITM_AMMETER: return AMMETER;
			case ITM_VOLTMETER: return VOLTMETER;
			}
		}
	}
}
int UI::getXtemp() {
	return xtemp;
}
int UI::getYtemp() {
	return ytemp;
}

//======================================================================================//
//								Output Functions										//
//======================================================================================//


void UI::ChangeTitle(string Title) const
{
	pWind->ChangeTitle(Title);
}

void UI::CreateStatusBar() const
{
	pWind->SetPen(RED,3);
	pWind->DrawLine(0, height-StatusBarHeight, width, height-StatusBarHeight);
}

void UI::ToSimulation() {


	AppMode = SIMULATION;
	delete pWind;
	pWind = new window(width, height, wx, wy);
	CreateSimulationToolBar();
	CreateStatusBar();


}



void UI::PrintMsg(string msg) const
{
	ClearStatusBar();
	int MsgX = 25;
	int MsgY = StatusBarHeight - 10;

	
    pWind->SetFont(20, BOLD | ITALICIZED, BY_NAME, "Arial"); 
	pWind->SetPen(MsgColor); 
	pWind->DrawString(MsgX, height - MsgY, msg);
}
void UI::labelMsg(string msg,int x,int y)
{
	ClearStatusBar();
	
	int MsgX = x;
	int MsgY = y;

	
	pWind->SetFont(20, BOLD | ITALICIZED, BY_NAME, "Arial");
	pWind->SetPen(MsgColor);
	pWind->DrawString(MsgX,MsgY, msg);
}

void UI::ClearStatusBar()const
{
	
	int MsgX = 25;
	int MsgY = StatusBarHeight - 10;

	
	pWind->SetPen(BkGrndColor);
	pWind->SetBrush(BkGrndColor);
	pWind->DrawRectangle(MsgX, height - MsgY, width, height);
}


void UI::ClearDrawingArea() const
{
	pWind->SetPen(RED, 1);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, ToolBarHeight, width, height - StatusBarHeight);
	
}
void UI::ClearToolBarArea() const
{
	pWind->SetPen(WHITE, 1);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, 0, width, ToolBarHeight);

}
void UI::SwitchImageType() {
	if (img == Real)
		img = Schem;
	else
		img = Real;
}


void UI::CreateDesignToolBar() 
{
	AppMode = DESIGN;	

	string MenuItemImages[ITM_DSN_CNT];
	MenuItemImages[ITM_RES] = "images\\Menu\\Menu_Resistor.jpg";
	MenuItemImages[ITM_BULB] = "images\\Menu\\Menu_Bulb.jpg";
	MenuItemImages[ITM_BUZZER] = "images\\Menu\\Menu_Buzzer.jpg";
	MenuItemImages[ITM_BATTERY] = "images\\Menu\\Menu_Battery.jpg";
	MenuItemImages[ITM_FUSE] = "images\\Menu\\Menu_Fuze.jpg";
	MenuItemImages[ITM_GROUND] = "images\\Menu\\Menu_Ground.jpg";
	MenuItemImages[ITM_SWITCH] = "images\\Menu\\Menu_Switch.jpg";
	MenuItemImages[ITM_EDIT] = "images\\Menu\\Menu_Edit.jpg";
	MenuItemImages[ITM_LABEL] = "images\\Menu\\Menu_Label.jpg";
	MenuItemImages[ITM_DELETE] = "images\\Menu\\Menu_Delete.jpg";
	MenuItemImages[ITM_EXIT] = "images\\Menu\\Menu_Exit.jpg";
	MenuItemImages[ITM_CONNECTION] = "images\\Menu\\Menu_Wire.jpg";
	MenuItemImages[ITM_SIMU] = "images\\Menu\\Menu_Play.jpg";


	for(int i=0; i<ITM_DSN_CNT; i++)
		pWind->DrawImage(MenuItemImages[i],i*ToolItemWidth,0,ToolItemWidth, ToolBarHeight);

	pWind->SetPen(BLUE,3);
	pWind->DrawLine(0, ToolBarHeight, width, ToolBarHeight);	
}



void UI::CreateSimulationToolBar()
{
		AppMode = SIMULATION;	

		string SimulationMenuImages[ITM_SIM_CNT];
		SimulationMenuImages[ITM_CIRC_SIM] = "images\\Simulation Menu\\SMenu_Simulate.jpg";
		SimulationMenuImages[ITM_DESIGN] = "images\\Simulation Menu\\SMenu_Design.jpg";
		SimulationMenuImages[ITM_EXIT2] = "images\\Simulation Menu\\SMenu_Exit.jpg";

		for (int i = 0; i < ITM_SIM_CNT; i++)
		{
			pWind->DrawImage(SimulationMenuImages[i], i * ToolItemWidth, 0, ToolItemWidth, ToolBarHeight);
		}
		pWind->SetPen(RED, 3);
		pWind->DrawLine(0, ToolBarHeight, width, ToolBarHeight);
	
}

//======================================================================================//
//								Components Drawing Functions							//
//======================================================================================//

void UI::DrawResistor(const GraphicsInfo &r_GfxInfo, bool selected) const
{
	
	string ResistorImage;
	if (img == Schem) {
		if (selected)
			ResistorImage = "Images\\Comp\\Resistor_HI.jpg";	
		else
			ResistorImage = "Images\\Comp\\Resistor.jpg";	
	}
	else {
		if (selected)
			ResistorImage = "Images\\Comp\\Real_Resistor_HI.jpg";	
		else
			ResistorImage = "Images\\Comp\\Real_Resistor.jpg";	
	}
	
		pWind->DrawImage(ResistorImage, r_GfxInfo.PointsList[0].x, r_GfxInfo.PointsList[0].y, COMP_WIDTH, COMP_HEIGHT);
	
}


void UI::DrawBattery(const GraphicsInfo& r_GfxInfo, bool selected) const
{

	string BatteryImage;
	if (img == Schem) {
		if (selected)
			BatteryImage = "Images\\Comp\\Battery_HI.jpg";
		else
			BatteryImage = "Images\\Comp\\Battery.jpg";	
	}
	else {
		if (selected)
			BatteryImage = "Images\\Comp\\Real_Battery_HI.jpg";	
		else
			BatteryImage = "Images\\Comp\\Real_Battery.jpg";	
	}

	pWind->DrawImage(BatteryImage, r_GfxInfo.PointsList[0].x, r_GfxInfo.PointsList[0].y, COMP_WIDTH, COMP_HEIGHT);

}

void UI::DrawFuse(const GraphicsInfo& r_GfxInfo, bool selected) const
{

	string FuseImage;
	if (img == Schem) {
		if (selected)
			FuseImage = "Images\\Comp\\Fuze_HI.jpg";
		else
			FuseImage = "Images\\Comp\\Fuze.jpg";
	}
	else {
		if (selected)
			FuseImage = "Images\\Comp\\Real_Fuze_HI.jpg";
		else
			FuseImage = "Images\\Comp\\Real_Fuze.jpg";
	}


	pWind->DrawImage(FuseImage, r_GfxInfo.PointsList[0].x, r_GfxInfo.PointsList[0].y, COMP_WIDTH, COMP_HEIGHT);

}


void UI::DrawGround(const GraphicsInfo& r_GfxInfo, bool selected) const
{

	string GroundImage;
	if (selected)
		GroundImage = "Images\\Comp\\Ground_HI.jpg";	
	else
		GroundImage = "Images\\Comp\\Ground.jpg";	

	

	pWind->DrawImage(GroundImage, r_GfxInfo.PointsList[0].x, r_GfxInfo.PointsList[0].y, COMP_WIDTH, COMP_HEIGHT);

}
void UI::DrawOpenSwitch(const GraphicsInfo& r_GfxInfo, bool selected) const
{

	string SwitchImage;
	if (img == Schem) {
		if (selected)
			SwitchImage = "Images\\Comp\\OpenSwitch_HI.jpg";	
		else
			SwitchImage = "Images\\Comp\\OpenSwitch.jpg";
	}
	else {
		if (selected)
			SwitchImage = "Images\\Comp\\Real_OpenSwitch_HI.jpg";
		else
			SwitchImage = "Images\\Comp\\Real_OpenSwitch.jpg";	
	}


	pWind->DrawImage(SwitchImage, r_GfxInfo.PointsList[0].x, r_GfxInfo.PointsList[0].y, COMP_WIDTH, COMP_HEIGHT);

}
void UI::DrawClosedSwitch(const GraphicsInfo& r_GfxInfo, bool selected) const
{

	string SwitchImage;
	if (img == Schem) {
		if (selected)
			SwitchImage = "Images\\Comp\\OpenSwitch.jpg";
		else
			SwitchImage = "Images\\Comp\\ClosedSwitch.jpg";
	}
	else {
		if (selected)
			SwitchImage = "Images\\Comp\\Real_ClosedSwitch_HI.jpg";
		else
			SwitchImage = "Images\\Comp\\Real_ClosedSwitch.jpg";
	}
	

	pWind->DrawImage(SwitchImage, r_GfxInfo.PointsList[0].x, r_GfxInfo.PointsList[0].y, COMP_WIDTH, COMP_HEIGHT);

}

void UI::DrawBulb(const GraphicsInfo& r_GfxInfo, bool selected) const
{
	string BulbImage;
	if (img == Schem) {
		if (selected)
			BulbImage = "Images\\Comp\\Bulb_HI.jpg";	
		else
			BulbImage = "Images\\Comp\\Bulb.jpg";
	}
	else {
		if (selected)
			BulbImage = "Images\\Comp\\Real_Bulb_HI.jpg";
		else
			BulbImage = "Images\\Comp\\Real_Bulb.jpg";	
	}

	pWind->DrawImage(BulbImage, r_GfxInfo.PointsList[0].x, r_GfxInfo.PointsList[0].y, COMP_WIDTH, COMP_HEIGHT);
}
void UI::DrawBuzzer(const GraphicsInfo& r_GfxInfo, bool selected) const
{
	string BuzzerImage;
	if (img == Schem) {
		
		if (selected)
			BuzzerImage = "Images\\Comp\\Buzzer_HI.jpg";
		else
			BuzzerImage = "Images\\Comp\\Buzzer.jpg";	

		
		
	}
	else {
		if (selected)
			BuzzerImage = "Images\\Comp\\Real_Buzzer_HI.jpg";	
		else
			BuzzerImage = "Images\\Comp\\Real_Buzzer.jpg";	

	}
	pWind->DrawImage(BuzzerImage, r_GfxInfo.PointsList[0].x, r_GfxInfo.PointsList[0].y, COMP_WIDTH, COMP_HEIGHT);
}



void UI::DrawConnection(const GraphicsInfo &r_GfxInfo, bool selected) const
{
	
	string WireImage;
	if (selected)
		pWind->SetPen(RED, PEN_THICKNESS);
	else
		pWind->SetPen(BLACK, PEN_THICKNESS);

	
	pWind->DrawLine(r_GfxInfo.PointsList[0].x, r_GfxInfo.PointsList[0].y, r_GfxInfo.PointsList[1].x, r_GfxInfo.PointsList[1].y);
}


UI::~UI()
{
	delete pWind;

}