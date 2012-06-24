#include <time.h>

#ifndef GRADIENT_H
#define GRADIENT_H

#define EPSILON 0.0000000001
#define DELTA0 0.0000001

void adaline(base_t * data,double seuil);
void descenteGradient(base_t * data,double seuil);
int testb(double * w,double * variation,int siez,double seuil);
double pas(base_t* data,double* descente);
double psiPrime(base_t data,double * descente,double pas);


#endif
