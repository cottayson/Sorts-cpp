// source: Merge sort algorithm by - Mycodeschool https://vimeo.com/369031069
template<typename T>
void merge(std::vector<T> &aVector, std::vector<T> &left, std::vector<T> &right)
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
  unsigned sizeLeft = left.size();
  unsigned sizeRight = right.size();
  unsigned i = 0, j = 0, k = 0;
  // Merge left and right parts
  while (i < sizeLeft && j < sizeRight) {
    // if (L[i] < R[j])
    if (left[i] < right[j]) {
      aVector[k++] = left[i++];
    } else {
      aVector[k++] = right[j++];
    }
  }
  // if right part is empty, we copy result from left part
  while (i < sizeLeft) {
    aVector[k++] = left[i++];
  }
  // if left part is empty, we copy result from right part
  while (j < sizeRight) {
    aVector[k++] = right[j++];
  }
}

template<typename T>
void merge_sort(std::vector<T> &aVector)
{
  unsigned n = aVector.size();
  if (n <= 1) {
    return;
  }
  unsigned middle = n / 2;
  // Allocate two parts (left and right) of vector
  std::vector<T> left, right;
  for (unsigned i = 0; i < middle; ++i) {
    left.push_back(aVector[i]);
  }
  for (unsigned i = middle; i < n; ++i) {
    right.push_back(aVector[i]);
  }
  merge_sort(left);
  merge_sort(right);
  merge(aVector, left, right);
  // after merge we must have already sorted vector
  std::cout << "aVector = ";
  show(aVector);
  std::cout << std::endl;
}
