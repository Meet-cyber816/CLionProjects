//
// Created by meetpanchal on 7/20/25.
//
#include <vector>
#include <iostream>
using namespace std;


struct ListNode {
    int val;
  ListNode *next;
    explicit ListNode(int x) : val(x), next(nullptr) {}
};

struct Pos{
    int val;
    int pos;
};
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *temp = head;
        int len=0,j=0;
        vector<Pos> v1;
        v1.push_back({head->val, j});
        temp = temp->next;
        for(auto &i : v1){
            while( temp->val != i.val){
                j++;
                v1.push_back( {temp->val, j});
                temp = temp->next;
            }
            temp=head;
        }
        temp=head;
        while(len<j){
            temp = temp->next;
        }
        for(auto &i : v1)
            if(temp->next->val == i.val)
                return true;
        return false;
    }
};