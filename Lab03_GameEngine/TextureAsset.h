#pragma once
#ifndef _TEXTURE_ASSET_H_
#define _TEXTURE_ASSET_H_

#include "Asset.h"

class TextureAsset : public Asset
{
public:
	TextureAsset();
	~TextureAsset();

	void Load(json::JSON& _json);
};
#endif // !_TEXTURE_ASSET_H_


