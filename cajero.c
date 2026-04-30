#include <stdio.h>
#include <string.h>

int main() {

    char usuarios[3][20] = {"ronny", "angel", "julio"};
    char claves[3][20] = {"1234", "5678", "abcd"};
    float saldos[3] = {5000.0, 3000.0, 7000.0};

    char usuario[20], contrasena[20];
    int acceso = 0;
    int posicionUsuario = -1;

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

    if(acceso == 0) {
        printf("Credenciales incorrectas.\n");
    }

    return 0;
}