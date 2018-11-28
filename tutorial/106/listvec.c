#include <stdio.h>
#include <sys/time.h>

#define N 100 * (1 << 20) /* 100 M */

double get_dtime() {
  struct timeval tv;
  gettimeofday(&tv, 0);
  return ((double)(tv.tv_sec) + (double)(tv.tv_usec) * 0.001 * 0.001);
}

double a[N];
double b[N];
int idx[N];

int main() {
  int i;
  for(i = 0; i < N; i++) {
	idx[i] = N - 1 - i;
  }
  double start = get_dtime();
  for(i = 0; i < N; i++) {
	a[i] = b[idx[i]];
  }
  printf("elapsed time = %.3f sec\n",get_dtime() - start);
}
