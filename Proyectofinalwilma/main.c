#include <stdio.h>
#include <stdlib.h>

/* Estructura para los par�metros fijos del veh�culo  */
struct ParametrosVehiculo
{
    float costo_vehiculo;
    int tiempo_uso;
    float depreciacion;
    float devaluacion_total; /* Nuevo par�metro */
    float km_promedio_anual;
    float min_consumo;
    float max_consumo;
    float mantenimiento_mensual;
    float seguro_mensual;
    float costo_gomas_anual;
};

/* Funci�n para leer los par�metros del veh�culo desde un archivo  */
void leerParametros(struct ParametrosVehiculo *parametros)
{
    FILE *archivo = fopen("parametros_vehiculo.txt", "r");
    if (archivo != NULL)
    {
        fscanf(archivo, "%f %d %f %f %f %f %f %f %f %f",
               &parametros->costo_vehiculo, &parametros->tiempo_uso,
               &parametros->depreciacion, &parametros->devaluacion_total, /* Leer devaluaci�n total */
               &parametros->km_promedio_anual, &parametros->min_consumo,
               &parametros->max_consumo, &parametros->mantenimiento_mensual,
               &parametros->seguro_mensual, &parametros->costo_gomas_anual);
        fclose(archivo);
    }
    else
    {
        /* Valores predeterminados si el archivo no existe  */
        parametros->costo_vehiculo = 2000000.00;
        parametros->tiempo_uso = 5;
        parametros->depreciacion = 700000.00;
        parametros->devaluacion_total = 1300000.00; /* Valor predeterminado para devaluaci�n total  */
        parametros->km_promedio_anual = 20000.00;
        parametros->min_consumo = 8.0;
        parametros->max_consumo = 16.0;
        parametros->mantenimiento_mensual = 6200.00;
        parametros->seguro_mensual = 2000.00;
        parametros->costo_gomas_anual = 26000.00;
    }
}

/* Funci�n para escribir los par�metros del veh�culo en un archivo  */

void escribirParametros(const struct ParametrosVehiculo *parametros)
{
    FILE *archivo = fopen("parametros_vehiculo.txt", "w");
    if (archivo != NULL)
    {
        fprintf(archivo, "%.2f %d %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f",
                parametros->costo_vehiculo, parametros->tiempo_uso,
                parametros->depreciacion, parametros->devaluacion_total, /* Escribir devaluaci�n total  */
                parametros->km_promedio_anual, parametros->min_consumo,
                parametros->max_consumo, parametros->mantenimiento_mensual,
                parametros->seguro_mensual, parametros->costo_gomas_anual);
        fclose(archivo);
    }
    else
    {
        printf("No se pudo abrir el archivo de par�metros del veh�culo.\n");
        exit(1);
    }
}

/* Funci�n para modificar los par�metros del veh�culo  */

void modificarParametros(struct ParametrosVehiculo *parametros)
{
    printf("\nModificando par�metros del veh�culo...\n");
    printf("Introduce el nuevo costo del veh�culo: ");
    scanf("%f", &parametros->costo_vehiculo);
    printf("Introduce el nuevo tiempo de uso del veh�culo: ");
    scanf("%d", &parametros->tiempo_uso);
    printf("Introduce la nueva depreciaci�n despu�s de %d a�os: ", parametros->tiempo_uso);
    scanf("%f", &parametros->depreciacion);
    printf("Introduce la nueva devaluaci�n total: "); /* Nueva entrada para la devaluaci�n total */
    scanf("%f", &parametros->devaluacion_total);
    printf("Introduce el nuevo kilometraje promedio anual: ");
    scanf("%f", &parametros->km_promedio_anual);
    printf("Introduce el nuevo m�nimo de consumo (L/100km): ");
    scanf("%f", &parametros->min_consumo);
    printf("Introduce el nuevo m�ximo de consumo (L/100km): ");
    scanf("%f", &parametros->max_consumo);
    printf("Introduce el nuevo mantenimiento mensual: ");
    scanf("%f", &parametros->mantenimiento_mensual);
    printf("Introduce el nuevo seguro mensual: ");
    scanf("%f", &parametros->seguro_mensual);
    printf("Introduce el nuevo costo anual de gomas: ");
    scanf("%f", &parametros->costo_gomas_anual);
    // Escribir los nuevos par�metros en el archivo
    escribirParametros(parametros);
    printf("�Par�metros modificados y guardados correctamente!\n");
}

