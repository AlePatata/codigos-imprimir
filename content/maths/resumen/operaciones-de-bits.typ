*Operadores bitwise (a nivel de bit, o bit a bit)*\
En C++, un número se puede escribir en binario agregando `0b` al inicio.
Por ej. `0b1101` es 13 en binario. En los ejemplos siguientes se usan números de 4 bits.

- `~`: operador lógico NOT ("no"), pasa 0s a 1s y viceversa
  - Ej. `~0b1101 == 0b0010`, `~0b0101 == 0b1010`
- `&`: operador lógico AND ("y"), conmutativo, asociativo, distrubutivo c/r a OR, XOR
  - Ej. `0b1001 & 0b0111 == 0b0001`, `0b0101 & 0b1100 == 0b0100`
- `|`: operador lógico OR ("o"), conmutativo, asociativo, distrubutivo c/r a AND
  - Ej. `0b1001 | 0b0111 == 0b1111`, `0b0101 | 0b1100 == 0b1101`
- `^`: operador lógico XOR (exclusive or; "o" exclusivo), conmutativo, asociativo
  - Ej. `0b1001 ^ 0b0111 == 0b1110`, `0b0101 ^ 0b1100 == 0b1001`
- `>>`, `<<`: bitshifts (desplazamiento de bits) derecho e izquierdo
  - Ej. `0b`#text(blue, [`1`])`01`#text(red, [`1`])` >> 1 == 0b0`#text(blue, [`1`])`01`,
    `0b00`#text(blue, [`1`])`1 << 2 == 0b`#text(blue, [`1`])`100`

#table(
  columns: 2,
  [*Operación*], [*Código*],
  [Encender bit $i$], [`x | (1 << i)`],
  [Apagar bit $i$], [`x & ~(1 << i)`],
  [Alternar bit $i$], [`x ^ (1 << i)`],
  [Chequear bit $i$], [`(x >> i) & 1`],
  [Contar bits encendidos], [`__builtin_popcount(x)` (C++20: `popcount(x)`)],
  [Bit menos significativo], [`x & (-x)`],
  [Iterar todas las máscaras de $n$ bits], [`for (int mask = 0; mask < (1 << n); mask++)`],
  [Iterar submáscaras de `mask`], [`for (int sub = mask; sub > 0; sub = (sub - 1) & mask)`],
)
