#include "..\script_component.hpp"
params ["_Target"];
private["_Target"];

private _hitpointsMajor = [];
private _hitpointsMajorPart = [];

private _selectionsToIgnore = _Target call EFUNC(repair,getSelectionsToIgnore);
(getAllHitPointsDamage _Target) params [["_hitPoints", []], ["_hitSelections", []]];
([_Target] call EFUNC(common,getWheelHitPointsWithSelections)) params ["_wheelHitPoints", "_wheelHitSelections"];
private _vehCfg = configOf _Target;
private _vehenginesize = getNumber (_vehCfg >> "FL_advrepair" >> "vehicleenginesize");
private _vehfueltanksize = getNumber (_vehCfg >> "FL_advrepair" >> "vehiclefueltanksize");
private _veharmor = getNumber (_vehCfg  >> "FL_advrepair" >> "vehiclearmor");
private _vehengine = getText (_vehCfg  >> "FL_advrepair" >> "vehicleengine");

{
    private _selection = _x; 
    private _hitpoint = toLowerANSI (_hitPoints select _forEachIndex);

    if (_forEachIndex in _selectionsToIgnore) then {
        TRACE_3("Skipping ignored hitpoint",_hitpoint,_forEachIndex,_selection);
        continue
    };

    if (_selection in _wheelHitSelections) then {
        _hitpointsMajor pushBack _hitpoint;
        _hitpointsMajorPart pushBack "Spare Wheel";
    } else {
        if (_hitpoint in FUELTANK_HITPOINTS) exitWith {
            if (_vehfueltanksize == 0) then {
                if (_selection in _processedSelections) exitWith {TRACE_3("Duplicate Fueltank",_hitpoint,_forEachIndex,_selection);};
                _hitpointsMajor pushBack _hitpoint;
                _hitpointsMajorPart pushBack "Fuel Tank Small";  
            } else {
                if (_selection in _processedSelections) exitWith {TRACE_3("Duplicate Fueltank",_hitpoint,_forEachIndex,_selection);};
                _hitpointsMajor pushBack _hitpoint;
                _hitpointsMajorPart pushBack "Fuel Tank Large";   
            };
            _processedSelections pushBack _selection;
        };
		if (_hitpoint in GUN_HITPOINTS) exitWith {
            if (_selection in _processedSelections) exitWith {TRACE_3("Duplicate Avionics",_hitpoint,_forEachIndex,_selection);};
            _hitpointsMajor pushBack _hitpoint;
            _hitpointsMajorPart pushBack "Gun FCS"; 
            _processedSelections pushBack _selection;   
        };
		if (_hitpoint in TURRET_HITPOINTS) exitWith {
            if (_selection in _processedSelections) exitWith {TRACE_3("Duplicate Avionics",_hitpoint,_forEachIndex,_selection);};
            _hitpointsMajor pushBack _hitpoint;
            _hitpointsMajorPart pushBack "Turret Drive"; 
            _processedSelections pushBack _selection;
        };
        if (_vehicle isKindOf "Helicopter") exitWith {
		    if (_hitpoint in ROTOR_HITPOINTS) exitWith {
                if (_selection in _processedSelections) exitWith {TRACE_3("Duplicate RotorAssembly",_hitpoint,_forEachIndex,_selection);};
                _hitpointsMajor pushBack _hitpoint;
                _hitpointsMajorPart pushBack "Rotor Assembly"; 
                _processedSelections pushBack _selection;
            };
		    if (_hitpoint == "hitavionics") exitWith {
                if (_selection in _processedSelections) exitWith {TRACE_3("Duplicate Avionics",_hitpoint,_forEachIndex,_selection);};
                _hitpointsMajor pushBack _hitpoint;
                _hitpointsMajorPart pushBack "Avionics"; 
                _processedSelections pushBack _selection;
            };
            if (_hitpoint in HELIENGINE_HITPOINTS) exitWith { 
                if (_selection in _processedSelections) exitWith {TRACE_3("Duplicate Avionics",_hitpoint,_forEachIndex,_selection);};
                private _engineselect = [_vehenginesize,_vehengine] joinstring "";
                switch (_engineselect) do {
                    default {
                        _hitpointsMajor pushBack _hitpoint;
                        _hitpointsMajorPart pushBack "Piston Engine Medium"; 
                    };
                    case "0piston": {
                        _hitpointsMajor pushBack _hitpoint;
                        _hitpointsMajorPart pushBack "Piston Engine Small"; 
                    };
                    case "1piston": {
                        _hitpointsMajor pushBack _hitpoint;
                        _hitpointsMajorPart pushBack "Piston Engine Medium"; 
                    };
                    case "2piston": {
                        _hitpointsMajor pushBack _hitpoint;
                        _hitpointsMajorPart pushBack "Piston Engine Large"; 
                    };
                    case "1turbine":{
                        _hitpointsMajor pushBack _hitpoint;
                        _hitpointsMajorPart pushBack "Turbine Engine Small"; 
                    };
                    case "2turbine":{
                        _hitpointsMajor pushBack _hitpoint;
                        _hitpointsMajorPart pushBack "Turbine Engine Large"; 
                    };
                };
                _processedSelections pushBack _selection;
            };
        };
        if (_vehicle isKindOf "Plane") exitWith {
		    if (_hitpoint == "hitavionics") exitWith {
                if (_selection in _processedSelections) exitWith {TRACE_3("Duplicate Avionics",_hitpoint,_forEachIndex,_selection);};
                _hitpointsMajor pushBack _hitpoint;
                _hitpointsMajorPart pushBack "Avionics"; 
                _processedSelections pushBack _selection;
            };
            if (_hitpoint == "hitengine" || _hitpoint == "hitengine2") exitWith { 
                if (_selection in _processedSelections) exitWith {TRACE_3("Duplicate Avionics",_hitpoint,_forEachIndex,_selection);};
                private _engineselect = [_vehenginesize,_vehengine] joinstring "";
                switch (_engineselect) do {
                    default {
                        _hitpointsMajor pushBack _hitpoint;
                        _hitpointsMajorPart pushBack "Piston Engine Medium"; 
                    };
                    case "0piston": {
                        _hitpointsMajor pushBack _hitpoint;
                        _hitpointsMajorPart pushBack "Piston Engine Small"; 
                    };
                    case "1piston": {
                        _hitpointsMajor pushBack _hitpoint;
                        _hitpointsMajorPart pushBack "Piston Engine Medium"; 
                    };
                    case "2piston": {
                        _hitpointsMajor pushBack _hitpoint;
                        _hitpointsMajorPart pushBack "Piston Engine Large"; 
                    };
                    case "1turbine":{
                        _hitpointsMajor pushBack _hitpoint;
                        _hitpointsMajorPart pushBack "Turbine Engine Small"; 
                    };
                    case "2turbine":{
                        _hitpointsMajor pushBack _hitpoint;
                        _hitpointsMajorPart pushBack "Turbine Engine Large"; 
                    };
                };
                _processedSelections pushBack _selection;
            };
            if (_hitpoint in CONTROLSURFACES_HITPOINTS) exitWith {
                if (_selection in _processedSelections) exitWith {TRACE_3("Duplicate Avionics",_hitpoint,_forEachIndex,_selection);};
                _hitpointsMajor pushBack _hitpoint;
                _hitpointsMajorPart pushBack "Control Surfaces"; 
                _processedSelections pushBack _selection;
            };
        };
        if (_hitpoint == "hitengine") exitWith { 
            if (_selection in _processedSelections) exitWith {TRACE_3("Duplicate Avionics",_hitpoint,_forEachIndex,_selection);};
            private _engineselect = [_vehenginesize,_vehengine] joinstring "";
            switch (_engineselect) do {
                default {
                    _hitpointsMajor pushBack _hitpoint;
                    _hitpointsMajorPart pushBack "Piston Engine Medium"; 
                };
                case "0piston": {
                    _hitpointsMajor pushBack _hitpoint;
                    _hitpointsMajorPart pushBack "Piston Engine Small"; 
                };
                case "1piston": {
                    _hitpointsMajor pushBack _hitpoint;
                    _hitpointsMajorPart pushBack "Piston Engine Medium"; 
                };
                case "2piston": {
                    _hitpointsMajor pushBack _hitpoint;
                    _hitpointsMajorPart pushBack "Piston Engine Large"; 
                };
                case "1turbine":{
                    _hitpointsMajor pushBack _hitpoint;
                    _hitpointsMajorPart pushBack "Turbine Engine Small"; 
                };
                case "2turbine":{
                    _hitpointsMajor pushBack _hitpoint;
                    _hitpointsMajorPart pushBack "Turbine Engine Large"; 
                };
            };
            _processedSelections pushBack _selection;
        };
        if (_hitpoint in TRACK_HITPOINTS) exitWith {
            _hitpointsMajor pushBack _hitpoint;
            _hitpointsMajorPart pushBack "Spare Track"; 
        };
    };
} forEach _hitSelections;

_hitpointsvehiclevar = [_hitpointsMajor,_hitpointsMajorPart];
SETVAR(_vehicle,HitpointsMajorVar,_hitpointsvehiclevar);
_hitpointsvehiclevar;