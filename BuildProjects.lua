solution "gm_hash"

	language "C++"
	location ( os.get() .."-".. _ACTION )
	flags { "Symbols", "NoEditAndContinue", "NoPCH", "StaticRuntime", "EnableSSE" }
	targetdir ( "lib/" .. os.get() .. "/" )
	includedirs { "../_include/"}

	configurations
	{ 
		"Release"
	}
	
	configuration "Release"
		defines { "NDEBUG" }
		flags{ "Optimize", "FloatFast" }

	project "gm_crypto"
		defines { "GMMODULE" }
		files { "src/**.*", "../_include/**.*"}
		kind "SharedLib"
		