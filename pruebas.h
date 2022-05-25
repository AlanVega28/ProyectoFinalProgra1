int buscarPrueba(int prueba){
	setlocale(LC_CTYPE, "Spanish");
	Detalle *regis2= (Detalle*)malloc(sizeof(Detalle));
	int y=5;
	if(!(arch=fopen("detalle.xls", "r"))){
		printf("Error al intentar leer el archivo");
		exit(1); //Salida fallida
	}
	printf("Estado\t\tidDetalle\tNo.prueba\tTipo de prueba");	
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
		
		if(prueba==regis2->prueba.idPrueba){
			gotoxy(0, y);
			printf("%s\t", regis2->prueba.estado);
			gotoxy(17, y);
			printf("%d\t\t", regis2->idDetalle);
			gotoxy(33, y);
			printf("%d\t\t", regis2->prueba.idPrueba);
			gotoxy(49, y);
			printf("%s\n", regis2->inf.tipoDeAnalisis);
		}
	}
	fclose(arch);
	return 0;
}



int buscarDetalle(int prueba, int idDetalle, char estado[]){
	setlocale(LC_CTYPE, "Spanish");
	Detalle *regis2= (Detalle*)malloc(sizeof(Detalle));

		
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
		if(prueba==regis2->prueba.idPrueba){
			if(idDetalle == regis2->idDetalle){
				strcpy(estado, regis2->prueba.estado);
				printf("%s\t", regis2->prueba.estado);
				printf("%d\t", regis2->prueba.idPrueba);
				printf("%d\t", regis2->idDetalle);
				printf("%s\n", regis2->inf.tipoDeAnalisis);
			}
		}
	}
	fclose(arch);
	return 0;
}

int validaPrueba(){
	setlocale(LC_CTYPE, "Spanish");
	Detalle *regis2= (Detalle*)malloc(sizeof(Detalle));
	int prueba=0;
	bool bandera=true;
	
	while(bandera){
		bandera=true;
		prueba=validaEntero("\n\nNo. de prueba: ");
			
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
			
			if(prueba==regis2->prueba.idPrueba){
				bandera=false;
			}
		}
		fclose(arch);
	}
	return prueba;
}

int validaDetalle(int prueba){
	setlocale(LC_CTYPE, "Spanish");
	Detalle *regis2= (Detalle*)malloc(sizeof(Detalle));
	int detalle=0;
	bool bandera=true;

	
	while(bandera){
		bandera=true;
		detalle=validaEntero("\nid del detalle de estado a modificar: ");
			
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
			if(prueba==regis2->prueba.idPrueba and detalle==regis2->idDetalle){
				bandera=false;
			}
		}
	}
	fclose(arch);
	return detalle;
}

void cancelarPrueba(int prueba){
	setlocale(LC_CTYPE, "Spanish");
	Detalle *regis2= (Detalle*)malloc(sizeof(Detalle));
	char canc[10]="Cancelada";
	bool bandera=false;
	
	if(!(arch=fopen("detalle.xls", "r"))){
		printf("Error al intentar leer el archivo");
		exit(1); //Salida fallida
	}
	if(!(arch2=fopen("copiaPrueba.xls", "a+"))){
		printf("Error al intentar leer el archivo");
		exit(1); //Salida fallida
	}
			
			while(!feof(arch)){ 
				fscanf(arch, "%[^\t]\t", regis2->prueba.estado);
				fscanf(arch, "%d\t", &regis2->prueba.paciente.idPaciente);
				fscanf(arch, "%d\t", &regis2->idDetalle);
				fscanf(arch, "%d\t", &regis2->prueba.idPrueba);
				fscanf(arch, "%d\t", &regis2->inf.codigoAnalisis);
				fscanf(arch, "%[^\t]\t", regis2->inf.tipoDeAnalisis);
				fscanf(arch, "%f\t", &regis2->inf.precio);
				fscanf(arch, "%[^\n]\n", regis2->inf.condiciones);
				
				if(prueba==regis2->prueba.idPrueba){
					strcpy(regis2->prueba.estado, canc);
					bandera=true;
				}
				fprintf(arch2, "%s\t", regis2->prueba.estado);
				fprintf(arch2, "%d\t", regis2->prueba.paciente.idPaciente);
				fprintf(arch2, "%d\t", regis2->idDetalle);
				fprintf(arch2, "%d\t", regis2->prueba.idPrueba);
				fprintf(arch2, "%d\t", regis2->inf.codigoAnalisis);
				fprintf(arch2, "%s\t", regis2->inf.tipoDeAnalisis);
				fprintf(arch2, "%f\t", regis2->inf.precio);
				fprintf(arch2, "%s\n", regis2->inf.condiciones);
			}
			if(bandera==false){
				printf("\nOcurrio un error al actualizar el estado");
			}else{
				printf("\nEstado actualizado");
			}
			fclose(arch);
			fclose(arch2);
			remove("detalle.xls");
			rename("copiaPrueba.xls", "detalle.xls");
}
			


