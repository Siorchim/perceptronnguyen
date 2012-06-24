#include <stdio.h>
#include <stdlib.h>
#include "fichier.h"
#include "gradient.h"
#include <math.h>




void adaline(base_t * data,float pas,float seuil){
   	int j,i,compteur=0;
   	float o=0;
	float copie[(data->n)];
	float variation[(data->n)];
	float * temp;
	srand(time(0));
   	for(i=0;i<(data->n);i++)
		(data->w)[i]=rand();
	
	
	do{
		for(i=0;i<(data->n);i++)
			copie[i]=(data->w)[i];									
		
		if (isnan(o))
			{
				for(j=0;j<(data->n);j++)
					(data->w)[j]=rand();
				pas=pas/10;
			}
		for(j=0;j<data->p;j++)
		{
			
			
			o=produitScalaire((data->x)[j],data->w,(data->n)-1);
			
			
			for(i=0;i<(data->n);i++)
			{
						
						variation[i]=pas*(((data->c)[j]-o)*((data->x)[j][i]));
			}
			
			temp=sommeVecteurs(data->w,variation,(data->n)-1);
			free(data->w);
			data->w=temp;
			

			
			pas=pas*0.999;
			
		}
		
	}while(!testb(copie,variation,(data->n)-1,seuil));

}

void descenteGradient(base_t * data,float seuil){

	int i,j;
	float pas=1;
	float copie[(data->n)];
	float variation[(data->n)];
	float o[(data->p)];
	
	srand(time(0));
	for(i=0;i<(data->n);i++){
		(data->w)[i]=rand();
	}
	
	do{
		
		for(i=0;i<(data->n);i++){
			variation[i]=0;
			copie[i]=data->w[i];
		}
		
		for(i=0;i<data->p;i++){
			o[i]=produitScalaire((data->x)[i],data->w,(data->n)-1);
			
			if (isnan(o[i]))
			{
				for(j=0;j<(data->n);j++)
					(data->w)[j]=rand();
				pas=pas/10;
			}
			
			for(j=0;j<(data->n);j++){
				
				variation[j]=variation[j]+pas*(data->c[i]-o[i])*data->x[i][j];
			}
		}
		
		for(i=0;i<data->n;i++){
			
			data->w[i]=data->w[i]+variation[i];
		}
			
		pas=pas*0.999;		
		
		
	}while(!testb(copie,variation,(data->n),seuil));
	
	afficherW(data);
}



int testb(float * w,float * variation,int size,float seuil)
{

    int i;
    float normeW=0,normeVariation=0;

    for(i=0;i<size;i++){
		normeW=normeW+w[i]*w[i];
        normeVariation=normeVariation+variation[i]*variation[i];
	}
	normeW=sqrt(normeW);
	normeVariation=sqrt(normeVariation);
	
	
    return ((normeVariation/normeW)<seuil);


}

float** MatA(base_t * data)
{
	int i,j;
	float temp[data->n];
	float** retour;
	for(j=0;j<data->n;j++)
		{
			temp[j]=(data->x)[0][j];
			
		}
	retour=produitVecteurVecteur(temp,temp,data->n);	
	for(i=1;i<data->n;i++)
	{
		for(j=0;j<data->n;j++)
		{
			temp[j]=(data->x)[i][j];
			
		}
		retour=sommeMatrice(retour,produitVecteurVecteur(temp,temp,data->n),data->n,data->n);
	}
	return retour;
}

float* VectB(base_t * data)
{
	int i,j;
	float temp[data->n];
	float temp2[data->n];
	float * retour;
	for(j=0;j<data->n;j++)
		{
			temp2[j]=(data->x)[0][j]*(data->c)[0];			
		}
	retour=temp2;
	for(i=1;i<data->n;i++)
	{
		for(j=0;i<data->n;j++)
		{
			temp[j]=(data->x)[i][j]*(data->c)[i];
		}
		retour=sommeVecteurs(retour,temp,data->n);
	}
	return retour;
}	

