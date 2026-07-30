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
 * player_inv.hpp - Player inventory / Z-menu
 *
 * Part of    : Altis Life UI Pack (MrFrost, 2021) - archived, unmaintained.
 * Root class : playerSettings
 * IDD        : playersys_DIALOG (from player_sys.sqf) = 2001
 * Opened by  : createDialog "playerSettings";
 * Requires   : dialog/MrFrost_defines.hpp (MrFrost_POSITION and the
 *              MrFrost_Rsc* base classes) and dialog/common.hpp.
 *
 * Positions are authored against a 1920x1080 reference canvas.
 * MrFrost_POSITION(X,Y,W,H) rewrites those pixel values into
 * safezone-relative coordinates at preprocess time, so the numbers
 * below can be read directly as pixels on a 1080p screen.
 *
 * Note       : #include "player_sys.sqf" at the top pulls in the plain
 *              #define list that this dialog indexes into.
 *
 * Full IDD/IDC table : docs/dialog-reference.md
 * Before production  : docs/known-issues.md
 * ------------------------------------------------------------------------- */
#include "player_sys.sqf"

/* IDD/IDCs Macros */
//#define MrFrost_IDD_ZMenu
//Main Background
#define MrFrost_IDC_ZMenu_MainBackgroundMiddle_Diagonal -1
#define MrFrost_IDC_ZMenu_MainBackground -1
#define MrFrost_IDC_ZMenu_Bar_Bottom -1
#define MrFrost_IDC_ZMenu_Bar_Top -1
#define MrFrost_IDC_ZMenu_MainBackgroundMiddle -1
#define MrFrost_IDC_ZMenu_Logo -1
//Background Elements
#define MrFrost_IDC_ZMenu_Background_Licenses -1
#define MrFrost_IDC_ZMenu_Bar_Licenses -1
#define MrFrost_IDC_ZMenu_Background_Money -1
#define MrFrost_IDC_ZMenu_Bar_Money -1
#define MrFrost_IDC_ZMenu_Background_Buttons -1
#define MrFrost_IDC_ZMenu_Bar_Buttons -1
#define MrFrost_IDC_ZMenu_Background_Inventory -1
#define MrFrost_IDC_ZMenu_Bar_Inventory -1
#define MrFrost_IDC_ZMenu_Background_Inventory_Buttons -1
#define MrFrost_IDC_ZMenu_Bar_Inventory_Buttons -1
//Titles
#define MrFrost_IDC_ZMenu_Inventory_Title -1
#define MrFrost_IDC_ZMenu_Money_Title -1
#define MrFrost_IDC_ZMenu_Licenses_Title -1
#define MrFrost_IDC_ZMenu_Tools_Title -1
#define MrFrost_IDC_ZMenu_Project_Text -1
#define MrFrost_IDC_ZMenu_Version_Text -1
//Licenses
#define MrFrost_IDC_ZMenu_Licenses_List -1
#define MrFrost_IDC_ZMenu_Licenses_List_Text 2014
//Background Money
#define MrFrost_IDC_ZMenu_Background_Money_Bank -1
#define MrFrost_IDC_ZMenu_Background_Money_Cash -1
#define MrFrost_IDC_ZMenu_Background_Money_Person -1
#define MrFrost_IDC_ZMenu_Background_Money_Value -1
#define MrFrost_IDC_ZMenu_Money_Bank_Icon -1
#define MrFrost_IDC_ZMenu_Money_Cash_Icon -1
//Usable Money
#define MrFrost_IDC_ZMenu_Money_Bank 50001
#define MrFrost_IDC_ZMenu_Money_Cash 50002
#define MrFrost_IDC_ZMenu_Money_Person 2022
#define MrFrost_IDC_ZMenu_Money_Value 2018
#define MrFrost_IDC_ZMenu_Money_Button_Give 2001
//Background Buttons
#define MrFrost_IDC_ZMenu_Background_Button_1 -1
#define MrFrost_IDC_ZMenu_Background_Button_2 -1
#define MrFrost_IDC_ZMenu_Background_Button_3 -1
#define MrFrost_IDC_ZMenu_Background_Button_4 -1
#define MrFrost_IDC_ZMenu_Background_Button_5 -1
#define MrFrost_IDC_ZMenu_Background_Button_6 -1
#define MrFrost_IDC_ZMenu_Background_Button_7 -1
#define MrFrost_IDC_ZMenu_Background_Button_8 -1
#define MrFrost_IDC_ZMenu_Background_Button_9 -1
#define MrFrost_IDC_ZMenu_Background_Button_10 -1
#define MrFrost_IDC_ZMenu_Background_Button_11 -1
#define MrFrost_IDC_ZMenu_Background_Button_12 -1
#define MrFrost_IDC_ZMenu_Background_Button_13 -1
#define MrFrost_IDC_ZMenu_Background_Button_14 -1
#define MrFrost_IDC_ZMenu_Background_Button_15 -1
//Button Icons
#define MrFrost_IDC_ZMenu_Icon_Button_Settings -1
#define MrFrost_IDC_ZMenu_Icon_Button_Gang -1
#define MrFrost_IDC_ZMenu_Icon_Button_Wanted -1
#define MrFrost_IDC_ZMenu_Icon_Button_Keys -1
#define MrFrost_IDC_ZMenu_Icon_Button_Cellphone -1
#define MrFrost_IDC_ZMenu_Icon_Button_Adminmenu -1
#define MrFrost_IDC_ZMenu_Icon_Button_Achievement -1
#define MrFrost_IDC_ZMenu_Icon_Button_Dispatch -1
#define MrFrost_IDC_ZMenu_Icon_Button_DynMarket -1
#define MrFrost_IDC_ZMenu_Icon_Button_Info -1
#define MrFrost_IDC_ZMenu_Icon_Button_3 -1
#define MrFrost_IDC_ZMenu_Icon_Button_4 -1
#define MrFrost_IDC_ZMenu_Icon_Button_8 -1
#define MrFrost_IDC_ZMenu_Icon_Button_9 -1
#define MrFrost_IDC_ZMenu_Icon_Button_14 -1
//Buttons Buttons
#define MrFrost_IDC_ZMenu_Button_Settings -1
#define MrFrost_IDC_ZMenu_Button_Gang 2011
#define MrFrost_IDC_ZMenu_Button_Wanted 2012
#define MrFrost_IDC_ZMenu_Button_Keys 2013
#define MrFrost_IDC_ZMenu_Button_Cellphone 2014
#define MrFrost_IDC_ZMenu_Button_Adminmenu 2021
#define MrFrost_IDC_ZMenu_Button_Achievement -1
#define MrFrost_IDC_ZMenu_Button_Dispatch -1
#define MrFrost_IDC_ZMenu_Button_DynMarket -1
#define MrFrost_IDC_ZMenu_Button_Info -1
#define MrFrost_IDC_ZMenu_Button_3 -1
#define MrFrost_IDC_ZMenu_Button_4 -1
#define MrFrost_IDC_ZMenu_Button_8 -1
#define MrFrost_IDC_ZMenu_Button_9 -1
#define MrFrost_IDC_ZMenu_Button_14 -1
//Background Inventory
#define MrFrost_IDC_ZMenu_Background_Inventory_Person -1
#define MrFrost_IDC_ZMenu_Background_Inventory_Value -1
//#define MrFrost_IDC_ZMenu_Inventory_Weight -1
//Inventory Usable
//#define MrFrost_IDC_ZMenu_Inventory_List -1  //item_list
#define MrFrost_IDC_ZMenu_Inventory_Person 2023
//#define MrFrost_IDC_ZMenu_Inventory_Value -1  //item_edit
//Inventory Buttons
#define MrFrost_IDC_ZMenu_Inventory_Button_Give 2002
#define MrFrost_IDC_ZMenu_Inventory_Button_Use -1
#define MrFrost_IDC_ZMenu_Inventory_Button_Delete -1
//Main Buttons Background
#define MrFrost_IDC_ZMenu_Background_Button_Close -1
#define MrFrost_IDC_ZMenu_Background_Button_Save -1
//Main Buttons Buttons
#define MrFrost_IDC_ZMenu_Button_Report -1
#define MrFrost_IDC_ZMenu_Button_Close -1
#define MrFrost_IDC_ZMenu_Button_Save -1

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
class playerSettings {
    idd = playersys_DIALOG;
    movingEnable = 1;
    enableSimulation = 1;

