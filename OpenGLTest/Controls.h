#pragma once
#include <iostream>
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <SDL2/SDL.h>
class Controls
{
public:
	Controls();
	glm::vec3 keyContr(glm::vec3* move);
	~Controls();

private:
	glm::vec3* move;
	SDL_Event event;
	const Uint8 *keyState;
};

