### Exercism
[Exercism](https://exercism.io/) es una plataforma orientada a aprender a programar o también a mejorar las
capacidades de cualquier programadora.
El objetivo de Exercism es servir como medio para aprender a programar en un determinado lenguaje, y para ello se propone
hacerlo mediante la resolución de ejercicios que otros usuarios han planteado. 
Lo que se persigue es que tanto quien resuelve el problema como quien lo planteó aprendan al mismo tiempo. 
Además, la interacción con el resto de la comunidad podrá llevar a debates para determinar cuál sería la mejor solución para un determinado problema.

La plataforma se basa en una una aplicación de línea de comandos disponible para diferentes sistemas
operativos (Linux, Mac, Windows).
Usando esa aplicación, un usuario puede descargar una serie de ejercicios de programación disponibles en la
plataforma y realiza los correspondientes programas hasta que consigue aprobar los diferentes tests que se le
pasan a cada ejercicio.

La plataforma puede ser usada en "modo práctica", en cuyo caso no existe la opción de mentorización (solicitar
que una experta le ayude con sus ejercicios), pero aún
así merece la pena practicar los múltiples ejercicios que hallará en la plataforma.

### Primeros pasos en Exercism
Comience por [registrarse en Exercism](https://exercism.io/users/sign_up). 
Si lo desea, puede Ud. hacerlo usando la cuenta de GitHub de la que ya dispone.
Una vez disponga de una cuenta, configure lo básico de la misma y elija un "track" (un lenguaje) en el que
desee practicar.
Obviamente se le propone que elija el track correspondiente a C++.

Propóngase a continuación resolver el problema "Hello World".
En la página de ese problema (o de cualquier otro) hallará Ud. un enlace que indica *Get started* y 
[Begin walk-through](https://exercism.io/cli-walkthrough).
Si sigue ese enlace le llevará a una pantalla *Welcome to the Exercism installation guide!* con instrucciones
sobre cómo instalar `exercism`.
En este documento se propone instalarla en la máquina virtual Linux de la asignatura.
Eligiendo la opción *Linux* y a continuación la opción *Using snap* se le pedirá que ejecute
```
sudo snap install exercism
```
Ese comando instalará en primer lugar `snap` y a continuación `exercism`, que es lo que se persigue.
También en esa página se indica que se compruebe que la instalación es correcta con el comando
```
exercism version
```
[`snap`](https://blogubuntu.com/que-es-ubuntu-snap) es un mecanismo alternativo al ya conocido
`apt-get install` para instalar aplicaciones en Ubuntu Linux.
Si quiere Ud. saber más sobre `snap` puede consultar
[esta referencia](https://snapcraft.io/docs/getting-started),
aunque ello no es necesario para el trabajo que se propone realizar con Exercism.

Una vez instalada la aplicación `exercism` el siguiente paso es configurar la interfaz de comandos (CLI) de la
aplicación.
Para ello se pide que se ejecute el comando
```
exercism configure --token=xxxxxxxx-xxxx-xxxx-xxxx-xxxxxxxxxxxx
```
donde el *token* que figura en el comando anterior se encuentra (es específico de cada usuario) en la [página
de configuración](https://exercism.io/my/settings) de la cuenta de usuario que se ha creado.
Basta copiar de esa página el token y colocarlo en el comando anterior.

El comando anterior, una vez ejecutado indica:
```
You have configured the Exercism command-line client:

Config dir:                       /home/usuario/snap/exercism/5/.config/exercism
Token:         (-t, --token)      xxxxxxxx-xxxx-xxxx-xxxx-xxxxxxxxxxxx
Workspace:     (-w, --workspace)  /home/usuario/snap/exercism/5/exercism
API Base URL:  (-a, --api)        https://api.exercism.io/v1
```
A continuación se puede elegir un problema para pasar a resolverlo.
Se propone, como ya se ha dicho, elegir el problema "Hello World".
En la página de ese problema figura una descripción precisa del problema planteado y en la parte derecha de
esa página figuran las instrucciones para:
* Download. Descargar el problema mediante el comando `exercism download --exercise=hello-world --track=cpp`
* Solve. Para resolver el problema se propone usar el editor favorito del usuario. Se recomienda usar Visual
  Studio Code
* Submit. El comando para subir a la plataforma la solución que el usuario proponga.

Si se ejecuta el comando para descargar el problema el sistema responde:
```
$ exercism download --exercise=hello-world --track=cpp

Downloaded to
/home/usuario/snap/exercism/5/exercism/cpp/hello-world
```
indicando el directorio donde ha colocado el código necesario para trabajar en ese problema.

Si revisa Ud. los ficheros descargados observará que Exercism utiliza `.cpp` como extensión para los ficheros
con código fuente C++ en lugar de la extensión `.cc` que recomienda la Guía de Estilo de Google.
La extensión `.cpp` es muy común para ficheros de código C++.

### Ejecución de los tests para un determinado problema
El siguiente paso consiste en editar el programa (en el caso del problema "Hello World" el fichero a editar es
`hello_world.cpp`).
Edite ese fichero hasta que considere que tiene una versión operativa.
Una vez finalizado su programa, el siguiente paso consiste en pasar (superar) los tests del código.
Cada ejercicio de Exercism va acompañado de una serie de tests que el programa debe superar para ser
considerado válido.

Tal como se explica en la página [Running the Tests](https://exercism.io/tracks/cpp/tests), cada problema va
acompañado de sus tests unitarios (así se llama este tipo de tests) y un fichero `CMakeLists.txt` que se
utiliza para automatizar la compilación de los tests y del propio programa.
Tenga en cuenta que **no** debiera editar ni modificar el fichero `CMakeLists.txt`.

Tal como se indica en la página anterior y suponiendo que su ejercicio se llame `bob`, 
debieran existir los ficheros `bob.cpp` y `bob.h` antes de
ejecutar los tests. 
Esos ficheros podrían estar vacíos, pero han de existir.
En el caso del ejercicio `hello-world` los ficheros son `hello-world.cpp` y `hello-world.h`

El siguiente paso (suponiendo un entorno Linux) es compilar el programa y los tests unitarios.
Para ello, colóquese en el directorio del ejercicio (`/home/usuario/snap/exercism/5/exercism/cpp/hello-world`)
y ejecute:
```
$ touch hello-world.{h,cpp}
$ mkdir build
$ cd build
$ cmake -G "Unix Makefiles" ..
$ make
```
El comando [touch](https://ss64.com/bash/touch.html) modifica la fecha del fichero (ficheros) que se le pasen
como argumentos. 
El directorio `build` que se crea servirá para alojar (entre otros ficheros) un programa ejecutable que pasará
los tests a su código.
Exercism utiliza `cmake` (tendrá Ud. que instalar esa aplicación en su VM si no la tiene instalada).
[CMake](https://cmake.org/) es una herramienta (similar a `make` en cuanto a su finalidad, pero más
sofisticada) que facilita construir, probar y empaquetar software. 
De forma análoga a `make`, `CMake` también se utiliza para controlar el proceso de compilación de la
aplicación.

Para usar Exercism no es necesario que conozca Ud. los detalles de `CMake`.
El fichero `CMakeLists.txt` que acompaña a cada problema es un fichero de configuración para `CMake`.
Al ejecutar `cmake -G "Unix Makefiles" ..` CMake creará un fichero Makefile que le servirá para compilar su
ejercicio.
Al ejecutar `make` en el directorio `build` se compilan los tests que ha de pasar su programa.
Si se producen errores de compilación, tendrá Ud. que solucionarlos en el directorio (padre de `build` de su
ejercicio.
Una vez que se corrijan los errores, `make` construirá y ejecutará los tests que haya disponibles para el
ejercicio en cuestión.

Normalmente cada problema viene acompañado de un conjunto de tests cuyo código se encuentra en un fichero cuyo
nombre tiene el sufijo `_test` (fichero `hello_world_test.cpp` en el caso del ejercicio "Hello
World").
La estrategia que ha de seguir a la hora de progresar en la mejora de su ejercicio es hacer que su código pase
progresivamente las diferentes pruebas (tests) que figuran en ese fichero.
Para ello basta que "mueva" en el código la línea
```
#if defined(EXERCISM_RUN_ALL_TESTS)
```
para situarla después del siguiente test que quiera probar.

Exercism puede ser usado en "modo práctica", en cuyo caso no existe la opción de mentorización, pero aún
así merece la pena practicar los múltiples ejercicios que hallará en la plataforma.

Cuando su solución al problema pase todos los tests y esté Ud. satisfecha con la misma, puede remitirla a la
plataforma.
Utilice para ello el comando `exercism submit` que hallará Ud. en la página correspondiente al problema.
Una vez que haya enviado su solución a Exercism recibirá un mensaje similar a este:
```
Your solution has been submitted successfully.
You can complete the exercise and unlock the next core exercise at:

https://exercism.io/my/solutions/xxxx
```
A partir de este punto puede ya ver las soluciones que otras usuarias hayan dado al mismo problema o bien
avanzar con otros problemas de ese mismo "track".

