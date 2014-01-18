#include <stdlib.h>
#include <assert.h>
#include <sys/time.h>
#include "timer.hpp"

Timer::Timer()
:before_({0}), after_({0}), overheadMuS_(calculateOverhead()) {}

void Timer::start() { gettimeofday(&before_, NULL); }

long long Timer::elapsedMuS() { return elapsedWithOverhead() - overheadMuS_; }

long long Timer::calculateOverhead() {
  start();
  return elapsedWithOverhead();
}

long long Timer::elapsedWithOverhead() {
  gettimeofday(&after_, NULL);

  // Two subtractions can be done here without decreasing stability because
  // tv_sec and tv_usec are not floating point format. Doing the subtractions
  // separately before the multiplication and addition reduces the
  // possibility of overflow.
  return (
      (after_.tv_sec - before_.tv_sec) * 1e6 +
      (after_.tv_usec - before_.tv_usec)
  );
}