/* Funci�n para calcular el costo del viaje y generar la tabla */
void calcularCostoViaje(const struct ParametrosVehiculo *parametros)
{
    float km_recorrer;
    float costo_galon;
    printf("\nIntroduce los kil�metros a recorrer en el viaje: ");
    scanf("%f", &km_recorrer);
    printf("Introduce el costo del gal�n de gasolina: ");
    scanf("%f", &costo_galon);

    /* Generar la tabla de c�lculos */
    printf("\n|--------------------------------------------------------------------------|\n");
    printf("| Consumo (L/100km) | Costo vehiculo/km | Costo km/galon | Costo total viaje |\n");
    printf("|--------------------------------------------------------------------------|\n");
    for (float consumo = parametros->min_consumo; consumo <= parametros->max_consumo; consumo += 1.0)
    {
        // C�lculo del costo del veh�culo por kil�metro
        float costo_vehiculo_km = (((parametros->mantenimiento_mensual * 12 * parametros->tiempo_uso) +
                                    (parametros->seguro_mensual * 12 * parametros->tiempo_uso) +
                                    (parametros->costo_gomas_anual * parametros->tiempo_uso) +
                                    parametros->devaluacion_total) /
                                    (parametros->km_promedio_anual * parametros->tiempo_uso));

        /* Conversi�n de litros a galones */
        float galones = consumo / 3.78541; /* 1 gal�n = 3.78541 litros */

        /* C�lculo del costo del kil�metro por gal�n durante el viaje */
        float costo_km_galon = (galones * costo_galon) / 100;

        /* C�lculo del costo total del viaje */
        float costo_total_viaje = costo_km_galon * km_recorrer;

        printf("|      %.1f L/100km    |     %.2f         |      %.2f        |       %.2f        |\n",
               consumo, costo_vehiculo_km, costo_km_galon, costo_total_viaje);
    }
    printf("|--------------------------------------------------------------------------|\n");

    /* Preguntar si desea guardar la tabla en un archivo */
    int opcion_guardar;
    printf("\n�Desea guardar la tabla en un archivo? (0 = No, 1 = S�): ");
    scanf("%d", &opcion_guardar);
    if (opcion_guardar == 1)
    {
        FILE *archivo = fopen("informe_total_proyecto_final.txt", "w");
        if (archivo != NULL)
        {
            fprintf(archivo, "|--------------------------------------------------------------------------|\n");
            fprintf(archivo, "| Consumo (L/100km) | Costo vehiculo/km | Costo km/galon | Costo total viaje |\n");
            fprintf(archivo, "|--------------------------------------------------------------------------|\n");
            for (float consumo = parametros->min_consumo; consumo <= parametros->max_consumo; consumo += 1.0)
            {
                /* C�lculo del costo del veh�culo por kil�metro */
                float costo_vehiculo_km = (((parametros->mantenimiento_mensual * 12 * parametros->tiempo_uso) +
                                            (parametros->seguro_mensual * 12 * parametros->tiempo_uso) +
                                            (parametros->costo_gomas_anual * parametros->tiempo_uso) +
                                            parametros->devaluacion_total) /
                                            (parametros->km_promedio_anual * parametros->tiempo_uso)) ;

                /* Conversi�n de litros a galones */
                float galones = consumo / 3.78541; /* 1 gal�n = 3.78541 litros  */

                /* C�lculo del costo del kil�metro por gal�n durante el viaje  */
                float costo_km_galon = (galones * costo_galon) / 100;

                /* C�lculo del costo total del viaje */
                float costo_total_viaje = costo_km_galon * km_recorrer;

                fprintf(archivo, "|      %.1f L/100km    |     %.2f         |      %.2f        |       %.2f        |\n",
                        consumo, costo_vehiculo_km, costo_km_galon, costo_total_viaje);
            }
            fprintf(archivo, "|--------------------------------------------------------------------------|\n");
            fclose(archivo);
            printf("\n�Tabla guardada exitosamente en el archivo 'informe_total_proyecto_final.txt'!\n");
        }
        else
        {
            printf("\n�Tabla no guardada!\n");
        }
    }
    else
    {
        printf("\n�Tabla no guardada!\n");
    }
}

int main()
{
    struct ParametrosVehiculo parametros;
    leerParametros(&parametros);

    int opcion;
    do
    {
        printf("\nMenu:\n");
        printf("1. Ver parametros del vehiculo\n");
        printf("2. Modificar par�metros del vehiculo\n");
        printf("3. Calcular costo del viaje y generar tabla\n");
        printf("4. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
            printf("\nParametros del vehiculo:\n");
            printf("Costo del vehiculo: %.2f\n", parametros.costo_vehiculo);
            printf("Tiempo de uso del vehiculo: %d anos\n", parametros.tiempo_uso);
            printf("Depreciacion despues de %d a�os: %.2f\n", parametros.tiempo_uso, parametros.depreciacion);
            printf("Devaluacion total: %.2f\n", parametros.devaluacion_total); // Imprimir devaluaci�n total
            printf("Kilometraje promedio anual: %.2f\n", parametros.km_promedio_anual);
            printf("Minimo de consumo (L/100km): %.2f\n", parametros.min_consumo);
            printf("Maximo de consumo (L/100km): %.2f\n", parametros.max_consumo);
            printf("Mantenimiento mensual: %.2f\n", parametros.mantenimiento_mensual);
            printf("Seguro mensual: %.2f\n", parametros.seguro_mensual);
            printf("Costo anual de gomas: %.2f\n", parametros.costo_gomas_anual);
            break;
        case 2:
            modificarParametros(&parametros);
            break;
        case 3:
            calcularCostoViaje(&parametros);
            break;
        case 4:
            printf("\n�Hasta luego!\n");
            break;
        default:
            printf("\nOpci�n no v�lida. Por favor, seleccione una opci�n v�lida.\n");
        }
    } while (opcion != 4);

    return 0;
}
