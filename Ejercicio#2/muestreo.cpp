#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

struct datos{
	char edad[5];
}est;
int main(){
	int numero, i, salir=0,menu, contenedor;
	int cont=0, cont1=0,  cont2=0, cont3=0, total;
	float porcentaje;
	
	do{
		system("cls");
		cout<<"\t\t\tMuestreo de personas"<<endl;
		cout<<"\t\t\t1. Ingresar un muestreo"<<endl;
		cout<<"\t\t\t2. leer datos"<<endl;
		cout<<"\t\t\t3. salir"<<endl;
		cout<<"\t\t\tIngrese una opcion: ";
		cin>>menu;
		
		switch(menu){
			case 1:
			do{
			system("cls");
			cout<<"     Muestreo de personas "<<endl;
			cout<<"Ingrese el numero de personas ";
			cin>>numero;
    		}while(numero>50); 
	
			for(i=0;i<numero;i++){
				fflush(stdin);
				cout<<"ingrese la edad de la persona "<<i+1<<": ";
				gets(est.edad);
				fflush(stdin);
				contenedor = atoi(est.edad);
		
				if(contenedor>=0 && contenedor<13){
		        	   	cont++;
				}else if(contenedor>12 && contenedor<30){
					cont1++;
				}else if(contenedor>29 && contenedor<60){
				cont2++;
				}else if(contenedor>59){
					cont3++;
				}
			}
			
			FILE *archivo;
			archivo = fopen("archivo.txt","a+b");
			
			if(archivo ==NULL){
				cout<<"no se pudo abrir el archivo "<<endl;
				exit(1);
			}
			fwrite(&est,sizeof(est),1,archivo);
			cout<<"Datos guardados"<<endl;
			fclose(archivo);
			system("pause");
				break;
			case 2:
				system("cls");
				FILE *leer;
				leer = fopen("archivo.txt","r");
				if(leer==NULL){
					cout<<"no se pudo leer el archivo"<<endl;
					exit(1);
				}
				
					total= cont+cont1+cont2+cont3;
					cout<<"el total de datos es de "<<total<<endl;
					cout<<"el total de porcentaje de niños es: "<<(cont*100)/total<<"%"<<endl;
					cout<<"el total de porcentaje de jovenes es: "<<(cont1*100)/total<<"%"<<endl;
					cout<<"el total de porcentaje de adultos es: "<<(cont2*100)/total<<"%"<<endl;
					cout<<"el total de porcentaje de adultos mayores es: "<<(cont3*100)/total<<"%"<<endl;
					fclose(leer);
					system("pause");
				break;
			case 3:
				salir = 1;
				break;
		}
	}while(salir!=1);
	system("pause");
}
