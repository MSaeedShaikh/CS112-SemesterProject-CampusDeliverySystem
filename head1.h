#include <fstream>
#include <vector>
using namespace std;

int BId=0;

class Catalog{
    public:
    vector<string> name;
    vector<float> price;
    
    int findIndex(string item) {
        for (auto i = 0; i < name.size(); ++i) {
            if (name[i] == item)
                return i;
        }
        return -1;
    }
    void AddItem(string n, float p){
        name.push_back(n);
        price.push_back(p);
    }
    void RemoveItem(string item){
        int ind = findIndex(item);
        if(ind!=-1){
            name.erase(name.begin()+ind);
            price.erase(price.begin()+ind);
        }
    }
    void ChangePrice(string item, float p){
        int ind = findIndex(item);
        if(ind!=-1){
            price[ind]=p;
        }
    }
};


class Business : public Catalog{
    public:
    int id;
    string name;
    Business(string x){
        id=BId;
        BId++;
        name = x;
    }
    friend void BSave(vector<Business> &a);
    friend void BLoad(vector<Business> &a);
};

void BLoad(vector<Business> &a){

}