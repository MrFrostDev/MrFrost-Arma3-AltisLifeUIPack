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
 * key_chain.hpp - Vehicle key chain
 *
 * Part of    : Altis Life UI Pack (MrFrost, 2021) - archived, unmaintained.
 * Root class : Life_key_management
 * IDD        : MrFrost_IDD_Keys = 2700
 * Opened by  : createDialog "Life_key_management";
 * Requires   : dialog/MrFrost_defines.hpp (MrFrost_POSITION and the
 *              MrFrost_Rsc* base classes) and dialog/common.hpp.
 *
 * Positions are authored against a 1920x1080 reference canvas.
 * MrFrost_POSITION(X,Y,W,H) rewrites those pixel values into
 * safezone-relative coordinates at preprocess time, so the numbers
 * below can be read directly as pixels on a 1080p screen.
 *
 * Note       : Shares resolved IDD 2700 with bank.hpp.
 *
 * Full IDD/IDC table : docs/dialog-reference.md
 * Before production  : docs/known-issues.md
 * ------------------------------------------------------------------------- */
 /* IDD/IDCs Macros */
#define MrFrost_IDD_Keys 2700
//Main Background
#define MrFrost_IDC_Keys_MainBackground -1
#define MrFrost_IDC_Keys_Bar_Bottom -1
#define MrFrost_IDC_Keys_Bar_Top -1
//pictures
#define MrFrost_IDC_Keys_Button_Close_Image -1
#define MrFrost_IDC_Keys_Logo -1
//Parts Background
#define MrFrost_IDC_Keys_Background_Keys_List -1
#define MrFrost_IDC_Keys_Background_Keys_Buttons -1
#define MrFrost_IDC_Keys_Bar_Keys_List -1
#define MrFrost_IDC_Keys_Bar_Keys_Buttons -1
//Titles
#define MrFrost_IDC_Keys_Title_Keys_List -1
//Elements Background
#define MrFrost_IDC_Keys_Background_Keys_Value -1
//Elements
#define MrFrost_IDC_Keys_List 2701
#define MrFrost_IDC_Keys_Combo 2702
//Buttons
#define MrFrost_IDC_Keys_Button_Give_Key 2703
#define MrFrost_IDC_Keys_Button_Drop_Key -1
//Main Buttons
#define MrFrost_IDC_Keys_Button_Close -1

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
class Life_key_management {
	idd = MrFrost_IDD_Keys;
    name= "life_key_chain";
    movingEnable = 0;
    enableSimulation = 1;
    onLoad = "[] spawn life_fnc_keyMenu;";

    class Controls {

        class Picture_Preview : MrFrost_RscPictureKeepAspect {
            idc = -1;
            MrFrost_POSITION(0,0,1920,1080)
            text = "pictures\GUI\PreviewBackground.jpg";
        };

////////////////////////////////////////////////////////////////////////////////

        class Keys_MainBackground : MrFrost_RscText {
			idc = MrFrost_IDC_Keys_MainBackground;
			MrFrost_POSITION(778,249,484,582)
			colorBackground[] = {0.094,0.094,0.094,1};
		};

        class Keys_Bar_Bottom : MrFrost_RscText {
			idc = MrFrost_IDC_Keys_Bar_Bottom;
			MrFrost_POSITION(778,831,484,7)
			colorBackground[] = {0.69,0,0,1};
		};

        class Keys_Bar_Top : MrFrost_RscText {
			idc = MrFrost_IDC_Keys_Bar_Top;
			MrFrost_POSITION(778,242,484,7)
			colorBackground[] = {0.69,0,0,1};
		};

////////////////////////////////////////////////////////////////////////////////

        class Keys_Logo : MrFrost_RscPictureKeepAspect {
            idc = MrFrost_IDC_Keys_Logo;
			MrFrost_POSITION(789,270,462,462)
            text = "pictures\GUI\Logo_Mammut.paa";
        };

////////////////////////////////////////////////////////////////////////////////

