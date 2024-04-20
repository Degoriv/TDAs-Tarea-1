#include "tdas/list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX 100

typedef struct tipoPaciente {
	int prioridad;
	int nFicha;
  char nombre[MAX];
	int edad;
	char sintoma[MAX];
 	int hora;
} tipoPaciente;

int totalPacientes = 0;

// Función para limpiar la pantalla
void limpiarPantalla() { system("clear"); }

void strMay(char *cadena) {
		int i = 0;
		while (cadena[i] != '\0') {
				cadena[i] = toupper(cadena[i]);
				i++;
		}
}

void presioneTeclaParaContinuar() {
  puts("Presione una tecla para continuar...");
  getchar(); // Consume el '\n' del buffer de entrada
  getchar(); // Espera a que el usuario presione una tecla
}

// Menú principal
void mostrarMenuPrincipal() {
  limpiarPantalla();
  puts("========================================");
  puts("     Sistema de Gestión Hospitalaria");
  puts("========================================");

  puts("1) Registrar paciente");
  puts("2) Asignar prioridad a paciente");
  puts("3) Mostrar lista de espera");
  puts("4) Atender al siguiente paciente");
  puts("5) Mostrar pacientes por prioridad");
  puts("6) Salir");
}

void registrar_paciente(List *listaPacientes) 
{
	printf("\nRegistrar nuevo paciente \n");
	tipoPaciente *paciente = malloc(sizeof(tipoPaciente));
	if (paciente == NULL) {
		printf("ERROR DE MEMORIA");
		return;}
	
	printf("Ingresa el nombre del paciente: \n");
	getchar();
	scanf(" %[^\n]", paciente->nombre);
	
	printf("Ingresa la edad del paciente: \n");
	scanf("%i", &paciente->edad);

	printf("Ingresa el sintoma del paciente:\n");
	getchar();
	scanf(" %[^\n]", paciente->sintoma);
	
	strMay(paciente->sintoma);
	strMay(paciente->nombre);

	paciente->prioridad = 1; //Se asigna en baja automaticamente

	list_pushBack(listaPacientes, paciente);
	totalPacientes += 1;
	paciente->nFicha = totalPacientes;
}
		
void mostrar_lista_pacientes(List *listaPacientes) 
{
  printf("Pacientes en espera: \n");
	tipoPaciente *pacienteActual = list_first(listaPacientes);
	puts("=============================================================================");
	printf("|                          Pacientes en espera: %d                           |\n"
	,totalPacientes);
	puts("=============================================================================");
	printf("| %-20s | %-10s | %-25s | %-8s |\n", "Nombres", "Edad", "Sintoma", "Prioridad");
	puts("=============================================================================");
	while(pacienteActual != NULL)
		{
			char nombre[MAX];
			strcpy(nombre, pacienteActual->nombre);
			
			int edad = pacienteActual->edad;
			
			char sintoma[MAX];
			strcpy(sintoma, pacienteActual->sintoma);

			int prioridad = pacienteActual->prioridad;

			printf("| %-20s | %-10d | %-25s |", nombre, edad, sintoma);
			if (prioridad == 1) printf(" %-9s |\n", "Baja");
			else if (prioridad == 2) printf(" %-9s |\n", "Media");
			else if (prioridad == 3) printf(" %-9s |\n", "Alto");
			
			pacienteActual = list_next(listaPacientes);
		}
}

void asignPriori(List *listaPacientes)
{
	if (totalPacientes == 0){
	printf("No hay pacientes registrados /n");
	return; }
	
	printf("Ingrese el nombre del paciente del cual quiere cambiar prioridad:\n");
	getchar();
	char nombrePaciente[MAX];
	scanf(" %[^\n]", nombrePaciente);
	strMay(nombrePaciente);

	tipoPaciente *pacienteActual = list_first(listaPacientes);

	while (pacienteActual != NULL)
		{	
			if (pacienteActual->nombre == nombrePaciente){
				printf("No se ha encontrado al paciente");
				break; }
			else pacienteActual = list_next(listaPacientes);
		}
	
	printf("El paciente tiene prioridad ");
	if (pacienteActual->prioridad == 1) printf("baja");
	else if (pacienteActual->prioridad == 2) printf("media");
	else if (pacienteActual->prioridad == 3) printf("alta");

	int nuevaPrioridad;
	bool validPriori = false;

	while (!validPriori) //Bucle solamente para definir y validar el dato nuevaPrioridad
	{
		printf("\nIngrese el numero de la nueva prioridad: \n");
		printf("1 - Baja\n");
		printf("2 - Media\n");
		printf("3 - Alta\n");
		scanf("%i", &nuevaPrioridad);
		if (nuevaPrioridad == 1 || nuevaPrioridad == 2 || nuevaPrioridad == 3) validPriori = true;
		else printf("Prioridad no valida, ingrese nuevamente");
	}

	bool cambGuard = false;
	if (pacienteActual->prioridad == nuevaPrioridad) printf("No se ha hecho ningun cambio");
	else {pacienteActual->prioridad = nuevaPrioridad;
				printf("Se han guardado los cambios");}
	
}

int main() {
  char opcion;
  List *listaPacientes =
      list_create(); // Puedes usar una lista para gestionar los pacientes

  do {
    mostrarMenuPrincipal();
    printf("Ingrese su opción: ");
    scanf(" %c", &opcion); // Nota el espacio antes de %c para consumir el
                           // newline anterior

    switch (opcion) {
    case '1':
      registrar_paciente(listaPacientes);
      break;
    case '2':
      // Lógica para asignar prioridad
			asignPriori(listaPacientes);
      break;
    case '3':
      mostrar_lista_pacientes(listaPacientes);
      break;
    case '4':
      // Lógica para atender al siguiente paciente
      break;
    case '5':
      // Lógica para mostrar pacientes por prioridad
      break;
    case '6':
      puts("Saliendo del sistema de gestión hospitalaria...");
      break;
    default:
      puts("Opción no válida. Por favor, intente de nuevo.");
    }
    presioneTeclaParaContinuar();

  } while (opcion != '6');

  // Liberar recursos, si es necesario
  list_clean(listaPacientes);

  return 0;
}
