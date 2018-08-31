#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string cur, prev;
    
    cin >> prev;
    unsigned int cnt = 0;
    unsigned int max = cnt;
    string most;
    while(cin >> cur) {
      
        if(cur == prev) {
            cnt++;
            if(cnt > max) {
                max = cnt;
                most = cur;
            }
        }
        else
            cnt = 0;

	prev = cur;
    }
    
    if(max == 0)
        cout << "No word is repeated. " << endl;
    else
        cout << "The word that is repeated the most time is: " << most << endl;
}
