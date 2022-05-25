void menuProyecto();
void menu(int, int, int &);
void continuar(int x, int y, int &opc);
int continuar_(const char mensaje[]);
void menu_1();
void menu1(int x, int y, int &opc);
void menu_2();
void menu2(int x, int y, int &opc);

void continuar(int x, int y, int &opc){
	char tecla='\0';
	opc= 1;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	gotoxy(x, y);
	printf("%c", 16);
	do{
		if(kbhit()){ 
			tecla= getch();
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
			gotoxy(x, y);
			printf("%c", 16);
			if(opc>1 && tecla==72){
				y--;
				opc--;
			}
			if(opc<2 && tecla==80){
				y++;
				opc++;
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);	
			gotoxy(x, y);
			printf("%c", 16);
		}
	}while(tecla!=13);
}

int continuar_(const char mensaje[]){
	setlocale(LC_CTYPE, "Spanish");
	system("cls");
	int opc=0;
	int x=25;
	int y=5;
	
	
 
	while(opc!=2){
		opc=0;
		x=25;
		y=5;
		
		system("cls");
		gotoxy(x, y);
		printf("%s\n\n", mensaje);
		gotoxy(x, ++y);
		printf("¿Estas seguro que quieres continuar?\n");
		gotoxy(x, ++y);
		printf("1. Continuar\n");
		gotoxy(x, ++y);
		printf("2. Regresar\n");
		
		continuar(22,7, opc);
		system("cls");
		gotoxy(10,4);
	
		switch(opc){
			case OPC1:
				return 1;
				break;
			case OPC2:
				break;
		}
	}
}

void menu(int x, int y, int &opc){
	char tecla='\0'; //' '
	opc= 1;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	gotoxy(x, y);
	printf("%c", 16);
	do{
		if(kbhit()){ //khbit() sirve para identificar si se tecleo algo
			tecla= getch();
			//printf("%d", tecla);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
			gotoxy(x, y);
			printf("%c", 16);
			if(opc>1 && tecla==72){ //Flecha arriba
				y--;
				opc--;
			}
			if(opc<7 && tecla==80){ //Flecha abajo
				y++;
				opc++;
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);	
			gotoxy(x, y);
			printf("%c", 16);
		}
	}while(tecla!=13); //13 --> enter
}

void menuProyecto(){
	setlocale(LC_CTYPE, "Spanish");
	int seguir=0;
	int opc=0;
	int x=0;
	int y=0;
	
	while(opc!=7){
		system("color 02");
		x=25;
		y=5;
		system("cls");
		gotoxy(x, y);
		printf("1. Listado de precios\n");
		gotoxy(x, ++y);
		printf("2. Consulta de condiciones previas al estudio\n");
		gotoxy(x, ++y);
		printf("3. Actualizar datos (precios y condiciones)\n");
		gotoxy(x, ++y);
		printf("4. Registro de pruebas\n");
		gotoxy(x, ++y);
		printf("5. Modificar estado de la prueba\n");
		gotoxy(x, ++y);
		printf("6. Consulta de prueba\n");
		gotoxy(x, ++y);
		printf("7. Salir del sistema\n");
		gotoxy(x, ++y);
		
		menu(22,5, opc);
		system("cls");
		
		gotoxy(10,4);
		switch(opc){
			case OPC1:
				seguir=continuar_("Listado de precios");
				if(seguir==1){
					printf("Listado de precios\n");
					imprimirEstructura();
					leer_archivo();
					getch();
				}
				break;
			case OPC2:
				seguir=continuar_("Consulta de condiciones previas al estudio");
				if(seguir==1){
					printf("Consulta de condiciones previas al estudio\n");
					consulta();
					getch();
				}
				break;
			case OPC3:
				seguir=continuar_("Actualizar datos (precios y condiciones)");
				if(seguir==1){
					printf("Actualizar datos (precios y condiciones)\n");
					menu_1();
					getch();
				}
				break;
			case OPC4:
				seguir=continuar_("Registro de pruebas:");
				if(seguir==1){
					printf("Registro de pruebas\n");
					agregarDinamico();
					getch();
				}
				break;
			case OPC5:
				seguir=continuar_("Modificar estado de la prueba");
				if(seguir==1){
					printf("Modificar estado de la prueba\n");
					modificarEstado();
					getch();
				}
				break;
			case OPC6:
				seguir=continuar_("Consulta de Prueba");
				if(seguir==1){
					printf("Consulta de Prueba\n");
					menu_2();
					getch();
				}
				break;
			case OPC7:
				system("cls");
				printf("Adios :(");
				exit(0);	
				break;
		/* default:
				printf("No existe la opción \n");
				getch();
				break;	*/	
		}
	}
	getch();
}

