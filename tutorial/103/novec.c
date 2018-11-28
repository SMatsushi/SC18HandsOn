#include <stdio.h>
#include <sys/time.h>

#define N 200 * (1 << 20)

double get_dtime() {
  struct timeval tv;
  gettimeofday(&tv, 0);
  return ((double)(tv.tv_sec) + (double)(tv.tv_usec) * 0.001 * 0.001);
}

double a[N];

int main() {
  int i,j;
  double start = get_dtime();
  for(i = 0; i < N - 1; i++) {
	a[i+1] = a[i] ;
  }
  printf("elapsed time = %.3f sec\n",get_dtime() - start);
}
