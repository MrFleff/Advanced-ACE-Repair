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
