#include "..\script_component.hpp"
params ["_rowsel"];
private["_rowsel"];

_Display = findDisplay 1665;
_lnb = _Display displayCtrl 1400;
if (isNil "_rowsel") then {
    _rowsel = lnbCurSelRow _lnb;
};

_target = missionNamespace getVariable (_lnb lnbData [0,3]);
_partsel = _lnb lnbText [_rowsel,1];
_dmg = _target getHitPointDamage _partsel;
_partheal = ParseNumber (_lnb lnbText [_rowsel,2]);
_finalhp = _dmg - _partheal / 100;

if (_dmg <= 0) exitWith {
    hint "No more parts in need of repair.";
};
if !(([player, "advrepair_SpareParts"] call BIS_fnc_hasItem)) exitWith {
    hint "No more spare parts found in inventory.";
};

_nextrow = _rowsel;
if (_finalhp <= 0) then {
    _finalhp = 0;
    _nextrow = _rowsel + 1;
};

player removeItem "advrepair_SpareParts";
_target setHitPointDamage [_partsel,_finalhp];
_newdmg = format ["%1%% HP",round((100 - 100 * _finalhp) * (10 ^ 2)) / (10 ^ 2)];
_lnb lnbsetText [[_rowsel,0],_newdmg];

[_nextrow] call FUNC(guiRepairAllPart);
