/*
 * Leetcode Easy 35. Search Insert Position
 * author: shizuka1024
 * AC(C++)
 */
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> P;
typedef long long int LL;
#define PB push_back
#define MP make_pair
#define X first
#define Y second

class Solution
{
public:
    int searchInsert(vector<int>& n, int k)
    {
        int l = 0, r = n.size();
        while(l < r)
        {
            int mid = (l+r) / 2;

            if(n[mid] >= k)
                r = mid;
            else
                l = mid+1;
        }

        return l;
    }

    int stl(vector<int>& n, int k)
    {
        return lower_bound(n.begin(), n.end(), k) - n.begin();
    }
};

int main()
{
    vector<int> v = {1,3,5,6};
    int t;
    while(cin >> t)
    {
        printf("t=%d => ", t);
        cout << Solution{}.searchInsert(v, t) << '\n';
    }
}
