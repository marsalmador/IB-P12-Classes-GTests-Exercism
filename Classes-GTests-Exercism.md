# Práctica 12. Introducción a la Programación Orientada a Objetos. Clases. Google Tests. Exercism

### Objetivos
Los objetivos de esta práctica son que el alumnado:
* Desarrolle programas sencillos en C++ que utilicen clases, así como todas las características del lenguaje
  estudiadas
* Aloje todo el código fuente de sus programas en repositorios privados de GitHub
* Sepa depurar sus programas usando la interfaz de depuración del VSC
* Incluya en sus programas comentarios en el formato requerido por Doxygen
* Conozca la herramienta CMake y sepa usarla para construir sus programas ejecutables
* Conozca el framework de testing de Google (Google Tests) y sea capaz de desarrollar tests unitarios
  sencillos
* Conozca la plataforma Exercism y sea capaz de interaccionar con la misma para resolver algunos problemas
  sencillos

### Rúbrica de evaluacion de esta práctica
Se señalan a continuación los aspectos más relevantes (la lista no es exhaustiva)
que se tendrán en cuenta a la hora de evaluar esta práctica:
* El alumnado ha de acreditar conocer los conceptos expuestos en el material de referencia de esta práctica.
* El alumnado ha de acreditar que ha realizado todos los ejercicios propuestos, así como ser capaz de desarrollar otros similares.
* Ha de acreditar que es capaz de escribir un fichero CMakeLists.txt para automatizar el proceso de compilación de sus programas.
* El código que escriba ha de estar escrito de acuerdo a los estándares definidos en la 
  [Guía de Estilo de Google para C++](https://google.github.io/styleguide/cppguide.html).
* Todos los identificadores que utilice en su programa (constantes, variables, etc.) deberán ser
  siempre significativos. No utilice nunca identificadores de una única letra, tal vez con la excepción de las
  variables que utilice para iterar en un bucle.
* Antes de su ejecución, todos los programas que desarrolle, deben imprimir en pantalla un
  mensaje indicando la finalidad del programa así como la información que precisará del usuario para su correcta ejecución.
* Ante la presencia de cualquier bug, el alumnado ha de conocer las técnicas básicas de depuración usando
  Visual Studio Code.
* Todos los ficheros de código del proyecto correspondiente a esta práctica han de alojarse en un repositorio de 
  [GitHub](https://github.com/).
* Los programas deben contener comentarios adecuados en el formato requerido por 
  [Doxygen](https://www.doxygen.nl/index.html).
* Los programas deben estructurarse en directorios diferentes para cada "proyecto" y hacer que cada uno de
  ellos contenga un fichero `CMakeLists.txt` con la configuración de despliegue del proyecto.

### La plataforma de testing de Google
Tal como recoge la
[Wikipedia](https://es.wikipedia.org/wiki/Desarrollo_guiado_por_pruebas),
El desarrollo dirigido por tests (TDD, *Test Driven Development* en sus siglas en inglés) es una práctica de 
ingeniería de software que involucra otras dos prácticas: 
Escribir las pruebas primero (Test First Development) y 
[Refactorización](https://es.wikipedia.org/wiki/Refactorizaci%C3%B3n)
(Refactoring) o reestructuración del código.
Para escribir las pruebas generalmente se utilizan las pruebas unitarias (unit test en inglés). 

El desarrollo dirigido por pruebas (TDD) se basa en la repetición de un ciclo de desarrollo muy corto que
involucra la repetición de tres pasos:
* En primer lugar el desarrollador escribe un caso de prueba (test) que falla y que define una mejora deseada o una nueva función
* A continuación se desarrolla el código que hace que la prueba pase satisfactoriamente 
* Finalmente refactoriza el nuevo código hasta obtener un resultado satisfactorio
El propósito del desarrollo guiado por pruebas es lograr un código limpio que funcione correctamente.
La idea es que los requisitos sean traducidos a pruebas (tests), y de este modo, cuando las pruebas pasen 
se garantizará que el software cumple con los requisitos que se han establecido.


Las "unidades de código" para las que se realizan tests habitualmente se refieren a clases, funciones o grupos ellas. 
Las pruebas unitarias  se suelen realizar utilizando entornos de pruebas (testing) especializados.
Supongamos por ejemplo que se está implementando una función que calcula la suma de dos números enteros.
Una prueba (test unitario) es un código que valida la corrección de esa función: se podría comprobar que lo
que reciba la función sean realmente dos parámetros, y que esos dos parámetros sean números, y que lo que
devuelva la función sea otro número, y que ese número corresponda realmente con la suma. 
Todas estas podrían ser posibles pruebas unitarias que se realicen sobre la función.

Existen 
[diversas plataformas](https://en.wikipedia.org/wiki/List_of_unit_testing_frameworks#C++)
para el desarrollo de tests unitarios en C++.
En esta práctica se propone utilizar el framework 
[Google Test](https://en.wikipedia.org/wiki/Google_Test),
(también conocido como gtest) es una librería de pruebas unitarias (*unit tests*) para C++.
El entorno permite que las pruebas (*tests*) se ejecuten de una en una o todas a la vez. 
Google Tests puede ser utilizado en 
[Visual Studio Code](https://docs.microsoft.com/es-es/visualstudio/test/how-to-use-google-test-for-cpp?view=vs-2019), 
aunque en esta práctica se propone un uso de la plataforma de modo independiente de VSC.

El primer paso para usar gtest es su instalación. 
Siga para ello los siguientes pasos:

```
 1 $ git clone https://github.com/google/googletest.git -b release-1.10.0
 2 $ cd googletest/
 3 $ mkdir build
 4 $ cd build/
 5 $ cmake .. -DBUILD_GMOCK=OFF
 6 $ make
 7 $ sudo make install
```
que se explican en el documento 
[Standalone CMake Project](https://github.com/google/googletest/blob/master/googletest/README.md#standalone-cmake-project).
El comando `sudo make install` instalará gtest en el directorio `/usr/local/`, de modo que en los directorios
```
/usr/local/include
/usr/local/lib
```
se alojan los ficheros de cabecera (`*.h`) y las librerías (`*.a`) necesarios para usar gtest.

El repositorio de esta práctica contiene un directorio `gtests` con el siguiente contenido:
```
gtests
   ├── CMakeLists.txt
   ├── src
   │   ├── addition.cc
   │   ├── addition.h
   │   ├── cubic.cc
   │   ├── cubic.h
   │   ├── factorial.cc
   │   ├── factorial.h
   │   ├── formula.cc
   │   ├── formula.h
   │   ├── main_program.cc
   │   ├── multiply.cc
   │   ├── multiply.h
   │   ├── square_root.cc
   │   └── square_root.h
   └── test
       ├── gtest_main.cc
       ├── test_addition.cc
       ├── test_cubic.cc
       ├── test_factorial.cc
       ├── test_formula.cc
       ├── test_multiply.cc
       └── test_square_root.cc
```
Siguiendo la costumbre habitual, el subdirectorio `src` contiene el código fuente del proyecto.
A modo de ejemplo, el programa principal `main_program.cc` invoca a diferentes funciones de carácter matemático que han sido
desarrolladas por el usuario (ficheros `src/*.cc` y `src/*.h`).

Compile el proyecto cuya configuración viene dada por el fichero `CMakeLists.txt` ejecutando en el directorio
`gtests`:
```
$ mkdir build
$ cd build
$ cmake ..
$ make
```
Estos comandos crearán en el directorio `build` sendos programas ejecutables: `user_program` y `runTests`.
El primero de ellos corresponde con el programa del usuario.
Pruebe a ejecutarlo y revise el código de las diferentes funciones que utiliza ese programa.
El programa `runTests` ejecuta todos los tests unitarios que se han desarrollado para comprobar el correcto
funcionamiento de las diferentes funciones que intervienen en el programa del usuario.
Pruebe asimismo a ejecutarlo.
Ambos programas se pueden compilar de forma independiente ejecutando en el diectorio `build`:

```
$ make user_program
```
o bien:
```
$ make runTests
```

Estudie el contenido del fichero `CMakeLists.txt` y observe en el mismo (comandos `add_executable(runTests ...)`
y `add_executable(user_program)`) los ficheros que están involucrados en cada uno de los dos programas
anteriores.

Lo que más interesa estudiar a continuación es el contenido del directorio `tests`.
En ese directorio, el programa `gtest_main.cc` invoca la ejecución de todos los tests mientras que los
diferentes ficheros `test_*.cc` contienen los tests correspondientes a las diferentes funciones del usuario
que utiliza el programa `main_program.cc`.

Estudie la documentación del 
[Googletest Primer](https://github.com/google/googletest/blob/master/googletest/docs/primer.md)
para aprender sobre los diferentes tipos de 
[aserciones](https://es.wikipedia.org/wiki/Aserci%C3%B3n_(inform%C3%A1tica))
y comparaciones que soporta la plataforma para realizar sus tests.

En todos los programas C++ que desarrolle de ahora en adelante, utilice siempre gtests para comprobar la
corrección de todas sus funciones y métodos.
Este enfoque (TDD) le ayudará a hallar los bugs de forma temprana de modo que podrá solucionarlos de forma
menos costosa en tiempo y esfuerzo.
La técnica de *testing* es fundamental para "cazar" cuanto antes los errores potenciales.
Las funciones que han sido comprobadas mediante tests unitarios son siempre más fiables.
Para cada función que escriba de ahora en adelante, escriba al menos dos tests: uno para las situaciones "normales" y otro para situaciones "extremas".
La regla a seguir de ahora en adelante es **Convierta en un hábito la escritura de tests para sus programas**.
Desarrolle siempre sus funciones iterando el famoso ciclo TDD que ya se ha expuesto en este documento:
* Escriba un test que falle y que define una mejora deseada o una nueva función
* Escirba el código (función, método) que haga que la prueba pase satisfactoriamente 
* Finalmente refactoriza el nuevo código hasta obtener un resultado satisfactorio
Es fácil encontrar en la web mucha documentación sobre TDD. 
A modo de ejemplo e introducción se recomienda el estudio de
[Mejorar la calidad del código mediante la prueba unitaria](https://www.mql5.com/es/articles/1579).

### Trabajo previo
Antes de realizar los ejercicios de esta práctica, estudie detenidamente el Capítulo 8 (epígrafes 8.1-8.16) del
[tutorial learncpp](https://www.learncpp.com/cpp-tutorial/81-welcome-to-object-oriented-programming/).
Muchos de los ejemplos de ese tutorial son los mismos que se utilizan en las clases teóricas de la asignatura,
cuyo material debiera Ud. también estudiar.

### Entorno de trabajo
Al realizar los siguientes ejercicios cree dentro de su repositorio de esta práctica un directorio diferente
para cada uno de los ejercicios (proyectos) con un contenido similar al que se ha entregado para la aplicación
de ejemplo `fibonacci_sum`.
Tómese como ejemplo el primero de los ejercicios.
Ponga a cada uno de esos directorios nombres significativos (fechas, complejos, racionales por ejemplo).

Haga que cada uno de sus programas conste de 3 ficheros:
* Un fichero `fechas.cc` (programa principal) que contendrá la función `main` e incluirá el fichero de cabecera `fecha.h`.
* El fichero `fecha.h` que contendrá las declaraciones correspondientes a la clase `Fecha`.
* El fichero `fecha.cc` que contendrá el código (definiciones) correspondientes a la clase `Fecha`.
* Obviamente si el programa principal (`fechas.cc`) utiliza otras clases, debería incluir (`#include`) los
  correspondientes ficheros de cabecera.
Modifique estos nombres de ficheros para adaptarlos al ejercicio en cuestión.

La compilación del programa correspondiente a cada ejercicio se automatizará con un fichero `CMakeLists.txt`
que se utilizará con `cmake`.

Así pues, la estructura de directorios y sus contenidos correspondiente al primero de los ejercicios
propuestos sería la siguiente:
```
fechas
    ├── build           // Directorio inicialmente vacío para alojar el programa ejecutable
    ├── CMakeLists.txt  // Fichero de configuración para cmake
    └── src             // Directorio contenedor del código fuente del ejercicio
        ├── fecha.cc
        ├── fecha.h
        └── fechas.cc
```

Desarrolle cada uno de estos ejercicios de forma incremental, probando cada una de las funciones que va Ud.
desarrollando. Utilice el depurador de VSC para corregir cualquier tipo de error semántico que se produzca en
cualquiera de sus desarrollos.

### Ejercicios
1. La clase Fecha.

Desarrolle una clase `Fecha` que permita representar y gestionar fechas.
Incorpore en la clase los miembros de datos y métodos que considere adecuados para la finalidad que se
persigue en este ejercicio.
Incluya un método que permita determinar si el año correspondiente a una fecha es un año bisiesto o
no.
Realice un programa cliente `fechas.cc` que tome como parámetro una fecha, un número y un nombre de fichero:
```
./fechas - Gestión de fechas
Modo de uso: ./fechas dd/mm/aa N fichero_salida.txt
Pruebe ./fechas --help para más información
```
El programa deberá imprimir en el fichero de salida (tercer parámetro) las N (segundo parámetro) fechas cronológicamente posteriores a la
introducida (primer parámetro) con una separación de un día entre fechas sucesivas.

2. La clase Complejo.

Todo
[número complejo](https://es.wikipedia.org/wiki/N%C3%BAmero_complejo)
puede representarse como la suma de un número real y un número imaginario, de la forma `a + bi` donde el
término `a` es la parte real, `b` la parte imaginaria e `i` la
[unidad imaginaria](https://es.wikipedia.org/wiki/Unidad_imaginaria).

En este ejercicio se propone desarrollar una clase `Complejo` que permita operar con números complejos.

Separe el diseño de su clase `Complejo` en dos ficheros, `complejo.h` y `complejo.cc` conteniendo
respectivamente la declaración y la definición de la clase.
Siga las indicaciones del tutorial 
[Class code and header files](https://www.learncpp.com/cpp-tutorial/89-class-code-and-header-files/)
para realizar esta separación de su clase en dos ficheros.
Siga igualmente las indicaciones del tutorial 
[Header guards](https://www.learncpp.com/cpp-tutorial/header-guards/)
para incluir (siempre de ahora en adelante) *header guards* (guardas de cabecera) en sus ficheros de
definiciones (`*.h`) de modo que se evite la inclusión múltiple del mismo fichero.

Desarrolle un programa cliente `complejos.cc` que permita operar con números complejos y haga uso
de la clase `Complejo` que diseñe.
La clase `Complejo` ha de contener al menos métodos que permitan (*print()*) imprimir un número 
complejo así como sumar (*Add()*) y restar (*Sub()*) números complejos.
Así la función *main* del programa `complejos.cc` podría contener sentencias como las siguientes:

```
main() {
  Complejo complejo1{4, 5}, complejo2{7, -8};
  Complejo resultado;
  resultado = add(complejo1, complejo2);
  resultado.print();
  resultado = sub(complejo1, complejo2);
  resultado.print();
}
```
que imprimirían en pantalla los resultados de la suma y referencia de números complejos indicada.

Incluya (discrecionalmente) cualesquiera otras operaciones que considere adecuadas como métodos en la clase
`Complejo`.

3. La clase Racional.

Un 
[número racional](https://en.wikipedia.org/wiki/Rational_number)
tiene un numerador y un denominador de la forma `p/q` donde `p` es el numerador y `q` el denominador.
Por ejemplo, 1/3, 3/4 y 10/4 son números racionales.

Un número racional no puede tener denominador 0, pero sí puede ser cero el numerador.
Todo número entero `n` es equivalente al racional `n/1`.
Los números racionales se utilizan en cálculos precisos que involucran fracciones.
Por ejemplo, `1/3 = 0.33333 ...`.
Este número no puede ser representado de forma precisa en formato de punto flotante utilizando los tipos float o double.
Para obtener resultados precisos es conveniente usar números racionales.

C++ dispone de tipos de datos para enteros y números en punto flotante, pero no para racionales.
En este ejercicio se propone el diseño de una clase para representar números racionales.

Desarrolle un programa cliente `racionales.cc` que permita operar con números racionales y haga uso
de la clase `Racional` que ha de diseñarse.

Las siguientes deben tomarse como especificaciones del programa a desarrollar:
* Separe el diseño de su clase `Racional` en dos ficheros, `racional.h` y `racional.cc` conteniendo
  respectivamente la declaración y la definición de la clase.
* La clase `Racional` incluirá al menos métodos para:
    * Crear objetos de tipo `Racional`. Se debe implementar un constructor por defecto y uno parametrizado.
    * Escribir (a fichero o a pantalla) un objeto de tipo `Racional`.
    * Leer (por teclado o desde fichero) un objeto de tipo `Racional`.
    * Sumar dos objetos de tipo `Racional`.
    * Restar dos objetos de tipo `Racional`.
    * Multiplicar dos objetos de tipo `Racional`.
    * Dividir dos objetos de tipo `Racional`.
    * Comparar objetos de tipo `Racional`.
* El programa ha de permitir leer un fichero de texto en el que figuran pares de números racionales
separados por espacios de la forma:

```
a/b c/d
e/f g/h
  ...
```

y para cada par de números racionales, el programa ha de imprimir en otro fichero de salida todas las operaciones posibles
con cada uno de los pares de números del fichero de entrada, de la forma:

```
a/b + c/d = n/m
  ...
```

Si el programa se ejecuta sin pasar parámetros en la línea de comandos, debemos obtener el siguiente mensaje:

```
./racionales -- Números Racionales
Modo de uso: ./racionales fichero_entrada fichero_salida
Pruebe ./racionales --help para más información
```

Si el programa se ejecuta pasando como parámetro la opción `--help` se ha de obtener:

```
./racionales -- Números Racionales
Modo de uso: ./racionales fichero_entrada fichero_salida 

fichero_entrada: Fichero de texto conteniendo líneas con un par de números racionales: `a/b c/d` separados por un espacio
fichero_salida:  Fichero de texto que contendrá líneas con las operaciones realizadas: `a/b + c/d = n/m`
```
### Referencias
* [Desarrollo dirigido por Tests](https://es.wikipedia.org/wiki/Desarrollo_guiado_por_pruebas)
* [Google Test](https://en.wikipedia.org/wiki/Google_Test)
* [Cómo usar Google Test para C++ en VSC](https://docs.microsoft.com/es-es/visualstudio/test/how-to-use-google-test-for-cpp?view=vs-2019), 
* [Google Tests build instructions](https://github.com/google/googletest/blob/master/googletest/README.md#standalone-cmake-project)
* [Googletest Primer](https://github.com/google/googletest/blob/master/googletest/docs/primer.md)
* [Mejorar la calidad del código mediante la prueba unitaria](https://www.mql5.com/es/articles/1579).


* [Google Test + gcover. Una lista de recetas](https://usingstdcpp.files.wordpress.com/2016/11/gtest.pdf)




* [Números complejos](https://es.wikipedia.org/wiki/N%C3%BAmero_complejo)
* [Rational Number](https://en.wikipedia.org/wiki/Rational_number)
*	[Class code and header files](https://www.learncpp.com/cpp-tutorial/89-class-code-and-header-files/)
* [Header guards](https://www.learncpp.com/cpp-tutorial/header-guards/)
* [Doxygen](https://en.wikipedia.org/wiki/Doxygen)
* [Documenting C++ Code](https://developer.lsst.io/cpp/api-docs.html)
* [Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html)
