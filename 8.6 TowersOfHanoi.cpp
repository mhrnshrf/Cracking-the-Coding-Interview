#include<iostream>
#include<stack>
#include<vector>

using namespace std;

class Tower{
    public:
        stack<int>* disks;
        int index;
        Tower(int i){
            index = i;
            disks = new stack<int>();
        }
        void addTop(int d){
            disks->push(d);
        }
        void removeTop(){
            if (!disks->empty()){
                disks->pop();
            }
        }
        void print(){
            cout << "Tower " << index << endl;
            while (!disks->empty()){
                cout << disks->top() << endl;
                disks->pop();
            }
        }

        void moveDisks(Tower * buf, Tower * dest, int n){
            if (n <= 0){
                return;
            }
            
            this->moveDisks(dest, buf, n-1);
            int d = disks->top();
            this->removeTop();
            dest->addTop(d);
            buf->moveDisks(this, dest, n-1);
        }

};






int main(){

    int n;
    cout << "Enter number of disks: ";
    cin >> n;

    vector<Tower*> * hanoi = new vector<Tower*>();
    for (int i = 0; i < 3; i++){
        Tower * t = new Tower(i);
        hanoi->push_back(t);
    }
    

    for (int i = n-1; i >= 0; i--){
        hanoi->at(0)->disks->push(i);
    }

    
    hanoi->at(0)->moveDisks(hanoi->at(1), hanoi->at(2), n);

    for (int i = 0; i < 3; i++){
        hanoi->at(i)->print();
    }
    


}