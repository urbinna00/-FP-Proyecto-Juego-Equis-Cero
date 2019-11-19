#include<iostream>
#include<stdio.h>
#include<string.h>
#include<vector>

using namespace std;

bool ganador_horizontal(vector< vector<char> > array,int n){
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

bool ganador_vertical(vector< vector<char> > array,int n){
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

bool ganador_diagonal(vector< vector<char> > array,int n){
	char aux;
	bool ganador_encontrado = false;
	//diagonal de izquierda a derecha
	for(int i=0;i<n;i++){
		aux = array[i][i];
		if(aux==array[i][i]&&array[i][i]!=' '){
			aux==array[i][i];
		}
		else{
			break;
		}
		if(i==n-1) ganador_encontrado=true;
	}
	//diagonal de derecha a izquierda
	int cont=0;
	for(int i=n-1;i>=0;i--)
			if(array[i][n-1-i]=='X')
				cont+=1;
				
	if(cont==n) ganador_encontrado=true;
	
	for(int i=n-1;i>=0;i--)
			if(array[i][n-1-i]=='O')
				cont+=1;
				
	if(cont==n) ganador_encontrado=true;
		
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
			if(ganador_horizontal(gato,n) || ganador_vertical(gato,n) || ganador_diagonal(gato,n))
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
			if(ganador_horizontal(gato,n) || ganador_vertical(gato,n) || ganador_diagonal(gato,n))
				ganador = 2;
			k=1;
			
		}
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
