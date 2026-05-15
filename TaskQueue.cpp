#include "TaskQueue.h"
#include <iostream>

void TaskQueue::addTask(const std::function<void()>& task) {
	std::cout << "Adding task to queue, total tasks: " << tasks.size() + 1 << std::endl;
	tasks.push(task);
}

std::function<void()>& TaskQueue::getTask() {
	// empty check should be done by caller
	std::cout << "Getting task from queue, remaining tasks: " << tasks.size() - 1 << std::endl;
	auto& task = tasks.front();
	tasks.pop();
	return task;
}

void TaskQueue::populateQueue(const int count) {
	for (int i = 0; i < count; ++i) {
		addTask([i]() {
			std::cout << "Executing number " << i + 1 << "!" << std::endl;
			});
	}
}

std::queue<std::function<void()>>& TaskQueue::getQueue()
{
	return tasks;
}
