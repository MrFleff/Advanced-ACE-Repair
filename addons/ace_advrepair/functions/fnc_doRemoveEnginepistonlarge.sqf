#include "..\script_component.hpp"

params ["_unit", "_vehicle", "_hitPoint"];
TRACE_3("params",_unit,_vehicle,_hitPoint);

// get current hitpoint damage
private _hitPointDamage = _vehicle getHitPointDamage _hitPoint;

// can't remove destroyed or already removed wheel
if (_hitPointDamage >= 1) exitWith {};

// don't die by spawning / moving the wheel
[QEGVAR(common,fixCollision), _unit] call CBA_fnc_localEvent;

// spawn wheel
private _newobj = ["FL_parts_enginepistonlarge", getPosASL _unit, _hitPointDamage] call EFUNC(repair,spawnObject);
TRACE_2("new enginepistonlarge created",_newobj,damage _newobj);

// raise event to set the new hitpoint damage
[QEGVAR(repair,setWheelHitPointDamage), [_vehicle, _hitPoint, 1], _vehicle] call CBA_fnc_targetEvent;

// display text message if enabled
if (EGVAR(repair,DisplayTextOnRepair)) then {
    [localize LSTRING(RemovedEnginepistonlarge)] call EFUNC(common,displayTextStructured);
};

//[_unit,_newobj] call ace_dragging_fnc_startcarry;
[_unit,_newobj] call ace_dragging_fnc_startdrag;