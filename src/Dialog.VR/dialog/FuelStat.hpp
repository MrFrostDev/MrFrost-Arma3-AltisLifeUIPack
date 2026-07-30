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
 * FuelStat.hpp - Fuel station
 *
 * Part of    : Altis Life UI Pack (MrFrost, 2021) - archived, unmaintained.
 * Root class : Life_FuelStat
 * IDD        : MrFrost_IDD_Fuel = 20300
 * Opened by  : createDialog "Life_FuelStat";
 * Requires   : dialog/MrFrost_defines.hpp (MrFrost_POSITION and the
 *              MrFrost_Rsc* base classes) and dialog/common.hpp.
 *
 * Positions are authored against a 1920x1080 reference canvas.
 * MrFrost_POSITION(X,Y,W,H) rewrites those pixel values into
 * safezone-relative coordinates at preprocess time, so the numbers
 * below can be read directly as pixels on a 1080p screen.
 *
 * Note       : onLoad hides control 2330, an id that belongs to the stock
 *              vehicle shop - most likely a leftover.
 *
 * Full IDD/IDC table : docs/dialog-reference.md
 * Before production  : docs/known-issues.md
 * ------------------------------------------------------------------------- */
 /* IDD/IDCs Macros */
#define MrFrost_IDD_Fuel 20300
//Main Background
#define MrFrost_IDC_Fuel_MainBackground -1
#define MrFrost_IDC_Fuel_Bar_Bottom -1
#define MrFrost_IDC_Fuel_Bar_Top -1
#define MrFrost_IDC_Fuel_Button_Close_Image -1
//Parts Background
#define MrFrost_IDC_Fuel_Background_Vehicle_List -1
#define MrFrost_IDC_Fuel_Background_Info -1
#define MrFrost_IDC_Fuel_Background_Buttons -1
#define MrFrost_IDC_Fuel_Bar_Vehicle_List -1
#define MrFrost_IDC_Fuel_Bar_Info -1
#define MrFrost_IDC_Fuel_Bar_Buttons -1
//Titles
#define MrFrost_IDC_Fuel_Title_Vehicle_List 20301
#define MrFrost_IDC_Fuel_Title_Info 20330
#define MrFrost_IDC_Fuel_Text_Fuel 20324
#define MrFrost_IDC_Fuel_Text_Total 20323
#define MrFrost_IDC_Fuel_Text_Price 20322
//Elements
#define MrFrost_IDC_Fuel_Vehicle_List 20302
#define MrFrost_IDC_Fuel_Text_Info 20303
#define MrFrost_IDC_Fuel_Background_Slider -1
#define MrFrost_IDC_Fuel_Slider 20901
//Buttons
#define MrFrost_IDC_Fuel_Button_Refuel 20309
//Main Buttons
#define MrFrost_IDC_Fuel_Button_Close -1

/* Positions Macros */
/*
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
class Life_FuelStat {
    idd = MrFrost_IDD_Fuel;
    name="life_fuelStat";
    movingEnabled = 0;
    enableSimulation = 1;
    onLoad = "ctrlShow [2330,false];";
    onUnload = "life_action_inUse = false;";

    class Controls {

////////////////////////////////////////////////////////////////////////////////

        /*class Picture_Preview : MrFrost_RscPicture {
            idc = -1;
            MrFrost_POSITION(0,0,1920,1080)
            text = "pictures\GUI\PreviewBackground.jpg";
        };*/

////////////////////////////////////////////////////////////////////////////////

        class Fuel_MainBackground : MrFrost_RscText {
			idc = MrFrost_IDC_Fuel_MainBackground;
			MrFrost_POSITION(615,249,691,582)
			colorBackground[] = {0.094,0.094,0.094,1};
		};

        class Fuel_Bar_Bottom : MrFrost_RscText {
			idc = MrFrost_IDC_Fuel_Bar_Bottom;
			MrFrost_POSITION(615,831,691,7)
			colorBackground[] = {0.69,0,0,1};
		};

        class Fuel_Bar_Top : MrFrost_RscText {
			idc = MrFrost_IDC_Fuel_Bar_Top;
			MrFrost_POSITION(615,242,691,7)
			colorBackground[] = {0.69,0,0,1};
		};

////////////////////////////////////////////////////////////////////////////////

        class Fuel_Background_Vehicle_List : MrFrost_RscText {
			idc = MrFrost_IDC_Fuel_Background_Vehicle_List;
			MrFrost_POSITION(652,308,301,371)
			colorBackground[] = {0,0,0,0.31};
		};

        class Fuel_Background_Info : MrFrost_RscText {
			idc = MrFrost_IDC_Fuel_Background_Info;
			MrFrost_POSITION(968,308,301,371)
			colorBackground[] = {0,0,0,0.31};
		};

        class Fuel_Background_Buttons : MrFrost_RscText {
			idc = MrFrost_IDC_Fuel_Background_Buttons;
			MrFrost_POSITION(652,700,617,101)
			colorBackground[] = {0,0,0,0.31};
		};

