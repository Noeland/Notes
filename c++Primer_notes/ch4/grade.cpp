/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string score[] = {"F", "D", "C", "B", "A", "A++"};
    vector<string> lettergrades;
    
    unsigned int grade;
    
    while(cin >> grade) {
        if(grade < 60) {
            lettergrades.push_back(score[0]);
            cout << "Grade: " << score[0] << endl;
        }
        else {
            
            string lettergrade = score[(grade - 50) / 10];
            if(grade != 100) {
                if(grade % 10 >= 7) {
                    lettergrade += "+";
                    lettergrades.push_back(lettergrade);
                    cout << "Grade: " << lettergrade << endl;
                }
                else if(grade % 10 <= 3) {
                    lettergrade += "-";
                    lettergrades.push_back(lettergrade);
                    cout << "Grade: " << lettergrade << endl;
                }
                else {
                    lettergrades.push_back(lettergrade);
                    cout << "Grade: " << lettergrade << endl;
                }
            }
            else {
                lettergrades.push_back(lettergrade);
                cout << "Grade: " << lettergrade << endl;
            }
            
        }
    }
}



