#include "WorkerPool.h"

WorkerPool::WorkerPool(const int count) : workers(), cv() {
	for (int i = 0; i < count; ++i) {
		Worker w;
		workers.emplace_back(std::move(w));
	}
}

void WorkerPool::submit(std::function<void()>& task) {

}

void WorkerPool::shutdown() {

}