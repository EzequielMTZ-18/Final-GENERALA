#ifndef DADOS_H_INCLUDED
#define DADOS_H_INCLUDED


using namespace std;
using namespace rlutil;


void showItem(const char* text, int posx, int posy, bool selected);///ESTA ES LA FUNCION UTILIZADA PARA VER QUE OPCION TIENES SELECCIONADA EN EL MENU

void cargarVector(int*,int);///CARGAR DADOS DE PRUEBA

int cargarAleatorio(int*,int,int);///CARGAR DADOS CON NUMEROS ALEATORIOS


void MenuDeDados(int*);///FUNCION LLAMDA PARA IMPRIMIR LOS DADOS EN PANTALLA , ESTA EN ESPECIFICO SE ENCARGA DE IMRPIMIR LOS PUNTOS

///DIBUJA LOS DADOS, PERO SIN LOS PUNTOS DENTRO
void dadouno();///DIBUJA EL DADO 1
void dadoDos();///DIBUJA EL DADO 2
void dadoTres();///DIBUJA EL DADO 3          ///NO ES NECESARIO LLAMARLAS, YA QUE LA FUNCION MENU_DE_DADOS LLAMA A TODAS.
void dadoCuatro();///DIBUJA EL DADO 5
void dadoCinco();///DIBUJA EL DADO 6
int SeleccionarJUG(int  PuntajePosible[][10], int JugadasAnuladas[][10],int jugador);

//int Calc_Puntos(int *dados,int tam,int matriz,int jugador);//NUEVA FUNCION DE CALCULAR PUNTOS

