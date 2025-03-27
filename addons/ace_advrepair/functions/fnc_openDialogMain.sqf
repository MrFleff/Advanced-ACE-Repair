#include "..\script_component.hpp"
params ["_unit", "_vehicle", "_hitPoint"];
private["_vehicle"];
closeDialog 2;

_classname = typeOf _vehicle;

createDialog "advrepair_dialog_Main";

/*
_frame = (findDisplay 1664) displayCtrl 1801;
_frame ctrlSetBackgroundColor [0, 0, 0, 1];
*/

//Vehicle Name
_VehName = getText (configFile >> "CfgVehicles" >> _classname >> "DisplayName");
_Display = findDisplay 1664;
_VehNameIDC = _Display displayCtrl 1000;
_VehNameIDC ctrlSetText _VehName;

_note = _vehicle getVariable ["advrep_GUI_note","Notes go here~"];
_notebox = _Display displayCtrl 1400;
_notebox ctrlSetText _note;

//Vehicle Adv Repair Stats (Top Right)
_VehConfigStatsIDC  = (findDisplay 1664) displayCtrl 1500;
_VehEngineSize      = getNumber (configFile >> "CfgVehicles" >> _classname >> "FL_advrepair" >> "vehicleenginesize");
_VehFuelTankSize    = getNumber (configFile >> "CfgVehicles" >> _classname >> "FL_advrepair" >> "vehiclefueltanksize");
_VehArmor           = getNumber (configFile >> "CfgVehicles" >> _classname >> "FL_advrepair" >> "vehiclearmor");
_VehEngine          = getText   (configFile >> "CfgVehicles" >> _classname >> "FL_advrepair" >> "vehicleengine");
private _VehEngineStr = "";
switch (_VehEngine) do {
    case "piston": {
        switch (_VehEngineSize) do {
            default {_VehEngineStr = "Piston Engine"};
            case 0:{_VehEngineStr = "Small Piston Engine"};
            case 1:{_VehEngineStr = "Medium Piston Engine"};
            case 2:{_VehEngineStr = "Large Piston Engine"};
        };
    };
    case "turbine": {
        switch (_VehEngineSize) do {
            default {_VehEngineStr = "Turbine Engine"};
            case 1:{_VehEngineStr = "Small Turbine Engine"};
            case 2:{_VehEngineStr = "Large Turbine Engine"};
        };
    };
    default {
        switch (_VehEngineSize) do {
            default {_VehEngineStr = "Unknown Engine"};
            case 0:{_VehEngineStr = "Small Unknown Engine"};
            case 1:{_VehEngineStr = "Medium Unknown Engine"};
            case 2:{_VehEngineStr = "Large Unknown Engine"};
        };
    };
};
private _VehFuelTankSizeStr = "";
switch (_VehFuelTankSize) do {
    case 0:{_VehFuelTankSizeStr = "Small Fuel Tank"};
    case 1:{_VehFuelTankSizeStr = "Large Fuel Tank"};
};
private _VehArmorStr = "";
switch (_VehArmor) do {
    case 0:{_VehArmorStr = "Minimal Armor"};
    case 1:{_VehArmorStr = "Medium Armor"};
    case 2:{_VehArmorStr = "Heavy Armor"};
};
_VehConfigStatsIDC lbAdd _VehEngineStr;
_VehConfigStatsIDC lbAdd _VehFuelTankSizeStr;
_VehConfigStatsIDC lbAdd _VehArmorStr;


vehsel = _vehicle;
_ButtonMin = _Display displayCtrl 1601;
_ButtonMin ctrlAddEventHandler ["ButtonClick", {[vehsel] spawn FUNC(openDialogMinor)}];
_ButtonMaj = _Display displayCtrl 1602;
_ButtonMaj ctrlAddEventHandler ["ButtonClick", {[vehsel] spawn FUNC(openDialogMajor)}]; 