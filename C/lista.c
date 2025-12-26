#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int val;
    struct node* next;
}node;
typedef struct list{
    node* first;
    node* last;
}list;
list* dodaj(list* lista,int vala){
    if (lista==NULL) {
        lista=(list*)malloc(sizeof(list));
        lista->first=(node*)malloc(sizeof(node));
        lista->first->val=vala;
        lista->first->next=NULL;
        lista->last=lista->first;
        return lista;
    }
    else{
        node* a=(node*)malloc(sizeof(node));
        a->val=vala;
        a->next=NULL;
        lista->last->next=a;
        lista->last=a;
        return lista;
    }
}
void wypisz(list* lista){
    node* a = lista->first;
    while (a!=NULL){
        printf("%d\n",a->val);
        a=a->next;
    }
}
list* usun(list* lista){
    if(lista==NULL){
        printf("%s\n","Pusta Lista");
        return NULL;
    }
    node* blast;
    blast=lista->first;
    if (lista->first==lista->last){
        free(lista->first);
        free(lista);
        return NULL; // gdzie NULL to dla mnie pusta lista tak szczerze
    }
    while (blast->next!=lista->last){
        blast=blast->next;
    }
    free(lista->last);
    blast->next=NULL;
    lista->last=blast;
    return lista;
}
int main(){
    list* lista;
    lista = NULL;
    lista = dodaj(lista,12);
    lista = dodaj(lista,15);
    lista = dodaj(lista,28);
    lista = dodaj(lista,17);
    printf("%p\n",lista->first);
    lista=usun(lista);
    wypisz(lista);
    return 0;
}