int SeleccionarJUG(int  PuntajePosible[][10], int JugadasAnuladas[][10],int jugador){  ///ESTO ES EL MENU PARA SELECCIONAR QUE JUGADA QUEDARSE, A SU VEZ DENTRO TIENE EL MENU QUE PERMITE ANULAR
                       ///COMBINACIONES
                        ///JUGADAS ANULADAS = 0 (NO ESTA ANULADO), 1 (ESTA ANULADO)

    int CerrarSelec=1;///CERRAR MENU COMBINACIONES
    int CerrarSelec2=1;///CERRAR MENU DE ANULAR
    int puntaje=0;
    int y=0;           ///INDICA POSICION DEL MENU COMBINACIONES
    int y2=0;          ///INDICA POSICION DEL MENU ANULAR
    //int key;           ///TECLA MENU 1
    //int key2;          ///TECLA MENU 2
    hidecursor();


    recuadroVACIO(1,13,40,5,15,cNEGRO);///ESTO PARA LIMPIAR EL COUT DE "QUIERE VOLVER A LANZAR?" PINTA DE COLOR NEGRO BASICAMENTE.
    do{

        setBackgroundColor(rlutil::COLOR::BLACK);
        setColor(rlutil::COLOR::WHITE);
        recuadro(52,1,35,22,cBLANCO,cNEGRO);//ancho era 25
        locate(53,2);
        cout<<" OBTUVO LAS SIGUIENTES "<<endl;
        locate(55,3);
        cout<<"   COMBINACIONES   "<<endl;
        locate(55,4);
        cout<<"-->ESCOJA UNA<--- "<<endl;
        ///--------------------------------------------------
        if(PuntajePosible[jugador-1][0]!=0 && JugadasAnuladas[jugador-1][0]==0){

        showItem("  JUEGO DE 1 ",         56,5,y==0);

        }
        else{
            if(JugadasAnuladas[jugador-1][0]==1){
              showItem(" JUEGO USADO ", 56,5,y==0);
            }
            if(JugadasAnuladas[jugador-1][0]==2){
              showItem(" JUEGO ANULADO ", 56,5,y==0);
            }
            else{
            showItem(" NO HAY JUEGO ", 56,5,y==0);
            }
        }
        ///--------------------------------------------------
        if(PuntajePosible[jugador-1][1]!=0 && JugadasAnuladas[jugador-1][1]==0){

        showItem("  JUEGO DE 2 ",         56,6,y==1);

        }
        else{
            if(JugadasAnuladas[jugador-1][1]==1){
              showItem(" JUEGO USADO ", 56,6,y==1);
            }
            if(JugadasAnuladas[jugador-1][1]==2){
              showItem(" JUEGO ANULADO ", 56,6,y==1);
            }
            else{
            showItem(" NO HAY JUEGO ", 56,6,y==1);
            }
        }

        ///--------------------------------------------------
        if(PuntajePosible[jugador-1][2]!=0 && JugadasAnuladas[jugador-1][2]==0){

        showItem("  JUEGO DE 3 ",         56,7,y==2);


        }
        else{
            if(JugadasAnuladas[jugador-1][2]==1){
              showItem(" JUEGO USADO ", 56,7,y==2);
            }
            if(JugadasAnuladas[jugador-1][2]==2){
              showItem(" JUEGO ANULADO ", 56,7,y==2);
            }
            else{
            showItem(" NO HAY JUEGO ", 56,7,y==2);
            }
        }

        ///----------------------------------------------
        if(PuntajePosible[jugador-1][3]!=0 && JugadasAnuladas[jugador-1][3]==0){

        showItem("  JUEGO DE 4 ",         56,8,y==3);

        }
        else{
                if(JugadasAnuladas[jugador-1][3]==1){
              showItem(" JUEGO USADO ", 56,8,y==3);
            }
            if(JugadasAnuladas[jugador-1][3]==2){
              showItem(" JUEGO ANULADO ", 56,8,y==3);
            }
            else{
            showItem(" NO HAY JUEGO ", 56,8,y==3);
            }
        }
        ///--------------------------------------------------
        if(PuntajePosible[jugador-1][4]!=0 && JugadasAnuladas[jugador-1][4]==0){

        showItem("  JUEGO DE 5 ",         56,9,y==4);

        }
        else{
                if(JugadasAnuladas[jugador-1][4]==1){
              showItem(" JUEGO USADO ", 56,9,y==4);
            }
            if(JugadasAnuladas[jugador-1][4]==2){
              showItem(" JUEGO ANULADO ", 56,9,y==4);
            }
            else{
            showItem(" NO HAY JUEGO ", 56,9,y==4);
            }
        }
        ///--------------------------------------------------
        if(PuntajePosible[jugador-1][5]!=0 && JugadasAnuladas[jugador-1][5]==0){

        showItem("  JUEGO DE 6 ",         56,10,y==5);

        }
        else{
                if(JugadasAnuladas[jugador-1][5]==1){
              showItem(" JUEGO USADO ", 56,10,y==5);
            }
            if(JugadasAnuladas[jugador-1][5]==2){
              showItem(" JUEGO ANULADO ", 56,10,y==5);
            }
            else{
            showItem(" NO HAY JUEGO ", 56,10,y==5);
            }
        }

        ///--------------------------------------------------
        if(PuntajePosible[jugador-1][6]!=0 && JugadasAnuladas[jugador-1][6]==0){

        showItem("  ESCALERA "  ,         56,11,y==6);

        }
        else{
                if(JugadasAnuladas[jugador-1][6]==1){
              showItem(" JUEGO USADO ", 56,11,y==6);
            }
            if(JugadasAnuladas[jugador-1][6]==2){
              showItem(" JUEGO ANULADO ", 56,11,y==6);
            }
            else{
            showItem(" NO HAY JUEGO ", 56,11,y==6);
            }
        }
        ///--------------------------------------------------
        if(PuntajePosible[jugador-1][7]!=0 && JugadasAnuladas[jugador-1][7]==0){

        showItem("  FULL "      ,         56,12,y==7);

        }
        else{
                if(JugadasAnuladas[jugador-1][7]==1){
              showItem(" JUEGO USADO ", 56,12,y==7);
            }
            if(JugadasAnuladas[jugador-1][7]==2){
              showItem(" JUEGO ANULADO ", 56,12,y==7);
            }
            else{
            showItem(" NO HAY JUEGO ", 56,12,y==7);
            }

        }

        ///--------------------------------------------------
        if(PuntajePosible[jugador-1][8]!=0 && JugadasAnuladas[jugador-1][8]==0){

        showItem("  POKER "     ,         56,13,y==8);

        }
        else{
                if(JugadasAnuladas[jugador-1][8]==1){
              showItem(" JUEGO USADO ", 56,13,y==8);
            }
            if(JugadasAnuladas[jugador-1][8]==2){
              showItem(" JUEGO ANULADO ", 56,13,y==8);
            }
            else{
            showItem(" NO HAY JUEGO ", 56,13,y==8);
            }
        }
        ///-----------------------------------------------
        if(PuntajePosible[jugador-1][9]!=0 && JugadasAnuladas[jugador-1][9]==0){

        showItem("  GENERALA  " ,         56,14,y==9);

        }
        else{
                if(JugadasAnuladas[jugador-1][9]==1){
              showItem(" JUEGO USADO ", 56,14,y==9);
            }
            if(JugadasAnuladas[jugador-1][9]==2){
              showItem(" JUEGO ANULADO ", 56,14,y==9);
            }
            else{
            showItem(" NO HAY JUEGO ", 56,14,y==9);
            }
        }
        ///--------------------------------------------------


        showItem("  ANOTAR PUNTAJE 0 "  ,         56,15,y==10);


       int key=getkey();

       switch(key)
       {
           case 14://UP
              rlutil::locate(54,5+y);
              cout<<" "<<endl;
              y--;
                 if(y<0){
                 y=0;
                 }
              break;
           case 15://DOWN
              rlutil::locate(54,5+y);
              cout<<" "<<endl;
              y++;
                 if(y>10){
                 y=10;
                 }
              break;
           case 1://ENTER
               switch(y)
               {
               case 0://JUEGO DE 1
                   if(JugadasAnuladas[jugador-1][0]==0 && PuntajePosible[jugador-1][0]!=0){
                   JugadasAnuladas[jugador-1][0]=1;
                   puntaje=PuntajePosible[jugador-1][0];
                   CerrarSelec=0;
                   }
                   else{
                    locate(56,5);
                    cout<<"Juego anulado o usado";
                    pause();
                   }
                break;
               case 1://JUEGO DE 2
                   if(JugadasAnuladas[jugador-1][1]==0 && PuntajePosible[jugador-1][1]!=0){
                   JugadasAnuladas[jugador-1][1]=1;
                   puntaje=PuntajePosible[jugador-1][1];
                   CerrarSelec=0;

                   }
                   else{
                    locate(56,6);
                    cout<<"Juego anulado o usado";
                    pause();
                   }
                break;
               case 2://JUEGO DE 3
                   if(JugadasAnuladas[jugador-1][2]==0 && PuntajePosible[jugador-1][2]!=0){
                   JugadasAnuladas[jugador-1][2]=1;
                   puntaje=PuntajePosible[jugador-1][2];
                   CerrarSelec=0;

                   }
                   else{
                    locate(56,7);
                    cout<<"Juego anulado o usado";
                    pause();
                   }
                break;
                case 3://JUEGO DE 4
                    if(JugadasAnuladas[jugador-1][3]==0 && PuntajePosible[jugador-1][3]!=0){
                   JugadasAnuladas[jugador-1][3]=1;
                   puntaje=PuntajePosible[jugador-1][3];
                   CerrarSelec=0;

                    }
                    else{
                    locate(56,8);
                    cout<<"Juego anulado o usado";
                    pause();
                   }
                break;
                case 4://JUEGO DE 5
                    if(JugadasAnuladas[jugador-1][4]==0 && PuntajePosible[jugador-1][4]!=0){
                   JugadasAnuladas[jugador-1][4]=1;
                   puntaje=PuntajePosible[jugador-1][4];
                   CerrarSelec=0;

                    }
                    else{
                    locate(56,9);
                    cout<<"Juego anulado o usado";
                    pause();
                   }
                break;
                case 5://JUEGO DE 6
                    if(JugadasAnuladas[jugador-1][5]==0 && PuntajePosible[jugador-1][5]!=0){
                   JugadasAnuladas[jugador-1][5]=1;
                   puntaje=PuntajePosible[jugador-1][5];
                   CerrarSelec=0;

                    }
                    else{
                    locate(56,10);
                    cout<<"Juego anulado o usado";
                    pause();
                   }
                break;
                case 6://ESCALERA
                    if(JugadasAnuladas[jugador-1][6]==0 && PuntajePosible[jugador-1][6]!=0){
                   JugadasAnuladas[jugador-1][6]=1;
                   puntaje=25;
                   CerrarSelec=0;

                    }
                    else{
                    locate(56,11);
                    cout<<"Juego anulado o usado";
                    pause();
                   }
                break;
                case 7://FULL
                    if(JugadasAnuladas[jugador-1][7]==0 && PuntajePosible[jugador-1][7]!=0){
                   JugadasAnuladas[jugador-1][7]=1;
                   puntaje=30;
                   CerrarSelec=0;

                    }
                    else{
                    locate(56,12);
                    cout<<"Juego anulado o usado";
                    pause();
                   }
                break;
                case 8://POKER
                    if(JugadasAnuladas[jugador-1][8]==0 && PuntajePosible[jugador-1][8]!=0){
                   JugadasAnuladas[jugador-1][8]=1;
                   puntaje=40;
                   CerrarSelec=0;

                    }
                    else{
                    locate(56,13);
                    cout<<"Juego anulado o usado";
                    pause();
                   }
                   break;
                case 9://GENERALA
                    if(JugadasAnuladas[jugador-1][9]==0 && PuntajePosible[jugador-1][9]!=0){
                     JugadasAnuladas[jugador-1][9]==1;
                     puntaje=50;
                     CerrarSelec=0;

                    }
                    else{
                    locate(56,14);
                    cout<<"Juego anulado o usado";
                    pause();

                    }
                    break;
                ///---------------------------------------

                case 10://PUNTAJE 0 ANULAR JUGADA
             do{
                recuadro(52,1,35,22,cBLANCO,cNEGRO);
                locate(53,2);
                cout<<" QUE JUGADA DESEA "<<endl;
                locate(55,3);
                cout<<"   TACHAR?   "<<endl;
                locate(55,4);
                cout<<"-->ESCOJA UNA<--- "<<endl;
                showItem(" JUEGO DE 1",                   56,5,y2==0);
                showItem(" JUEGO DE 2",                   56,6,y2==1);
                showItem(" JUEGO DE 3",                   56,7,y2==2);
                showItem(" JUEGO DE 4",                   56,8,y2==3);
                showItem(" JUEGO DE 5",                   56,9,y2==4);
                showItem(" JUEGO DE 6",                   56,10,y2==5);
                showItem(" ESCALERA  ",                   56,11,y2==6);
                showItem(" FULL      ",                   56,12,y2==7);
                showItem(" POKER     ",                   56,13,y2==8);
                showItem(" GENERALA  ",                   56,14,y2==9);


                int key2=getkey();

                switch(key2)
                  {
           case 14://UP
              rlutil::locate(54,5+y2);
              cout<<" "<<endl;
              y2--;
                 if(y2<0){
                 y2=0;
                 }
              break;
           case 15://DOWN
              rlutil::locate(54,5+y2);
              cout<<" "<<endl;
              y2++;
                 if(y2>9){
                 y2=9;
                 }
              break;
           case 1://ENTER
               switch(y2)
               {
               case 0://JUEGO DE 1
                   if(JugadasAnuladas[jugador-1][0]==0){
                   puntaje=0;
                   CerrarSelec2=0;
                   JugadasAnuladas[jugador-1][0]=2;
                   }
                   else{
                    locate(56,5);
                    cout<<"Juego ya anulado o usado";
                    pause();
                   }

                break;
               case 1://JUEGO DE 2
                   if(JugadasAnuladas[jugador-1][1]==0){
                   puntaje=0;
                   CerrarSelec2=0;
                 JugadasAnuladas[jugador-1][1]=1;
                   }
                   else{
                    locate(56,6);
                    cout<<"Juego ya anulado o usado";
                    pause();
                   }
                break;
               case 2://JUEGO DE 3
                   if(JugadasAnuladas[jugador-1][2]==0){
                   puntaje=0;
                   CerrarSelec2=0;
                  JugadasAnuladas[jugador-1][2]=2;
                   }
                   else{
                    locate(56,7);
                    cout<<"Juego ya anulado o usado";
                    pause();
                   }
                break;
                case 3://JUEGO DE 4
                    if(JugadasAnuladas[jugador-1][3]==0){
                    puntaje=0;
                    CerrarSelec2=0;
                    JugadasAnuladas[jugador-1][3]=2;
                    }
                    else{
                    locate(56,8);
                    cout<<"Juego ya anulado o usado";
                    pause();
                   }
                break;
                case 4://JUEGO DE 5
                    if(JugadasAnuladas[jugador-1][4]==0){
                    puntaje=0;
                    CerrarSelec2=0;
                    JugadasAnuladas[jugador-1][4]=2;
                    }
                    else{
                    locate(56,9);
                    cout<<"Juego ya anulado o usado";
                    pause();
                   }
                break;
                case 5://JUEGO DE 6
                    if(JugadasAnuladas[jugador-1][5]==0){
                   puntaje=0;
                   CerrarSelec2=0;
                   JugadasAnuladas[jugador-1][5]=2;
                    }
                    else{
                    locate(56,10);
                    cout<<"Juego ya anulado o usado";
                    pause();
                   }
                break;
                case 6://ESCALERA
                    if(JugadasAnuladas[jugador-1][6]==0){
                   puntaje=0;
                   CerrarSelec2=0;
                   JugadasAnuladas[jugador-1][6]=2;
                    }
                    else{
                    locate(56,11);
                    cout<<"Juego ya anulado o usado";
                    pause();
                   }
                break;
                case 7://FULL
                    if(JugadasAnuladas[jugador-1][7]==0){
                   puntaje=0;
                   CerrarSelec2=0;
                   JugadasAnuladas[jugador-1][7]=2;
                    }
                    else{
                    locate(56,12);
                    cout<<"Juego ya anulado o usado";
                    pause();
                   }
                break;
                case 8://POKER
                    if(JugadasAnuladas[jugador-1][8]==0){
                   puntaje=0;
                   CerrarSelec2=0;
                   JugadasAnuladas[jugador-1][8]=2;
                    }
                    else{
                    locate(56,13);
                    cout<<"Juego ya anulado o usado";
                    pause();
                   }
                case 9://GENERALA
                    if(JugadasAnuladas[jugador-1][9]==0){
                     puntaje=0;
                     CerrarSelec2=0;
                     JugadasAnuladas[jugador-1][9]=2;
                    }
                    else{
                    locate(56,14);
                    cout<<"Juego ya anulado o usado";
                    pause();
                    }
                break;
               }
            }
            }while(CerrarSelec2!=0);
          if(CerrarSelec2==0){
            CerrarSelec=0;
          }
        break;
       }
       }
       //cout<<"Key: "<<key;

        //rlutil::anykey();
        ///Tecla Arriba:   14
        ///Tecla Abajo:    15
        ///Tecla Izquierda:16
        ///Tecla Derecha:  17

    }while (CerrarSelec!=0);

    return puntaje;
}






