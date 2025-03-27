#include "script_component.hpp"
#include "UI\BaseControls.hpp"
#include "UI\RscDisplayMain.hpp"
#include "UI\RscDisplayMajorParts.hpp"
#include "UI\RscDisplayMinorParts.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {
            "FL_parts_rotorassembly",
            "FL_parts_engineturbinesmall",
            "FL_parts_engineturbinelarge",
            "FL_parts_controlsurfaces",
            "FL_parts_avionics",
            "FL_parts_enginepistonlarge",
            "FL_parts_enginepistonmedium",
            "FL_parts_enginepistonsmall",
            "FL_parts_gunfcs",
            "FL_parts_turretdrive",
            "FL_parts_fueltanksmall",
            "FL_parts_fueltanklarge",
			"FL_parts_SpareParts",
			"FL_parts_SparePartsLarge"
        };
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {QUOTE(REPLACEMOD)};
        author = "Fleff";
        authors[] = {"Fleff","ACE-Team"};
        url = "";
        VERSION_CONFIG;
        skipWhenMissingDependencies = 1;
    };
};

class Extended_PreStart_EventHandlers
{
	class ADDON
	{
		init = QUOTE(call COMPILE_SCRIPT(XEH_preStart));
	};
};

class Extended_PreInit_EventHandlers
{
	class ADDON
	{
		init = QUOTE(call COMPILE_SCRIPT(XEH_preInit));
	};
};

class Extended_InitPost_EventHandlers
{
	class Car
	{
		class ace_repair
		{
			init="_this call ace_advrepair_fnc_addAdvRepairActions";
		};
	};
	class Motorcycle
	{
		class ace_repair
		{
			init="_this call ace_advrepair_fnc_addAdvRepairActions";
		};
	};
	class Tank
	{
		class ace_repair
		{
			init="_this call ace_advrepair_fnc_addAdvRepairActions";
		};
	};
	class Helicopter
	{
		class ace_repair
		{
			init="_this call ace_advrepair_fnc_addAdvRepairActions";
			exclude[]=
			{
				"ace_fastroping_helper",
				"ACE_friesBase",
				"ace_refuel_helper"
			};
		};
	};
	class Plane
	{
		class ace_repair
		{
			init="_this call ace_advrepair_fnc_addAdvRepairActions";
		};
	};
	class Ship_F
	{
		class ace_repair
		{
			init="_this call ace_advrepair_fnc_addAdvRepairActions";
		};
	};
	class ACE_RepairItem_Base
	{
		class ace_repair
		{
			init="_this call ace_advrepair_fnc_addPartAdvRepairActions";
		};
	};
};

class CfgVehicleClasses
{
	class FL_Logistics_Items
	{
		displayName="$STR_ace_advrepair_logisticsparts";
	};
};

class CfgEditorSubcategories
{
	class FL_parts_subcategory
	{
		displayName="$STR_ace_advrepair_parts";
	};
};

class ACE_Settings
{
	class ace_advrepair_MajorRepairLocations
	{
		movedToSQF=1;
	};
	class ace_advrepair_MajorRepairPermissions
	{
		movedToSQF=1;
	};
	class ace_advrepair_GunFCSRepair
	{
		movedToSQF=1;
	};
	class ace_advrepair_TurretDrive
	{
		movedToSQF=1;
	};
	class ace_advrepair_Avionics
	{
		movedToSQF=1;
	};
	class ace_advrepair_ControlSurfaces
	{
		movedToSQF=1;
	};
	class ace_advrepair_EngTurbineSmall
	{
		movedToSQF=1;
	};
	class ace_advrepair_EngTurbineLarge
	{
		movedToSQF=1;
	};
	class ace_advrepair_EngPistonSmall
	{
		movedToSQF=1;
	};
	class ace_advrepair_EngPistonMedium
	{
		movedToSQF=1;
	};
	class ace_advrepair_EngPistonLarge
	{
		movedToSQF=1;
	};
	class ace_advrepair_RotorAssembly
	{
		movedToSQF=1;
	};
	class ace_advrepair_FuelTankSmall
	{
		movedToSQF=1;
	};
	class ace_advrepair_FuelTankLarge
	{
		movedToSQF=1;
	};
	class ace_advrepair_WheelRepair
	{
		movedToSQF=1;
	};
	class ace_advrepair_TrackRepair
	{
		movedToSQF=1;
	};
	class ace_advrepair_DefaultRepair
	{
		movedToSQF=1;
	};
	class ace_advrepair_Hull0
	{
		movedToSQF=1;
	};
	class ace_advrepair_Hull1
	{
		movedToSQF=1;
	};
	class ace_advrepair_Hull2
	{
		movedToSQF=1;
	};
	class ace_advrepair_ERARep
	{
		movedToSQF=1;
	};
};

