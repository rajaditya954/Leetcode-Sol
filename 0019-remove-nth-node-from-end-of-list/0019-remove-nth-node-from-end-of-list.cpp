class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size = 0;
        ListNode* temp = head;

        
        while (temp != nullptr) {
            size++;
            temp = temp->next;
        }

       
        int pos = size - n;

        if (pos == 0) {
            ListNode* del = head;
            head = head->next;
            delete del;
            return head;
        }

      
        temp = head;
        for (int i = 1; i < pos; i++) {
            temp = temp->next;
        }

        
        ListNode* del = temp->next;
        temp->next = del->next;
        delete del;

        return head;
    }
};