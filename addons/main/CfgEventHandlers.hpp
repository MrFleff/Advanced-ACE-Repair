
class Extended_PreStart_EventHandlers {
	class ADDON {
		init = QUOTE(call COMPILE_SCRIPT(XEH_preStart));
	};
};

class Extended_PreInit_EventHandlers {
	class ADDON {
		init = QUOTE(call COMPILE_SCRIPT(XEH_preInit));
	};
};

class Extended_InitPost_EventHandlers {
	class Car {
		class ace_repair {
			init="_this call advrepair_main_fnc_addAdvRepairActions";
		};
	};
	class Motorcycle {
		class ace_repair {
			init="_this call advrepair_main_fnc_addAdvRepairActions";
		};
	};
	class Tank {
		class ace_repair {
			init="_this call advrepair_main_fnc_addAdvRepairActions";
		};
	};
	class Helicopter {
		class ace_repair {
			init="_this call advrepair_main_fnc_addAdvRepairActions";
			exclude[]=
			{
				"ace_fastroping_helper",
				"ACE_friesBase",
				"ace_refuel_helper"
			};
		};
	};
	class Plane {
		class ace_repair {
			init="_this call advrepair_main_fnc_addAdvRepairActions";
		};
	};
	class Ship_F {
		class ace_repair {
			init="_this call advrepair_main_fnc_addAdvRepairActions";
		};
	};
	class ACE_RepairItem_Base {
		class ace_repair {
			init="_this call advrepair_main_fnc_addPartAdvRepairActions";
		};
	};
};
