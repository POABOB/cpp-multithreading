#include <chrono>
#include <iostream>
#include <thread>

using namespace std;

/**
 * 這是一個簡單的執行緒範例，透過 thread 建立兩個執行緒，並且等待兩個執行緒結束
 * 並且為了讓兩個執行緒可以彼此同時執行，每次 loop 執行都會睡 100 毫秒
 */

void work() {
  for (int i = 0; i < 10; i++) {
    // 執行緒等待 100 毫秒
    this_thread::sleep_for(chrono::milliseconds(100));
    cout << "Loop " << i << endl;
  }
}

int main() {
  // 使用 thread 建立執行緒
  thread t1(work);
  thread t2(work);
  // 將執行緒 blocking 等待結束，不使用 join 則會直接往下執行
  t1.join();
  t2.join();
  return 0;
}