struct Node {
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

int getMiddle(Node *head)
{
   int n=0;
   if(head!=NULL){
       n+=1;
   }
   struct Node* temp= head;
   while(temp->next!=NULL){
       n+=1;
       temp=temp->next;
   }
   temp=head;
   int t=n/2;
   while(t--){
       temp=temp->next;
   }
   return temp->data;
}
