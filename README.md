# Proyecto-IE-0117-Grupo1
Este proyecto está diseñado para funcionar con el editor de texto mousepad, su propósito es monitorear la apertura y cierre de un archivo de texto con el editor mousepad  y controlar el encendido y apagado de un led a través de un modulo en el kernel.

## Instrucciones para compilar e instalar el módulo del kernel en Raspberry Pi
A continuación se detallan los pasos necesarios para compilar e instalar el módulo led_module.ko en una Raspberry Pi:

### Requisitos previos
Antes de comenzar, asegúrese de contar con:
Raspberry Pi con Raspberry Pi OS instalado.
GPIO27 (físico pin 13) conectado a un LED con resistencia limitadora.
Paquetes necesarios instalados:
  ```bash
  sudo apt update
  sudo apt install -y raspberrypi-kernel-headers build-essential
 ```
### Estructura esperada
El archivo del módulo debe llamarse led_module.c y debe estar acompañado de un archivo Makefile. Ambos deben encontrarse en el mismo directorio.
### Compilación del módulo
Desde el directorio que contiene el código fuente, ejecute:
 ```bash
  make
 ```
###  Instalación y carga del módulo
Cargar el módulo:
 ```bash
  sudo insmod led_module.ko
```
Verificar que el módulo se haya cargado correctamente:
```bash
  lsmod | grep led_module
dmesg | tail
```
El dispositivo de caracteres se creará como /dev/led_control. Puedes escribir sobre él desde el espacio de usuario para controlar el LED.
```bash
  echo on/off | sudo tee /dev/led_control
```
### (Opcional) Cargar el módulo automáticamente al arrancar
Si deseas que el módulo se cargue automáticamente al iniciar la Raspberry Pi:
Copia el archivo .ko al directorio de módulos:
```bash
  sudo cp led_module.ko /lib/modules/$(uname -r)/
```
Agrega el nombre del módulo al archivo /etc/modules:
```bash
  echo "led_module" | sudo tee -a /etc/modules
```
Actualiza las dependencias de los módulos:
```bash
  sudo depmod -a
```
⚠️ Recuerda que para que el módulo funcione correctamente, ningún otro proceso debe estar usando el GPIO al momento de cargarlo.

## Para habilitar el demonio:
Es necesario tener _pgrep_ instalado, puede ser instalado con el comando:
```bash
apt install pgrep
```
Después, dentro  del archivo _monitoreo_led.sh_, en la linea 5, después de FILE debe estar tu ruta al escritorio. Ejemplo:
```bash
FILE=/home/tu-usuario/Escritorio/monitoreo_led.txt
```
el archivo _monitoreo_led.sh_ debe tener permisos de ejecución, pueden ser otorgados con:
```bash
chmod +x monitoreo_led.sh
```
Después de realizar estos cambios, se debe mover(o copiar) el archivo _monitoreo_led.sh_ a _/usr/local/bin_, puede ser con el comando:
```bash
sudo cp monitoreo_led.sh /usr/local/bin/monitoreo_led.sh para copiar 
sudo mv monitoreo_led.sh /usr/local/bin/monitoreo_led.sh para mover
```
luego se debe copiar o mover el archivo _monitoreo_led.ervice_ a _etc/systemctl/system_, con el comando
```bash
sudo cp monitoreo_led.service etc/systemctl/system/monitoreo_led.service para copiar 
sudo mv monitoreo_led.service etc/systemctl/system/monitoreo_led.service para mover
```
para habilitar el servicio es necesario ejecutar los siguientes comandos en la terminal:
```bash
sudo systemctl daemon-reload #recarga la configuaracion de los servicios
sudo systemctl enable monitor_led.service #habilitar el servicio
sudo systemctl start monitor_led.service #iniciar la ejecucion del servicio
```
### Instrucciones útiles
ver la salida del servicio
```bash
journalctl -u monitoreo_led.service -f
```
detener el servico
```bash
sudo systemctl stop monitor_led.service
```
deshabilitar el servicio
```bash
sudo systemctl disable monitor_led.service
```
