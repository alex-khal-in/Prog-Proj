#include "lab1.h"
#include <stdio.h>

int run_lab1()
{
    float V;
    float v1;
    float v0;
    float t;
	float v2;
    printf("V(l) = ");
    scanf("%f", &V);
    printf("v1(l/min) = ");
    scanf("%f", &v1);
    printf("t(min) = ");
    scanf("%f", &t);
	v0 = V/t;
	v2 = v1 - v0;
	printf("v2(l/min) = %f\n", v2);
	return 0;
}

float calc_v2(float V, float v1, float t) {return v1 - V/t;}

int run_lab1_add()
{
    float V;
    float v1;
    float t;
    printf("V(l) = ");
    scanf("%f", &V);
    printf("v1(l/min) = ");
    scanf("%f", &v1);
    printf("t(min) = ");
    scanf("%f", &t);
    printf("v2(l/min) = %f\n", calc_v2(V, v1, t));
    return 0;
}
