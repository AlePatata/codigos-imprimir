/*
 *Descripción:* Obtiene el inverso modular de \(a\) módulo \(m\), si existe.
 *Complejidad:* \(O(\log m)\).
 *Requiere:* extgcd. Módulo \(m>1\).
 *Retorna:* El inverso modular o -1 si no existe.
 */

 template<class T>
T invmod_general(T a, T m) {
    a %= m;
    if (a < 0) a += m;

    T x, y;
    T g = extgcd(a, m, x, y);

    if (g != 1) return -1;

    x %= m;
    if (x < 0) x += m;
    return x;
}