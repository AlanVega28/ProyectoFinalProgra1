/*   El operador para las estructuras apuntadores es ->, el equivalente para los estaticos es el .   */

analisisClinicos buscaCodigo(int codigo){
	setlocale(LC_CTYPE, "Spanish");
	analisisClinicos dato;
	bool bandera=true;
		
	if(!(arch=fopen("analisisClinico.xls", "r"))){
		printf("Error al intentar leer el archivo");
		exit(1); //Salida fallida
	}
	
	while(!feof(arch)){ //Hasta que no llegue al final del archivo
		fscanf(arch, "%d\t", &dato.codigoAnalisis);
		fscanf(arch, "%[^\t]\t", dato.tipoDeAnalisis);
		fscanf(arch, "%f\t", &dato.precio);
		fscanf(arch, "%[^\n]\n", dato.condiciones); 
		
		if(codigo==dato.codigoAnalisis){
			printf("\nDatos actuales del analisis: \n\n");
			printf("%d\t", dato.codigoAnalisis);
			printf("%s\t\t", dato.tipoDeAnalisis);
			printf("%s\n\n", dato.condiciones);
			fclose(arch);
			return dato;
		}
	}
	if(bandera==false)printf("No se encuentra el registro");
	fclose(arch);
	return dato;
	
}

int validaCodigo(){
	int codigo=0;
	setlocale(LC_CTYPE, "Spanish");
	analisisClinicos dato;
	bool bandera=true;
	
	while(bandera){
		bandera=true;
		
		codigo=validaEntero("Código: ");
			
		if(!(arch=fopen("analisisClinico.xls", "r"))){
			printf("Error al intentar leer el archivo");
			exit(1); //Salida fallida
		}
		
		while(!feof(arch)){ //Hasta que no llegue al final del archivo
			fscanf(arch, "%d\t", &dato.codigoAnalisis);
			fscanf(arch, "%[^\t]\t", dato.tipoDeAnalisis);
			fscanf(arch, "%f\t", &dato.precio);
			fscanf(arch, "%[^\n]\n", dato.condiciones); 
			
			if(codigo==dato.codigoAnalisis){
				bandera=false;
			}
		}
		fclose(arch);
	}
	fclose(arch);
	
	return codigo;
}

