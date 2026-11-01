/*
 *Descripción:* Obtiene el área de un polígono
 - Si se quiere el doble del área, activar el flag `x2`
*/
template<typename T>
T polygonArea(vector<Point2D<T>> P, bool x2 = 0) {
  T area = 0;
  for(int i = 0; i < sz(P)-1; ++i)
    area += P[i]^(P[i+1]);
  // Si el primer punto se repite, sacar:
  area += (P.back())^(P.front());
  return abs(area)/ (x2 ? 1 : 2);
}