#include "GarrysMod/Lua/Interface.h"
#include <time.h>

#include "tier1/checksum_md5.h"
#include "md5.h"
#include "sha256.h"
#include "sha512.h"

using namespace GarrysMod::Lua;

static const char* chars = "0123456789!@#$%^&*ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

int hash_Salt(lua_State* state)
{
	if (LUA->CheckNumber(1))
	{
		unsigned count = LUA->GetNumber(1);
		char* salt = new char[count];

		srand(time(NULL));
		for (unsigned i = 0;  i < count; ++i)
		{
			salt[i] = chars['a' + rand() % 26];
		}

		LUA->PushString(salt, count);

		delete[] salt;

		return 1;
	}

	return 0;
}

int hash_PseudoRandom(lua_State* state)
{
	if (LUA->CheckNumber(1))
	{
		LUA->PushNumber((double)MD5_PseudoRandom((unsigned int)LUA->GetNumber(1)));
		return 1;
	}

	return 0;
}


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
		
			//LUA->PushCFunction(hash_Salt);
			//LUA->SetField(-2, "Salt");

			LUA->PushCFunction(hash_PseudoRandom);
			LUA->SetField(-2, "PseudoRandom");

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