#text(size: 8pt)[*Vim*]
- `vim .vimrc`

```vim
syntax on
set re=0
set smartindent
set tabstop=2
set shiftwidth=2
set expandtab
set nu
set rnu
```

#text(size: 8pt)[*Shortcuts de Vim*]
- *Buscar:* `/texto` (adelante), `?texto` (atrás), `n`/`N` siguiente/anterior, `*` busca la palabra bajo el cursor
- *Reemplazar en todo el archivo:* `:%s/viejo/nuevo/g` (agregar `c` al final para confirmar cada uno: `/gc`)
- *Reemplazar en líneas `a` a `b`:* `:a,bs/viejo/nuevo/g`; en selección visual: `:'<,'>s/viejo/nuevo/g`
- *Moverse:* `gg` inicio, `G` final, `:n` línea `n`, `%` paréntesis/llave pareja, `0`/`$` inicio/fin de línea
- *Editar:* `dd` borrar línea, `yy` copiar línea, `p` pegar, `u` deshacer, `Ctrl+r` rehacer, `.` repetir
- *Visual:* `v` caracteres, `V` líneas, `Ctrl+v` bloque; `>`/`<` indentar, `y` copiar, `d` cortar
- *Archivo:* `gg=G` re-indentar todo, `ggyG` copiar todo, `ggdG` borrar todo
- *Compilar sin salir:* `:w | !g++ % -o run.out && ./run.out < in.txt`

#text(size: 8pt)[*Bash*]
- `vim .bashrc`
- Tip: reiniciar la terminal, o ejecutar `source .bashrc`

```
alias g++="g++ -o run.out -Wall"
```


#text(size: 8pt)[*GDB*]
- Compilar con `g++ -g sol.cpp` y abrir con `gdb ./run.out`
- `run < in.txt` ejecutar con input
- `bt` ver dónde cayó (segfault), `frame k` ir al frame `k` del `bt`
- `b N` breakpoint en línea `N`, `b N if i == 5` condicional
- `d` borrar breakpoints
- `n` siguiente línea, `c` continuar, `until N` correr hasta línea `N`
- `s` entrar a función, `finish` salir de la función
- `p x` imprimir `x`, `p *arr@n` primeros `n` elementos de un arreglo, `info locals` todas las variables
- `display x` imprimir `x` en cada paso, `watch x` parar cuando `x` cambie, `set var x = 3` modificar variable

#text(size: 8pt)[*Sanitizers*] (detectan índices fuera de rango, overflow y memoria inválida, sin usar GDB)
```
g++ -g -fsanitize=address,undefined -D_GLIBCXX_DEBUG sol.cpp
```
