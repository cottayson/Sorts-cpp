// https://stackoverflow.com/questions/2298242/callback-functions-in-c

double add_half(int x) {
  return (double)x + 0.5;
}
//                             return type <= *funcname <= types of arguments
// func :: int -> double  <=>  double (*func)(int)
void test_func(double (*func)(int)) {
  int y = 10;
  cout << "y = " << y << ", func = " << func(y) << endl;
}
