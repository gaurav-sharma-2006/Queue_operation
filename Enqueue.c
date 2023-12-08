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
//inserting an element into a queue
int enqueue(struct queue *q,int val){
    if(isfull(q)){
        printf("Queue Overflow\n");
    }
    else{
        q->r++;
        q->arr[q->r]=val;
    }
}
//deleteing an element from a queue
int dequeue(struct queue *q){
    int a=-1;
    if(isempty(q)){
        printf("Queue Underflow\n");
    }
    else{
        q->f++;
        a=q->arr[q->f];
    }
    return a;
}
void traverse(struct queue *q){
    if(isempty(q)){
        printf("Queue is empty");
    }
    else{
        for(int i=q->f+1;i<=q->r;i++){
            printf("position of %d is %d\n",i,q->arr[i]);
        }
    }
}
int main(){
    struct queue *q=(struct queue*)malloc(sizeof(struct queue));
    q->size=80;
    q->f=q->r=-1;
    q->arr=(int*)malloc(q->size*sizeof(int));

    printf("inserted item into a queue %d\n",enqueue(q,45));
    printf("inserted item into a queue %d\n",enqueue(q,46));
    printf("inserted item into a queue %d\n",enqueue(q,47));
    printf("inserted item into a queue %d\n",enqueue(q,48));

    printf("\n\n");
    traverse(q);
    printf("\n\n");

    printf("Deleted element is %d\n",dequeue(q));
}