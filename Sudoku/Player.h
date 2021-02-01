#pragma once
#include <thread>
#include <chrono>
#include "Field.h"

class Player : private Field
{
public:
	void StartMenu();
	void TaskIsStarted();

private:
	int choise;

	class Clock
	{
	private:
		std::chrono::steady_clock::time_point start, end;
		std::chrono::duration<float> time;
	public:
		void StartClock();
		void EndClock();
		void SeeTime();

	};

	Clock clock;
};
