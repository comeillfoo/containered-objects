#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>


struct config {
    int version;
    char const* name;  
};


static int l_supply_config(lua_State* l) {
    struct config config = {
        .version = 1,
        .name = "example"
    };
    
    lua_newtable(l);
    lua_pushinteger(l, config.version);
    lua_pushstring(l, config.name);
    lua_setfield(l, -3, "name");
    lua_setfield(l, -2, "version");

    luaL_setmetatable(l, "config");
    return 1;
}


int luaopen_libsupplier(lua_State* l) {
    static const struct luaL_Reg supplier[] = {
        {"supply_config", l_supply_config},
        {NULL, NULL}
    };

    luaL_newlib(l, supplier);
    return 1;
}