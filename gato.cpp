#include<iostream>
#include<stdio.h>
#include<string.h>
#include<vector>

using namespace std;

bool mifunc(vector< vector<char> > array,int n){
	char aux;
	
	bool ganador_encontrado=false;
	for(int i =0;i<n;i++){
		aux = array[i][0];
		for(int j =0;j<n;j++){
			if(aux==array[i][j]&&array[i][j]!=' '){
				aux==array[i][j];
			}
			else{
				break;
			}
			if(j==n-1) ganador_encontrado=true;
		}
	
	}
	
	return ganador_encontrado;
}

bool mifunc2(vector< vector<char> > array,int n){
	char aux;
	bool ganador_encontrado=false;
	for(int j =0;j<n;j++){
		aux = array[0][j];
		for(int i =0;i<n;i++){
			if(aux==array[i][j]&&array[i][j]!=' '){
				aux==array[i][j];
			}
			else{
				break;
			}
			if(i==n-1) ganador_encontrado=true;
		}
	}
	
	return ganador_encontrado;
}

void imprimir_gato(vector< vector<char> > gato,int n){
	
	for(int i=0;i<n;i++){
		
		for(int j=0;j<n;j++){
		
		cout<<"| "<<gato[i][j]<<" |";
		
		}
		cout<<"\n";
	}
}


int main(){
	int n;
	int k=1,fila,columna,opcion;
	int ganador = 0;
	cout<<"    EL JUEGO DE EL GATO (X/0)\n";
	cout<<"formas de ganar: "<<endl;
	cout<<"Ingrese el tamanio de su tablero (minimo una matriz de 3x3, solo es necesario ingresar un numero entero): "; cin >> n;
	vector<vector<char> > gato(n,vector<char>(n,' '));
	
	do{
		imprimir_gato(gato,n);
		do{
		cout<<"Ronda numero: "<<k<<endl;
		if(k%2 != 0){
			do{
				do{
					cout<<"Turno del jugador 1";
					cout<<"\nIngrese las coordenadas de la casilla que desea: ";
					cin>>fila;
					cin>>columna;
					if (fila>n ||columna>n){
						cout<<"\nError en la cordenada";
						cout<<"\n";
					}	
				}
			while(fila>n ||columna>n);
			}
			while (gato[fila-1][columna-1]!=' ');
			gato[fila-1][columna-1]='X';
			imprimir_gato(gato,n);
			cout << (mifunc(gato,n) ? "Ganador encontrado" : "Todavia no hay ganador") << endl;
			cout << (mifunc2(gato,n) ? "Ganador encontrado" : "Todavia no hay ganador") << endl;
			if(mifunc(gato,n) || mifunc2(gato,n))
				ganador = 1;
			k=2;
		}
		else if (k%2 == 0){
			do{
			do{
			cout<<"\nTurno del jugador 2";
			cout<<"\nIngrese las coordenadas de la casilla que desea: ";
			cin>>fila;
			cin>>columna;
			if(fila>n ||columna>n){
				cout<<"\nError en la coordenada";
				cout<<"\n";
			}
			}
			while (fila>n||columna>n);
			}
			while(gato[fila-1][columna-1]!=' ');
			gato[fila-1][columna-1]='O';
			imprimir_gato(gato,n);
			cout << (mifunc(gato,n) ? "Ganador encontrado" : "Todavia no hay ganador") << endl;
			cout << (mifunc2(gato,n) ? "Ganador encontrado" : "Todavia no hay ganador") << endl;
			if(mifunc(gato,n) || mifunc2(gato,n))
				ganador = 2;
			k=1;
			
		}
		cout << "Termina do while" << endl;
		}
		while(ganador==0);
		
		if (ganador==1){
			cout<<"\nEl ganador es el jugador 1 ";
		}
		if(ganador==2){
			cout<<"\nEl ganador es el jugador 2";
		}
		if(ganador==0){
			cout<<"\nEs un empate";
		}
	cout<<"\nles gustaria jugar de nuevo? preciona 1(yes) para inicia de nuevo: ";
	cin>>opcion;
	k=1;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			gato[i][j]=' ';
		}
	}
	}
	while(opcion==1);
	return 0;
}
