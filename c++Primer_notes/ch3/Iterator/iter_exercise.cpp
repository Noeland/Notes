#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
  vector<int> v1;         // empty vector
  vector<int> v2(10);     // ten zeros
  vector<int> v3(10, 42); // ten elements, each one is 42
  vector<int> v4{10};     // one elememnt, 10
  vector<int> v5{10, 42}; // 10 and 42
  vector<string> v6{10};  // ten empty strings
  vector<string> v7{10, "hi"}; // ten "hi"

  cout << "vector v1 has " << v1.size() << " element" << (v1.size() <= 1 ? "." : "s.") << endl;
  cout << "They are: " << endl;

  for(auto it = v1.cbegin() ; it != v1.cend(); ++it) {
    if(it + 1 == v1.cend())
      cout << *it << endl;
    else
      cout << *it << ", ";
  }
  
  cout << "vector v2 has " << v2.size() << " element" << (v2.size() <= 1 ? "." : "s.") << endl;
  cout << "They are: " << endl;

  for(auto it = v2.cbegin() ; it != v2.cend(); ++it) {
    if(it + 1 == v2.cend())
      cout << *it << endl;
    else
      cout << *it << ", ";
  }

  
  cout << "vector v3 has " << v3.size() << " element" << (v3.size() <= 1 ? "." : "s.") << endl;
  cout << "They are: " << endl;
  for(auto it = v3.cbegin() ; it != v3.cend() ; ++it) {
    if(it == v3.cend() - 1)
      cout << *it << endl;
    else
      cout << *it << ", ";
  }

  cout << "vector v4 has " << v4.size() << " element" << (v4.size() <= 1 ? "." : "s.") << endl;
  cout << "They are: " << endl;
  for(auto it = v4.cbegin(); it != v4.cend(); ++it) {
    if(it == v4.cend() - 1)
      cout << *it << endl;
    else
      cout << *it << ", ";
  }

  cout << "vector v5 has " << v5.size() << " element" << (v5.size() <= 1 ? "." : "s.") << endl;
  cout << "They are: " << endl;
  for(auto it = v5.cbegin(); it != v5.cend(); ++it) {
    if(it == v5.cend() - 1)
      cout << *it << endl;
    else
      cout << *it << ", ";
  }

  cout << "vector v6 has " << v6.size() << " element" << (v6.size() <= 1 ? "." : "s.") << endl;
  cout << "They are: " << endl;
  for(auto it = v6.cbegin(); it != v6.cend(); ++it)
    if(it == v6.cend() - 1)
      cout << *it << endl;
    else
      cout << *it << ", ";

  cout << "vector v7 has " << v7.size() << " element" << (v7.size() <= 1 ? "." : "s.") << endl;
  cout << "They are: " << endl;
  for(auto it = v7.cbegin(); it != v7.cend(); ++it)
    if(it == v7.cend() - 1)
      cout << *it << endl;
    else
      cout << *it << ", ";

  
  
}
