#include<stdio.h>
#include<stdio.h>

// Lower triangular matrix, column major formula

struct Matrix
{
    int *A; //pointer to heap array
    int n; // matrix dimensions
};

void Set(struct Matrix *m, int i, int j, int x)
{
    if(i >= j)
    {
        m->A[m->n*(j-1)+(j-2)*(j-1)/2+i-j]=x; // if row is greater than or equal to colums, set x to specified index
    }
}

int Get(struct Matrix m, int i, int j)
{
    if(i >= j)
    {
        return m.A[m.n*(j-1)+(j-2)*(j-1)/2+i-j];
    }else{
            return 0;
      }
}

void Display(struct Matrix m)
{
    int i=0, j=0;
    for(i=1; i <= m.n; i++)
    {
        for(j=1; j<=m.n; j++)
        {
           if(i>=j)
               printf("%d ",m.A[m.n*(j-1)+(j-2)*(j-1)/2+i-j]);
           else 
              printf("0 ");
        }
        printf("\n");
    }
}

int main(void)
{
    struct Matrix m;
    int i=0,j=0,x=0;
    
    printf("Enter dimensions of matrix: \n");
    scanf("%d", &m.n); // store dimensions in struct m 
    m.A=(int *)malloc(m.n*(m.n+1)/2*sizeof(int)); // allocate size of matrix in heap
    
    printf("Enter all elements into the matrix: \n");
    for(i=1; i<=m.n; i++)
    {
        for(j=1; j<=m.n; j++)
        {
            scanf("%d", &x);
            Set(&m, i, j, x); //call to set function address, indicies, and x to insert into matrix
        }
    }
    printf("\n\n");
    Display(m);
    
    return 0;
}
