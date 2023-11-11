#include "Entity.h"

Entity::Entity()
{
}

Entity::~Entity()
{
}

void Entity::Initialize()
{
}

void Entity::Destroy()
{
}

void Entity::Update()
{
}

void Entity::Load(json::JSON& _json)
{
}

Component* Entity::CreateComponent(std::string _componentType)
{
	return nullptr;
}

void Entity::RemoveComponent(Component* _component)
{
	components.remove(_component);
}
