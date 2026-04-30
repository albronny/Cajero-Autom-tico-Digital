# Cajero-Autom-tico-Digital
# Cajero Automatico Digital

## Descripcion del sistema

Este proyecto consiste en el desarrollo de un sistema en lenguaje C que simula el funcionamiento basico de un cajero automatico digital.

El programa permite que varios usuarios previamente registrados puedan iniciar sesion mediante un nombre de usuario y una contraseña. Una vez dentro del sistema, el usuario puede realizar diferentes operaciones bancarias sobre su cuenta, tales como consultar su saldo disponible, depositar dinero, retirar dinero y salir del sistema.

---

## Funcionalidades implementadas

El sistema cuenta con las siguientes funcionalidades:

- Inicio de sesion con usuario y contraseña.
- Validacion de credenciales almacenadas en el sistema.
- Consulta de saldo disponible.
- Deposito de dinero a la cuenta.
- Retiro de dinero con verificacion de fondos suficientes.
- Menu interactivo repetitivo hasta seleccionar la opcion de salida.
- Mensajes de confirmacion y advertencia segun cada operacion.
- Uso de estructura `switch case` para organizar las opciones del menu.
- Codigo documentado con comentarios explicativos.

---


## Instrucciones para compilar el programa en C

Para compilar el programa desde la terminal utilizando GCC, se debe escribir el siguiente comando:

```bash
gcc cajero.c -o cajero
```

---

## Instrucciones para ejecutar el sistema

Luego de compilar correctamente, el programa se ejecuta con el siguiente comando:

```bash
./cajero
```

---

## Mejoras realizadas


### Implementacion de switch case
Se reemplazo la estructura de multiples condicionales por `switch case` para que el menu principal fuera mas limpio y facil de entender.