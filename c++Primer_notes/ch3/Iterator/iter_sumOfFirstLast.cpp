#include <iostream>
#include <vector>

using namespace std;

int main()
{
  vector<int> result;  // will hold the resulting sums
  vector<int> inputs;  // will hold the input sequence of integers
  int input;

  while(cin >> input)
    inputs.push_back(input);

  if(inputs.empty()) {
    cout << "No Valid Input!" << endl;
    return 1;
  }

  auto first = inputs.cbegin();
  auto second = inputs.cend() - 1;

  while(first < second) {
    result.push_back(*first + *second);
    ++first;
    --second;
  }

  if(first == second)
    result.push_back(*first);

  for(auto e : result)
    cout << e << ' ';

  cout << endl;
}
