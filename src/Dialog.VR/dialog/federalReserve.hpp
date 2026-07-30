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
 * federalReserve.hpp - Federal reserve
 *
 * Part of    : Altis Life UI Pack (MrFrost, 2021) - archived, unmaintained.
 * Root class : Federal_Safe
 * IDD        : MrFrost_IDD_Federal = 3500
 * Opened by  : createDialog "Federal_Safe";
 * Requires   : dialog/MrFrost_defines.hpp (MrFrost_POSITION and the
 *              MrFrost_Rsc* base classes) and dialog/common.hpp.
 *
 * Positions are authored against a 1920x1080 reference canvas.
 * MrFrost_POSITION(X,Y,W,H) rewrites those pixel values into
 * safezone-relative coordinates at preprocess time, so the numbers
 * below can be read directly as pixels on a 1080p screen.
 *
 * Note       : Shares resolved IDD 3500 with trunk.hpp.
 *
 * Full IDD/IDC table : docs/dialog-reference.md
 * Before production  : docs/known-issues.md
 * ------------------------------------------------------------------------- */
 /* IDD/IDCs Macros */
#define MrFrost_IDD_Federal 3500
//Main Background
#define MrFrost_IDC_Federal_MainBackground -1
#define MrFrost_IDC_Federal_Bar_Bottom -1
#define MrFrost_IDC_Federal_Bar_Top -1
#define MrFrost_IDC_Federal_Button_Close_Image -1
//Parts Background
#define MrFrost_IDC_Federal_Background_Safe_Federal_List -1
#define MrFrost_IDC_Federal_Background_Safe_Federal_Buttons -1
#define MrFrost_IDC_Federal_Bar_Safe_Federal_List -1
#define MrFrost_IDC_Federal_Bar_Safe_Federal_Buttons -1
//Titles
#define MrFrost_IDC_Federal_Title_Safe_Federal_List 2403
#define MrFrost_IDC_Federal_Title_Safe_Weight 3504
//Elements Background
#define MrFrost_IDC_Federal_Background_Safe_Federal_Value -1
//Elements
#define MrFrost_IDC_Federal_Safe_Federal_List 3502
#define MrFrost_IDC_Federal_Safe_Federal_Value 3505
//Buttons
#define MrFrost_IDC_Federal_Button_Take -1
//Main Buttons
#define MrFrost_IDC_Federal_Button_Close -1

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
class Federal_Safe {
	idd = MrFrost_IDD_Federal;
    name = "Federal_Safe";
    movingEnable = 0;
    enableSimulation = 1;

    class Controls {

        /*class Picture_Preview : MrFrost_RscPictureKeepAspect {
            idc = -1;
            MrFrost_POSITION(0,0,1920,1080)
            text = "pictures\GUI\PreviewBackground.jpg";
        };*/

////////////////////////////////////////////////////////////////////////////////

        class Federal_MainBackground : MrFrost_RscText {
			idc = MrFrost_IDC_Federal_MainBackground;
			MrFrost_POSITION(778,249,364,582)
			colorBackground[] = {0.094,0.094,0.094,1};
		};

        class Federal_Bar_Bottom : MrFrost_RscText {
			idc = MrFrost_IDC_Federal_Bar_Bottom;
			MrFrost_POSITION(778,831,364,7)
			colorBackground[] = {0.69,0,0,1};
		};

        class Federal_Bar_Top : MrFrost_RscText {
			idc = MrFrost_IDC_Federal_Bar_Top;
			MrFrost_POSITION(778,242,364,7)
			colorBackground[] = {0.69,0,0,1};
		};

////////////////////////////////////////////////////////////////////////////////

		class Federal_Title_Safe_Weight : MrFrost_RscText {
			idc = MrFrost_IDC_Federal_Title_Safe_Weight;
			MrFrost_POSITION(815,481,290,40)
			colorBackground[] = {0,0,0,0};
            colortext[] = {1,1,1,1};
            colorShadow[] = {0,0,0,0};
            style = 0x02;
            sizeex = 0.08;
            font = PuristaSemiBold;
            text = "100/100";
		};

////////////////////////////////////////////////////////////////////////////////

