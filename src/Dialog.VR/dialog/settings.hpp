/*
 * Dialog by MrFrost
 * Macros by Heyoxe
 *
 * Hereby I forbid the publication under a different name, as original or modified, without my explicit permission.
 * This script was developed explicitly for all "Mammut-Roleplay.de Servers".
 * It is not allowed to use, publish or sell it on other platforms without my explicit permission.
 * It is not allowed to remove this header.
 */

/* --------------------------------------------------------------------------
 * settings.hpp - Settings menu
 *
 * Part of    : Altis Life UI Pack (MrFrost, 2021) - archived, unmaintained.
 * Root class : SettingsMenu
 * IDD        : MrFrost_IDD_Settings = 2900
 * Opened by  : createDialog "SettingsMenu";
 * Requires   : dialog/MrFrost_defines.hpp (MrFrost_POSITION and the
 *              MrFrost_Rsc* base classes) and dialog/common.hpp.
 *
 * Positions are authored against a 1920x1080 reference canvas.
 * MrFrost_POSITION(X,Y,W,H) rewrites those pixel values into
 * safezone-relative coordinates at preprocess time, so the numbers
 * below can be read directly as pixels on a 1080p screen.
 *
 * Note       : Shares resolved IDD 2900 with the stock admin_menu.hpp.
 *
 * Full IDD/IDC table : docs/dialog-reference.md
 * Before production  : docs/known-issues.md
 * ------------------------------------------------------------------------- */
/* IDD/IDCs Macros */
#define MrFrost_IDD_Settings 2900

//Main Background
#define MrFrost_IDC_MainBackground -1
#define MrFrost_IDC_Bar_Bottom -1
#define MrFrost_IDC_Bar_Top -1
#define MrFrost_IDC_Logo_Mammut -1

//Parts Background
#define MrFrost_IDC_Background_Settings_ViewDistance -1
#define MrFrost_IDC_Background_Settings_Buttons -1
#define MrFrost_IDC_Background_Settings_Hotkeys_Text -1
#define MrFrost_IDC_Bar_Settings_ViewDistance -1
#define MrFrost_IDC_Bar_Settings_Buttons -1
#define MrFrost_IDC_Bar_Settings_Hotkeys_Text -1

//Titles
#define MrFrost_IDC_Title_Settings_Title -1

//Background Slider Elements
#define MrFrost_IDC_Background_Settings_ViewDistance_Foot -1
#define MrFrost_IDC_Background_Settings_ViewDistance_Car -1
#define MrFrost_IDC_Background_Settings_ViewDistance_Air -1

//Background Edit Elements
#define MrFrost_IDC_Background_Settings_ViewDistance_Foot_Edit -1
#define MrFrost_IDC_Background_Settings_ViewDistance_Car_Edit -1
#define MrFrost_IDC_Background_Settings_ViewDistance_Air_Edit -1

//Background Buttons Elements
#define MrFrost_IDC_Background_Settings_Buttons_SideChat -1
#define MrFrost_IDC_Background_Settings_Buttons_NearObjects -1
#define MrFrost_IDC_Background_Settings_Buttons_Broadcast -1

#define MrFrost_IDC_Background_Settings_Buttons_Button_1 -1
#define MrFrost_IDC_Background_Settings_Buttons_Button_2 -1
#define MrFrost_IDC_Background_Settings_Buttons_Button_3 -1
#define MrFrost_IDC_Background_Settings_Buttons_Button_4 -1
#define MrFrost_IDC_Background_Settings_Buttons_Button_5 -1
#define MrFrost_IDC_Background_Settings_Buttons_Button_6 -1
#define MrFrost_IDC_Background_Settings_Buttons_Button_7 -1
#define MrFrost_IDC_Background_Settings_Buttons_Button_8 -1

//Background Main Buttons
#define MrFrost_IDC_Picture_Button_Close -1

//Text Elements
#define MrFrost_IDC_Text_Settings_Buttons_SideChat -1
#define MrFrost_IDC_Text_Settings_Buttons_NearObjects -1
#define MrFrost_IDC_Text_Settings_Buttons_Broadcast -1