void MostrarNumDados(int dados[],int Tirada){///FUNCION PARA MOSTRAR NUMERO DEBAJO DE LOS DADOS POR SI EL GRAFICAR DADOS FALLA
     locate(6,9);
     cout<<dados[0]<<endl;
     locate(16,9);
     cout<<dados[1]<<endl;
     locate(26,9);
     cout<<dados[2]<<endl;
     locate(36,9);
     cout<<dados[3]<<endl;
     locate(46,9);
     cout<<dados[4]<<endl;
     //locate(2,11);
     //cout<<"Tirada "<<Tirada<<endl;
}

///FUNCION PARA LANZAR UN DADO INDIVIDUAL A LA HORA DE VOLVER A LANZAR
int DadoIndividual(){
    int lanzamiento;
    lanzamiento = rand() % 6 + 1;
    return lanzamiento;
}



///CARGAR DADO PRUEBA
/*
void cargarVector(int v[], int tam) {
int i;
for (i=0;i<tam;i++){
        recuadro(24,6,35,9,cBLANCO,cNEGRO);///ESTO ES EL RECUADRO PEQUEÑO
        rlutil::locate(27,8);
        cout << "INGRESE NUMERO PARA EL DADO "<<i+1<<endl;
        rlutil::locate(37,11);
        cin >> v[i];
    }
}
*/

