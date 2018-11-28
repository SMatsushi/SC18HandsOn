#include <stdio.h>
#include <sys/time.h>

#define N 200 * (1 << 20) /* 200 M */

double get_dtime() {
  struct timeval tv;
  gettimeofday(&tv, 0);
  return ((double)(tv.tv_sec) + (double)(tv.tv_usec) * 0.001 * 0.001);
}

double a[N];

int main() {
  int i;
  double sum = 0;
  for(i = 0; i < N; i++) {
	a[i] = 1;
  }
  double start = get_dtime();
  for(i = 0; i < N; i++) {
	sum += a[i];
  }
  printf("elapsed time = %.3f sec\n",get_dtime() - start);
  printf("sum = %f\n", sum);
}
