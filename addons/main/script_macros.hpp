#include "\x\cba\addons\main\script_macros_common.hpp"

#define DFUNC(var1) TRIPLES(ADDON,fnc,var1)

#ifdef DISABLE_COMPILE_CACHE
    #undef PREP
    #define PREP(fncName) DFUNC(fncName) = compile preprocessFileLineNumbers QPATHTOF(functions\DOUBLES(fnc,fncName).sqf)
#else
    #undef PREP
    #define PREP(fncName) [QPATHTOF(functions\DOUBLES(fnc,fncName).sqf), QFUNC(fncName)] call CBA_fnc_compileFunction
#endif

#define ACESTRING(var1) QUOTE(DOUBLES(STR_ace_repair,var1))
#define EACESTRING(var1,var2) QUOTE(TRIPLES(STR,DOUBLES(ace,var1),var2))

#define ACEVAR(var1,var2) TRIPLES(ace,var1,var2)
#define QACEVAR(var1,var2) QUOTE(ACEVAR(var1,var2))
