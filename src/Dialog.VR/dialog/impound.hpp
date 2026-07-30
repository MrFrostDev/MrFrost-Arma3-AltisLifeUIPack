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
 * impound.hpp - Garage / impound
 *
 * Part of    : Altis Life UI Pack (MrFrost, 2021) - archived, unmaintained.
 * Root class : Life_impound_menu
 * IDD        : MrFrost_IDD_Garage = 2800
 * Opened by  : createDialog "Life_impound_menu";
 * Requires   : dialog/MrFrost_defines.hpp (MrFrost_POSITION and the
 *              MrFrost_Rsc* base classes) and dialog/common.hpp.
 *
 * Positions are authored against a 1920x1080 reference canvas.
 * MrFrost_POSITION(X,Y,W,H) rewrites those pixel values into
 * safezone-relative coordinates at preprocess time, so the numbers
 * below can be read directly as pixels on a 1080p screen.
 *
 * Full IDD/IDC table : docs/dialog-reference.md
 * Before production  : docs/known-issues.md
 * ------------------------------------------------------------------------- */
 /* IDD/IDCs Macros */
#define MrFrost_IDD_Garage 2800
//Main Background
#define MrFrost_IDC_Garage_MainBackground -1
#define MrFrost_IDC_Garage_Bar_Bottom -1
#define MrFrost_IDC_Garage_Bar_Top -1
#define MrFrost_IDC_Garage_Button_Close_Image -1
//Parts Background
#define MrFrost_IDC_Garage_Background_Garage_List -1
#define MrFrost_IDC_Garage_Background_Info -1
#define MrFrost_IDC_Garage_Background_Buttons -1
#define MrFrost_IDC_Garage_Bar_Garage_List -1
#define MrFrost_IDC_Garage_Bar_Info -1
#define MrFrost_IDC_Garage_Bar_Buttons -1
//Titles
#define MrFrost_IDC_Garage_Title_Garage_List 2801
#define MrFrost_IDC_Garage_Title_Info 2830
//Elements
#define MrFrost_IDC_Garage_Garage_List 2802
#define MrFrost_IDC_Garage_Text_Info 2803
//Buttons
#define MrFrost_IDC_Garage_Button_Retrieve -1
#define MrFrost_IDC_Garage_Button_Insurance 2804
#define MrFrost_IDC_Garage_Button_Sell -1
//Main Buttons
#define MrFrost_IDC_Garage_Button_Close -1

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
class Life_impound_menu {
    idd = MrFrost_IDD_Garage;
    name="life_impound_menu";
    movingEnable = 0;
    enableSimulation = 1;

    class Controls {

////////////////////////////////////////////////////////////////////////////////

        class Picture_Preview : RscPicture {
            idc = -1;
            MrFrost_POSITION(0,0,1920,1080)
            text = "pictures\GUI\PreviewBackground.jpg";
        };

////////////////////////////////////////////////////////////////////////////////

        class Garage_MainBackground : RscText {
			idc = MrFrost_IDC_Garage_MainBackground;
			MrFrost_POSITION(615,249,691,582)
			colorBackground[] = {0.094,0.094,0.094,1};
		};

        class Garage_Bar_Bottom : RscText {
			idc = MrFrost_IDC_Garage_Bar_Bottom;
			MrFrost_POSITION(615,831,691,7)
			colorBackground[] = {0.69,0,0,1};
		};

        class Garage_Bar_Top : RscText {
			idc = MrFrost_IDC_Garage_Bar_Top;
			MrFrost_POSITION(615,242,691,7)
			colorBackground[] = {0.69,0,0,1};
		};

////////////////////////////////////////////////////////////////////////////////

        class Garage_Background_Garage_List : RscText {
			idc = MrFrost_IDC_Garage_Background_Garage_List;
			MrFrost_POSITION(652,308,290,508)
			colorBackground[] = {0,0,0,0.31};
		};

        class Garage_Background_Info : RscText {
			idc = MrFrost_IDC_Garage_Background_Info;
			MrFrost_POSITION(979,308,290,343)
			colorBackground[] = {0,0,0,0.31};
		};

        class Garage_Background_Buttons : RscText {
			idc = MrFrost_IDC_Garage_Background_Buttons;
			MrFrost_POSITION(979,672,290,144)
			colorBackground[] = {0,0,0,0.31};
		};

////////////////////////////////////////////////////////////////////////////////

