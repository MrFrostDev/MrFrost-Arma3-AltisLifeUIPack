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
 * cell_phone.hpp - Cell phone
 *
 * Part of    : Altis Life UI Pack (MrFrost, 2021) - archived, unmaintained.
 * Root class : Life_cell_phone
 * IDD        : MrFrost_IDD_Life_cell_phone = 3000
 * Opened by  : createDialog "Life_cell_phone";
 * Requires   : dialog/MrFrost_defines.hpp (MrFrost_POSITION and the
 *              MrFrost_Rsc* base classes) and dialog/common.hpp.
 *
 * Positions are authored against a 1920x1080 reference canvas.
 * MrFrost_POSITION(X,Y,W,H) rewrites those pixel values into
 * safezone-relative coordinates at preprocess time, so the numbers
 * below can be read directly as pixels on a 1080p screen.
 *
 * Note       : onLoad spawns life_fnc_cellphone, which fills the player list
 *              and message templates.
 *
 * Full IDD/IDC table : docs/dialog-reference.md
 * Before production  : docs/known-issues.md
 * ------------------------------------------------------------------------- */
/* IDD/IDCs Macros */
//Cellphone
#define MrFrost_IDD_Life_cell_phone 3000
//Main Background
#define MrFrost_IDC_CellPhone_MainBackground -1
//Pictures
#define MrFrost_IDC_CellPhone_Picture_Logo -1
#define MrFrost_IDC_CellPhone_Picture_Close -1
//Backgrounds
#define MrFrost_IDC_CellPhone_Background_Message -1
#define MrFrost_IDC_CellPhone_Background_Buttons -1
#define MrFrost_IDC_CellPhone_Background_Edit_Message -1
#define MrFrost_IDC_CellPhone_Background_Combo_Player -1
//Bars
#define MrFrost_IDC_CellPhone_Bar_Bottom -1
#define MrFrost_IDC_CellPhone_Bar_Top -1
#define MrFrost_IDC_CellPhone_Bar_Message -1
#define MrFrost_IDC_CellPhone_Bar_Buttons -1
//Titles
#define MrFrost_IDC_CellPhone_Title_Message 3002
#define MrFrost_IDC_CellPhone_Title_Main 3001
//Elements
#define MrFrost_IDC_CellPhone_Edit_Message 3003
#define MrFrost_IDC_CellPhone_Combo_Player 3004
//Buttons
#define MrFrost_IDC_CellPhone_Button_Button_SendMessage 3015
#define MrFrost_IDC_CellPhone_Button_Button_SendCop 3016
#define MrFrost_IDC_CellPhone_Button_Button_SendEMS 3022
#define MrFrost_IDC_CellPhone_Button_Button_SendToAdmin 3017
#define MrFrost_IDC_CellPhone_Button_Button_SendAsAdmin 3020
#define MrFrost_IDC_CellPhone_Button_Button_SendAsAdminAll 3021
#define MrFrost_IDC_CellPhone_Button_Button_SendCopAll 3023
#define MrFrost_IDC_CellPhone_Button_Button_SendAsMercenary 3024
#define MrFrost_IDC_CellPhone_Button_Close -1


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
class Life_cell_phone {
	idd = MrFrost_IDD_Life_cell_phone;
    name= "life_cell_phone";
    movingEnable = 0;
    enableSimulation = 1;
    onLoad = "[] spawn life_fnc_cellphone";

	class Controls {

        /*class Picture_Preview : MrFrost_RscPictureKeepAspect {
            idc = -1;
            MrFrost_POSITION(0,0,1920,1080)
            text = "pictures\GUI\PreviewBackground.jpg";
        };*/

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		class CellPhone_MainBackground : MrFrost_RscText {
			idc = MrFrost_IDC_CellPhone_MainBackground;
			MrFrost_POSITION(460,249,1000,582)
			colorBackground[] = {0.09412,0.09412,0.09412,1};
		};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		class CellPhone_Picture_Logo : MrFrost_RscPicture {
			idc = MrFrost_IDC_CellPhone_Picture_Logo;
			MrFrost_POSITION(857,304,512,512)
            text = "pictures\GUI\Logo_Mammut.paa";
		};

