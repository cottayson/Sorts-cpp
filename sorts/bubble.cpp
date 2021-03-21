template<typename T>
void bubble_sort(std::vector<T> &aVector)
{
  for (unsigned end = aVector.size() - 1; end >= 1; --end) {
    for (unsigned j = 0; j < end; j++) {
      if (larger( aVector[j], aVector[j+1] )) {
        std::swap( aVector[j], aVector[j+1] );
      }
    }
  }
}
