/*Write by TheRipper
email: metasploit.ruby@gmail.com
ver 1.0*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define TAILLE 16

void remplissage(int tb[], int taille);
void calcul(int *pt, int taille);
int resultat (int tb[], int taille, int chiffr);

/*this program work trought Luhn Algorithm*/

/*-------------------------------------------------*/

int main(){

    int tab[TAILLE] = {4}, nbre = 0;
    /*char validity [] = "the credit card is valid";*/
    /*char invalidity [] = "the credit card is not valid";*/

    remplissage(tab, TAILLE);

    /*printf("------AVANT------\n");*/

    for (int i = 0; i<TAILLE; i++){
        printf("%d",tab[i]);
    }
    printf("\n");

    /*printf("------Apres------\n");*/

    calcul(tab, TAILLE);

    for (int i = 0; i<TAILLE; i++){
        /*printf("%d",tab[i]);*/
    }
    printf("\n");


    /*printf("------Resultat definitif------\n");*/

    resultat(tab, TAILLE, nbre);


    return 0;
}

/*------------------------------------------------------------------*/

void remplissage(int tb[], int taille){
    /* function generate the random numbers and fills the array from
    index[1] until index[15]*/
    srand(time(NULL));
    for (int i=1; i<taille;i++)
        tb[i] = rand()%10;
}

/*------------------------------------------------------------------*/

void calcul(int *pt, int taille){

    /*This function multiplies by 2 each odd index and verifies if this index
    is greater than or equal to 10,if it is greater than 10 it subtracts 9*/

    int cal1, cal2, cal3;

    pt[0] *=2;

    if ((pt[2] *=2) >= 10)
        pt[2] -=9;
    if ((pt[4] *=2) >= 10)
        pt[4] -=9;
    if ((pt[6] *=2) >= 10)
        pt[6] -=9;
    if ((pt[8] *=2) >= 10)
        pt[8] -=9;
    if ((pt[10] *=2) >= 10)
        pt[10] -=9;
    if ((pt[12] *=2) >= 10)
        pt[12] -=9;
    if ((pt[14] *=2) >= 10)
        pt[14] -=9;
}

/*---------------------------------------------------*/

int resultat (int tb[], int taille, int cal){

    /*this function added every digit of array, if */

    int cal1, cal2;

    cal1 = tb[0]+tb[1]+tb[2]+tb[3]+tb[4]+tb[5]+tb[6]+tb[7];
    cal2 = tb[8]+tb[9]+tb[10]+tb[11]+tb[12]+tb[13]+tb[14]+tb[15];
    cal = cal1 + cal2;
    /*printf("la somme est :%d\n", cal);*/

    if (cal % 10 != 0)
    {
        printf("The creditcard is not valid\n");
    }

    else
    {
        printf("The creditcard is valid\n");
    }

    return cal;
}