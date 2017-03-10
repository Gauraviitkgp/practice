#include <stdio.h>
#include <C:\Users\Mahi Suryawanshi\Documents\IIT Kharagpur\Computer science\Programs\area_curves.h>

int main()
{
    float a,b;
    scanf("%f%f",&a,&b);
    printf("%5.2f\n",area_Circle(a));
    printf("%5.2f\n",area_Ellipse(a,b));
    printf("%5.2f\n",area_Square(a));
    printf("%5.2f",area_Rectangle(a,b));
}
