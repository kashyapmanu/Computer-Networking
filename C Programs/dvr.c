#include<stdio.h>
#include<stdlib.h>
#define INFINITY 999

struct Node
{
    int cost;
    int via;
}c[10][10];

int numberOfNodes;

void displayRoutingTable();
void createRoutingTable();
void findPath(int source,int destination);

int main()
{
    printf("Enter the number of nodes:");
    scanf("%d",&numberOfNodes);
    printf("\nEnter the initail routing table(999 if no direct path).\n");
    for(int i=1;i<=numberOfNodes;i++)
    {
        for(int j=1;j<=numberOfNodes;j++)
        {
            scanf("%d",&c[i][j].cost);
            c[i][j].via = INFINITY;
        }
    }
    printf("\nThe initail routing table:\n");
    displayRoutingTable();
    createRoutingTable();
    printf("\nFinal Routing table:\n");
    displayRoutingTable();
    int choice = 1;
    int source,destination;
    while(choice)
    {
        printf("\nWould you like to find the distance between two nodes?(0 or 1):");
        scanf("%d",&choice);
        if(!choice)
        {
            exit(0);
        }
        printf("\nEnter the source node:");
        scanf("%d",&source);
        printf("Enter the destination node:");
        scanf("%d",&destination);
        printf("\nCost:%d",c[source][destination].cost);
        printf("\n%d-->",source);
        findPath(source,destination);
        printf("%d\n",destination);
    }
    return 0;
}

void displayRoutingTable()
{
    for(int i=1;i<=numberOfNodes;i++)
    {
        printf("Row %d -->",i);
        for(int j=1;j<=numberOfNodes;j++)
        {
            printf("Node:%d\tCost:%d\tVia:%d\t|\t",j,c[i][j].cost,c[i][j].via);
        }
        printf("\n");
    }
}

void createRoutingTable()
{
    int cost,tempCost,via;
    for(int i=1;i<=numberOfNodes;i++)
    {
        for(int j=1;j<=numberOfNodes;j++)
        {
            cost = INFINITY;
            if(i!=j)
            {
                for(int k=1;k<=numberOfNodes;k++)
                {
                    if(i!=k)
                    {
                        tempCost = c[i][k].cost + c[k][j].cost;
                        if(cost>tempCost)
                        {
                            cost = tempCost;
                            via = k;
                        }
                    }
                }
                c[i][j].cost=cost;
                c[i][j].via=via;
            }
            else
            {
                c[i][j].cost = 0;
                c[i][j].via = i;
            }
        }
    }
}

void findPath(int source,int destination)
{
    int tempVia = c[source][destination].via;
    if(tempVia<destination)
    {
        findPath(source,tempVia);
    }
    if(tempVia!=destination)
    {
        printf("%d-->",tempVia);
    }
}

