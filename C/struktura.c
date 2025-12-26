#include<stdio.h>
struct node{
    int val;
    struct node* next;
};

int main(){
    struct node pier;
    struct node drug;
    pier.next=&drug;
    drug.next=NULL;
    drug.val=15;
    pier.val=12;
    int trzy=(*pier.next).val;

    printf("%d",trzy);
}
