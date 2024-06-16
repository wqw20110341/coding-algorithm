//
// Created by 12582 on 2024/6/16.
//

#include <iostream>
#include <thread>
#include <queue>
#include <condition_variable>
#include <mutex>

std::queue<int> data_queue;
std::mutex mtx;
std::condition_variable cond_var;

bool stop = false;

void producer() {
    for (int i = 0; i < 10; ++i) {
        std::unique_lock<std::mutex> lock(mtx);
        data_queue.push(i);
        std::cout << "Produced: " << i << std::endl;
        cond_var.notify_one();  // 通知一个等待的线程
    }
    stop = true;
    cond_var.notify_all();  // 通知所有等待的线程，我们已经完成了
}

void consumer() {
    while (true) {
        std::unique_lock<std::mutex> lock(mtx);
        cond_var.wait(lock, [] { return !data_queue.empty() || stop; });  // 等待直到队列非空或停止信号
        if (stop && data_queue.empty()) {
            break;  // 所有数据都已处理，且生产者已停止
        }
        int data = data_queue.front();
        data_queue.pop();
        std::cout << "Consumed: " << data << std::endl;
    }
}

int main() {
    std::thread producer_thread(producer);
    std::thread consumer_thread(consumer);

    producer_thread.join();
    consumer_thread.join();

    return 0;
}


