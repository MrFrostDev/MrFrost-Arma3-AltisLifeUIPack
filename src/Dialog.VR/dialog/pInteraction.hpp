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
 * pInteraction.hpp - Player and vehicle interaction menus
 *
 * Part of    : Altis Life UI Pack (MrFrost, 2021) - archived, unmaintained.
 * Root class : pInteraction_Menu / vInteraction_Menu
 * IDD        : MrFrost_IDD_pInteraction / MrFrost_IDD_vInteraction = 37400 (both)
 * Opened by  : createDialog "pInteraction_Menu"; / createDialog "vInteraction_Menu";
 * Requires   : dialog/MrFrost_defines.hpp (MrFrost_POSITION and the
 *              MrFrost_Rsc* base classes) and dialog/common.hpp.
 *
 * Positions are authored against a 1920x1080 reference canvas.
 * MrFrost_POSITION(X,Y,W,H) rewrites those pixel values into
 * safezone-relative coordinates at preprocess time, so the numbers
 * below can be read directly as pixels on a 1080p screen.
 *
 * Note       : pInteraction_Menu sets idd = MrFrost_IDD_Interaction, a macro
 *              that is never defined. Left as-is; this is the first thing to
 *              fix - see known-issues.md.
 *
 * Full IDD/IDC table : docs/dialog-reference.md
 * Before production  : docs/known-issues.md
 * ------------------------------------------------------------------------- */
/* IDD/IDCs Macros */
//Person Interaction
#define MrFrost_IDD_pInteraction 37400
//Main Background
#define MrFrost_IDC_pInteraction_MainBackground -1
#define MrFrost_IDC_pInteraction_Bar_Bottom -1
#define MrFrost_IDC_pInteraction_Bar_Top -1
#define MrFrost_IDC_pInteraction_Button_Close_Image -1
//Parts Background
#define MrFrost_IDC_pInteraction_Background_Interaction -1
#define MrFrost_IDC_pInteraction_Bar_Interaction -1
//Titles
#define MrFrost_IDC_pInteraction_Title_Interaction 37401
//Elements Background
#define MrFrost_IDC_pInteraction_Background_Interaction_Button_1 -1
#define MrFrost_IDC_pInteraction_Background_Interaction_Button_2 -1
#define MrFrost_IDC_pInteraction_Background_Interaction_Button_3 -1
#define MrFrost_IDC_pInteraction_Background_Interaction_Button_4 -1
#define MrFrost_IDC_pInteraction_Background_Interaction_Button_5 -1
#define MrFrost_IDC_pInteraction_Background_Interaction_Button_6 -1
#define MrFrost_IDC_pInteraction_Background_Interaction_Button_7 -1
#define MrFrost_IDC_pInteraction_Background_Interaction_Button_8 -1
#define MrFrost_IDC_pInteraction_Background_Interaction_Button_9 -1
#define MrFrost_IDC_pInteraction_Background_Interaction_Button_10 -1
#define MrFrost_IDC_pInteraction_Background_Interaction_Button_11 -1
//Buttons
#define MrFrost_IDC_pInteraction_Button_Interaction_Button_1 37450
#define MrFrost_IDC_pInteraction_Button_Interaction_Button_2 37451
#define MrFrost_IDC_pInteraction_Button_Interaction_Button_3 37452
#define MrFrost_IDC_pInteraction_Button_Interaction_Button_4 37453
#define MrFrost_IDC_pInteraction_Button_Interaction_Button_5 37454
#define MrFrost_IDC_pInteraction_Button_Interaction_Button_6 37455
#define MrFrost_IDC_pInteraction_Button_Interaction_Button_7 37456
#define MrFrost_IDC_pInteraction_Button_Interaction_Button_8 37457
#define MrFrost_IDC_pInteraction_Button_Interaction_Button_9 50020
#define MrFrost_IDC_pInteraction_Button_Interaction_Button_10 50021
#define MrFrost_IDC_pInteraction_Button_Interaction_Button_11 50022
//Main Buttons
#define MrFrost_IDC_pInteraction_Button_Close -1

