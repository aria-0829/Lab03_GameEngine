#include "AssetManager.h"
AssetManager* AssetManager::instance = nullptr;

void AssetManager::AddAsset(Asset* _asset)
{
}

void AssetManager::RemoveAsset(Asset* _asset)
{
}

void AssetManager::Initialize()
{
}

void AssetManager::Destroy()
{
	if (instance != nullptr)
	{
		delete instance;
	}
}

void AssetManager::Update()
{
}
