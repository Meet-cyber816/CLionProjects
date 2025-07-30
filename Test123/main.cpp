
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 != nullptr && list2 != nullptr){
            ListNode *temp1 = list1;int i=0;
            while(temp1->next != nullptr){
                temp1 = temp1->next;i++;
            }
            temp1->next = list2;
            int j=0;
            while(j<i){
                temp1 = list1;
                while(temp1->next != nullptr){
                    if(temp1->val > temp1->next->val){
                        int x = temp1->val;
                        temp1->val = temp1->next->val;
                        temp1->next->val = x;
                    }
                    temp1 = temp1->next;
                }
                j++;
                temp1 = list1;
            }
        }
        else{
            if(list1 == nullptr)
                return list2;
            else
                return list1;
        }
        return list1;
    }
};

int main() {
    Solution s1;
    s1.
}