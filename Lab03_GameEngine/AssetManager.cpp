#include "AssetManager.h"
AssetManager* AssetManager::instance = nullptr;

void AssetManager::AddAsset(Asset* _asset)
{
	assets.push_back(_asset);
}

void AssetManager::RemoveAsset(Asset* _asset)
{
	assets.remove(_asset);
}

void AssetManager::Initialize()
{
	for (auto& asset : assets)
	{
		asset->Initialize();
	}
}

void AssetManager::Destroy()
{
	for (auto& asset : assets)
	{
		asset->Destroy();
		delete asset;
	}
	assets.clear();

	if (instance != nullptr)
	{
		delete instance;
	}
}

void AssetManager::Update()
{
}
