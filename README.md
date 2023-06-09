# The Integrated Parking System Embedded With Cooling System Arduino Project

# Links to:
 Working Model video: https://youtube.com/shorts/LHOsuY6DAG0?feature=share 
 
 Explanation of this project: https://youtu.be/xS3-r1mMmFM

The integrated parking system embedded with cooling system is an Arduino project designed to assist users with parking their vehicles safely and conveniently, while also providing a cooling system to maintain a comfortable environment in the vehicle. The system is composed of three subsystems, each with its specific functions.

The first subsystem of the system is equipped with an ultrasonic sensor that can detect objects nearby and an LCD that displays the distance in both centimeters and inches. When an object is detected, the sensor sends a signal to the second subsystem via hardware serial communication.

The second subsystem consists of an LED, a buzzer, a potentiometer, NPN transistor, and a fan. When the distance between the vehicle and the object is closer to 50 cm (this distance threshold can be adjusted), the buzzer in the second subsystem will start beeping, and the LED will start emitting light. The speed of the LED emitting light will also change as the object gets closer to the vehicle. The beeping sound will also beeps when the object comes is closer to 50 cm and remains steady if the object is at a constant distance, and the sound frequency will increase as the object gets closer to 0 cm. Thus, the LED and buzzer provide visual and auditory feedback to the user about the proximity of the object. The second subsystem also includes a potentiometer that can adjust the frequency of the buzzer, and a fan that can adjust its speed according to the temperature of the vehicle. This subsystem receives signals from the first and third subsystems and adjusts the fan speed accordingly.

The third subsystem of the system is equipped with a DHT11 sensor that detects temperature and humidity and an LCD that displays the information. This subsystem is connected to the second subsystem via software serial communication and sends signals to the second subsystem to adjust the fan speed according to the temperature. 

Overall, the integrated parking system embedded with cooling system Arduino project provides an efficient and convenient way to park and cool vehicles. With its ability to detect nearby objects and adjust the fan speed according to the temperature, this system can help users park their vehicles safely and comfortably.


"This integrated parking system embedded with cooling system Arduino project is the result of a group effort by three students as their final project for CS 362 Computer Design at the University of Illinois at Chicago. All intellectual property rights and ownership of this project belong to the group members and the University of Illinois at Chicago."

