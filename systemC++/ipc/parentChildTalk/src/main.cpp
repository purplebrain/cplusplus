#include <csignal>
#include <thread>
#include <unistd.h>
#include <memory>
#include <sys/types.h>
#include <chrono>
#include <iostream>

using namespace std;

void
fooSigHup(int sigNum)
{
  cout << "CHILD: got SIGHUP signal" << endl;
  return;
}

void
fooSigInt(int sigNum)
{
  cout << "CHILD: got SIGINT signal" << endl;
  return;
}

void
fooSigQuit(int sigNum)
{
  cout << "CHILD: got SIGQUIT signal" << endl;
  return;
}

int
main(int argc, char *argv[])
{
  int cPID;

  if ((cPID = fork()) < 0) {
    cout << "fork(): could not fork" << endl;
    exit(1);
  } else {
    if (cPID) {
      // This is parent-process
      cout << "I'm PARENT with PID=" << getpid() << " who forked a CHILD with PID=" << cPID << endl;
      this_thread::sleep_for(chrono::seconds(3));
      cout << "PARENT: sending SIGHUP to CHILD" << endl;
      kill(cPID, SIGHUP);
      this_thread::sleep_for(chrono::seconds(3));
      cout << "PARENT: sending SIGINT to CHILD" << endl;
      kill(cPID, SIGINT);
      this_thread::sleep_for(chrono::seconds(3));
      cout << "PARENT: sending SIGQUIT to CHILD" << endl;
      kill(cPID, SIGQUIT);
      this_thread::sleep_for(chrono::seconds(3));
    } else {
      // This is child-process
      cout << "I'm CHILD with PID=" << getpid() << endl;
      signal(SIGHUP, fooSigHup);
      signal(SIGINT, fooSigInt);
      signal(SIGQUIT, fooSigQuit);
      while(1);
    }
  }

  exit(0);
}
