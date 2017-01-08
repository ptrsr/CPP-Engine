#include "LuaParser.hpp"
#include "World.h"
#include "InputHandler.h"
#include "SFML\Window\Mouse.hpp"
#include "SpriteComponent.h"

std::string LuaParser::func;

int Write(lua_State * lua) 
{
    std::cout << lua_tostring(lua, -1) << std::endl; 
    return 0;
}

int Visit(lua_State * lua)
{
	LuaParser::func = lua_tostring(lua, -1);
	return 0;
}

int Image(lua_State * lua)
{
	std::string path = lua_tostring(lua, -3);
	sf::Vector2f pos = sf::Vector2f(lua_tonumber(lua, -2), lua_tonumber(lua, -1));

	GameObject* object = new GameObject(path, pos);
	object->AddComponent(new SpriteComponent(ImageCache::Push(path)));
	World::AddChild(object);

	return 0;
}

int Button(lua_State * lua)
{
	std::string path = lua_tostring(lua, -3);
	sf::Vector2f pos = sf::Vector2f(lua_tonumber(lua, -2), lua_tonumber(lua, -1));

	GameObject* object = new GameObject(path, pos);
	sf::Texture* texture = ImageCache::Push(path);

	object->AddComponent(new SpriteComponent(texture));
	World::AddChild(object);

	if (InputHandler::GetButtonDown(sf::Mouse::Button::Left))
	{
		sf::Vector2i mousePos = InputHandler::GetMousePos();
		sf::Vector2u imageSize = texture->getSize();

		if (mousePos.x >= pos.x && mousePos.y >= pos.y
			&& mousePos.x <= pos.x + imageSize.x && mousePos.y <= pos.y + imageSize.y)
		{
			lua_pushboolean(lua, true);
			return 1;
		}
	}
	lua_pushboolean(lua, false);
	return 1;
}

LuaParser::LuaParser(std::string startFunc) 
{
	func = startFunc;

    lua = luaL_newstate();
    luaL_openlibs(lua);
    
	luaL_dofile(lua, "main.lua");

    lua_pushcfunction(lua, Write);
    lua_setglobal(lua, "write");

	lua_pushcfunction(lua, Image);
	lua_setglobal(lua, "image");

	lua_pushcfunction(lua, Button);
	lua_setglobal(lua, "button");

	lua_pushcfunction(lua, Visit);
	lua_setglobal(lua, "visit");
}

void LuaParser::Update()
{	
	std::vector<GameObject*> &children = World::Get().children;

	for (int i = children.size() - 1; i >= 0; --i)
		delete children[i];

	lua_getglobal(lua, const_cast<char*>(func.c_str()));

	if (lua_isfunction(lua, lua_gettop(lua)))
		lua_call(lua, 0, 0);
}