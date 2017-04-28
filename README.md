# Programacion Orientada a Objetos
## Proyecto 3
Eduardo Aguilar Leal


Jorge Andres Sabella

27 de abril de 2017

---
## Diseño del Programa
Inicialmente el programa necesita dos archivos de texto, uno que contenga los servicios dados (servicios.txt) y otro que contenga las reservaciones programadas (reservaciones.txt). Una vez que existan ambos archivos en el orden correcto se van a guardar en los arreglos de apuntadores de objetos.
Ya con la información en los arreglos de apuntadores se va a correr un menú que va a contener las siguientes opciones, todas las opciones tienen una función especificada.

* Consultar la lista de Servicios: En esta opción simplemente se corre un ciclo en donde usa el método virtual muestra de la clase de servicios para mostrar el contenido de todos los servicios.

* Consultar la lista de reservaciones: Esta opción usa un ciclo para checar todo el arreglo apuntadores de reservaciones, en esta se muestra el tiempo inicial y después se calcula el  tiempo de final usando el método dentro de la clase reservaciones.

* Consultar las reservaciones de un servicio dado: Esta opción inicia preguntando al usuario por el servicio y después usa un ciclo que checa si existe tal servicio, si no vuelve a preguntar y si existe usa otro ciclo para checar si existen reservaciones de ese servicio y mostrar la hora de inicio y final en caso de que sí.

* Consulta las reservaciones de una hora específica: Esta opción checa si la hora ingresada es la de alguna reservación y si lo es muestra los datos de la reservación, la hora tiene que estar entre  24 – 0 horas y 59 – 0 minutos.

* Hacer una reservación:  Esta opcion le pide al usarios los datos que requerra para hacer una reservacion como el ID, la hora, la duracion y el servicio. Con esto y con la validacion de lo anterior creara un nuevo objeto de tipo reservacion que ser añadira a el arreglo de reservaciones. La opcion tiene una funcion de tipo `booleana` que define si sí logro hace una reservacion o no. Asimismo esta funcion edita el objeto de tipo reservacion que debido a que es un apuntador no se regresa con la funcion.

* ActualizarTexto: Esta funcion recibe como parametro el arreglo de reservaciones con el cual vuelve a reescribir linea por linea el archivo del cual originalmente adquirio las reservaciones. Esto con un `for loop`.

Formato de los archivos de texto:

#### Reservaciones:
(clave del Servicio) (hora) (minutos) (tiempo En Minutos) (id Cliente)

#### Servicios:
* Aparato: (clave del Servicio) (tiempo Máximo) (Tipo de Servicio) (costo por 15 min) (con
Instructor) (descripción)

* Cancha: (clave del Servicio) (tiempo Máximo) (Tipo de Servicio)) (costo por Hora) (cantidad de Personas Máximo) (deporte)
