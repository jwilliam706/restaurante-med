# Sistema de Restaurante - Estructuras de datos

## Dev
Compilar:
```console
gcc sqlite3.dll main.c -o main.exe
```

Ejecutar:
```console
./main.exe
```

## Requisitos Tecnicos
- OS: Windows 64-bits
- Compilador utilizado: TDM-GCC (MinGW-w64 based) [Descargar](https://jmeubank.github.io/tdm-gcc/)
## Requerimientos del Sistema


En un restaurante se sirven 7 platillos diferentes y cada uno de ellos se identifica por una clave numérica que toma valores comprendidos entre 1 y 7.
Diariamente se atienden numerosos clientes, por lo que es necesario generar facturas con este formato:



Se pide:

a) Leer los precios de los 7 platillos

b) Leer los datos de cada cliente y entregar una factura como la anterior. Las facturas se enumeran de 1 hasta N, desde el comienzo del día.

c) Las ventas totales del día

d) El promedio de consumo por cada cliente

e) Identificar cuál es el platillo favorito del público y cantidad producida por ese plato

f) Cuál es el platillo más consumido y cantidad producida

g) Cuál es el platillo que más dinero produce al final del día

h) Cuál es el platillo que menos dinero produce al final del día.


El dueño del restaurante sabe que entre el gusto del público figuran los platillos 1, 3, 5 y 6.
También considerar la diferencia entre favorito y más consumido. Por ejemplo, si tenemos 3 clientes, dos pueden optar por el platillo 1 y consumirlo solo una vez, sin embargo, el tercer cliente puede elegir el platillo 5 y consumirlo tres veces. Por lo tanto, el platillo favorito es el 1 y el más consumido el 5. Considere que la información estará almacenada en un archivo de texto y al iniciar el programa este deberá de precargar la información del mismo.
Después de cada generación de una factura, esta deberá de almacenarse en el archivo de texto. Los precios de los platillos son por su cuenta.