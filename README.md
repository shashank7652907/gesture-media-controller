
# ✋ Gesture-Based Media Controller using Arduino

This project demonstrates a media controller that uses **ultrasonic sensors** to recognize hand gestures and control media playback functions like Play/Pause, Next, and Previous.

## 🎯 Features
- Gesture-based control using 2 ultrasonic sensors
- Arduino UNO-based logic
- Communicates with PC to trigger media controls
- Simple and easy to build

## 📷 Demo
> Include images in the `images/` folder and a video in `videos/`

### Gesture Actions
| Gesture        | Action       |
|----------------|--------------|
| Swipe Right    | Next Track   |
| Swipe Left     | Previous     |
| Hold Both      | Play/Pause   |

## 🧠 Code Overview
See `gesture_controller.ino` for full code. Sample output via `Serial.println()`:

```
NEXT
PREV
PLAY_PAUSE
```

Connect this to Python/PyAutoGUI or AutoHotKey script on PC to trigger keyboard shortcuts.

## 🔧 Components
- Arduino UNO
- 2x HC-SR04 Ultrasonic Sensors
- Jumper Wires + Breadboard
- USB Cable

## 📜 How it Works
- Sensor 1 = detects right hand
- Sensor 2 = detects left hand
- Based on proximity logic, the Arduino sends serial commands for media control.

## 🛠 Tools Used
- Arduino IDE
- (Optional) Python + PyAutoGUI for controlling PC

## 🧩 Wiring Diagram
> Upload `wiring_diagram.png` inside `docs/`

## 👨‍💻 Author
- **A. Shashank**  
  [GitHub](https://github.com/shashank7652907)

## 📜 License
MIT License
