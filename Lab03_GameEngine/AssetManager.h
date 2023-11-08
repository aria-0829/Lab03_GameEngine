#pragma once
#ifndef _ASSET_MANAGER_H_
#define _ASSET_MANAGER_H_

#include "Asset.h"
#include <list>

class AssetManager
{
private:
	static AssetManager* instance;

	friend class Engine;

	inline explicit AssetManager() = default;
	inline ~AssetManager() = default;
	inline explicit AssetManager(AssetManager const&) = delete;
	inline AssetManager& operator=(AssetManager const&) = delete;

	std::list<Asset*> assets;

public:
	static AssetManager& Instance()
	{
		if (instance == nullptr)
		{
			instance = new AssetManager();
		}
		return *instance;
	}

	void AddAsset(Asset* _asset);
	void RemoveAsset(Asset* _asset);

protected:
	void Initialize();
	void Destroy();
	void Update();
};

#endif // !_ASSET_MANAGER_H_

