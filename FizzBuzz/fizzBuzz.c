/*
3/18/2019
Riad Shash (Ray)
CSCI 420
Kattis problem => FizzBuzz
https://open.kattis.com/problems/fizzbuzz

Prints the integers from 1 to N, replacing any of them divisible by X with Fizz or,
if they are divisible by Y, with Buzz. If the number is divisible by both X and Y,
prints FizzBuzz instead.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

#define BUFFER 1000

char* FizzBuzz(int X, int Y, int N, bool testing);
bool QIsDiv(int X, int cur);
void test();

int main(int argc, char **argv){
    int X,Y,N;
    char *temp = NULL;

    if(argc == 1){
        //Read input, store in X,Y,N
        while (scanf("%i %i %i", &X, &Y, &N)==3) {
            temp = FizzBuzz(X,Y,N, false);
        }
    }else if(argc >=2){
        //Test
        if(strcmp(argv[1],"test")==0)
            test();
    }
   return 0;
}

char* FizzBuzz(int X, int Y, int N, bool testing){
    char strFizz[] = "Fizz";
    char strBuzz[] = "Buzz";

    //For the result
    char result[BUFFER] = "\0";

    //Flags
    bool isFizz= false;
    bool isBuzz = false;

    //Go from #s 1-N
    for(int i = 1; i <= N; i++){
        //Reset flags
        isFizz= false;
        isBuzz = false;

        isFizz = QIsDiv(X, i);
        isBuzz = QIsDiv(Y, i);

        if(isFizz){
            if (!testing)
                printf("%s",strFizz);
            else
               strcat(result,strFizz);
        }

        if(isBuzz){
            if(!testing)
                printf("%s",strBuzz);
            else
                strcat(result,strBuzz);
        }

        if(!isFizz && !isBuzz){
            if (!testing) {printf("%i",i);}
            else{
                //Integer can be <= 10000
                char num[10];
                snprintf(num, 10, "%i", i);
                strcat(result,num);
            }
        }
        if(!testing){printf("\n");}
    }

    if(testing){
        char* dynStr = (char*)malloc(sizeof(result));
        /*Copies the values of num bytes from the location pointed to by
        source directly to the memory block pointed to by destination.
        strlen returns the length of the C string str.*/
        memcpy(dynStr,result,strlen(result));
        return dynStr;
    }else{
        return NULL;
    }

}

//Is cur divisible by X
bool QIsDiv(int X, int cur){
    if(cur % X == 0)
        return true;
    else
        return false;
}

//Is it div by X and Y?
bool QIsFizzBuzz(bool X, bool Y){
    if(X && Y)
        return true;
    else
        return false;
}

void test(){
    char *temp = NULL;

    char testcase1[] = "1FizzBuzzFizz5FizzBuzz7";
    char testcase2[] = "1Fizz3FizzBuzz5Fizz7";
    char testcase3[] = "12Fizz4BuzzFizz7";

    //Test case#1
    temp = FizzBuzz(2,3,7,true);
    assert(strcmp(temp,testcase1)==0);
    memset(temp,0,BUFFER);
    free(temp);

    //Test case#2
    temp = FizzBuzz(2,4,7,true);
    assert(strcmp (temp,testcase2)==0);
    memset(temp,0,BUFFER);
    free(temp);

    //Test case#2
    temp = FizzBuzz(3,5,7,true);
    assert(strcmp (temp,testcase3)==0);
    memset(temp,0,BUFFER);
    free(temp);

    printf("All tests passed!\n");
}

