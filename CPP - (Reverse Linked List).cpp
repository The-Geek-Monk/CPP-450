#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node* next;
    
    node(int x){
        data = x;
        next = NULL;
    }
    
};

/* Function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

class Solution
{
    public:
    struct node *reverse (struct node *head, int k)
    { 
        if (!head or k==1) return head;
        
        node *curr = head, *prevFirst = NULL;
        
        bool isFirst = true;
        
        while(curr)
        {
            int count = 0;
            node *first = curr, *prev = NULL;
            while(curr && count < k)
            {
                node *next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
                count++;
            }
            if (isFirst){head = prev, isFirst = false;}
            else prevFirst->next = prev;
            prevFirst = first;
        }
        
        return head;
    }
};

int main(void)
{
    int t;
    cin>>t;
     
    while(t--)
    {
        struct node* head = NULL;
        struct node* temp = NULL;
        int n;
        cin >> n;
         
        for(int i=0 ; i<n ; i++)
        {
            int value;
            cin >> value;
            if(i == 0)
            {
                head = new node(value);
                temp = head;
            }
            else
            {
                temp->next = new node(value);
                temp = temp->next;
            }
        }
        
        int k;
        cin>>k;
        
        Solution ob;
        head = ob.reverse(head, k);
        printList(head);
    }
     
    return(1);
}
