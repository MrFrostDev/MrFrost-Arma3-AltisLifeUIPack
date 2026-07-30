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
 * progress.hpp - Progress bar and timer resources
 *
 * Part of    : Altis Life UI Pack (MrFrost, 2021) - archived, unmaintained.
 * Root class : life_progress / life_timer
 * IDD        : MrFrost_IDD_life_progress = 38200
 * Opened by  : "progressBar" cutRsc ["life_progress","PLAIN"];
 * Requires   : dialog/MrFrost_defines.hpp (MrFrost_POSITION and the
 *              MrFrost_Rsc* base classes) and dialog/common.hpp.
 *
 * Positions are authored against a 1920x1080 reference canvas.
 * MrFrost_POSITION(X,Y,W,H) rewrites those pixel values into
 * safezone-relative coordinates at preprocess time, so the numbers
 * below can be read directly as pixels on a 1080p screen.
 *
 * Note       : Both are RscTitles resources rather than dialogs; the stock
 *              life_fnc_progressBar drives control 38201/38202.
 *
 * Full IDD/IDC table : docs/dialog-reference.md
 * Before production  : docs/known-issues.md
 * ------------------------------------------------------------------------- */
 /* IDD/IDCs Macros */
 //Progress
#define MrFrost_IDD_life_progress 38200
//MainBackground
#define MrFrost_IDC_Progress_MainBackground -1
//ProgressBar
#define MrFrost_IDC_Progress_ProgressBar 38201
#define MrFrost_IDC_Progress_ProgressText 38202


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
class life_progress {
	idd = MrFrost_IDD_life_progress;
    name = "life_progress";
    fadein=0;
    duration = 99999999999;
    fadeout=0;
    movingEnable = 0;
    onLoad="uiNamespace setVariable ['life_progress',_this select 0]";
    objects[]={};

	class Controls {

		class Progress_MainBackground : MrFrost_RscText {
			idc = MrFrost_IDC_Progress_MainBackground;
			MrFrost_POSITION(496,30,928,25)
			colorBackground[] = {0.09804,0.09804,0.09804,1};
		};

////////////////////////////////////////////////////////////////////////////////

		class Progress_ProgressBar : MrFrost_RscProgress {
			idc = MrFrost_IDC_Progress_ProgressBar;
			MrFrost_POSITION(496,30,525,25)
			texture = "";
			shadow = 0;
			colorFrame[] = {0, 0, 0, 0};
			colorBackground[] = {0,0,0,0};
			colorBar[] = {0.6902,0,0,1};
		};

////////////////////////////////////////////////////////////////////////////////

		class Progress_ProgressText : MrFrost_RscText {
			idc = MrFrost_IDC_Progress_ProgressText;
			MrFrost_POSITION(496,30,928,25)
            font = PuristaSemiBold;
            sizeEx = 0.035;
			text = "Servicing Chopper (50%)...";
		};

////////////////////////////////////////////////////////////////////////////////

	};
};

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

class life_timer {
    name = "life_timer";
    idd = 38300;
    fadeIn = 1;
    duration = 99999999999;
    fadeout = 1;
    movingEnable = 0;
    onLoad = "uiNamespace setVariable ['life_timer',_this select 0]";
    objects[] = {};

    class controlsBackground {
        class TimerIcon: life_RscPicture {
            idc = -1;
            text = "\a3\ui_f\data\IGUI\RscTitles\MPProgress\timer_ca.paa";
            x = 0.00499997 * safezoneW + safezoneX;
            y = 0.291 * safezoneH + safezoneY;
            w = 0.04;
            h = 0.045;
        };

        class TimerText: Life_RscText {
            colorBackground[] = {0,0,0,0};
            idc = 38301;
            text = "";
            x = 0.0204688 * safezoneW + safezoneX;
            y = 0.2778 * safezoneH + safezoneY;
            w = 0.09125 * safezoneW;
            h = 0.055 * safezoneH;
        };
    };
};

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
