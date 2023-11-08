#pragma once

#ifndef _OBJECT_H_
#define _OBJECT_H_

#include <string>
#include "json.hpp"

class Object
{
private:
	bool initialized = false;
	std::string name = "";
	int id = 0;

protected:
	Object();
	virtual ~Object();
	virtual void Initialize() = 0;
	virtual void Destroy() {};

public:
	void Load(json::JSON& _json);
	bool isInitialized() { return initialized; }
	std::string& GetName() { return name; }
	int GetId() { return id; }
};
#endif // !_OBJECT_H_