//Vehicle Interaction
#define MrFrost_IDD_vInteraction 37400
//Main Background
#define MrFrost_IDC_vInteraction_MainBackground -1
#define MrFrost_IDC_vInteraction_Bar_Bottom -1
#define MrFrost_IDC_vInteraction_Bar_Top -1
#define MrFrost_IDC_vInteraction_Button_Close_Image -1
//Parts Background
#define MrFrost_IDC_vInteraction_Background_Interaction -1
#define MrFrost_IDC_vInteraction_Bar_Interaction -1
//Titles
#define MrFrost_IDC_vInteraction_Title_Interaction 37401
//Elements Background
#define MrFrost_IDC_vInteraction_Background_Interaction_Button_1 -1
#define MrFrost_IDC_vInteraction_Background_Interaction_Button_2 -1
#define MrFrost_IDC_vInteraction_Background_Interaction_Button_3 -1
#define MrFrost_IDC_vInteraction_Background_Interaction_Button_4 -1
#define MrFrost_IDC_vInteraction_Background_Interaction_Button_5 -1
#define MrFrost_IDC_vInteraction_Background_Interaction_Button_6 -1
#define MrFrost_IDC_vInteraction_Background_Interaction_Button_7 -1
#define MrFrost_IDC_vInteraction_Background_Interaction_Button_8 -1
#define MrFrost_IDC_vInteraction_Background_Interaction_Button_9 -1
#define MrFrost_IDC_vInteraction_Background_Interaction_Button_10 -1
#define MrFrost_IDC_vInteraction_Background_Interaction_Button_11 -1
//Buttons
#define MrFrost_IDC_vInteraction_Button_Interaction_Button_1 37450
#define MrFrost_IDC_vInteraction_Button_Interaction_Button_2 37451
#define MrFrost_IDC_vInteraction_Button_Interaction_Button_3 37452
#define MrFrost_IDC_vInteraction_Button_Interaction_Button_4 37453
#define MrFrost_IDC_vInteraction_Button_Interaction_Button_5 37454
#define MrFrost_IDC_vInteraction_Button_Interaction_Button_6 37455
#define MrFrost_IDC_vInteraction_Button_Interaction_Button_7 37456
#define MrFrost_IDC_vInteraction_Button_Interaction_Button_8 37457
#define MrFrost_IDC_vInteraction_Button_Interaction_Button_9 50020
#define MrFrost_IDC_vInteraction_Button_Interaction_Button_10 50021
#define MrFrost_IDC_vInteraction_Button_Interaction_Button_11 50022
//Main Buttons
#define MrFrost_IDC_pInteraction_Button_Close -1

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
//Person Interactive
class pInteraction_Menu {
    idd = MrFrost_IDD_Interaction;
    movingEnable = 0;
    enableSimulation = 1;

    class Controls {

        class pInteraction_MainBackground : MrFrost_RscText {
			idc = MrFrost_IDC_pInteraction_MainBackground;
			MrFrost_POSITION(765,260,364,582)
			colorBackground[] = {0.094,0.094,0.094,1};
		};

        class pInteraction_Bar_Bottom : MrFrost_RscText {
			idc = MrFrost_IDC_pInteraction_Bar_Bottom;
			MrFrost_POSITION(765,842,364,7)
			colorBackground[] = {0.69,0,0,1};
		};

        class pInteraction_Bar_Top : MrFrost_RscText {
			idc = MrFrost_IDC_pInteraction_Bar_Top;
			MrFrost_POSITION(765,253,364,7)
			colorBackground[] = {0.69,0,0,1};
		};

////////////////////////////////////////////////////////////////////////////////

        class pInteraction_Background_Interaction : MrFrost_RscText {
			idc = MrFrost_IDC_pInteraction_Background_Interaction;
			MrFrost_POSITION(802,319,290,488)
			colorBackground[] = {0,0,0,0.31};
		};

        class pInteraction_Bar_Interaction : MrFrost_RscText {
			idc = MrFrost_IDC_pInteraction_Bar_Interaction;
			MrFrost_POSITION(802,313,290,6)
			colorBackground[] = {0.69,0,0,1};
		};

////////////////////////////////////////////////////////////////////////////////

