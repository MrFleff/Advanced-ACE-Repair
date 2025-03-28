#include "..\script_component.hpp"
params ["_vehicle"];
private["_vehicle"];

_classname = typeOf _vehicle;

closeDialog 2;
sleep 0.001;
createDialog "advrepair_dialog_MinorParts";

_Display = findDisplay 1665;
_lnb = _Display displayCtrl 1400;
_lnbl = _Display displayCtrl 1401;

_vehiclevar = _vehicle getVariable "HitpointsMajorVar";
vehsel = _vehicle;
if (isNil "_vehiclevar") then {
    _vehiclevar = [vehsel] call FUNC(guiAddVehVar);
};
_MajorHitPoints = _vehiclevar select 0;
_AllHitpoints = (getAllHitPointsDamage _vehicle) select 0;

_VehEngineSize      = getNumber (configFile >> "CfgVehicles" >> _classname >> "FL_advrepair" >> "vehicleenginesize");
_VehFuelTankSize    = getNumber (configFile >> "CfgVehicles" >> _classname >> "FL_advrepair" >> "vehiclefueltanksize");
_VehArmor           = getNumber (configFile >> "CfgVehicles" >> _classname >> "FL_advrepair" >> "vehiclearmor");
_VehEngine          = getText   (configFile >> "CfgVehicles" >> _classname >> "FL_advrepair" >> "vehicleengine");

/*
{
    _Chp = _x select 1
    _Cname = _x select 0
    _lnb lnbAddRow [_Chp,_Cname];
} foreach
*/

_lnbl lnbAddRow ["Part Health", "Hitpoint Name", "%HP per Repair"];
{
    _y = _foreachindex;
    if !(_x in _MajorHitPoints) then {
        _rep = GVAR(DefaultRepair);
        if (("hull" in (toLowerANSI _x)) || ("body" in (toLowerANSI _x))) then {
            switch (_VehArmor) do {
                case 0: {_rep = GVAR(Hull0)};
                case 1: {_rep = GVAR(Hull1)};
                case 2: {_rep = GVAR(Hull2)};
            };
        };
        if ("era" in (toLowerANSI _x)) then {
            _rep = GVAR(ERARep);
        };
        _dmg = format ["%1%% HP",round((100 - 100 * (_vehicle getHitPointDamage _x)) * (10 ^ 2)) / (10 ^ 2)];
        _repf = format ["+%1%% HP", _rep];
        _lnb lnbAddRow[_dmg, _x, _repf];
    };
} forEach _AllHitpoints;
_lnb lnbSetData [[0,3],[_vehicle] call BIS_fnc_objectVar];

/*
{
    _dmg = format ["%1%% HP",round((100 - 100 * (_vehicle getHitPointDamage _x)) * (10 ^ 2)) / (10 ^ 2)];
    _lnb lnbAddRow[_dmg, _x];
} forEach _MajorHitPoints;
*/

vehsel = _vehicle;
_ButtonMain = _Display displayCtrl 1601;
_ButtonMain ctrlAddEventHandler ["ButtonClick", {["",vehsel] spawn FUNC(openDialogMain)}];
_ButtonMaj = _Display displayCtrl 1602;
_ButtonMaj ctrlAddEventHandler ["ButtonClick", {[vehsel] spawn FUNC(openDialogMajor)}];