int cargarAleatorio(int v[], int tam, int limite){ // CARGA EL DADO CON NUMEROS ALEATORIOS
  int i;
  srand(time(NULL));
  for( i=0; i<tam; i++ ){
        v[i]=(rand()%limite)+1;
  }
  return 1;
}

/*
bool seguirLanzando(int tiro){///SEGUIR LANZANDO DADOS

     char opcion;
     int Cant_Dados;
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
            if(dado<=C_D){
                dados[dado-1] = DadoIndividual();

            }
        }


        seguir = true;
    }
    else{
        seguir=false;
    }
    recuadroVACIO(1,14,50,5,15,cNEGRO);/// HICE ESTA FUNCION PARA LIMPIAR LOS COUTS
    cargarVecRONDA(VecPuntosRONDA,10);
    return seguir;
}
*/








void dadouno() { // la funcion que dibuja al dado en la primera posicion

    // HORIZONTAL
    for (int i = 2; i < 10; i++) {
        locate(i, 3); printf("%c", 205);
        locate(i, 7); printf("%c", 205);
    }
    // VERTICAL
    for (int i = 4; i < 7; i++) {
        locate(2, i); printf("%c", 186);
        locate(10, i); printf("%c", 186);
    }
    ///ESQUINAS
    locate(2, 3); printf("%c", 201);
    locate(2, 7); printf("%c", 200);
    locate(10, 3); printf("%c", 187);
    locate(10, 7); printf("%c", 188);
}

