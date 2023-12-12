#include <stdio.h>
#include <stdbool.h>

int start(char pole[],int idx);
//int medzera(char pole[],int idx);
int stop(char pole[],int idx);

int main(int argc, char*argv[]){

FILE*fp = fopen(argv[1],"r");

char znak = fgetc(fp);
int size = 0;

while(znak != EOF){
size++;
znak = fgetc(fp);
}

fclose(fp);

char buffer[size];

FILE*fp2 = fopen(argv[1],"r");

znak = fgetc(fp2);
int k=0;
while(znak != EOF){
buffer[k] = znak;

if(start(buffer,k) == 1){
break;
}

znak = fgetc(fp2);
k++;
}

char pole[size];

    znak = fgetc(fp2);
    int l=0;

    while(znak != EOF){
    pole[l] = znak;

    if(stop(pole,l) == 1){
    break;
    }

    znak = fgetc(fp2);
    l++;
    }
    pole[l-5] = '\0';

    buffer[size] = '\0';

    fclose(fp2);

    char result[size];
    int idx = 0;

    bool druhe = false;
    bool first = true;

    for(int i=0;i<l-5;i++){
    if(pole[i] == ' '){
    if(druhe == true){
    druhe = false;
    }
    else{
    druhe = true;
    if(first == true){
    i++;
    first = false;
    }
    }
    }

    if(druhe == true){
    result[idx] = pole[i];
    idx++;
    }
    }
    result[idx] = '\0';

    FILE *fp3 = fopen(argv[2],"w");

    for(int h=0;h<idx;h++){
    fputc(result[h],fp3);
    }

    fclose(fp3);


    return 0;
    }

    /* int medzera(char pole[],int idx){
    while(pole[idx] != ' '){
    idx++;
    }
    return idx;
    } */

    int start(char pole[],int idx){
    if(pole[idx-5] != 'S' ){
    return 0;
    }
    if(pole[idx-4] != 'T'){
    return 0;
    }
    if(pole[idx-3] != 'A'){
    return 0;
    }
    if(pole[idx-2] != 'R'){
    return 0;
    }
    if(pole[idx-1] != 'T'){
    return 0;
    }
    if(pole[idx] != ' ' ){
    return 0;
    }
    return 1;
    }


    int stop(char pole[],int idx){
    if(pole[idx-4] != 'S'){
    return 0;
    }
    if(pole[idx-3] != 'T'){
    return 0;
    }
    if(pole[idx-2] != 'O'){
    return 0;
    }
    if(pole[idx-1] != 'P' ){
    return 0;
    }
    return 1;

    }
