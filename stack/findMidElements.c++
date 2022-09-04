#include <bits/stdc++.h>
using namespace std;

class SpecialStack
{
    struct Node
    {
        Node *prev;
        int val;
        Node *next;
        Node(int val)
        {
            Node *prev = NULL;
            this->val = val;
            Node *next = NULL;
        }
    };
    Node *head = NULL;
    Node *mid = NULL;
    int size = 0;

public:
    void push(int data)
    {
        Node *temp = new Node(data);
        if (size == 0)
        {
            head = temp;
            mid = temp;
            size++;
        }
        else
        {
            head->next = temp;
            temp->prev = head;
            // updating head bcz head acts as top elements
            head = head->next;
            // updating middle elements
            if (size % 2 == 1)
            {
                mid = mid->next;
                size++;
            }
        }
    }

    int pop()
    {
        int data = -1;
        if (size != 0)
        {
            if (size == 1)
            {
                data = head->val;
                Node *temp = head;
                head = NULL;
                mid = NULL;
                delete temp;
            }
            else
            {
                Node *temp = head;
                data = head->val;
                head = head->prev;
                head->next = NULL;
                if (size % 2 == 0)
                {
                    mid = mid->prev;
                }
                delete temp;
            }
            size--;
        }
        return data;
    }

    int findMiddle()
    {
        if (size == 0)
        {
            return -1;
        }
        return mid->val;
        ;
    }

    void popMiddle()
    {
        if (size != 0)
        {
            if (size == 1)
            {
                head = NULL;
                mid = NULL;
            }
            else if (size == 2)
            {
                head = head->prev;
                mid = mid->prev;
                mid->next = NULL;
                head->next = NULL;
            }
            else
            {
                mid->next->prev = mid->prev;
                mid->prev->next = mid->next;
                if (size % 2 == 0)
                {
                    mid = mid->prev;
                }
                else
                {
                    mid = mid->next;
                }
            }
            size--;
        }
    }
};

int main()
{
    SpecialStack st;
    st.push(10);
    st.push(20);
    st.push(30);
    cout << st.findMiddle() << endl;
    st.popMiddle();
    cout << st.findMiddle() << endl;
    st.pop();
    cout << st.findMiddle() << endl;
}