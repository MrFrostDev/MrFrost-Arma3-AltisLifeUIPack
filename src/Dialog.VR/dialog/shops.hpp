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
 * shops.hpp - Weapon shop
 *
 * Part of    : Altis Life UI Pack (MrFrost, 2021) - archived, unmaintained.
 * Root class : life_weapon_shop
 * IDD        : MrFrost_IDD_ItemShop = 38400
 * Opened by  : createDialog "life_weapon_shop";
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
//ItemShop
#define MrFrost_IDD_ItemShop 38400
//Main Background
#define MrFrost_IDC_ItemShop_MainBackground -1
#define MrFrost_IDC_ItemShop_Bar_Bottom -1
#define MrFrost_IDC_ItemShop_Bar_Top -1
//Background Shop
#define MrFrost_IDC_ItemShop_Background_Shop -1
#define MrFrost_IDC_ItemShop_Bar_Shop -1
//Background Elements
#define MrFrost_IDC_ItemShop_Background_Elements -1
#define MrFrost_IDC_ItemShop_Bar_Elements -1
#define MrFrost_IDC_ItemShop_Background_Elements_Filter -1
//Ttle / Text
#define MrFrost_IDC_ItemShop_Title_Shop 38401
#define MrFrost_IDC_ItemShop_Text_Price 38404
//Elements
#define MrFrost_IDC_ItemShop_List_Shop 38403
#define MrFrost_IDC_ItemShop_Combo_Elements_Filter 38402
//Buttons
#define MrFrost_IDC_ItemShop_Button_Elements_Mag 38406
#define MrFrost_IDC_ItemShop_Button_Elements_Acc 38407
#define MrFrost_IDC_ItemShop_Button_Elements_BuySell 38405
//Main Buttons
#define MrFrost_IDC_ItemShop_Button_Close -1

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
class life_weapon_shop {
    idd = MrFrost_IDD_ItemShop;
    movingEnable = 0;
    enableSimulation = 1;

    class Controls {

///////////////////////////////////////////////////////////////////////////////

		class ItemShop_MainBackground : MrFrost_RscText {
			idc = MrFrost_IDC_ItemShop_MainBackground;
			MrFrost_POSITION(765,260,364,582)
			colorBackground[] = {0.098,0.098,0.098,1};
		};

		class ItemShop_Bar_Bottom : MrFrost_RscText {
			idc = MrFrost_IDC_ItemShop_Bar_Bottom;
			MrFrost_POSITION(765,842,364,7)
			colorBackground[] = {0.6902,0,0,1};
		};

		class ItemShop_Bar_Top : MrFrost_RscText {
			idc = MrFrost_IDC_ItemShop_Bar_Top;
			MrFrost_POSITION(765,253,364,7)
			colorBackground[] = {0.6902,0,0,1};
		};

		class ItemShop_Background_Button_Close : MrFrost_RscPictureKeepAspect {
			idc = MrFrost_IDC_ItemShop_Background_Button_Close;
			MrFrost_POSITION(770,265,18,18)
			colorBackground[] = {0,0,0,0};
            text= "\A3\ui_f\data\GUI\Rsc\RscDisplayArcadeMap\icon_exit_cross_ca.paa";
		};

///////////////////////////////////////////////////////////////////////////////

		class ItemShop_Background_Shop : MrFrost_RscText {
			idc = MrFrost_IDC_ItemShop_Background_Shop;
			MrFrost_POSITION(802,319,290,300)
            colorBackground[] = {0,0,0,0.31};
		};

		class ItemShop_Bar_Shop : MrFrost_RscText {
			idc = MrFrost_IDC_ItemShop_Bar_Shop;
			MrFrost_POSITION(802,313,290,6)
			colorBackground[] = {0.6902,0,0,1};
		};

///////////////////////////////////////////////////////////////////////////////

