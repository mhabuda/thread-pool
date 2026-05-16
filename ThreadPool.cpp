#include "ThreadPool.h"

int main()
{
	WorkerPool workerPool(4);
	for (int i = 0; i < 8; i++)
	{
		workerPool.submit([i]() { std::cout << "task" << i << "\n";});
	}
	workerPool.shutdown();

	return 0;
}
