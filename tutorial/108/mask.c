#include <stdio.h>
#include <sys/time.h>

#define N 100 * (1 << 20) /* 100 M */

double get_dtime() {
  struct timeval tv;
  gettimeofday(&tv, 0);
  return ((double)(tv.tv_sec) + (double)(tv.tv_usec) * 0.001 * 0.001);
}

int a[N];
int b[N];

int main() {
  int i, j;
  for(i = 0; i < N; i++) {
	a[i] = i % 2;
  }
  double start = get_dtime();
  for(i = 0, j = 0; i < N; i++) {
	if(a[i] == 0) b[i] = a[i];
  }
  printf("elapsed time = %.3f sec\n",get_dtime() - start);
}
