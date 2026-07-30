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
 * vehicleShop3D.hpp - Vehicle shop with 3D preview
 *
 * Part of    : Altis Life UI Pack (MrFrost, 2021) - archived, unmaintained.
 * Root class : Life_Vehicle_Shop_v2_3D
 * IDD        : MrFrost_IDD_Life_Vehicle_Shop_v2_3D = 2300
 * Opened by  : createDialog "Life_Vehicle_Shop_v2_3D";
 * Requires   : dialog/MrFrost_defines.hpp (MrFrost_POSITION and the
 *              MrFrost_Rsc* base classes) and dialog/common.hpp.
 *
 * Positions are authored against a 1920x1080 reference canvas.
 * MrFrost_POSITION(X,Y,W,H) rewrites those pixel values into
 * safezone-relative coordinates at preprocess time, so the numbers
 * below can be read directly as pixels on a 1080p screen.
 *
 * Note       : Drop-in replacement for the stock veh_shop.hpp /
 *              vehicleShop.hpp; all three declare IDD 2300, so pick exactly
 *              one.
 *
 * Full IDD/IDC table : docs/dialog-reference.md
 * Before production  : docs/known-issues.md
 * ------------------------------------------------------------------------- */
/* IDD/IDCs Macros */
//VehicleShop
#define MrFrost_IDD_Life_Vehicle_Shop_v2_3D 2300
//Main Background
#define MrFrost_IDC_VehicleShop_MainBackground -1
#define MrFrost_IDC_VehicleShop_Bar_Bottom -1
#define MrFrost_IDC_VehicleShop_Bar_Top -1
#define MrFrost_IDC_VehicleShop_Picture_Close -1
//Backgrounds
#define MrFrost_IDC_VehicleShop_Background_Shop -1
#define MrFrost_IDC_VehicleShop_Bar_Shop -1
#define MrFrost_IDC_VehicleShop_Background_Elements -1
#define MrFrost_IDC_VehicleShop_Bar_Elements -1
#define MrFrost_IDC_VehicleShop_Background_Info -1
#define MrFrost_IDC_VehicleShop_Bar_Info -1
//Background Elements
#define MrFrost_IDC_VehicleShop_Background_Elements_Color -1
//Buttons
#define MrFrost_IDC_VehicleShop_Button_Elements_Rent -1
#define MrFrost_IDC_VehicleShop_Button_Elements_Buy 2309
//Elements
#define MrFrost_IDC_VehicleShop_Combo_Elements_Color 2304
#define MrFrost_IDC_VehicleShop_List_Shop 2302
//Title and Text
#define MrFrost_IDC_VehicleShop_Text_Info 2303
#define MrFrost_IDC_VehicleShop_Title_Shop 2301
//Main Buttons
#define MrFrost_IDC_VehicleShop_Button_Close -1



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
class Life_Vehicle_Shop_v2_3D {
	idd = MrFrost_IDD_Life_Vehicle_Shop_v2_3D;
    name = "life_vehicle_shop";
    movingEnable = 0;
    enableSimulation = 1;
    onLoad = "call life_fnc_3dPreviewInit;";
    onUnLoad = "call life_fnc_3dPreviewExit;";


	class Controls {

        /*class Picture_Preview : MrFrost_RscPictureKeepAspect {
            idc = -1;
            MrFrost_POSITION(0,0,1920,1080)
            text = "pictures\GUI\PreviewBackground.jpg";
        };*/

///////////////////////////////////////////////////////////////////////////////

		class VehicleShop_MainBackground : MrFrost_RscText {
			idc = MrFrost_IDC_VehicleShop_MainBackground;
			MrFrost_POSITION(30,249,364,582)
			colorBackground[] = {0.09412,0.09412,0.09412,1};
		};

		class VehicleShop_Bar_Bottom : MrFrost_RscText {
			idc = MrFrost_IDC_VehicleShop_Bar_Bottom;
			MrFrost_POSITION(30,831,364,7)
			colorBackground[] = {0.6902,0,0,1};
		};

		class VehicleShop_Bar_Top : MrFrost_RscText {
			idc = MrFrost_IDC_VehicleShop_Bar_Top;
			MrFrost_POSITION(30,242,364,7)
			colorBackground[] = {0.6902,0,0,1};
		};

		class VehicleShop_Picture_Close : MrFrost_RscPictureKeepAspect {
			idc = MrFrost_IDC_VehicleShop_Picture_Close;
			MrFrost_POSITION(35,254,18,18)
			colorBackground[] = {0,0,0,0};
            text= "\A3\ui_f\data\GUI\Rsc\RscDisplayArcadeMap\icon_exit_cross_ca.paa";
		};

///////////////////////////////////////////////////////////////////////////////

