/*
 * Dialog by MrFrost
 * Macros by Heyoxe
 *
 * Hereby I forbid the publication under a different name, as original or modified, without my explicit permission.
 * This script was developed explicitly for all "Mammut-Roleplay.de Servers".
 * It is not allowed to use, publish or Store it on other platforms without my explicit permission.
 * It is not allowed to remove this header.
 */

/* --------------------------------------------------------------------------
 * trunk.hpp - Vehicle trunk
 *
 * Part of    : Altis Life UI Pack (MrFrost, 2021) - archived, unmaintained.
 * Root class : TrunkMenu
 * IDD        : MrFrost_IDD_Trunk = 3500
 * Opened by  : createDialog "TrunkMenu";
 * Requires   : dialog/MrFrost_defines.hpp (MrFrost_POSITION and the
 *              MrFrost_Rsc* base classes) and dialog/common.hpp.
 *
 * Positions are authored against a 1920x1080 reference canvas.
 * MrFrost_POSITION(X,Y,W,H) rewrites those pixel values into
 * safezone-relative coordinates at preprocess time, so the numbers
 * below can be read directly as pixels on a 1080p screen.
 *
 * Note       : Shares resolved IDD 3500 with federalReserve.hpp, and the
 *              macro name is reused by newsStation.hpp.
 *
 * Full IDD/IDC table : docs/dialog-reference.md
 * Before production  : docs/known-issues.md
 * ------------------------------------------------------------------------- */
 /* IDD/IDCs Macros */
#define MrFrost_IDD_Trunk 3500
//Main Background
#define MrFrost_IDC_Trunk_MainBackground -1
#define MrFrost_IDC_Trunk_Bar_Bottom -1
#define MrFrost_IDC_Trunk_Bar_Top -1
#define MrFrost_IDC_Trunk_Button_Close_Image -1
//Parts Background
#define MrFrost_IDC_Trunk_Background_Vehicle_Trunk_List -1
#define MrFrost_IDC_Trunk_Background_Inventory_List -1
#define MrFrost_IDC_Trunk_Background_Vehicle_Trunk_Buttons -1
#define MrFrost_IDC_Trunk_Background_Inventory_Buttons -1
#define MrFrost_IDC_Trunk_Bar_Vehicle_Trunk_List -1
#define MrFrost_IDC_Trunk_Bar_Inventory_List -1
#define MrFrost_IDC_Trunk_Bar_Vehicle_Trunk_Buttons -1
#define MrFrost_IDC_Trunk_Bar_Inventory_Buttons -1
//Titles
#define MrFrost_IDC_Trunk_Title_Vehicle_Trunk_List 2403
#define MrFrost_IDC_Trunk_Title_Inventory_List -1
#define MrFrost_IDC_Trunk_Title_Inventory_Weight 50011
#define MrFrost_IDC_Trunk_Title_Vehicle_Weight 3504
//Elements Background
#define MrFrost_IDC_Trunk_Background_Vehicle_Trunk_Value -1
#define MrFrost_IDC_Trunk_Background_Inventory_Value -1
//Elements
#define MrFrost_IDC_Trunk_Vehicle_Trunk_List 3502
#define MrFrost_IDC_Trunk_Inventory_List 3503
#define MrFrost_IDC_Trunk_Vehicle_Trunk_Value 3505
#define MrFrost_IDC_Trunk_Inventory_Value 3506
//Buttons
#define MrFrost_IDC_Trunk_Button_Take -1
#define MrFrost_IDC_Trunk_Button_Take_All -1
#define MrFrost_IDC_Trunk_Button_Take_5 -1
#define MrFrost_IDC_Trunk_Button_Take_10 -1
#define MrFrost_IDC_Trunk_Button_Store -1
#define MrFrost_IDC_Trunk_Button_Store_All -1
#define MrFrost_IDC_Trunk_Button_Store_5 -1
#define MrFrost_IDC_Trunk_Button_Store_10 -1
//Main Buttons
#define MrFrost_IDC_Trunk_Button_Close -1

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
class TrunkMenu {
	idd = MrFrost_IDD_Trunk;
	name = "TrunkMenu";
	movingEnable = 0;
	enableSimulation = 1;

    class Controls {

        class Trunk_MainBackground : MrFrost_RscText {
			idc = MrFrost_IDC_Trunk_MainBackground;
			MrFrost_POSITION(615,249,691,582)
			colorBackground[] = {0.094,0.094,0.094,1};
		};

        class Trunk_Bar_Bottom : MrFrost_RscText {
			idc = MrFrost_IDC_Trunk_Bar_Bottom;
			MrFrost_POSITION(615,831,691,7)
			colorBackground[] = {0.69,0,0,1};
		};

        class Trunk_Bar_Top : MrFrost_RscText {
			idc = MrFrost_IDC_Trunk_Bar_Top;
			MrFrost_POSITION(615,242,691,7)
			colorBackground[] = {0.69,0,0,1};
		};

////////////////////////////////////////////////////////////////////////////////

