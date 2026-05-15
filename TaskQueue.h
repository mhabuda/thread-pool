#pragma once
#include <queue>
#include <functional>

class TaskQueue {
	std::queue<std::function<void()>> tasks;
public:
	void addTask(const std::function<void()>& task);
	std::function<void()>& getTask();
	void populateQueue(const int count);
	std::queue<std::function<void()>>& getQueue();
};