#include <stdio.h>
#include <sys/time.h>

#define N 200 * (1 << 20) /* 200 M */

double get_dtime() {
  struct timeval tv;
  gettimeofday(&tv, 0);
  return ((double)(tv.tv_sec) + (double)(tv.tv_usec) * 0.001 * 0.001);
}

double a[N];
double b[N];

int main() {
  int i;
  double start = get_dtime();
  for(i = 0; i < N; i++) {
	a[i] = b[i];
  }
  printf("elapsed time = %.3f sec\n",get_dtime() - start);
}
