#include "SceneManager.h"
SceneManager* SceneManager::instance = nullptr;

void SceneManager::AddScene(std::string _fileName)
{
}

void SceneManager::RemoveScene(std::string _fileName)
{
}

Entity* SceneManager::GetEntity()
{
	return nullptr;
}

void SceneManager::RemoveEntity(Entity* _entity)
{
}

void SceneManager::SetActiveScene(int _id)
{
}

Scene* SceneManager::GetActiveScene()
{
	return nullptr;
}

Entity* SceneManager::FindEntity(int _id)
{
	return nullptr;
}

void SceneManager::Initialize()
{
}

void SceneManager::Destroy()
{
	if (instance != nullptr)
	{
		delete instance;
	}
}

void SceneManager::Update()
{
}
