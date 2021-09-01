#include <iostream>

using namespace std;

int main(int argc, char * argv[]){
    string str;
    cout << "Enter a string:" << endl;

    cin >> str;
    int i = 0;
    int j = 0;
    bool unique = true;
    char c = str[0];
    char var = str[0];
    while (c != NULL)
    {
        // cout << "c: "<< c << endl;
        var = str[0];
        j = 0;
        while (var != NULL)
        {
            // cout << "var: " << var << endl;
            var = str[j];
            if (var == c && i != j)
            {
               unique = false;
               break;
            }
            
            j++;
        }
        if (!unique)
        {
            break;
        }      
        
        i++;
        c = str[i];
    }
    
    string msg = unique?"unique":"not unique";
    cout << msg << endl;
    return 0;
}