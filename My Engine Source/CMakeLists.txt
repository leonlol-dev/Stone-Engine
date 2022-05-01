cmake_minimum_required(VERSION 3.0)
project(MYENGINE)

include_directories(
 src # For MyEngine.h
 contrib # For glm.hpp
)

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /SAFESEH:NO")

if(MSVC)
 include_directories(
 contrib/SDL2/include # For SDL.h
 contrib/glew/include # For glew.h
 contrib/openal/include # For openal.h
 )
 link_directories(
 ${CMAKE_SOURCE_DIR}/contrib/SDL2/lib
 ${CMAKE_SOURCE_DIR}/contrib/glew/lib
 ${CMAKE_SOURCE_DIR}/contrib/openal/lib
 )
else()
 # Linux, Emscripten, macOS equivalents
endif()
# Avoid the weird SDL2main hack
if(MSVC)
 add_definitions(-DSDL_MAIN_HANDLED)
endif()


add_library(leonengine
src/leonsengine/Core.cpp
src/leonsengine/Core.h
src/leonsengine/Entity.cpp
src/leonsengine/Entity.h
src/leonsengine/Component.cpp
src/leonsengine/Component.h
src/leonsengine/Screen.cpp
src/leonsengine/Screen.h
src/leonsengine/Environment.cpp
src/leonsengine/Environment.h
src/leonsengine/TriangleRenderer.cpp
src/leonsengine/TriangleRenderer.h
src/leonsengine/VertexBuffer.cpp
src/leonsengine/VertexBuffer.h
src/leonsengine/VertexArray.cpp
src/leonsengine/VertexArray.h
src/leonsengine/ShaderProgram.cpp
src/leonsengine/ShaderProgram.h
src/leonsengine/Keyboard.cpp
src/leonsengine/Keyboard.h
src/leonsengine/Transform.cpp
src/leonsengine/Transform.h
src/leonsengine/AudioSource.cpp
src/leonsengine/AudioSource.h
src/leonsengine/AudioClip.cpp
src/leonsengine/AudioClip.h
src/leonsengine/Exception.cpp
src/leonsengine/Exception.h
src/leonsengine/SphereCollider.cpp
src/leonsengine/SphereCollider.h
src/leonsengine/Trigger.cpp
src/leonsengine/Trigger.h
src/leonsengine/Resource.h
src/leonsengine/Resource.cpp
src/leonsengine/Resources.h
src/leonsengine/Resources.cpp
src/leonsengine/Model.h
src/leonsengine/Model.cpp
src/leonsengine/ModelRenderer.h
src/leonsengine/ModelRenderer.cpp
src/leonsengine/Material.h
src/leonsengine/Material.cpp
src/leonsengine/Texture.h
src/leonsengine/Texture.cpp
src/leonsengine/Camera.h
src/leonsengine/Camera.cpp
src/leonsengine/bugl.h
src/leonsengine/myEngine.h
)

add_executable(game
src/demo/main.cpp
src/demo/Player.cpp
src/demo/Player.h
src/demo/Enemy.cpp
src/demo/Enemy.h
src/demo/Music.cpp
src/demo/Music.h
)

target_link_libraries(leonengine SDL2 glew32 opengl32 openal32)
target_link_libraries(game leonengine)