void modificarEstado(){
	setlocale(LC_CTYPE, "Spanish");
	Detalle *regis2= (Detalle*)malloc(sizeof(Detalle));
	bool bandera=true;
	bool bandera2=true;
	bool bandera3=true;
	char repetir='s';
	char repetir2='s';
	int prueba=0;
	int idDetalle=0;
	char estado[10]="";
	FILE *arch2;
	char active[10]="Activo";
	char reali[10]="Realizada";
	char env[10]="Enviada";
	char canc[10]="Cancelada";
	char opcActiva=0;
	//int opc=0
	char opc2=' ';
	int entrada=0;
	char opcCancelar=' ';
	
	while(bandera2){
		leer_pruebas();
		prueba=validaPrueba();
		printf("\n\n--------------Pruebas en el documento--------------\n\n");
		buscarPrueba(prueba);

		while(bandera){
			bandera3=true;
			entrada=0;
			system("cls");
			printf("\n\n--------------Pruebas en el documento--------------\n\n");
			buscarPrueba(prueba);
			
			opcCancelar=validaSN("\n\n¿Desea cancelar todos los analisis? (s/n): ");
			if(opcCancelar=='s' || opcCancelar=='S'){
				cancelarPrueba(prueba);
				opcCancelar=validaSN("\n\n¿Desea cambiar el estado de otro analisis? (s/n): ");
				if(opcCancelar=='s' || opcCancelar=='S'){
					system("cls");
					printf("\n\n--------------Pruebas en el documento--------------\n\n");
					buscarPrueba(prueba);
				}else{
					break;
				}
			}else{
				system("cls");
				printf("\n\n--------------Pruebas en el documento--------------\n\n");
				buscarPrueba(prueba);
			}
			
			idDetalle=validaDetalle(prueba);
			
			printf("\n\n--------------Estado actual de la prueba--------------\n\n");
			
			
			buscarDetalle(prueba, idDetalle, estado);
			
			if(strcmp(estado, active)==0){
				/*do{
					opc=validaEntero("\n¿A que estado desea cambiar la prueba?\n\t1.Realizada 2. Cancelada\n\t--> ");
				}while(opc!=1 && opc!=2);
					switch(opc){
						OPC1:
							strcpy(estado, reali);
							break;
						OPC2:
							strcpy(estado, canc);
							break;
					}*/
					
					//opcActiva=validaSN("\n¿Esta prueba esta activa, desea cambiar el estado a realizada?(s/n)--> ");
					opc2=validaChar("\n¿Esta prueba esta activa, desea cambiar el estado a realizada?(s/n)--> ");
					entrada=1;
					if(opc2=='s' || opc2=='S'){
					strcpy(estado, reali);
					}
					if(opc2=='n' || opc2=='N'){
					strcpy(estado, active);
					}				
			}
			if(strcmp(estado, reali)==0 && !(entrada==1)){
				do{
					opc2=validaChar("\nEsta prueba esta realizada, ¿Desea enviarla?(s/n) -->");
				}while(!(opc2=='s') && !(opc2=='S') && !(opc2=='N') && !(opc2=='n'));
				entrada=2;
				if(opc2=='s' || opc2=='S'){
					strcpy(estado, env);
				}
				if(opc2=='n' || opc2=='N'){
					strcpy(estado, reali);
				}
			}
			if(strcmp(estado, canc)==0 && !(entrada==1) && !(entrada==2)){
				do{
					opc2=validaChar("\nEsta prueba esta cancelada, ¿Desea activarla?(s/n) -->");
				}while(!(opc2=='s') && !(opc2=='S') && !(opc2=='N') && !(opc2=='n'));
				
				if(opc2=='s' || opc2=='S'){
					strcpy(estado, active);
				}
				if(opc2=='n' || opc2=='N'){
					strcpy(estado, canc);
				}
			}
			if(strcmp(estado, env)==0 && !(entrada==1)  && !(entrada==2)){
				entrada=3;
				printf("\nEsta prueba ya fue enviada\n");
				strcpy(regis2->prueba.estado, estado);
			}			
			
			if(!(arch=fopen("detalle.xls", "r"))){
				printf("Error al intentar leer el archivo");
				exit(1); //Salida fallida
			}
			if(!(arch2=fopen("copiaPrueba.xls", "a+"))){
				printf("Error al intentar leer el archivo");
				exit(1); //Salida fallida
			}
			
			while(!feof(arch)){ 
				fscanf(arch, "%[^\t]\t", regis2->prueba.estado);
				fscanf(arch, "%d\t", &regis2->prueba.paciente.idPaciente);
				fscanf(arch, "%d\t", &regis2->idDetalle);
				fscanf(arch, "%d\t", &regis2->prueba.idPrueba);
				fscanf(arch, "%d\t", &regis2->inf.codigoAnalisis);
				fscanf(arch, "%[^\t]\t", regis2->inf.tipoDeAnalisis);
				fscanf(arch, "%f\t", &regis2->inf.precio);
				fscanf(arch, "%[^\n]\n", regis2->inf.condiciones);
				
				if(prueba==regis2->prueba.idPrueba and idDetalle==regis2->idDetalle){
					strcpy(regis2->prueba.estado, estado);
					bandera3=true;
				}
				fprintf(arch2, "%s\t", regis2->prueba.estado);
				fprintf(arch2, "%d\t", regis2->prueba.paciente.idPaciente);
				fprintf(arch2, "%d\t", regis2->idDetalle);
				fprintf(arch2, "%d\t", regis2->prueba.idPrueba);
				fprintf(arch2, "%d\t", regis2->inf.codigoAnalisis);
				fprintf(arch2, "%s\t", regis2->inf.tipoDeAnalisis);
				fprintf(arch2, "%f\t", regis2->inf.precio);
				fprintf(arch2, "%s\n", regis2->inf.condiciones);
			}
			if(bandera3==false){
				printf("\nOcurrio un error al actualizar el estado");
			}else{
				if(!(entrada==3)){
					printf("\nEstado actualizado");
				}
			}
			fclose(arch);
			fclose(arch2);
			remove("detalle.xls");
			rename("copiaPrueba.xls", "detalle.xls");
			
			repetir=validaSN("\n\n¿Quiere modificar otro estado? (s/n): ");
	
			if(repetir=='n' || repetir=='N'){
				//bandera = false;
				system("cls");
				printf("\n\n--------------Estado de las pruebas del paciente-------\n\n");
				buscarPrueba(prueba);
				bandera=false;
			}
		} 
		repetir2=validaSN("\n\n¿Quiere modificar el estado de otro no. de prueba? (s/n): ");
		if(repetir2=='s' || repetir2=='S'){
			bandera=true;
			prueba=0;
			idDetalle=0;
			system("cls");
			gotoxy(10,4);
			printf("Modificar estado de la prueba\n");
		}
		if(repetir2=='n' || repetir2=='N'){
			bandera2=false;
		}
	}	
}

