#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = QUOTE(COMPONENT);
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
        requiredAddons[] = {
            "ace_repair",
        };
        author = "Fleff";
        authors[] = {"Fleff","ACE-Team"};
        url = "";
        VERSION_CONFIG;
        skipWhenMissingDependencies = 1;
    };
};

#include "CfgEventHandlers.hpp"
#include "CfgVehicles.hpp"
#include "CfgWeapons.hpp"

#include "ACE_Repair.hpp"

#include "UI\BaseControls.hpp"
#include "UI\RscDisplayMain.hpp"
#include "UI\RscDisplayMajorParts.hpp"
#include "UI\RscDisplayMinorParts.hpp"

class CfgVehicleClasses {
    class FL_Logistics_Items {
        displayName="$STR_advrepair_main_logisticsparts";
    };
};

class CfgEditorSubcategories {
    class FL_parts_subcategory {
        displayName="$STR_advrepair_main_parts";
    };
};
