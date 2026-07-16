class Solution {
public:
    ListNode* findlastnode(ListNode* head, int k){
        while(--k){
            head = head->next;
        }
        return head;
    }

    ListNode* rotateRight(ListNode* head, int k) {

        if(head == nullptr || head->next == nullptr || k == 0)
            return head;

        int count = 1;
        ListNode* tail = head;

        while(tail->next != nullptr){
            tail = tail->next;
            count++;
        }

        k %= count;

        if(k == 0)
            return head;

        tail->next = head;

        ListNode* lastnode = findlastnode(head, count - k);

        head = lastnode->next;

        lastnode->next = nullptr;

        return head;
    }
};