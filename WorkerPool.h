#pragma once
#include <vector>
#include <functional>
#include <condition_variable>
#include "Worker.h"

class WorkerPool {
	std::vector<Worker> workers;
	std::queue<std::function<void()>> taskQueue;
	std::condition_variable cv;
	std::mutex mutex;
	std::atomic<bool> shutdownFlag;

public:
	WorkerPool() = delete;
	WorkerPool(const int count);

	void submit(std::function<void()> task);
	void shutdown();
};