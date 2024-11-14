#ifndef INICIAR_PARTIDA_H_INCLUDED
#define INICIAR_PARTIDA_H_INCLUDED



void cargarCadena(char *pal, int tam){
  int i;
  fflush(stdin);
  for(i=0;i<tam;i++){
      pal[i]=cin.get();
	  if(pal[i]=='\n') break;
	  }
  pal[i]='\0';
  fflush(stdin);
}


void cargarDados(int v[], int tam) {
int i;
for (i=0;i<tam;i++){
        recuadro(24,6,35,9,cBLANCO,cNEGRO);///ESTO ES EL RECUADRO PEQUEÑO
        rlutil::locate(27,8);
        cout << "INGRESE NUMERO PARA EL DADO "<<i+1<<endl;
        rlutil::locate(37,11);
        cin >> v[i];
    }
}

class Jugador{
private:
    char nombre[30];
    int puntaje;
    int rondas;
    int tiradas;
public:

    Jugador(const char *n="Player",int p=0,int r=0,int t=0){///constructor
        strcpy_s(nombre,n);
        puntaje=p;
        rondas=r;
        tiradas=t;
        }
    //gets
    const char *getNombre(){return nombre;}
    int getPuntaje(){return puntaje;}
    int getRondas(){return rondas;}
    int getTiradas(){return tiradas;}
    //sets
    void setNombre(const char *n){strcpy_s(nombre,n);}
    void setPuntaje(int p){puntaje=p;}
    void setRondas(int r){rondas=r;}
    void setTiradas(int t){tiradas=t;}

    void Mostrar(){
    cls();
    recuadro(24,6,40,9,cBLANCO,cNEGRO);
    locate(36,8);
    cout<<"===SCOREBOARD==="<<endl;
    locate(30,10);
    cout<<"JUGADOR: "<<nombre<<endl;
    locate(30,11);
    cout<<"PUNTAJE OBTENIDO: "<<puntaje<<endl;
    locate(30,12);
    cout<<"TOTAL DE TIRADAS: "<<tiradas<<endl;
    locate(30,13);
    cout<<"RONDAS JUGADAS: "<<rondas<<endl;


    }
};

//Jugador CalcularGanador(Jugador jugadores[],Jugador top1);
Jugador CalcularTop1(Jugador Ganador, Jugador top1);


bool seguirLanzando(int tiro, int *dados){///SEGUIR LANZANDO DADOS

     char opcion;
     int Cant_Dados=5;
     int dado;
     bool seguir; //VARIABLE PARA MARCAR SI SE UTILIZO EL LANZAMIENTO

     ///locate(2,11);
     ///cout<<"Tirada "<<tiro-1<<endl;

     locate(2,13);
     cout<<"Desea seguir lanzando? S/N : "<<endl;
     locate(30,13);
     cin>>opcion;

    if(opcion=='S'||opcion=='s'){
        locate(2,14);
        cout<<"Cuantos dados?(hasta 5): ";
        locate(27,14);
        cin>>Cant_Dados;

        for(int i=0;i<Cant_Dados;i++){  //SE LANZA LA CANTIDAD DE DADOS QUE DECIDE EL USUARIO
            locate(2,15);
            cout<<"Elija el dado a lanzar (Del 1 al 5): ";
            locate(38,15);
            cin>>dado;
            if(dado<=5){
                dados[dado-1] = DadoIndividual();

            }
        }


        seguir = true;
    }
    else{
        seguir=false;
    }
    recuadroVACIO(1,14,50,5,15,cNEGRO);/// HICE ESTA FUNCION PARA LIMPIAR LOS COUTS

    return seguir;
}


