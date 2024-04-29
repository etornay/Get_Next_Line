<h1>Parte obligatoria</h1>

• Llamar a tu función get_next_line de manera repetida (por ejemplo, usando un
bucle) te permitirá leer el contenido del archivo hacia el que apunta el file descriptor,
línea a línea, hasta el final.

• Tu función deberá devolver la línea que se acaba de leer.
Si no hay nada más que leer o si ha ocurrido un error, deberá devolver NULL.

• Asegúrate de que tu función se comporta adecuadamente cuando lea de un archivo
y cuando lea de stdin.

• Ten en cuenta que la línea devuelta debe terminar con el caracter
n, excepto si se ha llegado al final del archivo y esté no termina con un caracter
n.

• En el header get_next_line.h deberás tener como mínimo el prototipo de la función get_next_line.

• Añade todas las funciones de ayuda que necesites en el archivo get_next_line_utils.c

• Se considera que get_next_line() tiene un comportamiento indeterminado si el
archivo al que apunta el fd ha cambiado desde la última vez que se llamó, siempre
que read() no haya llegado al final del archivo.

• Se considera que get_next_line() tiene un comportamiento indeterminado cuando
lo que se lee es un archivo binario. Sin embargo, puedes implementar alguna manera
lógica de sortear este problema, si quieres.
