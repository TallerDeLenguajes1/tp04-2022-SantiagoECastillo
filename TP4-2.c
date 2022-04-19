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
void mostrarTareas(Tarea **tareas, int cantidad);


int main(){
    Tarea **tareas;
    int cantidadTareas;
    srand(time(NULL));

    printf("Ingrese la cantidad de tareas a realizar: ");
    scanf("%d", &cantidadTareas);
    fflush(stdin);

    tareas = (Tarea **)malloc(sizeof(Tarea) * cantidadTareas);
    
    cargarTareas(tareas, cantidadTareas);
    mostrarTareas(tareas, cantidadTareas);

    free(tareas);
    
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

void mostrarTareas(Tarea **tareas, int cantidad){
    printf("---------Tarear a realizar---------\n\n");
    
    for(int j=0; j<cantidad; j++){
        printf("ID: %d \n",  tareas[j]->TareaID);
        printf("Descripcion: %s \n", tareas[j]->Descripcion);
        printf("Duracin: %d \n", tareas[j]->Duracion);
        free(tareas[j]->Descripcion);


    }

    for(int j=0; j<cantidad; j++){
        free(tareas[j]);
    }
    
}
