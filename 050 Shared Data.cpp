#include <atomic>
#include <iostream>
#include <thread>

using namespace std;

/**
 * 在共享多個執行緒內共享變數時，若沒有特別使用 atomic
 * 則會導致 data race 發生，進而產生無法預期的結果
 */

int main() {
  atomic<int> count = 0;
  const int ITERATIONS = 1000000;

  // Lambda 函數: [](int a, int b) -> int { body }
  // []: 捕獲變數
  // (): 函數參數
  // ->: return 變數
  // {}: Lambda 函數主題
  thread t1([&count]() {
    for (int i = 0; i < ITERATIONS; i++) {
      ++count;
    }
  });
  thread t2([&count]() {
    for (int i = 0; i < ITERATIONS; i++) {
      ++count;
    }
  });
  t1.join();
  t2.join();

  cout << "Count: " << count << endl;
  return 0;
}