        class Trunk_Title_Inventory_Weight : MrFrost_RscText {
			idc = MrFrost_IDC_Trunk_Title_Inventory_Weight;
			MrFrost_POSITION(979,460,290,40)
			colorBackground[] = {0,0,0,0};
            colortext[] = {1,1,1,1};
            colorShadow[] = {0,0,0,0};
            style = 0x02;
            sizeex = 0.08;
            font = PuristaSemiBold;
            text = "100/100";
		};

		class Trunk_Title_Vehicle_Weight : MrFrost_RscText {
			idc = MrFrost_IDC_Trunk_Title_Vehicle_Weight;
			MrFrost_POSITION(652,460,290,40)
			colorBackground[] = {0,0,0,0};
            colortext[] = {1,1,1,1};
            colorShadow[] = {0,0,0,0};
            style = 0x02;
            sizeex = 0.08;
            font = PuristaSemiBold;
            text = "100/100";
		};

////////////////////////////////////////////////////////////////////////////////

        class Trunk_Background_Vehicle_Trunk_List : MrFrost_RscText {
			idc = MrFrost_IDC_Trunk_Background_Vehicle_Trunk_List;
			MrFrost_POSITION(652,308,290,343)
			colorBackground[] = {0,0,0,0.31};
		};

        class Trunk_Background_Inventory_List : MrFrost_RscText {
			idc = MrFrost_IDC_Trunk_Background_Inventory_List;
			MrFrost_POSITION(979,308,290,343)
			colorBackground[] = {0,0,0,0.31};
		};

        class Trunk_Background_Vehicle_Trunk_Buttons : MrFrost_RscText {
			idc = MrFrost_IDC_Trunk_Background_Vehicle_Trunk_Buttons;
			MrFrost_POSITION(652,672,290,144)
			colorBackground[] = {0,0,0,0.31};
		};

        class Trunk_Background_Inventory_Buttons : MrFrost_RscText {
			idc = MrFrost_IDC_Trunk_Background_Inventory_Buttons;
			MrFrost_POSITION(979,672,290,144)
			colorBackground[] = {0,0,0,0.31};
		};

////////////////////////////////////////////////////////////////////////////////

        class Trunk_Bar_Vehicle_Trunk_List : MrFrost_RscText {
			idc = MrFrost_IDC_Trunk_Bar_Vehicle_Trunk_List;
			MrFrost_POSITION(652,302,290,6)
			colorBackground[] = {0.69,0,0,1};
		};

        class Trunk_Bar_Inventory_List : MrFrost_RscText {
			idc = MrFrost_IDC_Trunk_Bar_Inventory_List;
			MrFrost_POSITION(979,302,290,6)
			colorBackground[] = {0.69,0,0,1};
		};

        class Trunk_Bar_Vehicle_Trunk_Buttons : MrFrost_RscText {
			idc = MrFrost_IDC_Trunk_Bar_Vehicle_Trunk_Buttons;
			MrFrost_POSITION(652,666,290,6)
			colorBackground[] = {0.69,0,0,1};
		};

        class Trunk_Bar_Inventory_Buttons : MrFrost_RscText {
			idc = MrFrost_IDC_Trunk_Bar_Inventory_Buttons;
			MrFrost_POSITION(979,666,290,6)
			colorBackground[] = {0.69,0,0,1};
		};

////////////////////////////////////////////////////////////////////////////////

        class Trunk_Title_Vehicle_Trunk_List : MrFrost_RscText {
			idc = MrFrost_IDC_Trunk_Title_Vehicle_Trunk_List;
			MrFrost_POSITION(652,264,290,40)
			colorBackground[] = {0,0,0,0};
            colortext[] = {1,1,1,1};
            colorShadow[] = {0,0,0,0};
            style = 0x02;
            sizeex = 0.08;
            font = PuristaSemiBold;
            //text = "$STR_VS_SI";
            text = "Vehicle Trunk";
		};

        class Trunk_Title_Inventory_List : MrFrost_RscText {
			idc = MrFrost_IDC_Trunk_Title_Inventory_List;
			MrFrost_POSITION(979,264,290,40)
			colorBackground[] = {0,0,0,0};
            colortext[] = {1,1,1,1};
            colorShadow[] = {0,0,0,0};
            style = 0x02;
            sizeex = 0.08;
            font = PuristaSemiBold;
            //text = "$STR_VS_PI";
            text = "Inventory";
		};

////////////////////////////////////////////////////////////////////////////////

        class Trunk_Background_Vehicle_Trunk_Value : MrFrost_RscText {
			idc = MrFrost_IDC_Trunk_Background_Vehicle_Trunk_Value;
			MrFrost_POSITION(667,687,260,28)
			colorBackground[] = {0.098,0.098,0.098,1};
		};

