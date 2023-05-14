#include <fstream>
#include <vector>
using namespace std;

int BId=0;

class Catalog{
    public:
    vector<string> iname;
    vector<float> iprice;
    
    int findIndex(string item) {
        for (int i = 0; i < iname.size(); ++i) {
            if (iname[i] == item)
                return i;
        }
        return -1;
    }
    void AddItem(string n, float p){
        iname.push_back(n);
        iprice.push_back(p);
    }
    void RemoveItem(string item){
        int ind = findIndex(item);
        if(ind!=-1){
            iname.erase(iname.begin()+ind);
            iprice.erase(iprice.begin()+ind);
        }
    }
    void ChangePrice(string item, float p){
        int ind = findIndex(item);
        if(ind!=-1){
            iprice[ind]=p;
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