#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#define MAX 20

char string1[MAX];
char string2[MAX];

int pi[MAX];

int KMP_prefix()
{
    pi[0] = 0;
    int j = 0;
    
    for (int i=1; i<strlen(string2); i++)
    {
        while (j>0 && string2[i] != string2[j])
        j = pi[j];
        if (string2[i] == string2[j])
        j++;
        pi[i] = j;
        
    }
}

int KMP_matcher()
{
    int j=0;
    for (int i=0; i<strlen(string1); i++)
    {
        while (j>0 && string1[i]!=string2[j])
        j = pi[j];
        if (string1[i]==string2[j])
        j++;
        if (j==strlen(string2))
        return i-strlen(string2)+1;
    }
    return -1;
}

int main()
{
    printf("Enter the main string: ");
    gets(string1);
    printf("Enter the subset: ");
    gets(string2);
    for(int i=0; i<strlen(string1); i++)
    string1[i] = tolower(string1[i]);
    for(int i=0; i<strlen(string2); i++)
    string2[i] = tolower(string2[i]);
    
    KMP_prefix();
    int a = KMP_matcher();
    printf("%d ", a);
    return 0;
}