#define MrFrost_IDC_Text_Settings_ViewDistance_Foot -1
#define MrFrost_IDC_Text_Settings_ViewDistance_Car -1
#define MrFrost_IDC_Text_Settings_ViewDistance_Air -1

#define MrFrost_IDC_Text_Settings_Hotkeys_Text -1

//Slider Elements
#define MrFrost_IDC_Slider_Settings_ViewDistance_Foot 2901
#define MrFrost_IDC_Slider_Settings_ViewDistance_Car 2911
#define MrFrost_IDC_Slider_Settings_ViewDistance_Air 2921

//Edit Elements
#define MrFrost_IDC_Edit_Settings_ViewDistance_Foot 2902
#define MrFrost_IDC_Edit_Settings_ViewDistance_Car 2912
#define MrFrost_IDC_Edit_Settings_ViewDistance_Air 2922

//Buttons Elements
#define MrFrost_IDC_Button_Settings_Buttons_SideChat 2971
#define MrFrost_IDC_Button_Settings_Buttons_NearObjects 2972
#define MrFrost_IDC_Button_Settings_Buttons_Broadcast 2973

#define MrFrost_IDC_Button_Settings_Buttons_Button_1 -1
#define MrFrost_IDC_Button_Settings_Buttons_Button_2 -1
#define MrFrost_IDC_Button_Settings_Buttons_Button_3 -1
#define MrFrost_IDC_Button_Settings_Buttons_Button_4 -1
#define MrFrost_IDC_Button_Settings_Buttons_Button_5 -1
#define MrFrost_IDC_Button_Settings_Buttons_Button_6 -1
#define MrFrost_IDC_Button_Settings_Buttons_Button_7 -1
#define MrFrost_IDC_Button_Settings_Buttons_Button_8 -1

//Main Buttons
#define MrFrost_IDC_Button_Close -1


/* Positions Macros
#define MrFrost_POSITION(X,Y,W,H) \
	x = #((((X * (getResolution select 0)) / 1920) * safeZoneW) / (getResolution select 0) + safeZoneX); \
	y = #((((Y * (getResolution select 1)) / 1080) * safeZoneH) / (getResolution select 1) + safeZoneY); \
	w = #((((W * (getResolution select 0)) / 1920) * safeZoneW) / (getResolution select 0)); \
	h = #((((H * (getResolution select 1)) / 1080) * safeZoneH) / (getResolution select 1));

#define MrFrost_POSITION_CT(X,Y,W,H) \
	x = #((((X * (getResolution select 0)) / 1920) * safeZoneW) / (getResolution select 0)); \
	y = #((((Y * (getResolution select 1)) / 1080) * safeZoneH) / (getResolution select 1)); \
	w = #((((W * (getResolution select 0)) / 1920) * safeZoneW) / (getResolution select 0)); \
	h = #((((H * (getResolution select 1)) / 1080) * safeZoneH) / (getResolution select 1));
*/

/* Dialog */

class SettingsMenu {
    idd = MrFrost_IDD_Settings;
    name = "SettingsMenu";
    movingEnable = 1;
    enableSimulation = 1;

	class Controls {

		class MainBackground : MrFrost_RscText {
			idc = MrFrost_IDC_MainBackground;
			MrFrost_POSITION(414,249,1093,582)
			colorBackground[] = {0.09412,0.09412,0.09412,1};
		};

		class Bar_Bottom : MrFrost_RscText {
			idc = MrFrost_IDC_Bar_Bottom;
			MrFrost_POSITION(414,831,1093,7)
			colorBackground[] = {0.6902,0,0,1};
		};

		class Bar_Top : MrFrost_RscText {
			idc = MrFrost_IDC_Bar_Top;
			MrFrost_POSITION(414,242,1093,7)
			colorBackground[] = {0.6902,0,0,1};
		};

/////////////////////////////////////////////////////////////////////////////

		class Logo : MrFrost_RscPictureKeepAspect {
			idc = MrFrost_IDC_Logo_Mammut;
			MrFrost_POSITION(1013,424,412,412)
            text = "pictures\GUI\Logo_Mammut.paa";
		};

/////////////////////////////////////////////////////////////////////////////

