// main.cpp
#include <Arduino.h>
#include <Arduino_FreeRTOS.h>
#include <queue.h>

// Pin definitions
const int gestureSensorPin = 2;   // IR sensor or ultrasonic trigger
const int ledPin = 13;            // LED for debug

// Queue handle
QueueHandle_t gestureQueue;

// Function declarations
void GestureTask(void *pvParameters);
void ActionTask(void *pvParameters);

void setup() {
  pinMode(gestureSensorPin, INPUT);
  pinMode(ledPin, OUTPUT);

  Serial.begin(9600);

  // Create queue with capacity of 5 gesture codes
  gestureQueue = xQueueCreate(5, sizeof(int));

  if (gestureQueue != NULL) {
    // Create RTOS tasks
    xTaskCreate(GestureTask, "Gesture", 128, NULL, 1, NULL);
    xTaskCreate(ActionTask, "Action", 128, NULL, 1, NULL);
  }

  // Start scheduler
  vTaskStartScheduler();
}

void loop() {
  // Empty: RTOS takes over
}

void GestureTask(void *pvParameters) {
  int gesture;
  while (1) {
    // Simple gesture simulation: HIGH = 1 (gesture detected)
    if (digitalRead(gestureSensorPin) == HIGH) {
      gesture = 1; // can later extend with different gestures
      xQueueSend(gestureQueue, &gesture, portMAX_DELAY);
      Serial.println("Gesture Detected!");
      vTaskDelay(500 / portTICK_PERIOD_MS); // debounce delay
    }
    vTaskDelay(100 / portTICK_PERIOD_MS);
  }
}

void ActionTask(void *pvParameters) {
  int receivedGesture;
  while (1) {
    if (xQueueReceive(gestureQueue, &receivedGesture, portMAX_DELAY)) {
      if (receivedGesture == 1) {
        Serial.println("Play/Pause Action Triggered");
        digitalWrite(ledPin, HIGH);
        vTaskDelay(200 / portTICK_PERIOD_MS);
        digitalWrite(ledPin, LOW);
      }
    }
  }
}

