from machine import Pin, ADC
import time
mq2 = ADC(Pin(34))
mq2.atten(ADC.ATTN_11DB)
led = Pin(2, Pin.OUT)
threshold = 2000
while True:
    gas = mq2.read()
    print("Gas Value:", gas)
    if gas > threshold:
        led.on()
        print("Gas Detected!")
    else:
        led.off()
        print("Gas not Detected!")
    time.sleep(1)