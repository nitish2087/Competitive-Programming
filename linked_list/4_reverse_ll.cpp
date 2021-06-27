struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

Node* reverseList(Node *head)
{
  if(head!=NULL){
      struct Node* prev=head;
      struct Node* curr=prev->next;
      struct Node* agla;
      prev->next=NULL;
      while(curr!=NULL){
          agla=curr->next;
          curr->next=prev;
          prev=curr;
          curr=agla;
      }
      head=prev;
  }
  return head;
}
