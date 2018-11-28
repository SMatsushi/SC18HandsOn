#include <stdio.h>
#include <sys/time.h>

#define M 16
#define N 4 * (1 << 20) /* 4M */

double get_dtime() {
  struct timeval tv;
  gettimeofday(&tv, 0);
  return ((double)(tv.tv_sec) + (double)(tv.tv_usec) * 0.001 * 0.001);
}

double a[M * (N+1)]; /* 2 dim array, 64M + pad */
double b[M];

void myloop(int m, int n) {
  int i, j;
  for(i = 0; i < n; i++) {
	for(j = 0; j < m; j++) {
	  a[i + (N+1)*j] = b[j];
	}
  }
}

int main() {
  double start = get_dtime();
  myloop(M, N);
  printf("elapsed time = %.3f sec\n",get_dtime() - start);
}
