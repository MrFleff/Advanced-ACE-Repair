#include "..\script_component.hpp"

params ["_unit", "_target", "_hitPoint"];
TRACE_3("params",_unit,_target,_hitPoint);

if !([_unit, _target, ["isNotDragging", "isNotCarrying", "isNotOnLadder"]] call ace_common_fnc_canInteractWith) exitWith {false};

_hasitem = [_unit, "advrepair_SpareParts"] call BIS_fnc_hasItem;

alive _target && {damage _target > 0} && (_hasitem);