		class Background_Settings_ViewDistance : MrFrost_RscText {
			idc = MrFrost_IDC_Background_Settings_ViewDistance;
			MrFrost_POSITION(451,307,1019,144)
			colorBackground[] = {0,0,0,0.31};
		};

		class Background_Settings_Buttons : MrFrost_RscText {
			idc = MrFrost_IDC_Background_Settings_Buttons;
			MrFrost_POSITION(451,472,502,316)
			colorBackground[] = {0,0,0,0.31};
		};

		class Background_Settings_Hotkeys_Text : MrFrost_RscText {
			idc = MrFrost_IDC_Background_Settings_Hotkeys_Text;
			MrFrost_POSITION(968,472,502,316)
			colorBackground[] = {0,0,0,0.31};
		};

/////////////////////////////////////////////////////////////////////////////

		class Bar_Settings_ViewDistance : MrFrost_RscText {
			idc = MrFrost_IDC_Bar_Settings_ViewDistance;
			MrFrost_POSITION(451,301,1019,6)
			colorBackground[] = {0.6902,0,0,1};
		};

		class Bar_Settings_Buttons : MrFrost_RscText {
			idc = MrFrost_IDC_Bar_Settings_Buttons;
			MrFrost_POSITION(451,466,502,6)
			colorBackground[] = {0.6902,0,0,1};
		};

		class Bar_Settings_Hotkeys_Text : MrFrost_RscText {
			idc = MrFrost_IDC_Bar_Settings_Hotkeys_Text;
			MrFrost_POSITION(968,466,502,6)
			colorBackground[] = {0.6902,0,0,1};
		};

/////////////////////////////////////////////////////////////////////////////

		class Title_Settings_Title : MrFrost_RscText {
			idc = MrFrost_IDC_Title_Settings_Title;
			MrFrost_POSITION(451,263,1019,40)
			colorBackground[] = {0,0,0,0};
            colortext[] = {1,1,1,1};
            colorShadow[] = {0,0,0,0};
            style = 0x02;
            sizeex = 0.08;
            font = PuristaSemiBold;
			//text = "$STR_SM_Title";
            text = "Settings";
		};

/////////////////////////////////////////////////////////////////////////////

		class Text_Settings_Buttons_SideChat : MrFrost_RscText {
			idc = MrFrost_IDC_Text_Settings_Buttons_SideChat;
			MrFrost_POSITION(466,487,429,28)
            font = PuristaSemiBold;
            sizeEx = 0.035;
            //text = "$STR_SM_SC";
            text = "Show Sidechat";
		};

		class Text_Settings_Buttons_NearObjects : MrFrost_RscText {
			idc = MrFrost_IDC_Text_Settings_Buttons_NearObjects;
			MrFrost_POSITION(466,530,429,28)
            font = PuristaSemiBold;
            sizeEx = 0.035;
            //text = "$STR_SM_RNObj";
            text = "Reveal Nearest Objects";
		};

		class Text_Settings_Buttons_Broadcast : MrFrost_RscText {
			idc = MrFrost_IDC_Text_Settings_Buttons_Broadcast;
			MrFrost_POSITION(466,573,429,28)
            font = PuristaSemiBold;
            sizeEx = 0.035;
            //text = "$STR_SM_BCSW";
			text = "Show Broadcast";
		};

		class Text_Settings_ViewDistance_Foot : MrFrost_RscText {
			idc = MrFrost_IDC_Text_Settings_ViewDistance_Foot;
			MrFrost_POSITION(466,322,228,28)
            font = PuristaSemiBold;
            sizeEx = 0.035;
            //text = "$STR_SM_onFoot";
			text = "View Distance on Foot";
		};

		class Text_Settings_ViewDistance_Car : MrFrost_RscText {
			idc = MrFrost_IDC_Text_Settings_ViewDistance_Car;
			MrFrost_POSITION(466,365,228,28)
            font = PuristaSemiBold;
            sizeEx = 0.035;
            //text = "$STR_SM_inCar";
			text = "View Distance in Car";
		};

