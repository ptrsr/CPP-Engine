#ifndef LuaParser_hpp
#define LuaParser_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include "SFML\Graphics.hpp"
#include "Component.h"
#include "../Lua/src/lua.hpp"
#include "ImageCache.h"

class LuaParser : public Component {
    
public:
    LuaParser(std::string startFunc = "main");
	static std::string func;
	virtual void Update();
    
private:
    lua_State * lua;
	static ImageCache * cache;

};

#endif
