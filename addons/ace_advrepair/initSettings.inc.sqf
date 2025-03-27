[
    QGVAR(MajorRepairLocations), 
    "LIST",
    [LSTRING(MajorPartRepairLocations_DisplayName), LSTRING(MajorPartRepairLocations_Description)],
    ["Fleff's Advanced Repair","Repair Permissions"],
    [[0,1,2,3,4],[LSTRING(useAnywhere), LSTRING(repairVehicleOnly), LSTRING(repairFacilityOnly), LSTRING(vehicleAndFacility), ELSTRING(common,Disabled)],1], // [values, titles, defaultIndex]
    true
] call CBA_fnc_addSetting;
[
    QGVAR(MajorRepairPermissions), 
    "LIST",
    [LSTRING(MajorPartRepairPerms_DisplayName), LSTRING(MajorPartRepairPerms_Description)],
    ["Fleff's Advanced Repair","Repair Permissions"],
    [[0,1,2],[LSTRING(engineerSetting_anyone), LSTRING(engineerSetting_EngineerOnly), LSTRING(engineerSetting_AdvancedOnly)],1], // [values, titles, defaultIndex]
    true
] call CBA_fnc_addSetting;



[
    QGVAR(GunFCSRepair), "SLIDER",
    [LSTRING(GunFCSRepair_Displayname), LSTRING(RepairCost_Description)],
    ["Fleff's Advanced Repair","Major Parts - Percentage Healed Per Spare Part Spent"],
    [0,100,20,-1], // [min, max, default value, trailing decimals (-1 for whole numbers only)]
    true
] call CBA_fnc_addSetting;

[
    QGVAR(TurretDrive), "SLIDER",
    [LSTRING(TurretDrive_Displayname), LSTRING(RepairCost_Description)],
    ["Fleff's Advanced Repair","Major Parts - Percentage Healed Per Spare Part Spent"],
    [0,100,20,-1], // [min, max, default value, trailing decimals (-1 for whole numbers only)]
    true
] call CBA_fnc_addSetting;

[
    QGVAR(Avionics), "SLIDER",
    [LSTRING(Avionics_Displayname), LSTRING(RepairCost_Description)],
    ["Fleff's Advanced Repair","Major Parts - Percentage Healed Per Spare Part Spent"],
    [0,100,20,-1], // [min, max, default value, trailing decimals (-1 for whole numbers only)]
    true
] call CBA_fnc_addSetting;

[
    QGVAR(ControlSurfaces), "SLIDER",
    [LSTRING(ControlSurfaces_Displayname), LSTRING(RepairCost_Description)],
    ["Fleff's Advanced Repair","Major Parts - Percentage Healed Per Spare Part Spent"],
    [0,100,20,-1], // [min, max, default value, trailing decimals (-1 for whole numbers only)]
    true
] call CBA_fnc_addSetting;

[
    QGVAR(EngTurbineSmall), "SLIDER",
    [LSTRING(EngTurbineSmall_Displayname), LSTRING(RepairCost_Description)],
    ["Fleff's Advanced Repair","Major Parts - Percentage Healed Per Spare Part Spent"],
    [0,100,10,-1], // [min, max, default value, trailing decimals (-1 for whole numbers only)]
    true
] call CBA_fnc_addSetting;

[
    QGVAR(EngTurbineLarge), "SLIDER",
    [LSTRING(EngTurbineLarge_Displayname), LSTRING(RepairCost_Description)],
    ["Fleff's Advanced Repair","Major Parts - Percentage Healed Per Spare Part Spent"],
    [0,100,5,-1], // [min, max, default value, trailing decimals (-1 for whole numbers only)]
    true
] call CBA_fnc_addSetting;

[
    QGVAR(EngPistonSmall), "SLIDER",
    [LSTRING(EngPistonSmall_Displayname), LSTRING(RepairCost_Description)],
    ["Fleff's Advanced Repair","Major Parts - Percentage Healed Per Spare Part Spent"],
    [0,100,50,-1], // [min, max, default value, trailing decimals (-1 for whole numbers only)]
    true
] call CBA_fnc_addSetting;

[
    QGVAR(EngPistonMedium), "SLIDER",
    [LSTRING(EngPistonMedium_Displayname), LSTRING(RepairCost_Description)],
    ["Fleff's Advanced Repair","Major Parts - Percentage Healed Per Spare Part Spent"],
    [0,100,30,-1], // [min, max, default value, trailing decimals (-1 for whole numbers only)]
    true
] call CBA_fnc_addSetting;

