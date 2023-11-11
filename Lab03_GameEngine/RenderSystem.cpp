#include "RenderSystem.h"
#include "Engine.h"
RenderSystem* RenderSystem::instance = nullptr;

void RenderSystem::Initialize()
{
	Load();
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
			Engine::Instance().SetIsRunning(false);
		}
	}

	SDL_RenderPresent(renderer);
}

void RenderSystem::Load()
{
	std::ifstream inputStream("RenderSystem.json");
	if (!inputStream.is_open()) {
		std::cerr << "Error: Unable to open RenderSystem.json" << std::endl;
		return;
	}

	std::string str((std::istreambuf_iterator<char>(inputStream)), std::istreambuf_iterator<char>());
	json::JSON documentData = json::JSON::Load(str);

	try
	{
		if (documentData.hasKey("name"))
		{
			if (typeid(documentData["name"].ToString()) == typeid(std::string))
			{
				name = documentData["name"].ToString();
			}
			else
			{
				std::cerr << "Error: 'name' is not a string type." << std::endl;
			}
		}
		else
		{
			std::cerr << "Error: 'name' key not found in JSON data." << std::endl;
		}

		if (documentData.hasKey("width"))
		{
			try
			{
				width = documentData["width"].ToInt();
			}
			catch (const std::exception& ex)
			{
				std::cerr << "Error: Failed to convert 'width' to an int. " << ex.what() << std::endl;
			}
		}
		else
		{
			std::cerr << "Error: 'width' key not found in JSON data." << std::endl;
		}

		if (documentData.hasKey("height"))
		{
			try
			{
				height = documentData["height"].ToInt();
			}
			catch (const std::exception& ex)
			{
				std::cerr << "Error: Failed to convert 'height' to an int. " << ex.what() << std::endl;
			}
		}
		else
		{
			std::cerr << "Error: 'height' key not found in JSON data." << std::endl;
		}

		if (documentData.hasKey("fullscreen"))
		{
			if (typeid(documentData["fullscreen"].ToBool()) == typeid(bool))
			{
				fullScreen = documentData["fullscreen"].ToBool();
			}
			else
			{
				std::cerr << "Error: 'fullscreen' is not a bool type." << std::endl;
			}
		}
		else
		{
			std::cerr << "Error: 'fullscreen' key not found in JSON data." << std::endl;
		}
	}
	catch(std::exception& ex)
	{
		std::cerr << "Error: " << ex.what() << std::endl;
		throw;
	}
}

void RenderSystem::Display()
{
	for (auto renderable : renderables)
	{
		renderable->Render();
	}
}
