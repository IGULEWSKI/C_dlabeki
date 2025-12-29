#include<stdio.h>
#include<string.h>
#include<stdlib.h>



typedef struct zakres{
    long long pocz;//lepiej dane w tym wypadku dać bo long long to 8bajtów podczas gdy wskaźnik do long long to 8+8 bajtów ogólnie w przypadku staticów to jest lepsze
    long long kon;
}zakres;



long long strnalong(char* nap){
    long long sum=0;
    for(int i=0;nap[i]!='\0';i++){
        int liczba=nap[i]-'0';
        sum=sum*10+liczba;   
    }
    return sum;
}




void usunn(char* nap){
    int len=strlen(nap);
    nap[len-1]='\0';
}



int spr1(char** zakresy,long long liczba){//pamiętaj aby do cholery nie zwracać lokalnej tablicy do maina bo zwracając tablicę zwracasz wskaźnik na pierwszy element którego w mainie już nie ma bo tablica jest na stosie funkcji
    //zakres tab[500];
    for(int i=0;zakresy[i]!=NULL;i++){
        int guard=0;
        char a[50];
        char b[50];
        int j1=0;
        int j2=0;
        int j=0;
        while(zakresy[i][j]!='\0'){
            if (zakresy[i][j]=='-'){
                guard=1;
                a[j1]='\0';
                j++;
                continue;
            }
            if(guard==0) {
                a[j1]=zakresy[i][j];
                j1++;
            }
            else {
                b[j2]=zakresy[i][j];
                j2++;
            }
            j++;
        }
        b[j2]='\0';
        long long vala=strnalong(a);
        long long valb=strnalong(b);
        if(liczba>=vala && liczba<=valb) return 1;
        // zakres zak;
        // zak.pocz=strnalong(a);
        // zak.kon=strnalong(b);
        // tab[i]=zak;
    }
    // return tab;
    return 0;
}



int zad1(char** tab){
    int l=0;
    int i=0;
    char** zakresy=malloc(sizeof(char*)*500);
    int guard=0;
    while (tab[i]!=NULL){
        if(tab[i][0]!='\0' && guard==0){
            zakresy[i]=tab[i];
        }
        else if(guard==1) l+=spr1(zakresy,strnalong(tab[i]));
        else{
            zakresy[i]=NULL;
            guard=1;
        }
        i++;
    }
    free(zakresy);
    return l;
}


long long spr2(char** zakresy){//pamiętaj aby do cholery nie zwracać lokalnej tablicy do maina bo zwracając tablicę zwracasz wskaźnik na pierwszy element którego w mainie już nie ma bo tablica jest na stosie funkcji
    zakres* tab[500]={NULL};
    int licz=0;
    for(int i=0;zakresy[i]!=NULL;i++){
        int guard=0;
        char a[50];
        char b[50];
        int j1=0;
        int j2=0;
        int j=0;
        while(zakresy[i][j]!='\0'){
            if (zakresy[i][j]=='-'){
                guard=1;
                a[j1]='\0';
                j++;
                continue;
            }
            if(guard==0) {
                a[j1]=zakresy[i][j];
                j1++;
            }
            else {
                b[j2]=zakresy[i][j];
                j2++;
            }
            j++;
        }
        b[j2]='\0';
        long long vala=strnalong(a);
        long long valb=strnalong(b);
        int guard2=1;
        for(int k=0;tab[k]!=NULL;k++){
            if (vala <= tab[k]->pocz && valb >= tab[k]->kon) {
                tab[k]->pocz=-1;
                tab[k]->kon=-1;
                continue;
            }
            if (vala >= tab[k]->pocz && valb <= tab[k]->kon){
                guard2=0; 
                break;
            }
            if (vala>=tab[k]->pocz && vala<=tab[k]->kon){
                vala=tab[k]->kon+1;
            }
            if (valb>=tab[k]->pocz && valb<=tab[k]->kon){
                valb=tab[k]->pocz-1;
            }
            if(vala>valb) {guard2=0; break;}
        }
        if(guard2==1){
            zakres* zak=malloc(sizeof(zakres));
            zak->pocz=vala;
            zak->kon=valb;
            tab[licz]=zak;
            licz++;
        }
    }
    long long suma=0;
    for(int i=0;tab[i]!=NULL;i++){
        printf("%lld - ",tab[i]->pocz);
        printf("%lld\n",tab[i]->kon);
        if(tab[i]->pocz!=-1) suma+= tab[i]->kon-tab[i]->pocz + 1;
    }
    return suma;
}


int zad2(char** tab){
    int i=0;
    char** zakresy=malloc(sizeof(char*)*500);
    while (tab[i]!=NULL && tab[i][0]!='\0'){
        zakresy[i]=tab[i];
        i++;
    }
    zakresy[i]=NULL;
    printf("%lld\n",spr2(zakresy));
    free(zakresy);
}



int main(){//nie no w pythonie to byłby taki banał
    char** tab=malloc(1500*sizeof(char*));
    FILE *plik = fopen("przyklad5.txt","r");
    if(plik==NULL) return 1;
    char buffer[50];
    int i=0;
    while(fgets(buffer,sizeof(buffer),plik)!=NULL){
        usunn(buffer);
        char* nap = malloc((strlen(buffer)+1));
        strcpy(nap,buffer);
        tab[i]=nap;
        i++;
        //printf("%s\n",nap);
    }//to tab jest w sumie nie potrzebne ale chiciałem se poćwiczyć
    tab[i]=NULL;
    // printf("%d",zad1(tab));
    zad2(tab);

    return 0;
}