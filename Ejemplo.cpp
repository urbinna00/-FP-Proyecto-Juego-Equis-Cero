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
	int opcion=0, contaPoint=0, contaPoint2=0;
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
				contaPoint= contaPoint+1; //Contador de Puntos, no se reinicia al crear nueva partida.
				cout<<"El puntaje es: "<<contaPoint<<endl;
			}
			if(ganador==2){
				cout<<"\nEl ganador es el jugador 2"<<endl;
				contaPoint2= contaPoint2+1; //Contador de Puntos, no se reinicia al crear nueva partida.
				cout<<"El puntaje es: "<<contaPoint2<<endl;
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
			cout<<"\n1. Al iniciar, deben escoger el tamanio de la matriz con la que desean jugar (Debera tener un minimo de 3x3).\n solo es necesario ingresar un numero entero."<<endl;
			cout<<"\n2. Cada jugador dispone de un turno para indicar las coordenadas de la casilla en que desea marcar;\n el jugador 1 marca las 'X' y el jugador 2 los 'O'.\n Para indicar la coordenada, debera ingresar el numero de la fila y columna separadas por un espacio. \n Ejemplo: (1 1)\n Se ingresan solamente numeros enteros y que esten en el rango de la matriz."<<endl;
			cout<<"\n3. Para ganar una partida debes tener toda una fila, columna o linea diagonal completa por el mismo signo;\n ya sea: (X o 0)."<<endl;
			cout<<"\n4.Los puntos se obtendran de la siguiente manera: \nEl ganador de la partida, acumulara 1 punto en su puntaje y el perdedor no acumula ningun punto. \nEn caso de un empate ningun jugador acumulara puntos."<< endl;
			cout<<"\nDISFRUTA DEL JUEGO!"<<endl;
			cout<<"\n";
			break;
            
 }   
}
	return 0;
}
