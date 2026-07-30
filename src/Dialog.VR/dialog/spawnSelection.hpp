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
 * spawnSelection.hpp - Spawn point selection
 *
 * Part of    : Altis Life UI Pack (MrFrost, 2021) - archived, unmaintained.
 * Root class : life_spawn_selection
 * IDD        : MrFrost_IDD_SpawnMenu = 38500
 * Opened by  : createDialog "life_spawn_selection";
 * Requires   : dialog/MrFrost_defines.hpp (MrFrost_POSITION and the
 *              MrFrost_Rsc* base classes) and dialog/common.hpp.
 *
 * Positions are authored against a 1920x1080 reference canvas.
 * MrFrost_POSITION(X,Y,W,H) rewrites those pixel values into
 * safezone-relative coordinates at preprocess time, so the numbers
 * below can be read directly as pixels on a 1080p screen.
 *
 * Note       : Uses pictures\GUI\Spawn_Background.paa as a full-screen
 *              backdrop.
 *
 * Full IDD/IDC table : docs/dialog-reference.md
 * Before production  : docs/known-issues.md
 * ------------------------------------------------------------------------- */
/* IDD/IDCs Macros */
#define MrFrost_IDD_SpawnMenu 38500
//Main Background
#define MrFrost_IDC_SpawnMenu_MainBackground_Image -1
#define MrFrost_IDC_SpawnMenu_MainBackground -1
#define MrFrost_IDC_SpawnMenu_Bar_Top -1
#define MrFrost_IDC_SpawnMenu_Bar_Bottom -1
#define MrFrost_IDC_SpawnMenu_Logo -1
//Elements Background
#define MrFrost_IDC_SpawnMenu_Background_Spawn_List -1
#define MrFrost_IDC_SpawnMenu_Background_Spawn_Map -1
#define MrFrost_IDC_SpawnMenu_Bar_Spawn_List -1
#define MrFrost_IDC_SpawnMenu_Bar_Spawn_Map -1
//Elements Titles
#define MrFrost_IDC_SpawnMenu_Spawn_List_Title -1
#define MrFrost_IDC_SpawnMenu_Spawn_Map_Title 38501
//Elements
#define MrFrost_IDC_SpawnMenu_Spawn_Button -1
#define MrFrost_IDC_SpawnMenu_Spawn_List 38510
#define MrFrost_IDC_SpawnMenu_Spawn_Map 38502


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
class life_spawn_selection {
    idd = MrFrost_IDD_SpawnMenu;
    movingEnable = 0;
    enableSimulation = 1;

    class Controls {

/////////////////////////////////////////////////////////////////////////////

        class SpawnMenu_MainBackground_Image : MrFrost_RscPictureKeepAspect {
            idc = MrFrost_IDC_SpawnMenu_MainBackground_Image;
            MrFrost_POSITION(0,0,1920,1080)
            text = "pictures\GUI\Spawn_Background.paa";
        };

/////////////////////////////////////////////////////////////////////////////

        class SpawnMenu_MainBackground : MrFrost_RscText {
			idc = MrFrost_IDC_SpawnMenu_MainBackground;
			MrFrost_POSITION(414,249,1093,582)
			colorBackground[] = {0.094,0.094,0.094,1};
		};

        class SpawnMenu_Bar_Bottom : MrFrost_RscText {
			idc = MrFrost_IDC_SpawnMenu_Bar_Bottom;
			MrFrost_POSITION(414,831,1093,7)
			colorBackground[] = {0.69,0,0,1};
		};

        class SpawnMenu_Bar_Top : MrFrost_RscText {
			idc = MrFrost_IDC_SpawnMenu_Bar_Top;
			MrFrost_POSITION(414,242,1093,7)
			colorBackground[] = {0.69,0,0,1};
		};

/////////////////////////////////////////////////////////////////////////////

       class Logo : MrFrost_RscPictureKeepAspect {
            idc = MrFrost_IDC_ZMenu_Logo;
            MrFrost_POSITION(368,355,412,412)
            text = "pictures\GUI\Logo_Mammut.paa";
        };

/////////////////////////////////////////////////////////////////////////////

        class SpawnMenu_Background_Spawn_List : MrFrost_RscText {
			idc = MrFrost_IDC_SpawnMenu_Background_Spawn_List;
			MrFrost_POSITION(429,307,290,464)
			colorBackground[] = {0,0,0,0.31};
		};

