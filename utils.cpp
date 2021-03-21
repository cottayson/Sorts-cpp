bool larger(int i, int j) {
  return i > j;
}

template<typename T>
void show(std::vector<T> &v) {
  for(unsigned i = 0; i < v.size(); ++i) {
    std::cout << v[i] << " ";
  }
}