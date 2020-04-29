#include <stdio.h>
#include <stdlib.h>

#define bucketSize 250
#define outRate 25

struct Packet
{
    int arTime;
    int weight;
}packet[20];

void readPackets(int n);
void leakyBucket();

int main()
{   int n;
    printf("Enter the number of packets:");
    scanf("%d",&n);
    readPackets(n);
    leakyBucket(n);
    return 0;
}

void readPackets(int n)
{
    for(int i=0;i<n;i++)
    {
        printf("\nEnter the arrival time of packet %d:",i);
        scanf("%d",&packet[i].arTime);
        printf("Enter the weight of the packet %d:",i);
        scanf("%d",&packet[i].weight);
    }
}

void leakyBucket(int n)
{
    int filled=0,free=bucketSize,i=0,j=0;
    for(i=1;i<30;i++)
    {
        if(packet[j].arTime == i)
        {
            if(packet[j].weight<=free)
            {
                filled = filled + packet[j].weight;
                free = free - filled;
                printf("\nTime:%d | Inserted Frame %d | Free space:%d",i,j,free);
                j+=1;
            }
            else
            {
                printf("\nTime:%d | Discarded Frame %d | Free space:%d",i,j,free);
                j+=1;
            }
        }
        if(i%5==0)
        {
            if(filled>=outRate)
            {
                filled -= outRate;
                free += outRate;
                printf("\nTime:%d | Out:%d | Free:%d",i,outRate,free);
            }
            else if(filled>0)
            {
                printf("\nTime:%d | Out:%d | Free:%d",i,filled,bucketSize);
                filled = 0;
                free = bucketSize;
                
            }
        }
    }
    while(free != bucketSize)
    {
        if(filled >= outRate)
        {
            free += outRate;
            filled -= outRate;
            printf("\nTime:%d | Out:%d | Free:%d",i+5,outRate,free);
        }
        else
        {
            printf("\nTime:%d | Out:%d | Free:%d",i+5,filled,bucketSize);
                filled = 0;
                free = bucketSize;
        }
    }
    printf("\nEmpty");
}
