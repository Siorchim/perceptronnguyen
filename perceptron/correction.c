#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "fichier.h"
#include "correction.h"



void correctionErreur(base_t * data){
    int alea=0,i,compteur=0;
    double o;

    initW(data);

    while(!test(data)&&compteur<100){




        o=(produitScalaire((data->x)[alea],data->w,data->n)>0? 1 : 0);


        for(i=0;i<(data->n)+1;i++){

            (data->w)[i]=(data->w)[i]+(((data->c)[alea]-o)*((data->x)[alea][i]));

        }

        afficherW(data);

        alea=(alea+1)%(data->p);

        compteur++;

    }


}










int test(base_t * data){

    int i,result=1;
    double o;

    for(i=0;i<data->p;i++){
        o=produitScalaire((data->x)[i],data->w,data->n);

        if((o>0&&(data->c)[i]==0)||(o<=0&&(data->c)[i]==1)){
            result=0;
        }
    }

    return result;


}
