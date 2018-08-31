#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
  string result;    // Input strings seperated by white space
  string input;     // the user input

  while(cin >> input) {
    result += input + " ";
  }

  cout << result << endl;
}
