#include "Scene.h"

void Scene::Initialize()
{
}

void Scene::Destroy()
{
}

void Scene::Update()
{
}

void Scene::Load(json::JSON& _json)
{
}

Scene::Scene()
{
}

Scene::~Scene()
{
}

Entity* Scene::CreateEntity()
{
	return nullptr;
}

void Scene::RemoveEntity(Entity* _entity)
{
	entities.remove(_entity);
}

Entity* Scene::FindEntityById(int _id)
{
	return nullptr;
}
