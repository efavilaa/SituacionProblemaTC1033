# AutoMatch

Un programa en C++ que carga una base de datos de carros usados (Toyota), permite filtrarlos por diversos criterios, ordenarlos, imprimirlos y generar un reporte del carro ideal según las preferencias del usuario.

# Evidencia 2. Solución Situación Problema

Ana Elisa Celaya Montalvo | A01287120

Ethiel Favila Alvarado | A00844789

Catherine González Díaz | A00845539

Profesor David Alonso Cantú Delgado

Pensamiento computacional orientado a objetos
Grupo 313

## Intrucciones de uso

Requisitos:
Tener instalado:
C++17 o superior
Un compilador como:
g++ (Linux/Mac)
clang++ (Mac)
MinGW (Windows)
Archivo toyota.csv en el directorio del ejecutable

Formato del archivo toyota.csv:
model,year,price,transmission,mileage,fuelType,tax,mpg,engineSize

Ejemplo de línea en toyota.csv:
Corolla,2018,15000,Manual,40000,Petrol,150,45.5,1.8
RAV4,2020,27000,Automatic,15000,Hybrid,170,50.2,2.5

## Compilación

Linux/Mac
g++ -std=cpp17 -O2 main.cpp -o analyzer

Windows(MinGW)
g++ -std=c++17 main.cpp -o analyzer.exe

Ejecutar
./analyzer

## Funciones del programa

1. Cargar datos desde un archivo CSV.
   loadData()

2. Imprimir todos los carros.
   printAll()

3. Filtrar por año
   filterDates();

4. Filtrar por modelo
   filterModel()

5. Carros con menor kilometraje
   lowestMileage()

6. Quiz del carro ideal
   idealCarQuiz()