void dadoDos() {// la funcion que dibuja al dado en la segunda posicion

    // HORIZONTAL
    for (int i = 13; i < 20; i++) {
        locate(i, 3); printf("%c", 205);
        locate(i, 7); printf("%c", 205);
    }
    // VERTICAL
    for (int i = 4; i < 7; i++) {
        locate(12, i); printf("%c", 186);
        locate(20, i); printf("%c", 186);
    }
    //ESQUINAS
    locate(12, 3); printf("%c", 201);
    locate(12, 7); printf("%c", 200);
    locate(20, 3); printf("%c", 187);
    locate(20, 7); printf("%c", 188);
}

void dadoTres() {// la funcion que dibuja al dado en la tercera posicion

    // HORIZONTAL
    for (int i = 23; i < 30; i++) {
        locate(i, 3); printf("%c", 205);
        locate(i, 7); printf("%c", 205);
    }
    // VERTICAL
    for (int i = 4; i < 7; i++) {
        locate(22, i); printf("%c", 186);
        locate(30, i); printf("%c", 186);
    }
    //ESQUINAS
    locate(22, 3); printf("%c", 201);
    locate(22, 7); printf("%c", 200);
    locate(30, 3); printf("%c", 187);
    locate(30, 7); printf("%c", 188);
}