Jugador Iniciar_Juego(int cantidad, Jugador jugadores[], int rondas, Jugador Top1,int Prueba){

    int Puntos[2]={0}; ///puntaje de cada jugador
    int dados[5];
    int reroll[5];
    int Combinaciones[2][10];
    int Comb_Usadas[2][10]; ///0 SIGNIFICA QUE NO FUE USADA, 1 SIGNIFICA QUE LO FUE
    cargarMatriz(Combinaciones,2,10);
    cargarMatriz(Comb_Usadas,2,10);

    int PuntajeRonda=0;
    int ContadorTiradas=0;
    //int ContadorTiradas2=0;
    bool continuar=true;
    bool GeneralaServida=false;
    Jugador Gano;
    //bool Turno=false;




  if(cantidad==1){
        recuadro(1,1,79,25,cBLANCO,cNEGRO);///ESTO SIMPLEMENTE ES EL RECUADRO
        locate(12,12);
        cout<<"MUY BIEN "<<jugadores[0].getNombre()<<", TOCA CUALQUIER TECLA PARA REALIZAR";
        locate(30,13);
        cout<<"TU PRIMER LANZAMIENTO";



        pause();
        cls();



        for(int i=0;i<rondas;i++){
                 cls();
                 int Tirada=1;
                 ContadorTiradas+=Tirada;
                 if(Prueba==1){
                    cargarDados(dados,5);
                 }
                 else{
                 cargarAleatorio(dados,5,6);
                 }
                 do{
                 cls();
                 rlutil::locate(2,2);
                 cout<<"Turno de "<<jugadores[0].getNombre()<<(char)186<<" Ronda "<<i+1<<(char)186<<" Puntaje Total "<<Puntos[0];
                 locate(1,11);
                 cout<<(char)186<<" Tirada: "<<Tirada;
                 locate(13,11);
                 cout<<(char)186<<" Tiradas totales: "<<ContadorTiradas;

                 MenuDeDados(dados);
                 MostrarNumDados(dados,5);

                 continuar = seguirLanzando(Tirada,dados);//LLAMA A LA FUNCION QUE HACE LOS LANZAMIENTOS EXTRAS
                 if(continuar==true){
                 Tirada++;
                 ContadorTiradas++;
                 cls();
                 rlutil::locate(2,2);
                 cout<<"Turno de "<<jugadores[0].getNombre()<<(char)186<<" Ronda "<<i+1<<(char)186<<" Puntaje Total "<<Puntos[0];
                 locate(1,11);
                 cout<<(char)186<<" Tirada: "<<Tirada;
                 locate(13,11);
                 cout<<(char)186<<" Tiradas totales: "<<ContadorTiradas;

                 MenuDeDados(dados);
                 MostrarNumDados(dados,5);
                 }

                }while(continuar&&Tirada<3);//MIENTRAS CONTINUAR SEA VERDADERO Y TIRADA NO LLEGO AL MAXIMO PERMITIDO

                Calc_Puntos(dados,Combinaciones,1);

                if(Combinaciones[0][9]==50 && Tirada==1){

                 cls();
                 locate(30,5);
                 cout<<"GENERALA SERVIDA!"<<endl;
                 GeneralaServida=true;
                 Puntos[0]=50;
                 locate(30,7);
                 continuar=false;
                 i=rondas;
                 cout<<"PUNTAJE DE RONDA "<<Puntos[0]<<endl;
                 pause();

                }

        if(GeneralaServida==false){           //SI NO HUBO GENERALA SERVIDA

        PuntajeRonda=SeleccionarJUG(Combinaciones,Comb_Usadas,1);//el 1 del final indica el jugador
        Puntos[0]+=PuntajeRonda;

        recuadroVACIO(52,1,35,22,15,cNEGRO); //FUNCION PARA LIMPIAR EL PUNTAJE DE TIRADA Y JUGADA / SELECCIONAR JUGADA
        locate(55,3);
        cout<<"PUNTAJE DE RONDA "<<PuntajeRonda<<endl;
        pause();

    }

  }
  cls();
  locate(10,10);
  cout<<"PUNTAJE FINAL DE LA PARTIDA: "<<Puntos[0]<<endl;
  pause();
  int total=Puntos[0];
  jugadores[0].setPuntaje(total);
  jugadores[0].setRondas(rondas);
  jugadores[0].setTiradas(ContadorTiradas);


  Gano.setNombre(jugadores[0].getNombre());
  Gano.setPuntaje(jugadores[0].getPuntaje());
  Gano.setTiradas(jugadores[0].getTiradas());
  Gano.setRondas(jugadores[0].getRondas());

  ///calcular top 1 puntaje etc
  //Gano=CalcularGanador(jugadores,Top1);
  return Gano;

 }///fin 1 jugador

///2 jugadores aca

 if(cantidad==2){
    cls();

    bool Turno=false;//false corresponde al p1, true al p2

    ///Tiradas del jugador 1 + contador + bandera por si saco generala servida
    int TiradaP1=0;
    int ContadorT_P1=0;
    bool G_ServidaP1=false;
    int P_RondaP1=0;//puntaje de ronda player 1
    bool continuarP1=false;


    ///Tiradas del jugador 2 + contador + bandera por si saco generala servida
    int TiradaP2=0;
    int ContadorT_P2=0;
    bool G_ServidaP2=false;
    int P_RondaP2=0;//puntaje de ronda player 2
    bool continuarP2=false;

    //cout<<jugadores[0].getNombre()<<endl;
    //cout<<jugadores[1].getNombre()<<endl;
    for(int i=0;i<rondas;i++){


        if(Turno==false){///turno jugador 1
                    G_ServidaP1=false;
        recuadro(1,1,79,25,cBLANCO,cNEGRO);
        locate(30,11);
        cout<<"RONDA: "<<i+1;
        locate(12,12);
        cout<<"TURNO DE "<<jugadores[0].getNombre()<<", TOCA CUALQUIER TECLA PARA REALIZAR";
        locate(30,13);
        cout<<"TU PRIMER LANZAMIENTO";
        pause();

        cls();

                 TiradaP1=1;
                 ContadorT_P1+=TiradaP1;
                 if(Prueba==1){
                    cargarDados(dados,5);
                 }
                 else{
                 cargarAleatorio(dados,5,6);
                 }
                 //cargarAleatorio(dados,5,6);
                 do{
                 cls();
                 rlutil::locate(2,2);
                 cout<<"Turno de "<<jugadores[0].getNombre()<<(char)186<<" Ronda "<<i+1<<(char)186<<" Puntaje Total "<<Puntos[0];
                 locate(1,11);
                 cout<<(char)186<<" Tirada: "<<TiradaP1;
                 locate(13,11);
                 cout<<(char)186<<" Tiradas totales: "<<ContadorT_P1;

                 MenuDeDados(dados);
                 MostrarNumDados(dados,5);

                 continuarP1 = seguirLanzando(TiradaP1,dados);//LLAMA A LA FUNCION QUE HACE LOS LANZAMIENTOS EXTRAS
                  if(continuarP1==true){
                 TiradaP1++;
                 ContadorT_P1++;
                 cls();
                 rlutil::locate(2,2);
                 cout<<"Turno de "<<jugadores[0].getNombre()<<(char)186<<" Ronda "<<i+1<<(char)186<<" Puntaje Total "<<Puntos[0];
                 locate(1,11);
                 cout<<(char)186<<" Tirada: "<<TiradaP1;
                 locate(13,11);
                 cout<<(char)186<<" Tiradas totales: "<<ContadorT_P1;

                 MenuDeDados(dados);
                 MostrarNumDados(dados,5);
                  }

                 }while(continuarP1&&TiradaP1<3);//MIENTRAS CONTINUAR SEA VERDADERO Y TIRADA NO LLEGO AL MAXIMO PERMITIDO

                 Calc_Puntos(dados,Combinaciones,1);//el numero del final indica jugador


                  P_RondaP1=SeleccionarJUG(Combinaciones,Comb_Usadas,1);//el 1 del final indica el jugador y el 2 el rival
                  Puntos[0]+=P_RondaP1;

                 if(Combinaciones[0][9]==50 && TiradaP1==1){

                 cls();
                 locate(30,5);
                 cout<<"GENERALA SERVIDA!"<<endl;
                 G_ServidaP1=true;
                 Puntos[0]=50;
                 locate(30,7);
                 continuar=false;
                 Turno=true;
                 cout<<"PUNTAJE DE RONDA "<<Puntos[0]<<endl;
                 pause();

                }

                 if(G_ServidaP1==false){           //SI NO HUBO GENERALA SERVIDA

            //P_RondaP1=SeleccionarJUG(Combinaciones,Comb_Usadas,1);//el 1 del final indica el jugador y el 2 el rival
            //Puntos[0]+=P_RondaP1;

            recuadroVACIO(52,1,35,22,15,cNEGRO); //FUNCION PARA LIMPIAR LA VENTANA PUNTAJE DE TIRADA Y JUGADA / SELECCIONAR JUGADA
            locate(55,3);
            cout<<"PUNTAJE DE RONDA "<<P_RondaP1<<endl;
            Turno=true;///Turno true para que siga con el jugador 2
            pause();
            cls();
        }
        }
        ///fin turno jugador 1


        ///Inicio turno jugador 2
        if(Turno==true){
                G_ServidaP2=false;
                if(G_ServidaP1==true){
                    cls();
                    locate(25,11);
                    cout<<"EL JUGADOR 2 TNDRA UN LANZAMIENTO PARA VER SI OBTIENE "<<endl;
                    locate(27,12);
                    cout<<" GENERALA SERVIDA COMO EL JUGADOR 1 "<<endl;
                    pause();
                    cls();
                    recuadro(1,1,79,25,cBLANCO,cNEGRO);
                    locate(30,11);
                    cout<<"RONDA: "<<i+1;
                    locate(12,12);
                    cout<<"TURNO DE "<<jugadores[1].getNombre()<<", TOCA CUALQUIER TECLA PARA REALIZAR";
                    locate(30,13);
                    cout<<"EL LANZAMIENTO";
                    TiradaP2=1;
                    ContadorT_P2+=TiradaP2;
                    pause();
                    cls();
                    if(Prueba==1){
                    cargarDados(dados,5);
                    }
                    else{
                    cargarAleatorio(dados,5,6);
                    }
                    cls();
                    MenuDeDados(dados);
                    MostrarNumDados(dados,5);
                    Calc_Puntos(dados,Combinaciones,2);

                    P_RondaP2=SeleccionarJUG(Combinaciones,Comb_Usadas,2);//el 2 del final indica el jugador
                    Puntos[1]+=P_RondaP2;

                    if(Combinaciones[1][9]==50 && TiradaP2==1){

                        cls();
                        locate(30,5);
                        cout<<"GENERALA SERVIDA!"<<endl;
                        G_ServidaP2=true;
                        Puntos[1]=50;
                        locate(30,7);
                        continuar=false;
                        cout<<"PUNTAJE DE RONDA "<<Puntos[1]<<endl;
                        pause();
                        }
                    else{
                        cls();
                        locate(30,15);
                        cout<<"FIN DEL JUEGO"<<endl;

                    }
                            pause();
                    }
            else{
            recuadro(1,1,79,25,cBLANCO,cNEGRO);
            locate(30,11);
            cout<<"RONDA: "<<i+1;
            locate(12,12);
            cout<<"TURNO DE "<<jugadores[1].getNombre()<<", TOCA CUALQUIER TECLA PARA REALIZAR";
            locate(30,13);
            cout<<"TU PRIMER LANZAMIENTO";
            pause();
            cls();

                 TiradaP2=1;
                 ContadorT_P2+=TiradaP2;
                 if(Prueba==1){
                    cargarDados(dados,5);
                 }
                 else{
                 cargarAleatorio(dados,5,6);
                 }
                 //cargarAleatorio(dados,5,6);
                 do{
                 cls();
                 rlutil::locate(2,2);
                 cout<<"Turno de "<<jugadores[1].getNombre()<<(char)186<<" Ronda "<<i+1<<(char)186<<" Puntaje Total "<<Puntos[1];
                 locate(1,11);
                 cout<<(char)186<<" Tirada: "<<TiradaP2;
                 locate(13,11);
                 cout<<(char)186<<" Tiradas totales: "<<ContadorT_P2;

                 MenuDeDados(dados);
                 MostrarNumDados(dados,5);

                 continuarP2 = seguirLanzando(TiradaP2,dados);//LLAMA A LA FUNCION QUE HACE LOS LANZAMIENTOS EXTRAS
                  if(continuarP2==true){
                 TiradaP2++;
                 ContadorT_P2++;
                 cls();
                 rlutil::locate(2,2);
                 cout<<"Turno de "<<jugadores[1].getNombre()<<(char)186<<" Ronda "<<i+1<<(char)186<<" Puntaje Total "<<Puntos[1];
                 locate(1,11);
                 cout<<(char)186<<" Tirada: "<<TiradaP2;
                 locate(13,11);
                 cout<<(char)186<<" Tiradas totales: "<<ContadorT_P2;

                 MenuDeDados(dados);
                 MostrarNumDados(dados,5);
                  }

                 }while(continuarP2&&TiradaP2<3);//MIENTRAS CONTINUAR SEA VERDADERO Y TIRADA NO LLEGO AL MAXIMO PERMITIDO

                 Calc_Puntos(dados,Combinaciones,2);///el numero del final indica jugador

                 if(Combinaciones[1][9]==50 && TiradaP2==1){

                 cls();
                 locate(52,5);
                 cout<<"GENERALA SERVIDA!"<<endl;
                 G_ServidaP2=true;
                 Puntos[1]=50;
                 locate(55,3);
                 continuar=false;
                 cout<<"PUNTAJE DE RONDA "<<Puntos[1]<<endl;
                 pause();

                }

                 if(G_ServidaP2==false){           //SI NO HUBO GENERALA SERVIDA

            P_RondaP2=SeleccionarJUG(Combinaciones,Comb_Usadas,2);//el 2 del final indica el jugador
            Puntos[1]+=P_RondaP2;

            recuadroVACIO(52,1,35,22,15,cNEGRO); //FUNCION PARA LIMPIAR LA VENTANA PUNTAJE DE TIRADA Y JUGADA / SELECCIONAR JUGADA
            locate(55,3);
            cout<<"PUNTAJE DE RONDA "<<P_RondaP2<<endl;
            Turno=false;///Turno false para que siga con el jugador 1
            pause();
            cls();

            }
        }
        if(G_ServidaP1==true && G_ServidaP2==false){
            cls();
            locate(20,10);
            cout<<"El jugador: "<<jugadores[0].getNombre()<<" GANA CON GENERALA SERVIDA! "<<endl;
                        Gano.setNombre(jugadores[0].getNombre());
                        Gano.setPuntaje(jugadores[0].getPuntaje());
                        Gano.setTiradas(jugadores[0].getTiradas());
                        Gano.setRondas(jugadores[0].getRondas());
                        pause();
                        return Gano;
        }
        if(G_ServidaP1==false && G_ServidaP2==true){
            cls();
            locate(20,10);
            cout<<"El jugador: "<<jugadores[1].getNombre()<<" GANA CON GENERALA SERVIDA! "<<endl;
                        Gano.setNombre(jugadores[1].getNombre());
                        Gano.setPuntaje(jugadores[1].getPuntaje());
                        Gano.setTiradas(jugadores[1].getTiradas());
                        Gano.setRondas(jugadores[1].getRondas());
                        pause();
                        return Gano;
        }
        if(G_ServidaP1==true && G_ServidaP2==true){
            G_ServidaP1=false;
            G_ServidaP2=false;
            Turno=false;
        }
        }
        }///===FIN DE EJECUCION DE RONDAS===
        cls();


        int totalP1=Puntos[0];///Puntaje total del jugador 1
        jugadores[0].setPuntaje(totalP1);
        jugadores[0].setRondas(rondas);
        jugadores[0].setTiradas(ContadorT_P1);

        int totalP2=Puntos[1];///Puntaje total
        jugadores[1].setPuntaje(totalP2);
        jugadores[1].setRondas(rondas);
        jugadores[1].setTiradas(ContadorT_P2);
        ///calcular ganador puntaje etc

            locate(20,10);
            cout<<"PUNTAJE FINAL DE "<<jugadores[0].getNombre() <<" = " <<totalP1<<endl;
            locate(20,12);
            cout<<"PUNTAJE FINAL DE "<<jugadores[1].getNombre() <<" = " <<totalP2<<endl;
            pause();

        if(jugadores[0].getTiradas()<jugadores[1].getTiradas() && jugadores[0].getPuntaje()>jugadores[1].getPuntaje()){
                        cls();
                        locate(20,10);
                        cout<<"GANADOR DE LA PARTIDA: "<<jugadores[0].getNombre();
                        locate(20,11);
                        cout<<"CON UN PUNTAJE DE: "<<jugadores[0].getPuntaje();
                        locate(20,12);
                        cout<<"TIROS REALIZADOS: "<<jugadores[0].getTiradas();

                        Gano.setNombre(jugadores[0].getNombre());
                        Gano.setPuntaje(jugadores[0].getPuntaje());
                        Gano.setTiradas(jugadores[0].getTiradas());
                        Gano.setRondas(jugadores[0].getRondas());
                        pause();

        }
         if(jugadores[1].getTiradas()<jugadores[0].getTiradas() && jugadores[1].getPuntaje()>jugadores[0].getPuntaje()){
                        cls();
                        locate(20,10);
                        cout<<"GANADOR DE LA PARTIDA: "<<jugadores[1].getNombre();
                        locate(20,11);
                        cout<<"CON UN PUNTAJE DE: "<<jugadores[1].getPuntaje();
                        locate(20,12);
                        cout<<"TIROS REALIZADOS: "<<jugadores[1].getTiradas();

                        Gano.setNombre(jugadores[1].getNombre());
                        Gano.setPuntaje(jugadores[1].getPuntaje());
                        Gano.setTiradas(jugadores[1].getTiradas());
                        Gano.setRondas(jugadores[1].getRondas());
                        pause();

        }
        if(jugadores[0].getTiradas()==jugadores[1].getTiradas()){
                    if(jugadores[0].getPuntaje()>jugadores[1].getPuntaje()){
                        cls();
                        locate(20,10);
                        cout<<"GANADOR DE LA PARTIDA: "<<jugadores[0].getNombre();
                        locate(20,11);
                        cout<<"CON UN PUNTAJE DE: "<<jugadores[0].getPuntaje();
                        locate(20,12);
                        cout<<"TIROS REALIZADOS: "<<jugadores[0].getTiradas();

                        Gano.setNombre(jugadores[0].getNombre());
                        Gano.setPuntaje(jugadores[0].getPuntaje());
                        Gano.setTiradas(jugadores[0].getTiradas());
                        Gano.setRondas(jugadores[0].getRondas());
                        pause();


                    }
                    else{
                        cls();
                        locate(20,10);
                        cout<<"GANADOR DE LA PARTIDA: "<<jugadores[1].getNombre();
                        locate(20,11);
                        cout<<"CON UN PUNTAJE DE: "<<jugadores[1].getPuntaje();
                        locate(20,12);
                        cout<<"TIROS REALIZADOS: "<<jugadores[1].getTiradas();

                        Gano.setNombre(jugadores[1].getNombre());
                        Gano.setPuntaje(jugadores[1].getPuntaje());
                        Gano.setTiradas(jugadores[1].getTiradas());
                        Gano.setRondas(jugadores[1].getRondas());

                        pause();
                    }

        }
        //Gano=CalcularGanador(jugadores,Top1);//EN REALIDAD CALCULA SI SUPERO AL TOP 1
        //pause();
        return Gano;

    }
 }