        class Garage_Bar_Garage_List : RscText {
			idc = MrFrost_IDC_Garage_Bar_Garage_List;
			MrFrost_POSITION(652,302,290,6)
			colorBackground[] = {0.69,0,0,1};
		};

        class Garage_Bar_Info : RscText {
			idc = MrFrost_IDC_Garage_Bar_Info;
			MrFrost_POSITION(979,302,290,6)
			colorBackground[] = {0.69,0,0,1};
		};

        class Garage_Bar_Buttons : RscText {
			idc = MrFrost_IDC_Garage_Bar_Buttons;
			MrFrost_POSITION(979,666,290,6)
			colorBackground[] = {0.69,0,0,1};
		};

////////////////////////////////////////////////////////////////////////////////

        class Garage_Title_Garage_List : RscText {
			idc = MrFrost_IDC_Garage_Title_Garage_List;
			MrFrost_POSITION(652,264,290,40)
			colorBackground[] = {0,0,0,0};
            colortext[] = {1,1,1,1};
            colorShadow[] = {0,0,0,0};
            style = 0x02;
            sizeex = 0.08;
            font = PuristaSemiBold;
            //text = "$STR_GUI_Garage";
            text = "Garage";
		};

        class Garage_Title_Info : RscText {
			idc = MrFrost_IDC_Garage_Title_Info;
			MrFrost_POSITION(979,264,290,40)
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

        class Garage_Garage_List : Life_RscListBox {
			idc = MrFrost_IDC_Garage_Garage_List;
			MrFrost_POSITION(652,310,290,503)
			colorBackground[] = {0,0,0,0};
            colortext[] = {1,1,1,1};
            colorShadow[] = {0,0,0,0};
            sizeEx = 0.035;
            onLBSelChanged = "_this call life_fnc_garageLBChange;";
		};

        class Garage_Text_Info : Life_RscListBox {
			idc = MrFrost_IDC_Garage_Text_Info;
			MrFrost_POSITION(979,310,290,338)
			colorBackground[] = {0,0,0,0};
            colortext[] = {1,1,1,1};
            colorShadow[] = {0,0,0,0};
            sizeEx = 0.035;
            text = "";
		};

////////////////////////////////////////////////////////////////////////////////

        class Garage_Button_Retrieve : RscButton {
			idc = MrFrost_IDC_Garage_Button_Retrieve;
			MrFrost_POSITION(994,687,260,28)
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
            //text = "$STR_Global_Retrieve";
            text= "Retrieve";
            onButtonClick = "[] call life_fnc_unimpound;";
		};

        class Garage_Button_Buy_Insurance : RscButton {
			idc = MrFrost_IDC_Garage_Button_Insurance;
			MrFrost_POSITION(994,730,260,28)
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
            text= "Insure";
			onButtonClick = "[] call life_fnc_insureCar;";
		};

        class Garage_Button_Sell : RscButton {
			idc = MrFrost_IDC_Garage_Button_Sell;
			MrFrost_POSITION(994,773,260,28)
			colorBackground[] = {0.69,0,0,1};
            colortext[] = {1,1,1,1};
			colorBackgroundActive[] = {1,0.435,0,1};
			colorFocused[] = {0.69,0,0,1};
            colorShadow[] = {0,0,0,0};
            soundEnter[] = {"\A3\ui_f\data\sound\RscButton\soundEnter",0.09,1};
            soundPush[] = {"\A3\ui_f\data\sound\RscButton\soundPush",0.09,1};
            soundClick[] = {"\A3\ui_f\data\sound\RscButton\soundClick",0.09,1};
            soundEscape[] = {"\A3\ui_f\data\sound\RscButton\soundEscape",0.09,1};
            font = PuristaSemiBold;
            sizeEx = 0.035;
            //text = "$STR_Global_Sell";
            text= "Sell";
            onButtonClick = "[] call life_fnc_sellGarage; closeDialog 0;";
		};

////////////////////////////////////////////////////////////////////////////////

        class Garage_Button_Close_Image : RscPicture {
			idc = MrFrost_IDC_Garage_Button_Close_Image;
			MrFrost_POSITION(620,254,18,18)
			colorBackground[] = {0,0,0,0};
            text= "\A3\ui_f\data\GUI\Rsc\RscDisplayArcadeMap\icon_exit_cross_ca.paa";
		};

        class Garage_Button_Close : RscButton {
			idc = MrFrost_IDC_Garage_Button_Close;
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
            onButtonClick = "closeDialog 0;";
        };
    };
};
