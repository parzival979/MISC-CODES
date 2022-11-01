//Programmed By Sravanth Chowdary Potluri CS20B1006
#include<stdio.h>

struct line
{
    int destination,distance,nexthop;
};

int main()
{
    int n,e,a,b,c,i,j,k;
    printf("enter number of routers: ");
    scanf("%i",&n);
    int input[n+1][n+1];
    printf("routers 1 to %i are created\nenter number of edges: ",n);
    scanf("%i",&e);
    printf("enter details of the edge in the form of router router distance:\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
            input[i][j]=-1;
        input[i][i]=0;
    }
    for(i=0;i<e;i++)
    {
        scanf("%i%i%i",&a,&b,&c);
        input[a][b]=c;
        input[b][a]=c;
    }
    struct line table[n+1][n+1];
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
        {
            table[i][j].destination=j;
            table[i][j].distance=input[i][j];
            if(input[i][j]>-1)
                table[i][j].nexthop=j;
        }
    printf("The Initial Routing Tables Are(Ignore the next hop values if the distance is -1(infinity))");
    for(i=1;i<=n;i++)
    {
        printf("\nrouting table for %i",i);
        printf("\ndestination\tdistance\tnexthop");
        for(j=1;j<=n;j++)
            printf("\n%i\t\t%i\t\t%i",table[i][j].destination,table[i][j].distance,table[i][j].nexthop);
    }
    printf("\n");
    for(e=2;e<n;e++)
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
            {
                a=table[i][j].distance;
                c=table[i][j].nexthop;
                for(k=1;k<=n;k++)
                    if(input[i][k]!=-1&&table[k][j].distance!=-1)
                    {
                        b=table[i][k].distance+table[k][j].distance;
                        if(b<a||a==-1)
                        {
                            a=b;
                            c=k;
                        }
                    }
                table[i][j].distance=a;
                table[i][j].nexthop=c;

            }
    printf("The Final Routing Tables Are\n");
    for(i=1;i<=n;i++)
    {
        printf("\nrouting table for %i",i);
        printf("\ndestination\tdistance\tnexthop");
        for(j=1;j<=n;j++)
            printf("\n%i\t\t%i\t\t%i",table[i][j].destination,table[i][j].distance,table[i][j].nexthop);
    }
}