/*
Jugador CalcularGanador(Jugador jugadores[],Jugador top1){
    Jugador Ganador;
   if(jugadores[0].getPuntaje()>jugadores[1].getPuntaje() && jugadores[0].getTiradas()<jugadores[1].getTiradas()){
      //si el puntaje del jugador 1 es mayor al del jugador 2 y lo obtuvo con menos tiradas
      //se pregunta si supera al top 1
      //cls();
      //cout<<"Paso por el primer if"<<endl;


            if(jugadores[0].getTiradas()==top1.getTiradas()){  ///POR SI EMPATA EN TIRADAS CON EL TOP1
            if(jugadores[0].getPuntaje()>top1.getPuntaje()){
                Ganador.setNombre(jugadores[0].getNombre());
                Ganador.setPuntaje(jugadores[0].getPuntaje());
                Ganador.setTiradas(jugadores[0].getTiradas());
                Ganador.setRondas(jugadores[0].getRondas());
                cls();
                recuadro(24,6,40,4,cBLANCO,cNEGRO);
                locate(35,8);
                cout<<"===NUEVO RECORD==="<<endl;
                pause();
                return Ganador;
            }
        }

      if(jugadores[0].getPuntaje()>top1.getPuntaje() && jugadores[0].getTiradas()<top1.getTiradas()){
        //cout<<"paso por el segundo if"<<endl;

        Ganador.setNombre(jugadores[0].getNombre());
        Ganador.setPuntaje(jugadores[0].getPuntaje());
        Ganador.setTiradas(jugadores[0].getTiradas());
        Ganador.setRondas(jugadores[0].getRondas());
        cls();
        recuadro(24,6,40,4,cBLANCO,cNEGRO);
        locate(35,8);
        cout<<"===NUEVO RECORD==="<<endl;
        pause();
        return Ganador;
      }


      return top1;
   }
   else{
        //cls();
        //cout<<"paso por el tercer if"<<endl;


            if(jugadores[1].getTiradas()==top1.getTiradas()){ ///POR SI EMPATA EN TIRADAS CON EL TOP1
            if(jugadores[1].getPuntaje()>top1.getPuntaje()){
                Ganador.setNombre(jugadores[1].getNombre());
                Ganador.setPuntaje(jugadores[1].getPuntaje());
                Ganador.setTiradas(jugadores[1].getTiradas());
                Ganador.setRondas(jugadores[1].getRondas());
                cls();
                recuadro(24,6,40,4,cBLANCO,cNEGRO);
                locate(35,8);
                cout<<"===NUEVO RECORD==="<<endl;
                pause();
                return Ganador;
            }
        }

      if(jugadores[1].getPuntaje()>top1.getPuntaje() && jugadores[1].getTiradas()<top1.getTiradas()){
            //cout<<"paso por el cuarto if"<<endl;

        Ganador.setNombre(jugadores[1].getNombre());
        Ganador.setPuntaje(jugadores[1].getPuntaje());
        Ganador.setTiradas(jugadores[1].getTiradas());
        Ganador.setRondas(jugadores[1].getRondas());
        cls();
        recuadro(24,6,40,4,cBLANCO,cNEGRO);
        locate(35,8);
        cout<<"===NUEVO RECORD==="<<endl;
        pause();
        return Ganador;
      }



      return top1;
   }



}
*/

