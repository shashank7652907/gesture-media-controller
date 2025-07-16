# 🎮 Gesture-Based Media Controller (FreeRTOS-Based)

An Arduino-based media controller that recognizes hand gestures using ultrasonic sensors and executes actions like Play/Pause and Next/Previous. Enhanced with **FreeRTOS** for modular task-based execution, this project showcases real-time scheduling and sensor-action separation.

---

## 📌 Key Features

- 🖐️ IR or ultrasonic gesture detection
- ⚙️ RTOS-based task separation (GestureTask + ActionTask)
- 💡 Debug LED feedback
- 🔁 Uses FreeRTOS queues for task communication
- 📉 Lightweight and real-time responsive

---

## 🧠 Architecture Overview

```
[Ultrasonic Sensor 1/2]
       |
   [GestureTask]
       |
    [Queue]
       |
   [ActionTask] —> Media action + LED
```

---

## 🛠️ Tech Stack

| Component        | Description                              |
|------------------|------------------------------------------|
| **MCU**          | Arduino Nano (ATmega328p)                |
| **Sensors**      | Ultrasonic HC-SR04 (x2)                  |
| **OS**           | FreeRTOS via Arduino_FreeRTOS_Library    |
| **Comm**         | Tasks + Queue from FreeRTOS              |
| **Tools**        | Arduino IDE, Serial Monitor, Fritzing    |

---

## 🔧 Setup Instructions

1. Clone this repo:

    ```bash
    git clone https://github.com/shashank7652907/gesture-media-controller.git
    cd gesture-media-controller
    ```

2. Install `Arduino_FreeRTOS_Library` via Library Manager.

3. Connect the ultrasonic sensors as per schematic.

4. Upload code using Arduino IDE.

---

## 📁 File Structure

```
gesture-media-controller/
├── src/
│   └── main.cpp
├── include/
│   └── FreeRTOSConfig.h
├── images/
│   └── schematic.png
│   └── demo.gif (optional)
├── README.md
├── LICENSE
├── .gitignore
```

---

## ✍️ Author

**Shashank Adepu**  
Embedded Systems | ECE | Real-time Linux & RTOS enthusiast  

---

## ⚖️ License

This project is licensed under the [MIT License](./LICENSE).

---

## 💡 Future Improvements

- Add support for multiple gestures (forward, backward)
- Integrate BLE to control real music app
- Low-power optimization using sleep mode. - Include Python CV so that hand movements are recoginized .


