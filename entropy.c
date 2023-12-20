#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>


void findEntropy (int nOccur[],int size,char str[]){
    float fEntropy = 0;
    float fSmall = 0;
    float probability = 0;

    for( int i = 0 ; i < size ; i++ ){
       if ( nOccur[i] != 0 ){
            probability = (float)nOccur[i] / (strlen(str)-1);
            fSmall = (float) probability * (log(1.0/probability)/log(2));
            fEntropy += fSmall;
        }
    }
    printf("%f\n",fEntropy);    
}



int main(){

    FILE *fp;
    char str[10000];
    int nOccur[256] = {0};
    float temp = 0;


    //simple steps to read a text by line from a file and assigning into char array
    fp = fopen("tonton.txt","r");
    if ( fp == NULL ){
        printf("Couldn't find/open the file\n");
    }
    fgets(str,10000,fp);
    fclose(fp);
    
    //Assigning occurences into the array corresponding to 256 ASCII values of the ASCII table
    for ( int i = 0 ; i < strlen(str)-1 ; i++ ){
        nOccur[str[i]]++;
    }

    findEntropy(nOccur,256,str);
    
    return 0;
}



