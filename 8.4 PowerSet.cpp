#include<iostream>
#include<vector>


using namespace std;

vector<vector<int> *>* getSubset(vector<int> * set, int ind){

    vector<vector<int> * > * subset = new vector<vector<int> *>();
    vector<int> * voidset = new vector<int>();
    subset->push_back(voidset);

    if (ind < 0)
    {
        return subset;
    }

    if (ind == 0)
    {
        vector<int> * single = new vector<int>();
        single->push_back(set->at(ind));
        subset->push_back(single);
        return subset;
    }
    
    
    vector<vector<int> * > * prevSubset = getSubset(set, ind-1);

    for (int i = 0; i < prevSubset->size(); i++)
    {
        subset->push_back(prevSubset->at(i));
        vector<int> * repset= new vector<int>();

        for (int j = 0; j < prevSubset->at(i)->size(); j++)
        {
            repset->push_back(prevSubset->at(i)->at(j));
        }
        subset->push_back(repset);
        subset->back()->push_back(set->at(ind));
    }
    
    return subset;

}



int main(){
    vector<int> set = {1, 2, 3};

    vector<vector<int> *>* subset = getSubset(&set, set.size()-1);

    for (int i = 0; i < subset->size(); i++)
    {
        for (int j = 0; j < subset->at(i)->size(); j++)
        {
            cout << subset->at(i)->at(j) ;
            if (j != subset->at(i)->size()-1)
            {
                cout << ", ";
            }
        }
        cout << endl;
    }
}