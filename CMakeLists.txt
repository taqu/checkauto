cmake_minimum_required(VERSION 3.16)
set(PROJECT_NAME check)
project(${PROJECT_NAME})
set(PROJECT_VERSION 1.0.0)
set(PROJECT_ROOT ${CMAKE_CURRENT_SOURCE_DIR})

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(AFTER ${PROJECT_ROOT})

set(HEADERS "SugoiDekai.h")
set(SOURCES "SugoiDekai.cpp;main.cpp")

source_group("include" FILES ${HEADERS})
source_group("src" FILES ${SOURCES})

add_executable(${PROJECT_NAME} ${HEADERS} ${SOURCES})
set_target_properties(${PROJECT_NAME} PROPERTIES
    OUTPUT_NAME_DEBUG "${PROJECT_NAME}d" OUTPUT_NAME_RELEASE "${PROJECT_NAME}")

if(MSVC)

    set(DEFAULT_CXX_FLAGS "/DWIN32 /D_WINDOWS /D_UNICODE /DUNICODE /W4 /WX- /nologo /fp:precise /arch:AVX /Oi /Zc:wchar_t /TP /Gd")

    if(MSVC_VERSION VERSION_LESS_EQUAL "1900")
        set(DEFAULT_CXX_FLAGS "${DEFAULT_CXX_FLAGS} /Zc:__cplusplus /std:c++latest")
    else()
        set(DEFAULT_CXX_FLAGS "${DEFAULT_CXX_FLAGS} /Zc:__cplusplus /std:c++17")
    endif()

    set(CMAKE_CXX_FLAGS "${DEFAULT_CXX_FLAGS}")
    set(CMAKE_CXX_FLAGS_DEBUG "/D_DEBUG /MDd /Zi /Ob0 /Od /RTC1 /Gy /GR- /GS /Gm- /EHsc")
    set(CMAKE_CXX_FLAGS_RELEASE "/MD /O2 /Oi /GL /GR- /DNDEBUG /EHsc-")

elseif(UNIX)
    set(DEFAULT_CXX_FLAGS "-Wall -Wextra -O2 -std=c++17 -march=x86-64-v3 -fno-exceptions")
elseif(XCODE)
endif()

