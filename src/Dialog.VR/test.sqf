#include "script_macros.hpp"

#define MrFrost_Esc_POSITION(X,Y,W,H) \
	x = #((((X * (getResolution select 0)) / 1920) * safeZoneW) / (getResolution select 0) + safeZoneX), \
	y = #((((Y * (getResolution select 1)) / 1080) * safeZoneH) / (getResolution select 1) + safeZoneY), \
	w = #((((W * (getResolution select 0)) / 1920) * safeZoneW) / (getResolution select 0)), \
	h = #((((H * (getResolution select 1)) / 1080) * safeZoneH) / (getResolution select 1))


disableSerialization;



    private _abortButton = CONTROL(49,104);
    private _respawnButton = CONTROL(49,1010);
    private _fieldManual = CONTROL(49,122);
    private _saveButton = CONTROL(49,103);