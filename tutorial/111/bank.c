#include <stdio.h>
#include <sys/time.h>

#define N 8 * (1 << 10) /* 8K */

double get_dtime() {
  struct timeval tv;
  gettimeofday(&tv, 0);
  return ((double)(tv.tv_sec) + (double)(tv.tv_usec) * 0.001 * 0.001);
}

double a[N][N]; /* 2 dim array, 64M */
double b[N];

int main() {
  int i, j;
  double start = get_dtime();
  for(i = 0; i < N; i++) {
	for(j = 0; j < N; j++) {
	  a[j][i] = b[j];
	}
  }
  printf("elapsed time = %.3f sec\n",get_dtime() - start);
}
