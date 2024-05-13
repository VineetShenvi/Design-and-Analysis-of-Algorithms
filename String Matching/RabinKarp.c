#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#define d 10
#define m 13
#define MAX 20

char string1[MAX];
char string2[MAX];

int hash(char string[], int k)
{
    int p =0;
    
    for (int i=k; i<strlen(string2)+k; i++)
    {
        p = (d*p + string[i]) %m;
    }
    return p;
}

int Matcher()
{
    int p = hash(string2, 0);
    for (int i=0;i<strlen(string1)-strlen(string2)+1; i++)
    {
        int t = hash(string1, i);
        if (t==p)
        {
            int j;
            int ctr=0;
            for (j=0; j<strlen(string2); j++)
            {
                if (string1[i+j]==string2[j])
                ctr++;
            }
            if (ctr == strlen(string2))
            return i;
        }
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
    
    int a = Matcher();
    printf("%d ", a);
    return 0;
}