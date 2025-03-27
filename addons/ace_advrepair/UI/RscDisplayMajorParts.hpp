////////////////////////////////////////////////////////
// GUI EDITOR OUTPUT START (by PLAYER 1, v1.063, #Jesuju)
////////////////////////////////////////////////////////
class advrepair_dialog_MajorParts
{
	idd = 1665;
	class controls
	{
		class Main_Frame: RscFrame
		{
			idc = 1800;
			x = 0.346512 * safezoneW + safezoneX;
			y = 0.291 * safezoneH + safezoneY;
			w = 0.306977 * safezoneW;
			h = 0.374 * safezoneH;
		};
		class Main_Background: RscText
		{
			idc = 1801;
			x = 0.346512 * safezoneW + safezoneX;
			y = 0.291 * safezoneH + safezoneY;
			w = 0.306977 * safezoneW;
			h = 0.374 * safezoneH;
			colorBackground[] = {0, 0, 0, 0.7};
		};
		class Main_ListBox: RscListNBox
		{
			idc = 1400;
			type = CT_LISTNBOX;
			x = 0.350349 * safezoneW + safezoneX;
			y = 0.335 * safezoneH + safezoneY;
			w = 0.299302 * safezoneW;
			h = 0.319 * safezoneH;
			columns[] = {0, 0.25,0.55};
			sizeEx = 0.025 * safezoneH;
			
			class ListScrollBar : ScrollBar //ListScrollBar is class name required for Arma 3
			{
				color[] = {1,1,1,0.6};
				colorActive[] = {1,1,1,1};
				colorDisabled[] = {1,1,1,0.3};
				thumb = "#(argb,8,8,3)color(1,1,1,1)";
				arrowEmpty = "#(argb,8,8,3)color(1,1,1,1)";
				arrowFull = "#(argb,8,8,3)color(1,1,1,1)";
				border = "#(argb,8,8,3)color(1,1,1,1)";
				shadow = 0;
			};
		};
		class Main_ListBoxLabel: RscListNBox
		{
			idc = 1401;
			type = CT_LISTNBOX;
			x = 0.350349 * safezoneW + safezoneX;
			y = 0.302 * safezoneH + safezoneY;
			w = 0.299302 * safezoneW;
			h = 0.022 * safezoneH;
			columns[] = {0, 0.25,0.55};
			sizeEx = 0.025 * safezoneH;
		};
		class Main_PageChangeMiscParts: RscButton
		{
			idc = 1601;
			text = "Minor Parts"; //--- ToDo: Localize;
			x = 0.423256 * safezoneW + safezoneX;
			y = 0.676 * safezoneH + safezoneY;
			w = 0.072907 * safezoneW;
			h = 0.033 * safezoneH;
			sizeEx = 0.025 * safezoneH;
		};
		class Main_PageChangeMainPage: RscButton
		{
			idc = 1602;
			text = "Main Page"; //--- ToDo: Localize;
			x = 0.346512 * safezoneW + safezoneX;
			y = 0.676 * safezoneH + safezoneY;
			w = 0.072907 * safezoneW;
			h = 0.033 * safezoneH;
			sizeEx = 0.025 * safezoneH;
		};
		class Main_PageChangeFuelStats: RscButton
		{
			idc = 1603;
			text = "Fuel Stats"; //--- ToDo: Localize;
			x = 0.503837 * safezoneW + safezoneX;
			y = 0.676 * safezoneH + safezoneY;
			w = 0.072907 * safezoneW;
			h = 0.033 * safezoneH;
			sizeEx = 0.025 * safezoneH;
		};
		class Main_PageChangeAmmoStats: RscButton
		{
			idc = 1604;
			text = "Ammo Stats"; //--- ToDo: Localize;
			x = 0.580581 * safezoneW + safezoneX;
			y = 0.676 * safezoneH + safezoneY;
			w = 0.072907 * safezoneW;
			h = 0.033 * safezoneH;
			sizeEx = 0.025 * safezoneH;
		};
		class Main_ReplacePart: RscButton
		{
			idc = 1605;
			//onButtonClick = QUOTE([] spawn FUNC(guiDoReplace));
			text = "Replace Selected Part"; //--- ToDo: Localize;
			x = 0.350349 * safezoneW + safezoneX;
			y = 0.236 * safezoneH + safezoneY;
			w = 0.134302 * safezoneW;
			h = 0.044 * safezoneH;
			sizeEx = 0.025 * safezoneH;
		};
		class Main_RemovePart: RscButton
		{
			idc = 1606;
			//onButtonClick = QUOTE([] spawn FUNC(guiDoRemove));
			text = "Remove Selected Part"; //--- ToDo: Localize;
			x = 0.515349 * safezoneW + safezoneX;
			y = 0.236 * safezoneH + safezoneY;
			w = 0.134302 * safezoneW;
			h = 0.044 * safezoneH;
			sizeEx = 0.025 * safezoneH;
		};
	};
};
////////////////////////////////////////////////////////
// GUI EDITOR OUTPUT END
////////////////////////////////////////////////////////
