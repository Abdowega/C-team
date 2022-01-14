#ifndef __UI_H_
#define __UI_H_
#include <string>
#include "..\Defs.h"
#include "..\CMUgraphicsLib\CMUgraphics.h"
using namespace std;

struct Point
{
	int x,y;
};

struct GraphicsInfo
{
	int PointsCount;
	Point* PointsList;
	GraphicsInfo(int PtsCnt)
	{
		PointsCount = PtsCnt;
		PointsList  = new Point[PointsCount];	
	}

};

class UI
{
	//Icons of the design menu 
	enum DsgnMenuItem 
	{
		ITM_RES,		
		ITM_BULB,
		ITM_BUZZER,
		ITM_FUSE,
		ITM_SWITCH,
		ITM_BATTERY,
		ITM_GROUND,
		ITM_CONNECTION,
		ITM_EDIT,
		ITM_LABEL,
		ITM_DELETE,
		ITM_SIMU,
		ITM_EXIT,
		ITM_DSN_CNT
		
	};


	//Simulation Menu Items;
	enum SimMenuItem 
	{
		ITM_CIRC_SIM,	
		ITM_DESIGN, 
		ITM_EXIT2,


		ITM_VOLTMETER,
		ITM_AMMETER,


		ITM_SIM_CNT		
	
	};

	
	MODE AppMode;		
	ImageType img;
	static const int	width = 1200, height = 650,	
		wx = 15, wy = 15,			
		StatusBarHeight = 50,	
		ToolBarHeight = 80,		
		ToolItemWidth = 80,		

		
		COMP_WIDTH = 55,		
		COMP_HEIGHT = 55,		
		PEN_THICKNESS = 5;
	color SelectColor;
	color DrawColor;			
	color ConnColor;		
	color BkGrndColor;
	color MsgColor;			
	

	UI* pU;
	window *pWind;
	int xtemp, ytemp;
public:
	UI();
	static int getToolBarHeight() ;
	static int Height();
	static int getWidth() ;
	static int getStatusBarHeight();
	static int getCompHeight();
	static int getCompWidth();	
	
	
	
	//(((( Input Functions )))) 
	void GetPointClicked(int &, int &);	
	string GetSrting(string msg = "Enter any Value", string value = "1");		
	void move(int&, int&);

	ActionType GetUserAction() ; 
	int getXtemp();
	int getYtemp();
	
	// (((( Output Functions ))))  
	void ChangeTitle(string Title) const;
	void CreateDesignToolBar();	
	void CreateSimulationToolBar();
	void CreateStatusBar() const;	
	void ClearStatusBar() const;		
	void ClearToolBarArea()const;
	void ClearDrawingArea() const;	
	void SwitchImageType();
	// Draws a resistor
	void DrawResistor(const GraphicsInfo &r_GfxInfo, bool selected = false) const;
	void DrawBattery(const GraphicsInfo& r_GfxInfo, bool selected = false) const;
	void DrawGround(const GraphicsInfo& r_GfxInfo, bool selected = false) const;
	void DrawOpenSwitch(const GraphicsInfo& r_GfxInfo, bool selected = false) const;
	void DrawClosedSwitch(const GraphicsInfo& r_GfxInfo, bool selected = false) const;
	void DrawFuse(const GraphicsInfo& r_GfxInfo, bool selected = false) const;
	void DrawBulb(const GraphicsInfo& r_GfxInfo, bool selected = false) const;
	void DrawBuzzer(const GraphicsInfo& r_GfxInfo, bool selected = false) const;
	void DrawConnection(const GraphicsInfo &r_GfxInfo, bool selected = false) const;
	
	void ToSimulation();

	void PrintMsg(string msg) const;
	void labelMsg(string msg,int x=25,int y= height-StatusBarHeight + 10);
	~UI();
};

#endif