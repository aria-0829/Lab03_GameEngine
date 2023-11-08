#pragma once

#ifndef _ENTITY_H_
#define _ENTITY_H_

#include "Object.h"
#include <list>

class Component;

class Entity final : public Object
{
private:
	friend class Scene;

	std::list<Component*> components;

protected:
	Entity();
	~Entity();

	void Initialize() override;
	void Destroy() override;
	virtual void Update();

public:
	void Load(json::JSON& _json);

	Component* CreateComponent(std::string _componentType);
	void RemoveComponent(Component* _component);
};

#endif // !_ENTITY_H_


