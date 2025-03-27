#define COMPONENT advrepair
#define COMPONENT_BEAUTIFIED advrepair
#define REPLACEMOD ace_repair
#define REPLACEPATH "z\ace\addons\repair"

#include "\z\ace\addons\main\script_mod.hpp"

#include "\z\ace\addons\main\script_macros.hpp"

#define TRACK_HITPOINTS ["hitltrack", "hitrtrack"]

#define ROTOR_HITPOINTS ["hitvrotor", "hithrotor"]

#define FUELTANK_HITPOINTS ["hitfuel", "hitfuel2", "hitfuelr", "hitfuell"]

#define CONTROLSURFACES_HITPOINTS ["hitlaileron", "hitraileron", "hitlcrudder", "hitrrudder", "hitlcelevator", "hitrelevator"]

#define GUN_HITPOINTS ["hitgun", "hitcomgun"]

#define TURRET_HITPOINTS ["hitturret", "hitcomturret"]

#define ALL_HITPOINTS ["hitavionics,"hitltrack", "hitrtrack","hitvrotor", "hithrotor","hitfuel", "hitfuel2", "hitfuelr", "hitfuell","hitlaileron", "hitraileron", "hitlcrudder", "hitrrudder", "hitlcelevator", "hitrelevator","hitgun", "hitcomgun","hitturret", "hitcomturret"]

#define DAMAGE_COLOR_SCALE ["#FFFFFF", "#FFFF7E", "#FFEC4D", "#FFD52C", "#FCB121", "#FF9916", "#FF7D16", "#FF4400", "#FF0000"]

#define IN_REPAIR_FACILITY_CACHE_EXPIRY 1

#define NEAR_REPAIR_VEHICLE_CACHE_EXPIRY 1

#define ANY_TOOLKIT_FAKECLASS QGVAR(anyToolKit)

#define PATCH_WHEEL_STEP_TIME 0.05

#define HELIENGINE_HITPOINTS ["hitengine","hitengine1","hitengine2","hitengine3","hitengine4"]