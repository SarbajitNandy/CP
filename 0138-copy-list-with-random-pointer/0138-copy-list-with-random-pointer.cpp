/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> mp;

        Node* head2=nullptr, *itr1 = head;
        Node* itr2 = nullptr;
        while(itr1!=nullptr) {
            Node* n = new Node(itr1->val);

            mp[itr1] = n;

            if (head2==nullptr) {
                head2 = n;
                itr2 = head2;
            } else {
                itr2->next = n;
                itr2=itr2->next;
            }

            itr1= itr1->next;
        }

        itr1 = head;
        itr2 = head2;

        while(itr1!=nullptr && itr2!=nullptr) {
            if (itr1->random!=nullptr) {
                itr2->random = mp[itr1->random];
            }


            itr1=itr1->next;
            itr2=itr2->next;
        }

        return head2;

    }
};