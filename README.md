# Proyecto-IE-0117-Grupo1
Este proyecto está diseñado para funcionar con el editor de texto mousepad, su propósito es monitorear la apertura y cierre de un archivo de texto con el editor mousepad  y controlar el encendido y apagado de un led a través de un modulo en el kernel.

Para habilitar el servicio:

Es necesario tener pgrep instalado, puede ser instalado con el comando apt install pgrep

primero, dentro  del archivo monitoreo_led.sh, en la linea 5, después de FILE debe estar la ruta al escritorio
FILE=/home/tu-usuario/Escritorio/monitoreo_led.txt

el archivo monitoreo_led.sh debe tener permisos de ejecución, pueden ser otorgados con 
chmod +x monitoreo_led.sh

Después de realizar estos cambios, se debe mover(o copiar) el archivo monitoreo_led/sh a /usr/local/bin, puede ser con el comando 
sudo cp monitoreo_led.sh /usr/local/bin/monitoreo_led.sh para copiar 
sudo mv monitoreo_led.sh /usr/local/bin/monitoreo_led.sh para mover

luego se debe copiar o mover el archivo monitoreo_led.ervice a etc/systemctl/system, con el comando
sudo cp monitoreo_led.service etc/systemctl/system/monitoreo_led.service para copiar 
sudo mv monitoreo_led.service etc/systemctl/system/monitoreo_led.service para mover

para habilitar el servicio es necesario ejecutar los siguientes comandos en la terminal:

recarga la configuaracion de los servicios
sudo systemctl daemon-reload

habilitar el servicio
sudo systemctl enable monitor_led.service 

iniciar la ejecucion del servicio
sudo systemctl start monitor_led.service


instrucciones útiles
ver la salida del servicio
journalctl -u monitoreo_led.service -f

detener el servico
sudo systemctl stop monitor_led.service

deshabilitar el servicio
sudo systemctl disable monitor_led.service
