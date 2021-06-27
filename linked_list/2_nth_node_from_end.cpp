struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
int getNthFromLast(Node *head, int n)
{
    int size=0;
    if(head!=NULL){
        size+=1;
    }
    struct Node* temp=head;
    while(temp->next!=NULL){
        size+=1;
        temp=temp->next;
    }
    temp=head;
    if(n<=size){
    size=size-n+1;
    int t=1;
    while(t!=size){
        temp=temp->next;
        t++;
    }
    return temp->data;
    }
    else {return -1;}
}