		class Text_Settings_ViewDistance_Air : MrFrost_RscText {
			idc = MrFrost_IDC_Text_Settings_ViewDistance_Air;
			MrFrost_POSITION(466,408,228,28)
            font = PuristaSemiBold;
            sizeEx = 0.035;
            //text = "$STR_SM_inAir";
			text = "View Distance in Air";
		};

		class Text_Settings_Hotkeys_Text : MrFrost_RscText {
			idc = MrFrost_IDC_Text_Settings_Hotkeys_Text;
			MrFrost_POSITION(968,472,502,316)
			colorBackground[] = {0,0,0,0};
			text = "TEST";
		};

/////////////////////////////////////////////////////////////////////////////

		class Background_Settings_ViewDistance_Foot : MrFrost_RscText {
			idc = MrFrost_IDC_Background_Settings_ViewDistance_Foot;
			MrFrost_POSITION(710,322,600,28)
			colorBackground[] = {0.09804,0.09804,0.09804,1};
		};

		class Background_Settings_ViewDistance_Car : MrFrost_RscText {
			idc = MrFrost_IDC_Background_Settings_ViewDistance_Car;
			MrFrost_POSITION(710,365,600,28)
			colorBackground[] = {0.09804,0.09804,0.09804,1};
		};

		class Background_Settings_ViewDistance_Air : MrFrost_RscText {
			idc = MrFrost_IDC_Background_Settings_ViewDistance_Air;
			MrFrost_POSITION(710,408,600,28)
			colorBackground[] = {0.09804,0.09804,0.09804,1};
		};

/////////////////////////////////////////////////////////////////////////////

		class Background_Settings_ViewDistance_Foot_Edit : MrFrost_RscText {
			idc = MrFrost_IDC_Background_Settings_ViewDistance_Foot_Edit;
			MrFrost_POSITION(1325,322,130,28)
			colorBackground[] = {0.09804,0.09804,0.09804,1};
		};

		class Background_Settings_ViewDistance_Car_Edit : MrFrost_RscText {
			idc = MrFrost_IDC_Background_Settings_ViewDistance_Car_Edit;
			MrFrost_POSITION(1325,365,130,28)
			colorBackground[] = {0.09804,0.09804,0.09804,1};
		};

		class Background_Settings_ViewDistance_Air_Edit : MrFrost_RscText {
			idc = MrFrost_IDC_Edit_Settings_ViewDistance_Air_Edit;
			MrFrost_POSITION(1325,408,130,28)
			colorBackground[] = {0.09804,0.09804,0.09804,1};
		};

/////////////////////////////////////////////////////////////////////////////

		class Background_Settings_Buttons_SideChat : MrFrost_RscText {
			idc = MrFrost_IDC_Background_Settings_Buttons_SideChat;
			MrFrost_POSITION(910,487,28,28)
			colorBackground[] = {0.09804,0.09804,0.09804,1};
		};

		class Background_Settings_Buttons_NearObjects : MrFrost_RscText {
			idc = MrFrost_IDC_Background_Settings_Buttons_NearObjects;
			MrFrost_POSITION(910,530,28,28)
			colorBackground[] = {0.09804,0.09804,0.09804,1};
		};

		class Background_Settings_Buttons_Broadcast : MrFrost_RscText {
			idc = MrFrost_IDC_Background_Settings_Buttons_Broadcast;
			MrFrost_POSITION(910,573,28,28)
			colorBackground[] = {0.09804,0.09804,0.09804,1};
		};

/////////////////////////////////////////////////////////////////////////////

		class Background_Settings_Buttons_Button_1 : MrFrost_RscText {
			idc = MrFrost_IDC_Background_Settings_Buttons_Button_1;
			MrFrost_POSITION(466,616,228,28)
			colorBackground[] = {0.09804,0.09804,0.09804,1};
		};

		class Background_Settings_Buttons_Button_2 : MrFrost_RscText {
			idc = MrFrost_IDC_Background_Settings_Buttons_Button_2;
			MrFrost_POSITION(710,616,228,28)
			colorBackground[] = {0.09804,0.09804,0.09804,1};
		};