    class Controls {

        class ZMenu_MainBackgroundMiddle_Diagonal : MrFrost_RscPictureKeepAspect {
            idc = MrFrost_IDC_ZMenu_MainBackgroundMiddle_Diagonal;
            MrFrost_POSITION(448,28,1024,1024)
            text = "pictures\GUI\ZMenu_Diagonal.paa";
        };

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        class ZMenu_MainBackground : MrFrost_RscText {
			idc = MrFrost_IDC_ZMenu_MainBackground;
			MrFrost_POSITION(414,249,1093,582)
			colorBackground[] = {0.094,0.094,0.094,1};
		};

        class ZMenu_Bar_Bottom : MrFrost_RscText {
			idc = MrFrost_IDC_ZMenu_Bar_Bottom;
			MrFrost_POSITION(414,831,1093,7)
			colorBackground[] = {0.69,0,0,1};
		};

        class ZMenu_Bar_Top : MrFrost_RscText {
			idc = MrFrost_IDC_ZMenu_Bar_Top;
			MrFrost_POSITION(414,242,1093,7)
			colorBackground[] = {0.69,0,0,1};
		};

        class ZMenu_MainBackgroundMiddle : MrFrost_RscText {
			idc = MrFrost_IDC_ZMenu_MainBackgroundMiddle;
			MrFrost_POSITION(779,213,363,654)
			colorBackground[] = {0.055,0.055,0.055,1};
		};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        class ZMenu_Logo : MrFrost_RscPictureKeepAspect {
            idc = MrFrost_IDC_ZMenu_Logo;
            MrFrost_POSITION(754,334,412,412)
            text = "pictures\GUI\Logo_Mammut.paa";
        };