        class Trunk_Background_Inventory_Value : MrFrost_RscText {
			idc = MrFrost_IDC_Trunk_Background_Inventory_Value;
			MrFrost_POSITION(994,687,260,28)
			colorBackground[] = {0.098,0.098,0.098,1};
		};

////////////////////////////////////////////////////////////////////////////////

        class Trunk_Vehicle_Trunk_Value : MrFrost_RscEdit {
			idc = MrFrost_IDC_Trunk_Vehicle_Trunk_Value;
			MrFrost_POSITION(667,687,260,28)
			colorBackground[] = {0,0,0,0};
            colortext[] = {1,1,1,1};
            colorShadow[] = {0,0,0,0};
            style = 512;
            sizeex = 0.048;
            text= "1";
		};

        class Trunk_Inventory_Value : MrFrost_RscEdit {
			idc = MrFrost_IDC_Trunk_Inventory_Value;
			MrFrost_POSITION(994,687,260,28)
			colorBackground[] = {0,0,0,0};
            colortext[] = {1,1,1,1};
            colorShadow[] = {0,0,0,0};
            style = 512;
            sizeex = 0.048;
            text= "1";
		};

////////////////////////////////////////////////////////////////////////////////

        class Trunk_Vehicle_Trunk_List : MrFrost_RscListBox {
			idc = MrFrost_IDC_Trunk_Vehicle_Trunk_List;
			MrFrost_POSITION(652,310,290,338)
			colorBackground[] = {0,0,0,0};
            colortext[] = {1,1,1,1};
            colorShadow[] = {0,0,0,0};
            sizeEx = 0.035;
		};

        class Trunk_Inventory_List : MrFrost_RscListBox {
			idc = MrFrost_IDC_Trunk_Inventory_List;
			MrFrost_POSITION(979,310,290,338)
			colorBackground[] = {0,0,0,0};
            colortext[] = {1,1,1,1};
            colorShadow[] = {0,0,0,0};
            sizeEx = 0.035;
		};

////////////////////////////////////////////////////////////////////////////////

        class Trunk_Button_Take : MrFrost_RscButton {
			idc = MrFrost_IDC_Trunk_Button_Take;
			MrFrost_POSITION(667,730,122,28)
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
            //text = "$STR_VS_TakeItem";
            text= "Take";
            onButtonClick = "[] call Life_fnc_vehTakeItem;";
		};

        class Trunk_Button_Take_All : MrFrost_RscButton {
			idc = MrFrost_IDC_Trunk_Button_Take_All;
			MrFrost_POSITION(805,730,122,28)
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
            //text = "$STR_VS_TakeAllItem"; //Must be added
            text= "Take All";
		};

        class Trunk_Button_Take_5 : MrFrost_RscButton {
			idc = MrFrost_IDC_Trunk_Button_Take_5;
			MrFrost_POSITION(667,773,122,28)
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
            //text = "$STR_VS_TakeFiveItem"; //Must be added
            text= "Take 5";
		};

        class Trunk_Button_Take_10 : MrFrost_RscButton {
			idc = MrFrost_IDC_Trunk_Button_Take_10;
			MrFrost_POSITION(805,773,122,28)
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
            //text = "$STR_VS_TakeTenItem"; //Must be added
            text= "Take 10";
		};

        class Trunk_Button_Store : MrFrost_RscButton {
			idc = MrFrost_IDC_Trunk_Button_Store;
			MrFrost_POSITION(994,730,122,28)
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
            //text = "$STR_VS_StoreItem";
            text= "Store";
            onButtonClick = "[] call Life_fnc_vehStoreItem;";
		};

        class Trunk_Button_Store_All : MrFrost_RscButton {
			idc = MrFrost_IDC_Trunk_Button_Store_All;
			MrFrost_POSITION(1132,730,122,28)
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
            text= "Store All";
            //text = "$STR_VS_StoreAllItem";  //Must be added
            default = 1;
		};

        class Trunk_Button_Store_5 : MrFrost_RscButton {
			idc = MrFrost_IDC_Trunk_Button_Store_5;
			MrFrost_POSITION(994,773,122,28)
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
            //text = "$STR_VS_StoreFiveItem";  //Must be added
            text= "Store 5";
		};

        class Trunk_Button_Store_10 : MrFrost_RscButton {
			idc = MrFrost_IDC_Trunk_Button_Store_10;
			MrFrost_POSITION(1132,773,122,28)
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
            //text = "$STR_VS_StoreTenItem";  //Must be added
            text= "Store 10";
		};

////////////////////////////////////////////////////////////////////////////////

        class Trunk_Button_Close_Image : MrFrost_RscPictureKeepAspect {
			idc = MrFrost_IDC_Trunk_Button_Close_Image;
			MrFrost_POSITION(620,254,18,18)
			colorBackground[] = {0,0,0,0};
            text= "\A3\ui_f\data\GUI\Rsc\RscDisplayArcadeMap\icon_exit_cross_ca.paa";
		};

        class Trunk_Button_Close : MrFrost_RscButton {
			idc = MrFrost_IDC_Trunk_Button_Close;
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
