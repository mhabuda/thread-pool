#pragma once
#include <vector>
#include <functional>
#include <condition_variable>
#include "Worker.h"

class WorkerPool {
	std::vector<Worker> workers;
	std::condition_variable cv;
public:
	WorkerPool(const int count);

	void submit(std::function<void()>& task);

	void shutdown();
};