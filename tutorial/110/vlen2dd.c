#include <stdio.h>
#include <sys/time.h>

#define M 16
#define N 4 * (1 << 20) /* 4M */
#define PAD 1 /* padding in column to skew column in neighbour rows */

double get_dtime() {
  struct timeval tv;
  gettimeofday(&tv, 0);
  return ((double)(tv.tv_sec) + (double)(tv.tv_usec) * 0.001 * 0.001);
}

double a[M][N+PAD]; /* 2 dim array, 64M + pad */
double b[N];

void myloop(int m, int n) {
  int i, j;
  for(i = 0; i < m; i++) {
	for(j = 0; j < n; j++) {
	  a[i][j] = b[j];
	}
  }
}

int main() {
  double start = get_dtime();
  myloop(M, N);
  printf("elapsed time = %.3f sec\n",get_dtime() - start);
}
