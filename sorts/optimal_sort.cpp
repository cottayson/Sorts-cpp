template<typename T>
void optimal_sort(std::vector<T> &aVector)
{
  // optimal sort for small arrays
  if(aVector.size() <= 1) {
    return; // do nothing
  }
  // [1, 2] -> [1, 2]   0 swaps
  // [2, 1] -> [1, 2]   1 swap

  // мы имеем сравнение между векторами 
  // (0 swap, 1 check) < (1 swap, 1 check)
  // которое возвращает {true, false, {true, false}}
  // compare (2 swap, 0 check) (1 swap, 1 check) = {>, <}
  if(aVector.size() == 2) {
    if (aVector[0] > aVector[1]) {
      std::swap(aVector[0], aVector[1]);
    }
  }
  // [1, 2, 3] -> [1, 2, 3]   0 swaps ? checks
  // [1, 3, 2] -> [1, 2]   1 swap
  /*
  ==> = observe
  -> = agent action

  let a = [3, 2, 1]

  start state -> check a[0] > a[1] ==> true -> 
                               ... ==> false -> 
          ... -> swap a[0] a[1] -> 
          ... -> swap a[0] a[1] -> 
  */
}