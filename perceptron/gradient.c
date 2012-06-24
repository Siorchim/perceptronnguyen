#include <stdio.h>
#include <stdlib.h>
#include "fichier.h"
#include "gradient.h"
#include <math.h>




void adaline(base_t * data,double seuil){
   	int j,i,test=0,compteur=0;
   	double o=0;
	double copie[(data->n)];
	double descente[(data->n)];	
	double epsilon;
	srand(time(0));
   	for(i=0;i<(data->n);i++)
		(data->w)[i]=rand()%10;
	j=0;
	
	
	
	do{
		for(i=0;i<(data->n);i++)
			copie[i]=(data->w)[i];									
		o=produitScalaire((data->x)[j],data->w,(data->n));
		
		
		for(i=0;i<(data->n);i++)
		{
					
			descente[i]=(((data->c)[j]-o)*((data->x)[j][i]));
			/*printf("sur l'échantillon %d, la direction sur %d est %lf\n",j,i,descente[i]);*/
		}
		
		epsilon=pas(data,descente);
		/*printf("epsilon %e\n",epsilon);*/
		for(i=0;i<data->n;i++){
			
			data->w[i]=data->w[i]+descente[i]*epsilon;
		}
		j=(j+1)%(data->p);
		
		compteur++;
		/*printf(" Le pas vaut %lf, echantillon %d\n",epsilon,j);*/
		
		
		if(j==0){
			
			test=testb(copie,data->w,data->n,seuil);

		}
			
		
		
	}while(compteur<data->p*20||!test);
	afficherW(data);
	printf("%d corrections avec adaline\n",compteur);
}

void descenteGradient(base_t * data,double seuil){

	int i,j,compteur=0;
	double copie[(data->n)];
	double descente[(data->n)];
	double o[(data->p)];
	double epsilon;
	srand(time(0));
	for(i=0;i<(data->n);i++){
		(data->w)[i]=rand()%100;
	}
	
	do{
		
		for(i=0;i<(data->n);i++){
			descente[i]=0;
			copie[i]=data->w[i];
		}

		for(i=0;i<data->p;i++){
			
			
			
			for(j=0;j<(data->n);j++){
				
				descente[j]=descente[j]+(data->c[i]-produitScalaire((data->x)[i],data->w,(data->n)))*data->x[i][j];
			}
		}
		epsilon=pas(data,descente);
		/*printf("epsilon %e\n",epsilon);*/
		
		for(i=0;i<data->n;i++){
			
			data->w[i]=data->w[i]+descente[i]*epsilon;
			/*descente[i]=descente[i]*epsilon;*/
		}
		compteur++;
		
		
		
		
	}while(!testb(copie,data->w,(data->n),seuil)||compteur<data->p);
	afficherW(data);	
	printf("On a %d corrections avec descente de gradient\n",compteur*(data->n));
	
}



int testb(double * copie,double * w,int size,double seuil)
{
	
	int i;
	double normeW=0,normeVariation=0, temp[size];

	for(i=0;i<size;i++){

		temp[i]=w[i]-copie[i];

	}
	
	normeVariation=sqrt(produitScalaire(temp,temp,size));
	normeW=sqrt(produitScalaire(w,w,size));

	
	
	
		
		
	return ((normeVariation/normeW)<seuil);


}

double psiPrime(base_t data,double * descente,double pas)
{
	int i,j;
	double gradient[(data.n)];
	for(i=0;i<data.n;i++){
			
			data.w[i]=data.w[i]+pas*descente[i];
			gradient[i]=0;
			
		}
	for(i=0;i<data.p;i++){
			
			
			
			for(j=0;j<(data.n);j++){
				
				gradient[j]=gradient[j]-(data.c[i]-produitScalaire((data.x)[i],data.w,(data.n)))*data.x[i][j];
			}
		}
	return produitScalaire(gradient,descente,(data.n));
}

double pas(base_t* data,double* descente)
{
	double t0=0;
	double t=DELTA0;
	double t1,tm,h=1;
	do
	{
		
			t0=t;
			t=2*t;
		
	}
		while(psiPrime(*data,descente,t)<0);
	t1=t;
	while(t1-t0>2*EPSILON&&(fabs(h)<EPSILON))
	{
		tm=(t0+t1)/2;
		/*printf("tm courant %e",tm);*/
		h=psiPrime(*data,descente,tm);
		
		if (!(fabs(h)<EPSILON))
		{
			t=(t0+t1)/2;
			if (h>0)
				t1=t;
			if (h<0)
				t0=t;
		}
	}
	return tm;
}
	
	
		

