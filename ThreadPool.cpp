#include "ThreadPool.h"

int main()
{
	TaskQueue taskQueue;
	WorkerPool workerPool(4);
	taskQueue.populateQueue(8);
	auto& task = taskQueue.getTask();
	workerPool.submit(task);

	return 0;
}
