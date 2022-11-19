/*
 * Leetcode Easy 141. Linked List Cycle
 * author: shizuka1024
 * AC(C++)
 */
#include <bits/stdc++.h>
using namespace std;
#include "helper.h"

typedef pair<int, int> P;
typedef long long int LL;
#define PB push_back
#define MP make_pair
#define X first
#define Y second

class Solution
{
public:
    set<ListNode*> s;
    bool intuition(ListNode *head)
    {
        ListNode *cur = head;
        while(cur)
        {
            if(s.count(cur))
            {
                return true;
            }
            s.insert(cur);
            cur = cur->next;
        }
        return false;
    }

    bool floyd(ListNode *head)
    {
        ListNode *a = head, *b = head;
        while(b && b->next)
        {
            a = a->next;
            b = b->next->next;
            
            if(a == b)
                return true;
        }
        return false;
    }

    bool hasCycle(ListNode *head)
    {
        return floyd(head);
    }
};

int main()
{
    vector<int> v = {1,2};
    int pos = 0;
    ListNode *h = build_sll(v), *last = h, *c = h;
    while(last->next)
        last = last->next;
    while(pos > 0 && c->next)
    {
        c = c->next;
        pos--;
    }
    cout << Solution{}.hasCycle(h) << '\n';
}
