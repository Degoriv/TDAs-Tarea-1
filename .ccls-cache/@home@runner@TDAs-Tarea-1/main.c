#include "tdas/list.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct tipoPaciente {
	int prioridad;
  char *nombre;
	int edad;
	char *sintoma;
 	int hora; // Por ahora sera solamente sera un contador
} tipoPaciente;

// Función para limpiar la pantalla
void limpiarPantalla() { system("clear"); }

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

void registrar_paciente(List *listaPacientes) {
	tipoPaciente *paciente = malloc(sizeof(tipoPaciente));
	printf("Registrar nuevo paciente\n");
	
	printf("Ingresa el nombre del paciente:\n");
	scanf("%s", paciente->nombre);

	printf("Ingresa la edad del paciente:\n");
	scanf("s", &paciente->edad);
	

	
	// Aquí implementarías la lógica para registrar un nuevo paciente
}

void mostrar_lista_pacientes(List *listaPacientes) {
  // Mostrar pacientes en la cola de espera
  printf("Pacientes en espera: \n");
  // Aquí implementarías la lógica para recorrer y mostrar los pacientes
}

int main() {
  char opcion;
  List *listaPacientes =
      list_create(); // puedes usar una lista para gestionar los pacientes

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
