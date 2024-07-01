#include<vector>
using namespace std;

class GenericTrees
{
public:
    int data;
    vector<GenericTrees*> childrens;
    GenericTrees(/* args */);
    ~GenericTrees();
};

GenericTrees::GenericTrees(/* args */)
{

}

GenericTrees::~GenericTrees()
{
}
