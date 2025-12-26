#include<stdio.h>


int main(){
    FILE* fptr;
    fptr= fopen("plik.txt","r");
    if (fptr==NULL) {printf("%s\n","DAFUQ"); return 1;}
    char buffer[300000];
    while (fgets(buffer,sizeof(buffer),fptr)!=NULL) printf("%s(aha)",buffer);
}