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
 * clothing.hpp - Clothing store
 *
 * Part of    : Altis Life UI Pack (MrFrost, 2021) - archived, unmaintained.
 * Root class : Life_Clothing
 * IDD        : MrFrost_IDD_Life_Clothing = 3100
 * Opened by  : createDialog "Life_Clothing";
 * Requires   : dialog/MrFrost_defines.hpp (MrFrost_POSITION and the
 *              MrFrost_Rsc* base classes) and dialog/common.hpp.
 *
 * Positions are authored against a 1920x1080 reference canvas.
 * MrFrost_POSITION(X,Y,W,H) rewrites those pixel values into
 * safezone-relative coordinates at preprocess time, so the numbers
 * below can be read directly as pixels on a 1080p screen.
 *
 * Note       : this dialog's onLoad is commented out. It would have run
 *              core\client\keychain\init.sqf - a copy/paste leftover from the
 *              key chain dialog. Disabled as shipped; left exactly as found.
 *              See known-issues.md.
 *
 * Full IDD/IDC table : docs/dialog-reference.md
 * Before production  : docs/known-issues.md
 * ------------------------------------------------------------------------- */
/* IDD/IDCs Macros */
//Clothing Shop
#define MrFrost_IDD_Life_Clothing 3100
//Main Background
#define MrFrost_IDC_ClothingShop_MainBackground -1
#define MrFrost_IDC_ClothingShop_Bar_Bottom -1
#define MrFrost_IDC_ClothingShop_Bar_Top -1
#define MrFrost_IDC_ClothingShop_MainBackground_Slider -1
#define MrFrost_IDC_ClothingShop_Bar_Top_Slider -1
#define MrFrost_IDC_ClothingShop_Picture_Close -1
//Background Element
#define MrFrost_IDC_ClothingShop_Background_Shop -1
#define MrFrost_IDC_ClothingShop_Bar_Shop -1
#define MrFrost_IDC_ClothingShop_Background_Elements -1
#define MrFrost_IDC_ClothingShop_Bar_Elements -1
#define MrFrost_IDC_ClothingShop_Background_Elements_Slider -1
#define MrFrost_IDC_ClothingShop_Background_Elements_Filter -1
//Slider Elements
#define MrFrost_IDC_ClothingShop_Slider_View 3107
//Shop Elements
#define MrFrost_IDC_ClothingShop_List_Shop 3101
#define MrFrost_IDC_ClothingShop_Combo_Elements_Filter 3105
//Title and Text
#define MrFrost_IDC_ClothingShop_Title_Shop 3103
#define MrFrost_IDC_ClothingShop_Text_Price 3102
#define MrFrost_IDC_ClothingShop_Text_Price_Total 3106
//Buttons
#define MrFrost_IDC_ClothingShop_Button_Elements_Buy -1
#define MrFrost_IDC_ClothingShop_Button_Close -1
//Test
#define MrFrost_IDC_Test_TestObject -1


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
class Life_Clothing {
	idd = MrFrost_IDD_Life_Clothing;
    name= "Life_Clothing";
    movingEnable = 1;
    enableSimulation = 1;
    //onLoad = "[] execVM 'core\client\keychain\init.sqf'";

	class Controls {

        /*class Picture_Preview : MrFrost_RscPictureKeepAspect {
            idc = -1;
            MrFrost_POSITION(0,0,1920,1080)
            text = "pictures\GUI\PreviewBackground.jpg";
        };*/

///////////////////////////////////////////////////////////////////////////////

		class ClothingShop_MainBackground : MrFrost_RscText {
			idc = MrFrost_IDC_ClothingShop_MainBackground;
			MrFrost_POSITION(30,249,364,582)
			colorBackground[] = {0.09412,0.09412,0.09412,1};
		};

		class ClothingShop_Bar_Bottom : MrFrost_RscText {
			idc = MrFrost_IDC_ClothingShop_Bar_Bottom;
			MrFrost_POSITION(30,831,364,7)
			colorBackground[] = {0.6902,0,0,1};
		};

		class ClothingShop_Bar_Top : MrFrost_RscText {
			idc = MrFrost_IDC_ClothingShop_Bar_Top;
			MrFrost_POSITION(30,242,364,7)
			colorBackground[] = {0.6902,0,0,1};
		};

		class ClothingShop_Picture_Close : MrFrost_RscPictureKeepAspect {
			idc = MrFrost_IDC_ClothingShop_Picture_Close;
			MrFrost_POSITION(35,254,18,18)
			colorBackground[] = {0,0,0,0};
            text= "\A3\ui_f\data\GUI\Rsc\RscDisplayArcadeMap\icon_exit_cross_ca.paa";
		};

///////////////////////////////////////////////////////////////////////////////

		class ClothingShop_MainBackground_Slider : MrFrost_RscText {
			idc = MrFrost_IDC_ClothingShop_MainBackground_Slider;
			MrFrost_POSITION(461,981,998,58)
			colorBackground[] = {0.0549,0.0549,0.0549,0.8};
		};

