#include <iostream>
#include <stdio.h>
#include <stdlib.h> 
#include <time.h> 

using namespace std;

const int filas = 10;
const int columnas = 10;
int barcosEnemigos = 30;
int matriz1[filas][columnas];
int matriz2[filas][columnas];

void inicializandoMatriz()
{
	for(int i=0; i < filas; i++)
	{
		for(int j=0; j < columnas; j++)
		{
			matriz1[i][j] = 0;
		}
	}
}

void Matriz()
{
	for(int i=0; i < filas; i++)
	{
		for(int j=0; j < columnas; j++)
		{
			cout << matriz1[i][j] << " ";
		}
		cout << endl;
	}
}

void Matriz2()
{
	for(int i=0; i < filas; i++)
	{
		for(int j=0; j < columnas; j++)
		{
			cout << matriz2[i][j] << " ";
		}
		cout << endl;
	}
}

int espacios()
{
	int contador = 0;
	
	for(int i=0; i < filas; i++)
	{
		for(int j=0; j < columnas; j++)
		{
			if(matriz1[i][j] == 1)
				contador++;
		}
	}
	
	return contador;
}

void Naves()
{
	int s = 0;
	while(s < barcosEnemigos)
	{
		int x = rand() % filas;
		int y = rand() % columnas;
		if(matriz1[x][y] != 1)
		{
			s++;
			matriz1[x][y] = 1;
		}
	}
}

bool Ataque(int x,int y)
{
	if(matriz1[x][y] == 1)
	{
		matriz1[x][y] = 2;
		return true;
	}
	return false;
}

void batallaNaval() 
{
	int i,j,x,y;
	inicializandoMatriz();
	Naves();
	srand(time(NULL));
	char continuar;
	while(true)
	{
		
		cout<<"Introduce las coordenadas del  barco:"<<endl;
		cin>>x;
		cin>>y;
		matriz2[x][y] = 1;
		if(Ataque(x,y))
		{
			cout<<"Me diste"<<endl;
			matriz2[x][y] = 2;
		}	
		else
		   cout << "No hay nada!" << endl;
		
		cout << "Deseas continuar (s/n)? "; 
		cin >> continuar;
		if(continuar == 's')
			break;
	}
	cout << "Game over!" << endl;
	system("pause");
	
}


int main(int argc, char *argv[]) {
	batallaNaval();
	return 0;
}

 
