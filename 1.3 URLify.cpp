#include <iostream>
#include <string>

using namespace std;

string URLify(string str, int len){
    int sp = 0;
    char* url = new char[len*3]; 
    int ind = 0;
    bool consec = false;
    for (int i = 0; i < len; i++)
    {
        
        if (str[i] != ' ')
        {
            url[ind] = str[i];
            ind++;
            consec = false;
        }
        else if (!consec)
        {
             url[ind] = '%';
             url[ind+1] = '2';
             url[ind+2] = '0';
             ind += 3;
             consec = true;
        }
      
              
    }
    return url;
}

int main(){
    string str;
    int len;
    cout << "Enter a string:" << endl;
    getline(cin, str);
    cout << "Enter its length:" << endl;
    cin >> len;

    cout << URLify(str, len) << endl;

    return 0; 
}


