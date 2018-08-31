#include <iostream>
#include <string>

using namespace std;

struct Person{
  friend istream& read(istream&, Person&);
  friend ostream& print(ostream&, const Person&);
  
private:
  string name;
  string address;

public:
  Person() = default;
  Person(const string& n): name(n) { }
  Person(const string& n, const string& add):
    name(n), address(add) { }
  Person(istream& is) { read(is, *this); }

  string NameOf() const { return name; }
  string AddressOf() const { return address; }
};



istream& read(istream& is, Person& p)
{
  is >> p.name >> p.address;
  return is;
}

ostream& print(ostream& os, const Person& p)
{
  os << p.name << " " << p.address;
  return os;
}
