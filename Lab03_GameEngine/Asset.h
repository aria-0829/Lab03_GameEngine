#pragma once
#ifndef _ASSET_H_
#define _ASSET_H_

#include "Object.h"

class Asset : public Object
{
private:
	friend class AssetManager;

protected:
	Asset();
	~Asset();

public:
	void Load(json::JSON& _json);
};

#endif // !_ASSET_H_

