#pragma once
#include <thread>
#include <queue>
#include <functional>
#include <mutex>
#include <condition_variable>

class Worker {
	std::thread t;
	std::queue<std::function<void()>>& taskQueue;
	std::mutex& mutex;
	std::condition_variable& conditionVariable;
	std::atomic<bool>& shutdownFlag;
public:
	Worker(std::queue<std::function<void()>>& taskQueue, std::mutex& mutex, std::condition_variable& cv, std::atomic<bool>& shutdownFlag);

	void execute();
	void join();

};