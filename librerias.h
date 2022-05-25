#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#include <time.h>

void gotoxy(int x, int y){
	HANDLE hcon= GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dWPos;
	dWPos.X = x;
	dWPos.Y = y;
	SetConsoleCursorPosition(hcon, dWPos);
}

struct analisisClinicos{
	int codigoAnalisis;
	char tipoDeAnalisis[30];
	float precio;
	char condiciones[200];
};

analisisClinicos listaDatos[] ={
	{111, "Biometría hemática", 700, "Ayuno de 4 horas"},
	{112, "Examen general de orina", 650, "Recolectar en un vaso clinico la primera orina del día, no debe estar menstruando (mujeres)"},
	{113, "Hemoglobina glucosilada", 300, "No requiere indicaciones"},
	{114, "Prueba de Glucosa", 100, "Ayuno de 8 a 10 horas"},
	{115, "Prueba de embarazo", 250, "No requiere indicaciones"},
	{116, "Química sanguínea", 600, "Ayundo de 8 a 12 horas"},
	{117, "Reacciones febriles", 2300, "Ayuno de 8 horas"},
	{118, "Ultrasonido obstétrico", 1800, "Presentar orden médica, acudir con 1/2 L de agua potable, acudir con blusa y pantalón"},
	{119, "Prueba COVID-19 (PCR)", 1700, "Acudir con cubrebocas KN-95"},
	{120, "Electrocardiograma", 1500, "Presentar orden médica, Ropa cómoda, no uso de cremas ni perfumes, no portar objetos metálicos"}
};

typedef struct{
	int idPaciente;
	char nombre[30];
	int edad;
	char tel[20];
	char correo[30];
	char fechaHoraCita[20];
}Paciente;

typedef struct{
	int idPrueba;
	char estado[10];
	Paciente paciente;
	//Detalle detalle;
}Prueba;

typedef struct{
	int idDetalle;
	Prueba prueba;
	analisisClinicos inf;
}Detalle;

enum MENU {OPC1=1, OPC2, OPC3, OPC4, OPC5, OPC6, OPC7};

FILE *arch = NULL;
FILE *arch2 = NULL;
Detalle *regis= (Detalle*)malloc(sizeof(Detalle));


#include "validaciones.h"
#include "decorar.h"
#include "leer.h"
#include "estructura.h"
#include "estrucApuntador.h"
#include "pruebas.h"
#include "menu.h"



