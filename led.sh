#!/bin/bash

# Encender GPIO27
sudo gpioset gpiochip0 27=1
sleep 5
# Apagar GPIO27
sudo gpioset gpiochip0 27=0