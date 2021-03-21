unsigned counter = 0;
unsigned mergeCounter = 0;

template<typename T>
void merge(std::vector<T> &aVector, unsigned start, unsigned middle, unsigned end)
{
  // merge([2,6,9], [3,5,7]) rejected by human using `list of lemmas`
  // list of lemmas = [by `должно быть (топологически) произвольное расположение интервалов левой части и правой части`]
  // iteration 1
  // merge([1,2,6,9], [3,5,7])
  // 1: [2,6,9], 3: [5,7]
  // leftKey = left.pop()
  // 1 < 3 => merged.push_back(1)
  // iteration 2
  // merge([2,6,9], [3,5,7], merged = [1])
  std::cout << "merge: " << ++mergeCounter << std::endl;
  unsigned sizeLeft = middle - start;
  unsigned sizeRight = end - middle;
  std::vector<T> temp;
  unsigned i = 0, j = 0;
  // Merge left and right parts
  while (i < sizeLeft && j < sizeRight) {
    // if (L[i] < R[j])
    if (aVector[i + start] < aVector[j + middle]) {
      temp.push_back(aVector[i + start]);
      ++i;
    } else {
      temp.push_back(aVector[j + middle]);
      ++j;
    }
  }
  std::cout << "temp = ";
  show(temp);
  std::cout << std::endl;
  // Copy temp to aVector
  for (unsigned k = 0; k < temp.size(); ++k) {
    aVector[k] = temp[k];
  }
}

template<typename T>
void merge_sort_aux(std::vector<T> &aVector, unsigned start, unsigned end)
{
  if (end - start <= 1) {
    return;
  }
  unsigned middle = (start + end) / 2;
  std::cout << "merge_sort_aux: " << ++counter << std::endl;
  merge_sort_aux(aVector, start, middle);
  merge_sort_aux(aVector, middle, end);
  merge(aVector, start, middle, end);
}

template<typename T>
void merge_sort(std::vector<T> &aVector)
{
  merge_sort_aux(aVector, 0, aVector.size());
}
