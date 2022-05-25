void portada(){
	int aux=0;  /*Si abres el archivo siempre tiene que estar cerrado en tu equipo*/
/*Tipo FILE*/	FILE *archivo = fopen("portada.txt", "r"); /*Es un apuntador y guarda direcciones de memoria*/ /*fopen("nombre de tu archivo, modo)*/
	
	for(int i=0; i<48;i++){
		for(int j=0; j<62; j++){
			fscanf(archivo, "%d\t", &aux); /*sirve para leer el archivo, fscanf(archivo, "lo que lee", donde lo guarda)*/
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), aux);
			printf("%c%c", 219, 219);
		}
		printf("\n");
	}
	fclose(archivo);
}

void datos(){
	setlocale(LC_CTYPE, "Spanish");
	gotoxy(65, 10);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 176);
	printf("ANÁLISIS CLÍNICOS");
	gotoxy(65, 12);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 176);
	printf("Universidad Politécnica de San Luis Potosí");
	gotoxy(65, 14);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 176);
	printf("Programación I Lenguaje C");
	gotoxy(65, 16);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 176);
	printf("Alan Franshesco Vega Pérez | Mat: 177875");
	gotoxy(65, 18);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 176);
	printf("Angel Salcedo Hurtado | Mat: 179290");
	gotoxy(65, 20);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 176);
	printf("Cualquier tecla para iniciar...");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	getch();
}




void cuadro(int x1, int y1, int x2, int y2){
	for(int i=x1; i<x2; i++){
		gotoxy(i, y1); 
		printf("-");
		gotoxy(i, y2);
		printf("-");
	}
	
	for(int i=y1; i<y2; i++){
		gotoxy(x1, i);
		printf("¦");
		gotoxy(x2, i);
		printf("¦");
	}
	
	gotoxy(x1, y1);
	printf("+");
	gotoxy(x1, y2);
	printf("+");
	gotoxy(x2, y1);
	printf("+");
	gotoxy(x2, y2);
	printf("+");
}

