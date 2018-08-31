#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main()
{
  string result;     // The resulting large string
  string input;      // The user input

  while(cin >> input) {
    result += input;
  }

  cout << result << endl;
}
