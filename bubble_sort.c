


// 1)program for bubble sort
#include<stdio.h>
int main()
{
    int a[10],i,j,temp,n;
    printf("\n Enter the max no.of Elements to Sort: \n");
    scanf("%d",&n);
    printf("\n Enter the Elements : \n");
    for(i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0; i<n; i++)
        for(j=i+1; j<n; j++)
        {
            if(a[i]>a[j])
            {
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    for(i=0; i<n; i++)
    {
        printf("%d\t",a[i]);
    }
    return 0;
}

// output:

//  Enter the max no.of Elements to Sort: 
// 7

//  Enter the Elements : 
// 3
// 5
// 23
// 34
// 12
// 7
// 45
// 3       5       7       12      23      34      45      