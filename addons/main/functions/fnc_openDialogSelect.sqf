#include "..\script_component.hpp"
params ["_select","_Target"];
private["_select","_Target"];

diag_log "PreSelect";
diag_log _Target;

if (isNil "_Target") then {
    _Target = localNamespace getVariable "advrep_GUI_Target";
} else {
    localNamespace setVariable ["advrep_GUI_Target",_Target];
};

diag_log "PostSelect";
diag_log _Target;

switch (_select) do {
    case 0: {[_Target] spawn FUNC(openDialogMain);};
    case 1: {[_Target] spawn FUNC(openDialogMajor);};
    case 2: {[_Target] spawn FUNC(openDialogMinor);};
};
