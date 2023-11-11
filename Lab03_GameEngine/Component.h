#pragma once

#ifndef _COMPONENT_H_
#define _COMPONENT_H_

#include "Object.h"
#include <string>

class Component : public Object
{
private:
	friend class Entity;

protected:
	Component();
	~Component() override;

	void Initialize() override;
	void Destroy() override;
	virtual void Update();

public:
	void Load(json::JSON& _json);
};

#endif // !_COMPONENT_H_

