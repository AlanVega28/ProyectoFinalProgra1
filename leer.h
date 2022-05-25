void leer_pruebas(){
	setlocale(LC_CTYPE, "Spanish");
	Detalle *regis2= (Detalle*)malloc(sizeof(Detalle));
	int y=10;
	
	printf("\n\n--------------Pruebas en el documento--------------\n\n");
		
	if(!(arch=fopen("detalle.xls", "r"))){
		printf("Error al intentar leer el archivo");
		exit(1); //Salida fallida
	}
	printf("Estado\t\tNo.prueba\tidDetalle\tTipo de prueba");
	while(!feof(arch)){ 
		y++;
		fscanf(arch, "%[^\t]\t", &regis2->prueba.estado);
		fscanf(arch, "%d\t", &regis2->prueba.paciente.idPaciente);
		fscanf(arch, "%d\t", &regis2->idDetalle);
		fscanf(arch, "%d\t", &regis2->prueba.idPrueba);
		fscanf(arch, "%d\t", &regis2->inf.codigoAnalisis);
		fscanf(arch, "%[^\t]\t", regis2->inf.tipoDeAnalisis);
		fscanf(arch, "%f\t", &regis2->inf.precio);
		fscanf(arch, "%[^\n]\n", regis2->inf.condiciones);
		
		gotoxy(0, y);
		printf("%s\t", regis2->prueba.estado);
		gotoxy(17, y);
		printf("%d\t\t", regis2->prueba.idPrueba);
		gotoxy(33, y);
		printf("%d\t\t", regis2->idDetalle);
		gotoxy(49, y);
		printf("%s\n", regis2->inf.tipoDeAnalisis);
	}
	fclose(arch);
}

void consultaCanceladas(){
	setlocale(LC_CTYPE, "Spanish");
	Detalle *regis2= (Detalle*)malloc(sizeof(Detalle));
	char canc[10]="Cancelada";
	bool bandera=true;
	
	printf("\n\n------------------------------------------\n\n");
		
	if(!(arch=fopen("detalle.xls", "r"))){
		printf("Error al intentar leer el archivo");
		exit(1); //Salida fallida
	}
			
	while(!feof(arch)){ 
		fscanf(arch, "%[^\t]\t", &regis2->prueba.estado);
		fscanf(arch, "%d\t", &regis2->prueba.paciente.idPaciente);
		fscanf(arch, "%d\t", &regis2->idDetalle);
		fscanf(arch, "%d\t", &regis2->prueba.idPrueba);
		fscanf(arch, "%d\t", &regis2->inf.codigoAnalisis);
		fscanf(arch, "%[^\t]\t", regis2->inf.tipoDeAnalisis);
		fscanf(arch, "%f\t", &regis2->inf.precio);
		fscanf(arch, "%[^\n]\n", regis2->inf.condiciones);
		
		if(strcmp(regis2->prueba.estado, canc)==0){
			printf("%s\t", regis2->prueba.estado);
			printf("%d\t", regis2->prueba.idPrueba);
			printf("%d\t", regis2->idDetalle);
			printf("%s\n", regis2->inf.tipoDeAnalisis);
			bandera=true;
		}
	}
	if(bandera==false){
		printf("\nNo se encontraron pruebas canceladas");
	}
	printf("\n\n------------------------------------------\n\n");
	fclose(arch);
}

