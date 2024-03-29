/*
 * Leetcode Medium 133. Clone Graph
 * author: shizuka1024
 * AC(C++)
 */
#include <bits/stdc++.h>
using namespace std;
#include "helper.h"

class Solution {
public:
    map<Node*, bool> vis;
    // old to new
    map<Node*, Node*> o2n;
    Node* bfs(Node *n)
    {
        if(!n) return nullptr;
        o2n[n] = new Node(n->val);

        queue<Node*> q;
        q.push(n);
        vis[n] = true;
        
        while(!q.empty())
        {
            Node *cur = q.front();
            q.pop();
            
            o2n[cur]->val = cur->val;
            
            for(Node *a : cur->neighbors)
            {
                if(!o2n.count(a))
                    o2n[a] = new Node(a->val);
                
                o2n[cur]->neighbors.push_back(o2n[a]);
                
                if(!vis.count(a))
                {
                    q.push(a);
                    vis[a] = true;
                }
            }
        }
        
        return o2n[n];
    }
    
    Node* cloneGraph(Node* node)
    {
        return bfs(node);
    }
};

int main()
{
    //
}