void dadoCuatro() {// la funcion que dibuja al dado en la cuarta posicion

    // HORIZONTAL
    for (int i = 32; i < 40; i++) {
        locate(i, 3); printf("%c", 205);
        locate(i, 7); printf("%c", 205);
    }
    // VERTICAL
    for (int i = 4; i < 7; i++) {
        locate(32, i); printf("%c", 186);
        locate(40, i); printf("%c", 186);
    }
    //ESQUINAS
    locate(32, 3); printf("%c", 201);
    locate(32, 7); printf("%c", 200);
    locate(40, 3); printf("%c", 187);
    locate(40, 7); printf("%c", 188);
}

void dadoCinco() {// la funcion que dibuja al dado en la quinta posicion

    // HORIZONTAL
    for (int i = 42; i < 50; i++) {
        locate(i, 3); printf("%c", 205);
        locate(i, 7); printf("%c", 205);
    }
    // VERTICAL
    for (int i = 4; i < 7; i++) {
        locate(42, i); printf("%c", 186);
        locate(50, i); printf("%c", 186);
    }
    //ESQUINAS
    locate(42, 3); printf("%c", 201);
    locate(42, 7); printf("%c", 200);
    locate(50, 3); printf("%c", 187);
    locate(50, 7); printf("%c", 188);
}


