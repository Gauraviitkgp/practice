#ifndef AREA_CURVES_H_INCLUDED
#define AREA_CURVES_H_INCLUDED
#define PI 3.14

float area_Circle(float radius)
{
    return (PI*radius*radius);
}

float area_Ellipse(float a, float b)
{
    return (PI*a*b);
}

float area_Square(float side)
{
    return side*side;
}

float area_Rectangle(float a, float b)
{
    return a*b;
}


#endif // AREA_CURVES_H_INCLUDED
