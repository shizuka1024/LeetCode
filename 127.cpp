/*
 * Leetcode Hard 127. Word Ladder
 * author: shizuka1024
 * AC(C++)
 */
#include <bits/stdc++.h>
using namespace std;
#include "helper.h"

#define N 5000

class Solution {
public:

    vector<int> G[N+5][10];
    unordered_map<string, int> s2i;
    vector<string> v;
    int siz;

    void build(string fr)
    {
        unordered_map<string, vector<string>> m;
        
        int a = 0;
        for(string s : v)
        {
            s2i[s] = a++;
            for(int i = 0; i < s.size(); i++)
            {
                string orig = s;
                s[i] = '.';
                m[s].push_back(orig);
                s = orig;
            }
        }

        siz = v[0].size();
      
        for(int i = 0; i < v.size(); i++)
        {
            for(int j = 0; j < v[i].size(); j++)
            {
                string orig = v[i];
                char c = v[i][j];

                v[i][j] = '.';

                if(m.count(v[i]))
                {
                    for(string k : m[v[i]])
                    {
                        if(orig == k)
                            continue;
                        G[i][j].push_back(s2i[k]);
                    }
                }

                v[i][j] = c;
            }
        }

        v.push_back(fr);
        s2i[fr] = v.size()-1;
        for(int i = 0; i < fr.size(); i++)
        {
            string orig = fr;
            fr[i] = '.';

            if(m.count(fr))
            {
                for(string k : m[fr])
                {
                    if(orig == k)
                        continue;
                    
                    G[s2i[orig]][i].push_back(s2i[k]);
                }
            }

            fr = orig;
        }
    }

    int ans = INT_MAX;
    void dfs(int step, int a, int b)
    {
        
        if(a == b)
        {
            ans = min(ans, step);
            return;
        }

        for(int i = 0; i < siz; i++)
        {
            for(int j : G[a][i])
            {
                if(!visit[j])
                {
                    visit[a] = true;
                    dfs(step+1, j, b);
                    visit[a] = false;
                }
            }
        }
    }

    int val[N+5];
    bool visit[N+5];
    void bfs(int a, int b)
    {
        queue<int> q;
        q.push(a);
        val[a] = 0;

        memset(val, 0, sizeof(val));
        memset(visit, 0, sizeof(visit));

        while(!q.empty())
        {
            int cur = q.front(); q.pop();

            for(int i = 0; i < siz; i++)
            {
                for(int j : G[cur][i])
                {
                    if(!visit[j])
                    {
                        q.push(j);
                        val[j] = val[cur] + 1;
                        visit[j] = true;
                    }
                }
            }
        }
    }

    int ladderLength(string fr, string to, vector<string>& l)
    {
        v = l;
        build(fr);

        if(!s2i.count(to))
            return 0;

        bfs(s2i[fr], s2i[to]);
        int ans = val[s2i[to]];
        
        return ans ? ans+1 : 0;
    }
};

int main()
{
    vector<string> l = {"hot","dot","dog","lot","log","cog"};
    string start = "hit", end = "cog";

    cout << Solution{}.ladderLength(start, end, l) << '\n';
}