class CfgVehicles {
	class ThingX;
	class ACE_RepairItem_Base: ThingX {};
	class FL_RepairItem: ACE_RepairItem_Base
	{
		accuracy=0.2;
		vehicleClass="FL_Logistics_Items";
		editorCategory="EdCat_Supplies";
		editorSubcategory="FL_parts_subcategory";
	};
	//Parts
		class ReammoBox_F: ThingX {};
		class Slingload_base_F: ReammoBox_F {};
		class CargoNet_01_base_F: Slingload_base_F {};
		class CargoNet_01_box_F: CargoNet_01_base_F {};
		class FL_parts_SparePartsLarge: CargoNet_01_box_F
		{
			author="Fleff";
			displayName = "$STR_ace_advrepair_part_SparePartsLarge";
			class TransportItems
			{
				class _xx_advrepair_SpareParts
				{
					name="advrepair_SpareParts";
					count=100;
				};
			};
			vehicleClass="FL_Logistics_Items";
			editorCategory="EdCat_Supplies";
			editorSubcategory="FL_parts_subcategory";
		};
		class FL_parts_SpareParts: FL_RepairItem              //silver    small
		{
			cargoCompartments[] = {"Compartment1"};
			ace_cargo_size=1;
			ace_cargo_canLoad=1;
			ace_cargo_noRename=1;
			ace_dragging_canDrag = 0;
			ace_dragging_canCarry = 1;
			author="Fleff";
			scope=2;
			model = "\A3\Structures_F_Heli\Items\Luggage\PlasticCase_01_small_F.p3d";
			displayName = "$STR_ace_advrepair_part_SpareParts";
			picture = "pictureThing";
			icon = "iconObject_1x2";
			mapSize=0.69999999;
			armor=500;
			armorStructural=1;
			minTotalDamageThreshold=0.0099999998;
			explosionShielding=1;
			hiddenSelections[] = {"Camo","Camo2"};
			hiddenSelectionsTextures[] = {"a3\Props_F_Orange\Humanitarian\Supplies\Data\PlasticCase_01_gray_CO.paa","z\ace\addons\advrepair\data\advrepair_part_SpareParts.paa"};
			maximumLoad = 300;
			transportMaxBackpacks = 12;
			transportMaxMagazines = 64;
			transportMaxWeapons = 12;
			class HitPoints
			{
				class HitBody
				{
					armor=1;
					material=-1;
					name="mat_rim";
					visual="mat_rim";
					passThrough=1;
					radius=0.1;
					explosionShielding=1;
					minimalHit=1;
				};
			};
			class Damage
			{
				tex[]={};
				mat[]=
				{
				};
			};
			editorPreview = "\A3\EditorPreviews_F_Orange\Data\CfgVehicles\Land_PlasticCase_01_small_gray_F.jpg";
			class TransportItems
			{
				class _xx_advrepair_SpareParts
				{
					name="advrepair_SpareParts";
					count=20;
				};
			};
		};
		/*
		class FL_parts_SparePartsLarge: FL_RepairItem
		{
			cargoCompartments[] = {"Compartment1"};
			ace_dragging_canDrag = 0;
			ace_dragging_canCarry = 0;
			ace_cargo_noRename=1;
			ace_cargo_size=6;
			ace_cargo_canLoad=1;
			author="Fleff";
			displayName = "$STR_ace_advrepair_part_SparePartsLarge";
			scope=2;
			model = "\A3\Supplies_F_Heli\CargoNets\CargoNet_01_box_F.p3d";
			picture = "pictureThing";
			icon = "iconObject_1x1";
			mapSize=0.69999999;
			armor=500;
			armorStructural=1;
			minTotalDamageThreshold=0.0099999998;
			explosionShielding=1;
			hiddenSelections[] = {};	
			maximumLoad = 6000;
			transportMaxBackpacks = 12;
			transportMaxMagazines = 144;
			transportMaxWeapons = 18;
			class HitPoints
			{
				class HitBody
				{
					armor=1;
					material=-1;
					name="mat_rim";
					visual="mat_rim";
					passThrough=1;
					radius=0.1;
					explosionShielding=1;
					minimalHit=1;
				};
			};
			class Damage
			{
				tex[]={};
				mat[]=
				{
				};
			};
			editorPreview = "\A3\EditorPreviews_F\Data\CfgVehicles\CargoNet_01_box_F.jpg";
			class TransportItems
			{
				class _xx_advrepair_SpareParts
				{
					name="advrepair_SpareParts";
					count=100;
				};
			};
		};
		*/

		class FL_parts_gunfcs: FL_RepairItem          		//black     small
		{
			ace_cargo_size=1;
			ace_cargo_canLoad=1;
			ace_cargo_noRename=1;
			ace_dragging_canDrag = 0;
			ace_dragging_canCarry = 1;
			author="Fleff";
			scope=2;
			model = "\A3\Structures_F_Heli\Items\Luggage\PlasticCase_01_small_F.p3d";
			displayName = "$STR_ace_advrepair_part_gunfcs";
			picture = "pictureThing";
			icon = "iconObject_1x2";
			mapSize=0.69999999;
			armor=500;
			armorStructural=1;
			minTotalDamageThreshold=0.0099999998;
			explosionShielding=1;
			hiddenSelections[] = {"Camo","Camo2"};
			hiddenSelectionsTextures[] = {"a3\Props_F_Enoch\Military\Supplies\Data\PlasticCase_01_black_CO.paa","z\ace\addons\advrepair\data\advrepair_part_gunfcs.paa"};
			class HitPoints
			{
				class HitBody
				{
					armor=1;
					material=-1;
					name="mat_rim";
					visual="mat_rim";
					passThrough=1;
					radius=0.1;
					explosionShielding=1;
					minimalHit=1;
				};
			};
			class Damage
			{
				tex[]={};
				mat[]=
				{
				};
			};
			editorPreview = "\A3\EditorPreviews_F_Enoch\Data\CfgVehicles\Land_PlasticCase_01_small_black_F.jpg";
		};
		class FL_parts_engineturbinesmall: FL_RepairItem   	//black     medium
		{
			ace_cargo_size=2;
			ace_cargo_canLoad=1;
			ace_cargo_noRename=1;
			ace_dragging_canDrag = 0;
			ace_dragging_canCarry = 1;
			author="Fleff";
			scope=2;
			model = "\A3\Structures_F_Heli\Items\Luggage\PlasticCase_01_medium_F.p3d";
			displayName = "$STR_ace_advrepair_part_engineturbinesmall";
			picture = "pictureThing";
			icon = "iconObject_1x2";
			mapSize=0.69999999;
			armor=500;
			armorStructural=1;
			minTotalDamageThreshold=0.0099999998;
			explosionShielding=1;
			hiddenSelections[] = {"Camo","Camo2"};
			hiddenSelectionsTextures[] = {"a3\Props_F_Enoch\Military\Supplies\Data\PlasticCase_01_black_CO.paa","z\ace\addons\advrepair\data\advrepair_part_engineturbinesmall.paa"};
			class HitPoints
			{
				class HitBody
				{
					armor=1;
					material=-1;
					name="mat_rim";
					visual="mat_rim";
					passThrough=1;
					radius=0.1;
					explosionShielding=1;
					minimalHit=1;
				};
			};
			class Damage
			{
				tex[]={};
				mat[]=
				{
				};
			};
			editorPreview = "\A3\EditorPreviews_F_Enoch\Data\CfgVehicles\Land_PlasticCase_01_medium_black_F.jpg";
		};
		class FL_parts_engineturbinelarge: FL_RepairItem   	//black     large
		{
			ace_cargo_size=4;
			ace_cargo_canLoad=1;
			ace_cargo_noRename=1;
			ace_dragging_canDrag = 1;
			ace_dragging_canCarry = 0;
			author="Fleff";
			scope=2;
			model = "\A3\Structures_F_Heli\Items\Luggage\PlasticCase_01_large_F.p3d";
			displayName = "$STR_ace_advrepair_part_engineturbinelarge";
			picture = "pictureThing";
			icon = "iconObject_1x2";
			mapSize=0.69999999;
			armor=500;
			armorStructural=1;
			minTotalDamageThreshold=0.0099999998;
			explosionShielding=1;
			hiddenSelections[] = {"Camo","Camo2"};
			hiddenSelectionsTextures[] = {"a3\Props_F_Enoch\Military\Supplies\Data\PlasticCase_01_black_CO.paa","z\ace\addons\advrepair\data\advrepair_part_engineturbinelarge.paa"};
			class HitPoints
			{
				class HitBody
				{
					armor=1;
					material=-1;
					name="mat_rim";
					visual="mat_rim";
					passThrough=1;
					radius=0.1;
					explosionShielding=1;
					minimalHit=1;
				};
			};
			class Damage
			{
				tex[]={};
				mat[]=
				{
				};
			};
			editorPreview = "\A3\EditorPreviews_F_Enoch\Data\CfgVehicles\Land_PlasticCase_01_large_black_F.jpg";
		};

