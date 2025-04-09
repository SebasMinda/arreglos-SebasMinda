#include <stdio.h>
#include <string.h>
int main()
{
    int len, EstudiantesIngresados=0, EstudiantesIngresados2=0, EstudiantesIngresados3, estudiantes = 5, status, asignaturas = 3, opc, notaAprobatoria = 6;
    float notas[5][3];
    float sumaEstudiante, sumaAsignatura;
    int aprobados[3] = {0};
    int reprobados[3] = {0};
    char nombreEstudiantes[5][20];


    #define Rojo "\x1B[31m"
    #define Verde "\x1B[32m"
    #define Celeste "\x1B[36m"
    #define Reset "\x1B[0m"
    printf(Celeste"\n=== BIENVENIDO AL PROGRAMA DE CALIFICACIONES ===\n"Reset);
    do
    {
        do
        {
            printf("\nSeleccione una de las opciones\n");
            printf(Celeste"1."Reset" Ingreso de calificaciones\n");
            printf(Celeste"2."Reset" Aprobados y Reprobados por Asignatura\n");
            printf(Celeste"3."Reset" Promedios de Estudiantes y Asignaturas\n");
            printf(Celeste"4."Reset" Maximos y Minimos de Estudiantes y Asignaturas\n");
            printf(Celeste"5."Reset" Salir\n");
            printf("Ingrese su opcion: ");
            status = scanf("%d", &opc);
            if (status == 0||opc < 1 || opc > 5)
            {
                printf(Rojo"\nEntrada invalida.\n"Reset);
                while (getchar() != '\n')
                    ; // Limpiar el buffer de entrada
            }
        } while (opc < 1 || opc > 6 || status == 0);

        switch (opc)
        {
        case 1:
            if (EstudiantesIngresados==estudiantes)
            {
                printf("\nYa se han ingresado las notas de todos los estudiantes.\n");
                break;
            }
            printf(Celeste"\n=== INGRESO DE CALIFICACIONES ===\n"Reset);
            while (EstudiantesIngresados<estudiantes){
                for (int i = 0; i < EstudiantesIngresados+1; i++)
                {
                    printf(Verde"\nEstudiante %d:\n\n", EstudiantesIngresados+1);
                    for (int j = 0; j < asignaturas; j++)
                    {
                        do
                        {
                            printf(Reset"Ingrese la nota del estudiante %d en la asignatura %d (0 a 10): ", EstudiantesIngresados+1, j + 1);
                            status = scanf("%f", &notas[EstudiantesIngresados][j]);
                            if (status == 0||notas[EstudiantesIngresados][j] < 0 || notas[EstudiantesIngresados][j] > 10)
                            {
                                printf(Rojo"\nEntrada invalida.\n\n"Reset);
                                while (getchar() != '\n')
                                    ; 
                            }
                        } while (notas[EstudiantesIngresados][j] < 0 || notas[EstudiantesIngresados][j] > 10 || status == 0);
                        if (notas[EstudiantesIngresados][j] >= notaAprobatoria) {
                            aprobados[j]++;
                        } else {
                            reprobados[j]++;
                        }
                    }
                    break;
                }
                EstudiantesIngresados++;
            }
            break;

        case 2:
            if (EstudiantesIngresados<estudiantes)
            {
                printf(Rojo"\nNo se han registrado los estudiantes todavia.\n"Reset);
                break;
            }
            // Aprobados y reprobados por asignatura
            printf(Celeste"\n=== APROBADOS Y REPROBADOS POR ASIGNATURA ===\n"Reset);
            for (int j = 0; j < asignaturas; j++)
            {
                printf("Asignatura %d -> Aprobados: %d | Reprobados: %d\n",
                       j + 1, aprobados[j], reprobados[j]);
            }
            break;
        case 3:
            if (EstudiantesIngresados < estudiantes) {
                printf(Rojo"\nNo se han registrado los estudiantes todavia.\n"Reset);
                break;
            }
        
            printf(Celeste"\n=== PROMEDIO DE CALIFICACIONES ===\n"Reset);
        
            // Promedio por estudiante
            printf(Verde"\n=== PROMEDIO POR ESTUDIANTE ===\n"Reset);
            for (int i = 0; i < estudiantes; i++) {
                sumaEstudiante = 0;
                for (int j = 0; j < asignaturas; j++) {
                    sumaEstudiante += notas[i][j];
                }
                printf("Estudiante %d -> Promedio: %.2f\n", i + 1, sumaEstudiante / asignaturas);
            }
        
            // Promedio por asignatura
            printf(Verde"\n=== PROMEDIO POR ASIGNATURA ===\n"Reset);
            for (int j = 0; j < asignaturas; j++) {
                sumaAsignatura = 0;
                for (int i = 0; i < estudiantes; i++) {
                    sumaAsignatura += notas[i][j];
                }
                printf("Asignatura %d -> Promedio: %.2f\n", j + 1, sumaAsignatura / estudiantes);
            }
            break;
        case 4:
        
            if (EstudiantesIngresados < estudiantes) {
                printf(Rojo"\nNo se han registrado los estudiantes todavia.\n"Reset);
                break;
            }
        
            printf(Celeste"\n=== CALIFICACION MAS ALTA Y MAS BAJA ===\n"Reset);
        
            // EnEstudiantesIngresadosrar calificación más alta y más baja por estudiante
            printf(Verde"\n=== CALIFICACION MAS ALTA Y MAS BAJA POR ESTUDIANTE ===\n"Reset);
            for (int i = 0; i < estudiantes; i++) {
                float maxEstudiante = notas[i][0];
                float minEstudiante = notas[i][0];
        
                for (int j = 1; j < asignaturas; j++) {
                    if (notas[i][j] > maxEstudiante) {
                        maxEstudiante = notas[i][j];
                    }
                    if (notas[i][j] < minEstudiante) {
                        minEstudiante = notas[i][j];
                    }
                }
        
                printf("Estudiante %d -> Maxima: %.2f | Minima: %.2f\n", i + 1, maxEstudiante, minEstudiante);
            }
        
            // EnEstudiantesIngresadosrar calificación más alta y más baja por asignatura
            printf(Verde"\n=== CALIFICACION MAS ALTA Y MAS BAJA POR ASIGNATURA ===\n"Reset);
            for (int j = 0; j < asignaturas; j++) {
                float maxAsignatura = notas[0][j];
                float minAsignatura = notas[0][j];
        
                for (int i = 1; i < estudiantes; i++) {
                    if (notas[i][j] > maxAsignatura) {
                        maxAsignatura = notas[i][j];
                    }
                    if (notas[i][j] < minAsignatura) {
                        minAsignatura = notas[i][j];
                    }
                }
        
                printf("Asignatura %d -> Maxima: %.2f | Minima: %.2f\n", j + 1, maxAsignatura, minAsignatura);
            }
            break;
    
        case 5:
            printf(Rojo"\n=== SALIR ===\n");
            printf("Saliendo del programa...\n\n"Reset);
            return 0;
        default:
            printf(Rojo"Opción invalida.\n"Reset);
            break;
        }
    } while (opc != 6);
    return 0;
}