void MenuDeDados(int dados[]) {    // dibuja los dados respecto a los valores que se le entreguen en las distintas posiciones
    int i;                          //DIBUJA LOS PUNTOS
    dadouno(); dadoDos(); dadoTres(); dadoCuatro(); dadoCinco();
    for (i = 0; i <5; i++) {
        switch (dados[i]) {
        /*dado 1*/ case 1:
            if (i == 0) { locate(6, 5); printf("%c", 254); }
            if (i == 1) { locate(16, 5); printf("%c", 254); }
            if (i == 2) { locate(26, 5); printf("%c", 254); }
            if (i == 3) { locate(36, 5); printf("%c", 254); }
            if (i == 4) { locate(46, 5); printf("%c", 254); }

            ; break;

        /*dado 2*/ case 2:
            if (i == 0) {
                locate(4, 4); printf("%c", 254);
                locate(8, 6); printf("%c", 254);
            }

            if (i == 1) {
                locate(14, 4); printf("%c", 254);
                locate(18, 6); printf("%c", 254);
            }
            if (i == 2) {
                locate(24, 4); printf("%c", 254);
                locate(28, 6); printf("%c", 254);
            }
            if (i == 3) {
                locate(34, 4); printf("%c", 254);
                locate(38, 6); printf("%c", 254);
            }
            if (i == 4) {
                locate(44, 4); printf("%c", 254);
                locate(48, 6); printf("%c", 254);
            }

            ; break;
        /*dado 3*/  case 3:
            if (i == 0) {
                locate(6, 5); printf("%c", 254);
                locate(8, 4); printf("%c", 254);
                locate(4, 6); printf("%c", 254);
            }

            if (i == 1) {
                locate(16, 5); printf("%c", 254);
                locate(18, 4); printf("%c", 254);
                locate(14, 6); printf("%c", 254);
            }

            if (i == 2) {
                locate(26, 5); printf("%c", 254);
                locate(28, 4); printf("%c", 254);
                locate(24, 6); printf("%c", 254);
            }

            if (i == 3) {
                locate(36, 5); printf("%c", 254);
                locate(38, 4); printf("%c", 254);
                locate(34, 6); printf("%c", 254);
            }

            if (i == 4) {
                locate(46, 5); printf("%c", 254);
                locate(48, 4); printf("%c", 254);
                locate(44, 6); printf("%c", 254);
            }

            ; break;

        /*dado 4*/ case 4:
            if (i == 0) {
                locate(4, 4); printf("%c", 254);
                locate(4, 6); printf("%c", 254);
                locate(8, 4); printf("%c", 254);
                locate(8, 6); printf("%c", 254);
            }

            if (i == 1) {
                locate(14, 4); printf("%c", 254);

                locate(14, 6); printf("%c", 254);
                locate(18, 4); printf("%c", 254);
                locate(18, 6); printf("%c", 254);
            }

            if (i == 2)

            {
                locate(24, 4); printf("%c", 254);
                locate(24, 6); printf("%c", 254);
                locate(28, 4); printf("%c", 254);
                locate(28, 6); printf("%c", 254);
            }


            if (i == 3)

            {
                locate(34, 4); printf("%c", 254);
                locate(34, 6); printf("%c", 254);
                locate(38, 4); printf("%c", 254);
                locate(38, 6); printf("%c", 254);
            }
            if (i == 4) {
                locate(44, 4); printf("%c", 254);
                locate(44, 6); printf("%c", 254);
                locate(48, 4); printf("%c", 254);
                locate(48, 6); printf("%c", 254);
            }

            break;

        /*dado 5*/ case 5:
            if (i == 0)
            {
                locate(4, 4); printf("%c", 254);
                locate(4, 6); printf("%c", 254);
                locate(8, 4); printf("%c", 254);
                locate(6, 5); printf("%c", 254);
                locate(8, 6); printf("%c", 254);
            }
            if (i == 1)
            {
                locate(14, 4); printf("%c", 254);
                locate(14, 6); printf("%c", 254);
                locate(18, 4); printf("%c", 254);
                locate(16, 5); printf("%c", 254);
                locate(18, 6); printf("%c", 254);
            }
            if (i == 2)
            {
                locate(24, 4); printf("%c", 254);
                locate(24, 6); printf("%c", 254);
                locate(28, 4); printf("%c", 254);
                locate(26, 5); printf("%c", 254);
                locate(28, 6); printf("%c", 254);
            }
            if (i == 3) {
                locate(34, 4); printf("%c", 254);
                locate(34, 6); printf("%c", 254);
                locate(38, 4); printf("%c", 254);
                locate(36, 5); printf("%c", 254);
                locate(38, 6); printf("%c", 254);
            }
            if (i == 4)
            {
                locate(44, 4); printf("%c", 254);
                locate(44, 6); printf("%c", 254);
                locate(48, 4); printf("%c", 254);
                locate(46, 5); printf("%c", 254);
                locate(48, 6); printf("%c", 254);
            }

            break;

        /*dado 6*/  case 6:
            if (i == 0) {
                locate(4, 4); printf("%c", 254);
                locate(4, 6); printf("%c", 254);
                locate(8, 4); printf("%c", 254);
                locate(4, 5); printf("%c", 254);
                locate(8, 5); printf("%c", 254);
                locate(8, 6); printf("%c", 254);
            }
            if (i == 1) {
                locate(14, 4); printf("%c", 254);
                locate(14, 6); printf("%c", 254);
                locate(18, 4); printf("%c", 254);
                locate(14, 5); printf("%c", 254);
                locate(18, 5); printf("%c", 254);
                locate(18, 6); printf("%c", 254);
            }
            if (i == 2) {
                locate(24, 4); printf("%c", 254);
                locate(24, 6); printf("%c", 254);
                locate(28, 4); printf("%c", 254);
                locate(24, 5); printf("%c", 254);
                locate(28, 5); printf("%c", 254);
                locate(28, 6); printf("%c", 254);
            }
            if (i == 3) {
                locate(34, 4); printf("%c", 254);
                locate(34, 6); printf("%c", 254);
                locate(38, 4); printf("%c", 254);
                locate(34, 5); printf("%c", 254);
                locate(38, 5); printf("%c", 254);
                locate(38, 6); printf("%c", 254);
            }
            if (i == 4) {
                locate(44, 4); printf("%c", 254);
                locate(44, 6); printf("%c", 254);
                locate(48, 4); printf("%c", 254);
                locate(44, 5); printf("%c", 254);
                locate(48, 5); printf("%c", 254);
                locate(48, 6); printf("%c", 254);
            }
            break;
        }
    }
}
#endif // DADOS_H_INCLUDED
