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
 * deathScreen.hpp - Death screen overlay
 *
 * Part of    : Altis Life UI Pack (MrFrost, 2021) - archived, unmaintained.
 * Root class : DeathScreen
 * IDD        : MrFrost_IDD_DeathScreen = 7300
 * Opened by  : createDialog "DeathScreen";
 * Requires   : dialog/MrFrost_defines.hpp (MrFrost_POSITION and the
 *              MrFrost_Rsc* base classes) and dialog/common.hpp.
 *
 * Positions are authored against a 1920x1080 reference canvas.
 * MrFrost_POSITION(X,Y,W,H) rewrites those pixel values into
 * safezone-relative coordinates at preprocess time, so the numbers
 * below can be read directly as pixels on a 1080p screen.
 *
 * Note       : Purely decorative blood/dust layers plus a respawn timer; no
 *              simulation is paused by the dialog itself.
 *
 * Full IDD/IDC table : docs/dialog-reference.md
 * Before production  : docs/known-issues.md
 * ------------------------------------------------------------------------- */
/* IDD/IDCs Macros */
//Deathscreen
#define MrFrost_IDD_DeathScreen 7300
//Main
#define MrFrost_IDC_DeathScreen_Picture_Dust -1
#define MrFrost_IDC_DeathScreen_Picture_Blood_Right -1
#define MrFrost_IDC_DeathScreen_Picture_Blood_Left -1
#define MrFrost_IDC_DeathScreen_Picture_Blood_Up -1
#define MrFrost_IDC_DeathScreen_Picture_Blood_Down -1
#define MrFrost_IDC_DeathScreen_MainBackground -1
#define MrFrost_IDC_DeathScreen_BarTop -1
//Things
#define MrFrost_IDC_DeathScreen_Background_Medics_Online 7304
#define MrFrost_IDC_DeathScreen_Picture_Medics_Online -1
//Titles
#define MrFrost_IDC_DeathScreen_Title_DeathCount 7301
//Buttons
#define MrFrost_IDC_DeathScreen_Button_Help 7303
#define MrFrost_IDC_DeathScreen_Button_Respawn 7302

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
class DeathScreen {
	idd = MrFrost_IDD_DeathScreen;
    name = "Life_Death_Screen";
    movingEnable = 0;
    enableSimulation = 1;

	class Controls {

/////////////////////////////////////////////////////////////////////////

		/*class Picture_Preview : MrFrost_RscPictureKeepAspect {
            idc = -1;
            MrFrost_POSITION(0,0,1920,1080)
            text = "pictures\GUI\PreviewBackground.jpg";
        };*/

        class DeathScreen_Picture_Dust : MrFrost_RscPictureKeepAspect {
			idc = MrFrost_IDC_DeathScreen_Picture_Dust;
			MrFrost_POSITION(-120,0,2160,1080)
			colorBackground[] = {0,0,0,0};
            text= "\A3\ui_f\data\IGUI\RscTitles\HealthTextures\dust_lower_ca.paa";
		};

		class DeathScreen_Picture_Blood_Right : MrFrost_RscPictureKeepAspect {
			idc = MrFrost_IDC_DeathScreen_Picture_Blood_Right;
			MrFrost_POSITION(1380,0,540,1080)
			colorBackground[] = {0,0,0,0};
            text= "\A3\ui_f\data\IGUI\RscTitles\HealthTextures\blood_right_ca.paa";
		};

		class DeathScreen_Picture_Blood_Left : MrFrost_RscPictureKeepAspect {
			idc = MrFrost_IDC_DeathScreen_Picture_Blood_Left;
			MrFrost_POSITION(0,0,540,1080)
			colorBackground[] = {0,0,0,0};
            text= "\A3\ui_f\data\IGUI\RscTitles\HealthTextures\blood_left_ca.paa";
		};

