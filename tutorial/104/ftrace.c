/*
  $ ncc -ftrace ftrace.c
  $ ./a.out
  $ ftrace -f ftarce.out
*/

#include <stdio.h>
#include <sys/time.h>

#define N 200 * (1 << 20) 

double get_dtime() {
  struct timeval tv;
  gettimeofday(&tv, 0);
  return ((double)(tv.tv_sec) + (double)(tv.tv_usec) * 0.001 * 0.001);
}

double a[N];
double b[N];

void vec_ok() {
  int i;
  for(i = 0; i < N; i++) {
	a[i] = b[i];
  }
}

void vec_ng() {
  int i;
  for(i = 1; i < N; i++) {
	a[i] = a[i-1];
  }
}

int main() {
  int i,j;
  double start = get_dtime();
  vec_ok();
  vec_ng();
  printf("elapsed time = %.3f sec\n",get_dtime() - start);
}
