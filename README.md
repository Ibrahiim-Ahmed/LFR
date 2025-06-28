# 🤖 5‑IR Sensor Line Following Robot – Arduino Uno + PID + Adafruit Motor Shield V1

This project presents a fully autonomous line-following robot that uses **five analog IR sensors**, a **PID control loop**, and an **Arduino Uno** paired with the **Adafruit Motor Shield v1.2**. It’s designed to follow a dark line on a white surface with smooth, precise, and intelligent movements—even through tight curves—making it an ideal educational and practical demonstration of embedded systems, sensor integration, and control systems engineering.

---

## 🧠 Project Overview

The robot works by continuously reading reflectance values from five IR sensors mounted in a row on the front of the chassis. These sensors detect changes in surface color (black line on white surface), and their readings are used to calculate the position of the line beneath the robot.

A PID (Proportional–Integral–Derivative) control algorithm determines how far the robot has deviated from the center of the line and adjusts the motor speeds accordingly. The Adafruit Motor Shield is used to drive two DC gear motors independently, allowing for tight cornering, smooth turns, and stable straight-line motion. Unlike simpler bang-bang or digital 3-sensor systems, this build achieves **real-time analog feedback and fine-tuned control**.

---

## 🧩 Component List and Their Functions

| Component                                      | Function                                                                                    |
| ---------------------------------------------- | ------------------------------------------------------------------------------------------- |
| 🧠 **Arduino Uno R3**                          | The microcontroller that processes sensor input, runs the PID loop, and controls the motors |
| ⚙️ **Adafruit Motor Shield v1.2**              | Drives the left and right DC motors with independent PWM speed control                      |
| 👁 **5x IR Sensors (TCRT5000 or equivalents)** | Detects the black line on the surface and sends analog signals to A0–A4                     |
| 🔩 **2x DC Gear Motors**                       | Provides movement; each motor is controlled independently for differential drive            |
| 🛞 **Wheels & Caster**                         | Two main wheels for propulsion and a caster or skid for balance                             |
| 🔋 **7.4V Li-ion Battery Pack**                | Powers the Arduino and motors through the motor shield                                      |
| 📦 **Chassis / Base Plate**                    | Mounts all components securely; can be acrylic or 3D printed                                |
| 🧰 **Cables, Resistors, Switches, etc.**       | For wiring, on/off control, and sensor conditioning                                         |

---

## ⚙️ How It Works – Control Flow

1. **Analog Reading**: The Arduino reads all five analog values from IR sensors on pins A0–A4.
2. **Line Position Calculation**: A weighted average is computed to find the approximate position of the black line relative to the center.
3. **Error Generation**: The difference between the line's current position and the "center" is calculated as the error.
4. **PID Controller**: The error is passed through a PID algorithm to compute a correction output.
5. **Motor Speed Adjustment**: The correction is added/subtracted from a base motor speed to adjust left/right motors accordingly.
6. **Repeat Loop**: This process runs continuously in the `loop()` function for real-time response.

---

## 🔧 Key Features

✅ Real-time PID-based line following
🎯 Five-point analog sensor accuracy
⚡ Precise curve handling without jitter
🔄 Smooth acceleration and cornering
🧪 Educational example of control systems
🔌 Powered by common components (no rare modules)
📦 Fully open-source: modify, remix, expand freely

---

## 🛠️ Working Principle (Brief Summary)

The IR sensors act as the robot's "eyes", detecting the contrast between the black line and the white surface. These readings are processed to calculate how far off-center the robot is from the line. The PID controller calculates how much to adjust the speed of the left and right motors to bring the robot back toward the center. By doing this continuously at high speed, the robot gracefully follows the line even during curves and direction changes.

---

![lfr](https://github.com/user-attachments/assets/2579a7b7-5734-4c44-ba80-c87a8a1e0e88)



## 🧪 Learning Objectives

This project helps learners understand:

* 📏 Analog sensor calibration and data acquisition
* ⚙️ PID control in real-world embedded applications
* 🧠 Motor control using PWM and H-bridge drivers
* 🧰 Practical debugging of sensor-based systems
* 🔁 Real-time system behavior under dynamic input

---

## 📚 Applications

Although made for education, this robot has many useful applications:

* 🔬 Engineering education and embedded systems labs
* 🤖 Intro to robotics and path-following AI
* 🏭 Prototype AGV (automated guided vehicle) concepts
* 🎓 Competitions (RoboLine, TechFests, etc.)

---

## ⚠️ Limitations

This robot follows only high-contrast black lines on white surfaces.
It does not detect obstacles, intersections, or multiple paths.
Battery level affects performance—ensure full charge for optimal results.
The PID constants require tuning based on the environment and speed.

---


## 👨‍💻 Contribution

Pull requests, issues, and forks are welcome!
You can contribute by:

* 🧠 Improving the PID tuning method
* 🧪 Adding real-time feedback (e.g., OLED display)
* 🤖 Adding obstacle detection or intersections
* 📝 Translating documentation to other languages

---

## 📜 License

You are free to use, modify, and distribute it with attribution.

---

