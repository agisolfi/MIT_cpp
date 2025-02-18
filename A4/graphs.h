#include <iostream>
#include <map>
using namespace std;

class Graph{
    protected:
        map<int,vector<int>> out;

    public:
        Graph(const vector<int> &starts, const vector<int> &ends);
        int numOutgoing(const int nodeID) const;
        const vector<int> &adjacent(const int nodeID) const;
};