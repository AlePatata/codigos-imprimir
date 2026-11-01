/*
 *Descripción:* Calcula el máximo común divisor de \(a,b\), encontrando coeficientes \(x,y\) tales que:
\[ ax+by=\gcd(a,b) \]
 *Complejidad:* \(O(\log(\min(a,b)))\), para \(a,b\) positivos.
 *Requiere:* T entero. Entradas no negativas, no ambas cero.
 */

template<class T>
T extgcd(T a, T b, T &x, T &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }

    T x1, y1;
    T g = extgcd(b, a % b, x1, y1);

    x = y1;
    y = x1 - (a / b) * y1;

    return g;
}