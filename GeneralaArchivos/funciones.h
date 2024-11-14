#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include <windows.h>
using namespace std;

int JuegoDe1(int *dados,int tam);
int JuegoDe2(int *dados,int tam);
int JuegoDe3(int *dados,int tam);
int JuegoDe4(int *dados,int tam);
int JuegoDe5(int *dados,int tam);
int JuegoDe6(int *dados,int tam);
int Escalera(int *dados,int tam);
int Full(int *dados,int tam);
int Poker(int *dados,int tam);
int Generala(int *dados,int tam);





///CUENTA LAS VECES Q APARECE UN NUMERO EN EL VECTOR DE DADOS.
int repetido(int n,int *dados){
    int repetido=0;
    for(int j=0;j<5;j++){ //RECORRE CADA INDICE PARA CONTAR CUANTO SE REPITE "I"
            if(dados[j]==n){
            repetido++;
        }
    }
    return repetido;
}

int contarNumerosRepetidos(int v[], int numero, int tam){
    int i, cant=0;
    for(i=0;i<tam;i++){
        if(v[i]==numero) cant++;
        }
    return cant;
}


void ponerCero(int v[], int tam){
    int i;
    for(i=0;i<tam;i++){
        v[i]=0;
    }
}


int sumarVector(int v[], int tam ){
    int i, suma=0;

    for(i=0;i<tam;i++){
        if(v[i]!=-1){
        suma+=v[i];
    }
    }
    return suma;
}

void cargarMatriz(int v[][10], int tam1, int tam2){
    int i,j;
    for(i=0;i<tam1;i++){
        for(j=0;j<tam2;j++){
            v[i][j]=0;
        }
    }
}


void Calc_Puntos(int *dados, int Puntaje[][10],int Jugador){

    //int Puntaje[10]={0}; ///Puntajes posibles de obtener con cada combinacion

    Puntaje[Jugador-1][0]=JuegoDe1(dados,5);
    Puntaje[Jugador-1][1]=JuegoDe2(dados,5);
    Puntaje[Jugador-1][2]=JuegoDe3(dados,5);
    Puntaje[Jugador-1][3]=JuegoDe4(dados,5);
    Puntaje[Jugador-1][4]=JuegoDe5(dados,5);
    Puntaje[Jugador-1][5]=JuegoDe6(dados,5);
    Puntaje[Jugador-1][6]=Escalera(dados,5);
    Puntaje[Jugador-1][7]=Full(dados,5);
    Puntaje[Jugador-1][8]=Poker(dados,5);
    Puntaje[Jugador-1][9]=Generala(dados,5);
}

//bool juegodex()
int JuegoDe1(int *dados,int tam){
     int puntos=0;
     int cantidad=0;

     cantidad=contarNumerosRepetidos(dados,1,5);///CANTIDAD ES IGUAL A : (LLAMA A LA FUNCION CONTAR NUMEROS REPETIDOS,LA CUAL LE RETORNA LA CANTIDAD DE VECES
                                             ///QUE SE REPITE UN NUMERO, LO MISMO CON EL RESTO DE JUGADAS
     puntos=1*cantidad;///SE MULTIPLICA 1 * LA CANTIDAD DE VECES QUE EL NUMERO SE REPITIO PARA OBTENER EL PUNTAJE Y SE LE ASIGNA AL VECTOR

     return puntos;
}

int JuegoDe2(int *dados,int tam){
     int puntos=0;
     int cantidad=0;

     cantidad=contarNumerosRepetidos(dados,2,5);

     puntos=2*cantidad;

     return puntos;
}

int JuegoDe3(int *dados,int tam){
     int puntos=0;
     int cantidad=0;

     cantidad=contarNumerosRepetidos(dados,3,5);

     puntos=3*cantidad;

     //VecPuntosFINAL[2]=3*cantidad;

     return puntos;
}

int JuegoDe4(int *dados,int tam){
     int puntos=0;
     int cantidad=0;

     cantidad=contarNumerosRepetidos(dados,4,5);

     puntos=4*cantidad;

     return puntos;
}

int JuegoDe5(int *dados,int tam){
     int puntos=0;
     int cantidad=0;

     cantidad=contarNumerosRepetidos(dados,5,5);

     puntos=5*cantidad;

     return puntos;
}

int JuegoDe6(int *dados,int tam){
     int puntos=0;
     int cantidad=0;

     cantidad=contarNumerosRepetidos(dados,6,5);

     puntos=6*cantidad;

     return puntos;
}

