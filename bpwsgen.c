/*
    Strong Password Generator
    Version 1.0b
    by DreamVB

    This file may be distributed under the terms of the GNU Public License.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define DEFAULT_PWS_LENGTH 8
#define DEFAULT_PWS_COUNT 1
#define MAX_PMASK 256

int main(int argc, char **argv)
{
    char *pLowcase = "abcdefghijklmnopqrstuvwxyz";
    char *pUppercase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char *pDigits = "0123456789";
    char *pSymbol = "!\"#$%&'()*+,-./:;<=>?@[]^_{|}~";
    char *pHex = "ABCDEF0123456789";
    char pMask[MAX_PMASK];

    int length = DEFAULT_PWS_LENGTH;
    int count = DEFAULT_PWS_COUNT;
    int x = 2;
    int i = 0;
    int j = 0;
    int rnd = 0;

    //Get random seed.
    srand((unsigned int)time(NULL));

    if(argc < 3){
        printf("-------------------------------------------------------------------------------\n");
        printf(" bpwsgen ::            Strong Password Generator\n");
        printf("-------------------------------------------------------------------------------\n");
        printf("\nSimple Usage :: bpwsgen length count  [OPTIONS]\n");
        printf("\n    Length ::  Length of the password to create.\n");
        printf("    Count  ::  Number of password to create.\n");
        printf("\n    The options\n\n");
        printf("       /U Include upper case characters A-Z\n");
        printf("       /L Include lower case characters a-z\n");
        printf("       /D Include digits 0-9\n");
        printf("       /S Include special characters\n");
        printf("       /H Include hexadecimal characters\n");
        return 0;
    }

    //Get password length
    length = atoi(argv[1]);
    count = atoi(argv[2]);

    //Check password length
    if(length < 4){
        printf("Password length must be at least 4 characters in length.\n");
        return 0;
    }

    //Check number of passwords.
    if(count < 1){
        printf("Password count must be at least 1\n");
        return 0;
    }

    strcpy(pMask,"");

    //Add default password mask if no options are selected.
    if(argc == 3){
        //Add default mask.
        strcat(pMask,pUppercase);
        strcat(pMask,pLowcase);
        strcat(pMask,pDigits);
    }
    //Create password mask
    while(x < argc){
        switch(argv[x][1]){
        case 'U':
        case 'u':
            strcat(pMask,pUppercase);
            break;
        case 'L':
        case 'l':
            strcat(pMask,pLowcase);
            break;
        case 'D':
        case 'd':
            strcat(pMask,pDigits);
            break;
        case 'S':
        case 's':
            strcat(pMask,pSymbol);
            break;
        case 'H':
        case 'h':
            strcat(pMask,pHex);
            break;
        }
        x++;
    }

    x = 0;
    //Create passwords.
    while(i < count){
        //Generate random password.
        for(j = 0; j < length;j++){
            //Get random number.
            rnd = rand() % strlen(pMask);
            //Get random char from pmask
            char c = pMask[rnd];
            //Print password.
            printf("%c",c);
        }
        printf("\n");
        i++;
    }

    //Clear pmask array.
    memset(pMask,0,sizeof(pMask));

    return 0;
}
