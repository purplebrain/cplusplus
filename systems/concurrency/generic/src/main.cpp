#include <iostream>
#include <cstdlib>
#include <string>
#include <memory>
#include <thread>
#include <chrono>
#include "myglobal.hpp"
#include "queue.hpp"

using namespace std;
typedef thread THREAD;

#define MAX_OPERATIONS 64
#define MAX_SIZE 32
#define NUM_PRODUCER 4
#define NUM_CONSUMER 2

unique_ptr<QUEUE> g_ptrQ;

MY_GLOBAL<bool> g_ExitRun(false);
MY_GLOBAL<bool> g_QThresholdHit(false);

int
getRandomInteger(void)
{
  return (rand()%100 + 1);
}

class QMONITOR
{
  public:
    void operator()(int _x) 
    {
      // _x is the size of queue when warning should be issued
      while (1) {
        cout << "<Monitoring> current operation count = " <<
                g_ptrQ->getOperationCnt() << endl;

        if (g_ptrQ->getOperationCnt() >= MAX_OPERATIONS) {
          g_ExitRun.set(true);
          terminate();
        }

        if (g_ptrQ->getSize() >= _x) {
          g_QThresholdHit.set(true);
          cout << "<Monitoring> qSize threshold hit" << endl;
        } else {
          g_QThresholdHit.set(false);
        }

        this_thread::sleep_for(chrono::seconds(2));
      }
    } 
};

void
fProducer(void)
{
  while(1) {
    if (g_ExitRun.get()) {
      terminate();
    }
    if (!g_QThresholdHit.get()) {
      g_ptrQ->push(getRandomInteger());
      this_thread::sleep_for(chrono::seconds(1));
    } else {
      g_ptrQ->pop();
    }
  }
}

void
fConsumer(void)
{
  while(1) 
  {
    if (g_ExitRun.get()) {
      terminate();
    }
    if (g_ptrQ->getSize()) {
      g_ptrQ->pop();
      this_thread::sleep_for(chrono::seconds(1));
    }
  }
}

int
main(int argc, char *argv[])
{
  g_ptrQ = make_unique<QUEUE>(MAX_SIZE);

  // generate producers
  THREAD arrProducer[NUM_PRODUCER];
  for (int i = 0; i < NUM_PRODUCER; i++) {
    arrProducer[i] = THREAD(fProducer);
  }

  // generate consumers
  THREAD arrConsumer[NUM_CONSUMER];
  for (int i = 0; i < NUM_CONSUMER; i++) {
    arrConsumer[i] = THREAD(fConsumer);
  }

  // generate monitor
  THREAD thMonitor(QMONITOR(), MAX_SIZE);

  // do join with children
  for (int i = 0; i < NUM_PRODUCER; i++) {
    arrProducer[i].join();
  }
  for (int i = 0; i < NUM_CONSUMER; i++) {
    arrConsumer[i].join();
  }
  thMonitor.join();

  cout << "Exiting Program" << endl;
  return (0);
}