        class Federal_Background_Safe_Federal_List : MrFrost_RscText {
			idc = MrFrost_IDC_Federal_Background_Safe_Federal_List;
			MrFrost_POSITION(815,308,290,386)
			colorBackground[] = {0,0,0,0.31};
		};

        class Federal_Background_Safe_Federal_Buttons : MrFrost_RscText {
			idc = MrFrost_IDC_Federal_Background_Safe_Federal_Buttons;
			MrFrost_POSITION(815,715,290,101)
			colorBackground[] = {0,0,0,0.31};
		};

////////////////////////////////////////////////////////////////////////////////

        class Federal_Bar_Safe_Federal_List : MrFrost_RscText {
			idc = MrFrost_IDC_Federal_Bar_Safe_Federal_List;
			MrFrost_POSITION(815,302,290,6)
			colorBackground[] = {0.69,0,0,1};
		};

        class Federal_Bar_Safe_Federal_Buttons : MrFrost_RscText {
			idc = MrFrost_IDC_Federal_Bar_Safe_Federal_Buttons;
			MrFrost_POSITION(815,709,290,6)
			colorBackground[] = {0.69,0,0,1};
		};

////////////////////////////////////////////////////////////////////////////////

        class Federal_Title_Safe_Federal_List : MrFrost_RscText {
			idc = MrFrost_IDC_Federal_Title_Safe_Federal_List;
			MrFrost_POSITION(815,264,290,40)
			colorBackground[] = {0,0,0,0};
            colortext[] = {1,1,1,1};
            colorShadow[] = {0,0,0,0};
            style = 0x02;
            sizeex = 0.08;
            font = PuristaSemiBold;
            //text = "$STR_Federal_TInventory";
            text = "Federal Reserve";
		};

////////////////////////////////////////////////////////////////////////////////

        class Federal_Background_Safe_Federal_Value : MrFrost_RscText {
			idc = MrFrost_IDC_Federal_Background_Safe_Federal_Value;
			MrFrost_POSITION(830,730,260,28)
			colorBackground[] = {0.098,0.098,0.098,1};
		};

////////////////////////////////////////////////////////////////////////////////

        class Federal_Safe_Federal_Value : MrFrost_RscEdit {
			idc = MrFrost_IDC_Federal_Safe_Federal_Value;
			MrFrost_POSITION(830,730,260,28)
			colorBackground[] = {0,0,0,0};
            colortext[] = {1,1,1,1};
            colorShadow[] = {0,0,0,0};
            style = 512;
            sizeex = 0.048;
            text= "1";
		};

////////////////////////////////////////////////////////////////////////////////

        class Federal_Safe_Federal_List : MrFrost_RscListBox {
			idc = MrFrost_IDC_Federal_Safe_Federal_List;
			MrFrost_POSITION(815,310,290,381)
			colorBackground[] = {0,0,0,0};
            colortext[] = {1,1,1,1};
            colorShadow[] = {0,0,0,0};
            sizeEx = 0.035;
		};

        class Federal_Button_Take : MrFrost_RscButton {
			idc = MrFrost_IDC_Federal_Button_Take;
			MrFrost_POSITION(830,773,260,28)
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
            //text = "$STR_Trunk_Take";
            text= "Take";
            onButtonClick = "[] call life_fnc_safeTake;";
		};

////////////////////////////////////////////////////////////////////////////////

        class Federal_Button_Close_Image : MrFrost_RscPictureKeepAspect {
			idc = MrFrost_IDC_Federal_Button_Close_Image;
			MrFrost_POSITION(783,254,18,18)
			colorBackground[] = {0,0,0,0};
            text= "\A3\ui_f\data\GUI\Rsc\RscDisplayArcadeMap\icon_exit_cross_ca.paa";
		};

        class Federal_Button_Close : MrFrost_RscButton {
			idc = MrFrost_IDC_Federal_Button_Close;
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
