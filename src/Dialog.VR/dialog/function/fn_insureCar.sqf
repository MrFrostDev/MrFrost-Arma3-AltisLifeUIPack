#include "..\..\script_macros.hpp"
/*
    Original Author: Guit0x "Lintox"
    Modified by : Maxence for The Programmer Forum

    Description: Send information to insure a vehicle to server and pay
*/
disableSerialization;

if ((lbCurSel 2802) isEqualTo -1) exitWith {hint localize "STR_Global_NoSelection"};

_vehicle = lbData[2802,(lbCurSel 2802)];
_vehicle = (call compile format ["%1",_vehicle]) select 0;
_vehicleLife = _vehicle;
_vid = lbValue [2802,(lbCurSel 2802)];
_pid = getPlayerUID player;

if (isNil "_vehicle") exitWith {hint localize "STR_Garage_Selection_Error"};
if ((time - life_action_delay) < 1.5) exitWith {hint localize "STR_NOTF_ActionDelay"};

if !(isClass (missionConfigFile >> "LifeCfgVehicles" >> _vehicleLife)) then {
    _vehicleLife = "Default";
    diag_log format ["%1: LifeCfgVehicles class doesn't exist",_vehicle];
};

_multiplier = 1;
_purchasePrice = 0;
_price = M_CONFIG(getNumber,"LifeCfgVehicles",_vehicleLife,"price");
switch (playerSide) do {
    case civilian: {
        _multiplier = LIFE_SETTINGS(getNumber,"vehicle_insurance_multiplier_CIVILIAN");
        _purchasePrice = _price * LIFE_SETTINGS(getNumber,"vehicle_purchase_multiplier_CIVILIAN");
    };
    case west: {
        _multiplier = LIFE_SETTINGS(getNumber,"vehicle_insurance_multiplier_COP");
        _purchasePrice = _price * LIFE_SETTINGS(getNumber,"vehicle_purchase_multiplier_COP");
    };
    case independent: {
        _multiplier = LIFE_SETTINGS(getNumber,"vehicle_insurance_multiplier_MEDIC");
        _purchasePrice = _price * LIFE_SETTINGS(getNumber,"vehicle_purchase_multiplier_MEDIC");
    };
    case east: {
        _multiplier = LIFE_SETTINGS(getNumber,"vehicle_insurance_multiplier_OPFOR");
        _purchasePrice = _price * LIFE_SETTINGS(getNumber,"vehicle_purchase_multiplier_OPFOR");
    };
};

_insurancePrice = _purchasePrice * _multiplier;
if (!(_insurancePrice isEqualType 0) || _insurancePrice < 1) then {_insurancePrice = 500};
if (BANK < _insurancePrice) exitWith {hint format [(localize "STR_GNOTF_NotEnoughMoney"),[_insurancePrice] call life_fnc_numberText]};

if (life_HC_isActive) then {
    [_vid,_pid] remoteExecCall ["HC_fnc_insureCar",HC_Life];
} else {
    [_vid,_pid] remoteExecCall ["TON_fnc_insureCar",RSERV];
};

hint "You have insured your vehicle!";
BANK = BANK - _insurancePrice;
life_action_delay = time;
closeDialog 0;