        class ZMenu_Inventory_Weight : MrFrost_RscText {
			idc = carry_weight;
			MrFrost_POSITION(1180,465,290,40)
			colorBackground[] = {0,0,0,0};
            colortext[] = {1,1,1,1};
            colorShadow[] = {0,0,0,0};
            style = 0x02;
            sizeex = 0.08;
            //text = "";
            text= "100/100";
		};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        class ZMenu_Background_Licenses : MrFrost_RscText {
			idc = MrFrost_IDC_ZMenu_Background_Licenses;
			MrFrost_POSITION(815,308,290,507)
			colorBackground[] = {0,0,0,0.31};
		};

        class ZMenu_Background_Money : MrFrost_RscText {
			idc = MrFrost_IDC_ZMenu_Background_Money;
			MrFrost_POSITION(451,308,290,254)
			colorBackground[] = {0,0,0,0.31};
		};

        class ZMenu_Background_Buttons : MrFrost_RscText {
			idc = MrFrost_IDC_ZMenu_Background_Buttons;
			MrFrost_POSITION(451,618,290,197)
			colorBackground[] = {0,0,0,0.31};
		};

        class ZMenu_Background_Inventory : MrFrost_RscText {
			idc = MrFrost_IDC_ZMenu_Background_Inventory;
			MrFrost_POSITION(1180,308,290,353)
			colorBackground[] = {0,0,0,0.31};
		};

        class ZMenu_Background_Inventory_Buttons : MrFrost_RscText {
			idc = MrFrost_IDC_ZMenu_Background_Inventory_Buttons;
			MrFrost_POSITION(1180,688,290,127)
			colorBackground[] = {0,0,0,0.31};
		};

        class ZMenu_Bar_Licenses : MrFrost_RscText {
			idc = MrFrost_IDC_ZMenu_Bar_Licenses;
			MrFrost_POSITION(815,302,290,6)
			colorBackground[] = {0.69,0,0,1};
		};

        class ZMenu_Bar_Money : MrFrost_RscText {
			idc = MrFrost_IDC_ZMenu_Bar_Money;
			MrFrost_POSITION(451,302,290,6)
			colorBackground[] = {0.69,0,0,1};
		};

        class ZMenu_Bar_Buttons : MrFrost_RscText {
			idc = MrFrost_IDC_ZMenu_Bar_Buttons;
			MrFrost_POSITION(451,612,290,6)
			colorBackground[] = {0.69,0,0,1};
		};

        class ZMenu_Bar_Inventory : MrFrost_RscText {
			idc = MrFrost_IDC_ZMenu_Bar_Inventory;
			MrFrost_POSITION(1180,302,290,6)
			colorBackground[] = {0.69,0,0,1};
		};

