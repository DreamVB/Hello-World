/*
    Strong Password Generator
    by DreamVB
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define DEFAULT_PWS_LENGTH 8
#define DEFAULT_PWS_COUNT 1
#define MAX_MASK_LEN 256
#define MAX_PWS_LEN 256
#define MAX_FLAGS 10
#define MAX_PASSWORDS 4000

#define TRUE 1
#define FALSE 0

//Password mask types.
char *pLowcase = "abcdefghijklmnopqrstuvwxyz";
char *pUppercase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char *pDigits = "0123456789";
char *pSymbol = "!\"#$%&'()*+,-./:;<=>?@[]^_{|}~";
char *pHex = "ABCDEF0123456789";

//Holds the option types of passwords to generate.
int i_flags = 0;
char flags[MAX_FLAGS];
//Holds the generated password.
char pws[MAX_PWS_LEN];

int flag_exsits(char c){
    //Look in the flags array if a char is found
    int x = 0;
    int Found = FALSE;

    while(x < i_flags){
        //Check if c is in flags
        if(c == flags[x]){
            //Yes it is found
            Found = TRUE;
            //Here we exit the loop
            break;
        }
        //INC counter
        x++;
    }
    return Found;
}

int is_vowel(char c){
    char ch = toupper(c);

    if(ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U'){
        return 1;
    }else{
        return 0;
    }
}

int main(int argc, char **argv)
{
    char flag = '\0';
    char pTempMask[MAX_MASK_LEN];
    char pMask[MAX_MASK_LEN];

    int pMaskLen = 0;
    int length = DEFAULT_PWS_LENGTH;
    int count = DEFAULT_PWS_COUNT;
    int x = 2;
    int i = 0;
    int j = 0;
    int rnd = 0;
    int rm_vowels = FALSE;

    //Get random seed.
    srand((unsigned int)time(NULL));

    if(argc < 3){
        printf("-------------------------------------------------------------------------------\n");
        printf("bpwsgen ::       Strong Password Generator Version 1.3\n");
        printf("-------------------------------------------------------------------------------\n");
        printf("\nSimple Usage :: bpwsgen length count  /[OPTIONS]\n");
        printf("\n    Length ::  Length of the password to create.\n");
        printf("    Count  ::  Number of passwords to create.\n");
        printf("\n    Options ::\n\n");
        printf("       /U Include upper case characters A-Z\n");
        printf("       /L Include lower case characters a-z\n");
        printf("       /D Include digits 0-9\n");
        printf("       /S Include special characters.\n");
        printf("       /H Include hexadecimal characters.\n");
        printf("       /V Do not include vowels.\n");
        return 0;
    }

    //Get password length
    length = atoi(argv[1]);
    count = atoi(argv[2]);

    //Check password length
    if(length < 4){
        length = 4;
    }
    //Max length of password is 255
    if(length > MAX_PWS_LEN){
        length = MAX_PWS_LEN;
    }

    //Check number of passwords.
    if(count < 1){
        count = 1;
    }
    //Max passwords
    if(count > MAX_PASSWORDS){
        count = MAX_PASSWORDS;
    }

    strcpy(pTempMask,"");

    //Add default password mask if no options are selected.
    if(argc == 3){
        //Add default mask.
        strcat(pTempMask,pUppercase);
        strcat(pTempMask,pLowcase);
        strcat(pTempMask,pDigits);
    }

    //Create password mask
    while(x < argc){
        //Get char from argv
        flag = toupper(argv[x][1]);
        //Check if flag is already in the flags array
        if(flag_exsits(flag) == FALSE && (isalpha(flag))){
            //Store flag
            flags[i_flags] = flag;
            //INC flag counter
            i_flags++;
        }
        //INC counter
        x++;
    }

    //Reset counter
    i = 0;

    //Process flags
    while(i < i_flags){
        //Get flag
        flag = flags[i];
        //Process flag
        switch(flag){
        case 'U':
            strcat(pTempMask,pUppercase);
            break;
        case 'L':
            strcat(pTempMask,pLowcase);
            break;
        case 'D':
            strcat(pTempMask,pDigits);
            break;
        case 'S':
            strcat(pTempMask,pSymbol);
            break;
        case 'H':
            strcat(pTempMask,pHex);
            break;
        case 'V':
            rm_vowels = TRUE;
            break;
        }
        i++;
    }

    i = 0;

    while(i < strlen(pTempMask)){
        char ch = pTempMask[i];
        //See if we need to remove vowels
        if(rm_vowels == TRUE){
            if(is_vowel(ch) == FALSE){
                pMask[pMaskLen] = ch;
                pMaskLen++;
            }
        }
        else{
            //Just copy ch to pMask
            pMask[pMaskLen] = ch;
            //INC password length
            pMaskLen++;
        }
        i++;
    }
    //Add ending for password mask.
    pMask[pMaskLen] = '\0';

    x = 0;
    i = 0;
    //Create passwords.
    while(i < count){
        //Generate random password.
        for(j = 0; j < length;j++){
            //Get random number.
            rnd = rand() % strlen(pMask);
            //Get random char from pTempMask
            char c = pMask[rnd];
            //Build password
            pws[j] = c;
        }
        //Add ending for password.
        pws[j] = '\0';
        //Print random password.
        printf("%s\n",pws);
        //INC counter
        i++;
    }
    //Clear arrays.
    memset(pTempMask,0,sizeof(pTempMask));
    memset(pMask,0,sizeof(pMask));
    memset(flags,0,sizeof(flags));
    memset(pws,0,sizeof(pws));
    return 0;
}
