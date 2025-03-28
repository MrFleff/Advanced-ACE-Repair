#include "..\script_component.hpp"
params ["_vehicle"];
private["_vehicle"];

_classname = typeOf _vehicle;

closeDialog 2;
sleep 0.001;
createDialog "advrepair_dialog_MajorParts";

_Display = findDisplay 1665;
_lnb = _Display displayCtrl 1400;
_lnbl = _Display displayCtrl 1401;

_vehiclevar = _vehicle getVariable "HitpointsMajorVar";
vehsel = _vehicle;
if (isNil "_vehiclevar") then {
    _vehiclevar = [vehsel] call FUNC(guiAddVehVar);
};

_MajorHitPoints = _vehiclevar select 0;
_MajorHitPointsPart = _vehiclevar select 1;
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

_lnbl lnbAddRow ["Part Health", "Hitpoint Name", "Linked Part Object"];
{
    _partname = _MajorHitPointsPart select _forEachIndex;
    _dmg = format ["%1%% HP",round((100 - 100 * (_vehicle getHitPointDamage _x)) * (10 ^ 2)) / (10 ^ 2)];
    _lnb lnbAddRow[_dmg, _x,_partname];
} forEach _MajorHitPoints;
_lnb lnbSetData [[0,0],str _vehicle];

/* Get Minor Parts
{
    if !(_x in _MajorHitPoints) then {
        _dmg = format ["%1%% HP",round((100 - 100 * (_vehicle getHitPointDamage _x)) * (10 ^ 2)) / (10 ^ 2)];
        _lnb lnbAddRow[_dmg, _x];
    };
} forEach _AllHitpoints;
*/

/*
{
    _dmg = format ["%1%% HP",round((100 - 100 * (_vehicle getHitPointDamage _x)) * (10 ^ 2)) / (10 ^ 2)];
    _lnb lnbAddRow[_dmg, _x];
} forEach _MajorHitPoints;
*/

_ButtonMin = _Display displayCtrl 1601;
_ButtonMin ctrlAddEventHandler ["ButtonClick", {[vehsel] spawn FUNC(openDialogMinor)}];
_ButtonMain = _Display displayCtrl 1602;
_ButtonMain ctrlAddEventHandler ["ButtonClick", {["",vehsel] spawn FUNC(openDialogMain)}];

_ButtonReplace = _Display displayCtrl 1605;
_ButtonReplace ctrlAddEventHandler ["ButtonClick", {[vehsel] spawn FUNC(guiDoReplace)}];
_ButtonRemove = _Display displayCtrl 1606;
_ButtonRemove ctrlAddEventHandler ["ButtonClick", {[vehsel] spawn FUNC(guiDoRemove)}];
