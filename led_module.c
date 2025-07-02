PSEUDOCÓDIGO
Nombre del módulo: led_module.ko
1. Declarar constantes
Definir el número de GPIO que controla el LED 
Definir nombre del dispositivo
Definir nombre de la clase de dispositivo

2. Función write() del dispositivo
Recibir un comando del espacio de usuario
Si el carácter es 'ON':
    Llamar comando de encender LED
Si el carácter es 'OFF':
    Llamar comando de apagar LED

3. Función led_init() [al cargar el módulo con insmod]
Verificar si GPIO_LED es válido: gpio_is_valid(GPIO_LED)
Solicitar el GPIO: gpio_request(GPIO_LED, "LED")
Configurar como salida: gpio_direction_output(GPIO_LED, 0)
Exportar el GPIO para debug: gpio_export(GPIO_LED, false)
Registrar un dispositivo de caracteres (register_chrdev)
Crear clase de dispositivo (class_create)
Crear el archivo en /dev/ (device_create)
Imprimir mensaje "módulo cargado correctamente"

4. Función led_exit() [al descargar con rmmod]
Eliminar el archivo en /dev/ (device_destroy)
Destruir la clase de dispositivo
Liberar el número mayor de dispositivo (unregister_chrdev)
Apagar LED con gpio_set_value(GPIO_LED, 0)
Liberar y desexportar el GPIO
