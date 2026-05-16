# thread-pool: requires C++20, CMake 3.20+, GCC or Clang
#
# 1. Thread-pool app that solves the problem of creating new thread with each arriving task instead preparing multiple waiting workers that do tasks the moment they arrive at queue allowing for automatic redirection of tasks from another app
#
# 2. Uses a condition variable to wake up workers at task arrival, also another one that allows for graceful shutdown
#
# 3. Hardest part was fixing multi-threading problems like data race and deadlock.
#
# 4. If I had more time I would add proper tests as some issues are visible only after a couple of runs.
#
# Build:
# mkdir build && cd build
# cmake ..
# make
# ./Thread-pool
#
# Usage:
# WorkerPool pool(x) where x = number of workers
# pool.submit(task) where task is a function
# pool.shutdown() graceful shutdown
#
# Known limitations:
# std::cout is not thread-safe
# No return values from tasks, use std::future for results