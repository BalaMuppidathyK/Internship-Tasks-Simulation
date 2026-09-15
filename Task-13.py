from hcsr04 import HCSR04
from machine import Pin, I2C, PWM
import ssd1306

i2c = I2C(scl=Pin(22), sda=Pin(21), freq=100000)
lcd = ssd1306.SSD1306_I2C(128, 64, i2c)


sensor = HCSR04(trigger_pin=12, echo_pin=13, echo_timeout_us=1000000)

led_pin = Pin(5) 
led_pwm = PWM(led_pin)

try:
    while True:
      
        distance = sensor.distance_cm()
        print("Distance in cm:", distance)
        
        brightness = int((25 - distance) * (1023 / 20))  
        brightness = max(min(brightness, 1023), 0) 
        
     
        led_pwm.duty(brightness)
        
       
        lcd.fill(0)
        lcd.text("Distance:", 30, 20)
        lcd.text(str(distance), 30, 40)
        lcd.show()
except KeyboardInterrupt:
    pass