////////////////////////////////////////////////////////////////////////////////

        class Fuel_Bar_Vehicle_List : MrFrost_RscText {
			idc = MrFrost_IDC_Fuel_Bar_Vehicle_List;
			MrFrost_POSITION(652,302,301,6)
			colorBackground[] = {0.69,0,0,1};
		};

        class Fuel_Bar_Info : MrFrost_RscText {
			idc = MrFrost_IDC_Fuel_Bar_Info;
			MrFrost_POSITION(968,302,301,6)
			colorBackground[] = {0.69,0,0,1};
		};

        class Fuel_Bar_Buttons : MrFrost_RscText {
			idc = MrFrost_IDC_Fuel_Bar_Buttons;
			MrFrost_POSITION(652,694,617,6)
			colorBackground[] = {0.69,0,0,1};
		};

////////////////////////////////////////////////////////////////////////////////

        class Fuel_Title_Vehicle_List : MrFrost_RscText {
			idc = MrFrost_IDC_Fuel_Title_Vehicle_List;
			MrFrost_POSITION(652,264,301,40)
			colorBackground[] = {0,0,0,0};
            colortext[] = {1,1,1,1};
            colorShadow[] = {0,0,0,0};
            style = 0x02;
            sizeex = 0.08;
            font = PuristaSemiBold;
            //text = "$STR_GUI_Fuel";
            text = "Gas Station";
		};

        class Fuel_Title_Info : MrFrost_RscText {
			idc = MrFrost_IDC_Fuel_Title_Info;
			MrFrost_POSITION(968,264,301,40)
			colorBackground[] = {0,0,0,0};
            colortext[] = {1,1,1,1};
            colorShadow[] = {0,0,0,0};
            style = 0x02;
            sizeex = 0.08;
            font = PuristaSemiBold;
            //text = "$STR_GUI_VehInfo";
            text = "Vehicle Specs";
		};

////////////////////////////////////////////////////////////////////////////////

        class Fuel_Vehicle_List : MrFrost_RscListBox {
			idc = MrFrost_IDC_Fuel_Vehicle_List;
			MrFrost_POSITION(652,310,301,366)
			colorBackground[] = {0,0,0,0};
            colortext[] = {1,1,1,1};
            colorShadow[] = {0,0,0,0};
            sizeEx = 0.035;
            onLBSelChanged = "_this call life_fnc_FuelLBChange;";
		};

        class Fuel_Text_Info : MrFrost_RscStructuredText {
			idc = MrFrost_IDC_Fuel_Text_Info;
			MrFrost_POSITION(968,308,301,371)
			colorBackground[] = {0,0,0,0};
            colortext[] = {1,1,1,1};
            colorShadow[] = {0,0,0,0};
            sizeEx = 0.035;
            text = "Super cool Specs";
		};

        class Fuel_Text_Fuel : MrFrost_RscText {
			idc = MrFrost_IDC_Fuel_Text_Fuel;
			MrFrost_POSITION(968,715,135,28)
            font = PuristaSemiBold;
            sizeEx = 0.035;
            text = "Fuel: 123 Liter";
		};

        class Fuel_Text_Total : MrFrost_RscText {
			idc = MrFrost_IDC_Fuel_Text_Total;
			MrFrost_POSITION(1119,715,135,28)
            font = PuristaSemiBold;
            sizeEx = 0.035;
            text = "Total: 12345678$";
		};

        class Fuel_Text_Price : MrFrost_RscText {
			idc = MrFrost_IDC_Fuel_Text_Price;
			MrFrost_POSITION(667,758,286,28)
            font = PuristaSemiBold;
            sizeEx = 0.035;
            text = "Price per Liter: 123456$";
		};

////////////////////////////////////////////////////////////////////////////////

        class Fuel_Background_Slider : MrFrost_RscText {
			idc = MrFrost_IDC_Fuel_Slider;
			MrFrost_POSITION(667,715,286,28)
			colorBackground[] = {0.09804,0.09804,0.09804,1};
            text = "";
        };

        class Fuel_Slider : MrFrost_RscXSliderH {
			idc = MrFrost_IDC_Fuel_Slider;
			MrFrost_POSITION(667,715,286,28)
			colorBackground[] = {0.09804,0.09804,0.09804,1};
            text = "";
            tooltip = "";
            onSliderPosChanged = "[3,_this select 1] call life_fnc_s_onSliderChange;";
        };

////////////////////////////////////////////////////////////////////////////////

        class Fuel_Button_Refuel : MrFrost_RscButton {
			idc = MrFrost_IDC_Fuel_Button_Refuel;
			MrFrost_POSITION(968,758,286,28)
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
            //text = "$STR_Global_Refuel";
            text= "Refuel";
            onButtonClick = "[] spawn life_fnc_fuelRefuelCar;";
		};

////////////////////////////////////////////////////////////////////////////////

        class Fuel_Button_Close_Image : MrFrost_RscPictureKeepAspect {
			idc = MrFrost_IDC_Fuel_Button_Close_Image;
			MrFrost_POSITION(620,254,18,18)
			colorBackground[] = {0,0,0,0};
            text= "\A3\ui_f\data\GUI\Rsc\RscDisplayArcadeMap\icon_exit_cross_ca.paa";
		};

        class Fuel_Button_Close : MrFrost_RscButton {
			idc = MrFrost_IDC_Fuel_Button_Close;
			MrFrost_POSITION(620,254,18,18)
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
            onButtonClick = "closeDialog 0; life_action_inUse = false;";
        };
    };
};
