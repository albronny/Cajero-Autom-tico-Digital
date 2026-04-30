#include <stdio.h>
#include <string.h>

int main() {

    char usuarios[3][20] = {"ronny", "angel", "julio"};
    char claves[3][20] = {"1234", "5678", "abcd"};
    float saldos[3] = {5000.0, 3000.0, 7000.0};

    char usuario[20], contrasena[20];
    int acceso = 0;
    int posicionUsuario = -1;
    int opcion;
    float deposito, retiro;

    printf("\nSISTEMA DE CAJERO AUTOMATICO\n\n");

    printf("Ingrese usuario: ");
    scanf("%s", usuario);

    printf("Ingrese contrasena: ");
    scanf("%s", contrasena);

    for(int i = 0; i < 3; i++) {
        if(strcmp(usuario, usuarios[i]) == 0 && strcmp(contrasena, claves[i]) == 0) {
            acceso = 1;
            posicionUsuario = i;
            break;
        }
    }

    if(acceso == 1) {
        do {
            printf("\n===== MENU =====\n");
            printf("1. Consultar saldo\n");
            printf("2. Depositar dinero\n");
            printf("3. Retirar dinero\n");
            printf("4. Salir\n");
            printf("Seleccione opcion: ");
            scanf("%d", &opcion);

            switch(opcion) {

                case 1:
                    printf("Su saldo actual es: RD$ %.2f\n", saldos[posicionUsuario]);
                    break;

                case 2:
                    printf("Ingrese monto a depositar: ");
                    scanf("%f", &deposito);

                    saldos[posicionUsuario] += deposito;

                    printf("Deposito realizado con exito.\n");
                    printf("Nuevo saldo: RD$ %.2f\n", saldos[posicionUsuario]);
                    break;

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

                case 4:
                    printf("Gracias por utilizar el cajero automatico.\n");
                    break;

                default:
                    printf("Opcion invalida.\n");
            }

        } while(opcion != 4);

    } else {
        printf("Credenciales incorrectas.\n");
    }

    return 0;
}