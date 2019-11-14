#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<string.h>

using namespace std;

int i,j,ganador;

void imprimir_gato(char gato[3][3]){
	
	cout<<"__________________\n";
	for(int i=0;i<3;i++){
		
		for(int j=0;j<3;j++){
		
		cout<<"|"<<gato[i][j]<<"|";
		
		}
		cout<<"\n";
		cout<<"__________________";
		cout<<"\n";
	}
}

int quien_gana(char gato[3][3]){
	
	ganador=0;
	if ((gato[0][0]=='X')&&(gato[0][1]=='X')&&(gato[0][2]=='X')) {ganador=1;}
	if (gato[1][0]=='X'&&gato[1][1]=='X'&&gato[1][2]=='X') {ganador=1;}
	if (gato[2][0]=='X'&&gato[2][1]=='X'&&gato[2][2]=='X') {ganador=1;}
	if (gato[0][0]=='X'&&gato[1][0]=='X'&&gato[2][0]=='X') {ganador=1;}
	if (gato[0][1]=='X'&&gato[1][1]=='X'&&gato[2][1]=='X') {ganador=1;}
	if (gato[0][2]=='X'&&gato[1][2]=='X'&&gato[2][2]=='X') {ganador=1;}
	if (gato[0][0]=='X'&&gato[1][1]=='X'&&gato[2][2]=='X') {ganador=1;}
	if (gato[2][0]=='X'&&gato[1][1]=='X'&&gato[0][2]=='X') {ganador=1;}
	
	if ((gato[0][0]=='O')&&(gato[0][1]=='O')&&(gato[0][2]=='O')) {ganador=2;}
	if (gato[1][0]=='O'&&gato[1][1]=='O'&&gato[1][2]=='O') {ganador=2;}
	if (gato[2][0]=='O'&&gato[2][1]=='O'&&gato[2][2]=='O') {ganador=2;}
	if (gato[0][0]=='O'&&gato[1][0]=='O'&&gato[2][0]=='O') {ganador=2;}
	if (gato[0][1]=='O'&&gato[1][1]=='O'&&gato[2][1]=='O') {ganador=2;}
	if (gato[0][2]=='O'&&gato[1][2]=='O'&&gato[2][2]=='O') {ganador=2;}
	if (gato[0][0]=='O'&&gato[1][1]=='O'&&gato[2][2]=='O') {ganador=2;}
	if (gato[2][0]=='O'&&gato[1][1]=='O'&&gato[0][2]=='O') {ganador=2;}
	return ganador;
}

int main(){
	int k=1,fila,columna,opcion;
	
	char gato[3][3]={' ',' ',' ',' ',' ',' ',' ',' ',' ',};
	cout<<"      EL JUEGO DE EL GATO (X/0)\n";
	do{
		cout<<"El ganador es el que complete primero una linea en: Fila, Columna, Diagonal\n";
		cout<<"Tablero del juego\n";
		imprimir_gato(gato);
		do{
		cout<<"Ronda numero: "<<k<<endl;
		if(k%2 != 0){
			do{
				do{
					cout<<"Turno del jugador 1";
					cout<<"\nIngrese las coordenadas de la casilla que desea: ";
					cin>>fila;
					cin>>columna;
					if (fila>3 ||columna>3){
						cout<<"\nError en la cordenada";
					}	
				}
			while(fila>3 ||columna>3);
			}
			while (gato[fila-1][columna-1]!=' ');
			gato[fila-1][columna-1]='X';
			imprimir_gato(gato);
			quien_gana(gato);
		}
		if (k%2 == 0){
			do{
			do{
			cout<<"\nTurno del jugador 2";
			cout<<"\nIngrese las coordenadas de la casilla que desea: ";
			cin>>fila;
			cin>>columna;
			if(fila>3 ||columna>3){
				cout<<"\nError en la coordenada";
			}
			}
			while (fila>3||columna>3);
			}
			while(gato[fila-1][columna-1]!=' ');
			gato[fila-1][columna-1]='O';
			imprimir_gato(gato);
			quien_gana(gato);
		}
		k=k+1;
		}
		while(k<10&&ganador==0);
		if (ganador==1){
			cout<<"\nEl ganador es el gugador 1";
		}
		if(ganador==2){
			cout<<"\nEl ganador es el gugador 2";
		}
		if(ganador==0){
			cout<<"\nEs un empate";
		}
	cout<<"\nles gustaria jugar de nuevo? preciona 1 para inicia de nuevo: ";
	cin>>opcion;
	k=1;
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			gato[i][j]=' ';
		}
	}
	}
	while(opcion==1);
	
	getch();
	return 0;
}
