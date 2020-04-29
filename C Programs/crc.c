#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int n,input[50];

struct Register
{
    int bit;
}r[16];

void computerCRC();
void checkError();

int main()
{
    for(int i=0;i<16;i++)
    {
        r[i].bit=0;
    }
    printf("Enter the number of bits in the input:");
    scanf("%d",&n);
    printf("\nEnter the data bits:\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&input[i]);
    }
    for(int i=n;i<(n+16);i++)
    {
        input[i]=0;
    }
    computerCRC();
    printf("\nData at the sender side:\n");
    for(int i=0;i<(n+16);i++)
    {
        printf("%d ",input[i]);
    }
    printf("\nSending data");
    for(int i=0;i<6;i++)
    {
        printf(".");
        sleep(1);
    }
    printf("\nData sent");
    for(int i=0;i<16;i++)
    {
        r[i].bit=0;
    }
    printf("\nEnter the data at the reciever side:\n");
    for(int i=0;i<(n+16);i++)
    {
        scanf("%d",&input[i]);
    }
    computerCRC();
    checkError();
    return 0;
}

void computerCRC()
{   
    int lmb;
    for(int i=0;i<(n+16);i++)
    {
        lmb=r[15].bit;
        for(int j=15;j>=0;j--)
        {
            r[j].bit = r[j-1].bit;
        }
        r[0].bit = input[i];
        if(lmb == 1)
        {
            r[12].bit = r[12].bit ^ lmb;
            r[5].bit = r[5].bit ^ lmb;
            r[0].bit = r[0].bit ^ lmb;
        }
    }
    printf("\nRegister content: ");
    {
        for(int i=15;i>=0;i--)
        {
            printf("%d ",r[i].bit);
        }
    }
    for(int i=n,j=15;j>=0;i++,j--)
    {
        input[i] = r[i].bit;
    }
}

void checkError()
{   
    int flag = 0;
    for(int i=n;i<(n+16);i++)
    {
        if(r[i].bit==1)
        {
            flag =1;
        }
    }
    if(flag == 1)
    {
        printf("\nThere is an error in the recieved data at positions:");
        for(int i=0;i<16;i++)
        {
            if(r[i].bit == 1)
            {
                printf("%d ",i);
            }
        }
    }
    else
    {
        printf("\nThere is no error\n");
    }
}

