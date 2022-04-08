#include <iostream>
// #include<bits/stdc++.h>
using namespace std;
struct Node
{
    int element;
    Node *next;
};

class SLinkedList
{
    Node *head;

public:
    SLinkedList() : head(NULL) {}
    bool isempty() const
    {
        return head == NULL;
    }
    const int &front() const
    {
        return head->element;
    }
    void addFront(const int &e)
    {
        // creating new node
        Node *node = new Node;
        node->element = e;
        node->next = head;

        // add it to front
        head = node;
    }
    void removeFront()
    {
        Node *old_head = head;
        head = old_head->next;
        delete old_head;
    }
    void printList()
    {
        for (auto ptr = head; ptr; ptr = ptr->next)
        {
            cout << ptr->element << "==>";
        }
        cout << "NULL"<<endl;
    }
    void remove_element(int ele)
    {
        Node *node_to_delete;
        //if ele is found in head
        if(head->element == ele)
        {
            node_to_delete = head;
            head = head->next;
            delete node_to_delete;
        }


            //if current node is not null and there is next node
            for (auto ptr = head; ptr && ptr->next;ptr=ptr->next)
            {
                // if next node contains the key
                if(ptr->next->element == ele)
                {
                    node_to_delete = ptr->next;
                    ptr->next = ptr->next->next;
                    delete node_to_delete;

                }
            }
        

    }
    ~SLinkedList() {}
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1-in.txt", "r", stdin);
    freopen("3-out.txt", "w", stdout);
#endif
    std::ios::sync_with_stdio(false);

    SLinkedList sl;
    int n;
    cin >> n;
    while(n--)
    {
        int x;
        cin >> x;
        sl.addFront(x);
        sl.printList();
    }
    sl.remove_element(6);
    cout << "after removing" << endl;
    sl.printList();
    return 0;
}