        class ZMenu_Bar_Inventory_Buttons : MrFrost_RscText {
			idc = MrFrost_IDC_ZMenu_Bar_Inventory_Buttons;
			MrFrost_POSITION(1180,682,290,6)
			colorBackground[] = {0.69,0,0,1};
		};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        class ZMenu_Background_Money_Bank : MrFrost_RscText {
			idc = MrFrost_IDC_ZMenu_Background_Money_Bank;
			MrFrost_POSITION(463,322,266,62)
			colorBackground[] = {0.098,0.098,0.098,1};
		};

        class ZMenu_Background_Money_Cash : MrFrost_RscText {
			idc = MrFrost_IDC_ZMenu_Background_Money_Cash;
			MrFrost_POSITION(463,399,266,62)
			colorBackground[] = {0.098,0.098,0.098,1};
		};

        class ZMenu_Background_Money_Person : MrFrost_RscText {
			idc = MrFrost_IDC_ZMenu_Background_Money_Person;
			MrFrost_POSITION(463,475,266,28)
			colorBackground[] = {0.098,0.098,0.098,1};
		};

        class ZMenu_Background_Money_Value : MrFrost_RscText {
			idc = MrFrost_IDC_ZMenu_Background_Money_Value;
			MrFrost_POSITION(463,518,170,28)
			colorBackground[] = {0.098,0.098,0.098,1};
		};

        class ZMenu_Background_Inventory_Person : MrFrost_RscText {
			idc = MrFrost_IDC_ZMenu_Background_Inventory_Person;
			MrFrost_POSITION(1190,700,271,28)
			colorBackground[] = {0.098,0.098,0.098,1};
		};

        class ZMenu_Background_Inventory_Value : MrFrost_RscText {
			idc = MrFrost_IDC_ZMenu_Background_Inventory_Value;
			MrFrost_POSITION(1190,740,271,28)
			colorBackground[] = {0.098,0.098,0.098,1};
		};

        class ZMenu_Background_Button_1 : MrFrost_RscText {
			idc = MrFrost_IDC_ZMenu_Background_Button_1;
			MrFrost_POSITION(463,640,42,42)
			colorBackground[] = {0.098,0.098,0.098,1};
		};

        class ZMenu_Background_Button_2 : MrFrost_RscText {
			idc = MrFrost_IDC_ZMenu_Background_Button_2;
			MrFrost_POSITION(519,640,42,42)
			colorBackground[] = {0.098,0.098,0.098,1};
        };

        class ZMenu_Background_Button_3 : MrFrost_RscText {
			idc = MrFrost_IDC_ZMenu_Background_Button_3;
			MrFrost_POSITION(575,640,42,42)
			colorBackground[] = {0.098,0.098,0.098,1};
		};

        class ZMenu_Background_Button_4 : MrFrost_RscText {
			idc = MrFrost_IDC_ZMenu_Background_Button_4;
			MrFrost_POSITION(631,640,42,42)
			colorBackground[] = {0.098,0.098,0.098,1};
		};

        class ZMenu_Background_Button_5 : MrFrost_RscText {
			idc = MrFrost_IDC_ZMenu_Background_Button_5;
			MrFrost_POSITION(687,640,42,42)
			colorBackground[] = {0.098,0.098,0.098,1};
		};

        class ZMenu_Background_Button_6 : MrFrost_RscText {
			idc = MrFrost_IDC_ZMenu_Background_Button_6;
			MrFrost_POSITION(463,696,42,42)
			colorBackground[] = {0.098,0.098,0.098,1};
		};

        class ZMenu_Background_Button_7 : MrFrost_RscText {
			idc = MrFrost_IDC_ZMenu_Background_Button_7;
			MrFrost_POSITION(519,696,42,42)
			colorBackground[] = {0.098,0.098,0.098,1};
		};

        class ZMenu_Background_Button_8 : MrFrost_RscText {
			idc = MrFrost_IDC_ZMenu_Background_Button_8;
			MrFrost_POSITION(575,696,42,42)
			colorBackground[] = {0.098,0.098,0.098,1};
		};

        class ZMenu_Background_Button_9 : MrFrost_RscText {
			idc = MrFrost_IDC_ZMenu_Background_Button_9;
			MrFrost_POSITION(631,696,42,42)
			colorBackground[] = {0.098,0.098,0.098,1};
		};