		class CellPhone_Picture_Close : MrFrost_RscPicture {
			idc = MrFrost_IDC_CellPhone_Picture_Close;
			MrFrost_POSITION(465,254,18,18)
            text= "\A3\ui_f\data\GUI\Rsc\RscDisplayArcadeMap\icon_exit_cross_ca.paa";
		};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		class CellPhone_Background_Message : MrFrost_RscText {
			idc = MrFrost_IDC_CellPhone_Background_Message;
			MrFrost_POSITION(780,308,665,508)
			colorBackground[] = {0,0,0,0.31};
		};

		class CellPhone_Background_Buttons : MrFrost_RscText {
			idc = MrFrost_IDC_CellPhone_Background_Buttons;
			MrFrost_POSITION(475,308,290,508)
			colorBackground[] = {0,0,0,0.31};
		};

		class CellPhone_Background_Edit_Message : MrFrost_RscText {
			idc = MrFrost_IDC_CellPhone_Background_Edit_Message;
			MrFrost_POSITION(780,308,665,508)
			colorBackground[] = {0,0,0,0.31};
		};

		class CellPhone_Background_Combo_Player : MrFrost_RscText {
			idc = MrFrost_IDC_CellPhone_Background_Combo_Player;
			MrFrost_POSITION(490,773,260,28)
			colorBackground[] = {0.09804,0.09804,0.09804,1};
		};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		class CellPhone_Bar_Bottom : MrFrost_RscText {
			idc = MrFrost_IDC_CellPhone_Bar_Bottom;
			MrFrost_POSITION(460,831,1000,7)
			colorBackground[] = {0.6902,0,0,1};
		};

		class CellPhone_Bar_Top : MrFrost_RscText {
			idc = MrFrost_IDC_CellPhone_Bar_Top;
			MrFrost_POSITION(460,242,1000,7)
			colorBackground[] = {0.6902,0,0,1};
		};

		class CellPhone_Bar_Message : MrFrost_RscText {
			idc = MrFrost_IDC_CellPhone_Bar_Message;
			MrFrost_POSITION(780,302,665,6)
			colorBackground[] = {0.6902,0,0,1};
		};

		class CellPhone_Bar_Buttons : MrFrost_RscText {
			idc = MrFrost_IDC_CellPhone_Bar_Buttons;
			MrFrost_POSITION(475,302,290,6)
			colorBackground[] = {0.6902,0,0,1};
		};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		class CellPhone_Title_Message : MrFrost_RscText {
			idc = MrFrost_IDC_CellPhone_Title_Message;
			MrFrost_POSITION(780,264,665,40)
			colorBackground[] = {0,0,0,0};
            colortext[] = {1,1,1,1};
            colorShadow[] = {0,0,0,0};
            style = 0x02;
            sizeex = 0.08;
            font = PuristaSemiBold;
			text = "Message";
			//text = "$STR_CELL_TextToSend";
		};

		class CellPhone_Title_Main : MrFrost_RscText {
			idc = MrFrost_IDC_CellPhone_Title_Main;
			MrFrost_POSITION(475,264,290,40)
			colorBackground[] = {0,0,0,0};
            colortext[] = {1,1,1,1};
            colorShadow[] = {0,0,0,0};
            style = 0x02;
            sizeex = 0.08;
            font = PuristaSemiBold;
			text = "Cellphone";
			//text = "$STR_CELL_Title";
		};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		class CellPhone_Edit_Message : MrFrost_RscEdit {
			idc = MrFrost_IDC_CellPhone_Edit_Message;
			MrFrost_POSITION(780,308,665,508)
			colorBackground[] = {0,0,0,0};
            colortext[] = {1,1,1,1};
            colorShadow[] = {0,0,0,0};
			maxChars = 1250;
            style = 16 + 512;
			lineSpacing = 1;
            sizeex = 0.048;
            text= "Enter your Message here...";
		};

