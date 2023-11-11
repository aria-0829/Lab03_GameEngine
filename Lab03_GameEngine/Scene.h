#pragma once
#ifndef _SCENE_H_
#define _SCENE_H_

#include "Entity.h"
#include <list>
#include "json.hpp"

class Scene
{
private:
	friend class SceneManager;

	std::list<Entity*> entities;
	std::string name = "";
	int id = 0;

protected:
	void Initialize();
	void Destroy();
	void Update();
	void Load(json::JSON& _json);

public:
	Scene();
	~Scene();
	
	Entity* CreateEntity();
	void RemoveEntity(Entity* _entity);
	Entity* FindEntityById(int _id);
	int GetId() { return id; }
};

#endif // !_SCENE_H_


