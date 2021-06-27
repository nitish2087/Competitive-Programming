struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

Node* rotate(Node* head, int k) {
    int size=0;
    if(head!=NULL){
        size+=1;
    }
    struct Node* temp1=head;
    struct Node* temp2=head;
    while(temp1->next!=NULL){
        size+=1;
        temp1=temp1->next;
    }
    if(size==1 || size==k){return head;}
    temp1=head;
    if(k<size){
    while(k>1){
        temp1=temp1->next;
        k--;
    }
    head=temp1->next;
    temp1->next=NULL;
    temp1=head;
    while(temp1->next!=NULL){
        temp1=temp1->next;
    }
    temp1->next=temp2;
    }
    return head;
}
