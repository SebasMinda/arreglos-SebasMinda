#include <stdio.h>

int main()
{
    int estudiantes = 5, status;
    int asignaturas = 3, opc;
    int notaAprobatoria = 6;
    float notas[5][3];
    float sumaEstudiante, sumaAsignatura;
    int aprobados[3] = {0};
    int reprobados[3] = {0};
    char nombreEstudiantes[5][20];
    do {
    printf("\n=== BIENVENIDO AL PROGRAMA DE CALIFICACIONES ===\n");
    printf("Seleccione una de las opciones\n");
    printf("1. Ingreso de calificaciones\n");
    printf("2. Ingreso de asignaturas\n");
    printf("3. Aprobados y reprobados por asignatura\n");
    printf("4. Promedios, maximos y minimos por estudiante\n");
    printf("5. Promedios, maximos, minimos y aprobaciones por asignatura\n");
    printf("6. Salir\n");
    printf("Ingrese su opcion: ");
    status=scanf("%d", &opc);
    if (status == 0)
    {
        printf("Entrada invalida. Por favor, ingrese un numero.\n");
        while (getchar() != '\n')
            ; // Limpiar el buffer de entrada
    }
    if (opc < 1 || opc > 6)
    {
        printf("Opcion invalida. Debe estar entre 1 y 6.\n");
    }
    } while (opc < 1 || opc > 6 || status == 0);    
    
    do
    {
        switch (opc)
        {
        case 1:
            // Ingreso de calificaciones
            printf("=== INGRESO DE CALIFICACIONES ===\n");
            for (int i = 0; i < estudiantes; i++)
            {
                for (int j = 0; j < asignaturas; j++)
                {
                    do
                    {
                        printf("Ingrese el nombre del estudiante %d: ", i + 1);
                        status = scanf("%s", nombreEstudiantes[i]);
                        printf("Ingrese la nota del estudiante %d en la asignatura %d (0 a 10): ", i + 1, j + 1);
                        status = scanf("%f", &notas[i][j]);
                        if (status == 0)
                        {
                            printf("Entrada inválida. Por favor, ingrese un número.\n");
                            while (getchar() != '\n')
                                ; // Limpiar el buffer de entrada
                        }
                        if (notas[i][j] < 0 || notas[i][j] > 10)
                        {
                            printf("Nota inválida. Debe estar entre 0 y 10.\n");
                        }
                    } while (notas[i][j] < 0 || notas[i][j] > 10 || status == 0);
                }
            }
            break;

        case 2:
            printf("=== INGRESO DE ASIGNATURAS ===\n");
            printf("Ingrese el número de asignaturas (1-10): ");
            scanf("%d", &asignaturas);
            if (asignaturas < 1 || asignaturas > 10)
            {
                printf("Numero de asignaturas invalido. Debe estar entre 1 y 10.\n");
            }
            break;
        case 3:
            // Aprobados y reprobados por asignatura
            printf("\n=== APROBADOS Y REPROBADOS POR ASIGNATURA ===\n");
            for (int j = 0; j < asignaturas; j++)
            {
                printf("Asignatura %d -> Aprobados: %d | Reprobados: %d\n",
                       j + 1, aprobados[j], reprobados[j]);
            }
            break;
        case 4:
            // Promedios, máximos y mínimos por estudiante
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
                printf("Estudiante %d -> Promedio: %.2f | Máx: %.2f | Mín: %.2f\n",
                       i + 1, sumaEstudiante / asignaturas, max, min);
            }
            break;
        case 5:
            // Promedios, máximos, mínimos y aprobaciones por asignatura
            printf("\n=== PROMEDIOS POR ASIGNATURA ===\n");
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
                printf("Asignatura %d -> Promedio: %.2f | Máx: %.2f | Mín: %.2f\n",
                       j + 1, sumaAsignatura / estudiantes, max, min);
            }
        case 6:
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
