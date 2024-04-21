# Codigo una lista de espera en un hospital

## 1 - Ejecutar el codigo
Para ejecutar el main primero debemos compilar (en la carpeta raíz)
````
gcc tdas/*.c main.c -Wno-unused-result -o main
````

Y luego ejecutar:
````
./main
````


## Funcionamiento del codigo
Al ejecutarse el codigo, se abre un menu con todas las opciones disponibles
````
========================================
     Sistema de Gestión Hospitalaria
========================================
1) Registrar paciente
2) Asignar prioridad a paciente
3) Mostrar lista de espera
4) Atender al siguiente paciente
5) Mostrar pacientes por prioridad
6) Salir
Ingrese su opción:_
````
Cuando se selecciona la opción para registrar un paciente, el programa solicitará al usuario que ingrese la informacion del paciente,
pidiendo el nombre, edad, sintoma, guardando todo eso en un struct.
````
typedef struct tipoPaciente {
  int prioridad;
  char nombre[MAX];
  int edad;
  char sintoma[MAX];
  time_t hora;
} tipoPaciente;
````
Para estandarizar los strings y facilitar las busquedas, se guarda el nombre y el sintoma con mayusculas. <br>
Funcion para transformar a mayuscula: `void strMay(char *cadena)` <br>
Funcion para registrar el paciente: `void registrar_paciente(List *listaPacientes)` <br>

Para asignar una prioridad diferente a un paciente registrado, el usuario podrá seleccionar la opción correspondiente en el menú y 
especificar el nombre del paciente. Luego, se mostrará la prioridad actual del paciente y se solicitará al usuario que ingrese la nueva
prioridad deseada. <br>
*Nota: Si al momento de ingresar la prioridad, el usuario ingresa caracteres, se hace un bucle*<br><br>
Apenas se cambia la proridad de un paciente, la funcion `void ordenar_por_prioridad(List *listaPacientes)` ordena la lista.<br><br>
Funcion usada para cambiar prioridad: `void asignar_prioridad(List *listaPacientes)`
<br>
<br>

La funcion `void mostrar_lista_pacientes(List *listaPacientes)` y `void mostrar_lista_prioridad(List *listaPacientes)` <br>
tienen la misma logica, las dos muestran a los pacientes en una tabla, la diferencia es que la funcion de mostrar prioridad <br>
solo imprime los pacientes con la prioridad ingresada:

Funcion `void mostrar_lista_pacientes(List *listaPacientes)`:<br>
````
=============================================================================
|                          Pacientes en espera: 7                           |
=============================================================================
| Nombres              | Edad       | Sintoma                   | Prioridad |
=============================================================================
| JAVIERA MUNOZ        | 18         | DEMENCIA                  | Alto      |
| SON GOKU             | 28         | ENFERMEDAD AL CORAZON     | Alto      |
| NICOLAS              | 20         | PERDIO UN DEDO            | Alto      |
| BOB ESPONJA          | 34         | ASTILLA EN EL DEDO        | Alto      |
| OSCAR                | 20         | COMA ETILICO              | Media     |
| CONY                 | 20         | TIENE TUTO                | Baja      |
| PAM BEESLY           | 27         | NANOROBOTS ASESINOS       | Baja      |
````
Funcion `void mostrar_lista_prioridad(List *listaPacientes)` mostrando la prioridad Alta:<br>
````
=============================================================================
|                          Pacientes en espera: 4                           |
=============================================================================
| Nombres              | Edad       | Sintoma                   | Prioridad |
=============================================================================
| JAVIERA MUNOZ        | 18         | DEMENCIA                  | Alto      |
| SON GOKU             | 28         | ENFERMEDAD AL CORAZON     | Alto      |
| NICOLAS              | 20         | PERDIO UN DEDO            | Alto      |
| BOB ESPONJA          | 34         | ASTILLA EN EL DEDO        | Alto      |
````
En el archivo `Input_Sugerido.txt` hay una sugerencia de entrada, que deja la lista con pacientes registrados y prioridades cambiadas:
