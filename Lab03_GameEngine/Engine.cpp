#include "Engine.h"

Engine* Engine::instance = nullptr;

void Engine::Load()
{
}

void Engine::Initialize()
{
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
	while (isRunning)
	{
		Time::Instance().Update();
		AssetManager::Instance().Update();
		InputManager::Instance().Update();
		SceneManager::Instance().Update();
		RenderSystem::Instance().Update();
	}
}
