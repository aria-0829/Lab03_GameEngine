#pragma once
#ifndef _ENGINE_H_
#define _ENGINE_H_

class Engine
{
private:
	static Engine* instance;

	void Load();

	inline explicit Engine() = default;
	inline ~Engine() = default;
	inline explicit Engine(Engine const&) = delete;
	inline Engine& operator=(Engine const&) = delete;

public:
	static Engine& Instance()
	{
		if (instance == nullptr)
		{
			instance = new Engine();
		}
		return *instance;
	}

	void Initialize();
	void Destroy();
	void GameLoop();
};
#endif // !_ENGINE_H_