        class pInteraction_Title_Interaction : MrFrost_RscText {
			idc = MrFrost_IDC_pInteraction_Title_Interaction;
			MrFrost_POSITION(802,275,290,40)
			colorBackground[] = {0,0,0,0};
            colortext[] = {1,1,1,1};
            colorShadow[] = {0,0,0,0};
            style = 0x02;
            sizeex = 0.08;
            font = PuristaSemiBold;
            text = "Interaction";
            //text = "$STR_pInAct_Title";
		};

////////////////////////////////////////////////////////////////////////////////

        class pInteraction_Background_Interaction_Button_1 : MrFrost_RscText {
			idc = MrFrost_IDC_pInteraction_Background_Interaction_Button_1;
			MrFrost_POSITION(817,334,260,28)
			colorBackground[] = {0.098,0.098,0.098,1};
		};

        class pInteraction_Background_Interaction_Button_2 : MrFrost_RscText {
			idc = MrFrost_IDC_pInteraction_Background_Interaction_Button_2;
			MrFrost_POSITION(817,377,260,28)
			colorBackground[] = {0.098,0.098,0.098,1};
		};

        class pInteraction_Background_Interaction_Button_3 : MrFrost_RscText {
			idc = MrFrost_IDC_pInteraction_Background_Interaction_Button_3;
			MrFrost_POSITION(817,420,260,28)
			colorBackground[] = {0.098,0.098,0.098,1};
		};

        class pInteraction_Background_Interaction_Button_4 : MrFrost_RscText {
			idc = MrFrost_IDC_pInteraction_Background_Interaction_Button_4;
			MrFrost_POSITION(817,463,260,28)
			colorBackground[] = {0.098,0.098,0.098,1};
		};

        class pInteraction_Background_Interaction_Button_5 : MrFrost_RscText {
			idc = MrFrost_IDC_pInteraction_Background_Interaction_Button_5;
			MrFrost_POSITION(817,506,260,28)
			colorBackground[] = {0.098,0.098,0.098,1};
		};

        class pInteraction_Background_Interaction_Button_6 : MrFrost_RscText {
			idc = MrFrost_IDC_pInteraction_Background_Interaction_Button_6;
			MrFrost_POSITION(817,549,260,28)
			colorBackground[] = {0.098,0.098,0.098,1};
		};

        class pInteraction_Background_Interaction_Button_7 : MrFrost_RscText {
			idc = MrFrost_IDC_pInteraction_Background_Interaction_Button_7;
			MrFrost_POSITION(817,592,260,28)
			colorBackground[] = {0.098,0.098,0.098,1};
		};

        class pInteraction_Background_Interaction_Button_8 : MrFrost_RscText {
			idc = MrFrost_IDC_pInteraction_Background_Interaction_Button_8;
			MrFrost_POSITION(817,635,260,28)
			colorBackground[] = {0.098,0.098,0.098,1};
		};

        class pInteraction_Background_Interaction_Button_9 : MrFrost_RscText {
			idc = MrFrost_IDC_pInteraction_Background_Interaction_Button_9;
			MrFrost_POSITION(817,678,260,28)
			colorBackground[] = {0.098,0.098,0.098,1};
		};

        class pInteraction_Background_Interaction_Button_10 : MrFrost_RscText {
			idc = MrFrost_IDC_pInteraction_Background_Interaction_Button_10;
			MrFrost_POSITION(817,721,260,28)
			colorBackground[] = {0.098,0.098,0.098,1};
		};

        class pInteraction_Background_Interaction_Button_11 : MrFrost_RscText {
			idc = MrFrost_IDC_pInteraction_Background_Interaction_Button_11;
			MrFrost_POSITION(817,764,260,28)
			colorBackground[] = {0.098,0.098,0.098,1};
		};

////////////////////////////////////////////////////////////////////////////////

