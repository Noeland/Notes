#include <iostream>
#include <string>
#include "Sales_data.h"
using namespace std;

int main()
{
  Sales_data data1, data2;
  // read in two data
  // check if they have the same bookNo
  // proceed if true

  double price;
  
  cout << "Please enter the first data: " << endl;
  cin >> data1.bookNo >> data1.unit_sold >> price ;
  data1.revenue = data1.unit_sold * price;

  cout << "Please enter the second data: " << endl;
  cin >> data2.bookNo >> data2.unit_sold >> price;
  data2.revenue = ( (double) data2.unit_sold ) * price;

  if(data1.bookNo == data2.bookNo)
    {
      int totalCnt = data1.unit_sold + data2.unit_sold;
      double totalRev = data1.revenue + data2.revenue;
      
      cout << data1.bookNo << " " << totalCnt << " ";
      
      if(totalCnt != 0)
	cout << totalRev / totalCnt << endl;
      else
	cout << "(no sale)" << endl;

      return 0;
    }
  else
    {
      cout << "Data with different bookNo" << endl;
      return -1;
    }
}
