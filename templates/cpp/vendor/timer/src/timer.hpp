#ifndef __TIMER_HPP__
#define __TIMER_HPP__

class Timer {
public:
  Timer();
  virtual ~Timer() {};

  void start();
  long long elapsedMuS();
  long long overheadMuS() const { return overheadMuS_; };

private: // methods
  long long calculateOverhead();
  long long elapsedWithOverhead();

private: // members
  struct timeval before_;
  struct timeval after_;
  long long overheadMuS_;
};

struct StopWatch {
  StopWatch():accumulatedMuS_(0), numTimings_(0) {};
  void start() {
    timer_.start();
  }
  void stop() {
    accumulatedMuS_ += timer_.elapsedMuS();
    ++numTimings_;
  }
  long long totalOverheadMuS() { return timer_.overheadMuS() * numTimings_; }

  Timer timer_;
  long long accumulatedMuS_;
  long numTimings_;
};

struct PerformanceMonitor {
  long long totalOverheadMuS() {
    return workingWatch_.totalOverheadMuS() + sleepingWatch_.totalOverheadMuS();
  }

  StopWatch workingWatch_;
  StopWatch sleepingWatch_;
};

#endif
