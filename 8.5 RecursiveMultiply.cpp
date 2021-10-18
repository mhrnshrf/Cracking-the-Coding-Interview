#include<iostream>

using namespace std;

int RecursiveMultiply(int a, int b){
    if (b == 0)
    {
        return 0;
    }

    return RecursiveMultiply(a, b-1) + a;
}

int main(){

    int a = 11;
    int b = 7;

    cout << "Recursive Multiply:" << endl;
    cout << a << " x " << b << " = " << RecursiveMultiply(a, b) << endl;
}