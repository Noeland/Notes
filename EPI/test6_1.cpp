#include <iostream>
#include <vector>
#include <utility>
using namespace std;


void partition(int pivot_idx, vector<int>* A)
{
  int last_smaller=0, first_non_smaller=0, first_greater=0;
  int pivot = A->at(pivot_idx);
  size_t len = A->size();

  for(size_t iter = 0; iter!=len; iter++) {
    if(A->at(iter) < pivot) {
      swap(A->at(iter), A->at(first_greater));
      swap(A->at(first_greater), A->at(first_non_smaller));
      last_smaller = first_non_smaller;
      first_non_smaller++;
      first_greater++;
    }
    else if(A->at(iter) == pivot) {
      swap(A->at(iter), A->at(first_greater));
      first_greater++;
    }
  }
}

int main()
{
  vector<int> A = {0, 1, 2, 0, 2, 3, 1, 4, 1};
  partition(1, &A);

  for(auto a : A)
    cout << a << ' ';
  cout << endl;
}
