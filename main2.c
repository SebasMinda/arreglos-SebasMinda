#include <stdio.h>
#include <string.h>
int main()
{
    int len;
    int estudiantes = 5, status;
    int asignaturas = 3, opc;
    int notaAprobatoria = 6;
    float notas[5][3];
    float sumaEstudiante, sumaAsignatura;
    int aprobados[3] = {0};
    int reprobados[3] = {0};
    char nombreEstudiantes[5][20];
    int cont = 0, cont2 = 0, cont3;

#define Rojo "\x1B[31m"
#define Verde "\x1B[32m"
#define Celeste "\x1B[36m"
#define Reset "\x1B[0m"

    do
    {
        do
        {
            printf(Celeste "\n=== BIENVENIDO AL PROGRAMA DE CALIFICACIONES ===\n" Reset);
            printf("Seleccione una de las opciones\n");
            printf(Celeste "1." Reset " Ingreso de calificaciones\n");
            printf(Celeste "2." Reset " Aprobados y reprobados por asignatura\n");
            printf(Celeste "3." Reset " Promedios, maximos y minimos por estudiante\n");
            printf(Celeste "4." Reset " Promedios, maximos, minimos y aprobaciones por asignatura\n");
            printf(Celeste "5." Reset " Salir\n");
            printf("Ingrese su opcion: ");
            status = scanf("%d", &opc);
            if (status == 0 || opc < 1 || opc > 6)
            {
                printf(Rojo "\nEntrada invalida.\n" Reset);
                while (getchar() != '\n')
                    ; // Limpiar el buffer de entrada
            }
        } while (opc < 1 || opc > 6 || status == 0);

        switch (opc)
        {
        case 1:
            if (cont == estudiantes)
            {
                printf("\nYa se han ingresado las notas de todos los estudiantes.\n");
                break;
            }
            printf(Celeste "\n=== INGRESO DE CALIFICACIONES ===\n" Reset);
            while (cont < estudiantes)
            {
                for (int i = 0; i < cont + 1; i++)
                {
                    printf("\nEstudiante %d:\n\n", cont + 1);
                    for (int j = 0; j < asignaturas; j++)
                    {
                        do
                        {
                            printf("Ingrese la nota del estudiante %d en la asignatura %d (0 a 10): ", cont + 1, j + 1);
                            status = scanf("%f", &notas[cont][j]);
                            if (status == 0 || notas[cont][j] < 0 || notas[cont][j] > 10)
                            {
                                printf(Rojo "Entrada invalida.\n" Reset);
                                while (getchar() != '\n')
                                    ;
                            }
                        } while (notas[cont][j] < 0 || notas[cont][j] > 10 || status == 0);
                        if (notas[cont][j] >= notaAprobatoria)
                        {
                            aprobados[j]++;
                        }
                        else
                        {
                            reprobados[j]++;
                        }
                    }
                    break;
                }
                cont++;
            }
            break;

        case 2:
            if (cont < estudiantes)
            {
                printf(Rojo "\nNo se han registrado los estudiantes todavia.\n" Reset);
                break;
            }
            // Aprobados y reprobados por asignatura
            printf(Celeste "\n=== APROBADOS Y REPROBADOS POR ASIGNATURA ===\n" Reset);
            for (int j = 0; j < asignaturas; j++)
            {
                printf("Asignatura %d -> Aprobados: %d | Reprobados: %d\n",
                       j + 1, aprobados[j], reprobados[j]);
            }
            break;
        case 3:
            if (cont < estudiantes)
            {
                printf(Rojo "\nNo se han registrado los estudiantes todavia.\n" Reset);
                break;
            }
            printf(Celeste "\n=== LISTADO DE ESTUDIANTES ===\n");
            for (int i = 0; i < cont; i++)
            {
                printf("Estudiante %d: "Reset, i + 1);
                for (int j = 0; j < asignaturas; j++)
                {
                    printf("Asignatura %d: %.2f ", j + 1, notas[i][j]);
                }
                printf("\n");
            }

            printf("\n=== PROMEDIOS POR ESTUDIANTE ===\n");
            for (int i = 0; i < estudiantes; i++)
            {
                sumaEstudiante = 0;
                float max = notas[i][0], min = notas[i][0];
                for (int j = 0; j < asignaturas; j++)
                {
                    float nota = notas[i][j];
                    sumaEstudiante += nota;
                    if (nota > max)
                        max = nota;
                    if (nota < min)
                        min = nota;
                }
                printf("Estudiante %d -> Promedio: %.2f | Nota Max: %.2f | Nota Min: %.2f\n", i + 1, sumaEstudiante / asignaturas, max, min);
            }
            break;
        case 4:
            if (cont < estudiantes)
            {
                printf(Rojo "\nNo se han registrado los estudiantes todavia.\n" Reset);
                break;
            }
            // Promedios, máximos, mínimos y aprobaciones por asignatura
            printf(Celeste"\n=== PROMEDIOS POR ASIGNATURA ===\n"Reset);
            for (int j = 0; j < asignaturas; j++)
            {
                sumaAsignatura = 0;
                float max = notas[0][j], min = notas[0][j];
                for (int i = 0; i < estudiantes; i++)
                {
                    float nota = notas[i][j];
                    sumaAsignatura += nota;
                    if (nota > max)
                        max = nota;
                    if (nota < min)
                        min = nota;
                    if (nota >= notaAprobatoria)
                    {
                        aprobados[j]++;
                    }
                    else
                    {
                        reprobados[j]++;
                    }
                }
                printf(Celeste"Asignatura %d -> "Reset"Promedio: %.2f | Nota Max: %.2f | Nota Min: %.2f\n",
                       j + 1, sumaAsignatura / estudiantes, max, min);
            }
        case 5:
            printf("=== SALIR ===\n");
            printf("Saliendo del programa...\n");
            break;
        default:
            printf("Opción inválida. Por favor, elija una opción válida.\n");
            break;
        }
    } while (opc != 6);
    return 0;
}