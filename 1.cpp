/*
 * Leetcode Easy 1. Two Sum
 * author: shizuka1024
 * AC(C++)
 */
#include <bits/stdc++.h>
using namespace std;

#define PB push_back

#define N 10000

class Solution
{
public:
    vector<int> twoSum(vector<int>& n, int t)
    {
        vector<int> ans;
        map<int, vector<int>> m;
        set<int> used;

        for(int i = 0; i < n.size(); i++)
            m[n[i]].PB(i);

        for(int i = 0; i < n.size(); i++)
        {
            int val = n[i];
            used.insert(i);

            if(m.count(t-val))
            {
                for(int j : m[t-val])
                {
                    if(!used.count(j))
                    {
                        ans.PB(i);
                        ans.PB(j);
                        goto end;
                    }
                }
            }

            used.erase(i);
        }
end:
        return ans;
    }
};

int main()
{
    vector<int> v = {2,7,11,15};
    int t = 9;
    auto a = Solution{}.twoSum(v, t);
    for (int i = 0; i < a.size(); i++) {
        cout << v[a[i]] << " ";
    }
}
