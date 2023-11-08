#pragma once
#ifndef _SCENE_MANAGER_H_
#define _SCENE_MANAGER_H_

#include "Scene.h"
#include "Entity.h"
#include <list>
#include <string>

class SceneManager
{
private:
	static SceneManager* instance;

	friend class Engine;

	inline explicit SceneManager() = default;
	inline ~SceneManager() = default;
	inline explicit SceneManager(SceneManager const&) = delete;
	inline SceneManager& operator=(SceneManager const&) = delete;

	std::list<Scene*> scenes;
	Scene* activeScene;

public:
	static SceneManager& Instance()
	{
		if (instance == nullptr)
		{
			instance = new SceneManager();
		}
		return *instance;
	}

	void AddScene(std::string _fileName);
	void RemoveScene(std::string _fileName);
	Entity* GetEntity();
	void RemoveEntity(Entity* _entity);
	void SetActiveScene(int _id);
	Scene* GetActiveScene();
	Entity* FindEntity(int _id);

protected:
	void Initialize();
	void Destroy();
	void Update();
};

#endif // !_SCENE_MANAGER_H_