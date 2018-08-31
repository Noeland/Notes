#include <iostream>
#include <vector>

using namespace std;

istream& readandprint(istream &is)
{
  string inputs;
  char input;
  while(!is.eof())
    {
      if(is >> input)
	inputs += input;
    }

  for(auto elem : inputs)
    cout << elem;
  
  cout << endl;
  is.clear();
  return is;
}



int main()
{
  readandprint(cin);
}