		class ItemShop_Background_Elements : MrFrost_RscText {
			idc = MrFrost_IDC_ItemShop_Background_Elements;
			MrFrost_POSITION(802,640,290,187)
            colorBackground[] = {0,0,0,0.31};
		};

		class ItemShop_Bar_Elements : MrFrost_RscText {
			idc = MrFrost_IDC_ItemShop_Bar_Elements;
			MrFrost_POSITION(802,634,290,6)
			colorBackground[] = {0.6902,0,0,1};
		};

		class ItemShop_Background_Elements_Filter : MrFrost_RscText {
			idc = MrFrost_IDC_ItemShop_Background_Elements_Filter;
			MrFrost_POSITION(817,655,260,28)
			colorBackground[] = {0.098,0.098,0.098,1};
		};

///////////////////////////////////////////////////////////////////////////////

		class ItemShop_Title_Shop : MrFrost_RscText {
			idc = MrFrost_IDC_ItemShop_Title_Shop;
			MrFrost_POSITION(802,275,290,40)
			colorBackground[] = {0,0,0,0};
            colortext[] = {1,1,1,1};
            colorShadow[] = {0,0,0,0};
            style = 0x02;
            sizeex = 0.08;
            font = PuristaSemiBold;
            text = "General Store";
		};

		class ItemShop_Text_Price : MrFrost_RscStructuredText {
			idc = MrFrost_IDC_ItemShop_Text_Price;
			MrFrost_POSITION(817,741,260,28)
            font = PuristaSemiBold;
            sizeEx = 0.035;
            text = Price: <t color='#8cff9b'>$1234567890</t>;
		};

///////////////////////////////////////////////////////////////////////////////

		class ItemShop_List_Shop : MrFrost_RscListBox {
			idc = MrFrost_IDC_ItemShop_List_Shop;
			MrFrost_POSITION(802,321,290,295)
			colorBackground[] = {0,0,0,0};
            colortext[] = {1,1,1,1};
            colorShadow[] = {0,0,0,0};
            sizeEx = 0.035;
			onLBSelChanged = "_this call life_fnc_weaponShopSelection";
		};

		class ItemShop_Combo_Elements_Filter : MrFrost_RscCombo {
			idc = MrFrost_IDC_ItemShop_Combo_Elements_Filter;
			MrFrost_POSITION(817,655,260,28)
			colorBackground[] = {0,0,0,0};
            colortext[] = {1,1,1,1};
            colorShadow[] = {0,0,0,0};
            style = 512;
            sizeEx = 0.035;
			onLBSelChanged = "_this call life_fnc_weaponShopFilter";
		};

///////////////////////////////////////////////////////////////////////////////

		class ItemShop_Button_Elements_Mag : MrFrost_RscButton {
			idc = MrFrost_IDC_ItemShop_Button_Elements_Mag;
			MrFrost_POSITION(817,698,122,28)
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
            text= "Magazines";
            //text = "$STR_Global_Mags";
            onButtonClick = "_this call life_fnc_weaponShopMags; _this call life_fnc_weaponShopFilter";
		};

		class ItemShop_Button_Elements_Acc : MrFrost_RscButton {
			idc = MrFrost_IDC_ItemShop_Button_Elements_Acc;
			MrFrost_POSITION(955,698,122,28)
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
            text= "Accessories";
            //text = "$STR_Global_Accs";
            onButtonClick = "_this call life_fnc_weaponShopAccs; _this call life_fnc_weaponShopFilter";
		};

		class ItemShop_Button_Elements_BuySell : MrFrost_RscButton {
			idc = MrFrost_IDC_ItemShop_Button_Elements_Buy;
			MrFrost_POSITION(817,784,260,28)
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
            onButtonClick = "[] spawn life_fnc_weaponShopBuySell; true";
		};

///////////////////////////////////////////////////////////////////////////////

		class ItemShop_Button_Close : MrFrost_RscButton {
			idc = MrFrost_IDC_ItemShop_Button_Close;
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
