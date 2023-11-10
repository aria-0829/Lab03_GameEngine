#pragma once
#ifndef _TIME_H_
#define _TIME_H_

#include <chrono>

class Time
{
private:
	static Time* instance;

	unsigned int frameCount = 0;
	std::chrono::duration<float> deltaTime = std::chrono::duration<float>(0.0f);
	std::chrono::time_point<std::chrono::system_clock> beginTime;
	std::chrono::time_point<std::chrono::system_clock> endTime;
	std::chrono::duration<float> totalTime = std::chrono::duration<float>(0.0f);


	friend class Engine;

	inline explicit Time() = default;
	//inline ~Time() = default;
	inline explicit Time(Time const&) = delete;
	inline Time& operator=(Time const&) = delete;

protected:
	void Initialize(); 
	void Update();

public:
	inline static Time& Instance()
	{
		if (instance == nullptr)
		{
			instance = new Time();
			instance->Initialize();
		}
		return *instance;
	}

	inline void Destroy()
	{
		if (instance != nullptr)
		{
			delete instance;
		}
	}

	float DeltaTime() { return deltaTime.count(); }
	float TotalTime() { return totalTime.count(); }
	unsigned int FrameCount() { return frameCount; }
};

#endif // !_TIME_H_