void agregarDinamico(){
	setlocale(LC_CTYPE, "Spanish");
	analisisClinicos dato={};
	bool bandera=true;
	bool bandera2=true;
	int repetir=1;
	int repetir2=1;
	regis->idDetalle=0;
	Detalle *regis2= (Detalle*)malloc(sizeof(Detalle));
	srand (time(NULL));
	int id=0;
	bool bandera3=true;
	int idreal=0;
	int primeravez=0;
	float total=0;
	int idprueba=0;
	char nombre[30]="";
	char fecha[20]="";
	char correo[30]="";
	char tel[10]="";
	
	while(bandera2){
		bandera3=true;
		
		regis->prueba.idPrueba= 10000+rand()%(9000-1000)+1;
		idprueba=regis->prueba.idPrueba;
		strcpy(regis->prueba.estado, "Activo");
		
		if(!(arch=fopen("encabezado.xls", "a"))){
			printf("Error al intentar leer el archivo");
			exit(1); //Salida fallida
		}
		fclose(arch);
		
		if(!(arch=fopen("encabezado.xls", "r"))){
			printf("Error al intentar leer el archivo");
			exit(1); //Salida fallida
		}
				
		while(!feof(arch)){ 
			fscanf(arch, "%d\t", &regis->prueba.paciente.idPaciente);
			fscanf(arch, "%[^\t]\t", regis->prueba.paciente.nombre);
			fscanf(arch, "%d\t", &regis->prueba.paciente.edad);
			fscanf(arch, "%[^\t]\t", regis->prueba.paciente.tel);
			fscanf(arch, "%[^\t]\t", regis->prueba.paciente.correo);
			fscanf(arch, "%[^\n]\n", regis->prueba.paciente.fechaHoraCita);
			
			printf("%d\t", regis->prueba.paciente.idPaciente);
			printf("%s\t", regis->prueba.paciente.nombre);
			printf("%s\n", regis->prueba.paciente.correo);	
		}
		fclose(arch);
		
		printf("\nSi aparecen tus datos en la lista ya estás registrado, solo escribe tu id (el primer número), de lo contrario pon -> 2 para crear tu perfil ");
		//esta opción permite al usuario agregar más pruebas a su registro por si se le olvido agregar alguna, ya están sus datos pero el id de prueba
		//es diferente debido a que va requerir otra factura con el nuevo estudio a realizar
		
		while(bandera3==true){
			id=validaEntero("\nId o '2': ");
			if(id==2){
				bandera3=false;
			}
			if(!(arch=fopen("encabezado.xls", "r"))){
				printf("Error al intentar leer el archivo");
				exit(1);
			}
				
			while(!feof(arch)){ 
				fscanf(arch, "%d\t", &regis->prueba.paciente.idPaciente);
				fscanf(arch, "%[^\t]\t", regis->prueba.paciente.nombre);
				fscanf(arch, "%d\t", &regis->prueba.paciente.edad);
				fscanf(arch, "%[^\t]\t", regis->prueba.paciente.tel);
				fscanf(arch, "%[^\t]\t", regis->prueba.paciente.correo);
				fscanf(arch, "%[^\n]\n", regis->prueba.paciente.fechaHoraCita);
				
				if(id==regis->prueba.paciente.idPaciente){
					idreal=id;
					bandera3=false;
				}
			}
			fclose(arch);
		}

		if(id==2){
			strcpy(nombre, "\0");
			strcpy(fecha, "\0");
			strcpy(correo, "\0");
			strcpy(tel, "\0");
			regis->prueba.paciente.idPaciente = 100+rand()%(200-100)+1;
			idreal=regis->prueba.paciente.idPaciente;
			fflush(stdin);
			validaCadena("Nombre completo: ", nombre);
			strcpy(regis->prueba.paciente.nombre, nombre);
			fflush(stdin);
			regis->prueba.paciente.edad = validaEntero("Edad: ");
			fflush(stdin);
			validaCadena("Correo electrónico: ", correo);
			strcpy(regis->prueba.paciente.correo, correo);
			fflush(stdin);
			validaTel("Teléfono: ", tel);
			strcpy(regis->prueba.paciente.tel, tel);
			fflush(stdin);
			printf("\n\tEjemplo de formato de fecha: dd/mm/aaaa, 8:00 PM/AM\n");
			ingresaCadena("Fecha y hora de la cita: ", fecha);	
			strcpy(regis->prueba.paciente.fechaHoraCita, fecha);
			
			
			if(!(arch=fopen("encabezado.xls", "a+"))){
				printf("Error al intentar leer el archivo");
				exit(1); //Salida fallida
			}
		
			fprintf(arch, "%d\t", regis->prueba.paciente.idPaciente);
			fprintf(arch, "%s\t", regis->prueba.paciente.nombre);
			fprintf(arch, "%d\t", regis->prueba.paciente.edad);
			fprintf(arch, "%s\t", regis->prueba.paciente.tel);
			fprintf(arch, "%s\t", regis->prueba.paciente.correo);
			fprintf(arch, "%s\n", regis->prueba.paciente.fechaHoraCita);
			fclose(arch);
		}
		
		while(bandera){
			system("cls");
			if(id==2){
				printf("%d\t", regis->prueba.idPrueba);
				printf("%s\n", regis->prueba.estado);
				printf("%d\t", regis->prueba.paciente.idPaciente);
				printf("%s\t", regis->prueba.paciente.nombre);
				printf("%d\t", regis->prueba.paciente.edad);
				printf("%s\t", regis->prueba.paciente.correo);
				printf("%s\t", regis->prueba.paciente.tel);
				printf("%s\t", regis->prueba.paciente.fechaHoraCita);
			}else{
				if(!(arch=fopen("encabezado.xls", "r"))){
					printf("Error al intentar leer el archivo");
					exit(1);
				}
				while(!feof(arch)){ 
					fscanf(arch, "%d\t", &regis->prueba.paciente.idPaciente);
					fscanf(arch, "%[^\t]\t", regis->prueba.paciente.nombre);
					fscanf(arch, "%d\t", &regis->prueba.paciente.edad);
					fscanf(arch, "%[^\t]\t", regis->prueba.paciente.tel);
					fscanf(arch, "%[^\t]\t", regis->prueba.paciente.correo);
					fscanf(arch, "%[^\n]\n", regis->prueba.paciente.fechaHoraCita);
					
					if(id==regis->prueba.paciente.idPaciente){
						printf("%d\t", regis->prueba.idPrueba);
						printf("%s\n", regis->prueba.estado);
						printf("%d\t", regis->prueba.paciente.idPaciente);
						printf("%s\t", regis->prueba.paciente.nombre);
						printf("%d\t", regis->prueba.paciente.edad);
						printf("%s\t", regis->prueba.paciente.tel);
						printf("%s\t", regis->prueba.paciente.correo);
						printf("%s\n", regis->prueba.paciente.fechaHoraCita);
					}
				}
				fclose(arch);
			}
		
			leer_archivo();
			regis->idDetalle++;
			
			regis->inf.codigoAnalisis = validaCodigo();
			dato = buscaCodigo(regis->inf.codigoAnalisis);
		
			regis->inf.codigoAnalisis = dato.codigoAnalisis;
			strcpy(regis->inf.tipoDeAnalisis, dato.tipoDeAnalisis);
			regis->inf.precio=dato.precio;
			strcpy(regis->inf.condiciones, dato.condiciones);
		
			if(!(arch=fopen("detalle.xls", "a+"))){
				printf("Error al intentar leer el archivo");
				exit(1); //Salida fallida
			}
			
			fprintf(arch, "%s\t", regis->prueba.estado);
			if(id==2){
				fprintf(arch, "%d\t", regis->prueba.paciente.idPaciente);	
			}else{
				fprintf(arch, "%d\t", idreal);
			}
			fprintf(arch, "%d\t", regis->idDetalle);
			fprintf(arch, "%d\t", regis->prueba.idPrueba);
			fprintf(arch, "%d\t", regis->inf.codigoAnalisis);
			fprintf(arch, "%s\t", regis->inf.tipoDeAnalisis);
			fprintf(arch, "%.2f\t", regis->inf.precio);
			fprintf(arch, "%s\n", regis->inf.condiciones);
			fclose(arch);
		
			printf("\n\nRegistro agregado\n");
			repetir=validaOpc("\n\n¿Quieres agregar otro analisis? 1->si | 2-> no: ");
		
			if(repetir==2){
				//bandera = false;
				system("cls");
				
				bandera = false;
				getch();
				system("cls");
				system("color E0");
				printf("\n\n--------------Analisis del paciente (Factura)--------\n\n");
				if(!(arch=fopen("encabezado.xls", "r"))){
					printf("Error al intentar leer el archivo");
					exit(1); 
				}
				while(!feof(arch)){ 
					fscanf(arch, "%d\t", &regis->prueba.paciente.idPaciente);
					fscanf(arch, "%[^\t]\t", regis->prueba.paciente.nombre);
					fscanf(arch, "%d\t", &regis->prueba.paciente.edad);
					fscanf(arch, "%[^\t]\t", regis->prueba.paciente.tel);
					fscanf(arch, "%[^\t]\t", regis->prueba.paciente.correo);
					fscanf(arch, "%[^\n]\n", regis->prueba.paciente.fechaHoraCita);
					
					if(idreal==regis->prueba.paciente.idPaciente){
						printf("\tID del paciente: ");
						printf("%d\n", regis->prueba.paciente.idPaciente);
						printf("\tNombre completo: ");
						printf("%s\n", regis->prueba.paciente.nombre);
						printf("\tEdad: ");
						printf("%d\n", regis->prueba.paciente.edad);
						printf("\tTeléfono: ");
						printf("%s\n", regis->prueba.paciente.tel);
						printf("\tCorreo electrónico: ");
						printf("%s\n", regis->prueba.paciente.correo);
						printf("\tFecha y hora de la cita: ");
						printf("%s\n", regis->prueba.paciente.fechaHoraCita);
					}
				}
				cuadro(0, 3, 151, 11);
				system("color E0");
				fclose(arch);
				if(!(arch2=fopen("detalle.xls", "r"))){
					printf("Error al intentar leer el archivo");
					exit(1); //Salida fallida
				}
				primeravez=1;
				while(!feof(arch2)){ 
					fscanf(arch2, "%[^\t]\t", &regis2->prueba.estado);
					fscanf(arch2, "%d\t", &regis2->prueba.paciente.idPaciente);
					fscanf(arch2, "%d\t", &regis2->idDetalle);
					fscanf(arch2, "%d\t", &regis2->prueba.idPrueba);
					fscanf(arch2, "%d\t", &regis2->inf.codigoAnalisis);
					fscanf(arch2, "%[^\t]\t", regis2->inf.tipoDeAnalisis);
					fscanf(arch2, "%f\t", &regis2->inf.precio);
					fscanf(arch2, "%[^\n]\n", regis2->inf.condiciones);
					
					
					if(idreal==regis2->prueba.paciente.idPaciente and idprueba==regis2->prueba.idPrueba){
						if(primeravez==1){
							printf("\n\nNúmero de prueba: ");
							printf("%d\n", regis2->prueba.idPrueba);
							printf("Estado: ");
							printf("%s\n", regis2->prueba.estado);
							printf("\n\tNúmero de análisis (id detalle):     Código de análisis:     Pruebas a realizar:   Precios:       Condiciones: \n");
							printf("-----------------------------------------------------------------------------------------------------------------------------\n");
							primeravez=2;
						}
						printf("\t%d\t", regis2->idDetalle);
						printf("%d\t", regis2->inf.codigoAnalisis);
						printf("%s\t", regis2->inf.tipoDeAnalisis);
						printf("%.2f\t", regis2->inf.precio);
						printf("%s\n", regis2->inf.condiciones);
						
						total+=regis2->inf.precio;
					}
				}
				cuadro(0, 15, 151, 28);
				system("color E0");
				fclose(arch2);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 228);
				printf("\n\nTOTAL:  %.3f", total);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 224);
			}
		} 
		repetir2=validaOpc("\n\n¿Quieres registrar otro paciente? 1->si | 2-> no: ");
		if(repetir2==1){
			system("color 0A");
			bandera=true;
			regis->idDetalle=0;
			total=0;
			system("cls");
			gotoxy(10,4);
			printf("Registro de pruebas\n");
		}
		if(repetir2==2){
			bandera2=false;
		}
	}
		
}


