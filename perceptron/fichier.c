 #include <stdio.h>
#include <stdlib.h>
#include "fichier.h"
#include <math.h>
#include <time.h>



base_t * lireFichier(char * nomfichier){
    FILE * fichier=NULL;
    int i,j;
    base_t * resultat=NULL;

    resultat=(base_t *)malloc(sizeof(base_t));

    if(resultat){

        fichier=fopen(nomfichier,"r");

        if(fichier){

            fscanf(fichier,"%d %d",&resultat->n,&resultat->p);

            fscanf(fichier,"\n");

            resultat->x=(double **)malloc((resultat->p)*sizeof(double *));
            resultat->c=(double *)malloc((resultat->p)*sizeof(double));
            resultat->w=(double *)malloc(((resultat->n)+1)*sizeof(double));

            if(resultat->w&&resultat->c&&resultat->w){
                for(i=0;i<resultat->p;i++){

                    (resultat->x)[i]=(double *)malloc((resultat->n)*sizeof(double));

                    (resultat->x)[i][0]=1.0;

                    for(j=1;j<(resultat->n)+1;j++){

                        fscanf(fichier,"%lf",&(resultat->x)[i][j]);

                    }

                    fscanf(fichier,"%lf",&(resultat->c)[i]);



                    fscanf(fichier,"\n");

                }
            }
            else{
                printf("Erreur lors de l'allocation.");
            }



            fclose(fichier);

        }
    }
	
    return resultat;

}

base_t * lireFichier2(char * nomfichier){
    FILE * fichier=NULL;
    int i,j;
    base_t * resultat=NULL;

    resultat=(base_t *)malloc(sizeof(base_t));

    if(resultat){

        fichier=fopen(nomfichier,"r");

        if(fichier){

            fscanf(fichier,"%d %d",&resultat->n,&resultat->p);

            fscanf(fichier,"\n");

            resultat->x=(double **)malloc((resultat->p)*sizeof(double *));
            resultat->c=(double *)malloc((resultat->p)*sizeof(double));
            resultat->w=(double *)malloc(((resultat->n)+1)*sizeof(double));

            if(resultat->w&&resultat->c&&resultat->w){
                for(i=0;i<resultat->p;i++){

                    (resultat->x)[i]=(double *)malloc((resultat->n)*sizeof(double));

                    

                    for(j=0;j<(resultat->n);j++){

                        fscanf(fichier,"%lf",&(resultat->x)[i][j]);

                    }

                    fscanf(fichier,"%lf",&(resultat->c)[i]);



                    fscanf(fichier,"\n");

                }
            }
            else{
                printf("Erreur lors de l'allocation.");
            }



            fclose(fichier);

        }
    }

    return resultat;

}

basePMC_t *Mono2PMC(base_t* mono,int couches)
{
    basePMC_t resultat=null;
    int i;
    
    resultat->x=mono->x;
    resultat->c=mono->c;
    resultat->n=mono->n;
    resultat->p=mono->p;
    resultat->w=(double **)malloc(couches)*sizeof(double *));
    
    for(i=0;i<couches;i++)
	resultat->w[i]=(double *)malloc(


void afficherW(base_t * data){
    int i;

    for(i=0;i<(data->n);i++){
        printf("%lf\t ",(data->w)[i]);
    }
    printf("\n");
}

void freeBase(base_t *data){

    int i;

    for(i=0;i<data->p;i++){
        free((data->x)[i]);
    }

    free(data->x);
    free(data->c);
    free(data->w);

    free(data);

}

void initW(base_t * data){

	int i;
	
	srand(time(0));
	for(i=0;i<(data->n)+1;i++)
		(data->w)[i]=rand();


}

double produitScalaire(double * vect1,double * vect2,int size){
    double result=0;
    int i;

    for(i=0;i<size+1;i++){
        result=result+vect1[i]*vect2[i];
    }


    return result;

}

double * produitMatriceVecteur(double ** matrice,double * vect,int row,int columns){
	int i;
	double * result=(double *)malloc(row*sizeof(double));
	
	
	if(result){
	
		for(i=0;i<row;i++){
		
			result[i]=produitScalaire(matrice[i],vect,columns);
			
		}
	}
	
	return result;
}
	
double* sommeVecteurs(double * vect1,double * vect2,int size){
    double* result=(double *)malloc(size*sizeof(double));
    int i;

    for(i=0;i<size+1;i++){
        result[i]=vect1[i]+vect2[i];
    }
	
    return result;
}

double ** produitVecteurVecteur(double * vect1,double *vect2,int size){

	int i,j;
	double ** result=(double **)malloc(size*sizeof(double *));
	
	if(result){
	
		for(i=0;i<size;i++){
		
			result[i]=(double *)malloc(size*sizeof(double));
			
			if(result[i]){
			
				for(j=0;j<size;j++){
				
					result[i][j]=vect1[i]*vect2[j];
					
				}
			}
		}
	}
	
	return result;
}


double ** sommeMatrice(double ** matrice1,double ** matrice2,int row,int columns){

		int i,j;
		double ** result=(double **)malloc(row*sizeof(double *));
		
		if(result){
		
			for(i=0;i<row;i++){
			
				result[i]=(double *)malloc(columns*sizeof(double));
				
				if(result[i]){
				
					for(j=0;j<columns;j++){
					
						result[i][j]=matrice1[i][j]+matrice2[i][j];
						
					}
					
				}
				
			}
			
		}
		
		return result;
		
}