unsigned counter = 0;
unsigned mergeCounter = 0;

template<typename T>
void merge(std::vector<T> &aVector, std::vector<T> &temp, unsigned start, unsigned middle, unsigned end)
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
  unsigned i = 0, j = 0, k = 0;
  // Merge left and right parts
  while (i < sizeLeft && j < sizeRight) {
    // if (L[i] < R[j])
    if (temp[i + start] < temp[j + middle]) {
      aVector[k] = temp[i + start];
      ++i;
    } else {
      aVector[k] = temp[j + middle];
      ++j;
    }
    ++k;
  }
  // if right part is empty, we copy result from left part
  while (i < sizeLeft) {
    aVector[k++] = temp[i + start];
    ++i;
  }
  // if left part is empty, we copy result from right part
  while (j < sizeRight) {
    aVector[k++] = temp[j + middle];
    ++j;
  }
}

template<typename T>
void merge_sort_aux(std::vector<T> &aVector, unsigned start, unsigned end)
{
  unsigned intervalSize = end - start;
  if (intervalSize <= 1) {
    return;
  }
  unsigned middle = (end - start) / 2;
  std::cout << "merge_sort_aux: " << ++counter << std::endl;

  // Create a copy of aVector interval
  std::vector<T> temp;
  for (unsigned k = 0; k < intervalSize; ++k) {
    temp.push_back(aVector[k]);
  }
  merge_sort_aux(temp, 0, middle);
  merge_sort_aux(temp, middle, intervalSize);
  merge(aVector, temp, 0, middle, intervalSize);
  // after merge we must have already sorted vector
  std::cout << "aVector = ";
  show(aVector);
  std::cout << std::endl;
}

template<typename T>
void merge_sort(std::vector<T> &aVector)
{
  merge_sort_aux(aVector, 0, aVector.size());
}
