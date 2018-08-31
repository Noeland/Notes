#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

int main()
{
  vector<int> result;      // will hold the resulting sum of pair
  vector<int> inputs;      // will hold the input sequence of integers

  int input;          // the input by user

  while( cin >> input )
    inputs.push_back(input);  // fill the vector with user inputs

  if(inputs.size() == 0) {
    cout << "No Valid Input!" << endl;
    return 1;
  }

  vector<int>::size_type first = 0;  // the first element of a pair
                                     // starting at the beginning of vector
  
  vector<int>::size_type second = inputs.size() - 1; // the second element of a pair
                                                     // decrement from the end of vector
  
  while(first <= second) {    // as long as the first element does not lie after the second element
    
    if(first != second)
      result.push_back(inputs[first] + inputs[second]);
    else
      result.push_back(inputs[first]);

    first++;
    second--;
  }

  for(auto elem : result)
    cout << elem << ' ';

  cout << endl;
  
}
