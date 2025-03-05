[](int a, float f) -> float // set return type to be float
{
  // no type deduction for return type occurs
  return a + f + 5.3; // double result is implicitly cast to float
}
