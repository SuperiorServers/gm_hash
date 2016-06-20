#include "GarrysMod/Lua/Interface.h"
#include <stdio.h>

#include "md5.h"
#include "sha256.h"
#include "sha512.h"

using namespace GarrysMod::Lua;

int hash_MD5(lua_State* state)
{
	if (LUA->CheckString(1))
	{
		LUA->PushString(md5((std::string)LUA->GetString(1)).data());
		return 1;
	}

	return 0;
}

int hash_SHA256(lua_State* state)
{
	if (LUA->CheckString(1))
	{
		LUA->PushString(sha256((std::string)LUA->GetString(1)).data());
		return 1;
	}

	return 0;
}

int hash_SHA512(lua_State* state)
{
	if (LUA->CheckString(1))
	{
		LUA->PushString(sha512((std::string)LUA->GetString(1)).data());
		return 1;
	}

	return 0;
}

GMOD_MODULE_OPEN()
{
	LUA->PushSpecial(GarrysMod::Lua::SPECIAL_GLOB);
		LUA->CreateTable();

			LUA->PushCFunction(hash_MD5);
			LUA->SetField(-2, "MD5");

			LUA->PushCFunction(hash_SHA256);
			LUA->SetField(-2, "SHA256");

			LUA->PushCFunction(hash_SHA512);
			LUA->SetField(-2, "SHA512");

		LUA->SetField(-2, "hash");
	LUA->Pop();
	
	return 0;
}

GMOD_MODULE_CLOSE()
{
	return 0;
}