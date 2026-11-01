*Antes de enviar:*
- Escribe algunos casos de prueba simples si los ejemplos no bastan.
- ¿Los tiempos están al límite? Si es así, genera casos máximos.
- ¿El uso de memoria está bien?
- ¿Algo podría hacer overflow?
- Asegúrate de enviar el archivo correcto.

*Wrong answer:*
- ¡Imprime tu solución! Imprime también salida de debug.
- ¿Estás limpiando todas las estructuras de datos entre casos de prueba?
- ¿Tu algoritmo soporta todo el rango del input?
- Vuelve a leer el enunciado completo.
- ¿Manejas bien todos los casos borde?
- ¿Entendiste bien el problema?
- ¿Variables sin inicializar?
- ¿Overflows?
- ¿Confundiste N y M, i y j, etc.?
- ¿Estás segura de que tu algoritmo funciona?
- ¿Qué casos especiales no has considerado?
- ¿Estás segura de que las funciones de la STL que usas funcionan como crees?
- Agrega algunos asserts, y quizás vuelve a enviar.
- Crea casos de prueba para correr tu algoritmo.
- Recorre el algoritmo a mano en un caso simple.
- Vuelve a revisar esta lista.
- Explícale tu algoritmo a una compañera de equipo.
- Pídele a tu compañera que revise tu código.
- Sal a caminar un poco, por ej. al baño.
- ¿El formato del output es correcto? (incluyendo espacios)
- ¿Estás usando inverso modular?
- Reescribe tu solución desde cero o deja que otra compañera lo haga.

*Runtime error:*
- ¿Probaste todos los casos borde localmente?
- ¿Variables sin inicializar?
- ¿Estás leyendo o escribiendo fuera del rango de algún vector?
- ¿Algún assert que pueda fallar?
- ¿Alguna posible división por 0? (mod 0 por ejemplo)
- ¿Alguna posible recursión infinita?
- ¿Punteros o iteradores invalidados?
- ¿Estás usando demasiada memoria?
- Debuggea con reenvíos (por ej. provocando distintos errores a propósito).

*Time limit exceeded:*
- ¿Hay algún posible loop infinito?
- ¿Cuál es la complejidad de tu algoritmo?
- ¿Estás copiando muchos datos innecesarios? (usa referencias)
- ¿Qué tan grande es el input y el output? (considera scanf)
- Evita vector y map. (usa arreglos / unordered_map)
- ¿Qué opinan tus compañeras de tu algoritmo?

*Memory limit exceeded:*
- ¿Cuál es la memoria máxima que debería necesitar tu algoritmo?
- ¿Estás limpiando todas las estructuras de datos entre casos de prueba?

*Tips:*
- pi=3.14159265...
- sortear double es caro!!!
- hacer funciones para evitar bugs estúpidos
- ponerle {} a todo
- casos -> funciones
- usar INVERSO MODULAR cuando haya que dividir cosas con módulo
- invmod() del blaz es solo para MOD primos
- ver el scoreboard desde el minuto 10!!
- vectores grandes con tamaño fijo -> usar arreglos globales para evitar tle (ej: `ll dp[8001][1001][5];`)
