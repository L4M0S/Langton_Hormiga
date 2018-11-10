//REGLAS//
//Si la casilla es blanca, la casilla pasa a ser negra, la hormiga gira 90� a la izquierda y avanza una casilla.
//Si la casilla es negra, la casilla pasa a ser blanca, la hormiga gira 90� a la derecha y avanza una casilla.

#include<stdio.h>
#include<windows.h>

#define BLANCA 1
#define NEGRA 0

#define NORTE 1
#define ESTE 2
#define SUR 3
#define OESTE 4

#define DER 1
#define IZD 3

#define TAM 50

///////////////////////////////////////////////////////
void ManipularCursor(bool visibilidad, int tamano)
{
     HANDLE hCon;
     hCon = GetStdHandle(STD_OUTPUT_HANDLE);
     CONSOLE_CURSOR_INFO cci;
     cci.dwSize=tamano;							//TAMA�O DEL CURSOR 1-100
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

void IniciarTablero()
{	
	for (int i=0; i<TAM; i++)
	{
		for (int j=0; j<TAM; j++)
		{
			tablero[i][j]=NEGRA;			//INICIA TODAS LAS CASILLAS EN NEGRO
		}
	}
}

void PintarTablero()
{
	for (int i=0; i<TAM; i++)
	{
		for (int j=0; j<TAM; j++)
		{
			if(tablero[i][j]==BLANCA)
			{
				gotoxy(i,j);
				printf("%c",219);
			}
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
	x=25;	//coordenada en X
	y=25;	//coordenada en Y
	dir=NORTE;	//direccion hacia la que ve  {0,1,2,3}
}

void HORMIGA::girar(int direccion)
{
	dir=(dir+direccion)%4;
}

void HORMIGA::avanzar(int direccion)
{
	if(direccion==NORTE) y--;
	else if(direccion==ESTE) x++;
	else if(direccion==SUR) y++;
	else if(direccion==OESTE) x--;
}

void HORMIGA::paso()
{
	if(tablero[x][y]==BLANCA)
	{
		dir=IZD;
		tablero[x][y]=NEGRA;
	}
	else if(tablero[x][y]==NEGRA)
	{
		dir=DER;
		tablero[x][y]=BLANCA;
	}
	girar(dir);
	avanzar(dir);
}
//////////////////////////////////////////////////////////////////////

int main()
{
	int contador=1;
	ManipularCursor(FALSE,100);
	
	IniciarTablero();
	//gotoxy(0,0); printf("%i", 4%4);
	//tablero[10][10]=BLANCA;
	PintarTablero();
	
	HORMIGA hormiga;
	
	while(true)
	{
		//gotoxy(0,0); printf("%i",contador);
		printf("%i %i %i",hormiga.x, hormiga.y, hormiga.dir);
		hormiga.paso();
		//PintarTablero();
		//contador++;
		fgetc(stdin);
	}
	
	return 0;
}