void consultaActivas(){
	setlocale(LC_CTYPE, "Spanish");
	Detalle *regis2= (Detalle*)malloc(sizeof(Detalle));
	char active[10]="Activo";
	bool bandera=true;
	
	printf("\n\n------------------------------------------\n\n");
		
	if(!(arch=fopen("detalle.xls", "r"))){
		printf("Error al intentar leer el archivo");
		exit(1); //Salida fallida
	}
			
	while(!feof(arch)){ 
		fscanf(arch, "%[^\t]\t", &regis2->prueba.estado);
		fscanf(arch, "%d\t", &regis2->prueba.paciente.idPaciente);
		fscanf(arch, "%d\t", &regis2->idDetalle);
		fscanf(arch, "%d\t", &regis2->prueba.idPrueba);
		fscanf(arch, "%d\t", &regis2->inf.codigoAnalisis);
		fscanf(arch, "%[^\t]\t", regis2->inf.tipoDeAnalisis);
		fscanf(arch, "%f\t", &regis2->inf.precio);
		fscanf(arch, "%[^\n]\n", regis2->inf.condiciones);
		
		if(strcmp(regis2->prueba.estado, active)==0){
			printf("%s\t", regis2->prueba.estado);
			printf("%d\t", regis2->prueba.idPrueba);
			printf("%d\t", regis2->idDetalle);
			printf("%s\n", regis2->inf.tipoDeAnalisis);
			bandera=true;
		}
	}
	
	if(bandera==false){
		printf("\nNo se encontraron pruebas activas");
	}
	printf("\n\n------------------------------------------\n\n");
	fclose(arch);
}

void consultaRealizadas(){
	setlocale(LC_CTYPE, "Spanish");
	Detalle *regis2= (Detalle*)malloc(sizeof(Detalle));
	char reali[10]="Realizada";
	bool bandera=true;
	
	printf("\n\n------------------------------------------\n\n");
		
	if(!(arch=fopen("detalle.xls", "r"))){
		printf("Error al intentar leer el archivo");
		exit(1); //Salida fallida
	}
			
	while(!feof(arch)){ 
		fscanf(arch, "%[^\t]\t", &regis2->prueba.estado);
		fscanf(arch, "%d\t", &regis2->prueba.paciente.idPaciente);
		fscanf(arch, "%d\t", &regis2->idDetalle);
		fscanf(arch, "%d\t", &regis2->prueba.idPrueba);
		fscanf(arch, "%d\t", &regis2->inf.codigoAnalisis);
		fscanf(arch, "%[^\t]\t", regis2->inf.tipoDeAnalisis);
		fscanf(arch, "%f\t", &regis2->inf.precio);
		fscanf(arch, "%[^\n]\n", regis2->inf.condiciones);
		
		if(strcmp(regis2->prueba.estado, reali)==0){
			printf("%s\t", regis2->prueba.estado);
			printf("%d\t", regis2->prueba.idPrueba);
			printf("%d\t", regis2->idDetalle);
			printf("%s\n", regis2->inf.tipoDeAnalisis);
			bandera=true;
		}
	}
	if(!(bandera==true)){
		printf("\nNo se encontraron pruebas realizadas");
	}
	printf("\n\n------------------------------------------\n\n");
	fclose(arch);
}

void consultaEnviadas(){
	setlocale(LC_CTYPE, "Spanish");
	Detalle *regis2= (Detalle*)malloc(sizeof(Detalle));
	char env[10]="Enviada";
	bool bandera=true;
	
	printf("\n\n------------------------------------------\n\n");
		
	if(!(arch=fopen("detalle.xls", "r"))){
		printf("Error al intentar leer el archivo");
		exit(1); //Salida fallida
	}
			
	while(!feof(arch)){ 
		fscanf(arch, "%[^\t]\t", &regis2->prueba.estado);
		fscanf(arch, "%d\t", &regis2->prueba.paciente.idPaciente);
		fscanf(arch, "%d\t", &regis2->idDetalle);
		fscanf(arch, "%d\t", &regis2->prueba.idPrueba);
		fscanf(arch, "%d\t", &regis2->inf.codigoAnalisis);
		fscanf(arch, "%[^\t]\t", regis2->inf.tipoDeAnalisis);
		fscanf(arch, "%f\t", &regis2->inf.precio);
		fscanf(arch, "%[^\n]\n", regis2->inf.condiciones);
		
		if(strcmp(regis2->prueba.estado, env)==0){
			printf("%s\t", regis2->prueba.estado);
			printf("%d\t", regis2->prueba.idPrueba);
			printf("%d\t", regis2->idDetalle);
			printf("%s\n", regis2->inf.tipoDeAnalisis);
			bandera=true;
		}
	}
	if(bandera==false){
		printf("\nNo se encontraron pruebas enviadas");
	}
	printf("\n\n------------------------------------------\n\n");
	fclose(arch);
}