Jugador CalcularTop1(Jugador Ganador, Jugador top1){

    if(Ganador.getPuntaje()>top1.getPuntaje() && Ganador.getTiradas()<top1.getTiradas()){
        //cout<<"paso por el segundo if"<<endl;

        top1.setNombre(Ganador.getNombre());
        top1.setPuntaje(Ganador.getPuntaje());
        top1.setTiradas(Ganador.getTiradas());
        top1.setRondas(Ganador.getRondas());
        cls();
        recuadro(24,6,40,4,cBLANCO,cNEGRO);
        locate(35,8);
        cout<<"===NUEVO RECORD==="<<endl;
        pause();
        return top1;
      }
    if(Ganador.getTiradas()==top1.getTiradas()){  ///POR SI EMPATA EN TIRADAS CON EL TOP1
            if(Ganador.getPuntaje()>top1.getPuntaje()){
                top1.setNombre(Ganador.getNombre());
                top1.setPuntaje(Ganador.getPuntaje());
                top1.setTiradas(Ganador.getTiradas());
                top1.setRondas(Ganador.getRondas());
                cls();
                recuadro(24,6,40,4,cBLANCO,cNEGRO);
                locate(35,8);
                cout<<"===NUEVO RECORD==="<<endl;
                pause();
                return top1;
            }
            return top1;
        }
    return top1;

}
#endif // INICIAR_PARTIDA_H_INCLUDED
