#include<vector>
#include<unordered_map>
using namespace std;



/*=============================================
Leetcode Daily
2023.04.08
133. Clone Graph
https://leetcode.com/problems/clone-graph/description/
1. The idea is to keep a mapping of (conceptually) <original node, cloned node>
2. and then do dfs on the node.
3. Note that the description of the problem says that the given graph is a connected undirected graph,
so dfs must find all nodes starting from any node.
4. dfs is a recursive function:
    base cases: no nodes, return nullptr
    recursive cases:
        1. if the node is already cloned, return the cloned node
        2. if the node is not cloned, clone it and add it to the map
        3. for each neighbor of the node, find the cloned neighbor and add it to the cloned node's neighbors
Runtime
7 ms Beats 61.34%
Memory
8.9 MB Beats 53.37%
=============================================*/

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    unordered_map <int, Node*> o2c;
    Node* cloneGraph(Node* node) {
        // dfs must find all nodes because the given map is a connected undirected graph
        if (!node){
            return nullptr;
        }
        int key = node -> val;
        if (o2c.find(key) != o2c.end()){
            return o2c[key];
        }
        Node* clone = new Node(key);
        o2c[key] = clone;
        for (auto n: node->neighbors){
            o2c[n->val] = cloneGraph(n);
            o2c[key]->neighbors.push_back(o2c[n->val]);
        }
        return o2c[key];
    }
};

int main(){
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);
    n1->neighbors.push_back(n2);
    n1->neighbors.push_back(n4);
    n2->neighbors.push_back(n1);
    n2->neighbors.push_back(n3);
    n3->neighbors.push_back(n2);
    n3->neighbors.push_back(n4);
    n4->neighbors.push_back(n1);
    n4->neighbors.push_back(n3);
    /*
    1----2
    |    |
    4----3
    */
    Solution s;
    Node* clone = s.cloneGraph(n1);
    return 0;
}