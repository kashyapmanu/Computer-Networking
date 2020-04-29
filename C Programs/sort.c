//C prorgam to implement the concept of frame shuffling and rearranging
#include<stdio.h>
#include<stdlib.h>

typedef struct Frame
{
    char message[20];
    int sequenceNumber;
}frame,temp;

frame f[20];
temp t;

void readFrame(int n);
void shuffleFrame(int n);
void sortFrame(int n);

int main()
{
    int numberOfFrames,i=0;
    printf("Enter the number of frames:");
    scanf("%d",&numberOfFrames);
    readFrame(numberOfFrames);
    printf("\nThe Frames before shuffling:\n");
    printf("Sequence Number -->\t");
    for(i=0;i<numberOfFrames;i++)
    {
        printf("%d\t",f[i].sequenceNumber);
    }
    printf("\nMessage         -->\t");
    for(i=0;i<numberOfFrames;i++)
    {
        printf("%s\t",f[i].message);
    }
    shuffleFrame(numberOfFrames);
    printf("\nThe Frames after shuffling:\n");
    printf("Sequence Number -->\t");
    for(i=0;i<numberOfFrames;i++)
    {
        printf("%d\t",f[i].sequenceNumber);
    }
    printf("\nMessage         -->\t");
    for(i=0;i<numberOfFrames;i++)
    {
        printf("%s\t",f[i].message);
    }
    sortFrame(numberOfFrames);
    printf("\nThe Frames after:\n");
    printf("Sequence Number -->\t");
    for(i=0;i<numberOfFrames;i++)
    {
        printf("%d\t",f[i].sequenceNumber);
    }
    printf("\nMessage         -->\t");
    for(i=0;i<numberOfFrames;i++)
    {
        printf("%s\t",f[i].message);
    }
    return(0);
}

void readFrame(int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        f[i].sequenceNumber = i;
    }
    for(int i=0;i<n;i++)
    {
        printf("Enter the conrents of the frame %d:",i+1);
        scanf("%s",&f[i].message);
    }
}

void shuffleFrame(int n)
{
    int i,r=0;
    srand(time(0));
    for(i=0;i<n;i++)
    {
        r = rand()%n;
        t = f[i];
        f[i] = f[r];
        f[r] = t;
    }
}

void sortFrame(int n)
{
    int i,j;
    int flag =0;
    for(i=0;i<n;i++)
    {
        flag = 0;
        for(j=0;j<n-i-1;j++)
        {
            if(f[j].sequenceNumber > f[j+1].sequenceNumber)
            {
                t = f[j];
                f[j] = f[j+1];
                f[j+1] = t;
                flag = 1;
            }
        }
        if(flag == 0)
        {
            break;
        }
    }
}