		class FL_parts_rotorassembly: FL_RepairItem         //silver    large
		{
			ace_cargo_size=4;
			ace_cargo_canLoad=1;
			ace_cargo_noRename=1;
			ace_dragging_canDrag = 0;
			ace_dragging_canCarry = 1;
			author="Fleff";
			scope=2;
			model = "\A3\Structures_F_Heli\Items\Luggage\PlasticCase_01_large_F.p3d";
			displayName = "$STR_ace_advrepair_part_rotorassembly";
			picture = "pictureThing";
			icon = "iconObject_1x2";
			mapSize=0.69999999;
			armor=500;
			armorStructural=1;
			minTotalDamageThreshold=0.0099999998;
			explosionShielding=1;
			hiddenSelections[] = {"Camo","Camo2"};
			hiddenSelectionsTextures[] = {"a3\Props_F_Orange\Humanitarian\Supplies\Data\PlasticCase_01_gray_CO.paa","z\ace\addons\advrepair\data\advrepair_part_rotorassembly.paa"};
			class HitPoints
			{
				class HitBody
				{
					armor=1;
					material=-1;
					name="mat_rim";
					visual="mat_rim";
					passThrough=1;
					radius=0.1;
					explosionShielding=1;
					minimalHit=1;
				};
			};
			class Damage
			{
				tex[]={};
				mat[]=
				{
				};
			};
			editorPreview = "\A3\EditorPreviews_F_Orange\Data\CfgVehicles\Land_PlasticCase_01_large_gray_F.jpg";
		};
		class FL_parts_controlsurfaces: FL_RepairItem       //silver    medium
		{
			ace_cargo_size=2;
			ace_cargo_canLoad=1;
			ace_cargo_noRename=1;
			ace_dragging_canDrag = 0;
			ace_dragging_canCarry = 1;
			author="Fleff";
			scope=2;
			model = "\A3\Structures_F_Heli\Items\Luggage\PlasticCase_01_medium_F.p3d";
			displayName = "$STR_ace_advrepair_part_controlsurfaces";
			picture = "pictureThing";
			icon = "iconObject_1x2";
			mapSize=0.69999999;
			armor=500;
			armorStructural=1;
			minTotalDamageThreshold=0.0099999998;
			explosionShielding=1;
			hiddenSelections[] = {"Camo","Camo2"};
			hiddenSelectionsTextures[] = {"a3\Props_F_Orange\Humanitarian\Supplies\Data\PlasticCase_01_gray_CO.paa","z\ace\addons\advrepair\data\advrepair_part_controlsurfaces.paa"};
			class HitPoints
			{
				class HitBody
				{
					armor=1;
					material=-1;
					name="mat_rim";
					visual="mat_rim";
					passThrough=1;
					radius=0.1;
					explosionShielding=1;
					minimalHit=1;
				};
			};
			class Damage
			{
				tex[]={};
				mat[]=
				{
				};
			};
			editorPreview = "\A3\EditorPreviews_F_Orange\Data\CfgVehicles\Land_PlasticCase_01_medium_gray_F.jpg";
		};
		class FL_parts_avionics: FL_RepairItem              //silver    small
		{
			ace_cargo_size=1;
			ace_cargo_canLoad=1;
			ace_cargo_noRename=1;
			ace_dragging_canDrag = 0;
			ace_dragging_canCarry = 1;
			author="Fleff";
			scope=2;
			model = "\A3\Structures_F_Heli\Items\Luggage\PlasticCase_01_small_F.p3d";
			displayName = "$STR_ace_advrepair_part_avionics";
			picture = "pictureThing";
			icon = "iconObject_1x2";
			mapSize=0.69999999;
			armor=500;
			armorStructural=1;
			minTotalDamageThreshold=0.0099999998;
			explosionShielding=1;
			hiddenSelections[] = {"Camo","Camo2"};
			hiddenSelectionsTextures[] = {"a3\Props_F_Orange\Humanitarian\Supplies\Data\PlasticCase_01_gray_CO.paa","z\ace\addons\advrepair\data\advrepair_part_avionics.paa"};
			class HitPoints
			{
				class HitBody
				{
					armor=1;
					material=-1;
					name="mat_rim";
					visual="mat_rim";
					passThrough=1;
					radius=0.1;
					explosionShielding=1;
					minimalHit=1;
				};
			};
			class Damage
			{
				tex[]={};
				mat[]=
				{
				};
			};
			editorPreview = "\A3\EditorPreviews_F_Orange\Data\CfgVehicles\Land_PlasticCase_01_small_gray_F.jpg";
		};