void menu1(int x, int y, int &opc){
	char tecla='\0';
	opc= 1;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	gotoxy(x, y);
	printf("%c", 16);
	do{
		if(kbhit()){ 
			tecla= getch();
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
			gotoxy(x, y);
			printf("%c", 16);
			if(opc>1 && tecla==72){
				y--;
				opc--;
			}
			if(opc<4 && tecla==80){
				y++;
				opc++;
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);	
			gotoxy(x, y);
			printf("%c", 16);
		}
	}while(tecla!=13);
}

void menu_1(){
	setlocale(LC_CTYPE, "Spanish");
	system("cls");
	int seguir=0;
	int opc=0;
	int x=25;
	int y=5;
	
	while(opc!=4){
		opc=0;
		seguir=0;
		x=25;
		y=5;
		
		system("cls");
		gotoxy(x, y);
		printf("1. Modificar precios\n");
		gotoxy(x, ++y);
		printf("2. Modificar condiciones\n");
		gotoxy(x, ++y);
		printf("3. Agregar nuevos registros\n");
		gotoxy(x, ++y);
		printf("4. Regresar\n");
		
		menu1(22,5, opc);
		system("cls");
		gotoxy(10,4);
	
		switch(opc){
			case OPC1:
				seguir=continuar_("Modificar precios: ");
				if(seguir==1){
				printf("Modificar precios: ");
				modificar_precio();
				getch();
				}
				break;
			case OPC2:
				seguir=continuar_("Modificar condiciones: ");
				if(seguir==1){
				printf("Modificar condiciones: ");
				modificar_consulta();
				getch();}
				break;
			case OPC3:
				seguir=continuar_("Agregar nuevos registros: ");
				if(seguir==1){
				printf("Agregar nuevos registros: \n");
				agregarRegistro();
				getch();
				}
				break;
			case OPC4:
				menuProyecto();
				break;
		}
	}
}

void menu2(int x, int y, int &opc){
	char tecla='\0';
	opc= 1;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	gotoxy(x, y);
	printf("%c", 16);
	do{
		if(kbhit()){ 
			tecla= getch();
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
			gotoxy(x, y);
			printf("%c", 16);
			if(opc>1 && tecla==72){
				y--;
				opc--;
			}
			if(opc<5 && tecla==80){
				y++;
				opc++;
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);	
			gotoxy(x, y);
			printf("%c", 16);
		}
	}while(tecla!=13);
}

void menu_2(){
	setlocale(LC_CTYPE, "Spanish");
	system("cls");
	int opc=0;
	int x=25;
	int y=5;
	int seguir=0;
	
	while(opc!=5){
		seguir=0;
		opc=0;
		x=25;
		y=5;
		
		system("cls");
		gotoxy(x, y);
		printf("1. Activas (pruebas solicitadas)\n");
		gotoxy(x, ++y);
		printf("2. Realizadas (pruebas realizadas)\n");
		gotoxy(x, ++y);
		printf("3. Enviadas (pruebas cuyos resultados ya han sido enviados a los pacientes)\n");
		gotoxy(x, ++y);
		printf("4. Canceladas (pruebas NO realizadas)\n");
		gotoxy(x, ++y);
		printf("5. Regresar\n");
		
		menu2(22,5, opc);
		system("cls");
		gotoxy(10,4);
	
		switch(opc){
			case OPC1:
				seguir=continuar_("Activas (pruebas solicitadas): ");
				if(seguir==1){
				printf("Activas (pruebas solicitadas): ");
				consultaActivas();
				getch();
				}
				break;
			case OPC2:
				seguir=continuar_("Realizadas (pruebas realizadas): ");
				if(seguir==1){
				printf("Realizadas (pruebas realizadas): ");
				consultaRealizadas();
				getch();
				}			
				break;
			case OPC3:
				seguir=continuar_("Enviadas (pruebas cuyos resultados ya han sido enviados a los pacientes): ");
				if(seguir==1){
				printf("Enviadas (pruebas cuyos resultados ya han sido enviados a los pacientes): ");
				consultaEnviadas();
				getch();
				}			
				break;
			case OPC4:
				seguir=continuar_("Canceladas (pruebas NO realizadas): ");
				if(seguir==1){
				printf("Canceladas (pruebas NO realizadas): ");
				consultaCanceladas();
				getch();
				}
				break;
			case OPC5:
				menuProyecto();
				break;
		}
	}
}

