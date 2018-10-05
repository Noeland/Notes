#include <vector>
#include <iostream>
using namespace std;
double BuyAndSellAtOnce(vector<double>* A_ptr)
{
  double curr_min = (*A_ptr)[0];
  double max = 0;
  for(int i = 0; i < A_ptr->size(); ++i)
    {
      if((*A_ptr)[i] < curr_min)
	curr_min = (*A_ptr)[i];

      if((*A_ptr)[i] - curr_min > max)
	max = (*A_ptr)[i] - curr_min;
    }

  return max;
}

int main()
{
  vector<double> A = {310, 310, 315, 315, 275, 295, 260, 270, 290, 230, 255, 250};
  cout << BuyAndSellAtOnce(&A) << endl;
}
