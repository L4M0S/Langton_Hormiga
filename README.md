# Langton_Hormiga
Hormiga de Langton

# Definicion
La hormiga de Langton es un una máquina de Turing bidimensional con un conjunto de reglas muy sencillo, que sin embargo da lugar a comportamientos emergentes complejos. La hormiga de Langton clásica opera sobre una rejilla espacial cuadrada, en que cada celda puede estar en uno de dos estados (blanca o negra, 1 o 0, viva o muerta, etc). Fue inventada por Chris Langton en 1986 y su universalidad se demostró en el año 2000.

# Funcionalidad
Cada cuadrado del entramado se colorea o bien blanco o bien negro. Se identifica arbitrariamente un cuadrado como la «hormiga». La hormiga siempre está mirando en una de las cuatro direcciones cardinales y se mueve un cuadrado cada vez, de acuerdo con las siguientes reglas:

Si está sobre un cuadrado blanco, cambia el color del cuadrado, gira noventa grados a la izquierda y avanza un cuadrado.

Si está sobre un cuadrado negro, cambia el color del cuadrado, gira noventa grados a la derecha y avanza un cuadrado.

# Comportmiento
Las simples reglas que gobiernan a la hormiga de Langton llevan a comportamientos complejos que han sido objeto de múltiples investigaciones. Comenzando con una rejilla totalmente blanca, la versión clásica presenta tres tipos de comportamiento aparentes,:

Simplicidad: durante los primeros cientos de pasos, la hormiga crea patrones sencillos y frecuentemente simétricos.

Caos: después de varios cientos de pasos, aparece un patrón grande e irregular. La hormiga sigue un camino aparentemente azaroso hasta los 10.000 pasos.

Orden emergente: finalmente la hormiga empieza a construir una «avenida», un patrón de 104 pasos que se repite indefinidamente.
