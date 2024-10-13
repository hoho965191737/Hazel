workspace "Hazel"
	architecture "x64"

	configurations{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "Hazel/vendor/GLFW/include"
IncludeDir["Glad"] = "Hazel/vendor/Glad/include"

include "Hazel/vendor/GLFW"
include "Hazel/vendor/Glad"

project "Hazel"
	location "Hazel"
	kind "SharedLib"
	language "C++"
	
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "hzpch.h"
	pchsource "Hazel/src/hzpch.cpp"

	-- **.h 表示 从该文件类型递归搜索文件夹
	files{
		"%{prj.name}/src/**.h",  
		"%{prj.name}/src/**.cpp",
	}

	includedirs{
		"%{wks.location}/Hazel/src",
		"%{wks.location}/Hazel/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
	}

	links{
		"GLFW",
		"Glad",
		"opengl32.lib",
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"
	
		defines{
			"HZ_PLATFORM_WINDOWS",
			"HZ_BUILD_DLL",
			"GLFW_INCLUDE_NONE",
		}
		
	filter "configurations:Debug"
		defines "HZ_DEBUG"
		buildoptions "/MDd"
		symbols "On"

	filter "configurations:Release"
		defines "HZ_RELEASE"
		buildoptions "/MD"
		optimize "On"

	filter "configurations:Dist"
		defines "HZ_DIST"
		buildoptions "/MD"
		optimize "On"


project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files{
		"%{prj.name}/src/**.h",  
		"%{prj.name}/src/**.cpp",
	}

	includedirs{
		"%{wks.location}/Hazel/vendor/spdlog/include",
		"%{wks.location}/Hazel/src",
	}

	links{
		"Hazel"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"
	
		defines{
			"HZ_PLATFORM_WINDOWS",
		}

		postbuildcommands{
			("{COPY} ../bin/" .. outputdir .. "/Hazel/Hazel.dll" .. " ../bin/" .. outputdir .. "/%{prj.name}")
		}

	filter "configurations:Debug"
		defines "HZ_DEBUG"
		buildoptions "/MDd"
		symbols "On"

	filter "configurations:Release"
		defines "HZ_RELEASE"
		buildoptions "/MD"
		optimize "On"

	filter "configurations:Dist"
		defines "HZ_DIST"
		buildoptions "/MD"
		optimize "On"
		