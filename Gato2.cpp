#include <iostream>
#include <string> 
#include <sstream> 
#include<stdio.h>
#include<string.h>
#include<vector>

using namespace std;

float validacion(string f){
	int flag = 1;
    string s;
    while(flag!=0){
    flag=0; 
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        if(!isdigit(s[i])) {
        flag=1;
        break;
        }
    }
    if(flag==1) cout<<"\nEscriba un numero entero: ";
    }
    stringstream convert(s);
    int x = 0;
    convert >> x;
    return x;
}

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
	int opcion=0;
	string op;

while(opcion!=4){
	cout<<"JUEGO DEL GATO (X/0)"<<endl;
    cout<<"\n1. Iniciar Partida. "<<endl;
    cout<<"2. Puntuaciones. "<<endl;
    cout<<"3. Instrucciones."<<endl;
    cout<<"4. finalizar juego."<<endl;
    

    cout<<"\n";
    cout<<"Ingrese una opcion: ";
    opcion= validacion(op);
    cout<<"\n";
    
    switch (opcion){
    	case 1: 
	
		{
			int n,nnew;
			int k=1,fila,columna,opcion=0;
			int ganador = 0;
			cout<<"\n";
			cout<<"Ingrese el tamanio de su tablero (minimo una matriz de 3x3, solo es necesario ingresar un numero entero): "; cin >> n;
			vector<vector<char> > gato(n,vector<char>(n,' '));
			cout<<"\n";
	
			do{
				imprimir_gato(gato,n);
				cout<<"\n";
				do{
					if(k%2 != 0){
					do{
						do{
							cout<<"\nTurno del jugador 1";
							cout<<"\n\nIngrese las coordenadas de la casilla que desea: ";
							cin>>fila;
							cin>>columna;
							cout<<"\n";
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
								cout<<"\n\nIngrese las coordenadas de la casilla que desea: ";
								cin>>fila;
								cin>>columna;
								cout<<"\n";
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
				cout<<"\nEl ganador es el jugador 1 "<<endl;
			}
			if(ganador==2){
				cout<<"\nEl ganador es el jugador 2"<<endl;
			}
			if(ganador==0){
				cout<<"\nEs un empate"<<endl;
			}
	
	
			cout<<"\nDesean jugar de nuevo? Presionen '1' para jugar nuevamente o '2' para salir de la partida: ";
			cin>>opcion;
			cout<<"\n";
			if(opcion==1){
				k=1;
				ganador=0;
				cout<<"Ingrese el tamanio de su tablero (minimo una matriz de 3x3, solo es necesario ingresar un numero entero): "; cin >> n;
				
			gato.resize(n,vector<char>(n,' '));
			for(int i=0;i<n;i++)
				gato[i].resize(n,' ');
			
				for(int i=0;i<n;i++){
					for(int j=0;j<n;j++){
					gato[i][j]=' ';
					}
				}	
			}	
		}
		while(opcion==1);
	}
				break;
    
    case 2:
    		cout<<"puntuaciones "<<endl;
    		break;
    
	case 3: cout<<"Instrucciones:"<<endl;
			cout<<"Como se juega"<<endl;
			cout<<"\n1. Al de iniciar, deben escoger el tamanio de la matriz con la que desean jugar (Debera tener un minimo de 3x3).\nsolo es necesario con ingresar un numero entero."<<endl;
			cout<<"\n2. Cada jugador dispone de un turno para indicar las coordenadas de la casilla en que desea marcar; el jugador uno marca las 'X' y el jugador 2 los 'O'.\nPara indicar la coordenada, debera ingresar el numero de la fila y columna separadas por un espacio por ejemplo: (1 1)\n'se ingresan solamente numeros enteros y que esten en el rango de la matriz'"<<endl;
			cout<<"\n3. Para ganar una partida debes tener toda una fila, columna o linea diagonal; completas por mismo signo ya sea: (X o O)."<<endl;
			cout<<"\nComo se haran las puntuaciones"<<endl;
			cout<<"\nLos puntos se obtendran de la siguiente manera: el logre ganar la partida, acumulara 1 punto en su puntaje y el perdedor no acumula ningun punto, En caso de un empate ningun jugador acumulara puntuacion."<< endl;
			cout<<"\n";
			break;
            
 }   
}
	return 0;
}
