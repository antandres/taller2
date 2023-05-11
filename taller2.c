//Hecho por Andrés Gubaira, V31.006.669
#include <stdio.h>

void ventascat(int indice, float mat[100][3], float *v1, float *v2, float *v3, float *vt); //Prototipo de función para calcular ventas por categoría

void main()
{
    FILE *entrada;
    FILE *salida;
    float ventas[100][3];
    int dim = 0;
    float aux1, aux2, aux3;
    float vcat1 = 0, vcat2 = 0, vcat3 = 0, vtotal = 0;
    entrada = fopen("ventas.txt", "r");
    salida = fopen("ventas_totales.txt", "w");
    if(entrada == NULL) //Confirmación de archivo
    {
        printf("No se pudo abrir el archivo origen. Verifique el directorio");
    }
    else
    {
        printf("Categoria del producto -- Cantidad vendida -- Precio unitario\n");
        while((feof(entrada) == 0)&&(dim<100)) //Ciclo para llenar la matriz con los datos. Pueden ingresarse hasta 100 ventas
        {
            fscanf(entrada, "%f,%f,%f", &aux1, &aux2, &aux3);
            ventas[dim][0] = aux1;
            ventas[dim][1] = aux2;
            ventas[dim][2] = aux3;
            printf("        %.0f                         %.0f               %.3f\n", ventas[dim][0], ventas[dim][1], ventas[dim][2]);
            ventascat(dim, ventas, &vcat1, &vcat2, &vcat3, &vtotal);
            dim++;
        }
        fprintf(salida, "Ventas totales por categoria:\nCategoria 1: $%.3f\nCategoria 2: $%.3f\nCategoria 3: $%.3f\nVentas totales: $%.3f", vcat1, vcat2, vcat3, vtotal); //Escritura en el archivo de salida
    }
    fclose(entrada);
    fclose(salida);
}

//Función para calcular el total de ventas por categoría y general
void ventascat(int indice, float mat[100][3], float *v1, float *v2, float *v3, float *vt)
{
    int x = mat[indice][0];
    switch(x)      
    {
        case(1):
        {
            *v1 = *v1 + (mat[indice][1] * mat[indice][2]);
            *vt = *vt + (mat[indice][1] * mat[indice][2]);
            break;
        }
        case(2):
        {
            *v2 = *v2 + (mat[indice][1] * mat[indice][2]);
            *vt = *vt + (mat[indice][1] * mat[indice][2]);
            break;
        }
        case(3):
        {
            *v3 = *v3 + (mat[indice][1] * mat[indice][2]);
            *vt = *vt + (mat[indice][1] * mat[indice][2]);
            break;
        }
    }

}