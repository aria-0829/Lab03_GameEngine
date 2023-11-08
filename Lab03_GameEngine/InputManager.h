#pragma once
#ifndef _INPUT_MANAGER_H_
#define _INPUT_MANAGER_H_

class InputManager
{
private:
	static InputManager* instance;

	friend class Engine;

	inline explicit InputManager() = default;
	inline ~InputManager() = default;
	inline explicit InputManager(InputManager const&) = delete;
	inline InputManager& operator=(InputManager const&) = delete;

public:
	static InputManager& Instance()
	{
		if (instance == nullptr)
		{
			instance = new InputManager();
		}
		return *instance;
	}

protected:
	void Initialize();
	void Destroy();
	void Update();
};

#endif // !_INPUT_MANAGER_H_

