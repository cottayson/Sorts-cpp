template <typename T>
void shell_sort(std::vector<T> &aVector)
{
  unsigned end = aVector.size() - 1;

  unsigned h = 0;
  for (h = 1; h <= end / 9; h = 3 * h + 1);

  for(; h > 0; h /= 3)
  {
    for(auto i = h; i <= end; i++)
    {
      unsigned j = i;
      T v = aVector[i];
      while(j >= h && v < aVector[j - h])
      {
        aVector[j] = aVector[j - h];
        j -= h;
      }
      aVector[j] = v;
    }
  }
}