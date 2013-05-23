#include<lua.h>
#include<lualib.h>
#include<laulib.h>

int divide(lua_State *s){
	double a=lua_tonumber(s,-2);
	double b=lua_tonumber(s,-1);
	int quot=(int)a/(int）b;
	int rem=(int)a%(int)b;
	lua_pushnumber(s,quot);
	lua_pushnumber(s,rem);
	return 2;
}

int main(){
	lua_State *s=luaL_newstate();
	luaL_openlibs(s);
	lua_register(s,"div",divide);
	luaL_dofile(s,"hello2.lua");
	lua_close(s);
	return 0;
}
