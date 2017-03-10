#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int roll;
    int marks;
}stu;

void modify_value(stu A)
{
        A.roll +=1000;
        A.marks +=1000;
}

void modify_reference(stu *A)
{
        A->roll +=1000;
        A->marks +=1000;
}





int main()
{
    stu A={50,100};

    printf("%d %d\n",A.roll, A.marks);

    modify_value(A);

    printf("-------------------------------------------\n");

    printf("%d %d\n",A.roll, A.marks);

    printf("-------------------------------------------\n");

    modify_reference(&A);

    printf("%d %d\n",A.roll, A.marks);

}
