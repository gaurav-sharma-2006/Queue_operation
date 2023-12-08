#include<stdio.h>
#include<stdlib.h>
struct queue{
    int size;
    int f,r;
    int *arr;
};
int isfull(struct queue *q){
    if(q->r==q->size-1){
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
        q->r++;
        q->arr[q->r]=value;
    }
}
int dequeue(struct queue *q){
    int a=-1;
    if(isempty(q)){
        printf("Queue underflow\n");
    }
    else{
        q->f++;
        a=q->arr[q->f];
    }
    return a;
}
int traverse(struct queue *q){
    if(isempty(q)){
        printf("Queue underflow");
    }
    else{
        for(int i=q->f+1;i<=q->r;i++){
            printf("Position of element is %d is %d\n",i,q->arr[i]);
        }
    }
}
int main(){
    struct queue *q=(struct queue*)malloc(sizeof(struct queue));
    q->size=10;
    q->f=q->r=-1;
    q->arr=(int*)malloc(q->size*sizeof(struct queue));
    int user,x;
    while(1){
        printf("1.Enqueue\n");
        printf("2.Dequeue\n");
        printf("3.Traverse\n");
        printf("4.Quit\n");
        printf("Select an option from the above option:-");
        scanf("%d",&user);
        if(user==1){
            printf("\n");
            int value;
            printf("Enter value to be inserted:-\n");
            scanf("%d",&value);
            enqueue(q,value);
            printf("********Enqueue operation is successfull********\n");
        }
        else if(user==2){
            printf("\n");
            x=dequeue(q);
            printf("Dequed element is %d",x);
            printf("********Dequeue operation is successfull********\n");
        }
        else if(user==3){
            printf("\n");
            traverse(q);
            printf("******traverse operation is successfull******\n");
        }
        else if(user==4){
            break;
        }
        else{
            printf("Enter valid choice\n");
        }
    }
}