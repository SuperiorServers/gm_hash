solution "gm_hash"

	language "C++"
	location ( os.get() .."-".. _ACTION )
	flags { "Symbols", "NoEditAndContinue", "NoPCH", "StaticRuntime", "EnableSSE" }
	targetdir ( "lib/" .. os.get() .. "/" )
	includedirs { "../_include/", "../_source-sdk-2013/mp/src/public/"}
	
	libdirs {
		'../_source-sdk-2013/mp/src/lib/public'
	}

	links {
		'tier0',
		'tier1',
		'tier2',
		'steam_api'
	}

	configurations
	{ 
		"Release"
	}
	
	configuration "Release"
		defines { "NDEBUG" }
		flags{ "Optimize", "FloatFast" }
	
	configuration "Debug"
		defines { }
		flags{ }
	
	project "gm_hash"
		defines { "GMMODULE" }
		files { "src/**.*", "../_include/**.*"}
		kind "SharedLib"
		