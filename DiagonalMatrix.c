#include <stdio.h>
#include <stdlib.h>
//Diagonal Matrix, store in array

struct Matrix
{
    int A[10];
    int n;
};
void Set(struct Matrix *m, int i, int j, int x) //modify address, use pointer * for m
{
    if(i==j)
    {
        m->A[i-1] = x;
    }
}
int Get(struct Matrix m, int i, int j)
{
   if(i==j)
   {
      return m.A[i-1];
   }else
       return 0;
}
void Display(struct Matrix m)
{
    int i=0, j=0;
    for(i=0; i<m.n; i++)
    {
        for(j=0; j<m.n; j++)
        {
            if(i==j)
                 printf("%d ", m.A[i]);
            else
                printf("0 ");
        }
        printf("\n");
    }
}
int main(void)
{
    struct Matrix m;
    m.n=4; //diagnonal matrix of size 4
    
    Set(&m,1,1,5); Set(&m,2,2,8);Set(&m,3,3,9);Set(&m,4,4,12);
    printf("%d \n", Get(m,2,2));
    Display(m);

    return 0;
}
