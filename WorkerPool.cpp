#include "WorkerPool.h"
#include <iostream>

WorkerPool::WorkerPool(const int count) : workers(), taskQueue(), mutex(), cv(), shutdownFlag(false){
	for (int i = 0; i < count; ++i) {
		Worker w(taskQueue, mutex, cv, shutdownFlag);
		workers.emplace_back(std::move(w));
	}
}

void WorkerPool::submit(std::function<void()> task) {
	std::unique_lock<std::mutex> lock(mutex);
	taskQueue.emplace(std::move(task));
	lock.unlock();
	cv.notify_one();
}

void WorkerPool::shutdown() {
	{
		std::unique_lock<std::mutex> lock(mutex);
		auto& tq = taskQueue;
		cv.wait(lock, [&tq]() { return tq.empty(); });
	}
	shutdownFlag = true;
	cv.notify_all();
	for (auto& it : workers) {
		it.join();
	}
}