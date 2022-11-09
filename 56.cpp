/*
 * Leetcode Medium 56. Merge Intervals
 * author: shizuka1024
 * AC(C++)
 */
#include <bits/stdc++.h>
using namespace std;
#include "helper.h"
#define PB push_back

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>>& v)
    {
        vector<vector<int>> ans;

        if(v.size() <= 1) return v;

        sort(v.begin(), v.end(), [](vector<int> &lhs, vector<int> &rhs) {
            return lhs[0] == rhs[0] ? lhs[1] < rhs[1] : lhs[0] < rhs[0];
        });

        int cur = 0, r = 1;

        while(cur < v.size() && r < v.size())
        {
            if(v[cur][1] >= v[r][0])
            {
                if(v[cur][1] <= v[r][1])
                    v[cur][1] = v[r][1];
            }
            else
            {
                ans.push_back(v[cur]);
                cur = r;
            }
            r++;
        }
        ans.push_back(v[cur]);
        return ans;
    }
};

int main()
{
    vector<vector<int>> v = {{1,4}, {2,3}};
    v = Solution{}.merge(v);
    DBG(v);
}
