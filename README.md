# VisionImpairment
Haptic/Audio feedback from Ultrasonic/IR sensors on Arduino

This project was initiated to investigate the use of echo location/infrared sensors for distance measurement to provide haptic and/or audio feedback to a blind user.

For the code included in "vibe_watch_v2":
Hardware used:
1 X Adruino Nano
1 X HC-SR04 Ultrasonic Sensor
1 X vibration motor
1 X 9V battery snap (if using a 9V battery) OR 1 X 5V (rechargeable) powerbank with USB cable

Parts of the code you may wish to change:
- Lines # 5 & 6 defines the pins on the Arduino Nano for connecting the TRIG & ECHO pins from the HC-SR04 sensor.
- Line # 8 defines which pin you will attach the +ve lead of the vibrating motor to.
- Lines # 49 & 54 define the distances at which you wish to trigger different vibration feedback to the user.
- Lines # 69 & 71 define the type of pulsing you want for the distance triggered by calling "void lt_a".
- Lines # 76 & 78 define the type of pulsing you want for the distance triggered by calling "void lt_b".

(You may only wish to have one pulse type - if this is the case, set the delays for lt_a & lt_b to be exactly the same. This will allow you to more cleanly revert to 2 different pulses at a later date if required.)

This device is being field tested in Jordan - please feel free to msg with any potential improvements.
