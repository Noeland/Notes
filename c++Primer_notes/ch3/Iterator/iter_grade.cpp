#include <iostream>
#include <vector>

using namespace std;

int main()
{
  vector<unsigned> result(11,0);

  unsigned grade;

  while(cin >> grade) {
    if(grade <= 100)
      ( *(result.begin() + grade/10) )++;
  }

  for(auto e : result)
    cout << e << ' ';

  cout << endl;
}