		class ClothingShop_Bar_Top_Slider : MrFrost_RscText {
			idc = MrFrost_IDC_ClothingShop_Bar_Top_Slider;
			MrFrost_POSITION(461,974,998,7)
			colorBackground[] = {0.6902,0,0,1};
		};

///////////////////////////////////////////////////////////////////////////////

		class ClothingShop_Background_Shop : MrFrost_RscText {
			idc = MrFrost_IDC_ClothingShop_Background_Shop;
			MrFrost_POSITION(67,308,290,343)
            colorBackground[] = {0,0,0,0.31};
		};

		class ClothingShop_Bar_Shop : MrFrost_RscText {
			idc = MrFrost_IDC_ClothingShop_Bar_Shop;
			MrFrost_POSITION(67,302,290,6)
			colorBackground[] = {0.6902,0,0,1};
		};

		class ClothingShop_Background_Elements : MrFrost_RscText {
			idc = MrFrost_IDC_ClothingShop_Background_Elements;
			MrFrost_POSITION(67,672,290,144)
            colorBackground[] = {0,0,0,0.31};
		};

		class ClothingShop_Bar_Elements : MrFrost_RscText {
			idc = MrFrost_IDC_ClothingShop_Bar_Elements;
			MrFrost_POSITION(67,666,290,6)
			colorBackground[] = {0.6902,0,0,1};
		};

		class ClothingShop_Background_Elements_Slider : MrFrost_RscText {
			idc = MrFrost_IDC_ClothingShop_Background_Elements_Slider;
			MrFrost_POSITION(476,996,968,28)
			colorBackground[] = {0.09804,0.09804,0.09804,1};
		};

		class ClothingShop_Background_Elements_Filter : MrFrost_RscText {
			idc = MrFrost_IDC_ClothingShop_Background_Elements_Filter;
			MrFrost_POSITION(82,687,260,28)
			colorBackground[] = {0.09804,0.09804,0.09804,1};
		};

///////////////////////////////////////////////////////////////////////////////

		class ClothingShop_Slider_View : MrFrost_RscXSliderH {
			idc = MrFrost_IDC_ClothingShop_Slider_View;
			MrFrost_POSITION(476,996,968,28)
			text = "";
			onSliderPosChanged = "[4,_this select 1] call life_fnc_s_onSliderChange;";
		};

///////////////////////////////////////////////////////////////////////////////

		class ClothingShop_List_Shop : MrFrost_RscListBox {
			idc = MrFrost_IDC_ClothingShop_List_Shop;
			MrFrost_POSITION(67,310,290,338)
			colorBackground[] = {0,0,0,0};
            colortext[] = {1,1,1,1};
            colorShadow[] = {0,0,0,0};
            sizeEx = 0.035;
			onLBSelChanged = "[_this] call life_fnc_changeClothes;";
		};

		class ClothingShop_Combo_Elements_Filter : MrFrost_RscCombo {
			idc = MrFrost_IDC_ClothingShop_Combo_Elements_Filter;
			MrFrost_POSITION(82,687,260,28)
			colorBackground[] = {0,0,0,0};
            colortext[] = {1,1,1,1};
            colorShadow[] = {0,0,0,0};
            style = 512;
            sizeEx = 0.035;
			onLBSelChanged  = "_this call life_fnc_clothingFilter";
		};

///////////////////////////////////////////////////////////////////////////////

		class ClothingShop_Title_Shop : MrFrost_RscText {
			idc = MrFrost_IDC_ClothingShop_Title_Shop;
			MrFrost_POSITION(67,264,290,40)
			colorBackground[] = {0,0,0,0};
            colortext[] = {1,1,1,1};
            colorShadow[] = {0,0,0,0};
            style = 0x02;
            sizeex = 0.08;
            font = PuristaSemiBold;
            text = "Clothing Store";
		};

		class ClothingShop_Text_Price : MrFrost_RscStructuredText {
			idc = MrFrost_IDC_ClothingShop_Text_Price;
			MrFrost_POSITION(82,730,122,28)
            font = PuristaSemiBold;
            sizeEx = 0.035;
            //text = Price: <t color='#8cff9b'>$1234567890</t>;
            text = Price: 1234567$
		};

		class ClothingShop_Text_Price_Total : MrFrost_RscStructuredText {
			idc = MrFrost_IDC_ClothingShop_Text_Price_Total;
			MrFrost_POSITION(220,730,122,28)
            font = PuristaSemiBold;
            sizeEx = 0.035;
            //text = Total: <t color='#8cff9b'>$1234567890</t>;
            text = Total: 1234567$
		};

///////////////////////////////////////////////////////////////////////////////

		class ClothingShop_Button_Elements_Buy : MrFrost_RscButton {
			idc = MrFrost_IDC_ClothingShop_Button_Elements_Buy;
			MrFrost_POSITION(82,773,260,28)
			colorBackground[] = {0.09804,0.09804,0.09804,1};
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
			onButtonClick = "[] call life_fnc_buyClothes;";
		};

		class ClothingShop_Button_Close : MrFrost_RscButton {
			idc = MrFrost_IDC_ClothingShop_Button_Close;
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
            onButtonClick = "closeDialog 0; [] call life_fnc_playerSkins;";
		};
	};
};
