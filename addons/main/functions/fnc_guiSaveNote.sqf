#include "..\script_component.hpp"
_Target = localNamespace getVariable "advrep_GUI_Target";

_Display = findDisplay 1664;
_ctrl = _Display displayCtrl 1400;
_text = ctrlText _ctrl;

_Target setVariable ["advrep_GUI_note",_text];

hint "Text saved";