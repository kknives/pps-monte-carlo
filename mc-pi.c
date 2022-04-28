// Program to estimate value of π using Monte Carlo method
#include <float.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int
main(int argc, char** argv)
{
  srand(time(NULL));

  printf("Enter epoch\n");
  unsigned long long digits;
  scanf("%llu", &digits);
  unsigned long long inside = 0;
  unsigned long long i = 0;

  for (i = 0; i < digits; i++) {
    float x = (float)rand() / RAND_MAX;
    float y = (float)rand() / RAND_MAX;

    float s = x * x + y * y - 1;
    if (s <= FLT_EPSILON)
      inside++;
  }
  long double pi = (long double)(inside * 4) / i;
  printf("pi is: %.10Lf\n", pi);
  return 0;
}
