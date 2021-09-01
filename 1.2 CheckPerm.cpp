#include <iostream>

using namespace std;

bool CheckPerm(string str1, string str2){

    if(str1.length() != str2.length()){
        return false;
    }

    char bitmap1[256] = {0};
    char bitmap2[256] = {0};

    for (int i = 0; i < str1.length(); i++)
    {
        bitmap1[str1[i]] += 1;
        bitmap2[str2[i]] += 1;
    }

    for (int i = 0; i < 256; i++)
    {
        if ( bitmap1[i] !=  bitmap2[i])
        {
            return false;
        }
    }
    return true;
}


int main(){
    string str1, str2;

    cout << "Enter a string:" << endl;
    cin >> str1;
    cout << "Enter another string:" << endl;
    cin >> str2;

    string msg = CheckPerm(str1, str2) ? "is perm" : "not perm";
    cout << msg << endl;

    return 0;
}