        class pInteraction_Button_Close_Image : MrFrost_RscPictureKeepAspect {
			idc = MrFrost_IDC_pInteraction_Button_Close_Image;
			MrFrost_POSITION(770,265,18,18)
			colorBackground[] = {0,0,0,0};
            text= "\A3\ui_f\data\GUI\Rsc\RscDisplayArcadeMap\icon_exit_cross_ca.paa";
		};

////////////////////////////////////////////////////////////////////////////////

        class pInteraction_Button_Interaction_Button_1 : MrFrost_RscButton {
			idc = MrFrost_IDC_pInteraction_Button_Interaction_Button_1;
			MrFrost_POSITION(817,334,260,28)
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
            text= "Button 1";
		};

        class pInteraction_Button_Interaction_Button_2 : MrFrost_RscButton {
			idc = MrFrost_IDC_pInteraction_Button_Interaction_Button_2;
			MrFrost_POSITION(817,377,260,28)
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
            text= "Button 2";
		};

        class pInteraction_Button_Interaction_Button_3 : MrFrost_RscButton {
			idc = MrFrost_IDC_pInteraction_Button_Interaction_Button_3;
			MrFrost_POSITION(817,420,260,28)
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
            text= "Button 3";
		};

        class pInteraction_Button_Interaction_Button_4 : MrFrost_RscButton {
			idc = MrFrost_IDC_pInteraction_Button_Interaction_Button_4;
			MrFrost_POSITION(817,463,260,28)
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
            text= "Button 4";
		};

        class pInteraction_Button_Interaction_Button_5 : MrFrost_RscButton {
			idc = MrFrost_IDC_pInteraction_Button_Interaction_Button_5;
			MrFrost_POSITION(817,506,260,28)
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
            text= "Button 5";
		};

        class pInteraction_Button_Interaction_Button_6 : MrFrost_RscButton {
			idc = MrFrost_IDC_pInteraction_Button_Interaction_Button_6;
			MrFrost_POSITION(817,549,260,28)
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
            text= "Button 6";
		};

        class pInteraction_Button_Interaction_Button_7 : MrFrost_RscButton {
			idc = MrFrost_IDC_pInteraction_Button_Interaction_Button_7;
			MrFrost_POSITION(817,592,260,28)
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
            text= "Button 7";
		};

        class pInteraction_Button_Interaction_Button_8 : MrFrost_RscButton {
			idc = MrFrost_IDC_pInteraction_Button_Interaction_Button_8;
			MrFrost_POSITION(817,635,260,28)
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
            text= "Button 8";
		};

        class pInteraction_Button_Interaction_Button_9 : MrFrost_RscButton {
			idc = MrFrost_IDC_pInteraction_Button_Interaction_Button_9;
			MrFrost_POSITION(817,678,260,28)
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
            text= "Button 9";
		};

        class pInteraction_Button_Interaction_Button_10 : MrFrost_RscButton {
			idc = MrFrost_IDC_pInteraction_Button_Interaction_Button_10;
			MrFrost_POSITION(817,721,260,28)
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
            text= "Button 10";
		};

        class pInteraction_Button_Interaction_Button_11 : MrFrost_RscButton {
			idc = MrFrost_IDC_pInteraction_Button_Interaction_Button_11;
			MrFrost_POSITION(817,764,260,28)
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
            text= "Button 11";
		};

        class pInteraction_Button_Close : MrFrost_RscButton {
			idc = MrFrost_IDC_pInteraction_Button_Close;
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

//Vehicle Interaction

class vInteraction_Menu {
    idd = MrFrost_IDD_vInteraction;
    movingEnable = 0;
    enableSimulation = 1;

    class Controls {

        class vInteraction_MainBackground : MrFrost_RscText {
			idc = MrFrost_IDC_vInteraction_MainBackground;
			MrFrost_POSITION(765,260,364,582)
			colorBackground[] = {0.094,0.094,0.094,1};
		};

        class vInteraction_Bar_Bottom : MrFrost_RscText {
			idc = MrFrost_IDC_vInteraction_Bar_Bottom;
			MrFrost_POSITION(765,842,364,7)
			colorBackground[] = {0.69,0,0,1};
		};

