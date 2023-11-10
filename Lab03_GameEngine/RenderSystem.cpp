#include "RenderSystem.h"

RenderSystem* RenderSystem::instance = nullptr;

void RenderSystem::Initialize()
{
	window = SDL_CreateWindow("SDL Example", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, fullScreen);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
}

void RenderSystem::Destroy()
{
	SDL_DestroyWindow(window);
	SDL_Quit();

	if (instance != nullptr)
	{
		delete instance;
	}
}

void RenderSystem::Update()
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		if (event.window.event == SDL_WINDOWEVENT_CLOSE)
		{
			Destroy();
		}
	}

	SDL_RenderPresent(renderer);
}

void RenderSystem::Load(json::JSON& _json)
{
	if (_json.hasKey("name"))
	{
		name = _json["name"].ToString();
	}

	if (_json.hasKey("width"))
	{
		width = _json["width"].ToInt();
	}

	if (_json.hasKey("height"))
	{
		height = _json["height"].ToInt();
	}

	if (_json.hasKey("fullscreen"))
	{
		fullScreen = _json["fullscreen"].ToBool();
	}
}

void RenderSystem::Display()
{
}
