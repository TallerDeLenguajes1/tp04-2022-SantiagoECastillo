#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    int TareaID;        //Numerado en ciclo iterativo
    char *Descripcion;  //Lee la descripcion de la tarea
    int Duracion;       // entre 10 – 100
}Tarea;

void cargarTareas(Tarea **tareas, int cantidad);
int categorizarTareas(Tarea **tareas, Tarea **realizada, int cantidad);
void mostrarTareasRealizadas(Tarea **realizada, int cantidad);
void mostrarTareasPendientes(Tarea **tareas, int cantidad);

int main(){
    Tarea **tareas, **tareasRealizadas;
    int cantidadTareas, cantTareasRealizadas;
    srand(time(NULL));

    printf("Ingrese la cantidad de tareas a realizar: ");
    scanf("%d", &cantidadTareas);
    fflush(stdin);

    tareas = (Tarea **)malloc(sizeof(Tarea) * cantidadTareas); //Arreglo qu contiene todas las tareas, se genera un arreglo de doble puntero
    tareasRealizadas = (Tarea **)malloc(sizeof(Tarea) * cantidadTareas); //Arreglo que contiene las tareas realizadas

    cargarTareas(tareas, cantidadTareas);
    cantTareasRealizadas = categorizarTareas(tareas ,tareasRealizadas, cantidadTareas);

    mostrarTareasRealizadas(tareasRealizadas, cantTareasRealizadas);
    mostrarTareasPendientes(tareas, cantidadTareas);

    free(tareas);
    free(tareasRealizadas);
    return 0;
}

void cargarTareas(Tarea **tareas, int cantidad){
    char *buffer;
    buffer = (char *)malloc(sizeof(char) * 100);

    
    for(int i=0; i<cantidad; i++){

        tareas[i] = (Tarea *)malloc(sizeof(Tarea));
        
        
        tareas[i]->TareaID = i+1;
        printf("Ingrese la descripcion de la tarea: ");
        gets(buffer);
        fflush(stdin);
        tareas[i]->Descripcion = (char *)malloc(sizeof(char) * (strlen(buffer)));
        strcpy(tareas[i]->Descripcion, buffer);
        tareas[i]->Duracion = rand() %101 +10; 

    }
    free(buffer);
}

int categorizarTareas(Tarea **tareas, Tarea **realizada, int cantidad){
    char confirmacion;
    int contador = 0;

    printf("\n\n---------TAREAS---------\n");
    
    for(int j=0; j<cantidad; j++){
        printf("ID: %d \n",  tareas[j]->TareaID);
        printf("Descripcion: %s \n", tareas[j]->Descripcion);
        printf("Duracion: %d \n", tareas[j]->Duracion);

        printf("Se realizo la tarea? (S/N): ");
        scanf("%c", &confirmacion);
        fflush(stdin);

        if(confirmacion == 's'){
            realizada[contador] = tareas[j];
            tareas[j] = NULL;
            contador++;
            printf("LA TAREA SE REALIZO\n");
        }else{
            printf("La tarea esta PENDIENTE\n");
        }
    }
    return contador;
}


void mostrarTareasRealizadas(Tarea **realizada, int cantidad){
    printf("\n---------TAREAS REALIZADAS----------\n");
    for(int i=0; i<cantidad; i++){
        printf("ID: %d \n", realizada[i]->TareaID);
        printf("Descripcion: %s \n", realizada[i]->Descripcion);
        printf("Duracion: %d \n", realizada[i]->Duracion);
    }
}

void mostrarTareasPendientes(Tarea **tareas, int cantidad){
    printf("\n---------TAREAS PENDIENTES----------\n");
    for(int i=0; i<cantidad; i++){
        if(tareas[i] != NULL){
            printf("ID: %d \n",  tareas[i]->TareaID);
            printf("Descripcion: %s \n", tareas[i]->Descripcion);
            printf("Duracion: %d \n", tareas[i]->Duracion); 
        }
    }
}