        class vInteraction_Bar_Top : MrFrost_RscText {
			idc = MrFrost_IDC_vInteraction_Bar_Top;
			MrFrost_POSITION(765,253,364,7)
			colorBackground[] = {0.69,0,0,1};
		};

////////////////////////////////////////////////////////////////////////////////

        class vInteraction_Background_Interaction : MrFrost_RscText {
			idc = MrFrost_IDC_vInteraction_Background_Interaction;
			MrFrost_POSITION(802,319,290,488)
			colorBackground[] = {0,0,0,0.31};
		};

        class vInteraction_Bar_Interaction : MrFrost_RscText {
			idc = MrFrost_IDC_vInteraction_Bar_Interaction;
			MrFrost_POSITION(802,313,290,6)
			colorBackground[] = {0.69,0,0,1};
		};

////////////////////////////////////////////////////////////////////////////////

        class vInteraction_Title_Interaction : MrFrost_RscText {
			idc = MrFrost_IDC_vInteraction_Title_Interaction;
			MrFrost_POSITION(802,275,290,40)
			colorBackground[] = {0,0,0,0};
            colortext[] = {1,1,1,1};
            colorShadow[] = {0,0,0,0};
            style = 0x02;
            sizeex = 0.08;
            font = PuristaSemiBold;
            text = "Interaction";
            //text = "$STR_pInAct_Title";
		};

////////////////////////////////////////////////////////////////////////////////

        class vInteraction_Background_Interaction_Button_1 : MrFrost_RscText {
			idc = MrFrost_IDC_vInteraction_Background_Interaction_Button_1;
			MrFrost_POSITION(817,334,260,28)
			colorBackground[] = {0.098,0.098,0.098,1};
		};

        class vInteraction_Background_Interaction_Button_2 : MrFrost_RscText {
			idc = MrFrost_IDC_vInteraction_Background_Interaction_Button_2;
			MrFrost_POSITION(817,377,260,28)
			colorBackground[] = {0.098,0.098,0.098,1};
		};

        class vInteraction_Background_Interaction_Button_3 : MrFrost_RscText {
			idc = MrFrost_IDC_vInteraction_Background_Interaction_Button_3;
			MrFrost_POSITION(817,420,260,28)
			colorBackground[] = {0.098,0.098,0.098,1};
		};

        class vInteraction_Background_Interaction_Button_4 : MrFrost_RscText {
			idc = MrFrost_IDC_vInteraction_Background_Interaction_Button_4;
			MrFrost_POSITION(817,463,260,28)
			colorBackground[] = {0.098,0.098,0.098,1};
		};

        class vInteraction_Background_Interaction_Button_5 : MrFrost_RscText {
			idc = MrFrost_IDC_vInteraction_Background_Interaction_Button_5;
			MrFrost_POSITION(817,506,260,28)
			colorBackground[] = {0.098,0.098,0.098,1};
		};

        class vInteraction_Background_Interaction_Button_6 : MrFrost_RscText {
			idc = MrFrost_IDC_vInteraction_Background_Interaction_Button_6;
			MrFrost_POSITION(817,549,260,28)
			colorBackground[] = {0.098,0.098,0.098,1};
		};

        class vInteraction_Background_Interaction_Button_7 : MrFrost_RscText {
			idc = MrFrost_IDC_vInteraction_Background_Interaction_Button_7;
			MrFrost_POSITION(817,592,260,28)
			colorBackground[] = {0.098,0.098,0.098,1};
		};

        class vInteraction_Background_Interaction_Button_8 : MrFrost_RscText {
			idc = MrFrost_IDC_vInteraction_Background_Interaction_Button_8;
			MrFrost_POSITION(817,635,260,28)
			colorBackground[] = {0.098,0.098,0.098,1};
		};

        class vInteraction_Background_Interaction_Button_9 : MrFrost_RscText {
			idc = MrFrost_IDC_vInteraction_Background_Interaction_Button_9;
			MrFrost_POSITION(817,678,260,28)
			colorBackground[] = {0.098,0.098,0.098,1};
		};

