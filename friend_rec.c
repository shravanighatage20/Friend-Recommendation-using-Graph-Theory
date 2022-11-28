#include<stdio.h>
#include<stdlib.h>
#define max 20

int main()
{
    int edges,i,j,v1,v2,a[max][max],b[max][max];
    int s=0,s2=0,p,k;
    int adj[max][max],d[max][max];
    int n;
    printf("Enter number of nodes: ");
    scanf("%d",&n);
    edges=n*(n-1)/2;

    for(i=1;i<=edges;i++)
    {
        printf("Enter edge %d( 0 0 to quit ): ",i);
        scanf("%d%d",&v1,&v2);

        if( (v1==0) && (v2==0) )
        {
            break;
        }
        if( v1 > n || v2 > n || v1<=0 || v2<=0)
        {
            printf("Invalid edge!\n");
            i--;
        }
        else
        {
            adj[v1][v2]=1;
            adj[v2][v1]=1;
        }

    }
    printf("The adjacency matrix is :\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
             if(adj[i][j]!=1)
             {
                 adj[i][j]=0;
             }
             printf("%4d",adj[i][j]);

        }
        printf("\n");
    }
    printf("\n");
    //square of matrix

    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
                if(i!=j)
                {
                    for(k=1;k<=n;k++)
                    {
                        s=s+adj[i][k]*adj[k][j];
                    }
                    a[i][j]=s;
                    s=0;
                }
        }
        printf("\n");
    }
    //for printing square of matrix
    printf("square of matrix\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(i==j)
            {
                a[i][j]=0;
            }
            printf("%4d",a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    //for cube of matrix
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(i!=j)
            {
                for(p=1;p<=n;p++)
                {
                      s2=s2+a[i][p]*adj[p][j];

                }
                b[i][j]=s2;
                s2=0;
            }


        }
        printf("\n");
    }
    //for cube of matrix
    printf("cube of matrix\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(i==j)
            {
                b[i][j]=0;
            }
            printf("%4d",b[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    //for sum of matrix ,cube,square
     printf("sum of A A^2 A^3\n");
     for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            d[i][j]=a[i][j]+adj[i][j]+b[i][j];
            printf("%4d",d[i][j]);


        }
        printf("\n");
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(d[i][j]==1)
            {
                printf("%d can be a friend of %d\n",i,j);
            }
        }
        printf("\n");
    }
}
