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
 * chop_shop.hpp - Chop shop
 *
 * Part of    : Altis Life UI Pack (MrFrost, 2021) - archived, unmaintained.
 * Root class : Chop_Shop
 * IDD        : MrFrost_IDD_ChopShop = 39400
 * Opened by  : createDialog "Chop_Shop";
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
#define MrFrost_IDD_ChopShop 39400
//Main Background
#define MrFrost_IDC_ChopShop_MainBackground -1
#define MrFrost_IDC_ChopShop_Bar_Bottom -1
#define MrFrost_IDC_ChopShop_Bar_Top -1
#define MrFrost_IDC_ChopShop_Button_Close_Image -1
//Parts Background
#define MrFrost_IDC_ChopShop_Background_Vehicles -1
#define MrFrost_IDC_ChopShop_Background_Buttons -1
#define MrFrost_IDC_ChopShop_Bar_Vehicles -1
#define MrFrost_IDC_ChopShop_Bar_Buttons -1
//Elements
#define MrFrost_IDC_ChopShop_Vehicles_List 39402
//Titles
#define MrFrost_IDC_ChopShop_Title -1
#define MrFrost_IDC_ChopShop_Text_Price 39401
//Buttons
#define MrFrost_IDC_ChopShop_Button_Sell -1
//Main Buttons
#define MrFrost_IDC_ChopShop_Button_Close -1

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
class Chop_Shop {
    idd = MrFrost_IDD_ChopShop;
    name= "life_ChopShop_menu";
    movingEnable = 0;
    enableSimulation = 1;

    class Controls {

        class Picture_Preview : MrFrost_RscPictureKeepAspect {
            idc = -1;
            MrFrost_POSITION(0,0,1920,1080)
            text = "pictures\GUI\PreviewBackground.jpg";
        };

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        class ChopShop_MainBackground : MrFrost_RscText {
			idc = MrFrost_IDC_ChopShop_MainBackground;
			MrFrost_POSITION(765,260,364,582)
			colorBackground[] = {0.094,0.094,0.094,1};
		};

        class ChopShop_Bar_Bottom : MrFrost_RscText {
			idc = MrFrost_IDC_ChopShop_Bar_Bottom;
			MrFrost_POSITION(765,842,364,7)
			colorBackground[] = {0.69,0,0,1};
		};

        class ChopShop_Bar_Top : MrFrost_RscText {
			idc = MrFrost_IDC_ChopShop_Bar_Top;
			MrFrost_POSITION(765,253,364,7)
			colorBackground[] = {0.69,0,0,1};
		};

////////////////////////////////////////////////////////////////////////////////

        class ChopShop_Background_Vehicles : MrFrost_RscText {
			idc = MrFrost_IDC_ChopShop_Background_Vehicles;
			MrFrost_POSITION(802,319,290,383)
			colorBackground[] = {0,0,0,0.31};
		};

        class ChopShop_Background_Buttons : MrFrost_RscText {
			idc = MrFrost_IDC_ChopShop_Background_Buttons;
			MrFrost_POSITION(802,723,290,101)
			colorBackground[] = {0,0,0,0.31};
		};

        class ChopShop_Bar_Vehicles : MrFrost_RscText {
			idc = MrFrost_IDC_ChopShop_Bar_Vehicles;
			MrFrost_POSITION(802,313,290,6)
			colorBackground[] = {0.69,0,0,1};
		};

        class ChopShop_Bar_Buttons : MrFrost_RscText {
			idc = MrFrost_IDC_ChopShop_Bar_Buttons;
			MrFrost_POSITION(802,717,290,6)
			colorBackground[] = {0.69,0,0,1};
		};

////////////////////////////////////////////////////////////////////////////////

        class ChopShop_Title : MrFrost_RscText {
			idc = MrFrost_IDC_ChopShop_Title;
			MrFrost_POSITION(802,275,290,40)
			colorBackground[] = {0,0,0,0};
            colortext[] = {1,1,1,1};
            colorShadow[] = {0,0,0,0};
            style = 0x02;
            sizeex = 0.08;
            font = PuristaSemiBold;
            text = "ChopShop";
		};

        class ChopShop_Text_Price : MrFrost_RscStructuredText {
			idc = MrFrost_IDC_ChopShop_Text_Price;
			MrFrost_POSITION(817,738,260,28)
			font = PuristaSemiBold;
            sizeEx = 0.035;
            text = Price: <t color='#8cff9b'>$1234567890</t>;
		};

////////////////////////////////////////////////////////////////////////////////

        class ATM_Button_Close_Image : MrFrost_RscPictureKeepAspect {
			idc = MrFrost_IDC_ATM_Button_Close_Image;
			MrFrost_POSITION(770,265,18,18)
			colorBackground[] = {0,0,0,0};
            text= "\A3\ui_f\data\GUI\Rsc\RscDisplayArcadeMap\icon_exit_cross_ca.paa";
		};

////////////////////////////////////////////////////////////////////////////////

        class ChopShop_Vehicles_List : Life_RscListBox {
			idc = MrFrost_IDC_ChopShop_Vehicles_List;
			MrFrost_POSITION(802,321,290,378)
			colorBackground[] = {0,0,0,0};
            colortext[] = {1,1,1,1};
            colorShadow[] = {0,0,0,0};
            sizeEx = 0.035;
            onLBSelChanged = "_this call life_fnc_chopShopSelection";
		};

////////////////////////////////////////////////////////////////////////////////

        class ChopShop_Button_Sell : MrFrost_RscButton {
			idc = MrFrost_IDC_ChopShop_Button_Sell;
			MrFrost_POSITION(817,781,260,28)
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
            //text = "$STR_Global_Sell";
            text= "Sell";
            onButtonclick = "[] call life_fnc_chopShopSell;";
		};

        class ChopShop_Button_Close : MrFrost_RscButton {
			idc = MrFrost_IDC_ChopShop_Button_Close;
			MrFrost_POSITION(770,265,18,18)
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
