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
	for (const auto& scene : scenes)
	{
		scene->RemoveEntity(_entity);
	}
}

void SceneManager::SetActiveScene(int _id)
{
	for (const auto& scene : scenes)
	{
		if (scene->GetId() == _id)
		{
			activeScene = scene;
			return;
		}
	}
}

Scene* SceneManager::GetActiveScene()
{
	return activeScene;
}

Entity* SceneManager::FindEntityById(int _id)
{
	for (const auto& scene : scenes)
	{
		Entity* entity = scene->FindEntityById(_id);
		if (entity != nullptr)
		{
			return entity;
		}
	}

	return nullptr;
}

void SceneManager::Initialize()
{
	for (auto& scene : scenes)
	{
		scene->Initialize();
	}
}

void SceneManager::Destroy()
{
	for (auto& scene : scenes)
	{
		scene->Destroy();
		delete scene;
	}
	scenes.clear();

	if (instance != nullptr)
	{
		delete instance;
	}
}

void SceneManager::Update()
{
	for (auto& scene : scenes)
	{
		scene->Update();
	}
}
