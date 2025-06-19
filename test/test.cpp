// ABOUTME: Test file for PictoWatch project
// ABOUTME: Contains Unity tests for LVGL and touchscreen features
#include <Arduino.h>
#include "unity.h"
#include <Wire.h>
#include <TouchDrvFT6X36.hpp>

TouchDrvFT6X36 touch;

void setUp(void) {
  // Initialize I2C and touch driver
  Wire.begin();
  touch.begin(Wire, FT6X36_SLAVE_ADDRESS);
}

void tearDown(void) {
  // No teardown needed
}

void waitForGesture(const char *prompt, TouchDrvFT6X36::GesTrue expected, uint32_t timeout_ms = 5000) {
  Serial.println(prompt);
  uint32_t start = millis();
  while (millis() - start < timeout_ms) {
    TouchDrvFT6X36::GesTrue gesture = (TouchDrvFT6X36::GesTrue)touch.getGesture();
    if (gesture == expected) {
      TEST_ASSERT_EQUAL(expected, gesture);
      return;
    }
    delay(50);
  }
  TEST_FAIL_MESSAGE("Expected gesture not detected in time");
}

void test_touch_swipe_left(void) {
  waitForGesture("Please swipe LEFT on the screen within 5 seconds...", TouchDrvFT6X36::MOVE_LEFT);
}

void test_touch_swipe_right(void) {
  waitForGesture("Please swipe RIGHT on the screen within 5 seconds...", TouchDrvFT6X36::MOVE_RIGHT);
}

void test_touch_short_press(void) {
  Serial.println("Please TAP (short press) the screen within 5 seconds...");
  uint32_t start = millis();
  bool detected = false;
  while (millis() - start < 5000) {
    if (touch.isPressed()) {
      detected = true;
      break;
    }
    delay(50);
  }
  TEST_ASSERT_TRUE_MESSAGE(detected, "Short press not detected");
}

void test_touch_long_press(void) {
  Serial.println("Please LONG PRESS (hold) the screen for >1s within 5 seconds...");
  uint32_t start = millis();
  bool detected = false;
  while (millis() - start < 5000) {
    if (touch.isPressed()) {
      uint32_t pressStart = millis();
      while (touch.isPressed()) {
        if (millis() - pressStart > 1000) {
          detected = true;
          break;
        }
        delay(50);
      }
      if (detected) {
        break;
      }
    }
    delay(50);
  }
  TEST_ASSERT_TRUE_MESSAGE(detected, "Long press not detected");
}

int runUnityTests(void) {
  UNITY_BEGIN();
  // RUN_TEST(test_touch_swipe_left);
  // RUN_TEST(test_touch_swipe_right);
  // RUN_TEST(test_touch_short_press);
  // RUN_TEST(test_touch_long_press);
  return UNITY_END();
}

void setup() {
  delay(2000);
  runUnityTests();
}
void loop() {}
