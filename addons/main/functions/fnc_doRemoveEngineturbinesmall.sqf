#include "..\script_component.hpp"

params ["_unit", "_vehicle", "_hitPoint"];
TRACE_3("params",_unit,_vehicle,_hitPoint);

// get current hitpoint damage
private _hitPointDamage = _vehicle getHitPointDamage _hitPoint;

// can't remove destroyed or already removed wheel
if (_hitPointDamage >= 1) exitWith {};

// don't die by spawning / moving the wheel
[QACEVAR(common,fixCollision), _unit] call CBA_fnc_localEvent;

// spawn wheel
private _newobj = ["FL_parts_engineturbinesmall", getPosASL _unit, _hitPointDamage] call ace_repair_fnc_spawnObject;
TRACE_2("new engineturbinesmall created",_newobj,damage _newobj);

// raise event to set the new hitpoint damage
[QACEVAR(repair,setWheelHitPointDamage), [_vehicle, _hitPoint, 1], _vehicle] call CBA_fnc_targetEvent;

// display text message if enabled
if (ACEVAR(repair,DisplayTextOnRepair)) then {
    [localize LSTRING(RemovedEngineturbinesmall)] call ace_common_fnc_displayTextStructured;
};

[_unit,_newobj] call ace_dragging_fnc_startcarry;
//[_unit,_newobj] call ace_dragging_fnc_startdrag;