[
    QGVAR(EngPistonLarge), "SLIDER",
    [LSTRING(EngPistonLarge_Displayname), LSTRING(RepairCost_Description)],
    ["Fleff's Advanced Repair","Major Parts - Percentage Healed Per Spare Part Spent"],
    [0,100,10,-1], // [min, max, default value, trailing decimals (-1 for whole numbers only)]
    true
] call CBA_fnc_addSetting;

[
    QGVAR(RotorAssembly), "SLIDER",
    [LSTRING(RotorAssembly_Displayname), LSTRING(RepairCost_Description)],
    ["Fleff's Advanced Repair","Major Parts - Percentage Healed Per Spare Part Spent"],
    [0,100,20,-1], // [min, max, default value, trailing decimals (-1 for whole numbers only)]
    true
] call CBA_fnc_addSetting;

[
    QGVAR(FuelTankSmall), "SLIDER",
    [LSTRING(FuelTankSmall_Displayname), LSTRING(RepairCost_Description)],
    ["Fleff's Advanced Repair","Major Parts - Percentage Healed Per Spare Part Spent"],
    [0,100,50,-1], // [min, max, default value, trailing decimals (-1 for whole numbers only)]
    true
] call CBA_fnc_addSetting;

[
    QGVAR(FuelTankLarge), "SLIDER",
    [LSTRING(FuelTankLarge_Displayname), LSTRING(RepairCost_Description)],
    ["Fleff's Advanced Repair","Major Parts - Percentage Healed Per Spare Part Spent"],
    [0,100,25,-1], // [min, max, default value, trailing decimals (-1 for whole numbers only)]
    true
] call CBA_fnc_addSetting;

[
    QGVAR(WheelRepair), "SLIDER",
    [LSTRING(WheelRepair_Displayname), LSTRING(RepairCost_Description)],
    ["Fleff's Advanced Repair","Major Parts - Percentage Healed Per Spare Part Spent"],
    [0,100,50,-1], // [min, max, default value, trailing decimals (-1 for whole numbers only)]
    true
] call CBA_fnc_addSetting;

[
    QGVAR(TrackRepair), "SLIDER",
    [LSTRING(TrackRepair_Displayname), LSTRING(RepairCost_Description)],
    ["Fleff's Advanced Repair","Major Parts - Percentage Healed Per Spare Part Spent"],
    [0,100,25,-1], // [min, max, default value, trailing decimals (-1 for whole numbers only)]
    true
] call CBA_fnc_addSetting;

[
    QGVAR(DefaultRepair), "SLIDER",
    [LSTRING(DefaultRepair_Displayname), LSTRING(RepairCost_Description)],
    ["Fleff's Advanced Repair","Miscellaneous Parts - Percentage Healed Per Spare Part Spent"],
    [0,100,100,-1], // [min, max, default value, trailing decimals (-1 for whole numbers only)]
    true
] call CBA_fnc_addSetting;

[
    QGVAR(Hull0), "SLIDER",
    [LSTRING(Hull0_Displayname), LSTRING(RepairCost_Description)],
    ["Fleff's Advanced Repair","Miscellaneous Parts - Percentage Healed Per Spare Part Spent"],
    [0,100,30,-1], // [min, max, default value, trailing decimals (-1 for whole numbers only)]
    true
] call CBA_fnc_addSetting;

[
    QGVAR(Hull1), "SLIDER",
    [LSTRING(Hull1_Displayname), LSTRING(RepairCost_Description)],
    ["Fleff's Advanced Repair","Miscellaneous Parts - Percentage Healed Per Spare Part Spent"],
    [0,100,20,-1], // [min, max, default value, trailing decimals (-1 for whole numbers only)]
    true
] call CBA_fnc_addSetting;

[
    QGVAR(Hull2), "SLIDER",
    [LSTRING(Hull2_Displayname), LSTRING(RepairCost_Description)],
    ["Fleff's Advanced Repair","Miscellaneous Parts - Percentage Healed Per Spare Part Spent"],
    [0,100,10,-1], // [min, max, default value, trailing decimals (-1 for whole numbers only)]
    true
] call CBA_fnc_addSetting;

[
    QGVAR(ERARep), "SLIDER",
    [LSTRING(ERARep_Displayname), LSTRING(RepairCost_Description)],
    ["Fleff's Advanced Repair","Miscellaneous Parts - Percentage Healed Per Spare Part Spent"],
    [0,100,50,-1], // [min, max, default value, trailing decimals (-1 for whole numbers only)]
    true
] call CBA_fnc_addSetting;