#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main()
{
  string hexdigits = "0123456789ABCDEF";  // possible hex digits

  cout << "Enter a series of numbers between 0 and 15"
       << " seperated by spaces. Hit ENTER when finished: "
       << endl;

  string result;        // will hold the resulting hexify'd input
  string::size_type n;  // hold numbers from the input

  while (cin >> n)
    if( n < hexdigits.size())   // ignore invalid input
      result += hexdigits[n];   // fetch the indicated hex digits
  
  cout << "Your hex number is: " << result << endl;
}
