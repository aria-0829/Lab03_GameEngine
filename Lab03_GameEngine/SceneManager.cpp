#include "SceneManager.h"
SceneManager* SceneManager::instance = nullptr;

void SceneManager::AddScene(std::string _fileName)
{
	std::ifstream inputStream("_fileName");
	if (!inputStream.is_open()) {
		std::cerr << "Error: Unable to open: " << _fileName << std::endl;
		return;
	}

	std::string str((std::istreambuf_iterator<char>(inputStream)), std::istreambuf_iterator<char>());
	json::JSON sceneData = json::JSON::Load(str);

	Scene* scene = new Scene();
	scenes.push_back(scene);
	scene->Load(sceneData);
	scene->Initialize();
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