		class CellPhone_Combo_Player : MrFrost_RscCombo {
			idc = MrFrost_IDC_CellPhone_Combo_Player;
			MrFrost_POSITION(490,773,260,28)
			colorBackground[] = {0,0,0,0};
            colortext[] = {1,1,1,1};
            colorShadow[] = {0,0,0,0};
            style = 512;
            sizeEx = 0.035;
		};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		class CellPhone_Button_Button_SendMessage : MrFrost_RscButton {
			idc = MrFrost_IDC_CellPhone_Button_Button_SendMessage;
			MrFrost_POSITION(490,323,260,28)
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
            text= "Send Message";
            //text = "$STR_CELL_TextMSGBtn";
            onButtonClick = "[] call TON_fnc_cell_textmsg";
		};

		class CellPhone_Button_Button_SendCop : MrFrost_RscButton {
			idc = MrFrost_IDC_CellPhone_Button_Button_SendCop;
			MrFrost_POSITION(490,366,260,28)
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
            text= "Send to Police";
            //text = "$STR_CELL_TextPolice";
            onButtonClick = "[] call TON_fnc_cell_textcop";
		};

		class CellPhone_Button_Button_SendEMS : MrFrost_RscButton {
			idc = MrFrost_IDC_CellPhone_Button_Button_SendEMS;
			MrFrost_POSITION(490,409,260,28)
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
            text= "Send to EMS";
			//text = "$STR_CELL_EMSRequest";
            onButtonClick = "[] call TON_fnc_cell_emsrequest";
		};

		class CellPhone_Button_Button_SendToAdmin : MrFrost_RscButton {
			idc = MrFrost_IDC_CellPhone_Button_Button_SendToAdmin;
			MrFrost_POSITION(490,452,260,28)
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
            text= "Send to Admin";
			//text = "$STR_CELL_TextAdmins";
            onButtonClick = "[] call TON_fnc_cell_textadmin";
		};

		class CellPhone_Button_Button_SendAsMercenary : MrFrost_RscButton {
			idc = MrFrost_IDC_CellPhone_Button_Button_SendAsMercenary;
			MrFrost_POSITION(490,495,260,28)
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
            text= "Send as Mercenary";
            onButtonClick = "";
		};

        class CellPhone_Button_Button_SendCopAll : MrFrost_RscButton {
			idc = MrFrost_IDC_CellPhone_Button_Button_SendCopAll;
			MrFrost_POSITION(490,495,260,28)
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
            text= "Send to all as Police";
            onButtonClick = "";
		};

		class CellPhone_Button_Button_SendAsAdmin : MrFrost_RscButton {
			idc = MrFrost_IDC_CellPhone_Button_Button_SendAsAdmin;
			MrFrost_POSITION(490,538,260,28)
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
            text= "Send as Admin";
			//text = "$STR_CELL_AdminMsg";
            onButtonClick = "[] call TON_fnc_cell_adminmsg";
		};

		class CellPhone_Button_Button_SendAsAdminAll : MrFrost_RscButton {
			idc = MrFrost_IDC_CellPhone_Button_Button_SendAsAdminAll;
			MrFrost_POSITION(490,581,260,28)
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
            text= "Send to all as Admin";
			//text = "$STR_CELL_AdminMSGAll";
            onButtonClick = "[] call TON_fnc_cell_adminmsgall";
		};

		class CellPhone_Button_Close : MrFrost_RscButton {
			idc = MrFrost_IDC_CellPhone_Button_Close;
			MrFrost_POSITION(465,254,18,18)
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

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	};
};
