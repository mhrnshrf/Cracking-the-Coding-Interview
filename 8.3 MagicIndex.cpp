#include<iostream>
#include<vector>
#include <algorithm> 

using namespace std;

int MagicIndex(int * arr, int start, int end){

    if (start > end)
    {
        return -1;
    }
    
    int mid = (start + end)/2;
    if (arr[mid] == mid)
    {
        return mid;
    }
    else if(arr[mid] < mid)
    {
        return MagicIndex(arr, mid+1, end);
    }
    else
    {
        return MagicIndex(arr, start, mid-1);
    }

}


int MagicIndexNotUnique(int * arr, int start, int end){

    if (start > end)
    {
        return -1;
    }
    
    int mid = (start + end)/2;
    if (arr[mid] == mid)
    {
        return mid;
    }


    int leftInd = min(mid-1, arr[mid]);
    int left = MagicIndexNotUnique(arr, start, leftInd);
    if(left > 0)
    {
        return left;
    }

    int rightInd = max(mid+1, arr[mid]);
    return MagicIndexNotUnique(arr, rightInd, end);

}

int main(){

    int array[5] = {-1, 1, 3, 4, 5};

    int mi = MagicIndex(array, 0, 4);

    if (mi == -1)
    {
        cout << "No magic index found!" << endl;
    }
    else
    {
        cout << "Magic index: " << mi << endl;
    }


    int arrayRep[5] = {1, 2, 2, 4, 5};

    int nu = MagicIndexNotUnique(arrayRep, 0, 4);
    // int nu = MagicIndexNotUnique(array, 0, 4);

    if (nu == -1)
    {
        cout << "No magic index found!" << endl;
    }
    else
    {
        cout << "Magic index: " << nu << endl;
    }

}
