#include "Worker.h"


Worker::Worker(std::queue<std::function<void()>>& taskQueue, std::mutex& mutex, std::condition_variable& conditionVariable, std::atomic<bool>& shutdownFlag)
	: taskQueue(taskQueue), mutex(mutex), conditionVariable(conditionVariable), shutdownFlag(shutdownFlag) {
	this->execute();
}

void Worker::execute()
{
	auto& tq = taskQueue;
	auto& m = mutex;
	auto& cv = conditionVariable;
	auto& sf = shutdownFlag;
	t = std::thread([&tq, &m, &cv, &sf]() {
		std::function<void()> task;
		std::unique_lock<std::mutex> lock(m);
		while (sf == false) {
			cv.wait(lock, [&tq, &sf]() {return !tq.empty() || sf.load() == true;});
			if (tq.empty() && sf.load() == true) break;
			if (tq.empty()) continue;
			task = tq.front();
			tq.pop();
			lock.unlock();
			task();
			lock.lock();
			cv.notify_all();
		}
	});
}

void Worker::join() { if(t.joinable()) t.join(); }