		class Background_Settings_Buttons_Button_3 : MrFrost_RscText {
			idc = MrFrost_IDC_Background_Settings_Buttons_Button_3;
			MrFrost_POSITION(466,659,228,28)
			colorBackground[] = {0.09804,0.09804,0.09804,1};
		};

		class Background_Settings_Buttons_Button_4 : MrFrost_RscText {
			idc = MrFrost_IDC_Background_Settings_Buttons_Button_4;
			MrFrost_POSITION(710,659,228,28)
			colorBackground[] = {0.09804,0.09804,0.09804,1};
		};

		class Background_Settings_Buttons_Button_5 : MrFrost_RscText {
			idc = MrFrost_IDC_Background_Settings_Buttons_Button_5;
			MrFrost_POSITION(466,702,228,28)
			colorBackground[] = {0.09804,0.09804,0.09804,1};
		};

		class Background_Settings_Buttons_Button_6 : MrFrost_RscText {
			idc = MrFrost_IDC_Background_Settings_Buttons_Button_6;
			MrFrost_POSITION(710,702,228,28)
			colorBackground[] = {0.09804,0.09804,0.09804,1};
		};

		class Background_Settings_Buttons_Button_7 : MrFrost_RscText {
			idc = MrFrost_IDC_Background_Settings_Buttons_Button_7;
			MrFrost_POSITION(466,745,228,28)
			colorBackground[] = {0.09804,0.09804,0.09804,1};
		};

		class Background_Settings_Buttons_Button_8 : MrFrost_RscText {
			idc = MrFrost_IDC_Background_Settings_Buttons_Button_8;
			MrFrost_POSITION(710,745,228,28)
			colorBackground[] = {0.09804,0.09804,0.09804,1};
		};

/////////////////////////////////////////////////////////////////////////////

		class Picture_Button_Close : MrFrost_RscPictureKeepAspect {
			idc = MrFrost_IDC_Button_Close;
			MrFrost_POSITION(419,254,18,18)
			colorBackground[] = {0,0,0,0};
            text= "\A3\ui_f\data\GUI\Rsc\RscDisplayArcadeMap\icon_exit_cross_ca.paa";
		};

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

		class Slider_Settings_ViewDistance_Foot : MrFrost_RscXSliderH {
			idc = MrFrost_IDC_Slider_Settings_ViewDistance_Foot;
			MrFrost_POSITION(710,322,600,28)
			colorBackground[] = {0.09804,0.09804,0.09804,1};
            text = "";
            onSliderPosChanged = "[0,_this select 1] call life_fnc_s_onSliderChange;";
            //tooltip = "$STR_SM_ToolTip1";
		};

		class Slider_Settings_ViewDistance_Car : MrFrost_RscXSliderH {
			idc = MrFrost_IDC_Slider_Settings_ViewDistance_Car;
			MrFrost_POSITION(710,365,600,28)
			colorBackground[] = {0.09804,0.09804,0.09804,1};
            text = "";
            onSliderPosChanged = "[1,_this select 1] call life_fnc_s_onSliderChange;";
            //tooltip = "$STR_SM_ToolTip2";
		};

		class Slider_Settings_ViewDistance_Air : MrFrost_RscXSliderH {
			idc = MrFrost_IDC_Slider_Settings_ViewDistance_Air;
			MrFrost_POSITION(710,408,600,28)
			colorBackground[] = {0.09804,0.09804,0.09804,1};
            text = "";
            onSliderPosChanged = "[2,_this select 1] call life_fnc_s_onSliderChange;";
            //tooltip = "$STR_SM_ToolTip3";
		};

/////////////////////////////////////////////////////////////////////////////

		class Edit_Settings_ViewDistance_Foot : MrFrost_RscEdit {
			idc = MrFrost_IDC_Edit_Settings_ViewDistance_Foot;
			MrFrost_POSITION(1325,322,130,28)
			colorBackground[] = {0,0,0,0};
            colortext[] = {1,1,1,1};
            colorShadow[] = {0,0,0,0};
            style = 512;
            sizeex = 0.048;
            text= "1";
            onChar = "[_this select 0, _this select 1,'ground',false] call life_fnc_s_onChar;";
            onKeyUp = "[_this select 0, _this select 1,'ground',true] call life_fnc_s_onChar;";
		};

