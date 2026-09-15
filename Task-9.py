#task 1 - Measure temperature and display it in LCD display


from machine import Pin
import dht
import time

# DHT22
sensor = dht.DHT22(Pin(4))

#LED Pins (changes if different in your circuit)
green_led = Pin(19, Pin.OUT)
red_led = Pin(18, Pin.OUT)



while True:

    sensor.measure()

    t = sensor.temperature()
    h = sensor.humidity()

    

    if t<30:
        #green blink
        red_led.off()
        green_led.on()
        time.sleep(0.5)
        green_led.off()
        time.sleep(0.5)

    else:
            #red blink
            green_led.off()
            red_led.on()
            time.sleep(0.5)
            red_led.off()
            time.sleep(0.5)
