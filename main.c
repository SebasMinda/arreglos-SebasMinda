#include <stdio.h>
#include <string.h>
int main()
{
    int len, EstudiantesIngresados = 0, EstudiantesIngresados2 = 0, EstudiantesIngresados3, estudiantes = 5, status, asignaturas = 3, opc, notaAprobatoria = 6;
    float notas[5][3];
    float sumaEstudiante, sumaAsignatura;
    int aprobados[3] = {0};
    int reprobados[3] = {0};
    char nombreEstudiantes[5][20];
    char nombreAsignaturas[3][20];

#define Rojo "\x1B[31m"
#define Verde "\x1B[32m"
#define Celeste "\x1B[36m"
#define Reset "\x1B[0m"
    printf(Celeste "\n=== BIENVENIDO AL PROGRAMA DE CALIFICACIONES ===\n" Reset);
    do
    {
        do
        {
            printf("\nSeleccione una de las opciones\n");
            printf(Celeste "1." Reset " Ingreso de calificaciones\n");
            printf(Celeste "2." Reset " Aprobados y Reprobados por Asignatura\n");
            printf(Celeste "3." Reset " Promedios de Estudiantes y Asignaturas\n");
            printf(Celeste "4." Reset " Maximos y Minimos de Estudiantes y Asignaturas\n");
            printf(Celeste "5." Reset " Salir\n");
            printf("Ingrese su opcion: ");
            status = scanf("%d", &opc);
            if (status == 0 || opc < 1 || opc > 5)
            {
                printf(Rojo "\nEntrada invalida.\n" Reset);
                while (getchar() != '\n')
                    ; // Limpiar el buffer de entrada
            }
        } while (opc < 1 || opc > 6 || status == 0);

        switch (opc)
        {
        case 1:

            if (EstudiantesIngresados == estudiantes)
            {
                printf("\nYa se han ingresado las notas de todos los estudiantes.\n");
                break;
            }
            printf(Celeste "\n=== INGRESO DE CALIFICACIONES ===\n" Reset);
            for (int i = 0; i < 3; i++)
            {
                printf("\nIngrese el nombre de la asignatura %d: ", i + 1);
                scanf("%s", nombreAsignaturas[i]);
            }
            for (int i = 0; i < 5; i++)
            {
                printf("\nIngrese el nombre de estudiante %d: ", EstudiantesIngresados + 1);
                status = scanf("%s", nombreEstudiantes[EstudiantesIngresados]);

                for (int j = 0; j < 3; j++)
                {
                    do
                    {
                        printf("Ingrese la nota del estudiante %s en la asignatura de %s (0 a 10): ", nombreEstudiantes[EstudiantesIngresados], nombreAsignaturas[j]);
                        status = scanf("%f", &notas[EstudiantesIngresados][j]);
                        if (status == 0 || notas[EstudiantesIngresados][j] < 0 || notas[EstudiantesIngresados][j] > 10)
                        {
                            printf(Rojo "\nEntrada invalida.\n\n" Reset);
                            while (getchar() != '\n')
                                ;
                        }
                    } while (notas[EstudiantesIngresados][j] < 0 || notas[EstudiantesIngresados][j] > 10 || status == 0);
                    if (notas[EstudiantesIngresados][j] >= notaAprobatoria)
                    {
                        aprobados[j]++;
                    }
                    else
                    {
                        reprobados[j]++;
                    }
                }
                EstudiantesIngresados++;
            }
            break;

        case 2:
            if (EstudiantesIngresados == 0)
            {
                printf(Rojo "\nNo hay estudiantes ingresados.\n" Reset);
                break;
            }
            printf(Celeste "\n=== APROBADOS Y REPROBADOS POR ASIGNATURA ===\n" Reset);
            for (int j = 0; j < asignaturas; j++)
            {
                printf("Asignatura %s -> Aprobados: %d | Reprobados: %d\n",
                       nombreAsignaturas[j], aprobados[j], reprobados[j]);
            }
            break;
        case 3:
            if (EstudiantesIngresados == 0)
            {
                printf(Rojo "\nNo hay estudiantes ingresados.\n" Reset);
                break;
            }
            printf(Celeste "\n=== PROMEDIO DE CALIFICACIONES ===\n" Reset);
            printf(Verde "\n=== PROMEDIO POR ESTUDIANTE ===\n" Reset);
            for (int i = 0; i < EstudiantesIngresados; i++)
            {
                sumaEstudiante = 0;
                for (int j = 0; j < asignaturas; j++)
                {
                    sumaEstudiante += notas[i][j];
                }
                printf("Estudiante %s -> Promedio: %.2f\n", nombreEstudiantes[i], sumaEstudiante / asignaturas);
            }
            printf(Verde "\n=== PROMEDIO POR ASIGNATURA ===\n" Reset);
            for (int j = 0; j < asignaturas; j++)
            {
                sumaAsignatura = 0;
                for (int i = 0; i < EstudiantesIngresados; i++)
                {
                    sumaAsignatura += notas[i][j];
                }
                printf("Asignatura %s -> Promedio: %.2f\n", nombreAsignaturas[j], sumaAsignatura / EstudiantesIngresados);
            }
            break;
        case 4:
            if (EstudiantesIngresados == 0)
            {
                printf(Rojo "\nNo hay estudiantes ingresados.\n" Reset);
                break;
            }

            printf(Celeste "\n=== CALIFICACION MAS ALTA Y MAS BAJA ===\n" Reset);
            printf(Verde "\n=== CALIFICACION MAS ALTA Y MAS BAJA POR ESTUDIANTE ===\n" Reset);
            for (int i = 0; i < EstudiantesIngresados; i++)
            {
                float maxEstudiante = notas[i][0];
                float minEstudiante = notas[i][0];

                for (int j = 1; j < asignaturas; j++)
                {
                    if (notas[i][j] > maxEstudiante)
                    {
                        maxEstudiante = notas[i][j];
                    }
                    if (notas[i][j] < minEstudiante)
                    {
                        minEstudiante = notas[i][j];
                    }
                }

                printf("Estudiante %s -> Maxima: %.2f | Minima: %.2f\n", nombreEstudiantes[i], maxEstudiante, minEstudiante);
            }
            printf(Verde "\n=== CALIFICACION MAS ALTA Y MAS BAJA POR ASIGNATURA ===\n" Reset);
            for (int j = 0; j < asignaturas; j++)
            {
                float maxAsignatura = notas[0][j];
                float minAsignatura = notas[0][j];

                for (int i = 0; i < 5; i++)
                {
                    if (notas[i][j] > maxAsignatura)
                    {
                        maxAsignatura = notas[i][j];
                    }
                    if (notas[i][j] < minAsignatura)
                    {
                        minAsignatura = notas[i][j];
                    }
                }

                printf("Asignatura %s -> Maxima: %.2f | Minima: %.2f\n", nombreAsignaturas[j], maxAsignatura, minAsignatura);
            }
            break;

        case 5:
            printf(Rojo "\n=== SALIR ===\n");
            printf("Saliendo del programa...\n\n" Reset);
            return 0;
        default:
            printf(Rojo "Opción invalida.\n" Reset);
            break;
        }
    } while (opc != 5);
    return 0;
}