        class ZMenu_Background_Button_10 : MrFrost_RscText {
			idc = MrFrost_IDC_ZMenu_Background_Button_10;
			MrFrost_POSITION(687,696,42,42)
			colorBackground[] = {0.098,0.098,0.098,1};
		};

        class ZMenu_Background_Button_11 : MrFrost_RscText {
			idc = MrFrost_IDC_ZMenu_Background_Button_11;
			MrFrost_POSITION(463,752,42,42)
			colorBackground[] = {0.098,0.098,0.098,1};
		};

        class ZMenu_Background_Button_12 : MrFrost_RscText {
			idc = MrFrost_IDC_ZMenu_Background_Button_12;
			MrFrost_POSITION(519,752,42,42)
			colorBackground[] = {0.098,0.098,0.098,1};
		};

        class ZMenu_Background_Button_13 : MrFrost_RscText {
			idc = MrFrost_IDC_ZMenu_Background_Button_13;
			MrFrost_POSITION(575,752,42,42)
			colorBackground[] = {0.098,0.098,0.098,1};
		};

        class ZMenu_Background_Button_14 : MrFrost_RscText {
			idc = MrFrost_IDC_ZMenu_Background_Button_14;
			MrFrost_POSITION(631,752,42,42)
			colorBackground[] = {0.098,0.098,0.098,1};
		};

        class ZMenu_Background_Button_15 : MrFrost_RscText {
			idc = MrFrost_IDC_ZMenu_Background_Button_15;
			MrFrost_POSITION(687,752,42,42)
			colorBackground[] = {0.098,0.098,0.098,1};
		};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        class ZMenu_Background_Button_Close : MrFrost_RscPictureKeepAspect {
			idc = MrFrost_IDC_ZMenu_Background_Button_Close;
			MrFrost_POSITION(787,221,18,18)
			colorBackground[] = {0,0,0,0};
            text= "\A3\ui_f\data\GUI\Rsc\RscDisplayArcadeMap\icon_exit_cross_ca.paa";
		};

        class ZMenu_Background_Button_Save : MrFrost_RscPictureKeepAspect {
			idc = MrFrost_IDC_ZMenu_Background_Button_Save;
			MrFrost_POSITION(1116,221,18,18)
			colorBackground[] = {0,0,0,0};
            text= "\A3\ui_f\data\GUI\Rsc\RscDisplayArcadeMap\icon_saveas_ca.paa";
		};

        class ZMenu_Money_Bank_Icon : MrFrost_RscPictureKeepAspect {
			idc = MrFrost_IDC_ZMenu_Money_Bank_Icon;
			MrFrost_POSITION(466,322,62,62)
			colorBackground[] = {0,0,0,0};
            text = "pictures\GUI\Money_Bank.paa";
		};

        class ZMenu_Money_Cash_Icon : MrFrost_RscPictureKeepAspect {
			idc = MrFrost_IDC_ZMenu_Money_Cash_Icon;
			MrFrost_POSITION(466,398,62,62)
			colorBackground[] = {0,0,0,0};
            text = "pictures\GUI\Money_Cash.paa";
		};



///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        class ZMenu_Inventory_Title : MrFrost_RscText {
			idc = MrFrost_IDC_ZMenu_Inventory_Title;
			MrFrost_POSITION(1180,264,290,40)
			colorBackground[] = {0,0,0,0};
            colortext[] = {1,1,1,1};
            colorShadow[] = {0,0,0,0};
            style = 0x02;
            sizeex = 0.08;
            font = PuristaSemiBold;
            text = "Inventory";
            //text = "$STR_PM_cItems";
		};

        class ZMenu_Licenses_Title : MrFrost_RscText {
			idc = MrFrost_IDC_ZMenu_Licenses_Title;
			MrFrost_POSITION(815,264,290,40)
			colorBackground[] = {0,0,0,0};
            colortext[] = {1,1,1,1};
            colorShadow[] = {0,0,0,0};
            style = 0x02;
            sizeex = 0.08;
            font = PuristaSemiBold;
            text = "Licenses";
            //text = "$STR_PM_Licenses";
		};

        class ZMenu_Money_Title : MrFrost_RscText {
			idc = MrFrost_IDC_ZMenu_Money_Title;
			MrFrost_POSITION(451,264,290,40)
			colorBackground[] = {0,0,0,0};
            colortext[] = {1,1,1,1};
            colorShadow[] = {0,0,0,0};
            style = 0x02;
            sizeex = 0.08;
            font = PuristaSemiBold;
            text = "Money";
            //text = "$STR_PM_MoneyStats";
		};

