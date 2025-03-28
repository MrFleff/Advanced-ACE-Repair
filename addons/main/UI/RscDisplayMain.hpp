////////////////////////////////////////////////////////
// GUI EDITOR OUTPUT START (by PLAYER 1, v1.063, #Jesuju)
////////////////////////////////////////////////////////
class advrepair_dialog_Main
{
	idd = 1664;
	class controls
	{
		class Main_Frame: RscFrame
		{
			idc = 1800;
			x = QUOTE(0.346512 * safezoneW + safezoneX);
			y = QUOTE(0.291 * safezoneH + safezoneY);
			w = QUOTE(0.306977 * safezoneW);
			h = QUOTE(0.374 * safezoneH);
		};
		class Main_Background: RscText
		{
			idc = 1801;
			x = QUOTE(0.346512 * safezoneW + safezoneX);
			y = QUOTE(0.291 * safezoneH + safezoneY);
			w = QUOTE(0.306977 * safezoneW);
			h = QUOTE(0.374 * safezoneH);
			colorBackground[] = {0, 0, 0, 0.7};
		};
		class Main_VehicleName: RscText
		{
			idc = 1000;
			text = "Vehicle Name"; //--- ToDo: Localize;
			x = QUOTE(0.350349 * safezoneW + safezoneX);
			y = QUOTE(0.302 * safezoneH + safezoneY);
			w = QUOTE(0.19186 * safezoneW);
			h = QUOTE(0.044 * safezoneH);
			sizeEx = QUOTE(0.06 * safezoneH);
		};
		class Main_Notebox: RscEdit
		{
			idc = 1400;
			x = QUOTE(0.350349 * safezoneW + safezoneX);
			y = QUOTE(0.401 * safezoneH + safezoneY);
			w = QUOTE(0.299302 * safezoneW);
			h = QUOTE(0.253 * safezoneH);
			lineSpacing = 1;
			sizeEx = QUOTE(0.025 * safezoneH);
		};
		class Main_NoteboxSave: RscButton
		{
			idc = 1600;
			onButtonClick = QUOTE([] call FUNC(guiSaveNote));
			text = "Save Note"; //--- ToDo: Localize;
			x = QUOTE(0.469303 * safezoneW + safezoneX);
			y = QUOTE(0.357 * safezoneH + safezoneY);
			w = QUOTE(0.0613954 * safezoneW);
			h = QUOTE(0.033 * safezoneH);
			sizeEx = QUOTE(0.025 * safezoneH);
		};
		class Main_PageChangeMiscParts: RscButton
		{
			idc = 1601;
			text = "Minor Parts"; //--- ToDo: Localize;
			x = QUOTE(0.423256 * safezoneW + safezoneX);
			y = QUOTE(0.676 * safezoneH + safezoneY);
			w = QUOTE(0.072907 * safezoneW);
			h = QUOTE(0.033 * safezoneH);
			sizeEx = QUOTE(0.025 * safezoneH);
		};
		class Main_PageChangeMajorParts: RscButton
		{
			idc = 1602;
			text = "Major Parts"; //--- ToDo: Localize;
			x = QUOTE(0.346512 * safezoneW + safezoneX);
			y = QUOTE(0.676 * safezoneH + safezoneY);
			w = QUOTE(0.072907 * safezoneW);
			h = QUOTE(0.033 * safezoneH);
			sizeEx = QUOTE(0.025 * safezoneH);
		};
		class Main_PageChangeFuelStats: RscButton
		{
			idc = 1603;
			text = "Fuel Stats"; //--- ToDo: Localize;
			x = QUOTE(0.503837 * safezoneW + safezoneX);
			y = QUOTE(0.676 * safezoneH + safezoneY);
			w = QUOTE(0.072907 * safezoneW);
			h = QUOTE(0.033 * safezoneH);
			sizeEx = QUOTE(0.025 * safezoneH);
		};
		class Main_PageChangeAmmoStats: RscButton
		{
			idc = 1604;
			text = "Ammo Stats"; //--- ToDo: Localize;
			x = QUOTE(0.580581 * safezoneW + safezoneX);
			y = QUOTE(0.676 * safezoneH + safezoneY);
			w = QUOTE(0.072907 * safezoneW);
			h = QUOTE(0.033 * safezoneH);
			sizeEx = QUOTE(0.025 * safezoneH);
		};
		class Main_VehicleConfigStats: RscListBox
		{
			idc = 1500;
			x = QUOTE(0.546046 * safezoneW + safezoneX);
			y = QUOTE(0.302 * safezoneH + safezoneY);
			w = QUOTE(0.103605 * safezoneW);
			h = QUOTE(0.088 * safezoneH);
			sizeEx = QUOTE(0.025 * safezoneH);
		};
		class Main_NoteboxName: RscText
		{
			idc = 1001;
			text = "Vehicle Notes:"; //--- ToDo: Localize;
			x = QUOTE(0.350349 * safezoneW + safezoneX);
			y = QUOTE(0.357 * safezoneH + safezoneY);
			w = QUOTE(0.103605 * safezoneW);
			h = QUOTE(0.033 * safezoneH);
			sizeEx = QUOTE(0.025 * safezoneH);
		};
	};
};
////////////////////////////////////////////////////////
// GUI EDITOR OUTPUT END
////////////////////////////////////////////////////////