		class VehicleShop_Background_Shop : MrFrost_RscText {
			idc = MrFrost_IDC_VehicleShop_Background_Shop;
			MrFrost_POSITION(67,308,290,386)
            colorBackground[] = {0,0,0,0.31};
		};

		class VehicleShop_Bar_Shop : MrFrost_RscText {
			idc = MrFrost_IDC_VehicleShop_Bar_Shop;
			MrFrost_POSITION(67,302,290,6)
			colorBackground[] = {0.6902,0,0,1};
		};

		class VehicleShop_Background_Elements : MrFrost_RscText {
			idc = MrFrost_IDC_VehicleShop_Background_Elements;
			MrFrost_POSITION(67,715,290,101)
            colorBackground[] = {0,0,0,0.31};
		};

		class VehicleShop_Bar_Elements : MrFrost_RscText {
			idc = MrFrost_IDC_VehicleShop_Bar_Elements;
			MrFrost_POSITION(67,709,290,6)
			colorBackground[] = {0.6902,0,0,1};
		};

		class VehicleShop_Background_Info : MrFrost_RscText {
			idc = MrFrost_IDC_VehicleShop_Background_Info;
			MrFrost_POSITION(1630,308,290,290)
			colorBackground[] = {0.0549,0.0549,0.0549,0.8};
		};

		class VehicleShop_Bar_Info : MrFrost_RscText {
			idc = MrFrost_IDC_VehicleShop_Bar_Info;
			MrFrost_POSITION(1630,302,290,6)
			colorBackground[] = {0.6902,0,0,1};
		};

///////////////////////////////////////////////////////////////////////////////

		class VehicleShop_Background_Elements_Color : MrFrost_RscText {
			idc = MrFrost_IDC_VehicleShop_Background_Elements_Color;
			MrFrost_POSITION(82,730,260,28)
			colorBackground[] = {0.09804,0.09804,0.09804,1};
		};

///////////////////////////////////////////////////////////////////////////////

		class VehicleShop_Combo_Elements_Color : MrFrost_RscCombo {
			idc = MrFrost_IDC_VehicleShop_Combo_Elements_Color;
			MrFrost_POSITION(82,730,260,28)
			colorBackground[] = {0,0,0,0};
            colortext[] = {1,1,1,1};
            colorShadow[] = {0,0,0,0};
            style = 512;
            sizeEx = 0.035;
			onLBSelChanged = "call life_fnc_vehicleColor3DRefresh;";
		};

		class VehicleShop_List_Shop : MrFrost_RscListBox {
			idc = MrFrost_IDC_VehicleShop_List_Shop;
			MrFrost_POSITION(67,310,290,381)
			colorBackground[] = {0,0,0,0};
            colortext[] = {1,1,1,1};
            colorShadow[] = {0,0,0,0};
            sizeEx = 0.035;
			onLBSelChanged = "_this call life_fnc_vehicleShopLBChange";
		};

///////////////////////////////////////////////////////////////////////////////

		class VehicleShop_Text_Info : MrFrost_RscStructuredText {
			idc = MrFrost_IDC_VehicleShop_Text_Info;
			MrFrost_POSITION(1630,308,290,290)
            sizeEx = 0.020;
            text = "Very cool test specs";
            colorBackground[] = {0,0,0,0};
            colorShadow[] = {0,0,0,0};
		};

		class VehicleShop_Title_Shop : MrFrost_RscText {
			idc = MrFrost_IDC_VehicleShop_Title_Shop;
			MrFrost_POSITION(67,264,290,40)
			colorBackground[] = {0,0,0,0};
            colortext[] = {1,1,1,1};
            colorShadow[] = {0,0,0,0};
            style = 0x02;
            sizeex = 0.08;
            font = PuristaSemiBold;
            text = "Vehicle Store";
		};

///////////////////////////////////////////////////////////////////////////////

		class VehicleShop_Button_Elements_Rent : MrFrost_RscButton {
			idc = MrFrost_IDC_VehicleShop_Button_Elements_Rent;
			MrFrost_POSITION(82,773,122,28)
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
            text= "Rent";
            //text = "$STR_Global_RentVeh";
			onButtonClick = "[false] spawn life_fnc_vehicleShopBuy;";
		};

		class VehicleShop_Button_Elements_Buy : MrFrost_RscButton {
			idc = MrFrost_IDC_VehicleShop_Button_Elements_Buy;
			MrFrost_POSITION(220,773,122,28)
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
            text= "Buy";
            //text = "$STR_Global_Buy";
			onButtonClick = "[true] spawn life_fnc_vehicleShopBuy;";
		};

		class VehicleShop_Button_Close : MrFrost_RscButton {
			idc = MrFrost_IDC_VehicleShop_Button_Close;
			MrFrost_POSITION(35,254,18,18)
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
