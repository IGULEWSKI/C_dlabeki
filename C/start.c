#include <stdio.h> // printf itd
#include<stdlib.h> //wskaźniki itd
#include<math.h> // potęgowanie pow() itd
int strtoint(char str[]){// funkcja konwertująca z str na int
        int fin = 0;
        for(int i=0;str[i]!='\0';i++){
            int lb = str[i] - '0';
            fin=fin*10+lb;
        }
        return fin;
}
int main(){
    int *ptr = (int*)malloc(sizeof(int));
    *ptr=10;
    int arr[5]={11,313,123,43,-1};
    int (*aptr)[5]=&arr;
    int licz = 0;
    for (int i=0; arr[i]!=-1;i++){ // tu dajesz jaki kolwiek warunek op
        printf("%p ",aptr[i]); //int ma 4 bajty więc adresy w pamięci chodzą co 4 więc garek często źle pokazuje na przykładach
        printf("%d\n",(*aptr)[i]);
    }
    while (licz<25){
        licz=licz+3;
        printf("%d\n",licz);
    }
    int licz2=5;
    do{
        printf("%d\n",licz2);
        licz2=licz2-1;
    } while(licz2>0);
    char napis[7]="napi0s"; // tablica znaków(char) specjalny przypadek ona zawsze skończy się /0
    int i=-1;
    while (napis[i]!='\0'){
        i++;
        printf("%c\n",napis[i]);
    }
    printf("%s\n","koniec");
    //zamiana znaku na int
    char a='2';
    int b1=a;
    printf("%d\n",b1); // print tu oddaje 50 czyli kod ascii np dla 0 jest to 48
    int b2=a-'0';
    printf("%d\n",b2); // tutaj odejmujemy od 2(50 w ascii)-0(48) w ten sposób convertujemy cha na inta tak samo jak można ponumerować alfabet
    printf("%d\t",strtoint("37031200"));
    printf("%d",5147500000);//przekroczyłem tu limit inta czyli 2**31-1
    return 0;
}