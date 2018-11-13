//REGLAS//
//Si la casilla es blanca, la casilla pasa a ser negra, la hormiga gira 90° a la izquierda y avanza una casilla.
//Si la casilla es negra, la casilla pasa a ser blanca, la hormiga gira 90° a la derecha y avanza una casilla.

#include<stdio.h>
#include<windows.h>

#define BLANCA 1
#define NEGRA 0

#define NORTE 0
#define ESTE 1
#define SUR 2
#define OESTE 3

#define DER 1
#define IZD 3

#define TAM 90

///////////////////////////////////////////////////////
void ManipularCursor(bool visibilidad, int tamano)
{
     HANDLE hCon;
     hCon = GetStdHandle(STD_OUTPUT_HANDLE);
     CONSOLE_CURSOR_INFO cci;
     cci.dwSize=tamano;							//TAMAÑO DEL CURSOR 1-100
     cci.bVisible=visibilidad;					//VISIBILIDAD DEL CURSOR TRUE/FALSE
     
     SetConsoleCursorInfo(hCon,&cci);         
}

void gotoxy(int x, int y)
{
    HANDLE hCon;
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;							//COORDENADA EN X
    dwPos.Y = y;							//COORDENADA EN Y
    
    SetConsoleCursorPosition(hCon, dwPos);
}
/////////////////////////////////////////////////////////

/////////////FUNCIONES DEL TABLERO///////////////////////
int tablero[TAM][TAM];
int anterior[TAM][TAM];

void IniciarTablero()
{	
	for (int i=0; i<TAM; i++)
	{
		for (int j=0; j<TAM; j++)
		{
			tablero[i][j]=NEGRA;			//INICIA TODAS LAS CASILLAS EN NEGRO
			
			anterior[i][j]=NEGRA;
		}
	}
	
}

void PintarTablero()
{
	for (int i=0; i<TAM; i++)
	{
		for (int j=0; j<TAM; j++)
		{
			if(tablero[i][j]==BLANCA && tablero[i][j]!=anterior[i][j])
			{
				gotoxy(i,j);
				printf("%c",219);
			}
			else if(tablero[i][j]==NEGRA && tablero[i][j]!=anterior[i][j])
			{
				gotoxy(i,j);
				printf("%c",32);
			}
		}
	}
	for (int k=0; k<TAM; k++)
	{
		for (int t=0; t<TAM; t++)
		{
			anterior[k][t]=tablero[k][t];
		}
	}
}
////////////////////////////////////////////////////////////

//////////////CLASE HORMIGA////////////////////////////////////
class HORMIGA
{	
	public:
		int x;	//coordenada en X
		int y;	//coordenada en Y
		int dir;	//direccion hacia la que ve  {0,1,2,3}
		HORMIGA();
		
		void girar(int);
		void avanzar(int);
		void paso();	
};

HORMIGA::HORMIGA()
{
	x=40;	//coordenada en X
	y=40;	//coordenada en Y
	dir=NORTE;	//direccion hacia la que ve  {0,1,2,3}
}

void HORMIGA::girar(int direccion)
{
	dir=(dir+direccion)%4;
}

void HORMIGA::avanzar(int direccion)
{
	if(direccion==NORTE) {y--;}
	else if(direccion==ESTE) {x++;}
	else if(direccion==SUR) {y++;}
	else if(direccion==OESTE) {x--;}
	
	x=(x+TAM)%TAM;
	y=(y+TAM)%TAM;
}

void HORMIGA::paso()
{
	if(tablero[x][y]==BLANCA)
	{
		girar(IZD);
		tablero[x][y]=NEGRA;
	}
	else if(tablero[x][y]==NEGRA)
	{
		girar(DER);
		tablero[x][y]=BLANCA;
	}
	//girar(dir);
	avanzar(dir);
}
//////////////////////////////////////////////////////////////////////

int main()
{
	//int contador=1;
	ManipularCursor(FALSE,100);
	
	IniciarTablero();
	//gotoxy(0,0); printf("%i", 4%4);
	//tablero[10][10]=BLANCA;
	PintarTablero();
	
	HORMIGA hormiga;
	
	while(true)
	{
		//gotoxy(91,91); printf("%i",contador);
		//printf("%i %i %i",hormiga.x, hormiga.y, hormiga.dir);
		
		//for(int i=0; i<100;i++)
		//{
			hormiga.paso();
			
			
		//}
		
		PintarTablero();
		//contador++;
		//fgetc(stdin);
		//Sleep(10);
	}
	
	return 0;
}

