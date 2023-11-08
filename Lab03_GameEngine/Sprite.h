#pragma once
#ifndef _SPRITE_H_
#define _SPRITE_H_

#include "Component.h"
#include "IRenderable.h"

class Sprite : public Component, IRenderable
{
public:
	Sprite();
	//~Sprite();

	void Load(json::JSON& _json);

protected:
	void Destroy() override;
	void Update() override;
	void Render() override;
};

#endif // !_SPRITE_H_
