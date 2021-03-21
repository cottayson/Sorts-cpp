template<typename T>
void selection_sort_auxilary(std::vector<T> &aVector, unsigned start)
{
  if (aVector.size() - start <= 1) {
    return;
  }
  T min = aVector[start];
  unsigned minIndex = start;
  for (unsigned i = start; i < aVector.size(); ++i) {
    if (min > aVector[i]) {
      min = aVector[i];
      minIndex = i;
    }
  }
  if(minIndex > start) {
    std::swap(aVector[start], aVector[minIndex]);
  }
  selection_sort_auxilary(aVector, start + 1);
}

template<typename T>
void selection_sort(std::vector<T> &aVector)
{
  selection_sort_auxilary(aVector, 0);
}