int Escalera(int *dados,int tam){  //VERDADERO SI LAS COMBINACIONES DE DADOS PUEDEN FORMAR 1-2-3-4-5 O 2-3-4-5-6
    bool escalera = false;
    bool seisYuno = true;
    bool distintos = true;



    for(int i=1;i<=6;i++){ //iteramos los numeros del 1 al 6
        if(repetido(i,dados) > 1){  //si lOS REPETIDOS de algun numero en los dados es mayor a 1
                distintos=false;
        }
        if((i==6 || i==1) && repetido(i,dados)>0){ //si salio el 6 o el 1
            seisYuno = !seisYuno;    //se niega la variable de tal forma que si aparecieron ambos(o ninguno) esta vuelva a su valor original
        }
    }

    escalera = (distintos && !seisYuno);    // es Escalera si todos los numeros son distintos y 6-1 no aparecen al mismo tiempo
    if(escalera==true){
        return 25;///retorna 25
    }
    return 0;
}

int Full(int *dados,int tam){ //verdadero si un numero aparece en los dados 3 veces Y otro aparece 2

    bool doble = false;
    bool triple = false;
    bool full = false;


    for(int i=1;i<=6;i++){
        if(repetido(i,dados)== 2){
            doble = true;;
        }
        else if(repetido(i,dados) == 3){
            triple = true;
        }
    }
    full = (triple&&doble); //si hay un triple Y un doble full es verdadero
    if(full==true){
        return 30;
    }
    return 0;
}


int Poker(int *dados,int tam){    //verdadero si un numero aparece 4 veces en los dados
    bool poker = false;


    for(int i=1;i<=6;i++){
        if(repetido(i,dados) == 4){
            poker = true;;
        }
    }
    if(poker==true){
        return 40;
    }
    return 0;
}


int Generala(int *dados,int tam){ //verdadero si un numero aparece 5 veces en los dados
    bool generala = false;


    for(int i=1;i<=6;i++){
        if(repetido(i,dados)== 5){
            generala = true;;
        }
    }
    if(generala==true){
        return 50;
    }
    return 0;
}



int posicionNumeroEnVector(int v[],int tam, int num){
    int i;
    for(i=0;i<tam;i++){
        if(v[i]==num) return i;
        }
    return -1;
}





enum Color{
cNEGRO=0,
cAZUL=1,
cVERDE=2,
cCIAN=3,
cROJO=4,
cMAGENTA=5,
cMARRON=6,
cGRIS_CLARO=7,
cGRIS=8,
cAZUL_CLARO=9,
cVERDE_CLARO=10,
cCIAN_CLARO=11,
cROJO_CLARO=12,
cMAGENTA_CLARO=13,
cAMARILLO=14,
cBLANCO=15
};
void cls(void){ ///LIMPIA PANTALLA
    system("cls");
}
void pause(void){/// PAUSA
    system("pause >nul");
}
void gotoxy(short x, short y){
    COORD a;
    a.X = x;
    a.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),a);
}
void textcolor(short colorTexto=15, short colorFondo=0){
    short color = colorTexto + colorFondo * 16;
    SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE), color);
}
void recuadro(short iniX, short iniY, short ancho, short alto, short colorLinea=cBLANCO, short colorFondo=cNEGRO){
    int i, j;
    for(i=iniX; i<=iniX+ancho; i++){
        for(j=iniY; j<=iniY+alto; j++){
            gotoxy(i, j);
            textcolor(colorLinea, colorFondo);
            //Arriba izquierda
            if(i==iniX && j==iniY){
                cout << (char) 201;
            }
            //Arriba derecha
            else if(i==iniX+ancho && j==iniY){
                cout << (char) 187;
            }
            //Abajo izquierda
            else if(i==iniX && j==iniY+alto){
                cout << (char) 200;
            }
            //Abajo derecha
            else if(i==iniX+ancho && j==iniY+alto){
                cout << (char) 188;
            }
            //Lineas arriba y abajo
            else if(j==iniY || j==iniY+alto){
                cout << (char) 205;
            }
            //Lineas izquierda y derecha
            else if(i==iniX || i==iniX+ancho){
                cout << (char) 186;
            }
            //Dentro del recuadro
            else{
                cout << " ";
            }
        }
    }
}

void recuadroVACIO(short iniX, short iniY, short ancho, short alto, short colorLinea=cBLANCO, short colorFondo=cNEGRO){
    int i, j;
    for(i=iniX; i<=iniX+ancho; i++){
        for(j=iniY; j<=iniY+alto; j++){
            gotoxy(i, j);
            textcolor(colorLinea, colorFondo);
            //Arriba izquierda
            if(i==iniX && j==iniY){
                cout << " ";
            }
            //Arriba derecha
            else if(i==iniX+ancho && j==iniY){
                cout << " ";
            }
            //Abajo izquierda
            else if(i==iniX && j==iniY+alto){
                cout << " ";
            }
            //Abajo derecha
            else if(i==iniX+ancho && j==iniY+alto){
                cout << " ";
            }
            //Lineas arriba y abajo
            else if(j==iniY || j==iniY+alto){
                cout << " ";
            }
            //Lineas izquierda y derecha
            else if(i==iniX || i==iniX+ancho){
                cout << " ";
            }
            //Dentro del recuadro
            else{
                cout << " ";
            }
        }
    }
}
#endif // FUNCIONES_H_INCLUDED