		class Edit_Settings_ViewDistance_Car : MrFrost_RscEdit {
			idc = MrFrost_IDC_Edit_Settings_ViewDistance_Car;
			MrFrost_POSITION(1325,365,130,28)
			colorBackground[] = {0,0,0,0};
            colortext[] = {1,1,1,1};
            colorShadow[] = {0,0,0,0};
            style = 512;
            sizeex = 0.048;
            text= "1";
            onChar = "[_this select 0, _this select 1,'vehicle',false] call life_fnc_s_onChar;";
            onKeyUp = "[_this select 0, _this select 1,'vehicle',true] call life_fnc_s_onChar;";
		};

		class Edit_Settings_ViewDistance_Air : MrFrost_RscEdit {
			idc = MrFrost_IDC_Edit_Settings_ViewDistance_Air;
			MrFrost_POSITION(1325,408,130,28)
			colorBackground[] = {0,0,0,0};
            colortext[] = {1,1,1,1};
            colorShadow[] = {0,0,0,0};
            style = 512;
            sizeex = 0.048;
            text= "1";
            onChar = "[_this select 0, _this select 1,'air',false] call life_fnc_s_onChar;";
            onKeyUp = "[_this select 0, _this select 1,'air',true] call life_fnc_s_onChar;";
		};

/////////////////////////////////////////////////////////////////////////////

		class Button_Settings_Buttons_SideChat : Life_Checkbox {
			idc = MrFrost_IDC_Button_Settings_Buttons_SideChat;
			MrFrost_POSITION(910,487,28,28)
			colorBackground[] = {0.09804,0.09804,0.09804,1};
			//tooltip = "$STR_GUI_SideSwitch";
			onCheckedChanged = "['tags',_this select 1] call life_fnc_s_onCheckedChange;";

            //sizeEx = 0.04;
		};

		class Button_Settings_Buttons_NearObjects : Life_Checkbox {
			idc = MrFrost_IDC_Button_Settings_Buttons_NearObjects;
			MrFrost_POSITION(910,530,28,28)
			colorBackground[] = {0.09804,0.09804,0.09804,1};
			//tooltip = "$STR_GUI_PlayerReveal";
			onCheckedChanged = "['objects',_this select 1] call life_fnc_s_onCheckedChange;";
		};

		class Button_Settings_Buttons_Broadcast : Life_Checkbox {
			idc = MrFrost_IDC_Button_Settings_Buttons_Broadcast;
			MrFrost_POSITION(910,573,28,28)
			colorBackground[] = {0.09804,0.09804,0.09804,1};
            //tooltip = "$STR_GUI_BroadcastSwitch";
            onCheckedChanged = "['broadcast',_this select 1] call life_fnc_s_onCheckedChange;";
		};

/////////////////////////////////////////////////////////////////////////////

		class Button_Settings_Buttons_Button_1 : MrFrost_RscButton {
			idc = MrFrost_IDC_Button_Settings_Buttons_Button_1;
			MrFrost_POSITION(466,616,228,28)
			colorBackground[] = {0.098,0.098,0.098,1};
            colortext[] = {1,1,1,1};
			colorBackgroundActive[] = {0.69,0,0,1};
			colorFocused[] = {0.098,0.098,0.098,1};
            colorShadow[] = {0,0,0,0};
            soundEnter[] = {"\A3\ui_f\data\sound\RscButton\soundEnter",0.09,1};
            soundPush[] = {"\A3\ui_f\data\sound\RscButton\soundPush",0.09,1};
            soundClick[] = {"\A3\ui_f\data\sound\RscButton\soundClick",0.09,1};
            soundEscape[] = {"\A3\ui_f\data\sound\RscButton\soundEscape",0.09,1};
            font = PuristaSemiBold;
            sizeEx = 0.035;
            text= "Button 1";
		};

