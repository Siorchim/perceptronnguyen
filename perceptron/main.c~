/**
 * Flood It par Christian Nguyen G12
 * Version graphique avec Xlib
 * 
 * Projet de TP numéro 6
 *
 * 
 * 
 * 
 */

/************************ INCLUSIONS *******************/

#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "fichier.h"
#include "correction.h"
#include "gradient.h"


/************************CONSTANTES**********************/

#define COULEURS 6
#define TAILLE 12
#define ESSAIS 22


/************************PROTOTYPES**********************/

void affiche(base_t* data);
void saisie();


/************************VARIABLES GLOBALES**************/


  Bool           sortie = False; /* Indicateur de fin de pgm             */

  Window         root;           /* Fenetre racine (fond de l'ecran)     */
  Window         win;            /* Fenetre de travail                   */
  Window         subwin;         /* Sous fenetre                         */
  Display       *dpy;            /* Serveur de fenetrage de ce pgm       */
  
  int            ecran;          /* Declaration de l'ecran par defaut    */
  
  unsigned long  wpx,            /* Variables temporaires pour la        */
		  bpx;            /* Couleur whithe et black (fg, bg)     */

  XEvent         ev;             /* D�clare une variable evenement       */
  unsigned long  mask;           /* Declare un mask d'evenement          */

  GC             gcontext;         
  XGCValues      gcv;               
  unsigned long  gcmask;             
  Visual        *visual;
  
  int            count;
  char **        list;
  
  Colormap       colormap;
  unsigned long  tab_couleurs[256];
  XColor C;
  
  
  

  
/************************ PROGRAMME PPAL***************/

int main(int argc, char** argv)
{


  int i;
  
  base_t * data=NULL;
  base_t * data2=NULL;

    if(argc==3){
        data=lireFichier2(argv[1]);
		data2=lireFichier2(argv[1]);
		
      

        if(data){
			
			descenteGradient(data,atof(argv[2]));
			adaline(data2,atof(argv[2]));

        	
        }

    }
  

  
  
  dpy = XOpenDisplay(0);         
				    
  ecran    = DefaultScreen(dpy);
  root     = DefaultRootWindow(dpy);
  
  /* ------- Recup. couleur de l'avant plan et arriere plan ------------ */
  
  bpx      = BlackPixel(dpy,ecran);
  wpx      = WhitePixel(dpy,ecran);
  
  visual   = DefaultVisual(dpy, ecran);
  
  /* ------- Creation de la fenetre: Epaiss 6 pixels, L 500 H 300 ------ */
  
  win = XCreateSimpleWindow(dpy,root,30,40,200,200,6,wpx,bpx);
  
  XStoreName(dpy,win,"Perceptron");

  /* ------- Definition des evenements qui les concernent -------------- */

  XSelectInput(dpy,win,ButtonPressMask |
			ButtonReleaseMask |
			Button1MotionMask |
			KeyPressMask |
			ExposureMask );

  /* ------------------------------------------------------------------- */

  XMapWindow(dpy,win);                      /* Affiche la fenetre        */


  /* ------- Obtention des couleurs ------------------------------------ */
  /* Le visual est suppose TrueColor */
  /* la palette est en lecture seule, d'ou le AllocNone */
  colormap = XCreateColormap(dpy, win, visual, AllocNone);
    
  /*--------Récupérations des couleurs dans les variables globales correspondantes*/
  
for(i = 0 ; i < 256 ; i++)
{
	C.red = 65535-i*256;
	C.green = 0;
	C.blue = i*256;
	/* Pour aller du rouge au bleu */
	XAllocColor(dpy,colormap , &C);
	tab_couleurs[i] = C.pixel;
}
  

  /* ------- Obtention des polices de taille 20------------------------ */
  list = XListFonts(dpy, "*-20-*", 1000, &count);  
  printf("Fonts count: %d\n", count);   

  /* ------- Creation des contextes standards -------------------------- */
  
  gcv.foreground = wpx;                     /* Contexte standard         */
  gcv.background = bpx;
  gcv.line_width = 3;
  gcv.function   = GXcopy;
  gcmask         = GCForeground | GCBackground | GCLineWidth | GCFunction;
  gcontext       = XCreateGC(dpy,win,gcmask,&gcv);


  /* ------- Début de la boucle principale ---------------------------- */
			
	affiche(data);
  while(!sortie)
  {                                             
      
      XNextEvent(dpy,&ev);
      switch(ev.type)
      {
	/*case Expose 	 : affiche(data);break;*/
	case KeyPress    : saisie();
			     break;

      }
  }
  
  XFreeFontNames(list);
  XFreeColormap(dpy, colormap);
  
  XDestroyWindow(dpy , win );
  
  XCloseDisplay(dpy);
  

  
  return 0;
}

/************************ IMPLEMENTATION ***************/

void affiche(base_t* data)
{                                     
  

  
  int 		i,j;
  double temp[3];
  double o;
  
  /***Construction de la grille****/
  temp[2]=-1;/*
  for (i=0;i<200;i++)
  {
    for (j=0;j<200;j++)
    {
	  temp[0]=i/10;
	  temp[1]=j/10;
	  o=(produitScalaire(temp,data->w,3));
	  o=(o>1?1:0);
	  
	  
	  C.red =  o*100000;
	  C.green =o*100000;
      C.blue = o*100000;
	
	XAllocColor(dpy,colormap , &C);
	XSetForeground(dpy,gcontext,C.pixel);
	XDrawPoint(dpy,win,gcontext,i,200-j);
	}
	}*/
	 for (i=0;i<200;i++)
	{
    for (j=0;j<200;j++)
    {
	  temp[0]=i/10;
	  temp[1]=j/10;
	  o=(produitScalaire(temp,data->w,3));
	  
	  o=(o>14?14:o);
	  
	  C.red =  o*4000;
	  C.green =o*4000;
      C.blue = 0;
	  
	  if (C.red<1000)
		printf("Pour les points %e %e la sortie vaut %f\n",temp[0],temp[1],o);
	
	XAllocColor(dpy,colormap , &C);
	XSetForeground(dpy,gcontext,C.pixel);
	XDrawPoint(dpy,win,gcontext,i,200-j);
	}
	}
	for (i=0;i<data->p;i++)
	{
	
	   C.red = (data->c)[i]*55555;
	  C.green =fabs((data->c)[i]-1)*55555;
      C.blue = 0;
      XAllocColor(dpy,colormap , &C);
	XSetForeground(dpy,gcontext,C.pixel);
	XFillRectangle(dpy,win,gcontext,(data->x)[i][0]*10+2,200-(data->x)[i][1]*10-8,6,6);
      
  }
  
  
  


}

/* ---------------------------------------------------------------------- */
/* saisie                Saisie de touches                                */
/* ---------------------------------------------------------------------- */

void saisie()
{   
  
  #define    ESPACE 0x20
  char       chaine[2];
  KeySym     ks;
  						

  XLookupString(&ev.xkey,chaine, 2, &ks, NULL);
  
  if (ks == ESPACE) sortie = True;/*Quitter le programme*/
  
  
}
/* ----------Fonctions issues du moteur texte------------------------- */




    