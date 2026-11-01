En la siguiente tabla se muestra el tiempo de ejecución de un número de operaciones en dos jueces populares
#footnote[Tiempo calculado con respecto a $n$ sumas, operaciones más costosas tomarán más tiempo]. El tiempo de
ejecución depende de la máquina que ejecuta el programa, pero esta es una buena referencia para estimar si un programa
está dentro del límite de tiempo o lo excederá.

#align(center, table(
  columns: (auto, auto, auto),
  table.header(
    [*Operaciones*], [*Codeforces (ms)*], [*AtCoder (ms)*],
  ),
  $1 dot 10^7$, $61.4 plus.minus 18.8$, $24.2 plus.minus 0.4$,
  $2.5 dot 10^7$, $87.4 plus.minus 9.1$, $58.4 plus.minus 0.5$,
  $5 dot 10^7$, $130.8 plus.minus 8.4$, $115.8 plus.minus 0.4$,
  $7.5 dot 10^7$, $196.2 plus.minus 17.9$, $172.2 plus.minus 1.3$,
  $1 dot 10^8$, $246.4 plus.minus 17.2$, $230.8 plus.minus 1.9$,
  $2.5 dot 10^8$, $586.8 plus.minus 34.3$, $574 plus.minus 1.2$,
  $5 dot 10^8$, $1114.8 plus.minus 32.7$, $1139 plus.minus 8.5$,
  $7.5 dot 10^8$, $1599.4 plus.minus 51.4$, $1693.6 plus.minus 26.4$,
  $1 dot 10^9$, $2161.6 plus.minus 58$, $2266.4 plus.minus 32.9$,
  $2 dot 10^9$, $4396.4 plus.minus 35.6$, $4553.8 plus.minus 25$,
))

Una simple aproximación lineal de estos datos está dada por
$ t = 2.2 dot 10^(-6) n $

