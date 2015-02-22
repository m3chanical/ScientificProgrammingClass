#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(void)
{
  /* print integer type maximums */
  printf("size: %i short maximum: %hd \n", sizeof(short), SHRT_MAX);
  printf("size: %i int   maximum: %d \n", sizeof(int), INT_MAX );
  printf("size: %i long  maximum: %Ld \n\n", sizeof(long), LONG_MAX );

  /* print float precision, range and maximum */
  printf("size: %i float precision digits: %d \n", sizeof(float), FLT_DIG);
  printf("size: %i float maximum exponent: %d \n", sizeof(float), FLT_MAX_10_EXP);
  printf("size: %i float maximum: %e \n\n", sizeof(float), FLT_MAX);

  /* print double float precision, range and maximum */
  printf("size: %i double precision digits: %d \n", sizeof(double), DBL_DIG);
  printf("size: %i double maximum exponent: %d \n", sizeof(double), DBL_MAX_10_EXP);
  printf("size: %i double maximum: %g \n\n", sizeof(double), DBL_MAX);

  /* print long precision, range and maximum */
  printf("size: %i long double precision digits: %i \n", sizeof(long double), LDBL_DIG);
  printf("size: %i long double maximum exponent: %i \n", sizeof(long double), LDBL_MAX_10_EXP);
  printf("size: %i long double maximun: %g \n\n", sizeof(long double), LDBL_MAX);

}