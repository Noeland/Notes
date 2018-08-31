#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

struct Sales_data;
istream& read(istream& is, Sales_data& data);

struct Sales_data {
  friend istream& read(istream&, Sales_data&);
  friend ostream& print(ostream&, const Sales_data&);
  friend Sales_data add(const Sales_data, const Sales_data);
  
public:
  // Conscturctor:
  Sales_data(const string& s = ""):bookNo(s) { }
  Sales_data(const string& s, unsigned c, double p):
    bookNo(s), units_sold(c), revenue(c*p) { }
  Sales_data(istream& is = std::cin ) { read(is, *this); }

  // Interfaces:
  string isbn() const { return bookNo; }
  Sales_data& combine(const Sales_data& other);

private:
  double avg_price() const;

  string bookNo;
  unsigned units_sold = 0;
  double revenue = 0.0;
};

inline double Sales_data::avg_price() const
{
  if(units_sold)
    return revenue/units_sold;
  else
    return 0;
}

Sales_data& Sales_data::combine(const Sales_data& other)
{
  units_sold += other.units_sold;
  revenue += other.revenue;
  return *this;
}

istream& read(istream& is, Sales_data& data)
{
  double price = 0.0;
  is >> data.bookNo >> data.units_sold >> price;
  data.revenue = price * data.units_sold;
  
  return is;
}

ostream& print(ostream& os, const Sales_data& data)
{
  os << data.isbn() << " " << data.units_sold << " "
     << data.revenue << " " << data.avg_price();
  
  return os;
}

Sales_data add(const Sales_data& lhs, const Sales_data& rhs)
{
  Sales_data sum = lhs;
  sum.combine(rhs);
  
  return sum;
}

int main()
{
  Sales_data total;
  double price = 0;
  
  if(read(cin, total)) {
    Sales_data trans;
    
    while(read(cin, trans)) {
      if(total.isbn() == trans.isbn())
	total.combine(trans);
      else {
	print(cout, total) << endl;
	total = trans;
      }
    }

    print(cout, total) << endl;;	
  }
  else {
    cerr << "No Data!?" << endl; // Warn the users.
    return -1; // Indicate failure.
  }
}
