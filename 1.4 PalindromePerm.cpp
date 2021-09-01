#include <iostream>
#include <string>
#include <cctype>

using namespace std;


bool PalindromePerm(string str){
    int bitmap[256] = {0};
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] != ' ')
        {
            if (isupper(str[i]))
            {
                str[i] += 32;
            }
            
            bitmap[str[i]]++;
        }
        
    }
    
    int odd = 0;
    for (int i = 0; i < 256; i++)
    {
        if (bitmap[i] % 2 != 0)
        {
            odd++;
        }
        
    }
    
    bool res = (odd > 1) ? false : true;
    
    return res;
}

int main () {
    string str;
    getline(cin, str);

    string msg = PalindromePerm(str) ? "true" : "false";

    cout << msg << endl;
}