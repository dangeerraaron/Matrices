#include <stdio.h>
#include <stdlib.h>

//sparse matrix template

struct Element //aray structure
{
    int i; //row
    int j; //column
    int x; // non-zero element
};

struct Sparse
{
    int m; //row
    int n; //columns
    int num; //# of non-zero elements
    struct Element *ele; // pointer to an array of elements, see above
    
};
void create(struct Sparse *s) 
{
    int i=0;
    
    printf("Enter dimensions of the matrix: \n");
    scanf("%d%d", &s->m, &s->n); //dimensions of matrix rows/cols, store in location struct sparse
    printf("Enter number of non-zero elements: \n");
    scanf("%d", &s->num);  //
    
    s->ele=(struct Element *)malloc(s->num*sizeof(struct Element)); //create array of size num, as the number of non-zero elements determines array size dynamically

    printf("Enter non-zero elements:\n");
        for(i=0; i<s->num; i++) //loop until non-zero net entered, enter into ele[]
        {
            scanf("%d%d%d", &s->ele[i].i, &s->ele[i].j, &s->ele[i].x);
        }
}

void display(struct Sparse s)//call by value as matrix won't be altered
{
    int i=0,j=0,k=0; //k=keeps track of non-zero elements
    
    for(i=0; i<s.m; i++)
    {
        for(j=0; j<s.n ;j++)
        {
           if(i==s.ele[k].i && j==s.ele[k].j)
           {
               printf("%d ",s.ele[k++].x); //increment index k 
           }else{
                    printf("0 ");
                }
         }
         
         printf("\n");
    }
}
struct Sparse * add(struct Sparse *s1, struct Sparse *s2)
{

    int i=0, j=0, k=0;

    struct Sparse *sum; //sum sparse pointer
    sum = (struct Sparse *)malloc(sizeof(struct Sparse)); //create sum in heap
    sum->ele=(struct Element *)malloc((s1->num+s2->num)*sizeof(struct Element)); //array created for sparse matrix addition
    
    while(i<s1->num && j<s2->num)
    {
        if(s1->ele[i].i < s2->ele[j].i)
            sum->ele[k++] = s1->ele[i++];
        else if(s1->ele[i].i > s2->ele[j].i)
            sum->ele[k++] = s2->ele[j++];
        else
        {
            if(s1->ele[i].j < s2->ele[j].j)
                sum->ele[k++] = s1->ele[i++];
            else if(s1->ele[i].j > s2->ele[j].j)
                sum->ele[k++] = s2->ele[j++];
            else
            {
                sum->ele[k]=s1->ele[i];
                sum->ele[k++].x = s1->ele[i++].x + s2->ele[j++].x;
            }
        
        }
    }
    for(;i<s1->num;i++)sum->ele[k++]=s1->ele[i];
    for(;j<s2->num;j++)sum->ele[k++]=s2->ele[j];
    sum->m=s1->m;
    sum->n=s1->n;
    sum->num=k;
    
    return sum;
    
}
int main(void)
{
    struct Sparse s1, s2,*s3;
    
    create(&s1);
    create(&s2);
    
    s3=add(&s1, &s2);
    printf("First Matrix: \n");
    display(s1);
    printf("Second Matrix: \n");
    display(s2);
    printf("Sum Matrix: \n");
    display(*s3);
    
   return 0;
};
