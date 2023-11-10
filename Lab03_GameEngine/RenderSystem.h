#pragma once
#ifndef _RENDER_SYSTEM_H_
#define _RENDER_SYSTEM_H_

#include <list>
#include <string>
#include "IRenderable.h"
#include "json.hpp"
#include <fstream>
#include "SDL.h"

class IRenderable;

class RenderSystem
{
private:
	static RenderSystem* instance;

	friend class Engine;

	inline explicit RenderSystem() = default;
	inline ~RenderSystem() = default;
	inline explicit RenderSystem(RenderSystem const&) = delete;
	inline RenderSystem& operator=(RenderSystem const&) = delete;

	std::string name = "";
	int width = 640;
	int height = 640;
	bool fullScreen = false;
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;
	std::list<IRenderable*> renderables;

public:
	static RenderSystem& Instance()
	{
		if (instance == nullptr)
		{
			instance = new RenderSystem();
		}
		return *instance;
	}

	//void AddRenderable(IRenderable* _renderable);
	//void RemoveRenderable(IRenderable* _renderable);

protected:
	void Initialize();
	void Destroy();
	void Update();
	void Load(json::JSON& _json);
	void Display();
};

#endif // !_RENDER_SYSTEM_H_


