#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char* setCode(char const* input)
{
    int textFullSize = strlen(input)+1;
    char* result = malloc(sizeof(char) * (textFullSize));
    int letterCounter = 1;
    int resultLetterCounter = 0;

    for(int i = 0; i < textFullSize; i++){
       if(input[i] != input[i+1] && letterCounter == 0){
           result[resultLetterCounter] = input[i];
           resultLetterCounter+=1;
       }
       if(input[i] != input[i+1] && letterCounter > 0){
           result[resultLetterCounter] = input[i];
           resultLetterCounter+=1;
           if(letterCounter != 1){
                result[resultLetterCounter] = letterCounter + '0';
                resultLetterCounter+=1;
           }
           letterCounter = 1;
       } 
       if(input[i] == input[i+1]){
           letterCounter+=1;
       }
    }
    return result;
}

char* readCode(char const* input)
{
    int textFullSize = strlen(input)+1;
    char* result = malloc(sizeof(char) * (textFullSize));
    int counterOfSameLetters = 0;
    int resultCounter = 0;

    for(int i = 0; i < textFullSize; i++){
       if(input[i] >= '0' && input[i] <= '9'){
           counterOfSameLetters = input[i] - 48;
           for(int j = 1; j < counterOfSameLetters; j++){
               result[resultCounter] = input[i-1];
               resultCounter++;
           }
       } else {
           result[resultCounter] = input[i];
           resultCounter++;
       }
    }

    return result;
}


int main(){
    char const code[] = "SUPPEEEER MANN";
    char const code2[] = "WOWWOWWELCOMEEEEE!";

    char* firstCode = setCode(code);
    char* secondCode = setCode(code2);
    
    printf("%s and %d\n", firstCode, strlen(firstCode));
    printf("%s and %d\n", secondCode, strlen(secondCode));

    char const code3[] = "SUP2E4R MAN2";
    char const code4[] = "WOW2OW2ELCOME5!";

    char* thirdCode = setCode(code3);
    char* fourthCode = setCode(code4);

    printf("%s and %d\n", thirdCode, strlen(thirdCode));
    printf("%s and %d\n", fourthCode, strlen(fourthCode));

    free(firstCode);
    free(secondCode);
    free(thirdCode);
    free(fourthCode);

    return 0;    
}
