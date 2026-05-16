#pragma once
#include <queue>
#include <functional>

class TaskQueue {
	std::queue<std::function<void()>> tasks;
};