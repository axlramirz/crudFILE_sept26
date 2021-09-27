#include <iostream>
#include <string.h>
using namespace std;
const char *nombre_archivo = "archivo.dat";
struct Estudiante{
	int codigo;
	char nombres[50];
	char apellidos[50];
	int telefono;
};
void menu();
void crear();
void leer();
void actualizar();
void deleter();

main(){
	
menu();

}

void menu (){
		int option;
	do{
	cout<<"\t.:MENU:.\n";
	cout<<"1. Insertar elementos a la lista\n";
	cout<<"2. Mostrar los elementos de la lista\n";
	cout<<"3. Modificar elemento en la lista\n";
	cout<<"4. Borrar elemento de la lista\n";
	cout<<"5. Salir\n";
	cout<<"opcion: "; cin>>option;
	switch(option){
		case 1:
				crear ();
				cout<<"\n";
			system("pause");
		break;
		case 2 :
			cout<<"------ L I S T A ------"<<endl;
			leer ();
			cout<<"\n";
			system("pause");	
		break;
		case 3:
			actualizar ();
			system("pause");
		break;
		case 4: 
			deleter();
			system("pause");
		break; 
		}
		system ("cls");
	}while (option != 5);
}


void actualizar(){
	FILE* archivo = fopen(nombre_archivo,"r+b");
	int id;
	Estudiante estudiante;
	string nombre,apellido;
	cout<<"Ingres el ID que desea Modificar:";
	cin>>id;
	fseek(archivo,id * sizeof(Estudiante),SEEK_SET);
	cout<<"Ingrese el Codigo:";
		cin>>estudiante.codigo;
		cin.ignore();
		cout<<"Ingrese los Nombres:";
		getline(cin,nombre);
		strcpy(estudiante.nombres,nombre.c_str());
		cout<<"Ingrese los Apellidos:";
		getline(cin,apellido);
		strcpy(estudiante.apellidos,apellido.c_str());
		cout<<"Ingrese el Telefono:";
		cin>>estudiante.telefono;
		cin.ignore();
	
	fwrite(&estudiante,sizeof(Estudiante),1,archivo);
	fclose(archivo);
	leer();
}
void crear(){
	char continuar;
	FILE* archivo = fopen(nombre_archivo,"ab");
	Estudiante estudiante;
	string nombre,apellido;
	do{
		fflush(stdin);
		cout<<"Ingrese el Codigo:";
		cin>>estudiante.codigo;
		cin.ignore();
		cout<<"Ingrese los Nombres:";
		getline(cin,nombre);
		strcpy(estudiante.nombres,nombre.c_str());
		cout<<"Ingrese los Apellidos:";
		getline(cin,apellido);
		strcpy(estudiante.apellidos,apellido.c_str());
		cout<<"Ingrese el Telefono:";
		cin>>estudiante.telefono;
		cin.ignore();
		fwrite(&estudiante,sizeof(Estudiante),1,archivo);
		cout<<"Dese Agregar otro Estudiante (s/n):";
		cin>>continuar;
	} while ( (continuar=='s') || (continuar=='S') );
	fclose(archivo);

}
void leer(){
		system("cls");
		FILE* archivo = fopen(nombre_archivo,"rb");	
		if (!archivo){
			archivo = fopen(nombre_archivo,"w+b");	
		}
		Estudiante estudiante;
		int id=0;	
		fread(&estudiante,sizeof(Estudiante),1,archivo);
		cout<<"____________________________________________"<<endl;
		cout<<"id"<<"|"<<"Codigo"<<"|"<<"Nombres"<<"|"<<"Apellidos"<<"|"<<"Telefono"<<endl;
		do{
			if(estudiante.telefono !=-1){
			cout<<"________________"<<endl;
			cout<<id<<"|"<<estudiante.codigo<<"|"<<estudiante.nombres<<"|"<<estudiante.apellidos<<"|"<<estudiante.telefono<<endl;	
			
		}
		fread(&estudiante,sizeof(Estudiante),1,archivo);
		id+=1;	
		}while(feof(archivo)==0);
		fclose(archivo);
		cout<<endl;
}
void deleter(){
	FILE* archivo = fopen(nombre_archivo,"r+b");
			if (!archivo){
			archivo = fopen(nombre_archivo,"tempt");	
		}
	int id;
	Estudiante estudiante;
	string nombre,apellido;
	cout<<"Ingres el ID que desea eliminar:";
	cin>>id;
	fseek(archivo,id * sizeof(Estudiante),SEEK_SET);
	cout<<"deleted"<<endl;
	fwrite(&estudiante,sizeof(Estudiante),1,archivo);
	fclose(archivo);
	remove("r+b");
	rename("tempt", "r+b");
	leer();
}
