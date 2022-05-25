void imprimirEstructura(){
	setlocale(LC_CTYPE, "Spanish");
	
	printf("\n\n--------------Registros en la Estructura----------------\n\n");
	
	for(int i=0; i<10; i++){
		printf("%d\t", listaDatos[i].codigoAnalisis);
		printf("%s\t\t", listaDatos[i].tipoDeAnalisis);
		printf("$%.2f \n", listaDatos[i].precio);
		//printf("%s\n\n", listaDatos[i].condiciones);
	}
}

void imprimirAnalisis(){
	setlocale(LC_CTYPE, "Spanish");
	analisisClinicos dato;
	
	if(!(arch=fopen("analisisClinico.xls", "r"))){
		printf("Error al intentar leer el archivo");
		exit(1); //Salida fallida
	}
	
	while(!feof(arch)){ //Hasta que no llegue al final del archivo
		fscanf(arch, "%d\t", &dato.codigoAnalisis);
		fscanf(arch, "%[^\t]\t", dato.tipoDeAnalisis);
		fscanf(arch, "%f\t", &dato.precio);
		fscanf(arch, "%[^\n]\n", dato.condiciones); //Si se pone un \n despues de la captura de las cadenas se tienes que poner \n dentro de la captura
		
		printf("%d\t", dato.codigoAnalisis);
		printf("%s\t\t", dato.tipoDeAnalisis);
		printf("$%.2f\t", dato.precio);
		printf("%s\n", dato.condiciones);
	}
	fclose(arch);
}

void buscarAnalisis(int codigo){
	setlocale(LC_CTYPE, "Spanish");
	analisisClinicos dato;
	
	if(!(arch=fopen("analisisClinico.xls", "r"))){
		printf("Error al intentar leer el archivo");
		exit(1); //Salida fallida
	}
	
	//printf("%s", mensaje); 
	
	while(!feof(arch)){ //Hasta que no llegue al final del archivo
		fscanf(arch, "%d\t", &dato.codigoAnalisis);
		fscanf(arch, "%[^\t]\t", dato.tipoDeAnalisis);
		fscanf(arch, "%f\t", &dato.precio);
		fscanf(arch, "%[^\n]\n", dato.condiciones); //Si se pone un \n despues de la captura de las cadenas se tienes que poner \n dentro de la captura
		
		if(codigo==dato.codigoAnalisis){
			printf("%d\t", dato.codigoAnalisis);
			printf("%s\t\t", dato.tipoDeAnalisis);
			printf("$%.2f\t", dato.precio);
			printf("%s\n", dato.condiciones);
		}
	}
	fclose(arch);
}

void crear_archivo(){
	
	if(!(arch=fopen("analisisClinico.xls", "w"))){
		printf("Error al intentar crear el archivo");
		exit(1); //Salida fallida, cierra el programa
	}
	
	for(int i=0; i<10; i++){  //No es necesario escanear en el orden en el que le imprimar al usuario
		fprintf(arch, "%d\t", listaDatos[i].codigoAnalisis);
		fprintf(arch, "%s\t", listaDatos[i].tipoDeAnalisis);
		fprintf(arch, "%f\t", listaDatos[i].precio);
		fprintf(arch, "%s\n", listaDatos[i].condiciones);
	}
	
	fclose(arch);
	
}

void leer_archivo(){
	setlocale(LC_CTYPE, "Spanish");
	analisisClinicos dato;
	
	if(!(arch=fopen("analisisClinico.xls", "r"))){
		printf("Error al intentar leer el archivo");
		exit(1); //Salida fallida
	}
	
	printf("\n\n--------------Registros en el Archivo----------------\n\n"); //Se tiene que sacar la información en el orden que lo metiste
	
	while(!feof(arch)){ //Hasta que no llegue al final del archivo
		fscanf(arch, "%d\t", &dato.codigoAnalisis);
		fscanf(arch, "%[^\t]\t", dato.tipoDeAnalisis);
		fscanf(arch, "%f\t", &dato.precio);
		fscanf(arch, "%[^\n]\n", dato.condiciones); //Si se pone un \n despues de la captura de las cadenas se tienes que poner \n dentro de la captura
		
		printf("%d\t", dato.codigoAnalisis);
		printf("%s\t\t", dato.tipoDeAnalisis);
		printf("$%.2f\n", dato.precio);
		//printf("%s\n\n", dato.condiciones);
	}
	fclose(arch);

}

