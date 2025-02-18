#include "graphs.h"
#include <iostream>
#include <stdexcept>
#include <vector>

Graph::Graph(const vector<int> &starts, const vector<int> &ends) {
    if(starts.size() != ends.size()) {
        throw invalid_argument("Start and end points must be of equal amounts");
    }
    for(int i = 0; i <starts.size(); i++ ) {
        int start = starts[i];
        int end = ends[i];
        out[start].push_back(end);
        out[end];
    }
}

int Graph::numOutgoing(const int nodeID) const {
    return adjacent(nodeID).size();
}

const vector<int> &Graph::adjacent(const int nodeID) const {
    map<int,vector<int>>::const_iterator i = out.find(nodeID);
    if(i == out.end()) {
        throw invalid_argument ("Invalid node ID");
    }
    return i->second ;
}