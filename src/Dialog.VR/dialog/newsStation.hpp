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
 * newsStation.hpp - News station broadcast
 *
 * Part of    : Altis Life UI Pack (MrFrost, 2021) - archived, unmaintained.
 * Root class : life_news_broadcast
 * IDD        : MrFrost_IDD_Trunk = 100100
 * Opened by  : createDialog "life_news_broadcast";
 * Requires   : dialog/MrFrost_defines.hpp (MrFrost_POSITION and the
 *              MrFrost_Rsc* base classes) and dialog/common.hpp.
 *
 * Positions are authored against a 1920x1080 reference canvas.
 * MrFrost_POSITION(X,Y,W,H) rewrites those pixel values into
 * safezone-relative coordinates at preprocess time, so the numbers
 * below can be read directly as pixels on a 1080p screen.
 *
 * Note       : The IDD macro is named MrFrost_IDD_Trunk, which redefines the
 *              macro of the same name from trunk.hpp. Left as-is; see
 *              known-issues.md.
 *
 * Full IDD/IDC table : docs/dialog-reference.md
 * Before production  : docs/known-issues.md
 * ------------------------------------------------------------------------- */
 /* IDD/IDCs Macros */
#define MrFrost_IDD_Trunk 100100
//Main Background
#define MrFrost_IDC_News_MainBackground -1
#define MrFrost_IDC_News_Bar_Bottom -1
#define MrFrost_IDC_News_Bar_Top -1
#define MrFrost_IDC_News_Button_Close_Image -1
//Parts Background
#define MrFrost_IDC_News_Background_Header -1
#define MrFrost_IDC_News_Background_Text -1
#define MrFrost_IDC_News_Background_Buttons -1
#define MrFrost_IDC_News_Bar_Header -1
#define MrFrost_IDC_News_Bar_Text -1
#define MrFrost_IDC_News_Bar_Buttons -1
//Titles and Text
#define MrFrost_IDC_News_Title_Main -1
#define MrFrost_IDC_News_Text_Price 100103
#define MrFrost_IDC_News_Text_Next 184838
//Elements Background
#define MrFrost_IDC_News_Background_Header_Edit -1
//Elements
#define MrFrost_IDC_News_Header_Edit 100101
#define MrFrost_IDC_News_Text_Edit 100102
//Buttons
#define MrFrost_IDC_News_Button_Send 100104
//Main Buttons
#define MrFrost_IDC_News_Button_Close -1

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
class life_news_broadcast {
	idd = MrFrost_IDD_Trunk;
    name= "life_news_broadcast";
    movingEnable = 0;
    enableSimulation = 1;

    class Controls {

        class Picture_Preview : MrFrost_RscPicture {
            idc = -1;
            MrFrost_POSITION(0,0,1920,1080)
            text = "pictures\GUI\PreviewBackground.jpg";
        };

////////////////////////////////////////////////////////////////////////////////

        class News_MainBackground : MrFrost_RscText {
			idc = MrFrost_IDC_News_MainBackground;
			MrFrost_POSITION(718,249,484,582)
			colorBackground[] = {0.094,0.094,0.094,1};
		};

        class News_Bar_Bottom : MrFrost_RscText {
			idc = MrFrost_IDC_News_Bar_Bottom;
			MrFrost_POSITION(718,831,484,7)
			colorBackground[] = {0.69,0,0,1};
		};

        class News_Bar_Top : MrFrost_RscText {
			idc = MrFrost_IDC_News_Bar_Top;
			MrFrost_POSITION(718,242,484,7)
			colorBackground[] = {0.69,0,0,1};
		};

////////////////////////////////////////////////////////////////////////////////

        class News_Background_Header : MrFrost_RscText {
			idc = MrFrost_IDC_News_Background_Header;
			MrFrost_POSITION(755,308,410,38)
			colorBackground[] = {0,0,0,0.31};
		};

        class News_Background_Text : MrFrost_RscText {
			idc = MrFrost_IDC_News_Background_Text;
			MrFrost_POSITION(755,367,410,284)
			colorBackground[] = {0,0,0,0.31};
		};

