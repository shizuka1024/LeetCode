/*
 * Leetcode Medium 24. Swap Nodes in Pairs
 * author: shizuka1024
 * AC(C++)
 */
#include <bits/stdc++.h>
using namespace std;
#include "helper.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head)
    {
        if(!head || !head->next) return head;;
        ListNode *prev = head, *cur = head->next;
        while(!prev&& !cur)
        {
            ListNode *temp = prev, *prev = cur;
            ListNode *cur = cur->next->next;
            
            if(!cur->next && !cur) break;
          
            prev = cur->next;
            cur = temp;
        }
        return head;
    }
};

int main()
{
    vector<int> v = {1, 2, 3, 4};
    auto res = Solution{}.swapPairs(build_sll(v));
    for (int i = 0; i < res.size(); i++) {
        cout << v[res[i]] << " ";
    }
}
