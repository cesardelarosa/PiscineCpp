# Resumen de Proyectos Piscine C++

## C00 - Un Megáfono para el Mundo
Este módulo introduce los fundamentos de C++, sustituyendo las funciones de C por **streams de entrada/salida estándar** y manejando la clase **std::string**. Se centra en la **encapsulación** de datos mediante clases y la distinción entre miembros privados y públicos para proteger la integridad de los objetos. Finalmente, se explora el uso de **miembros estáticos** para gestionar información compartida y el uso inicial de contenedores e **iteradores**.

* ex00: Procesamiento de argumentos de terminal y salida estándar con `std::cout`.
* ex01: Creación de clases, ocultación de datos y gestión de arrays de objetos.
* ex02: Implementación de atributos y funciones estáticas para estados globales de clase.

## C01 - Abriendo la Caja de Pandora
El bloque profundiza en la gestión de memoria, comparando la **asignación dinámica** en el montón frente a la asignación en la pila. Se introducen las **referencias** como una alternativa segura a los punteros y se practica la manipulación de archivos mediante **flujos de archivos (fstream)**. Concluye con el uso de **punteros a funciones miembro** y el control de flujo con comportamientos de **fallthrough**.

* ex00: Diferencia de ciclo de vida entre objetos en stack y heap mediante `new`/`delete`.
* ex01: Asignación y liberación de arrays dinámicos de objetos con `delete[]`.
* ex02: Uso de punteros y referencias como alias para variables existentes.
* ex03: Asociación de objetos mediante punteros (opcionales) y referencias (obligatorias).
* ex04: Manipulación de archivos y búsqueda/reemplazo de cadenas con `std::string::find`.
* ex05: Despacho dinámico de métodos mediante punteros a funciones miembro.
* ex06: Filtrado de niveles de ejecución mediante sentencias `switch` consecutivas.

## C02 - Números de Punto Fijo y la Forma Canónica
Este módulo establece los estándares de robustez mediante la **Forma Canónica Ortodoxa**, asegurando que las clases gestionen correctamente copias y asignaciones. Se explora la **sobrecarga de operadores** para permitir que los objetos realicen operaciones aritméticas y lógicas de forma intuitiva. La aplicación práctica es la creación de un tipo de **punto fijo** para cálculos numéricos eficientes mediante **operaciones de bits**.

* ex00: Implementación de constructores de copia y operadores de asignación básicos.
* ex01: Conversión entre tipos primitivos y representaciones de punto fijo.
* ex02: Sobrecarga exhaustiva de operadores de comparación, aritmética e incremento.
* ex03: Algoritmo de detección de puntos dentro de triángulos (BSP) usando punto fijo.

## C03 - Herencia
Se introduce la **herencia** como método para reutilizar código y extender funcionalidades entre clases base y derivadas. Se aprende a usar el ámbito **protegido (protected)** para permitir el acceso a miembros desde clases hijas manteniendo la privacidad externa. El reto principal es resolver el **problema del diamante** mediante el uso de la **herencia virtual** para evitar redundancias.

* ex00: Diseño de una clase base con gestión de puntos de vida y energía.
* ex01: Implementación de herencia simple y extensión de funcionalidades específicas.
* ex02: Creación de múltiples ramas de herencia a partir de una base común.
* ex03: Resolución de ambigüedades en herencia múltiple usando herencia virtual.

## C04 - Polimorfismo y Clases Abstractas
El módulo se enfoca en el **polimorfismo** y el uso de **funciones virtuales** para lograr el enlace dinámico en tiempo de ejecución. Se recalca la necesidad de **destructores virtuales** y la implementación de la **copia profunda** para evitar fugas de memoria. Finalmente, se define el uso de **clases abstractas e interfaces** mediante funciones virtuales puras.

* ex00: Uso de la palabra clave `virtual` para habilitar el despacho dinámico.
* ex01: Gestión de memoria en clases compuestas mediante copias profundas.
* ex02: Definición de clases que no pueden ser instanciadas directamente.
* ex03: Simulación de sistemas mediante interfaces y gestión de inventarios de objetos.

## C05 - Repetición y Excepciones
Este proyecto introduce el manejo de errores mediante la **gestión de excepciones**, permitiendo separar la lógica principal del control de fallos. Se practica el uso de bloques **try-catch** y la definición de **excepciones personalizadas** dentro de las clases. El sistema simula una burocracia donde las acciones requieren niveles de grado específicos, reforzando el uso de **clases abstractas**.

* ex00: Definición y lanzamiento de excepciones de rango personalizadas.
* ex01: Validación de requerimientos de firma mediante excepciones en formularios.
* ex02: Jerarquía de formularios con lógica de ejecución y manejo de archivos.
* ex03: Implementación de una clase factoría (Intern) para creación dinámica de objetos.

## C06 - Conversión de Tipos
El foco principal es el estudio de los mecanismos de **conversión de tipos (casts)** de C++ para superar la inseguridad de los casts de C. Se aprende a aplicar **static_cast**, **dynamic_cast**, **reinterpret_cast** y **const_cast** según el contexto de los datos. También se introduce la **serialización** de punteros y la identificación de tipos en tiempo de ejecución (**RTTI**).

* ex00: Conversión de literales de texto a tipos de datos escalares (int, float, char).
* ex01: Serialización de objetos a punteros integrales y su posterior restauración.
* ex02: Identificación segura de tipos reales mediante punteros y referencias en jerarquías.

## C07 - Plantillas (Templates)
Este módulo introduce la **programación genérica**, permitiendo escribir código que funciona con cualquier tipo de dato sin sacrificar la seguridad de tipos. Se exploran las **plantillas de función** y las **plantillas de clase**, facilitando la creación de algoritmos universales. Es el paso esencial para comprender la arquitectura de las librerías de contenedores.

* ex00: Implementación de funciones genéricas para operaciones de intercambio y comparación.
* ex01: Aplicación de una función genérica sobre cada elemento de un array.
* ex02: Diseño de una clase de array dinámico genérico con gestión segura de memoria.

## C08 - Contenedores, Iteradores y Algoritmos
Se profundiza en la **Standard Template Library (STL)**, utilizando sus **contenedores** (vectores, listas, mapas) y **algoritmos** genéricos. El aprendizaje se centra en el uso de **iteradores** como puente entre los datos y la lógica de procesamiento. Se practica la búsqueda, el almacenamiento eficiente y la extensión de funcionalidades de contenedores estándar.

* ex00: Búsqueda genérica de valores en diversos tipos de contenedores STL.
* ex01: Gestión de colecciones numéricas para calcular distancias mínimas y máximas.
* ex02: Implementación de iteradores funcionales sobre un contenedor restringido (`std::stack`).

## C09 - Contenedores de la STL
El módulo final aplica la **lógica algorítmica** y el uso eficiente de la STL para resolver problemas de procesamiento de datos complejos. Se evalúa la elección del **contenedor adecuado** basándose en la complejidad temporal y el rendimiento de las operaciones. Se implementan soluciones para bases de datos temporales, notación matemática y algoritmos de ordenación.

* ex00: Uso de `std::map` para gestionar y buscar tasas de cambio de Bitcoin por fecha.
* ex01: Evaluación de expresiones en Notación Polaca Inversa mediante el uso de `std::stack`.
* ex02: Implementación del algoritmo Ford-Johnson (Merge-Insertion) comparando distintos contenedores.