        class Keys_Background_Keys_List : MrFrost_RscText {
			idc = MrFrost_IDC_Keys_Background_Keys_List;
			MrFrost_POSITION(815,308,410,386)
			colorBackground[] = {0,0,0,0.31};
		};

        class Keys_Background_Keys_Buttons : MrFrost_RscText {
			idc = MrFrost_IDC_Keys_Background_Keys_Buttons;
			MrFrost_POSITION(815,715,410,101)
			colorBackground[] = {0,0,0,0.31};
		};

////////////////////////////////////////////////////////////////////////////////

        class Keys_Bar_Keys_List : MrFrost_RscText {
			idc = MrFrost_IDC_Keys_Bar_Keys_List;
			MrFrost_POSITION(815,302,410,6)
			colorBackground[] = {0.69,0,0,1};
		};

        class Keys_Bar_Keys_Buttons : MrFrost_RscText {
			idc = MrFrost_IDC_Keys_Bar_Keys_Buttons;
			MrFrost_POSITION(815,709,410,6)
			colorBackground[] = {0.69,0,0,1};
		};

////////////////////////////////////////////////////////////////////////////////

        class Keys_Title_Keys_List : MrFrost_RscText {
			idc = MrFrost_IDC_Keys_Title_Keys_List;
			MrFrost_POSITION(815,264,410,40)
			colorBackground[] = {0,0,0,0};
            colortext[] = {1,1,1,1};
            colorShadow[] = {0,0,0,0};
            style = 0x02;
            sizeex = 0.08;
            font = PuristaSemiBold;
            //text = "$STR_Keys_Title";
            text = "Your keys";
		};

////////////////////////////////////////////////////////////////////////////////

        class Keys_Background_Keys_Combo : MrFrost_RscText {
			idc = MrFrost_IDC_Keys_Background_Keys_Combo;
			MrFrost_POSITION(830,730,380,28)
			colorBackground[] = {0.098,0.098,0.098,1};
		};

////////////////////////////////////////////////////////////////////////////////

        class Keys_Keys_Combo : MrFrost_RscCombo {
			idc = MrFrost_IDC_Keys_Combo;
			MrFrost_POSITION(830,730,380,28)
			colorBackground[] = {0,0,0,0};
            colortext[] = {1,1,1,1};
            colorShadow[] = {0,0,0,0};
            style = 512;
            sizeEx = 0.035;
		};

////////////////////////////////////////////////////////////////////////////////

        class Keys_Keys_List : MrFrost_RscListBox {
			idc = MrFrost_IDC_Keys_List;
			MrFrost_POSITION(815,310,410,381)
			colorBackground[] = {0,0,0,0};
            colortext[] = {1,1,1,1};
            colorShadow[] = {0,0,0,0};
            sizeEx = 0.035;
		};

////////////////////////////////////////////////////////////////////////////////

        class Keys_Button_Give_Key : MrFrost_RscButton {
			idc = MrFrost_IDC_Keys_Button_Give_Key;
			MrFrost_POSITION(830,773,274,28)
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
            //text = "$STR_Keys_GiveKey";
            text= "Give Key";
            onButtonClick = "[] call life_fnc_keyGive";
		};

        class Keys_Button_Drop_Key : MrFrost_RscButton {
			idc = MrFrost_IDC_Keys_Button_Drop_Key;
			MrFrost_POSITION(1119,773,91,28)
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
            default = 0;
            //text = "$STR_Keys_DropKey";
            text= "Drop Key";
			onButtonClick = "[] call life_fnc_keyDrop";
		};

////////////////////////////////////////////////////////////////////////////////

        class Keys_Button_Close_Image : MrFrost_RscPictureKeepAspect {
			idc = MrFrost_IDC_Keys_Button_Close_Image;
			MrFrost_POSITION(783,254,18,18)
			colorBackground[] = {0,0,0,0};
            text= "\A3\ui_f\data\GUI\Rsc\RscDisplayArcadeMap\icon_exit_cross_ca.paa";
		};

        class Keys_Button_Close : MrFrost_RscButton {
			idc = MrFrost_IDC_Keys_Button_Close;
			MrFrost_POSITION(783,254,18,18)
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
