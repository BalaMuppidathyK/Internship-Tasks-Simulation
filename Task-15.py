
from machine import Pin, I2C
from i2c_lcd import I2cLcd
import dht
import time

# I2C LCD
i2c = I2C(0, scl=Pin(22), sda=Pin(21))
lcd = I2cLcd(i2c, 0x27, 2, 16)

# DHT22
sensor = dht.DHT22(Pin(4))

while True:
    sensor.measure()
    t = sensor.temperature()
    h = sensor.humidity()

    lcd.clear()
    lcd.putstr("Temp: {:.1f}C".format(t))
    lcd.move_to(0, 1)
    lcd.putstr("Hum: {:.1f}%".format(h))

    time.sleep(2)
