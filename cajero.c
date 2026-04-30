#include <stdio.h>
#include <string.h>

int main() {

    /*En estos arreglos se almacenan los usuarios autorizados,
    sus respectivas contraseñas y el saldo inicial de cada uno.*/
    char usuarios[3][20] = {"ronny", "angel", "julio"};
    char claves[3][20] = {"1234", "5678", "abcd"};
    float saldos[3] = {5000.0, 3000.0, 7000.0};

    /*Variables utilizadas para guardar las credenciales que
    ingresa el usuario al momento de iniciar sesion.*/ 
    char usuario[20], contrasena[20];

    /*La variable acceso indicara si el login fue correcto,
    mientras que posicionUsuario guardara la posicion del
    usuario encontrado dentro de los arreglos.*/
    int acceso = 0;
    int posicionUsuario = -1;

    /*Variables necesarias para manejar el menu de opciones
    y para almacenar temporalmente montos de deposito o retiro.*/
    int opcion;
    float deposito, retiro;

    printf("\nSISTEMA DE CAJERO AUTOMATICO\n\n");

    /*Se solicitan las credenciales del usuario para ver
    si pertenece a uno de los usuarios registrados.*/
    printf("Ingrese usuario: ");
    scanf("%s", usuario);

    printf("Ingrese contrasena: ");
    scanf("%s", contrasena);

    /*Este ciclo recorre todos los usuarios almacenados y
    compara tanto el nombre como la contraseña ingresada.
    Si ambos datos coinciden, se concede el acceso.*/
    for(int i = 0; i < 3; i++) {
        if(strcmp(usuario, usuarios[i]) == 0 && strcmp(contrasena, claves[i]) == 0) {
            acceso = 1;
            posicionUsuario = i;
            break;
        }
    }

    /* Si las credenciales del usuario son corrrectas se 
    mostrara el menu principal de operaciones y el programa 
    seguira ejecutandose hasta que seleccione la opcion de salir.*/
    if(acceso == 1) {
        do {
            printf("\n===== MENU =====\n");
            printf("1. Consultar saldo\n");
            printf("2. Depositar dinero\n");
            printf("3. Retirar dinero\n");
            printf("4. Salir\n");
            printf("Seleccione opcion: ");
            scanf("%d", &opcion);

            /*La estructura switch permite ejecutar una accion
            distinta dependiendo de la opcion elegida.*/
            switch(opcion) {

                //Muestra en pantalla el saldo actual del usuario.//
                case 1:
                    printf("Su saldo actual es: RD$ %.2f\n", saldos[posicionUsuario]);
                    break;

                /*Solicita un monto, lo suma al saldo existente
                y luego muestra el nuevo saldo actualizado.*/
                case 2:
                    printf("Ingrese monto a depositar: ");
                    scanf("%f", &deposito);

                    saldos[posicionUsuario] += deposito;

                    printf("Deposito realizado con exito.\n");
                    printf("Nuevo saldo: RD$ %.2f\n", saldos[posicionUsuario]);
                    break;

                /* Solicita un monto para retirar y primero verifica
                si el usuario posee fondos suficientes antes de
                descontarlo de la cuenta.*/
                case 3:
                    printf("Ingrese monto a retirar: ");
                    scanf("%f", &retiro);

                    if(retiro <= saldos[posicionUsuario]) {
                        saldos[posicionUsuario] -= retiro;
                        printf("Retiro realizado con exito.\n");
                        printf("Nuevo saldo: RD$ %.2f\n", saldos[posicionUsuario]);
                    } else {
                        printf("Fondos insuficientes para realizar el retiro.\n");
                    }
                    break;

                //Finaliza la ejecucion del sistema.//
                case 4:
                    printf("Gracias por utilizar el cajero automatico.\n");
                    break;

                //Se ejecuta si el usuario digita una opcion incorrecta.//
                default:
                    printf("Opcion invalida.\n");
            }

        } while(opcion != 4);

    } else {
        /*Mensaje mostrado cuando las credenciales no coinciden
        con ninguno de los usuarios registrados.*/
        printf("Credenciales incorrectas.\n");
    }

    return 0;
}