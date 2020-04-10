#include <iostream>
#include <fstream>
#include <cstdlib>
#include <stdlib.h>
using namespace std;

void annadir();
void leer();
void escribir();

class alumnos {     
  public: 
    int numero; 
    string cadena; 
};

int main(){
	int opcion;
	alumnos lista;
	int nalumno;
	lista.cadena = "Alumnos inscritos en la base de datos:";
	lista.numero = nalumno;
	
	do{
		cout << "******************BASE DE DATOS ALUMNOS**************"<<endl;
		cout << "1.- Annadir alumnos y sus datos a la base de datos."<<endl;
		cout << "2.- Leer datos de un alumno."<<endl;
		cout << "3.- Annadir datos a un alumno."<<endl;
		cout << "4.- Salir." << endl;
		cout << "Selecciona una opcion: " <<endl;
		cin >> opcion;
		cin.ignore(256,'\n');
		
		switch(opcion){
			case 1: escribir();
				break;
			case 2: leer();
				break;
			case 3: annadir();
				break;
			case 5: cout << "Gracias por todo." << endl;
				break;
			default:cout << "\n Esa opcion no esta en el menu! \n";
				break;			
		}	
	} while (opcion!=4);
	system ("pause");
	return 0;
}
void escribir(){
	ofstream archivo;
	string nombreArchivo;
	string linea;
	int nalumno;
 
	
	
	cout<<"¿Cuantos alumnos quieres annadir a la base de datos?"<<endl;//buscar una funcion que devuelva el numero de registros que tenga archivos
	cin>>nalumno;
	for(int i=0 ; i<=nalumno;i++){
		cout << "introduce el nombre del alumno: "<<endl;
		getline(cin,linea);
		archivo<<linea<<endl;
	}
	archivo.close();
	cout<<"el numero de alumnos en la base de datos es: " <<nalumno<<endl;
	
	
	cout<<"Alumno al que quiera insertar datos ----> ";
	getline(cin,nombreArchivo);
	archivo.open(nombreArchivo.c_str(), ios::out);
	if(archivo.fail()){
		cout<<"No puede abrir el archivo";
		exit(1);
		
	}
	
	cout<<"Introduce los datos de "<<nombreArchivo<<":"<<endl;
	getline(cin,linea);
	archivo<<linea<<endl;
	
	archivo.close();
	}
void leer(){
	ifstream archivo;
	string nombreArchivo;
	string linea;
		
	cout<<"Nombre del alumno que quieres leer: ";
	getline(cin, nombreArchivo);
	archivo.open(nombreArchivo.c_str(), ios::in);
		
	if(archivo.fail()){
		cout<<"No pude abrir el archivo";
		exit(1);
	}
	while(!archivo.eof()){
		getline(archivo, linea);
		cout<<linea<<endl;
	}
	archivo.close();
}
	
void annadir(){
	ofstream archivo;
	string nombreArchivo;
	string linea;
		
	cout << "¿A que alumno desea annadir datos?";
	getline(cin,nombreArchivo);
	archivo.open(nombreArchivo.c_str(),ios::app);//convierte el nombre en una cadena con comillas; dentro del sistema de entrada y salida, la accion que se va a realizar es de tipo out(salida)0
		
	if(archivo.fail()){
		cout << "No pude abrir el archivo";
		exit(1);
	}
		

		
	cout << "Introducir en los datos:"<<endl;
	getline(cin,linea);
	archivo<<linea<<endl;
	archivo.close();
	
}



		

		
		
