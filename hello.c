#include<lua.h>
#include<lualib.h>
#include<lauxlib.h>

char *code = "for i=0, 5 do print(\'Hello World!\') end";

int main(){
	lua_State *s=luaL_newstate();
	luaL_openlibs(s);
	luaL_dostring(s,code);
	lua_close(s);
	return 0;
}
