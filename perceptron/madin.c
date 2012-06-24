#include <stdio.h>
#include <stdlib.h>
#include "fichier.h"
#include "correction.h"
#include "gradient.h"

int main(int argc,char ** argv){
    base_t * data=NULL;

    if(argc==3){
        data=lireFichier2(argv[1]);
		
      

        if(data){
			
			descenteGradient(data,atof(argv[2]));
			adaline(data,atof(argv[2]));

        	freeBase(data);
        }

    }
	
    return 0;
}


