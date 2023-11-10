#include "Engine.h"

Engine* Engine::instance = nullptr;

void Engine::Load(json::JSON& _json)
{
	//RenderSystem::Instance().Load();
}

void Engine::Initialize()
{
	std::ifstream inputStream("RenderSystem.json");
	std::string str((std::istreambuf_iterator<char>(inputStream)), std::istreambuf_iterator<char>());
	json::JSON documentData = json::JSON::Load(str);

	Load(documentData);

	RenderSystem::Instance().Initialize();
	InputManager::Instance().Initialize();
	AssetManager::Instance().Initialize();
	SceneManager::Instance().Initialize();
}

void Engine::Destroy()
{
	Time::Instance().Destroy();
	SceneManager::Instance().Destroy();
	AssetManager::Instance().Destroy();
	InputManager::Instance().Destroy();
	RenderSystem::Instance().Destroy();
}

void Engine::GameLoop()
{
	while (true)
	{
		Time::Instance().Update();
		AssetManager::Instance().Update();
		InputManager::Instance().Update();
		SceneManager::Instance().Update();
		RenderSystem::Instance().Update();
	}
}