		class FL_parts_enginepistonlarge: FL_RepairItem     //large     green
		{
			ace_cargo_size=4;
			ace_cargo_canLoad=1;
			ace_cargo_noRename=1;
			ace_dragging_canDrag = 1;
			ace_dragging_canCarry = 0;
			author="Fleff";
			scope=2;
			model = "\A3\Structures_F_Heli\Items\Luggage\PlasticCase_01_large_F.p3d";
			displayName = "$STR_ace_advrepair_part_enginepistonlarge";
			picture = "pictureThing";
			icon = "iconObject_1x2";
			mapSize=0.69999999;
			armor=500;
			armorStructural=1;
			minTotalDamageThreshold=0.0099999998;
			explosionShielding=1;
			hiddenSelections[] = {"Camo","Camo2"};
			hiddenSelectionsTextures[] = {"a3\Props_F_Enoch\Military\Supplies\Data\PlasticCase_01_olive_CO.paa","z\ace\addons\advrepair\data\advrepair_part_enginepistonlarge.paa"};
			class HitPoints
			{
				class HitBody
				{
					armor=1;
					material=-1;
					name="mat_rim";
					visual="mat_rim";
					passThrough=1;
					radius=0.1;
					explosionShielding=1;
					minimalHit=1;
				};
			};
			class Damage
			{
				tex[]={};
				mat[]=
				{
				};
			};
			editorPreview = "\A3\EditorPreviews_F_Enoch\Data\CfgVehicles\Land_PlasticCase_01_large_olive_F.jpg";
		};
		class FL_parts_enginepistonmedium: FL_RepairItem    //medium    green
		{
			ace_cargo_size=2;
			ace_cargo_canLoad=1;
			ace_cargo_noRename=1;
			ace_dragging_canDrag = 0;
			ace_dragging_canCarry = 1;
			author="Fleff";
			scope=2;
			model = "\A3\Structures_F_Heli\Items\Luggage\PlasticCase_01_medium_F.p3d";
			displayName = "$STR_ace_advrepair_part_enginepistonmedium";
			picture = "pictureThing";
			icon = "iconObject_1x2";
			mapSize=0.69999999;
			armor=500;
			armorStructural=1;
			minTotalDamageThreshold=0.0099999998;
			explosionShielding=1;
			hiddenSelections[] = {"Camo","Camo2"};
			hiddenSelectionsTextures[] = {"a3\Props_F_Enoch\Military\Supplies\Data\PlasticCase_01_olive_CO.paa","z\ace\addons\advrepair\data\advrepair_part_enginepistonmedium.paa"};
			class HitPoints
			{
				class HitBody
				{
					armor=1;
					material=-1;
					name="mat_rim";
					visual="mat_rim";
					passThrough=1;
					radius=0.1;
					explosionShielding=1;
					minimalHit=1;
				};
			};
			class Damage
			{
				tex[]={};
				mat[]=
				{
				};
			};
			editorPreview = "\A3\EditorPreviews_F_Enoch\Data\CfgVehicles\Land_PlasticCase_01_medium_olive_F.jpg";
		};
		class FL_parts_enginepistonsmall: FL_RepairItem     //small     green
		{
			ace_cargo_size=1;
			ace_cargo_canLoad=1;
			ace_cargo_noRename=1;
			ace_dragging_canDrag = 0;
			ace_dragging_canCarry = 1;
			author="Fleff";
			scope=2;
			model = "\A3\Structures_F_Heli\Items\Luggage\PlasticCase_01_small_F.p3d";
			displayName = "$STR_ace_advrepair_part_enginepistonsmall";
			picture = "pictureThing";
			icon = "iconObject_1x2";
			mapSize=0.69999999;
			armor=500;
			armorStructural=1;
			minTotalDamageThreshold=0.0099999998;
			explosionShielding=1;
			hiddenSelections[] = {"Camo","Camo2"};
			hiddenSelectionsTextures[] = {"a3\Props_F_Enoch\Military\Supplies\Data\PlasticCase_01_olive_CO.paa","z\ace\addons\advrepair\data\advrepair_part_enginepistonsmall.paa"};
			class HitPoints
			{
				class HitBody
				{
					armor=1;
					material=-1;
					name="mat_rim";
					visual="mat_rim";
					passThrough=1;
					radius=0.1;
					explosionShielding=1;
					minimalHit=1;
				};
			};
			class Damage
			{
				tex[]={};
				mat[]=
				{
				};
			};
			editorPreview = "\A3\EditorPreviews_F_Enoch\Data\CfgVehicles\Land_PlasticCase_01_small_olive_F.jpg";
		};

		
		class FL_parts_turretdrive: FL_RepairItem           //small     tan
		{
			ace_cargo_size=1;
			ace_cargo_canLoad=1;
			ace_cargo_noRename=1;
			ace_dragging_canDrag = 0;
			ace_dragging_canCarry = 1;
			author="Fleff";
			scope=2;
			model = "\A3\Structures_F_Heli\Items\Luggage\PlasticCase_01_small_F.p3d";
			displayName = "$STR_ace_advrepair_part_turretdrive";
			picture = "pictureThing";
			icon = "iconObject_1x2";
			mapSize=0.69999999;
			armor=500;
			armorStructural=1;
			minTotalDamageThreshold=0.0099999998;
			explosionShielding=1;
			hiddenSelections[] = {"Camo","Camo2"};
			hiddenselectionsTextures[] = {"a3\structures_f_heli\items\luggage\data\plasticcase_01_co.paa","z\ace\addons\advrepair\data\advrepair_part_turretdrive.paa"};
			class HitPoints
			{
				class HitBody
				{
					armor=1;
					material=-1;
					name="mat_rim";
					visual="mat_rim";
					passThrough=1;
					radius=0.1;
					explosionShielding=1;
					minimalHit=1;
				};
			};
			class Damage
			{
				tex[]={};
				mat[]=
				{
				};
			};
			editorPreview = "\A3\EditorPreviews_F\Data\CfgVehicles\Land_PlasticCase_01_small_F.jpg";
		};
		class FL_parts_fueltanksmall: FL_RepairItem         //medium    tan
		{
			ace_cargo_size=2;
			ace_cargo_canLoad=1;
			ace_cargo_noRename=1;
			ace_dragging_canDrag = 0;
			ace_dragging_canCarry = 1;
			author="Fleff";
			scope=2;
			model = "\A3\Structures_F_Heli\Items\Luggage\PlasticCase_01_medium_F.p3d";
			displayName = "$STR_ace_advrepair_part_fueltanksmall";
			picture = "pictureThing";
			icon = "iconObject_1x2";
			mapSize=0.69999999;
			armor=500;
			armorStructural=1;
			minTotalDamageThreshold=0.0099999998;
			explosionShielding=1;
			hiddenSelections[] = {"Camo","Camo2"};
			hiddenselectionsTextures[] = {"a3\structures_f_heli\items\luggage\data\plasticcase_01_co.paa","z\ace\addons\advrepair\data\advrepair_part_fueltanksmall.paa"};
			class HitPoints
			{
				class HitBody
				{
					armor=1;
					material=-1;
					name="mat_rim";
					visual="mat_rim";
					passThrough=1;
					radius=0.1;
					explosionShielding=1;
					minimalHit=1;
				};
			};
			class Damage
			{
				tex[]={};
				mat[]=
				{
				};
			};
			editorPreview = "\A3\EditorPreviews_F\Data\CfgVehicles\Land_PlasticCase_01_medium_F.jpg";
		};
		class FL_parts_fueltanklarge: FL_RepairItem         //large     tan
		{
			ace_cargo_size=4;
			ace_cargo_canLoad=1;
			ace_cargo_noRename=1;
			ace_dragging_canDrag = 1;
			ace_dragging_canCarry = 0;
			author="Fleff";
			scope=2;
			model = "\A3\Structures_F_Heli\Items\Luggage\PlasticCase_01_large_F.p3d";
			displayName = "$STR_ace_advrepair_part_fueltanklarge";
			picture = "pictureThing";
			icon = "iconObject_1x2";
			mapSize=0.69999999;
			armor=500;
			armorStructural=1;
			minTotalDamageThreshold=0.0099999998;
			explosionShielding=1;
			hiddenSelections[] = {"Camo","Camo2"};
			hiddenselectionsTextures[] = {"a3\structures_f_heli\items\luggage\data\plasticcase_01_co.paa","z\ace\addons\advrepair\data\advrepair_part_fueltanklarge.paa"};
			class HitPoints
			{
				class HitBody
				{
					armor=1;
					material=-1;
					name="mat_rim";
					visual="mat_rim";
					passThrough=1;
					radius=0.1;
					explosionShielding=1;
					minimalHit=1;
				};
			};
			class Damage
			{
				tex[]={};
				mat[]=
				{
				};
			};
			editorPreview = "\A3\EditorPreviews_F\Data\CfgVehicles\Land_PlasticCase_01_large_F.jpg";
		};
		class LandVehicle;
	//Cars
		class Car: LandVehicle {};
		class Car_F: Car {
			class FL_advrepair
			{
				vehicleenginesize = 0;
				vehiclefueltanksize = 0;
				vehiclearmor = 0;
				vehicleengine = "piston";
			};
		};
	//Trucks
		class Truck_F: Car_F {
			class FL_advrepair
			{
				vehicleenginesize = 1;
				vehiclefueltanksize = 1;
				vehiclearmor = 0;
				vehicleengine = "piston";
			};
		};
	//Vans
		class Van_01_base_F: Truck_F {
			class FL_advrepair
			{
				vehicleenginesize = 1;
				vehiclefueltanksize = 0;
				vehiclearmor = 0;
				vehicleengine = "piston";
			};
		};
		class Van_02_base_F: Truck_F {
			class FL_advrepair
			{
				vehicleenginesize = 1;
				vehiclefueltanksize = 0;
				vehiclearmor = 0;
				vehicleengine = "piston";
			};
		};
	//MRAPs
		class MRAP_01_base_F: Car_F {
			class FL_advrepair
			{
				vehicleenginesize = 1;
				vehiclefueltanksize = 0;
				vehiclearmor = 1;
				vehicleengine = "piston";
			};
		};
		class MRAP_02_base_F: Car_F {
			class FL_advrepair
			{
				vehicleenginesize = 1;
				vehiclefueltanksize = 0;
				vehiclearmor = 1;
				vehicleengine = "piston";
			};
		};
		class MRAP_03_base_F: Car_F {
			class FL_advrepair
			{
				vehicleenginesize = 1;
				vehiclefueltanksize = 0;
				vehiclearmor = 1;
				vehicleengine = "piston";
			};
		};
	//Wheeled APC
		class Wheeled_APC_F: Car_F {
			class FL_advrepair
			{
				vehicleenginesize = 1;
				vehiclefueltanksize = 1;
				vehiclearmor = 1;
				vehicleengine = "piston";
			};
		};
	//Wheeled AFV
		class AFV_Wheeled_01_base_F: Wheeled_APC_F {
			class FL_advrepair
			{
				vehicleenginesize = 2;
				vehiclefueltanksize = 1;
				vehiclearmor = 1;
				vehicleengine = "piston";
			};
		};
	//Tracked 
		class Tank: LandVehicle {};
		class Tank_F: Tank {
			class FL_advrepair
			{
				vehicleenginesize = 2;
				vehiclefueltanksize = 1;
				vehiclearmor = 2;
				vehicleengine = "piston";
			};
		};
		class LT_01_base_F: Tank_F {	//Wiesel
			class FL_advrepair
			{
				vehicleenginesize = 1;
				vehiclefueltanksize = 0;
				vehiclearmor = 1;
				vehicleengine = "piston";
			};
		};
	//Tracked APC
		class APC_Tracked_01_base_F: Tank_F {
			class FL_advrepair
			{
				vehicleenginesize = 2;
				vehiclefueltanksize = 1;
				vehiclearmor = 1;
				vehicleengine = "piston";
			};
		};
		class APC_Tracked_02_base_F: Tank_F {
			class FL_advrepair
			{
				vehicleenginesize = 2;
				vehiclefueltanksize = 1;
				vehiclearmor = 1;
				vehicleengine = "piston";
			};
		};
		class APC_Tracked_03_base_F: Tank_F {
			class FL_advrepair
			{
				vehicleenginesize = 2;
				vehiclefueltanksize = 1;
				vehiclearmor = 1;
				vehicleengine = "piston";
			};
		};
	//Helicopter
		class Helicopter;
		class Helicopter_Base_F: Helicopter {
			class FL_advrepair
			{
				vehicleenginesize = 1;
				vehiclefueltanksize = 1;
				vehiclearmor = 0;
				vehicleengine = "turbine";
			};
		};
		class Helicopter_Base_H: Helicopter_Base_F {};
		class Heli_Light_01_base_F: Helicopter_Base_H {
			class FL_advrepair
			{
				vehicleenginesize = 1;
				vehiclefueltanksize = 0;
				vehiclearmor = 0;
				vehicleengine = "turbine";
			};
		}; 
	//Plane
		class Plane;
		class Plane_Base_F: Plane {
			class FL_advrepair
			{
				vehicleenginesize = 2;
				vehiclefueltanksize = 1;
				vehiclearmor = 0;
				vehicleengine = "turbine";
			};
		};
	//Ship
		class Ship;
		class Ship_F: Ship {
			class FL_advrepair
			{
				vehicleenginesize = 0;
				vehiclefueltanksize = 0;
				vehiclearmor = 0;
				vehicleengine = "piston";
			};
		};
};

