#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char* usunn(char* nap){
    int len = strlen(nap);
    nap[len-1]='\0';
    return nap;
}
void wypisz_tab(char** tab){
    for(int i=0;tab[i]!=NULL;i++){
        printf("NR%d",i);
        printf(" %s\n",tab[i]);
    }
}
void sprzątanie(char** tab){
    int i=0;
    while(1){
        if (tab[i]==NULL) break;
        free(tab[i]);
        i++;
    }
}
int czy_ok(int a,int b,int i){
    if(a>=0 && b>=0 && a<=i-1 && b<=i-1) return 1;
    return 0;
}
int zad1(char** tab){
    int w=0;
    int len=strlen(tab[0]);
    int l=0;
    while(tab[w]!=NULL){
        int k=0;
        while(tab[w][k]!='\0'){
            if (tab[w][k]=='@'){
                int licz=0;
                if (czy_ok(w-1,k-1,len)==1 && tab[w-1][k-1]=='@') licz++;
                if (czy_ok(w-1,k,len)==1 && tab[w-1][k]=='@') licz++;
                if (czy_ok(w-1,k+1,len)==1 && tab[w-1][k+1]=='@') licz++;
                if (czy_ok(w,k-1,len)==1 && tab[w][k-1]=='@') licz++;
                if (czy_ok(w,k+1,len)==1 && tab[w][k+1]=='@') licz++;
                if (czy_ok(w+1,k-1,len)==1 && tab[w+1][k-1]=='@') licz++;
                if (czy_ok(w+1,k,len)==1 && tab[w+1][k]=='@') licz++;
                if (czy_ok(w+1,k+1,len)==1 && tab[w+1][k+1]=='@') licz++;
                if (licz<4) l++;
            }
            k++;
        }
        w++;
    }
    return l;
}
int zad2pom(char** tab){
    int w=0;
    int len=strlen(tab[0]);
    int l=0;
    while(tab[w]!=NULL){
        int k=0;
        while(tab[w][k]!='\0'){
            if (tab[w][k]=='@'){
                int licz=0;
                if (czy_ok(w-1,k-1,len)==1 && tab[w-1][k-1]=='@') licz++;
                if (czy_ok(w-1,k,len)==1 && tab[w-1][k]=='@') licz++;
                if (czy_ok(w-1,k+1,len)==1 && tab[w-1][k+1]=='@') licz++;
                if (czy_ok(w,k-1,len)==1 && tab[w][k-1]=='@') licz++;
                if (czy_ok(w,k+1,len)==1 && tab[w][k+1]=='@') licz++;
                if (czy_ok(w+1,k-1,len)==1 && tab[w+1][k-1]=='@') licz++;
                if (czy_ok(w+1,k,len)==1 && tab[w+1][k]=='@') licz++;
                if (czy_ok(w+1,k+1,len)==1 && tab[w+1][k+1]=='@') licz++;
                if (licz<4) {
                    l++;
                    tab[w][k]='.';
                }
            }
            k++;
        }
        w++;
    }
    return l;
}
int zad2(char** tab){
    int fin=0;
    int dod=zad2pom(tab);
    while(dod>0){
        fin+=dod;
        dod=zad2pom(tab);
    }
    return fin;
}
int main(){
    FILE* plik;
    plik=fopen("input.txt","r");
    if(plik==NULL) return 1;
    char buffer[150];
    int i=0;
    char* tab[150];
    while(fgets(buffer,sizeof(buffer),plik)!=NULL){
        char* napis = usunn(buffer);
        char* nap = (char*)malloc(strlen(napis)+1);
        strcpy(nap,napis);
        tab[i]=nap;
        i++;
    }
    tab[i]=NULL;
    printf("%d\n",zad2(tab));
    sprzątanie(tab);
    return 0;
}