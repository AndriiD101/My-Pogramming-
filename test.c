#include <stdio.h>
#include <math.h>

double to_basic_degrees(double degrees) {
  double rounded_degrees = round(degrees / 360.0) * 90.0;

  // Ensure the value is one of the specified basic degrees
  if (rounded_degrees == 0) {
    rounded_degrees = 360.0;
  }

  return rounded_degrees;
}

int main() {
  double input_degrees;

  printf("Enter a value in degrees: ");
  scanf("%lf", &input_degrees);

  double basic_degrees = to_basic_degrees(input_degrees);

  printf("%lf degrees is equal to %lf basic degrees.\n", input_degrees, basic_degrees);

  return 0;
}
