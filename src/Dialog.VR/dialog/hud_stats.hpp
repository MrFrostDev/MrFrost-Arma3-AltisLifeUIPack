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
 * hud_stats.hpp - Player HUD (health / food / water)
 *
 * Part of    : Altis Life UI Pack (MrFrost, 2021) - archived, unmaintained.
 * Root class : playerHUD
 * IDD        : MrFrost_IDD_PlayerHUD = -1
 * Opened by  : ("playerHUD" cutRsc ["playerHUD","PLAIN"]) - a resource, not a dialog
 * Requires   : dialog/MrFrost_defines.hpp (MrFrost_POSITION and the
 *              MrFrost_Rsc* base classes) and dialog/common.hpp.
 *
 * Positions are authored against a 1920x1080 reference canvas.
 * MrFrost_POSITION(X,Y,W,H) rewrites those pixel values into
 * safezone-relative coordinates at preprocess time, so the numbers
 * below can be read directly as pixels on a 1080p screen.
 *
 * Note       : idd is -1 by design; the display is reached through
 *              uiNamespace getVariable "playerHUD" (see the LIFEctrl macro in
 *              script_macros.hpp).
 *
 * Full IDD/IDC table : docs/dialog-reference.md
 * Before production  : docs/known-issues.md
 * ------------------------------------------------------------------------- */
/* IDD/IDCs Macros */
#define MrFrost_IDD_PlayerHUD -1
//Main Background
#define MrFrost_IDC_PlayerHUD_MainBackground -1
#define MrFrost_IDC_PlayerHUD_Bar_Top -1
//Background Elements
#define MrFrost_IDC_PlayerHUD_Background_Life -1
#define MrFrost_IDC_PlayerHUD_Background_Food -1
#define MrFrost_IDC_PlayerHUD_Background_Water -1
//Elements
#define MrFrost_IDC_PlayerHUD_Life_Bar 2201
#define MrFrost_IDC_PlayerHUD_Food_Bar 2200
#define MrFrost_IDC_PlayerHUD_Water_Bar 2202
#define MrFrost_IDC_PlayerHUD_Life_Text 1201
#define MrFrost_IDC_PlayerHUD_Food_Text 1200
#define MrFrost_IDC_PlayerHUD_Water_Text 1202

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
class playerHUD {
    idd = MrFrost_IDD_PlayerHUD;
    duration = 10e10;
    movingEnable = 0;
    fadein = 0;
    fadeout = 0;
    name = "playerHUD";
    onLoad = "uiNamespace setVariable ['playerHUD',_this select 0]";
    objects[] = {};
    controls[] = {
        PlayerHUD_MainBackground,
        PlayerHUD_Bar_Top,
        PlayerHUD_Background_Life,
        PlayerHUD_Background_Food,
        PlayerHUD_Background_Water,
        PlayerHUD_Life,
        PlayerHUD_Food,
        PlayerHUD_Water,
        PlayerHUD_Life_Text,
        PlayerHUD_Food_Text,
        PlayerHUD_Water_Text
    };

/////////////////////////////////////////////////////

    class PlayerHUD_MainBackground : MrFrost_RscText {
        idc = MrFrost_IDC_PlayerHUD_MainBackground;
        MrFrost_POSITION(1699,994,214,79)
        colorBackground[] = {0.055,0.055,0.055,0.8};
    };

    class PlayerHUD_Bar_Top : MrFrost_RscText {
        idc = MrFrost_IDC_PlayerHUD_Bar_Top;
        MrFrost_POSITION(1699,988,214,6)
        colorBackground[] = {0.69,0,0,1};
    };

/////////////////////////////////////////////////////

    class PlayerHUD_Background_Life : MrFrost_RscText {
        idc = MrFrost_IDC_PlayerHUD_Background_Life;
        MrFrost_POSITION(1708,1000,196,16)
        colorBackground[] = {0.098,0.098,0.098,1};
    };

    class PlayerHUD_Background_Food : MrFrost_RscText {
        idc = MrFrost_IDC_PlayerHUD_Background_Food;
        MrFrost_POSITION(1708,1024,196,16)
        colorBackground[] = {0.098,0.098,0.098,1};
    };

    class PlayerHUD_Background_Water : MrFrost_RscText {
        idc = MrFrost_IDC_PlayerHUD_Background_Water;
        MrFrost_POSITION(1708,1047,196,16)
        colorBackground[] = {0.098,0.098,0.098,1};
    };

/////////////////////////////////////////////////////

    class PlayerHUD_Life : MrFrost_RscProgress {
        idc = MrFrost_IDC_PlayerHUD_Life;
        MrFrost_POSITION(1708,1000,196,16)
        colorBar[] = {0.69,0,0,1};
        colorFrame[] = {0,0,0,0};
    };

    class PlayerHUD_Food : MrFrost_RscProgress {
        idc = MrFrost_IDC_PlayerHUD_Food;
        MrFrost_POSITION(1708,1024,196,16)
        colorBar[] = {0.153,0.584,0,1};
        colorFrame[] = {0,0,0,0};
    };

    class PlayerHUD_Water : MrFrost_RscProgress {
        idc = MrFrost_IDC_PlayerHUD_Water;
        MrFrost_POSITION(1708,1047,196,16)
        colorBar[] = {0,0.522,0.824,1};
        colorFrame[] = {0,0,0,0};
    };

/////////////////////////////////////////////////////

    class PlayerHUD_Life_Text : MrFrost_RscText {
        idc = MrFrost_IDC_PlayerHUD_Life_Text;
        MrFrost_POSITION(1708,1000,196,16)
        colorBackground[] = {0,0,0,0};
        colortext[] = {1,1,1,1};
        colorShadow[] = {0,0,0,0};
        style = 0x02;
        sizeex = 0.025;
        font = PuristaSemiBold;
        text = "Health";
    };

    class PlayerHUD_Food_Text : MrFrost_RscText {
        idc = MrFrost_IDC_PlayerHUD_Food_Text;
        MrFrost_POSITION(1708,1024,196,16)
        colorBackground[] = {0,0,0,0};
        colortext[] = {1,1,1,1};
        colorShadow[] = {0,0,0,0};
        style = 0x02;
        sizeex = 0.025;
        font = PuristaSemiBold;
        text = "Food";
    };

    class PlayerHUD_Water_Text : MrFrost_RscText {
        idc = MrFrost_IDC_PlayerHUD_Water_Text;
        MrFrost_POSITION(1708,1047,196,16)
        colorBackground[] = {0,0,0,0};
        colortext[] = {1,1,1,1};
        colorShadow[] = {0,0,0,0};
        style = 0x02;
        sizeex = 0.025;
        font = PuristaSemiBold;
        text = "Water";
    };
};
