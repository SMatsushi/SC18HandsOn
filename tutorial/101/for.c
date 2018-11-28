#include <stdio.h>

#define N (1 << 20) /* 1M */

double a[N];
double b[N];

int main() {
  int i;
  for(i = 0; i < N; i++) {
	a[i] = b[i];
  }
}