        class ZMenu_Tools_Title : MrFrost_RscText {
			idc = MrFrost_IDC_ZMenu_Tools_Title;
			MrFrost_POSITION(451,574,290,40)
			colorBackground[] = {0,0,0,0};
            colortext[] = {1,1,1,1};
            colorShadow[] = {0,0,0,0};
            style = 0x02;
            sizeex = 0.08;
            font = PuristaSemiBold;
            text = "Tools";
            //text = "$STR_PM_Tools";  //Must be added
		};

        class ZMenu_Project_Text : MrFrost_RscText {
			idc = MrFrost_IDC_ZMenu_Project_Text;
			MrFrost_POSITION(887,223,147,14)
			colorBackground[] = {0,0,0,0};
            colortext[] = {1,1,1,1};
            colorShadow[] = {0,0,0,0};
            style = 0x02;
            sizeex = 0.03;
            font = PuristaSemiBold;
            text = "Mammut-Roleplay.de";
            //text = "$STR_PM_Project";  //Must be added
		};

        class ZMenu_Version_Text : MrFrost_RscText {
			idc = MrFrost_IDC_ZMenu_Version_Text;
			MrFrost_POSITION(887,238,147,14)
			colorBackground[] = {0,0,0,0};
            colortext[] = {1,1,1,1};
            colorShadow[] = {0,0,0,0};
            style = 0x02;
            sizeex = 0.03;
            font = PuristaSemiBold;
            text = "Version 1.1";
            //text = "$STR_PM_Version";  //Must be added
		};


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        class ZMenu_Money_Bank : MrFrost_RscText {
			idc = MrFrost_IDC_ZMenu_Money_Bank;
			MrFrost_POSITION(536,322,193,62)
			colorBackground[] = {0,0,0,0};
            colortext[] = {1,1,1,1};
            colorShadow[] = {0,0,0,0};
            style = 0x01;
            sizeex = 0.07;
            text= "12.345.678$";
		};

        class ZMenu_Money_Cash : MrFrost_RscText {
			idc = MrFrost_IDC_ZMenu_Money_Cash;
			MrFrost_POSITION(536,399,193,62)
			colorBackground[] = {0,0,0,0};
            colortext[] = {1,1,1,1};
            colorShadow[] = {0,0,0,0};
            style = 0x01;
            sizeex = 0.07;
            text= "12.345$";
		};

        class ZMenu_Money_Person : MrFrost_RscCombo {
			idc = MrFrost_IDC_ZMenu_Money_Person;
			MrFrost_POSITION(463,475,266,28)
			colorBackground[] = {0,0,0,0};
            colortext[] = {1,1,1,1};
            colorShadow[] = {0,0,0,0};
            style = 512;
            sizeEx = 0.035;
		};

        class ZMenu_Money_Value : MrFrost_RscEdit {
			idc = MrFrost_IDC_ZMenu_Money_Value;
			MrFrost_POSITION(463,518,170,28)
			colorBackground[] = {0,0,0,0};
            colortext[] = {1,1,1,1};
            colorShadow[] = {0,0,0,0};
            style = 512;
            sizeex = 0.048;
            text= "1";
		};

        class ZMenu_Inventory_Person : MrFrost_RscCombo {
			idc = MrFrost_IDC_ZMenu_Inventory_Person;
			MrFrost_POSITION(1190,700,271,28)
			colorBackground[] = {0,0,0,0};
            colortext[] = {1,1,1,1};
            colorShadow[] = {0,0,0,0};
            style = 512;
            sizeEx = 0.035;
		};

        class ZMenu_Inventory_Value : MrFrost_RscEdit {
			idc = item_edit;
			MrFrost_POSITION(1190,740,271,28)
			colorBackground[] = {0,0,0,0};
            colortext[] = {1,1,1,1};
            colorShadow[] = {0,0,0,0};
            style = 512;
            sizeex = 0.048;
            text= "1";
		};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        class ZMenu_Inventory_List : MrFrost_RscListBox {
			idc = 1234567;//item_list;
			MrFrost_POSITION(1180,310,290,348)
			colorBackground[] = {0,0,0,0};
            colortext[] = {1,1,1,1};
            colorShadow[] = {0,0,0,0};
            sizeEx = 0.035;
		};

