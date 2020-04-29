#include<stdio.h>
#include<stdlib.h>
#include<math.h>

long int e,n,d;

int prime(long int n)
{
    for(int i=2;i<n;i++)
    {
        if(n%i==0)
        {
            return 0;
        }
    }
    return 1;
}
int gcd(long int a,long int b)
{
    long int temp;
    while(b!=0)
    {
        temp = b;
        b = a%b;
        a = temp;
    }
    return a;
}
int encode(char ch)
{
    int temp;
    temp = ch;
    for(int i=1;i<e;i++)
    {
        temp = (temp*ch)%n;
    }
    return temp;
}
int decode(long int ch)
{
    int temp;
    temp = ch;
    for(int i=1;i<d;i++)
    {
        ch = (temp*ch)%n;
    }
    return ch;
}

int main()
{
    int i;
    //srand(time(0));
    long int p,q,phi,et[50];
    char text[50],dt[50];
    do
    {
        /* code */
        p = rand() % 30;
    } while (!prime(p));
    do
    {
        /* code */
        q = rand() % 30;
    } while (!prime(q));
    n = p*q;
    phi = (p-1)*(q-1);
    do
    {
        /* code */
        e = rand() % phi;
    } while (!gcd(e,phi));
    do
    {
        /* code */
        d = rand() % phi;
    } while ((e*d)%phi != 1);
    printf("Enter the text to be encoded:");
    gets(text);
    printf("\nEncoding");
    for(i=0;i<10;i++)
    {
        printf(".");
    }
    for(i=0;text[i]!='\0';i++)
    {
        et[i] = encode(text[i]);
    }
    et[i] = -999;
    printf("\nThe encoded text is:");
    for(i=0;et[i]!=-999;i++)
    {
        printf("%ld",et[i]);
    }
    printf("\nDecoding");
    for(i=0;i<10;i++)
    {
        printf(".");
    }
    for(i=0;et[i]!=-999;i++)
    {
        dt[i] = decode(et[i]);
    }
    dt[i] = '\0';
    printf("\nThe decoded text is:%s",dt);
    return 0;
}