/*
3/18/2019
Riad Shash (Ray)
CSCI 420
Kattis problem => Sum Kind of Problem
https://open.kattis.com/problems/sumkindofproblem

1st input -> P (1 <= P <= 10000) # of datasets to follow
Next P lines is just K followed by N (1<=N<=10000)

S1 = Sum of the first N positive ints = ((n*n)+n) / 2
S2 = Sum of first N odd ints = (n*n)
S3 = Sm of first N even ints = (n*n)+n
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

#define SIZE 1000

char* sumKindOfProb(int P, int* N, bool test);
char* calcSums(int N, int K, bool test);
int calcS1(int N);
int calcS2(int N);
int calcS3(int N);
void test();

int main(int argc, char **argv)
{
    int P;
    char *temp = NULL;

    if (argc == 1)
    {
        //Get P value
        scanf("%i", &P);
        temp = sumKindOfProb(P, NULL, false);
    }
    else if (argc >= 2)
    {
        //Testing
        if (strcmp(argv[1], "test") == 0)
            test();
    }
    return 0;
}

char* calcSums(int N, int K, bool test){
    //For the result
    char result[SIZE]="\0";
    if (!test)
    {
        scanf("%i", &K);
        scanf("%i", &N);
        printf("%i ", K);
        printf("%i ", calcS1(N));
        printf("%i ", calcS2(N));
        printf("%i ", calcS3(N));
    }else{
        //For testing only
        char num[20] = "\0";
        snprintf(num, 10, "%i", K);
        strcat(result, num);
        snprintf(num, 10, "%i", calcS1(N));
        strcat(result, num);
        snprintf(num, 10, "%i", calcS2(N));
        strcat(result, num);
        snprintf(num, 10, "%i", calcS3(N));
        strcat(result, num);
    }

    if (test){
        char *dynStr = (char *)malloc(sizeof(result));
        //Write 0s to memory block (clear data)
        memset(dynStr,0,SIZE);

        /*Copies the values of num bytes from the location pointed to by
        source directly to the memory block pointed to by destination.
        strlen returns the length of the C string str.*/
        memcpy(dynStr, result, strlen(result));
        return dynStr;
    }else{
        return NULL;
    }
}

char* sumKindOfProb(int P, int* N, bool test)
{
    //For the result
    char result[SIZE] = "\0";
    char *temp = NULL;

    for (int i = 1; i <= P; i++)
    {
        if(!test){
            temp = calcSums(0,i,false);
        }else{
            temp = calcSums(N[i],i,true);
            //Copy memory blocks to stepResult variable
            strcat(result,temp);
            //Write 0s to memory block (clear data)
            memset(temp,0,SIZE);
            free(temp);
        }
    }
    if (test){
        char *dynStr = (char *)malloc(sizeof(result));
        //Write 0s to memory block (clear data)
        memset(dynStr,0,SIZE);

        /*Copies the values of num bytes from the location pointed to by
        source directly to the memory block pointed to by destination.
        strlen returns the length of the C string str.*/
        memcpy(dynStr, result, strlen(result));
        return dynStr;
    }else{
        return NULL;
    }
}

int calcS1(int N) { return ((N * N) + N) / 2; }
int calcS2(int N) { return N * N; }
int calcS3(int N) { return (N * N) + N; }

void test()
{
    char *temp = NULL;

    char testcase1[] = "1112255100110350150110020011003002";
    char testcase2[] = "1152530266121132";
    char testcase3[] = "13462691231016204152530";

    //Test case#1
    int numsCase1[4] = {-1,1,10,1001};
    temp = sumKindOfProb(3,numsCase1,true);
    assert(strcmp(temp,testcase1)==0);
    memset(temp,0,SIZE);
    free(temp);

    //Test case#2
    int numsCase2[3] = {-1,5,11};
    temp = sumKindOfProb(2,numsCase2,true);
    assert(strcmp(temp,testcase2)==0);
    memset(temp,0,SIZE);
    free(temp);

    //Test case#3
    int numsCase3[5] = {-1,2,3,4,5};
    temp = sumKindOfProb(4,numsCase3,true);
    assert(strcmp(temp,testcase3)==0);
    memset(temp,0,SIZE);
    free(temp);
}