        class ZMenu_Licenses_List : MrFrost_RscControlsGroup {
			idc = MrFrost_IDC_ZMenu_Licenses_List;
			MrFrost_POSITION(815,308,290,507)
			colorBackground[] = {0,0,0,0};

            class Controls {
                class ZMenu_Licenses_List_Text: MrFrost_RscStructuredText {
                    idc = MrFrost_IDC_ZMenu_Licenses_List_Text;
                    sizeEx = 0.020;
                    text = "1234";
                    colorBackground[] = {0,0,0,0};
                    colorShadow[] = {0,0,0,0};
                    x = 0;
                    y = 0;
                    w = 0.366;
                    h = 0.853;
                };
            };
		};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        class ZMenu_Inventory_Button_Give : MrFrost_RscButton {
			idc = MrFrost_IDC_ZMenu_Inventory_Button_Give;
			MrFrost_POSITION(1284,780,83,28)
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
            text= "Give";
            //text = "$STR_Global_Give";
            onButtonClick = "[] call life_fnc_giveItem;";
		};

        class ZMenu_Inventory_Button_Use : MrFrost_RscButton {
			idc = MrFrost_IDC_ZMenu_Inventory_Button_Use;
			MrFrost_POSITION(1190,780,82,28)
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
            text= "Use";
            //text = "$STR_Global_Use";
            onButtonClick = "[] call life_fnc_useItem;";
		};

        class ZMenu_Inventory_Button_Delete : MrFrost_RscButton {
			idc = MrFrost_IDC_ZMenu_Inventory_Button_Delete;
			MrFrost_POSITION(1379,780,82,28)
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
            text= "Delete";
            //text = "$STR_Global_Remove";
            onButtonClick = "[] call life_fnc_removeItem;";
		};

        class ZMenu_Money_Button_Give : MrFrost_RscButton {
			idc = MrFrost_IDC_ZMenu_Money_Button_Give;
			MrFrost_POSITION(647,518,82,28)
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
            text= "Give";
            //text = "$STR_Global_Give";
            onButtonClick = "[] call life_fnc_giveMoney";
		};

////////////////////////////////////////////////

        /*class ZMenu_Button_Settings : MrFrost_RscButton {
			idc = MrFrost_IDC_ZMenu_Button_Settings;
			MrFrost_POSITION(463,640,42,42)
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
            text= "";
            onButtonClick = "[] call life_fnc_settingsMenu;";
		}; */

        class ZMenu_Button_Settings : MrFrost_MammutRP_RscButtonMenu {
			idc = MrFrost_IDC_ZMenu_Button_Settings;
            MrFrost_POSITION(463,640,42,42)
            text = "";
            textureNoShortcut = "pictures\GUI\ico_settings.paa";
            onButtonClick = "closeDialog 0; [] call life_fnc_settingsMenu;";
		};

        class ZMenu_Button_Gang : MrFrost_MammutRP_RscButtonMenu {
			idc = MrFrost_IDC_ZMenu_Button_Gang;
            MrFrost_POSITION(575,752,42,42)
            text= "8";
            textureNoShortcut = "pictures\GUI\ico_gang.paa";
            onButtonClick = "if (isNil ""life_action_gangInUse"") then {if (isNil {(group player) getVariable ""gang_owner""}) then {createDialog ""Life_Create_Gang_Diag"";} else {[] spawn life_fnc_gangMenu;};};";
		};

        class ZMenu_Button_Wanted : MrFrost_MammutRP_RscButtonMenu {
			idc = MrFrost_IDC_ZMenu_Button_Wanted;
			MrFrost_POSITION(687,696,42,42)
            text= "";
            textureNoShortcut = "pictures\GUI\ico_wanted.paa";
            onButtonClick = "[] call life_fnc_wantedMenu";
		};

        class ZMenu_Button_Keys : MrFrost_MammutRP_RscButtonMenu {
			idc = MrFrost_IDC_ZMenu_Button_Keys;
			MrFrost_POSITION(519,696,42,42)
            text= "";
            textureNoShortcut = "pictures\GUI\ico_keys.paa";
            onButtonClick = "createDialog ""Life_key_management"";";
		};

