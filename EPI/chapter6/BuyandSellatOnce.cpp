#include <vector>
#include <iostream>
using namespace std;

double BuyAndSellAtOnce(vector<double>* A_ptr)
{		     
  vector<double> A = *A_ptr;
  vector<double> peak, trough;

  int start=0;
  while(A[start] == A[start+1]) {
    start++;
  }
  if(A[start] < A[start+1])
    trough.push_back(A[start]);
  
  int end = A.size() - 1;
  while(A[end] == A[end-1])
    end--;
  if(A[end] > A[end-1])
    peak.push_back(A[end]);
  

  int prev = start;
  for(int i = start+1; i < end; ++i) {
    if(A[i] == A[i+1])
      continue;
    
    if(A[prev] < A[i] && A[i] > A[i+1])
      peak.push_back(A[i]);
    else if(A[prev] > A[i] && A[i] < A[i+1])
      trough.push_back(A[i]);
    prev=i;
  }

  double max = 0;
  for(int i = 0; i < trough.size(); ++i) {
    for(int j = i; j < peak.size(); ++j) {
      if (peak[j] > trough[i])
	max = peak[j] - trough[i] > max ? peak[j] - trough[i] : max;
    }
  }

  return max;
}

int main()
{
  vector<double> A = {310, 310, 315, 315, 275, 295, 260, 270, 290, 230, 255, 250};

  cout << BuyAndSellAtOnce(&A) << endl;
}
