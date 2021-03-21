template<typename T>
void quick_sort(std::vector<T> &aVector)
{
  if(aVector.size() <= 1) {
    return;
  }
  // aVector.size() >= 2
  T m = aVector[0];
  std::vector<T> less;
  std::vector<T> greater;
  for (unsigned i = 1; i < aVector.size(); i++) {
    T elem = aVector[i];
    if (elem < m) {
      less.push_back(elem);
    } else {
      greater.push_back(elem);
    }
  }

  #ifdef DEBUG
  std::cout << m << " less: ";
  show(less);
  std::cout << " greater: ";
  show(greater);
  std::cout << std::endl;
  #endif

  quick_sort(less);
  quick_sort(greater);
  for (unsigned i = 0; i < less.size(); i++) {
    aVector[i] = less[i];
  }
  aVector[less.size()] = m;
  for (unsigned i = 0; i < greater.size(); i++) {
    aVector[i+1+less.size()] = greater[i];
  }
}