        class SpawnMenu_Background_Spawn_Map : MrFrost_RscText {
			idc = MrFrost_IDC_SpawnMenu_Background_Spawn_Map;
			MrFrost_POSITION(734,307,758,507)
			colorBackground[] = {0,0,0,0.31};
		};

        class SpawnMenu_Bar_Spawn_List : MrFrost_RscText {
			idc = MrFrost_IDC_SpawnMenu_Bar_Spawn_List;
			MrFrost_POSITION(429,301,290,6)
			colorBackground[] = {0.69,0,0,1};
		};

        class SpawnMenu_Bar_Spawn_Map : MrFrost_RscText {
			idc = MrFrost_IDC_SpawnMenu_Bar_Spawn_Map;
			MrFrost_POSITION(734,301,758,6)
			colorBackground[] = {0.69,0,0,1};
		};

/////////////////////////////////////////////////////////////////////////////

        class SpawnMenu_Spawn_List : MrFrost_RscListBox /*MrFrost_RscListNBox*/ {
			idc = MrFrost_IDC_SpawnMenu_Spawn_List;
			MrFrost_POSITION(429,307,290,464)
			colorBackground[] = {0,0,0,0};
            colortext[] = {1,1,1,1};
            colorShadow[] = {0,0,0,0};
            sizeEx = 0.045;/*
            coloumns[] = {0,0,0.9};
            drawSideArrows = 0;
            idcLeft = -1;
            idcRight = -1;
            rowHeight = 0.050;*/
            onLBSelChanged = "_this call life_fnc_spawnPointSelected;";
		};

        class SpawnMenu_Spawn_Map : MrFrost_RscMapControl {
			idc = MrFrost_IDC_SpawnMenu_Spawn_Map;
			MrFrost_POSITION(734,307,758,507)
            maxSatelliteAlpha = 0.75;//0.75;
            alphaFadeStartScale = 1.15;//0.15;
            alphaFadeEndScale = 1.29;//0.29;
		};

/////////////////////////////////////////////////////////////////////////////

        class SpawnMenu_Spawn_List_Title : MrFrost_RscText {
			idc = MrFrost_IDC_SpawnMenu_Spawn_List_Title;
			MrFrost_POSITION(429,263,290,40)
			colorBackground[] = {0,0,0,0};
            colortext[] = {1,1,1,1};
            colorShadow[] = {0,0,0,0};
            style = 0x02;
            sizeex = 0.08;
            font = PuristaSemiBold;
            text = "Spawnpoints";
            //text = "$STR_Spawn_Title";
		};

        class SpawnMenu_Spawn_Map_Title : MrFrost_RscText {
			idc = MrFrost_IDC_SpawnMenu_Spawn_Map_Title;
			MrFrost_POSITION(734,263,758,40)
			colorBackground[] = {0,0,0,0};
            colortext[] = {1,1,1,1};
            colorShadow[] = {0,0,0,0};
            style = 0x02;
            sizeex = 0.08;
            font = PuristaSemiBold;
            text = "Spawnpoint XYZ Test Test";
		};

/////////////////////////////////////////////////////////////////////////////

        class SpawnMenu_Spawn_Button : MrFrost_RscButton {
			idc = MrFrost_IDC_SpawnMenu_Spawn_Button;
			MrFrost_POSITION(429,786,290,28)
			colorBackground[] = {0.69,0,0,1};
            colortext[] = {1,1,1,1};
			colorBackgroundActive[] = {0.153,0.584,0,1};
			colorFocused[] = {0.69,0,0,1};
            colorShadow[] = {0,0,0,0};
            soundEnter[] = {"\A3\ui_f\data\sound\RscButton\soundEnter",0.09,1};
            soundPush[] = {"\A3\ui_f\data\sound\RscButton\soundPush",0.09,1};
            soundClick[] = {"\A3\ui_f\data\sound\RscButton\soundClick",0.09,1};
            soundEscape[] = {"\A3\ui_f\data\sound\RscButton\soundEscape",0.09,1};
            font = PuristaSemiBold;
            sizeEx = 0.035;
            //text = "$STR_Spawn_Spawn";
            text= "Spawn";
            onButtonClick = "[] call life_fnc_spawnConfirm";
		};
    };
};
