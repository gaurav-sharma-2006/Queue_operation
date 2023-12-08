#include<stdio.h>
#include<stdlib.h>
struct queue
{
    int size;
    int f;
    int r;
    int *arr;
};
int isfull(struct queue *q){
    if((q->r+1)%q->size==q->f){
        return 1;
    }
    return 0;
}
int isempty(struct queue *q){
    if(q->f==q->r){
        return 1;
    }
    return 0;
}
int enqueue(struct queue *q,int value){
    if(isfull(q)){
        printf("Queue overflow\n");
    }
    else{
        q->r=(q->r+1)%q->size;
        q->arr[q->r]=value;
        printf("Enqued element is %d\n",value);
    }
}
int dequeue(struct queue *q){
    int a=-1;
    if(isempty(q)){
        printf("Queue underflow\n");
    }
    else{
        q->f=(q->f+1)%q->size;
        a=q->arr[q->f];
    }
    return a;
}
int traverse(struct queue *q){
    if(isempty(q)){
        printf("Queue underflow\n");
    }
    else{
        for(int i=q->f;i<=q->r;i++){
            printf("Position of %d is %d\n",i,q->arr[i]);
        }
    }
}
int main(){
    struct queue *q=(struct queue*)malloc(sizeof(struct queue));
    q->size=4;
    q->f=q->r=0;
    q->arr=(int*)malloc(q->size*sizeof(int));
    int user,b;
    while(1){
        printf("1.Enqueue\n");
        printf("2.Dequeue\n");
        printf("3.Traverse\n");
        printf("4.Quit\n");
        printf("Select an operation from the above option:-");
        scanf("%d",&user);

        printf("\n\n");
        switch(user){
            case 1:
            printf("Enter an element to be inserted:-");
            scanf("%d",&b);
            enqueue(q,b);
            printf("***Enqueue operation is successfull***\n");
            break;

            case 2:
            printf("Dequeued element is %d\n",dequeue(q));
            printf("***Dequeued operation is successfull***\n");
            break;

            case 3:
            traverse(q);
            break;

            default: printf("Invalid choice\n");
        }
    }
}