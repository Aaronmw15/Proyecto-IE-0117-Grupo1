PSEUDOCÓDIGO
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/init.h>
#include <linux/gpio.h>             // Control GPIO
#include <linux/uaccess.h>         // copy_from_user
#include <linux/device.h>          // device class
#include <linux/cdev.h>

#define DEVICE_NAME "led_control"
#define CLASS_NAME "led"

#define LED_GPIO 27

static int majorNumber;
static struct class*  ledClass  = NULL;
static struct device* ledDevice = NULL;

static ssize_t dev_write(struct file *filep, const char *buffer, size_t len, loff_t *offset) {
    char command[4] = {0}; // soporta hasta "on\n" o "off\n"

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
