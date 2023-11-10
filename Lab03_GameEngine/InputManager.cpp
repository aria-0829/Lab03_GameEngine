#include "InputManager.h"
InputManager* InputManager::instance = nullptr;

void InputManager::Initialize()
{
}

void InputManager::Destroy()
{
	if (instance != nullptr)
	{
		delete instance;
	}
}

void InputManager::Update()
{
}
