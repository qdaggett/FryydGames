#pragma once

#if _DEBUG
	#pragma comment(lib, "sfml-window-s-d.lib")
	#pragma comment(lib, "sfml-graphics-s-d.lib")
	#pragma comment(lib, "sfml-system-s-d.lib")
	#pragma comment(lib, "sfml-audio-s-d.lib")
#else
	#pragma comment(lib, "sfml-window-s.lib")
	#pragma comment(lib, "sfml-graphics-s.lib")
	#pragma comment(lib, "sfml-system-s.lib")
	#pragma comment(lib, "sfml-audio-s.lib")

#endif

#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "winmm.lib")
#pragma comment(lib, "gdi32.lib")
#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "freetype.lib")
#pragma comment(lib, "jpeg.lib")
#pragma comment(lib, "glew32s.lib")

//audio settings

#pragma comment (lib, "openal32.lib")
#pragma comment (lib,"flac.lib")
#pragma comment (lib,"vorbisenc.lib")
#pragma comment (lib,"vorbisfile.lib")
#pragma comment (lib,"vorbis.lib")
#pragma comment (lib,"ogg.lib")

#define SFML_STATIC
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>

#define GLEW_STATIC
#include <GL\glew.h>

#include "shader.h"
#include "sprite.h"
#include "matrix4x4.h"
#include "vector3.h"
#include "text.h"
#include "debug.h"
#include "window.h"
#include "shapes.h"

typedef sf::Keyboard Input;