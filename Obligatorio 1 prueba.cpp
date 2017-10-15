#include<stdio.h>
#include<stdlib.h>


#define largop 2000
#define columnasp 5


//====================Declaracion de variables========================

        //Matriz en la cual guardo los procesos
        int procesos [largop] [columnasp];

        int 	nroproceso;
		int 	tiempoarribo;
		int		tiemporafaga;
		int		tiemporestante;
		bool 	estado;


        int		cantidadprocesos=0;

int main(){
	

		//Presentacion
		printf("\n\n\n\n\n\n\n");
		printf("\t\t\t--------------------------------------------------------\n");
		printf("\t\t\t--------- Obligatorio 1 - Sistema Operativos -----------\n");
		printf("\t\t\t---------      Tecnologo en Informatica      -----------\n");
		printf("\t\t\t---------              Grupo 7               -----------\n");
		printf("\t\t\t------ Planificador de Procesos SJF Expropiativo -------\n");
		printf("\t\t\t--------------------------------------------------------\n");




//=================================================================
//================================Menu=============================
//=================================================================


						while(1)
						{
                            system ("clear");
							printf ("Por favor ingrese la cantidad total de procesos a ejecutar: ");
							scanf("%i",& cantidadprocesos);
							if (cantidadprocesos<1)
								{
								   printf ("\n Error: La cantidad total de procesos a ejecutar debe ser mayor a cero.");
								   printf ("\n\n Presione una tecla para continuar...");
								   ;
								}
							else
								break;
						}

                        for (int y=0;y<cantidadprocesos;y++)
						{
                            //for (int x=0; x<columnasp; x++)
                            //{


                                 //Asigno el Nrodeproceso
                                procesos[y][0]=y+1;
                                printf("Proceso %i : \n", procesos[y][0]);


                                //Tomo el tiempo de arribo de el proceso x
                                while(1)
                                {
                                    system ("clear");
                                    printf ("\n Ingrese el tiempo de arribo: ");
                                    scanf("%i",& procesos[y][1]);

                                    if (procesos[y][1]<1)
                                    {
                                       printf ("\n El tiempo de arribo debe ser mayor a 0");
                                    }
                                    else
                                      break;

                                }

                                //Tomo el tiempo de rafaga proceso x
                                while(1)
                                {
                                    system ("clear");
                                    printf ("\n Ingrese el tiempo de ráfaga:  ");
                                    scanf("%i",& procesos[y][2]);
                                    procesos[y][3]=procesos[y][2];
                                    if (procesos[y][2]<1)
                                    {
                                       printf ("\n El tiempo de rafaga debe ser mayor a 0");
                                    }
                                    else
                                      break;

                                }
                            //}
                        }
return 0;
}
