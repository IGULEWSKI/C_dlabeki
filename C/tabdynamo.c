#include<stdio.h>
#include<stdlib.h>
typedef struct dyntab{
        int* val;
        int act;
        int N;
}dyntab;
dyntab* stworz_tab(){
    dyntab* tab=(dyntab*)malloc(sizeof(dyntab)); // alokujemy tylko dane na wskaźnik btw
    if (tab==NULL){// fail zalokowania pamięci
        return NULL;
    }
    tab->N=2;
    tab->val=(int*)malloc(sizeof(int)*2);
    if (tab->val==NULL){//fail zaolokowania pamięcia
        free(tab);
        return NULL;
    }
    tab->act=0;
    return tab;//zwracamy wskaźnik a nie strukture bo jest to szybsze system nie musi kopiować całej struktury a tylko jej adres
}
void sprzątanko(dyntab* tab){
    if (tab!=NULL){// możebyć tak że skończy się pamięć i malloc zwróci NULL
        free(tab->val);
        free(tab);
    }
}
dyntab* dodaj_do(dyntab* tab,int war){
    if (tab->act==tab->N){
        int* nval=(int*)malloc(sizeof(int)*((tab->N)*2));//podobno zamiast tego wszystkiego można użyć znacznie łatwiejszej funkcji realloc
        for(int i=0;i<(tab->N);i++){                     //która albo rozciągnie pamięć zallocowaną albo ją przekopiuje automatycznie do nowej większej
            nval[i]=(tab->val)[i];                      // wyglądało by to tak: nval=(int*)realloc(tab->val,sizeof(int)*((tab->N)*2); tab->N=(tab->N)*2; powinno się używać zmiennej pomocniczej bo jak nie to może ci wskaźnik zniknąc lipa
        }
        tab->N=(tab->N)*2;
        free(tab->val);
        tab->val=nval;

    }
    tab->val[tab->act]=war;
    tab->act++;
    return tab;
}
void wypisz_tab(dyntab* tab){
    for(int i=0;i<(tab->act);i++){
        printf("%d\n",(tab->val)[i]);
    }
}

int main(){
    dyntab* tabl = stworz_tab();
    dodaj_do(tabl,12);
    dodaj_do(tabl,79999);
    dodaj_do(tabl,12);
    dodaj_do(tabl,12);
    dodaj_do(tabl,12);
    wypisz_tab(tabl);
    sprzątanko(tabl);
}