		class DeathScreen_Picture_Blood_Up : MrFrost_RscPictureKeepAspect {
			idc = MrFrost_IDC_DeathScreen_Picture_Blood_Up;
			MrFrost_POSITION(0,0,1920,960)
			colorBackground[] = {0,0,0,0};
            text= "\A3\ui_f\data\IGUI\RscTitles\HealthTextures\blood_up_ca.paa";
		};

		class DeathScreen_Picture_Blood_Down : MrFrost_RscPictureKeepAspect {
			idc = MrFrost_IDC_DeathScreen_Picture_Blood_Down;
			MrFrost_POSITION(0,120,1920,960)
			colorBackground[] = {0,0,0,0};
            text= "\A3\ui_f\data\IGUI\RscTitles\HealthTextures\blood_down_ca.paa";
		};

/////////////////////////////////////////////////////////////////////////

		class DeathScreen_MainBackground : MrFrost_RscText {
			idc = MrFrost_IDC_DeathScreen_MainBackground;
			MrFrost_POSITION(647,998,626,58)
			colorBackground[] = {0.09412,0.09412,0.09412,1};
		};

		class DeathScreen_BarTop : MrFrost_RscText {
			idc = MrFrost_IDC_DeathScreen_BarTop;
			MrFrost_POSITION(647,991,626,7)
			colorBackground[] = {0.6902,0,0,1};
		};

/////////////////////////////////////////////////////////////////////////

		class DeathScreen_Background_Medics_Online : MrFrost_RscText {
			idc = MrFrost_IDC_DeathScreen_Background_Medics_Online;
			MrFrost_POSITION(662,1013,28,28)
			colorBackground[] = {0.1098,0.6902,0,1};
		};

		class DeathScreen_Picture_Medics_Online : MrFrost_RscPictureKeepAspect {
			idc = MrFrost_IDC_DeathScreen_Picture_Medics_Online;
			MrFrost_POSITION(662,1013,28,28)
			colorBackground[] = {0,0,0,0};
            text = "\A3\ui_f\data\IGUI\RscIngameUI\RscUnitInfo\icon_cross_ca.paa";
		};


/////////////////////////////////////////////////////////////////////////

		class DeathScreen_Title_DeathCount : MrFrost_RscText {
			idc = MrFrost_IDC_DeathScreen_Title_DeathCount;
			MrFrost_POSITION(647,953,626,40)
			colorBackground[] = {0,0,0,0};
            colortext[] = {1,1,1,1};
            colorShadow[] = {0,0,0,0};
            style = 0x02;
            sizeex = 0.08;
            font = PuristaSemiBold;
            text = "12:34";
		};

/////////////////////////////////////////////////////////////////////////

		class DeathScreen_Button_Help : MrFrost_RscButton {
			idc = MrFrost_IDC_DeathScreen_Button_Help;
			MrFrost_POSITION(698,1013,254,28)
			colorBackground[] = {0.1098,0.6902,0,1};
            colortext[] = {1,1,1,1};
			colorBackgroundActive[] = {1,0.435,0,1};
			colorFocused[] = {0.1098,0.6902,0,1};
            colorShadow[] = {0,0,0,0};
            soundEnter[] = {"\A3\ui_f\data\sound\RscButton\soundEnter",0.09,1};
            soundPush[] = {"\A3\ui_f\data\sound\RscButton\soundPush",0.09,1};
            soundClick[] = {"\A3\ui_f\data\sound\RscButton\soundClick",0.09,1};
            soundEscape[] = {"\A3\ui_f\data\sound\RscButton\soundEscape",0.09,1};
            font = PuristaSemiBold;
            sizeEx = 0.035;
            default = 1;
            text= "Call Medic";
            onButtonClick = "[] call life_fnc_requestMedic;";
		};

		class DeathScreen_Button_Respawn : MrFrost_RscButton {
			idc = MrFrost_IDC_DeathScreen_Button_Respawn;
			MrFrost_POSITION(968,1013,290,28)
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
            text= "Give up";
            onButtonClick = "closeDialog 0; life_respawned = true; [] call life_fnc_spawnMenu;";
		};
	};
};
