#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

int main()
{

  vector<int> result;      // holds the sum of pair

  int input;               // holds the input integer
  int sum;                 // sum of current pair
  unsigned count = 0;      // count the number of inputs
  
  while(cin >> input) {
    if(count++ % 2 == 0)     // Increment the counter after the calculation
      sum = input;           // The even number inputs are the first element in a pair
    else {                   // the odd number inputs are the second element in a pair
      sum += input;          // calculate the sum of the current pair
      result.push_back(sum); // push the sum to the back of the vector result
    }
  }

  if(count % 2 != 0)         // If the total number of input is not even
    result.push_back(sum);

  for(auto elem : result)
    cout << elem << ' ';
  
  cout << endl;
  
}
