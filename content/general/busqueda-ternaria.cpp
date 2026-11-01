/*
 *Descripción:* Busca el mínimo en una función continua unimodal entre $l$ y $r$
*/
const double EPS = 1e-6; // ajustar para más o menos precisión
while (r - l > EPS) {
  double mid1 = l + (r - l) / 3;
  double mid2 = r - (r - l) / 3;
  if (f(mid2) >= f(mid1)) r = mid2;
  else l = mid1;
}
