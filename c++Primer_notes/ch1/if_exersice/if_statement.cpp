#include <iostream>

/*
 * Program to count how many times each value
 * occurs consecutively.
 */

int main()
{
  int curVal=0, val=0, cnt=0;
  
  if(std::cin >> curVal)
    {
      cnt = 1;
      while(std::cin >> val)
	{
	  if(val == curVal)
	    cnt++;
	  else
	    {
	      std::cout << curVal << " occurs " << cnt << " time"
			<< ( cnt > 1 ? "s." : ".") << std::endl;
	      curVal = val;
	      cnt = 1;
	    }
	}

	  std::cout << curVal << " occurs " << cnt << " time"
		    << (cnt > 1 ? "s." : ".") << std::endl;
    }
}
