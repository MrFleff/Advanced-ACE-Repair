#include "..\script_component.hpp"
params ["_Target"];
private["_Target","_hitPoint","_className"];

_Display = findDisplay 1665;
_lnb = _Display displayCtrl 1400;
_rowsel = lnbCurSelRow _lnb;

_vehiclevar = _Target getVariable "HitpointsMajorVar";
_MajorHitPoints = _vehiclevar select 0;
_MajorHitPointsPart = _vehiclevar select 1;
_partname = _MajorHitPointsPart select _rowsel;
_hitPoint = _MajorHitPoints select _rowsel;

_className = "";
switch (_partname) do {
    case "Spare Wheel":{_className = "RemoveWheel";};
    case "Fuel Tank Small":{_className = "RemoveFueltanksmall";};
    case "Fuel Tank Large":{_className = "RemoveFueltanklarge";};
    case "Gun FCS":{_className = "RemoveGunFCS";};
    case "Turret Drive":{_className = "RemoveTurretdrive";};
    case "Rotor Assembly":{_className = "RemoveRotorAssembly";};
    case "Avionics":{_className = "RemoveAvionics";};
    case "Piston Engine Medium":{_className = "RemoveEnginepistonmedium";};
    case "Piston Engine Small":{_className = "RemoveEnginepistonsmall";};
    case "Piston Engine Large":{_className = "RemoveEnginepistonlarge";};
    case "Turbine Engine Small":{_className = "RemoveEngineturbinesmall";};
    case "Turbine Engine Large":{_className = "RemoveEngineturbinelarge";};
    case "Control Surfaces":{_className = "RemoveControlsurfaces";};
    case "Spare Track":{_className = "RemoveTrack";};
};

_check = [player,_Target,_hitPoint,_className] call ace_repair_fnc_canRepair;

if (_check) then {
    [player,_Target,_hitPoint,_className] call ace_repair_fnc_repair;
};
