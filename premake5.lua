
workspace "pbgi"
    if _ACTION then
        location( "build/" )
    end

    configurations{ "Debug", "Release" }

    filter "configurations:Debug"
        defines { "DEBUG" }
        flags { "Symbols" }

    filter "configurations:Release"
        defines { "NDEBUG" }
        optimize "On"

    project "app"
        kind "ConsoleApp"
        language "C++"
        targetdir "bin"
        files { "src/**.cpp", "src/**.h", "3rdparty/src/*.cpp" }
        includedirs { "src/", "3rdparty/include/" }
        links { "glew32", "opengl32", "glfw3" }
        libdirs { "3rdparty/lib/" }

        postbuildcommands {
            "{COPY} ../3rdparty/bin/glew32.dll %{cfg.targetdir}",
            "{COPY} ../release/Data %{cfg.targetdir}/Data"
        }

        filter "configurations:Debug"
            debugdir "bin"
