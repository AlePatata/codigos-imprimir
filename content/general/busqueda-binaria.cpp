/*
 *Descripción:*
 1) Busca el primer valor entre `l` y `r` que hace la propiedad verdadera.
 2) Busca el último valor entre `l` y `r` que hace la propiedad falsa.
 `l`: inicio del espacio de búsqueda (`int` o `ll`)
 `r`: fin del espacio de búsqueda (`int` o `ll`)
 `mid`: centro del espacio de búsqueda (`int` o `ll`)
 Requiere que la condición sea "monótona": es falsa hasta cierto punto,
 después es siempre verdadera.
*/

while(l < r){
  mid = (l+r)/2; // se puede usar l+(r-l)/2 para evitar overflow por la suma
  if(/* condición es verdadera en mid */) r = mid;
  else l = mid+1;
}
if(/* condición es falsa en l */)
  // quejarse! la condición es falsa para todos los valores del espacio de búsqueda inicial
else
  // l (que en este punto es igual a r) es el primer valor en el espacio donde se cumple la condición

while(l < r){
  mid = (l+r+1)/2; // ahora hacemos la división con techo en vez de piso
  if(/* condición es verdadera en mid */) r = mid-1; // ahora aquí descartamos mid
  else l = mid; // acá ahora no descartamos mid porque puede ser el último falso
}
