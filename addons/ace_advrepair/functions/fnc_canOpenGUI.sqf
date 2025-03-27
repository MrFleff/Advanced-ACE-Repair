#include "..\script_component.hpp"

params ["_unit", "_target", "_hitPoint"];
TRACE_3("params",_unit,_target,_hitPoint);

if !([_unit, _target, ["isNotDragging", "isNotCarrying", "isNotOnLadder"]] call EFUNC(common,canInteractWith)) exitWith {false};
if (side _unit getFriend side _target < 0.6 || locked _target > 1 || isEngineOn _target) exitWith {false};

//check for a near track object is handled by claimObjects[] config
true;