void consulta(){
	int consulta=0;
	setlocale(LC_CTYPE, "Spanish");
	analisisClinicos datos;
	bool bandera=true;
	bool bandera2=true;
	int repetir=0;
	
	while(bandera){
		bandera=true;
		bandera2=false;
		system("cls");
		gotoxy(10,4);
		printf("Consulta de condiciones previas al estudio\n");
		leer_archivo();
		
	
	consulta=validaEntero("\n\nCódigo de analisis a consultar: ");
	
	
	if(!(arch=fopen("analisisClinico.xls", "r"))){
		printf("Error al intentar leer el archivo");
		exit(1); //Salida fallida
	}
	
	while(!feof(arch)){ //Hasta que no llegue al final del archivo
		fscanf(arch, "%d\t", &datos.codigoAnalisis);
		fscanf(arch, "%[^\t]\t", datos.tipoDeAnalisis);
		fscanf(arch, "%f\t", &datos.precio);
		fscanf(arch, "%[^\n]\n", datos.condiciones); //Si se pone un \n despues de la captura de las cadenas se tienes que poner \n dentro de la captura
		if(consulta==datos.codigoAnalisis){
			printf("%d\t", datos.codigoAnalisis);
			printf("%s\t\t", datos.tipoDeAnalisis);
			printf("%s\n", datos.condiciones);
			bandera2=true;
		//printf("%s\n\n", dato.condiciones);
		}
	}
	if(bandera2==false){
		printf("\nNo se encontro el registro");	
	}
	fclose(arch);
	//do{
		repetir=validaOpc("\n\n¿Quieres consultar otro analisis? 1->si | 2-> no: ");
	//}while(repetir!=1 && repetir!=2);
	
	if(repetir==2){
			bandera=false;
		}
	}

}

void modificar_precio(){
	setlocale(LC_CTYPE, "Spanish");
	analisisClinicos dato;
	FILE *arch2;
	int codigo=0;
	bool bandera=false;
	bool bandera2=true;
	int repetir=0;

	leer_archivo();
	
	while(bandera2){
		system("cls");
		gotoxy(10,4);
		printf("Modificar precios: ");
		leer_archivo();
		bandera=false;
		bandera2=true;
	
		if(!(arch=fopen("analisisClinico.xls", "r"))){
			printf("Error al intentar leer el archivo");
			exit(1); //Salida fallida
		}
		
		if(!(arch2=fopen("copia.xls", "a+"))){
			printf("Error al intentar leer el archivo");
			exit(1); //Salida fallida
		}
			
		codigo=validaEntero("\n\nCódigo del analisis a modificar: ");
		
		while(!feof(arch)){ 
			fscanf(arch, "%d\t", &dato.codigoAnalisis);
			fscanf(arch, "%[^\t]\t", dato.tipoDeAnalisis);
			fscanf(arch, "%f\t", &dato.precio);
			fscanf(arch, "%[^\n]\n", dato.condiciones); 
			
			if(codigo==dato.codigoAnalisis){
				printf("\n\nDatos actuales del analisis\n\n");
				printf("%d\t", dato.codigoAnalisis);
				printf("%s\t\t", dato.tipoDeAnalisis);
				printf("$%.02f\t", dato.precio);
				printf("%s\n", dato.condiciones);
					
				dato.precio=validaFlotante("\nNuevo precio: ");
				bandera=true;
			}
			fprintf(arch2, "%d\t", dato.codigoAnalisis);
			fprintf(arch2, "%s\t", dato.tipoDeAnalisis);
			fprintf(arch2, "%f\t", dato.precio);
			fprintf(arch2, "%s\n", dato.condiciones);
		}
		
		if(bandera==false){
			printf("\nNo se encontro el registro");
		}
		fclose(arch);
		fclose(arch2);
		remove("analisisClinico.xls");
		rename("copia.xls", "analisisClinico.xls");
		
		if(bandera==true){
			printf("\n\n--------------Analisis actualizado----------------\n\n");
			buscarAnalisis(codigo);
		}
		
		repetir=validaOpc("\n\n¿Quieres modificar otro precio? 1->si | 2-> no: ");
		
		if(repetir==2){
			bandera2=false;
		}
	}
}

