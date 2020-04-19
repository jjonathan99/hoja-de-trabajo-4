#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

struct datos{
	int tipo_fumi;
	int num_hec;
	int total;
	int total1;
	int total2;
	int total3;
}est;

int main(){
	float descuento, des1,des2,des3,des4;
	int t,t1,t2,t3;
	int salir=0, menu, cont=0,cont1=0,cont2=0,cont3=0;
	do{
		system("cls");
		cout<<"\t\t\t Compania Xterminio S.A "<<endl;
		cout<<"\t\t\t1. Nuevo pedido "<<endl;
		cout<<"\t\t\t2. Ver datos "<<endl;
		cout<<"\t\t\t3. Salir "<<endl;
		cout<<"\t\t\tIngrese una opcion: ";
		cin>>menu;
		
		switch(menu){
			case 1: 
				system("cls");
				cout<<"\t1.Mala hierba"<<endl; //10
				cout<<"\t2.Langostas"<<endl;		//20
				cout<<"\t3.Gusanos"<<endl;		//30
				cout<<"\t4.Todo lo anterior"<<endl<<endl;	//50
				cout<<"Ingrese una opcion: ";
				cin>>est.tipo_fumi;
	
				cout<<"\nIngrese el numero de hectareas: ";
				cin>>est.num_hec;
				
				
				if(est.tipo_fumi == 1){
					est.total= est.num_hec*10;
				}else if(est.tipo_fumi == 2){
					est.total1=est.num_hec*20;
				}else if(est.tipo_fumi == 3){
					est.total2 = est.num_hec*30;
				}else if(est.tipo_fumi == 4){
					est.total3 = est.num_hec*50;
				}
				
				if(est.num_hec > 500){
					des1 = est.total*0.05;
					des2 = est.total1*0.05;
					des3 = est.total2*0.05;
					des4 = est.total3*0.05;	
					est.total  -=des1;
					est.total1 -=des2;
					est.total2 -=des3;
					est.total3 -=des4;
				}
				
				if(est.total > 1500){
					descuento = est.total*0.10;
					est.total = est.total-descuento;
				}if(est.total1 > 1500){
					descuento = est.total1*0.20;
					est.total1 = est.total1-descuento;
				}if(est.total2 > 1500){
					descuento = est.total2*0.30;
					est.total2 = est.total2-descuento;
				}if(est.total3 > 1500){
					descuento = est.total3*0.50;
					est.total3 = est.total3-descuento;
				}
				
				
					
				if(est.tipo_fumi == 1){
					cout<<"El total a pagar es de: "<<est.total<<endl;
				}else if(est.tipo_fumi == 2){
					cout<<"El total a pagar es de: "<<est.total1<<endl;
				}else if(est.tipo_fumi == 3){
					cout<<"El total a pagar es de: "<<est.total2<<endl;
				}else if(est.tipo_fumi == 4){
					cout<<"El total a pagar es de: "<<est.total3<<endl;
				}
				
				FILE *archivo;
				archivo = fopen("archivo.txt","a+b");
				
				if(archivo == NULL){
					cout<<"no se pudo abrir el archivo"<<endl;
					exit(1);
				}
				
				fwrite(&est,sizeof(est),1,archivo);
				cout<<"\nDatos Guardados "<<endl;
				fclose(archivo);
				system("pause");
				break;
			case 2:
				system("cls");
				cont=0;
				cont1=0;
				cont2=0;
				cont3=0;
				t=0;
				t1=0;
				t2=0;
				t3=0;
				FILE *leer;
				leer = fopen("archivo.txt","r");
				if(leer == NULL){
					cout<<"no se pudo leer el archivo"<<endl;
					exit(1);
				}
				
				while(!feof(leer)){
					fread(&est,sizeof(est),1,leer);
					if(est.tipo_fumi == 1){
						cont++;
						t += est.total;
					}else if(est.tipo_fumi == 2){
						cont1++;
						t1 += est.total1;
					}else if(est.tipo_fumi == 3){
						cont2++;
						t2 += est.total2;
					}else if(est.tipo_fumi == 4){
						cont3++;
						t3 += est.total3;
					}
				}
				
				cout<<"El total de servicios de mala hierba es de "<<cont<<endl;
				cout<<"El monto total pagados por los clientes es de: "<<t<<endl<<endl;
				cout<<"El total de servicios de mala hierba es de "<<cont1<<endl;
				cout<<"El monto total pagados por los clientes es de: "<<t1<<endl<<endl;
				cout<<"El total de servicios de mala hierba es de "<<cont2<<endl;
				cout<<"El monto total pagados por los clientes es de: "<<t2<<endl<<endl;
				cout<<"El total de servicios de mala hierba es de "<<cont3<<endl;
				cout<<"El monto total pagados por los clientes es de: "<<t3<<endl<<endl;
				cout<<"El monto total de totos los servicios es de "<<t+t1+t2+t3<<endl;
				fclose(leer);
				
				system("pause");
				break;
			case 3:
				salir = 1;
				break;
		}
	}while(salir != 1);
	system("pause");
}
