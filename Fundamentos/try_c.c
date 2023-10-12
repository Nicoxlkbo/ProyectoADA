#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct s_elemento{
	int valor;
	struct s_elemento *siguiente;
} *ELEMENTO;

typedef struct s_pila{
	ELEMENTO tope;
} PILA;

/* Operaciones */
PILA crearPila();
/* Retorna 1 si la pila está vacía y un -1 eoc */
int empty(PILA);
/* Agrega un elemento a la pila */
PILA push(PILA, int);
/* Extrae el tope de la pila */
PILA pop(PILA);
/* Retorna el tope de la pila SIN extraerlo */
int top(PILA);

int main() {
    
    //FIXME:
    // Define estados
        char estados[100];
        int contador1 = 0;
        int i;
        
        fgets(estados, sizeof(estados), stdin);

        //Contador estados
        for (i = 0; estados[i] != '\0'; i++) {
            if (estados[i] == ' ') {
                contador1++;
            } 
        }
        int cantidadestados = contador1 + 1;
        
        //Validacion estados
        for (i = 0; estados[i] != '\0'; i++) {
            if (estados[i] == '#' || estados[i] == '"' || estados[i] == ',' || estados[i] == '.' || estados[i] == '_') {
                printf("Error encontrado en 1");
                return 0;
            } 
        }

    //FIXME:
    //Definicion alfabeto
        char alfabeto[100];
        fgets(alfabeto, sizeof(alfabeto), stdin);

        //Contador simbolos alfabeto
        int contador2 = 0;
        for (i = 0; alfabeto[i] != '\0'; i++) {
            if (alfabeto[i] == ' ') {
                contador2++;
            } 
        }

        int cantidadsimbolos = contador2 + 1;
    
        size_t largoalf = strlen(alfabeto);
        
        //Validacion alfabeto
        for (i = 0; largoalf - 1  > i; i++) {
            if (!isalnum(alfabeto[i]) && alfabeto[i] != ' ') {    
                printf("Error encontrado en 2");
                return 0;
            } 
        }    

    //FIXME:
    //Estado/s inicial/es
        char estiniciales[50];
        fgets(estiniciales,sizeof(estiniciales),stdin);

        int j = 0;
        int contador4 = 0;

        
        //Validacion existencia estados iniciales en estados generales
        for ( i = 0; estados[i] != '\0' ; i++){
            for ( j = 0; estiniciales[j] != '\0' ; j++){
                if (estados[i] == estiniciales [j] && estados[i] != ' ' && estiniciales[j] != ' ' ){   
                    contador4 ++;
                }   
            }   
        }
        
        contador4 = contador4 - 1; 
        
        //Validacion final estados iniciales
        if (contador4 != 1)
        {
            printf("Error encontrado en 3");
            return 0;
        }
    
    
    //FIXME:
    //Estado/s Final/es
    char estfinales[50];
        fgets(estfinales,sizeof(estfinales),stdin);
        
        int contador5 = 0;
        int contador6 = 0;

        //Contador estados finales
        for (i = 0; estfinales[i] != '\0'; i++) {
            if (estfinales[i] == ' ') {
                contador5++;
            } 
        }
        int cantidadestfinales = contador5 + 1;
        
        //Validacion existencia estados finales en estados generales
        for ( i = 0; estados[i] != '\0' ; i++){
            for ( j = 0; estfinales[j] != '\0' ; j++){
                if (estados[i] == estfinales [j] && estados[i] != ' ' && estfinales[j] != ' ' ){   
                    contador6 ++;
                }   
            }   
        }
        
        //Reparacion validacion anterior por tomar en cuenta la palabra vacia
        if (contador6 >= 1)
        {
            contador6 = contador6 - 1;
        }
        
        //Validacion final estados finales
        if (contador6 < 1 || contador6 != cantidadestfinales)
        {
            printf("Error encontrado en 4");
            return 0;
        }

    //FIXME:
    //LeerTransiciones
    char transiciones[100];

        fgets(transiciones,sizeof(transiciones),stdin);
        char reduccionTransiciones[100];

        int contador7 = 0;
        int validacion = 0;
        int validacion2 = 0;
        int x = 0 , y = 0;

        //Contador transiciones
        for (i = 0; transiciones[i] != '\0'; i++) {
            if (transiciones[i] == '(') {    
                contador7++;
            } 
        }
        int cantidadtransiciones = contador7;
        
        //Validacion elementos de la transicion
        i = 0;
        
        do
        {
           
            //Validacion primer elemento = (
            if (transiciones[i] != '('){
                    printf("Error encontrado en 5");
                    return 0;
                }
            i++;

            //Validacion segundo elemento existe en los estados
            for ( j = 0; estados[j] != '\0' ; j++){
                if (estados[j] == transiciones[i]){
                        validacion++;
                }
                }
                if (validacion != 1)
                {
                    printf("Error encontrado en 5");
                    return 0;
                }
                reduccionTransiciones[x] = transiciones[i];
                x++;
            i++;

            //Validacion tercer elemento = ,
                if (transiciones[i] != ',')
                {
                    printf("Error encontrado en 5");
                    return 0;
                }
            i++;

            //Validacion cuarto elemento existe en el alfabeto
            for ( j = 0; alfabeto[j] != '\0' ; j++){
                if (alfabeto[j] == transiciones[i]){
                        validacion2++;
                }
                }

            if (validacion != 1)
                {
                    printf("Error encontrado en 5");
                    return 0;
                } 
                reduccionTransiciones[x] = transiciones[i];
                x++;
            i++;

            //Validacion quinto elemento = ,
                if (transiciones[i] != ','){
                        printf("Error encontrado en 5");
                        return 0;
                }
            i++;

            //Validacion sexto elemento existe en los estados
                validacion = 0;
                for ( j = 0; estados[j] != '\0' ; j++){
                if (estados[j] == transiciones[i]){
                        validacion++;
                }
                }

                if (validacion != 1)
                {
                    printf("Error encontrado en 5");
                    return 0;
                }
            
                reduccionTransiciones[x] = transiciones[i];
                x++;
            i++;
            //Validacion septimo elemento = )
                if (transiciones[i] != ')'){
                    printf("Error encontrado en 5");
                    return 0;
                }
            
            i++;
            i++;
            y++;
            validacion = 0;
            validacion2 = 0;
            
        } while (y != cantidadtransiciones);
        

    //FIXME:
    //Palabra a reconocer
    char palabra[50];
        fgets(palabra,sizeof(palabra),stdin);
        int contador = 0;

        for ( i = 0; alfabeto[i] != '\0'; i++){
            for ( j = 0; palabra[j] != '\0'; j++){
                if (alfabeto[i] == palabra[j])
                {
                    contador++;
                } 
                if (palabra[i] == ' ')
                {
                    printf("Error encontrado en 6");
                    return 0;
                }
                 
            }
        }

        contador = contador - 1;
        size_t largoPalabra = strlen(palabra);      

        if (largoPalabra > 1)
        {
            largoPalabra = largoPalabra - 1;
        }
        

        if (largoPalabra != contador){
           printf("Error encontrado en 6");
           return 0;
        }
        

    //TODO:
    //Mostrar resultados por pantalla
    contador = 0;
    for (i = 0; i < largoPalabra + 1; i++){
    x = 0;  
    int posicion = 0;
    char estadoactual[20];
        for ( j = 0; j < contador; j++){
            printf("%c",palabra[j]);
        }
        printf("_");
        for ( j = contador; palabra[j] != '\0'; j++){
            printf("%c",palabra[j]);
            
            if (contador == 0 && j == largoPalabra - 1)
            {
                printf(" %c",estiniciales[i]);
                estadoactual[i] = estiniciales[i];
            }
            
            if (j == largoPalabra - 1 && contador != 0){
                for ( x = 0; x < cantidadtransiciones*largoPalabra; x++){
                printf("***");   
                    if (palabra[contador] == reduccionTransiciones[x + 1] && estadoactual[0] == reduccionTransiciones[x])
                    {

                            printf(":%c:",palabra[contador]);
                            printf("<%c>",estadoactual[0]);
                            
                            printf(">>%c<<",estadoactual[0]);  

                        
                        
                        
                    }    
                }
                estadoactual[0] = reduccionTransiciones[x + 2];
            }
        } 
        contador ++;
    }
    return 0;
}





