*Manipular bits*
Funciones de compilador:
- `__builtin_popcount(x)` : cuenta cantidad de 1 en un int
- `__builtin_popcountll(x)` : cuenta cantidad de 1 en un ll
- `__builtin_clz(x)` : cuenta ceros iniciales en un int
- `__builtin_ctz(x)` : cuenta ceroz finales en un int

*dato*: para obtener la posición del bit más significativo se usa `63 - __builtin_clzll(n)` (en un entero de 64 bits :3)

Funciones de `<bit>` (c++20): funcionan solo con unsigned :D
- `bit_ceil(x)` : potencia de 2 más pequeña mayor o igual que x
- `bit_floor(x)` : potencia de 2 más grande menor o igual que x