class ACE_Repair
{
	class Actions
	{
		class ReplaceWheel;
		class RemoveWheel: ReplaceWheel
		{/*
			condition="ace_repair_fnc_canReplaceWheel";*/
			callbackSuccess="ace_advrepair_fnc_doRemoveWheel";
		};
		class MiscRepair: ReplaceWheel {
			repairingTime=10;
		};
		class AdvMajorRepair: MiscRepair
		{
			displayName="$STR_ace_advrepair_RepairMajorPart";
			displayNameProgress="$STR_ace_advrepair_RepairingMajorPart";
			condition="ace_advrepair_fnc_canAdvMajorRepair";
			callbackSuccess="ace_advrepair_fnc_doAdvMajorRepair";
			requiredEngineer="ace_advrepair_MajorRepairPermissions";
			repairLocations[]=
			{
				"ace_advrepair_MajorRepairLocations"
			};
			itemConsumed=0;
			repairingTime=5;
		};
		class OpenRepairGUI: MiscRepair
		{
			displayName="$STR_ace_advrepair_OpenRepairGUI";
			displayNameProgress="$STR_ace_advrepair_OpenningRepairGUI";
			condition="ace_advrepair_fnc_canOpenGUI";
			callbackSuccess="ace_advrepair_fnc_openDialogMain";
			requiredEngineer="ace_repair_engineerSetting_Wheel";
			itemConsumed=0;
			repairingTime=5;
		};
		class RemoveTrack: MiscRepair
		{
			condition="ace_advrepair_fnc_canRemoveTrack";
			callbackSuccess="ace_advrepair_fnc_doRemoveTrack";
		};
		class ReplaceTrack: RemoveTrack
		{
			condition="ace_advrepair_fnc_canReplaceTrack";
		};
		class RemoveRotorAssembly: MiscRepair
		{
			displayName="$STR_ace_advrepair_RemoveRotorAssembly";
			displayNameProgress="$STR_ace_advrepair_RemovingRotorAssembly";
			requiredEngineer="ace_advrepair_MajorRepairPermissions";
			repairLocations[]=
			{
				"ace_advrepair_MajorRepairLocations"
			};
			condition="ace_advrepair_fnc_canRemoveLocked";
			callbackSuccess="ace_advrepair_fnc_doRemoveRotorAssembly";
			itemConsumed=0;
		};
		class ReplaceRotorAssembly: RemoveRotorAssembly
		{
			displayName="$STR_ACE_advrepair_ReplaceRotorAssembly";
			displayNameProgress="$STR_ACE_advrepair_ReplacingRotorAssembly";
			requiredEngineer="ace_advrepair_MajorRepairPermissions";
			repairLocations[]=
			{
				"ace_advrepair_MajorRepairLocations"
			};
			condition="ace_advrepair_fnc_canReplaceLocked";
			callbackSuccess="ace_advrepair_fnc_doReplaceRotorAssembly";
			claimObjects[]=
			{
				
				{
					"FL_parts_rotorassembly"
				}
			};
		};
		class RemoveAvionics: MiscRepair
		{
			displayName="$STR_ace_advrepair_RemoveAvionics";
			displayNameProgress="$STR_ace_advrepair_RemovingAvionics";
			requiredEngineer="ace_advrepair_MajorRepairPermissions";
			repairLocations[]=
			{
				"ace_advrepair_MajorRepairLocations"
			};
			condition="ace_advrepair_fnc_canRemoveLocked";
			callbackSuccess="ace_advrepair_fnc_doRemoveAvionics";
			itemConsumed=0;
		};
		class ReplaceAvionics: RemoveAvionics
		{
			displayName="$STR_ACE_advrepair_ReplaceAvionics";
			displayNameProgress="$STR_ACE_advrepair_ReplacingAvionics";
			requiredEngineer="ace_advrepair_MajorRepairPermissions";
			repairLocations[]=
			{
				"ace_advrepair_MajorRepairLocations"
			};
			condition="ace_advrepair_fnc_canReplaceLocked";
			callbackSuccess="ace_advrepair_fnc_doReplaceAvionics";
			claimObjects[]=
			{
				
				{
					"FL_parts_avionics"
				}
			};
		};
		//Engines
		class RemoveEnginepistonsmall: MiscRepair
		{
			displayName="$STR_ace_advrepair_RemoveEnginepistonsmall";
			displayNameProgress="$STR_ACE_advrepair_RemovingEnginepistonsmall";
			requiredEngineer="ace_advrepair_MajorRepairPermissions";
			repairLocations[]=
			{
				"ace_advrepair_MajorRepairLocations"
			};
			condition="ace_advrepair_fnc_canRemoveLocked";
			callbackSuccess="ace_advrepair_fnc_doRemoveEnginepistonsmall";
			itemConsumed=0;
		};
		class ReplaceEnginepistonsmall: RemoveEnginepistonsmall
		{
			displayName="$STR_ACE_advrepair_ReplaceEnginepistonsmall";
			displayNameProgress="$STR_ACE_advrepair_ReplacingEnginepistonsmall";
			requiredEngineer="ace_advrepair_MajorRepairPermissions";
			repairLocations[]=
			{
				"ace_advrepair_MajorRepairLocations"
			};
			condition="ace_advrepair_fnc_canReplaceLocked";
			callbackSuccess="ace_advrepair_fnc_doReplaceEnginepistonsmall";
			claimObjects[]=
			{
				
				{
					"FL_parts_enginepistonsmall"
				}
			};
		};
		class RemoveEnginepistonmedium: MiscRepair
		{
			displayName="$STR_ace_advrepair_RemoveEnginepistonmedium";
			displayNameProgress="$STR_ACE_advrepair_RemovingEnginepistonmedium";
			requiredEngineer="ace_advrepair_MajorRepairPermissions";
			repairLocations[]=
			{
				"ace_advrepair_MajorRepairLocations"
			};
			condition="ace_advrepair_fnc_canRemoveLocked";
			callbackSuccess="ace_advrepair_fnc_doRemoveEnginepistonmedium";
			itemConsumed=0;
		};
		class ReplaceEnginepistonmedium: RemoveEnginepistonmedium
		{
			displayName="$STR_ACE_advrepair_ReplaceEnginepistonmedium";
			displayNameProgress="$STR_ACE_advrepair_ReplacingEnginepistonmedium";
			requiredEngineer="ace_advrepair_MajorRepairPermissions";
			repairLocations[]=
			{
				"ace_advrepair_MajorRepairLocations"
			};
			condition="ace_advrepair_fnc_canReplaceLocked";
			callbackSuccess="ace_advrepair_fnc_doReplaceEnginepistonmedium";
			claimObjects[]=
			{
				
				{
					"FL_parts_enginepistonmedium"
				}
			};
		};
		class RemoveEnginepistonlarge: MiscRepair
		{
			displayName="$STR_ace_advrepair_RemoveEnginepistonlarge";
			displayNameProgress="$STR_ACE_advrepair_RemovingEnginepistonlarge";
			requiredEngineer="ace_advrepair_MajorRepairPermissions";
			repairLocations[]=
			{
				"ace_advrepair_MajorRepairLocations"
			};
			condition="ace_advrepair_fnc_canRemoveLocked";
			callbackSuccess="ace_advrepair_fnc_doRemoveEnginepistonlarge";
			itemConsumed=0;
		};
		class ReplaceEnginepistonlarge: RemoveEnginepistonlarge
		{
			displayName="$STR_ACE_advrepair_ReplaceEnginepistonlarge";
			displayNameProgress="$STR_ACE_advrepair_ReplacingEnginepistonlarge";
			requiredEngineer="ace_advrepair_MajorRepairPermissions";
			repairLocations[]=
			{
				"ace_advrepair_MajorRepairLocations"
			};
			condition="ace_advrepair_fnc_canReplaceLocked";
			callbackSuccess="ace_advrepair_fnc_doReplaceEnginepistonlarge";
			claimObjects[]=
			{
				
				{
					"FL_parts_enginepistonlarge"
				}
			};
		};
		class RemoveEngineturbinesmall: MiscRepair
		{
			displayName="$STR_ace_advrepair_RemoveEngineturbinesmall";
			displayNameProgress="$STR_ACE_advrepair_RemovingEngineturbinesmall";
			requiredEngineer="ace_advrepair_MajorRepairPermissions";
			repairLocations[]=
			{
				"ace_advrepair_MajorRepairLocations"
			};
			condition="ace_advrepair_fnc_canRemoveLocked";
			callbackSuccess="ace_advrepair_fnc_doRemoveEngineturbinesmall";
			itemConsumed=0;
		};
		class ReplaceEngineturbinesmall: RemoveEngineturbinesmall
		{
			displayName="$STR_ACE_advrepair_ReplaceEngineturbinesmall";
			displayNameProgress="$STR_ACE_advrepair_ReplacingEngineturbinesmall";
			requiredEngineer="ace_advrepair_MajorRepairPermissions";
			repairLocations[]=
			{
				"ace_advrepair_MajorRepairLocations"
			};
			condition="ace_advrepair_fnc_canReplaceLocked";
			callbackSuccess="ace_advrepair_fnc_doReplaceEngineturbinesmall";
			claimObjects[]=
			{
				
				{
					"FL_parts_engineturbinesmall"
				}
			};
		};
		class RemoveEngineturbinelarge: MiscRepair
		{
			displayName="$STR_ace_advrepair_RemoveEngineturbinelarge";
			displayNameProgress="$STR_ACE_advrepair_RemovingEngineturbinelarge";
			requiredEngineer="ace_advrepair_MajorRepairPermissions";
			repairLocations[]=
			{
				"ace_advrepair_MajorRepairLocations"
			};
			condition="ace_advrepair_fnc_canRemoveLocked";
			callbackSuccess="ace_advrepair_fnc_doRemoveEngineturbinelarge";
			itemConsumed=0;
		};
		class ReplaceEngineturbinelarge: RemoveEngineturbinelarge
		{
			displayName="$STR_ACE_advrepair_ReplaceEngineturbinelarge";
			displayNameProgress="$STR_ACE_advrepair_ReplacingEngineturbinelarge";
			requiredEngineer="ace_advrepair_MajorRepairPermissions";
			repairLocations[]=
			{
				"ace_advrepair_MajorRepairLocations"
			};
			condition="ace_advrepair_fnc_canReplaceLocked";
			callbackSuccess="ace_advrepair_fnc_doReplaceEngineturbinelarge";
			claimObjects[]=
			{
				
				{
					"FL_parts_engineturbinelarge"
				}
			};
		};
		//Fueltanks
		class RemoveFueltanksmall: MiscRepair
		{
			displayName="$STR_ace_advrepair_RemoveFueltanksmall";
			displayNameProgress="$STR_ACE_advrepair_RemovingFueltanksmall";
			requiredEngineer="ace_advrepair_MajorRepairPermissions";
			repairLocations[]=
			{
				"ace_advrepair_MajorRepairLocations"
			};
			condition="ace_advrepair_fnc_canRemoveLocked";
			callbackSuccess="ace_advrepair_fnc_doRemoveFueltanksmall";
			itemConsumed=0;
		};
		class ReplaceFueltanksmall: RemoveFueltanksmall
		{
			displayName="$STR_ACE_advrepair_ReplaceFueltanksmall";
			displayNameProgress="$STR_ACE_advrepair_ReplacingFueltanksmall";
			requiredEngineer="ace_advrepair_MajorRepairPermissions";
			repairLocations[]=
			{
				"ace_advrepair_MajorRepairLocations"
			};
			condition="ace_advrepair_fnc_canReplaceLocked";
			callbackSuccess="ace_advrepair_fnc_doReplaceFueltanksmall";
			claimObjects[]=
			{
				
				{
					"FL_parts_Fueltanksmall"
				}
			};
		};
		class RemoveFueltanklarge: MiscRepair
		{
			displayName="$STR_ace_advrepair_RemoveFueltanklarge";
			displayNameProgress="$STR_ACE_advrepair_RemovingFueltanklarge";
			requiredEngineer="ace_advrepair_MajorRepairPermissions";
			repairLocations[]=
			{
				"ace_advrepair_MajorRepairLocations"
			};
			condition="ace_advrepair_fnc_canRemoveLocked";
			callbackSuccess="ace_advrepair_fnc_doRemoveFueltanklarge";
			itemConsumed=0;
		};
		class ReplaceFueltanklarge: RemoveFueltanklarge
		{
			displayName="$STR_ACE_advrepair_ReplaceFueltanklarge";
			displayNameProgress="$STR_ACE_advrepair_ReplacingFueltanklarge";
			requiredEngineer="ace_advrepair_MajorRepairPermissions";
			repairLocations[]=
			{
				"ace_advrepair_MajorRepairLocations"
			};
			condition="ace_advrepair_fnc_canReplaceLocked";
			callbackSuccess="ace_advrepair_fnc_doReplaceFueltanklarge";
			claimObjects[]=
			{
				
				{
					"FL_parts_Fueltanklarge"
				}
			};
		};
		class RemoveControlsurfaces: MiscRepair
		{
			displayName="$STR_ace_advrepair_RemoveControlsurfaces";
			displayNameProgress="$STR_ACE_advrepair_RemovingControlsurfaces";
			requiredEngineer="ace_advrepair_MajorRepairPermissions";
			repairLocations[]=
			{
				"ace_advrepair_MajorRepairLocations"
			};
			condition="ace_advrepair_fnc_canRemoveLocked";
			callbackSuccess="ace_advrepair_fnc_doRemoveControlsurfaces";
			itemConsumed=0;
		};
		class ReplaceControlsurfaces: RemoveControlsurfaces
		{
			displayName="$STR_ACE_advrepair_ReplaceControlsurfaces";
			displayNameProgress="$STR_ACE_advrepair_ReplacingControlsurfaces";
			requiredEngineer="ace_advrepair_MajorRepairPermissions";
			repairLocations[]=
			{
				"ace_advrepair_MajorRepairLocations"
			};
			condition="ace_advrepair_fnc_canReplaceLocked";
			callbackSuccess="ace_advrepair_fnc_doReplaceControlsurfaces";
			claimObjects[]=
			{
				
				{
					"FL_parts_Controlsurfaces"
				}
			};
		};
		class RemoveGunFCS: MiscRepair
		{
			displayName="$STR_ace_advrepair_RemoveGunFCS";
			displayNameProgress="$STR_ACE_advrepair_RemovingGunFCS";
			requiredEngineer="ace_advrepair_MajorRepairPermissions";
			repairLocations[]=
			{
				"ace_advrepair_MajorRepairLocations"
			};
			condition="ace_advrepair_fnc_canRemoveLocked";
			callbackSuccess="ace_advrepair_fnc_doRemoveGunFCS";
			itemConsumed=0;
		};
		class ReplaceGunFCS: RemoveGunFCS
		{
			displayName="$STR_ACE_advrepair_ReplaceGunFCS";
			displayNameProgress="$STR_ACE_advrepair_ReplacingGunFCS";
			requiredEngineer="ace_advrepair_MajorRepairPermissions";
			repairLocations[]=
			{
				"ace_advrepair_MajorRepairLocations"
			};
			condition="ace_advrepair_fnc_canReplaceLocked";
			callbackSuccess="ace_advrepair_fnc_doReplaceGunFCS";
			claimObjects[]=
			{
				
				{
					"FL_parts_gunfcs"
				}
			};
		};
		class RemoveTurretdrive: MiscRepair
		{
			displayName="$STR_ace_advrepair_RemoveTurretdrive";
			displayNameProgress="$STR_ACE_advrepair_RemovingTurretdrive";
			requiredEngineer="ace_advrepair_MajorRepairPermissions";
			repairLocations[]=
			{
				"ace_advrepair_MajorRepairLocations"
			};
			condition="ace_advrepair_fnc_canRemoveLocked";
			callbackSuccess="ace_advrepair_fnc_doRemoveTurretdrive";
			itemConsumed=0;
		};
		class ReplaceTurretdrive: RemoveTurretdrive
		{
			displayName="$STR_ACE_advrepair_ReplaceTurretdrive";
			displayNameProgress="$STR_ACE_advrepair_ReplacingTurretdrive";
			requiredEngineer="ace_advrepair_MajorRepairPermissions";
			repairLocations[]=
			{
				"ace_advrepair_MajorRepairLocations"
			};
			condition="ace_advrepair_fnc_canReplaceLocked";
			callbackSuccess="ace_advrepair_fnc_doReplaceTurretdrive";
			claimObjects[]=
			{
				
				{
					"FL_parts_turretdrive"
				}
			};
		};
	};
};

class CfgWeapons {
	class ACE_ItemCore;
	class CBA_MiscItem_ItemInfo;
	class advrepair_SpareParts: ACE_ItemCore {
		displayName = "Spare Parts Kit";
		author="Fleff";
		descriptionShort = "Used in repair of various vehicle parts";
		model = "\A3\Weapons_F\Items\Toolkit";
		picture = "\A3\Weapons_F\Items\data\UI\gear_Toolkit_CA.paa";
		scope = 2;
		ACE_isTool = 1;
		class ItemInfo: CBA_MiscItem_ItemInfo
		{
			mass=10;
		};
	};
	class ToolKit;
	class ToolKitItem;
	class advrepair_ToolkitLight: ToolKit {
		displayName = "Lightweight Toolkit";
		author="Fleff";
		descriptionShort = "A lighter version of the regular toolkit";
		model = "\A3\Weapons_F\Items\Toolkit";
		picture = "\A3\Weapons_F\Items\data\UI\gear_Toolkit_CA.paa";
		scope = 2;
		ACE_isTool = 1;
		class ItemInfo: ToolKitItem
		{
			mass=40;
		};
	};
};
