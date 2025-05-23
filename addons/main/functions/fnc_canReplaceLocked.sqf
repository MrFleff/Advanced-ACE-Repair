#include "..\script_component.hpp"
/*
 * Author: commy2
 * Check if the unit can replace given track of the vehicle.
 *
 * Arguments:
 * 0: Unit that does the repairing <OBJECT>
 * 1: Vehicle to repair <OBJECT>
 * 2: Selected hitpoint <STRING>
 *
 * Return Value:
 * None
 *
 * Example:
 * [unit, vehicle, "hitpoint"] call ace_repair_fnc_canReplaceTrack
 *
 * Public: No
 */

params ["_unit", "_target", "_hitPoint"];
TRACE_3("params",_unit,_target,_hitPoint);

if !([_unit, _target, ["isNotDragging", "isNotCarrying", "isNotOnLadder"]] call ace_common_fnc_canInteractWith) exitWith {false};
if (side _unit getFriend side _target < 0.6 || locked _target > 1 || isEngineOn _target) exitWith {false};

//check for a near track object is handled by claimObjects[] config

(_target getHitPointDamage _hitPoint >= 1)
