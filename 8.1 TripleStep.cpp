#include <iostream>

using namespace std;


int TripleStep(int n, int * memo){
    if (n < 0)
    {
        return 0;
    }
    else if (n == 0)
    {
        return 1;
    }
    else if (memo[n] > -1)
    {
        return memo[n];
    }
    else
    {
        memo[n] = TripleStep(n-1, memo) + TripleStep(n-2, memo) + TripleStep(n-3, memo) ;
        return memo[n];
    }
    
}

int main(){
    int n;
    cout << "Enter a number: ";
    cin >> n;
    int * memo = new int[n];
    for (int i = 0; i < n; i++)
    {
        memo[i] = -1;
    }
    
    cout << TripleStep(n, memo);

}