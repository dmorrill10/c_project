#include <stdlib.h>
#include <assert.h>
#include <sys/time.h>
#include "timer.h"

static struct timeval before, after;

void start_timer() {
  before.tv_sec = 0;
  before.tv_usec = 0;
  after.tv_sec = 0;
  after.tv_usec = 0;

  gettimeofday(&before, NULL);
}
long long stop_timer() {
  gettimeofday(&after, NULL);

  // Two subtractions can be done here without decreasing stability because
  // tv_sec and tv_usec are not floating point format. Doing the subtractions
  // separately before the multiplication and addition reduces the
  // possibility of overflow.
  return (
      (after.tv_sec - before.tv_sec) * 1e6 +
      (after.tv_usec - before.tv_usec)
  );
}
