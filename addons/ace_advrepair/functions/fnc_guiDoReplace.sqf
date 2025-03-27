#include "..\script_component.hpp"
Params ["_Target"];
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
    case "Spare Wheel":{_className = "ReplaceWheel";};
    case "Fuel Tank Small":{_className = "ReplaceFueltanksmall";};
    case "Fuel Tank Large":{_className = "ReplaceFueltanklarge";};
    case "Gun FCS":{_className = "ReplaceGunFCS";};
    case "Turret Drive":{_className = "ReplaceTurretdrive";};
    case "Rotor Assembly":{_className = "ReplaceRotorAssembly";};
    case "Avionics":{_className = "ReplaceAvionics";};
    case "Piston Engine Medium":{_className = "ReplaceEnginepistonmedium";};
    case "Piston Engine Small":{_className = "ReplaceEnginepistonsmall";};
    case "Piston Engine Large":{_className = "ReplaceEnginepistonlarge";};
    case "Turbine Engine Small":{_className = "ReplaceEngineturbinesmall";};
    case "Turbine Engine Large":{_className = "ReplaceEngineturbinelarge";};
    case "Control Surfaces":{_className = "ReplaceControlsurfaces";};
    case "Spare Track":{_className = "ReplaceTrack";};
};

_check = [player,_Target,_hitPoint,_className] call DEFUNC(repair,canRepair);

if (_check) then {
    [player,_Target,_hitPoint,_className] call DEFUNC(repair,repair);
};