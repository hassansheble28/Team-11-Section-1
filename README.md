# Team 11 - Section 1: Obstacle-Avoiding Robot

An autonomous, object following robot project built on **Mbed OS 6**. The system continuously monitors forward clearance using a non-blocking HC-SR04 ultrasonic sensor and modulates its dual-channel DC motor speeds dynamically to follow the object and stop at a safe distance.

---

## 📂 Project Structure

The codebase is modularly organized into distinct abstraction layers:

* **`main.cpp`** — Core execution loop, state logic control, and threshold assessment.
* **`Ultrasonic.h` / `.cpp`** — High-performance ultrasonic driver utilizing hardware `InterruptIn` (rise/fall ISRs) and modern `std::chrono` timing to extract raw distance metrics without blocking execution.
* **`RobotDrive.h`** — Motor driver abstraction class controlling direction logic via `DigitalOut` pins and speed scaling via `PwmOut` duty-cycles (set to a stable 1kHz period).

---

## 🔌 Hardware Configuration & Pin Map

### Microcontroller Target
* **Platform:** ARM Mbed Compatible (e.g., NUCLEO series)

### Pinout Mapping

| Component | Function | MCU Pin |
| :--- | :--- | :--- |
| **Ultrasonic Sensor** | Trigger | `D3` |
| | Echo | `D2` |
| **Left Motor Control** | L\_PWM (Speed) | `D5` |
| | L\_IN1 (Direction) | `D7` |
| | L\_IN2 (Direction) | `D4` |
| **Right Motor Control**| R\_PWM (Speed) | `D6` |
| | R\_IN3 (Direction) | `D11` |
| | R\_IN4 (Direction) | `D8` |

---

## ⚙️ Control Logic Thresholds

The robot samples data and adjusts its movement vector dynamically every **100ms** based on the following rules:

* **Distance < 12 cm (or invalid loop-overflow > 400 cm):** Immediate Hard Stop (`robot.stop()`).
* **Distance > 50 cm:** Clear path ahead. Fast cruise speed (`SPEED_FAR = 0.30f`).
* **Distance 25 cm to 50 cm:** Approaching target threshold. Safe approach speed (`SPEED_NEAR = 0.18f`).
* **Distance < 25 cm:** Target reached. Controlled Stop (`robot.stop()`).

---

## 🛠️ Setup & Dependencies

This repository uses **Git Submodules** to manage firmware dependencies cleanly. 

### Cloning the Project
To pull this repository along with its linked Mbed OS framework dependencies, clone using the `--recursive` flag:
```bash
git clone --recursive [https://github.com/hassansheble28/Team-11-Section-1.git](https://github.com/hassansheble28/Team-11-Section-1.git)
```

---
## 📺 Demonstration & Media

### Robot Operation Video
See the robot in action:

[https://github.com/hassansheble28/Team-11-Section-1/user-attachments/assets/49ba3f2c-61cf-4f2a-b358-cc99b5fb3aca](https://github.com/hassansheble28/Team-11-Section-1/user-attachments/assets/194cbfda-ebf8-4958-baab-bfb148a97fe9)

---

## 📄 Documentation & Reports

The complete academic design constraints, component selections, and system analysis are detailed in the project report:

* 📥 **[Read the Full Technical Report (PDF)](./EmbeddedProject_Team%2011.pdf)**



