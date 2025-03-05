template <bool Cond, typename T, typename F> 
struct if_;

template <typename T, typename F>
struct if_<true,T,F>                  // Partial Specialization: True case
{
  typedef T result;
};

template <typename T, typename F>
struct if_<false,T,F>                 // Partial Specialization: False case
{
  typedef F result;
};

// If sizeof(short) == sizeof(int)
// then choose long, otherwise choose int.
typedef 
  typename if_<
    sizeof(short) == sizeof(int), // TEST
    long,                         // True result
    int                           // False result
  >::result,                      // "Return" of if_
  MY_INT                          // typedef name
;

int main()
{
  MY_INT i;
}
