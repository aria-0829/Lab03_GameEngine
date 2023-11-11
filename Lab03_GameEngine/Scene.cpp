#include "Scene.h"

void Scene::Initialize()
{
    for (auto& entity : entities)
    {
		entity->Initialize();
	}
}

void Scene::Destroy()
{
    for (auto& entity : entities)
    {
		entity->Destroy();
		delete entity;
	}
	entities.clear();
}

void Scene::Update()
{
    for (auto& entity : entities)
    {
        entity->Update();
    }
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
    Entity* newEntity = new Entity();
    entities.push_back(newEntity);
    return newEntity;
}

void Scene::RemoveEntity(Entity* _entity)
{
	entities.remove(_entity);
}

Entity* Scene::FindEntityById(int _id)
{
    for (const auto& entity : entities)
    {
        if (entity->GetId() == _id)
        {
            return entity;
        }
    }

	return nullptr;
}