        class News_Background_Buttons : MrFrost_RscText {
			idc = MrFrost_IDC_News_Background_Buttons;
			MrFrost_POSITION(755,672,410,144)
			colorBackground[] = {0,0,0,0.31};
		};

////////////////////////////////////////////////////////////////////////////////

        class News_Bar_Header : MrFrost_RscText {
			idc = MrFrost_IDC_News_Bar_Header;
			MrFrost_POSITION(755,302,410,6)
			colorBackground[] = {0.69,0,0,1};
		};

        class News_Bar_Text : MrFrost_RscText {
			idc = MrFrost_IDC_News_Bar_Text;
			MrFrost_POSITION(755,361,410,6)
			colorBackground[] = {0.69,0,0,1};
		};

        class News_Bar_Buttons : MrFrost_RscText {
			idc = MrFrost_IDC_News_Bar_Buttons;
			MrFrost_POSITION(755,666,410,6)
			colorBackground[] = {0.69,0,0,1};
		};

////////////////////////////////////////////////////////////////////////////////

        class News_Text_Price : MrFrost_RscText {
			idc = MrFrost_IDC_News_Text_Price;
			MrFrost_POSITION(770,687,380,28)
            font = PuristaSemiBold;
            sizeEx = 0.035;
            text = "The Message will cost: 12345678$";
		};

		class News_Text_Next : MrFrost_RscText {
			idc = MrFrost_IDC_News_Text_Next;
			MrFrost_POSITION(770,730,380,28)
            font = PuristaSemiBold;
            sizeEx = 0.035;
            text = "Broadcast available: YES";
		};

////////////////////////////////////////////////////////////////////////////////


        class News_Title_Main : MrFrost_RscText {
			idc = MrFrost_IDC_News_Title_Main;
			MrFrost_POSITION(755,264,410,40)
			colorBackground[] = {0,0,0,0};
            colortext[] = {1,1,1,1};
            colorShadow[] = {0,0,0,0};
            style = 0x02;
            sizeex = 0.08;
            font = PuristaSemiBold;
            //text = "$STR_News_DialogTitle";
            text = "AAN News Station";
		};

////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////

        class News_Header_Edit : MrFrost_RscEdit {
			idc = MrFrost_IDC_News_Header_Edit;
			MrFrost_POSITION(755,308,410,38)
			colorBackground[] = {0,0,0,0};
            colortext[] = {1,1,1,1};
            colorShadow[] = {0,0,0,0};
            style = 512;
            maxChars = 50;
            sizeex = 0.048;
            text= "Enter your Header here...";
		};

        class News_Text_Edit : MrFrost_RscEdit {
			idc = MrFrost_IDC_News_Text_Edit;
			MrFrost_POSITION(755,367,410,284)
			colorBackground[] = {0,0,0,0};
            colortext[] = {1,1,1,1};
            colorShadow[] = {0,0,0,0};
			maxChars = 350;
            style = 16 + 512;
			lineSpacing = 1;
            sizeex = 0.048;
            text= "Enter your Message here...";
		};

////////////////////////////////////////////////////////////////////////////////

        class News_Button_Send : MrFrost_RscButton {
			idc = MrFrost_IDC_News_Button_Send;
			MrFrost_POSITION(770,773,380,28)
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
            text= "Broadcast";
            onButtonClick = "[] call Life_fnc_vehTakeItem;";
		};

////////////////////////////////////////////////////////////////////////////////

        class News_Button_Close_Image : MrFrost_RscPictureKeepAspect {
			idc = MrFrost_IDC_News_Button_Close_Image;
			MrFrost_POSITION(723,254,18,18)
			colorBackground[] = {0,0,0,0};
            text= "\A3\ui_f\data\GUI\Rsc\RscDisplayArcadeMap\icon_exit_cross_ca.paa";
		};

        class News_Button_Close : MrFrost_RscButton {
			idc = MrFrost_IDC_News_Button_Close;
			MrFrost_POSITION(723,254,18,18)
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
