#include "..\script_component.hpp"

params ["_unit", "_vehicle", "_hitPoint", "", "", "", "_claimedObjects"];
TRACE_4("params",_unit,_vehicle,_hitPoint,_claimedObjects);

_claimedObjects params [["_wheel", objNull]];
if ((isNull _wheel) || {!([_unit, _wheel, ["isNotDragging", "isNotCarrying", "isNotOnLadder"]] call ace_common_fnc_canInteractWith)}) exitWith {
    WARNING_1("Bad Claimed RotorAssembly %1",_claimedObjects);
};

// get current hitpoint damage
private _hitPointDamage = _vehicle getHitPointDamage _hitPoint;

// can't replace not destroyed wheel
if (_hitPointDamage < 1) exitWith {};

// get replacement wheel's damage
private _newHitPointDamage = damage _wheel;

// can't replace a destroyed wheel
if (_newHitPointDamage >= 1) exitWith {};

deleteVehicle _wheel;

// raise event to set the new hitpoint damage
[QACEVAR(repair,setWheelHitPointDamage), [_vehicle, _hitPoint, _newHitPointDamage], _vehicle] call CBA_fnc_targetEvent;

// display text message if enabled
if (ACEVAR(repair,DisplayTextOnRepair)) then {
    [LSTRING(ReplacedRotorAssembly)] call ace_common_fnc_displayTextStructured;
};
