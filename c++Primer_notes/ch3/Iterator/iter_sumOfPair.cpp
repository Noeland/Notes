#include <iostream>
#include <vector>

using namespace std;

int main()
{
  vector<int> result;    // will hold the resulting vector of sums
  vector<int> inputs;    // will hold the sequence of user inputs
  int input;             // will hod the current user input

  while(cin >> input)
    inputs.push_back(input);

  unsigned count = 0;    // will count the number of element processed sofar
  int sum = 0;
  for(auto it = inputs.cbegin(); it != inputs.cend(); ++it) {
    sum += *it;
    if(count++ % 2 != 0) // the even number element
      {
	result.push_back(sum);
	sum = 0;
      }
    else if(it == inputs.cend() - 1)
      result.push_back(sum);
  }

  for(auto elem : result)
    cout << elem << ' ';
  cout << endl;
}