        class ZMenu_Button_Cellphone : MrFrost_MammutRP_RscButtonMenu {
			idc = MrFrost_IDC_ZMenu_Button_Cellphone;
			MrFrost_POSITION(519,640,42,42)
            text= "";
            textureNoShortcut = "pictures\GUI\ico_sms.paa";
            onButtonClick = "createDialog ""Life_cell_phone"";";
            class ShortcutPos
            {
                left = 0.006;
                top = 0.005;
                w = 0.04;
                h = 0.052;
            };
		};

        class ZMenu_Button_Adminmenu : MrFrost_MammutRP_RscButtonMenu {
			idc = MrFrost_IDC_ZMenu_Button_Adminmenu;
			MrFrost_POSITION(687,752,42,42)
            text= "";
            textureNoShortcut = "pictures\GUI\ico_admin.paa";
            onButtonClick = "closeDialog 0; createDialog ""life_admin_menu"";";
		};

        class ZMenu_Button_DynMarket : MrFrost_MammutRP_RscButtonMenu {
			idc = MrFrost_IDC_ZMenu_Button_DynMarket;
			MrFrost_POSITION(463,752,42,42)
            text= "";
            textureNoShortcut = "pictures\GUI\ico_dynmarket.paa";
            onButtonClick = "closeDialog 0;";
		};

        class ZMenu_Button_Achievement : MrFrost_MammutRP_RscButtonMenu {
			idc = MrFrost_IDC_ZMenu_Button_Achievement;
			MrFrost_POSITION(519,752,42,42)
            text= "";
            textureNoShortcut = "pictures\GUI\ico_xp.paa";
            onButtonClick = "closeDialog 0;";
		};

        class ZMenu_Button_Info : MrFrost_MammutRP_RscButtonMenu {
			idc = MrFrost_IDC_ZMenu_Button_Info;
			MrFrost_POSITION(463,696,42,42)
            text= "";
            textureNoShortcut = "pictures\GUI\ico_info.paa";
            onButtonClick = "closeDialog 0;";
		};

        class ZMenu_Button_Dispatch : MrFrost_MammutRP_RscButtonMenu {
			idc = MrFrost_IDC_ZMenu_Button_Dispatch;
			MrFrost_POSITION(687,640,42,42)
            text= "";
            textureNoShortcut = "pictures\GUI\ico_dispatch.paa";
            onButtonClick = "closeDialog 0;";
		};

        class ZMenu_Button_3 : MrFrost_MammutRP_RscButtonMenu {
			idc = MrFrost_IDC_ZMenu_Button_3;
			MrFrost_POSITION(575,640,42,42)
            text= "";
		};

        class ZMenu_Button_4 : MrFrost_MammutRP_RscButtonMenu {
			idc = MrFrost_IDC_ZMenu_Button_4;
			MrFrost_POSITION(631,640,42,42)
            text= "";
		};

        class ZMenu_Button_8 : MrFrost_MammutRP_RscButtonMenu {
			idc = MrFrost_IDC_ZMenu_Button_8;
			MrFrost_POSITION(575,696,42,42)
            text= "";
		};

        class ZMenu_Button_9 : MrFrost_MammutRP_RscButtonMenu {
			idc = MrFrost_IDC_ZMenu_Button_9;
			MrFrost_POSITION(631,696,42,42)
            text= "";
		};

        class ZMenu_Button_14 : MrFrost_MammutRP_RscButtonMenu {
			idc = MrFrost_IDC_ZMenu_Button_14;
			MrFrost_POSITION(631,752,42,42)
            text= "";
		};

        class ZMenu_Button_Report : MrFrost_RscButton {
			idc = MrFrost_IDC_ZMenu_Button_Report;
			MrFrost_POSITION(815,829,290,28)
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
            text= "Report";
            onButtonClick = "closeDialog 0;"; //Report script needed
		};

        class ZMenu_Button_Close : MrFrost_RscButton {
			idc = MrFrost_IDC_ZMenu_Button_Close;
			MrFrost_POSITION(787,221,18,18)
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

        class ZMenu_Button_Save : MrFrost_RscButton {
			idc = MrFrost_IDC_ZMenu_Button_Save;
			MrFrost_POSITION(1116,221,18,18)
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
            onButtonClick = "[] call SOCK_fnc_syncData;";
		};
    };
};
