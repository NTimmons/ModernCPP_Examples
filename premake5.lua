solution "CPPExtensionExample"
   configurations { "Debug", "Release" }


   project "CPPExtensionExample"
      kind "ConsoleApp"
      language "C++"
	  
      files { "**.h", "**.cpp" }

      configuration "Debug"
         defines { "DEBUG" }
		 symbols "on"
		 buildoptions { "/std:c++latest" }

      configuration "Release"
         defines { "NDEBUG" }
         flags { "Optimize" }
		 buildoptions { "/std:c++latest" }