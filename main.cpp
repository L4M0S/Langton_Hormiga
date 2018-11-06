//REGLAS//
//Si la casilla es blanca, la casilla pasa a ser negra, la hormiga gira 90° a la izquierda y avanza una casilla.
//Si la casilla es negra, la casilla pasa a ser blanca, la hormiga gira 90° a la derecha y avanza una casilla.

#include<stdio.h>
#include<windows.h>

#define BLANCA 1
#define NEGRA 0

#define NORTE 1
#define ESTE 2
#define SUR 3
#define OESTE 4

int tablero[50][50];

void ManipularCursor()
{
     HANDLE hCon;
     hCon = GetStdHandle(STD_OUTPUT_HANDLE);
     CONSOLE_CURSOR_INFO cci;
     cci.dwSize=100;							//TAMAÑO DEL CURSOR 1-100
     cci.bVisible=TRUE;					//VISIBILIDAD DEL CURSOR TRUE/FALSE
     
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

void IniciarTablero()
{	
	for (int i=0; i<50; i++)
	{
		for (int j=0; j<50; j++)
		{
			tablero[i][j]=NEGRA;			//INICIA TODAS LAS CASILLAS EN NEGRO
		}
	}
}
	
	
class HORMIGA
{
	int x,y, direccion, casilla, num;
	
	public:
		HORMIGA();
		
		void NUM()
		{
			printf("%i",num);
		}
				
};

	
int main()
{
	ManipularCursor();
	
	gotoxy(10,10);
	//printf("%c", 219);
	
	IniciarTablero(); 
	
	while(!getchar())
	{
	}
	
	getchar();
}

