/*
 * Copyright (c) 2014-2017 Cesanta Software Limited
 * All rights reserved
 *
 * Arduino Adafruit DHT library API wrapper
 */

#include <math.h>
#include "mgos_arduino_sht31.h"

#define MGOS_SHT31_RES_FAIL -12700

Adafruit_SHT31 *mgos_sht31_create(int pin_sda, int pin_scl, int addr) {
  return new Adafruit_SHT31(pin_sda, pin_scl, addr);
}

void mgos_sht31_close(Adafruit_SHT31 *sht31) {
  if (sht31 != nullptr) {
    delete sht31;
    sht31 = nullptr;
  }
}

void mgos_sht31_begin(Adafruit_SHT31 *sht31) {
  if (sht31 == nullptr) return;
  sht31->begin();
}

int mgos_sht31_read_temperature(Adafruit_SHT31 *sht31) {
  if (sht31 == nullptr) return MGOS_SHT31_RES_FAIL;
  float res = sht31->readTemperature();
  return isnan(res) ? MGOS_SHT31_RES_FAIL : round(res * 100.0);
}

int mgos_sht31_read_humidity(Adafruit_SHT31 *sht31) {
  if (sht31 == nullptr) return MGOS_SHT31_RES_FAIL;
  float res = sht31->readHumidity();
  return isnan(res) ? MGOS_SHT31_RES_FAIL : round(res * 100.0);
}