void modificar_consulta(){
	setlocale(LC_CTYPE, "Spanish");
	analisisClinicos dato;
	FILE *arch2;
	int codigo=0;
	bool bandera=false;
	bool bandera2=true;
	int repetir=0;
	char condicion[200]="";
	
	
	while(bandera2){
		bandera=false;
		bandera2=true;
		strcpy(condicion, "\0");
		system("cls");
		gotoxy(10,4);
		printf("Modificar condiciones: ");
		
		
		if(!(arch=fopen("analisisClinico.xls", "r"))){
		printf("Error al intentar leer el archivo");
		exit(1); //Salida fallida
		}
	
		printf("\n\n--------------Códigos de los analisis----------------\n\n"); 
		
		while(!feof(arch)){ 
			fscanf(arch, "%d\t", &dato.codigoAnalisis);
			fscanf(arch, "%[^\t]\t", dato.tipoDeAnalisis);
			fscanf(arch, "%f\t", &dato.precio);
			fscanf(arch, "%[^\n]\n\n", dato.condiciones); 
			
			printf("%d\t", dato.codigoAnalisis);
			printf("%s\t", dato.tipoDeAnalisis);
			printf("$%.2f\n", dato.precio);
		}
		
		fclose(arch);
		
	
		if(!(arch=fopen("analisisClinico.xls", "r"))){
			printf("Error al intentar leer el archivo");
			exit(1); //Salida fallida
		}
		
		if(!(arch2=fopen("copia.xls", "a+"))){
			printf("Error al intentar leer el archivo");
			exit(1); //Salida fallida
		}	
		
		codigo=validaEntero("\n\nCódigo del analisis a modificar: ");
		
		while(!feof(arch)){ //Hasta que no llegue al final del archivo
			fscanf(arch, "%d\t", &dato.codigoAnalisis);
			fscanf(arch, "%[^\t]\t", dato.tipoDeAnalisis);
			fscanf(arch, "%f\t", &dato.precio);
			fscanf(arch, "%[^\n]\n", dato.condiciones); 
			
			if(codigo==dato.codigoAnalisis){
				printf("\nDatos actuales del analisis\n\n");
					printf("%d\t", dato.codigoAnalisis);
					printf("%s\t\t", dato.tipoDeAnalisis);
					printf("$%.2f\t", dato.precio);
					printf("%s\n", dato.condiciones);
					
					ingresaCadena("\n\nNueva condición: ", condicion);
					strcpy(dato.condiciones, condicion);
					bandera=true;
			}
			fprintf(arch2, "%d\t", dato.codigoAnalisis);
			fprintf(arch2, "%s\t", dato.tipoDeAnalisis);
			fprintf(arch2, "%f\t", dato.precio);
			fprintf(arch2, "%s\n", dato.condiciones);
		}	
		if(bandera==false){
			printf("\nNo se encontro el registro");
		}
		fclose(arch);
		fclose(arch2);
		remove("analisisClinico.xls");
		rename("copia.xls", "analisisClinico.xls");
		
		if(bandera==true){
			printf("\n\n--------------Analisis actualizado----------------\n\n");
			buscarAnalisis(codigo);
		}
		repetir=validaOpc("\n\n¿Quieres modificar otra condición? 1->si | 2-> no: ");
		if(repetir==2){
			bandera2=false;
		}
	}
}

void agregarRegistro(){
	
	analisisClinicos dato;
	int codigo;
	bool bandera=true;
	bool bandera2=true;
	int repetir=0;
	char tipoAnalisis[50]=" ";
	char condiciones[200]=" ";
			
	while(bandera2){
		bandera=true;
		bandera2=true;
		strcpy(tipoAnalisis, "\0");
		strcpy(condiciones, "\0");
		
		system("cls");
		gotoxy(10,4);
		printf("Agregar nuevos registros: \n");
		
		codigo=100+rand()%(999-100)+1;
		
		if(!(arch=fopen("analisisClinico.xls", "a+"))){
			printf("Error al intentar crear el archivo");
			exit(1); //Salida fallida, cierra el programa
		}
		
		while(!feof(arch)){ 
			fscanf(arch, "%d\t", &dato.codigoAnalisis);
			fscanf(arch, "%[^\t]\t", dato.tipoDeAnalisis);
			fscanf(arch, "%f\t", &dato.precio);
			fscanf(arch, "%[^\n]\n\n", dato.condiciones); 
			
			if(dato.codigoAnalisis==codigo){
				bandera=false;
				printf("\nYa existe este código\n");
			}
			
		}
		
		if(bandera){
		 	dato.codigoAnalisis=codigo;
			validaCadena("\n\tTipo de analisis: ", tipoAnalisis);
			strcpy(dato.tipoDeAnalisis, tipoAnalisis);
			dato.precio=validaFlotante("\n\tPrecio: ");
			ingresaCadena("\n\tCondiciones: ", condiciones);
			strcpy(dato.condiciones, condiciones);
				
				
			fprintf(arch, "%d\t", dato.codigoAnalisis);
			fprintf(arch, "%s\t", dato.tipoDeAnalisis);
			fprintf(arch, "%f\t", dato.precio);
			fprintf(arch, "%s\n", dato.condiciones);
			bandera=false;
		}
		fclose(arch);
		
		printf("\n\n--------------Analisis agregado al archivo----------------\n\n");
		buscarAnalisis(codigo);
		
		repetir=validaOpc("\n\n¿Quieres agregar otro analisis? 1->si | 2-> no: ");
		if(repetir==2){
			bandera2=false;
		}
	}
	
}




