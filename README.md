# IR Controlled RC Car (Arduino Project)

This is an IR remote controlled RC car built using Arduino, a motor driver, and an IR receiver. The car can move forward, backward, left, and right. Speed can also be increased or decreased using the remote.

*This project is currently under development.*

---

## Components Used

- Arduino UNO board
- IR receiver module
- IR remote
- L298N motor driver
- 2 DC motors
- Battery pack
- Jumper wires
- Ultrasonic sensor (upcoming feature)
- Car chassis (3D printed – upcoming)
- LCD display (upcoming feature)

---

## Features

- Forward movement
- Reverse movement
- Left and right turning
- Speed control (0–255 using PWM)
- Auto stop if no signal is received for 2 seconds

---

## Pin Configuration

### IR Receiver
| Component | Pin |
|-----------|-----|
| IR Signal | 2   |

### Motor Driver
| Function | Pin |
|----------|-----|
| enA      | 3   |
| enB      | 11  |
| inA1     | 13  |
| inA2     | 9   |
| inB1     | 10  |
| inB2     | 12  |

---

## How It Works

1. The IR receiver detects signals from the remote.
2. Each button corresponds to a specific movement command.
3. PWM is used to control motor speed.
4. If no signal is received for 2 seconds, the motors automatically stop for safety.

---

## Upcoming Features

- Automatic obstacle detection using an ultrasonic sensor.
- Stop the car if an object is detected within a specific distance.
- Display current speed on the LCD screen.
- Display obstacle detection status on the LCD.

---