        class vInteraction_Background_Interaction_Button_10 : MrFrost_RscText {
			idc = MrFrost_IDC_vInteraction_Background_Interaction_Button_10;
			MrFrost_POSITION(817,721,260,28)
			colorBackground[] = {0.098,0.098,0.098,1};
		};

        class vInteraction_Background_Interaction_Button_11 : MrFrost_RscText {
			idc = MrFrost_IDC_vInteraction_Background_Interaction_Button_11;
			MrFrost_POSITION(817,764,260,28)
			colorBackground[] = {0.098,0.098,0.098,1};
		};

////////////////////////////////////////////////////////////////////////////////

        class vInteraction_Button_Close_Image : MrFrost_RscPictureKeepAspect {
			idc = MrFrost_IDC_vInteraction_Button_Close_Image;
			MrFrost_POSITION(770,265,18,18)
			colorBackground[] = {0,0,0,0};
            text= "\A3\ui_f\data\GUI\Rsc\RscDisplayArcadeMap\icon_exit_cross_ca.paa";
		};

////////////////////////////////////////////////////////////////////////////////

        class vInteraction_Button_Interaction_Button_1 : MrFrost_RscButton {
			idc = MrFrost_IDC_vInteraction_Button_Interaction_Button_1;
			MrFrost_POSITION(817,334,260,28)
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
            text= "Button 1";
		};

        class vInteraction_Button_Interaction_Button_2 : MrFrost_RscButton {
			idc = MrFrost_IDC_vInteraction_Button_Interaction_Button_2;
			MrFrost_POSITION(817,377,260,28)
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
            text= "Button 2";
		};

        class vInteraction_Button_Interaction_Button_3 : MrFrost_RscButton {
			idc = MrFrost_IDC_vInteraction_Button_Interaction_Button_3;
			MrFrost_POSITION(817,420,260,28)
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
            text= "Button 3";
		};

        class vInteraction_Button_Interaction_Button_4 : MrFrost_RscButton {
			idc = MrFrost_IDC_vInteraction_Button_Interaction_Button_4;
			MrFrost_POSITION(817,463,260,28)
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
            text= "Button 4";
		};

        class vInteraction_Button_Interaction_Button_5 : MrFrost_RscButton {
			idc = MrFrost_IDC_vInteraction_Button_Interaction_Button_5;
			MrFrost_POSITION(817,506,260,28)
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
            text= "Button 5";
		};

        class vInteraction_Button_Interaction_Button_6 : MrFrost_RscButton {
			idc = MrFrost_IDC_vInteraction_Button_Interaction_Button_6;
			MrFrost_POSITION(817,549,260,28)
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
            text= "Button 6";
		};

        class vInteraction_Button_Interaction_Button_7 : MrFrost_RscButton {
			idc = MrFrost_IDC_vInteraction_Button_Interaction_Button_7;
			MrFrost_POSITION(817,592,260,28)
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
            text= "Button 7";
		};

        class vInteraction_Button_Interaction_Button_8 : MrFrost_RscButton {
			idc = MrFrost_IDC_vInteraction_Button_Interaction_Button_8;
			MrFrost_POSITION(817,635,260,28)
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
            text= "Button 8";
		};

        class vInteraction_Button_Interaction_Button_9 : MrFrost_RscButton {
			idc = MrFrost_IDC_vInteraction_Button_Interaction_Button_9;
			MrFrost_POSITION(817,678,260,28)
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
            text= "Button 9";
		};

        class vInteraction_Button_Interaction_Button_10 : MrFrost_RscButton {
			idc = MrFrost_IDC_vInteraction_Button_Interaction_Button_10;
			MrFrost_POSITION(817,721,260,28)
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
            text= "Button 10";
		};

        class vInteraction_Button_Interaction_Button_11 : MrFrost_RscButton {
			idc = MrFrost_IDC_vInteraction_Button_Interaction_Button_11;
			MrFrost_POSITION(817,764,260,28)
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
            text= "Button 11";
		};

        class vInteraction_Button_Close : MrFrost_RscButton {
			idc = MrFrost_IDC_vInteraction_Button_Close;
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
