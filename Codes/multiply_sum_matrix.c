#include <stdio.h>
#include <stdlib.h>

void matrix_mul();
int main()
{
    int r1,r2,c1,c2,ch;
    printf("Enter the rows and columns of the 'A' matrix:\n");
    scanf("%d", &r1);   
    scanf("%d", &c1);
    printf("Enter the rows and columns of the 'B' matrix:\n");
    scanf("%d", &r2);   
    scanf("%d", &c2);
    printf("Enter 1 to perform A*B, and 2 to perform B*A\n");
    scanf("%d", &ch);
    
    //checking the order of the matrix

    if(ch==1)
    {
        if(c1==r2)
        matrix_mul(r1,r2,c1,c2,ch);
        else
        printf("Sorry, but the order of A or B does not make that operation possible");
    }
    else
    {   
        if(c2==r1)
        matrix_mul(r1,r2,c1,c2,ch);
        else
        printf("Sorry, but the order of A or B does not make that operation possible");
    }
    return 0;
}

void matrix_mul(int r1, int r2, int c1, int c2, int ch)
{
    int i,j,k,n,s=0,r,c;
    int *a[r1];
    int *b[r2];
    int *d[r1];
    
    //creating the order of the product matrix

    if(ch==1)   
    {
        r = r1;
        c = c2;
        n = r2;
    }
    else
    {
        r = r2;
        c = c1;
        n = c2;
    }
    int *m[r];
    
    //making the 2D arrays
    
    for(i=0;i<r1;i++)
    {
        a[i] = (int*)malloc(c1*sizeof(int));
        d[i] = (int*)malloc(c1*sizeof(int));
    }
    for(i=0;i<r2;i++)
    {
        b[i] = (int*)malloc(c2*sizeof(int));
    }
    for(i=0;i<r;i++)
    {
        m[i] = (int*)malloc(c*sizeof(int));
    }

    //taking input

    printf("Enter the elements of the array 'A'\n");
    
    for(i=0;i<r1;i++)
    {
        for(j=0;j<c1;j++)
        {
            scanf("%d", (*(a+i)+j));
        }
    }

    printf("Enter the elements of the array 'B'");
    
    for(i=0;i<r2;i++)
    {
        for(j=0;j<c2;j++)
        {
            scanf("%d", (*(b+i)+j));
        }
    }

    //printing A and B

    printf("The original array: 'A'\n");

    for(i=0;i<r1;i++)
    {
        for(j=0;j<c1;j++)
        {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }
    printf("The original array: 'B'\n");

    for(i=0;i<r2;i++)
    {
        for(j=0;j<c2;j++)
        {
            printf("%d\t", b[i][j]);
        }
        printf("\n");
    }

    //multiplication begins M = A*B/B*A (core logic)

    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            for(k=0;k<n;k++)
            {
                s = s + a[i][k] * b[k][j];
            }
            m[i][j] = s;
            s = 0;
        }
    }

    //printing the multiplied array

    printf("The product array 'C'\n");

    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            printf("%d\t", m[i][j]);
        }
        printf("\n");
    }

    //printing the sum of A and B (D=A+B)

    if(r1!=r2&&c1!=c2)
    {
        printf("The sum cannot be found as the order of the two matrice are not equal\n");
    }
    else
    {
        for(i=0;i<r1;i++)
        {
            for(j=0;j<c2;j++)
            {
                d[i][j] = a[i][j]+b[i][j];
            }
        }

        printf("The sum of the two arrays A and B: \n");

        for(i=0;i<r1;i++)
        {
            for(j=0;j<c1;j++)
            {
                printf("%d\t", d[i][j]);
            }
            printf("\n");
        }

    }

}