		class Button_Settings_Buttons_Button_2 : MrFrost_RscButton {
			idc = MrFrost_IDC_Button_Settings_Buttons_Button_2;
			MrFrost_POSITION(710,616,228,28)
			colorBackground[] = {0.098,0.098,0.098,1};
            colortext[] = {1,1,1,1};
			colorBackgroundActive[] = {0.69,0,0,1};
			colorFocused[] = {0.098,0.098,0.098,1};
            colorShadow[] = {0,0,0,0};
            soundEnter[] = {"\A3\ui_f\data\sound\RscButton\soundEnter",0.09,1};
            soundPush[] = {"\A3\ui_f\data\sound\RscButton\soundPush",0.09,1};
            soundClick[] = {"\A3\ui_f\data\sound\RscButton\soundClick",0.09,1};
            soundEscape[] = {"\A3\ui_f\data\sound\RscButton\soundEscape",0.09,1};
            font = PuristaSemiBold;
            sizeEx = 0.035;
            text= "Button 2";
		};

		class Button_Settings_Buttons_Button_3 : MrFrost_RscButton {
			idc = MrFrost_IDC_Button_Settings_Buttons_Button_3;
			MrFrost_POSITION(466,659,228,28)
			colorBackground[] = {0.098,0.098,0.098,1};
            colortext[] = {1,1,1,1};
			colorBackgroundActive[] = {0.69,0,0,1};
			colorFocused[] = {0.098,0.098,0.098,1};
            colorShadow[] = {0,0,0,0};
            soundEnter[] = {"\A3\ui_f\data\sound\RscButton\soundEnter",0.09,1};
            soundPush[] = {"\A3\ui_f\data\sound\RscButton\soundPush",0.09,1};
            soundClick[] = {"\A3\ui_f\data\sound\RscButton\soundClick",0.09,1};
            soundEscape[] = {"\A3\ui_f\data\sound\RscButton\soundEscape",0.09,1};
            font = PuristaSemiBold;
            sizeEx = 0.035;
            text= "Button 3";
		};

		class Button_Settings_Buttons_Button_4 : MrFrost_RscButton {
			idc = MrFrost_IDC_Button_Settings_Buttons_Button_4;
			MrFrost_POSITION(710,659,228,28)
			colorBackground[] = {0.098,0.098,0.098,1};
            colortext[] = {1,1,1,1};
			colorBackgroundActive[] = {0.69,0,0,1};
			colorFocused[] = {0.098,0.098,0.098,1};
            colorShadow[] = {0,0,0,0};
            soundEnter[] = {"\A3\ui_f\data\sound\RscButton\soundEnter",0.09,1};
            soundPush[] = {"\A3\ui_f\data\sound\RscButton\soundPush",0.09,1};
            soundClick[] = {"\A3\ui_f\data\sound\RscButton\soundClick",0.09,1};
            soundEscape[] = {"\A3\ui_f\data\sound\RscButton\soundEscape",0.09,1};
            font = PuristaSemiBold;
            sizeEx = 0.035;
            text= "Button 4";
		};

		class Button_Settings_Buttons_Button_5 : MrFrost_RscButton {
			idc = MrFrost_IDC_Button_Settings_Buttons_Button_5;
			MrFrost_POSITION(466,702,228,28)
			colorBackground[] = {0.098,0.098,0.098,1};
            colortext[] = {1,1,1,1};
			colorBackgroundActive[] = {0.69,0,0,1};
			colorFocused[] = {0.098,0.098,0.098,1};
            colorShadow[] = {0,0,0,0};
            soundEnter[] = {"\A3\ui_f\data\sound\RscButton\soundEnter",0.09,1};
            soundPush[] = {"\A3\ui_f\data\sound\RscButton\soundPush",0.09,1};
            soundClick[] = {"\A3\ui_f\data\sound\RscButton\soundClick",0.09,1};
            soundEscape[] = {"\A3\ui_f\data\sound\RscButton\soundEscape",0.09,1};
            font = PuristaSemiBold;
            sizeEx = 0.035;
            text= "Button 5";
		};

