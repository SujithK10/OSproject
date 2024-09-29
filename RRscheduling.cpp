#include <iostream>
#include <queue>

using namespace std;

struct Process {
    int pid;
    int burstTime;
    int remainingTime;
};

int main() {
    queue<Process> readyQueue;
    int timeQuantum = 4;

    
    readyQueue.push({1, 10, 10});
    readyQueue.push({2, 4, 4});
    readyQueue.push({3, 6, 6});

    int currentTime = 0;
    while (!readyQueue.empty()) {
        Process currentProcess = readyQueue.front();
        readyQueue.pop();

        if (currentProcess.remainingTime <= timeQuantum) {
            currentTime += currentProcess.remainingTime;
            cout << "Process " << currentProcess.pid << " finished at time " << currentTime << endl;
        } else {
            currentTime += timeQuantum;
            currentProcess.remainingTime -= timeQuantum;
            cout << "Process " << currentProcess.pid << " executed for " << timeQuantum << " units. Remaining time: " << currentProcess.remainingTime << endl;
            readyQueue.push(currentProcess);
        }
    }

    return 0;
}
