int validaEntero(const char mensaje[]){
	int continuar=0;
	int entero=0;
	do{
		printf("%s", mensaje);
		continuar = scanf("%d", &entero);
		fflush(stdin);
	}while(continuar != 1 or entero<0);
	
	return entero;
}

float validaFlotante(const char mensaje[]){
	int continuar=0;
	float flotante=0;
	//int num=0;
	
	do{		
	printf("%s", mensaje);
	continuar = scanf("%f", &flotante);
	fflush(stdin);
	}while(continuar != 1 or flotante<0);
		
	return flotante;
	//return num;
}

void validaCadena(const char mensaje[], char cadena[]){
	SetConsoleCP(1252);
	SetConsoleOutputCP(1252);
	bool bandera=true;
	int espacio=0;
	
	while(bandera){
		printf("%s", mensaje);
		scanf("%[^\n]", cadena);
		fflush(stdin);
		if(strlen(cadena)>200){
			continue;
		}else{
			for(int i=0;i<strlen(cadena);i++){
				if(isalpha(cadena[i]) || cadena[i]==' ' || cadena[i]==',' || cadena[i]=='(' || cadena[i]==')' || cadena[i]=='@' || cadena[i]=='.' || cadena[i]=='-'){
					if(cadena[i]==13){
						espacio=1;
					}
					if(i==(strlen(cadena)-1) && espacio==0){
						bandera=false;
					}
				}else{
					break;
				}
			}
		}
	}
}

void validaTel(const char mensaje[], char cadena[]){
	SetConsoleCP(1252);
	SetConsoleOutputCP(1252);
	bool bandera=true;
	
	while(bandera){
		printf("%s", mensaje);
		scanf("%[^\n]", cadena);
		fflush(stdin);
		
		if(strlen(cadena)>10){
			continue;
		}else{
			for(int i=0;i<strlen(cadena);i++){
					if(isdigit(cadena[i])){
						if(i== (strlen(cadena)-1) && !(cadena[i]==13)){
							bandera=false;
						}
					}else{
						break;
					}
				}
			
		}
	}
}

/*void validaFecha(const char mensaje[], char cadena[]){
	SetConsoleCP(1252);
	SetConsoleOutputCP(1252);
	bool bandera=true;
	int espacio=0, diagonal=0, coma=0, puntos=0;
	
	while(bandera){
		printf("%s", mensaje);
		scanf("%[^\n]", cadena);
		
		fflush(stdin);
		if(strlen(cadena)>20){
			continue;
		}else{
			for(int i=0;i<strlen(cadena);i++){
					if(isdigit(cadena[i]) || isalpha(cadena[i]) || cadena[i]=='/' || cadena[i]==' ' || cadena[i]==',' || cadena[i]==':' ){
						if(cadena[i]==' '){
							espacio++;
						};
						if(cadena[i]=='/'){
							diagonal++;
						};
						if(cadena[i]==','){
							coma++;
						};
						if(cadena[i]==':'){
							puntos++;
						};
						if(i== (strlen(cadena)-1) && !(cadena[i]==13) && espacio==2 && diagonal==4 && coma==1 && puntos==1){
							bandera=false;
						}
					}else{
						break;
					}
			}
		}
	}
}*/

void ingresaCadena(const char mensaje[], char cadena[]){
	SetConsoleCP(1252);
	SetConsoleOutputCP(1252);
	bool bandera=true;
	
	while(bandera){
		printf("%s", mensaje);
		scanf("%[^\n]", cadena);
		
		fflush(stdin);
		if(strlen(cadena)>200){
			continue;
		}else{
			for(int i=0;i<strlen(cadena);i++){
					if(isdigit(cadena[i]) || isalpha(cadena[i]) || cadena[i]=='/' || cadena[i]==' ' || cadena[i]==',' || cadena[i]=='(' || cadena[i]==')' || cadena[i]=='#' || cadena[i]=='.' || cadena[i]==':' ){
						if(i== (strlen(cadena)-1) && !(cadena[i]==13)){
							bandera=false;
						}
					}else{
						break;
					}
			}
		}
	}
}

int validaOpc(const char mensaje[]){
	//int continuar=0;
	int entero=0;
	do{
		printf("%s", mensaje);
		scanf("%d", &entero);
		fflush(stdin);
	}while(entero!=1 && entero!=2);
	
	return entero;
}

char validaSN(const char mensaje[]){
	char letra;
	//int num=0;
	
	do{		
		printf("%s", mensaje);
		scanf("%c", &letra);
		fflush(stdin);
	}while(!(letra=='s') && !(letra=='S') && !(letra=='N') && !(letra=='n'));
		
	return letra;
}

char validaChar(const char mensaje[]){
	int continuar=0;
	char letra;
	//int num=0;
	
	do{		
		printf("%s", mensaje);
		continuar = scanf("%c", &letra);
		fflush(stdin);
	}while(continuar !=1);
		
	return letra;
}



