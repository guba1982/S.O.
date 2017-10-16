#include<stdio.h>
#include<stdlib.h>
hola
#include<iostream>
#define largop 2000
#define columnasp 5

using namespace std;

//====================Declaracion de variables========================

        //Matriz Procesos
        int procesos [largop] [columnasp];

        int 	nroproceso;
		int 	tiempoarribo;
		int		tiemporafaga;
		int		tiemporestante;
		bool 	estado;

        //Matriz Procesados
        int procesados [largop] [columnasp];

		//Proceso Anterior
        int 	ejecucionproceso	=0;
		int 	ejecucioncomienzo	=0;
		int		ejecucionfin		=0;
		int		ejecucionrestante	=0;
        int		ejecuciontiempo		=0;

        //Proceso Minimo
        int 	minproceso=0;
		int 	minarribo=0;
		int		minrafaga=0;
		int		minrestante=0;
        int		minestado=0;

        int		cantidadprocesos=0;
        int		tiempototalrafagas=0;
        int     tiempotranscurrido=0;
		int		cambioproceso=0;
		int     hayprocesos=-1;

int main(){



//=================================================================
//================================Menu=============================
//=================================================================


						while(1)
						{
                            //system ("cls");
							cout<< "Por favor ingrese la cantidad total de procesos a ejecutar: ";
							cin>>cantidadprocesos;//scanf("%i",& cantidadprocesos);
							if (cantidadprocesos<1)
								{
								   cout<< "\n Error: La cantidad total de procesos a ejecutar debe ser mayor a cero.";
								   cout<< "\n\n Presione una tecla para continuar...";
								   cin.get();cin.get();

								}
							else
								break;
						}

                        for (int y=0;y<cantidadprocesos;y++)
						{
                                 //Asigno el Nrodeproceso
                                procesos[y][0]=y+1;

                                //Tomo el tiempo de arribo de el proceso x
                                while(1)
                                {
                                    //system ("cls");
                                    cout<<"Proceso "<<procesos[y][0]<<" :\n";
                                    cout<<"\n Ingrese el tiempo de arribo: ";
                                    cin>>procesos[y][1];//scanf("%i",& procesos[y][1]);

                                    if (procesos[y][1]<0)
                                    {
                                        cout<<"\n El tiempo de arribo debe ser mayor o igual a 0";
                                        cout<<"\n\n Presione una tecla para continuar...";
                                        cin.get();cin.get();

                                    }
                                    else
                                      break;

                                }

                                //Tomo el tiempo de rafaga proceso x
                                while(1)
                                {
                                    //system ("cls");
                                    cout<<"\n Ingrese el tiempo de ráfaga:  ";
                                    cin>>procesos[y][2];//scanf("%i",& procesos[y][2]);
                                    procesos[y][3]=procesos[y][2];
                                    if (procesos[y][2]<1)
                                    {
                                        cout<<"\n El tiempo de rafaga debe ser mayor a 0";
                                        cout<<"\n\n Presione una tecla para continuar...";
                                        cin.get();cin.get();
                                    }
                                    else
                                      break;

                                }

                        }


                        //Imprimo Matriz
                        cout<<"Proceso\tTiempoArribo\tTiempoRafaga\tTiempoRestante\n";
                        for (int h=0;h<cantidadprocesos;h++)
						{
                            cout<<"\n"		<<procesos[h][0];//Proceso
                            cout<<"\t"	    <<procesos[h][1];//TiempoArribo
                            cout<<"\t\t\t"	<<procesos[h][2];//TiempoRafaga
                            cout<<"\t\t\t"	<<procesos[h][3];//TiempoRestante
                            cout<<"\t\t\t\t"	<<tiempototalrafagas;
                            tiempototalrafagas+=procesos[h][2];

						}
                        //cout<<("\n\n\n\nProceso\tTiempoArribo\tTiempoRafaga\tTiempoRestante\tEstado\n");

                        //Proceso los datos
                        while (hayprocesos!=0)
                        {
							hayprocesos=0;
                            //Encuentro arribado con minimo tiempo no terminado
                            for (int k=0;k<cantidadprocesos;k++)
                            {

                                if (procesos[k][4]=1)//hay algo para ejecutar?
                                {
									
									if(procesos[k][1]>=tiempotranscurrido)
                                    {
										
										
										minproceso  =procesos[k][0];
										minarribo   =procesos[k][1];
										minrafaga   =procesos[k][2];
										minrestante =procesos[k][3];
										minestado   =procesos[k][4];
										
										
									}
									else
									{
										minproceso  = 0;
										minarribo   = 0;
										minrafaga   = 0;
										minrestante = 0;
										minestado   = 0;
									}

                                }

                            }

							//cout<<"\n\t"	<< minproceso ;
							//cout<<"\t"	<< minarribo  ;
							//cout<<"\t"	<< minrafaga  ;
							//cout<<"\t"	<< minrestante;
						    //cout<<"\t"	<< minestado  ;

							//if (cambiaproceso!=minproceso )



                                procesos[minproceso-1][3]--;
                                if(procesos[minproceso-1][3]==0)
                                {
                                    procesos[minproceso][4]=0;
                                }


                            tiempotranscurrido=tiempotranscurrido+1;
                        }


return 0;
}


/*
 int min_matriz (int m[N][N], int*imin, int*jmin)
{
	int i,j,min;
	min=m[0][0];
	*imin=0;
	*jmin=0;
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			if(m[i][j]<min)
			{
				min=m[i][j];
				*imin=i;
				*jmin=j;
			}
		}
	}
	return min;
}
*/
