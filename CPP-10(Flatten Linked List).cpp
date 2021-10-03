#include <bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};

void printList(Node *Node)
{
    while (Node != NULL)
    {
        printf("%d ", Node->data);
        Node = Node->bottom;
    }
}

Node* flatten (Node* root);

int main(void) {

	int t;
	cin>>t;
	while(t--){
    int n,m,flag=1,flag1=1;
    struct Node * temp=NULL;
	struct Node * head=NULL;
	struct Node * pre=NULL;
	struct Node * tempB=NULL;
	struct Node * preB=NULL;
		cin>>n;
        int work[n];
		for(int i=0;i<n;i++)
            cin>>work[i];
		for(int i=0;i<n;i++){
			m=work[i];
			--m;
			int data;
			scanf("%d",&data);
			temp = new Node(data);
			temp->next = NULL;
			temp->bottom = NULL;
			
			if(flag){
				head = temp;
				pre = temp;
				flag = 0;
				flag1 = 1;
			}
			else{
				pre->next = temp;
				pre = temp;
				flag1 = 1;
			}
			for(int j=0;j<m;j++){
				
				int temp_data;
				scanf("%d",&temp_data);
				tempB = new Node(temp_data);

				if(flag1){
					temp->bottom=tempB;
					preB=tempB;
					flag1=0;
				}
				else{
					preB->bottom=tempB;
					preB=tempB;
				}
			}
		}
		   Node *fun = head;
		   Node *fun2=head;

            Node* root = flatten(head);
            printList(root);
            cout<<endl;

	}
	return 0;
}
// } Driver Code Ends


/* Node structure  used in the program

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};
*/

/*  Function which returns the  root of 
    the flattened linked list. */
//bool compare(Node *a, Node *b){return a->data > b->data;}
Node *flatten(Node *root)
{
   struct compare {
    bool operator()(Node* a, Node* b)
    {
        return a->data > b->data;
    }
   };

    Node* ptr = root;
    Node* head = NULL;
 
    // Min Heap which will return
    // smallest element currently
    // present in heap
    priority_queue<Node*,
            vector<Node*>,
             compare> pq;
 
    // Push the head nodes of each
    // downward linked list
    while (ptr != NULL) {
        pq.push(ptr);
        ptr = ptr->next;
    }
 
    // This loop will execute
    // till the map becomes empty
    while (!pq.empty()) {
 
        // Pop out the node that
        // contains element
        // currently in heap
        Node* temp = pq.top();
        pq.pop();
 
        // Push the next node pointed by
        // the current node into heap
        // if it is not null
        if (temp->bottom != NULL) {
            pq.push(temp->bottom);
        }
 
        // Create new linked list
        // that is to be returned
        if (head == NULL) {
            head = temp;
            ptr = temp;
            ptr->next = NULL;
        }
        else {
            ptr->bottom = temp;
            ptr = temp;
            ptr->next = NULL;
        }
    }
 
    // Pointer to head node
    // in the linked list
    return head;
}
