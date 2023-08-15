#include <iostream>
#include <thread>
#include <mutex>
#include <queue>
#include <random>
#include <condition_variable>

std::mutex myMutex;             // Mutex for protecting shared data access
std::queue<int> myDataQueue;    // Shared data structure (queue)
std::condition_variable myCV;   // Condition variable for synchronization

bool isProducerDone = false;    // Indicator for producer completion

// Producer function: generates and adds data to the shared queue
void myProducer() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(1, 100);

    for (int i = 0; i < 10; ++i) {
        int num = dist(gen);

        std::unique_lock<std::mutex> myLock(myMutex); // Acquire the lock
        myDataQueue.push(num);                       // Add data to the queue
        myLock.unlock();                             // Unlock the mutex

        myCV.notify_one();                           // Notify waiting consumer

        std::this_thread::sleep_for(std::chrono::milliseconds(dist(gen)));
    }

    // Mark producer as done
    isProducerDone = true;
    myCV.notify_one(); // Notify waiting consumer to check if producer is done
}

// Consumer function: consumes data from the shared queue
void myConsumer() {
    while (true) {
        std::unique_lock<std::mutex> myLock(myMutex); // Acquire the lock
        myCV.wait(myLock, [&] { return !myDataQueue.empty() || isProducerDone; });

        if (!myDataQueue.empty()) {
            int num = myDataQueue.front();    // Get the data from the front of the queue
            myDataQueue.pop();                // Remove the data from the queue
            myLock.unlock();                  // Unlock the mutex

            std::cout << "Consumed: " << num << std::endl; // Print the consumed number
        } else if (isProducerDone) {
            // If producer is done and queue is empty, exit the consumer thread
            myLock.unlock();
            break;
        }
    }
}

int main() {
    std::thread myProducerThread(myProducer);
    std::thread myConsumerThread(myConsumer);

    myProducerThread.join(); // Wait for the producer thread to finish
    myConsumerThread.join(); // Wait for the consumer thread to finish

    return 0;
}
