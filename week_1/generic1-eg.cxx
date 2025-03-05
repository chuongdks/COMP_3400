template <typename T>
T min(T a, T b)
{
  return a < b ? a : b;
}

int main()
{
  min(2,2); // OK: match for min(int,int)
  min(2.3,13.1); // OK: match for min(double,double)
  min(3.3,1); // ERROR: no match for min(double,int)
}
