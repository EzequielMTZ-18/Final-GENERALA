#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>

using namespace std;


#include "rlutil.h"
#include "funciones.h"
#include "dados.h"
#include "Iniciar_Partida.h"


void showItem(const char* text, int posx, int posy, bool selected){

   if(selected){
    rlutil::setBackgroundColor(rlutil::COLOR::BLUE);
    rlutil::locate(posx-3,posy);
   cout<<(char)175<< text <<" "<<(char)174<<endl;
   }
   else{
    rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
    rlutil::locate(posx-3,posy);
   cout<< " " << text << "   " <<endl;
   }
   rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
}

int main(){
    recuadro(24,6,35,9,cBLANCO,cNEGRO);
    int op=1, y=0;

    Jugador Jugadores[2];//Vector de objeto jugador
    Jugador Ganador("Vacio",0,0,100);//obj ganador, jugador que gana la partida
    Jugador Top1("Vacio",0,0,100);//el top 1

    int Prueba=0;//activa modo prueba

    int JugadorDisponible=false;// dice si hay un top1 disponible
    int rondas;


    rlutil::hidecursor();


    do{
        cls();
        ///rlutil::cls(); ///sacar esto para que la pantalla no parpadee
        rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
        rlutil::setColor(rlutil::COLOR::WHITE);
        recuadro(24,6,35,9,cBLANCO,cNEGRO);
        rlutil::locate(30,8);
        cout<<" G E N E R A L A "<<endl;

        showItem(" Juego nuevo de a 1",         30,10,y==0);
        showItem(" Juego nuevo entre 2",        30,11,y==1);
        showItem(" Mostrar puntuacion mas alta",30,12,y==2);
        showItem(" Salir ",                     30,13,y==3);


       int key=rlutil::getkey();

       switch(key)
       {
           case 14://UP
              rlutil::locate(28,10+y);
              cout<<" "<<endl;
              y--;
                 if(y<0){
                 y=0;
                 }
              break;
           case 15://DOWN
              rlutil::locate(28,10+y);
              cout<<" "<<endl;
              y++;
                 if(y>3){
                 y=3;
                 }
              break;
           case 1://ENTER
               switch(y)
               {
               case 0://OPCION UN JUGADOr
                   cls();

                     char n[30];


                  recuadro(24,6,35,9,cBLANCO,cNEGRO);///ESTO ES EL RECUADRO PEQUEÑO
                  locate(36,8);
                  cout<<"UN JUGADOR"<<endl;

                  locate(32,10);
                  cout<<"INGRESE SU NOMBRE"<<endl;
                  locate(32,12);
                  cargarCadena(n,29);///OBTIENE NOMBRE DE JUGADOR
                  Jugadores[0].setNombre(n);

                  cls();
                  recuadro(24,6,36,9,cBLANCO,cNEGRO);
                  locate(25,9);
                  cout<<"INGRESE EL NUMERO DE RONDAS A JUGAR"<<endl;
                  locate(30,11);
                  cin>>rondas;
                  cls();

                  cls();
                  recuadro(24,6,36,9,cBLANCO,cNEGRO);
                  locate(27,9);
                  cout<<"CARGAR DADOS MANUALMENTE?"<<endl;
                  locate(27,10);
                  cout<<"1 - SI "<<endl;
                  locate(27,11);
                  cout<<"2 - NO "<<endl;
                  locate(30,13);
                  cin>>Prueba;
                  cls();

                  //antes de empezar cargo el valor de tiradas del segundo jugador con un valor absurdos para no arruinar el calcular ganador, ya que si lo dejo con 0 nunca pasaria el primer if
                  //Jugadores[1].setTiradas(100);


                  Ganador=Iniciar_Juego(1,Jugadores,rondas,Ganador,Prueba);
                  Top1=CalcularTop1(Ganador,Top1);
                  JugadorDisponible=true;
                  pause();

                     break;
               case 1://OPCION 2 JUGADORES
                  cls();

                  char n1[30];
                  char n2[30];


                  recuadro(24,6,40,9,cBLANCO,cNEGRO);///ESTO ES EL RECUADRO PEQUEÑO
                  locate(35,8);
                  cout<<"==DOS JUGADORES=="<<endl;

                  locate(30,10);
                  cout<<"INGRESE NOMBRE DEL JUGADOR 1"<<endl;
                  locate(32,12);
                  cargarCadena(n1,29);///OBTIENE NOMBRE DE JUGADOR
                  Jugadores[0].setNombre(n1);

                  cls();
                  recuadro(24,6,40,9,cBLANCO,cNEGRO);///ESTO ES EL RECUADRO PEQUEÑO
                  locate(35,8);
                  cout<<"==DOS JUGADORES=="<<endl;

                  locate(30,10);
                  cout<<"INGRESE NOMBRE DEL JUGADOR 2"<<endl;
                  locate(32,12);
                  cargarCadena(n2,29);///OBTIENE NOMBRE DE JUGADOR
                  Jugadores[1].setNombre(n2);
                  cls();

                  recuadro(24,6,36,9,cBLANCO,cNEGRO);
                  locate(25,9);
                  cout<<"INGRESE EL NUMERO DE RONDAS A JUGAR"<<endl;
                  locate(30,11);
                  cin>>rondas;
                  cls();


                  recuadro(24,6,36,9,cBLANCO,cNEGRO);
                  locate(27,9);
                  cout<<"CARGAR DADOS MANUALMENTE?"<<endl;
                  locate(27,10);
                  cout<<"1 - SI "<<endl;
                  locate(27,11);
                  cout<<"2 - NO "<<endl;
                  locate(30,13);
                  cin>>Prueba;
                  cls();

                  Ganador=Iniciar_Juego(2,Jugadores,rondas,Ganador,Prueba);
                  Top1=CalcularTop1(Ganador,Top1);
                  JugadorDisponible=true;

                     break;
               case 2://MOSTRAR MAYOR PUNTUACION
                   if(JugadorDisponible==false){
                        cls();
                    recuadro(24,6,40,9,cBLANCO,cNEGRO);///ESTO ES EL RECUADRO PEQUEÑO
                    locate(36,8);
                    cout<<"===SCOREBOARD==="<<endl;
                    locate(28,10);
                    cout<<"LA LISTA DE PUNTUACION ESTA VACIA"<<endl;
                    pause();

                   }
                   else{
                    //locate(36,8);
                    //cout<<"SCOREBOARD"<<endl;
                    //locate(28,10);
                    Top1.Mostrar();
                    pause();
                   }
                     break;
               case 3://OPCION SALIR
                op=0;
                     break;
               }
            break;
       }

       //cout<<"Key: "<<key;

        //rlutil::anykey();
        ///Tecla Arriba:   14
        ///Tecla Abajo:    15
        ///Tecla Izquierda:16
        ///Tecla Derecha:  17

    }while (op!=0);

    return 0;
}
