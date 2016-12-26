#include <iostream>
#include "Sales_item.h"

using namespace std;

int main()
{
  Sales_item next, curr;
  
  if(cin >> curr)
    {

      while(cin >> next)
	{
	  if(next.isbn() == curr.isbn())
	    curr+=next;
	  else
	    {
	      cout << "Book: " << curr << endl;
	      curr = next;
	    }
	}

      cout << "Book: " << curr << endl;
    }
}
