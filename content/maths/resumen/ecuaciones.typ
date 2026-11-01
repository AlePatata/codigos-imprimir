*Ecuación cuadrática:*
$ a x^2 + b x + c = 0 arrow.double x = (-b plus.minus sqrt(b^2 - 4a c)) / (2a), quad "extremo en" x = -b / (2a) $

*Sistema lineal 2x2:*
$ cases(a x + b y = e, c x + d y = f) arrow.double x = (e d - b f)/(a d - b c), quad y = (a f - e c)/(a d - b c) $

*Regla de Cramer:* Dado $A bold(x) = bold(b)$, se tiene $x_i = det(A_i') \/ det(A)$, donde $A_i'$ es $A$ con la columna $i$ reemplazada por $bold(b)$.

*Recurrencias:* Si $a_n = c_1 a_(n-1) + dots.c + c_k a_(n-k)$ y $r_1, dots, r_k$ son raíces distintas de $x^k - c_1 x^(k-1) - dots.c - c_k$, entonces:
$ a_n = d_1 r_1^n + dots.c + d_k r_k^n $
Una raíz repetida $r$ se convierte en un factor polinomial, por ej. $a_n = (d_1 n + d_2) r^n$.

*Número de Grundy para nim de L a R:*
$ f(x) = floor((x mod (L+R))/L) $
