#include <iostream>
#include <mutex>
#include <thread>

using namespace std;

/**
 * 除了使用 atomic 之外，可以在執行緒執行的過程中使用 mutex 來保護共享資源
 * 一旦執行緒被上鎖，其他執行緒就無法進入該執行緒，直到該執行緒解鎖
 */

int main() {
  int count = 0;
  mutex mtx;
  const int ITERATIONS = 1000000;

  auto func = [&]() {
    for (int i = 0; i < ITERATIONS; i++) {
      mtx.lock();
      ++count;
      mtx.unlock();
    }
  };
  thread t1(func);
  thread t2(func);
  t1.join();
  t2.join();

  cout << "Count: " << count << endl;
  return 0;
}