		class Button_Settings_Buttons_Button_6 : MrFrost_RscButton {
			idc = MrFrost_IDC_Button_Settings_Buttons_Button_6;
			MrFrost_POSITION(710,702,228,28)
			colorBackground[] = {0.098,0.098,0.098,1};
            colortext[] = {1,1,1,1};
			colorBackgroundActive[] = {0.69,0,0,1};
			colorFocused[] = {0.098,0.098,0.098,1};
            colorShadow[] = {0,0,0,0};
            soundEnter[] = {"\A3\ui_f\data\sound\RscButton\soundEnter",0.09,1};
            soundPush[] = {"\A3\ui_f\data\sound\RscButton\soundPush",0.09,1};
            soundClick[] = {"\A3\ui_f\data\sound\RscButton\soundClick",0.09,1};
            soundEscape[] = {"\A3\ui_f\data\sound\RscButton\soundEscape",0.09,1};
            font = PuristaSemiBold;
            sizeEx = 0.035;
            text= "Button 6";
		};

		class Button_Settings_Buttons_Button_7 : MrFrost_RscButton {
			idc = MrFrost_IDC_Button_Settings_Buttons_Button_7;
			MrFrost_POSITION(466,745,228,28)
			colorBackground[] = {0.098,0.098,0.098,1};
            colortext[] = {1,1,1,1};
			colorBackgroundActive[] = {0.69,0,0,1};
			colorFocused[] = {0.098,0.098,0.098,1};
            colorShadow[] = {0,0,0,0};
            soundEnter[] = {"\A3\ui_f\data\sound\RscButton\soundEnter",0.09,1};
            soundPush[] = {"\A3\ui_f\data\sound\RscButton\soundPush",0.09,1};
            soundClick[] = {"\A3\ui_f\data\sound\RscButton\soundClick",0.09,1};
            soundEscape[] = {"\A3\ui_f\data\sound\RscButton\soundEscape",0.09,1};
            font = PuristaSemiBold;
            sizeEx = 0.035;
            text= "Button 7";
		};

		class Button_Settings_Buttons_Button_8 : MrFrost_RscButton {
			idc = MrFrost_IDC_Button_Settings_Buttons_Button_8;
			MrFrost_POSITION(710,745,228,28)
			colorBackground[] = {0.098,0.098,0.098,1};
            colortext[] = {1,1,1,1};
			colorBackgroundActive[] = {0.69,0,0,1};
			colorFocused[] = {0.098,0.098,0.098,1};
            colorShadow[] = {0,0,0,0};
            soundEnter[] = {"\A3\ui_f\data\sound\RscButton\soundEnter",0.09,1};
            soundPush[] = {"\A3\ui_f\data\sound\RscButton\soundPush",0.09,1};
            soundClick[] = {"\A3\ui_f\data\sound\RscButton\soundClick",0.09,1};
            soundEscape[] = {"\A3\ui_f\data\sound\RscButton\soundEscape",0.09,1};
            font = PuristaSemiBold;
            sizeEx = 0.035;
            text= "Button 8";
		};

/////////////////////////////////////////////////////////////////////////////

		class Button_Close {
			idc = MrFrost_IDC_Button_Close;
			MrFrost_POSITION(419,254,18,18)
			colorBackground[] = {0,0,0,0};
            colortext[] = {1,1,1,0};
			colorBackgroundActive[] = {0,0,0,0};
			colorFocused[] = {0,0,0,0};
            colorShadow[] = {0,0,0,0};
            soundEnter[] = {"\A3\ui_f\data\sound\RscButton\soundEnter",0.09,1};
            soundPush[] = {"\A3\ui_f\data\sound\RscButton\soundPush",0.09,1};
            soundClick[] = {"\A3\ui_f\data\sound\RscButton\soundClick",0.09,1};
            soundEscape[] = {"\A3\ui_f\data\sound\RscButton\soundEscape",0.09,1};
            font = PuristaSemiBold;
            sizeEx = 0.035;
            text= "";
            onButtonClick = "closeDialog 0;";
		};
	};
};
