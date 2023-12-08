#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *r=NULL;
struct node *f=NULL;

void linkedListTraversal(struct node *ptr)
{
    int i=0;
    printf("Printing the elements of this linked list\n");
    while (ptr != NULL)
    {
        printf("position of %d is %d\n", i,ptr->data);
        ptr = ptr->next;
        i++;
    }
}
void enqueue(int val)
{
    struct node *n = (struct node *) malloc(sizeof(struct node));
    if(n==NULL){
        printf("Queue is Full");
    }
    else{
        n->data = val;
        n->next = NULL;
        if(f==NULL){
            f=r=n;
        }
        else{
            r->next = n;
            r=n;
        }
    }
}
int dequeue()
{
    int val = -1;
    struct node *ptr = f;
    if(f==NULL){
        printf("Queue is Empty\n");
    }
    else{
        f = f->next;
        val = ptr->data;
        free(ptr);
    }
    return val;
}
int main(){
    int user,x,b;
    while(1){
        printf("1.Enqueue\n");
        printf("2.Dequeue\n");
        printf("3.Traverse\n");
        printf("4.Quit\n");
        printf("Select an operation from the above option:-");
        scanf("%d",&user);

        if(user==1){
            printf("Enter an element to be inserted:-");
            scanf("%d",&b);
            enqueue(b);
            printf("***Enqueue operation is successfull***\n");
        }
        else if(user==2){
            x=dequeue();
            printf("Dequeued element is %d\n",x);
            printf("***Dequeued operation is successfull***\n");
        }
        else if(user==3){
            linkedListTraversal(f);
        }
        else if(user==4){
            break;
        }
        else{
            printf("Invalid choice");
        }
    }
}