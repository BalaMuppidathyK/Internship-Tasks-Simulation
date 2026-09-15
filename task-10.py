from machine import Pin, PWM
import time

# --- Setup ---
servo = PWM(Pin(2), freq=50)
btn1 = Pin(14, Pin.IN, Pin.PULL_UP)
btn2 = Pin(4, Pin.IN, Pin.PULL_UP)

pos = 0.0
step = 1.0

def write_servo(angle):
   
    duty = int((angle / 180) * (123 - 25) + 25)
    servo.duty(duty)

write_servo(pos)

while True:
    # Button 1: Decrement position
    if not btn1.value():
        print("Decrementing")
        if pos > 0:
            pos -= step
            write_servo(pos)
            print("Position:", pos)
            time.sleep_ms(5)

    # Button 2: Increment position
    if not btn2.value():
        print("Incrementing")
        if pos < 180:
            pos += step
            write_servo(pos)
            print("Position:", pos)
            time.sleep_ms(5)
            
    time.sleep_ms(10)
