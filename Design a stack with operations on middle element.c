/*
How to implement a stack which will support following operations in O(1) time complexity? 
1) push() which adds an element to the top of stack. 
2) pop() which removes an element from top of stack. 
3) findMiddle() which will return middle element of the stack. 
4) deleteMiddle() which will delete the middle element. 
Push and pop are standard stack operations. 
*/

#include <bits/stdc++.h>
using namespace std;

class Stack
{
    struct Node
    {
        int data;
        Node *prev;
        Node *next;
        Node(int num){
            this->data = num;
        }
    };
    public:
    
    Node *head = NULL;
    Node *mid = NULL;
    int size = 0;
    
    void push(int x)
    {
        Node *temp = new Node(x);
        if(head == NULL){
            head = temp;
            temp->next = NULL;
            mid = temp;
            size++;
            return;
        }
        else{
            temp->next = head;
            head->prev = temp;
            head = temp;
            if(size%2==1){
                mid = mid->prev;
            }
            size++;
        }
        
    }
    int pop()
    {
        if(head == NULL){
            cout << "Stack is empty\n";
            return 0;
        }
        else{
            if(size%2==0){
                mid = mid->next;
            }
            int x = head->data;
            head->next->prev = head;
            head = head->next;
            size--;
            return x;
        }
        
    }
    int getMiddle()
    {
        int x = mid->data;
        return x;
    }
    void delMiddle()
    {
        Node *temp;
        if(size%2==1){
            temp = mid->prev;
        }
        else{
            temp = mid->next;
        }
        mid->prev->next = mid->next;
        mid->next->prev = mid->prev;
        size--;
        mid = temp;
    }
    void display()
    {
        if(head==NULL){
            cout << "Stack is empty";
        }
        else{
            Node *temp = head;
            while(temp!=NULL){
                cout << temp->data << "->";
                temp = temp->next;
            }
            cout<<endl;
        }
    }
    
};

int main()
{
    Stack s;
    s.push(1);
    s.push(2);
    cout << s.getMiddle() << endl;
    s.push(3);
    s.push(4);
    cout << s.getMiddle() << endl;
    s.delMiddle();
    s.display();
    cout << s.getMiddle() << endl;
}
