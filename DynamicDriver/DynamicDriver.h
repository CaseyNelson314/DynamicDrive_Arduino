/**
 * @file   DynamicDriver.h
 * @author CaseyNelson
 * @brief  Dynamic controller
 * @date   2022-05-28
 */

#pragma once

class DynamicDriver {
 public:
  /**
   * @brief ピン格納用構造体 ↓配置
   * |--d--|
   * c     e
   * |--g--|
   * b     f
   * |--a--|  h
   */
  struct Vcc {
    const uint8_t a, b, c, d, e, f, g, h;
  };

  /**
   * @brief Construct a new Dynamic Driver object
   * @tparam T  auto
   * @param vcc Vcc構造体の実体
   * @param gnd GNDピン
   */
  template <typename... T>
  DynamicDriver(const Vcc &vcc, T... gnd) : digitCount(sizeof...(gnd)) {
    this->gnd = new uint8_t[digitCount];
    const uint8_t gndList[] = {static_cast<uint8_t>(gnd)...};
    memcpy(this->gnd, gndList, digitCount);

    this->vcc[0] = vcc.a;
    this->vcc[1] = vcc.b;
    this->vcc[2] = vcc.c;
    this->vcc[3] = vcc.d;
    this->vcc[4] = vcc.e;
    this->vcc[5] = vcc.f;
    this->vcc[6] = vcc.g;
    this->vcc[7] = vcc.h;

    for (const uint8_t &i : this->vcc) pinMode(i, OUTPUT);
    for (const uint8_t &i : gndList) {
      pinMode(i, OUTPUT);
      digitalWrite(i, HIGH);
    }
  }

  /**
   * @brief 出力(整数)
   * @param num 出力値
   */
  void show(uint32_t num) {
    for (uint8_t i = 0; i < digitCount; i++) {  //下桁から表示
      digitalWrite(gnd[i], LOW);
      showSingleNum(num % 10);
      digitalWrite(gnd[i], HIGH);
      num /= 10;
    }
  }

  /**
   * @brief 出力(浮動小数点)
   * @param num 出力値
   * @param maxDecimalDigit 表示する小数点の桁
   */
  void show(double num, uint8_t maxDecimalDigit = 1) {
    show(static_cast<uint32_t>(floor(num * pow(10, maxDecimalDigit))));
    if (maxDecimalDigit == 0) return;
    digitalWrite(gnd[maxDecimalDigit], LOW);
    digitalWrite(vcc[7], HIGH);
    delayMicroseconds(10);
    digitalWrite(vcc[7], LOW);
    digitalWrite(gnd[maxDecimalDigit], HIGH);
  }

  /**
   * @brief ピンを確認する
   * @param testPin 確認するピン
   */
  void test(uint8_t testPin) {
    pinMode(testPin, OUTPUT);
    digitalWrite(testPin, HIGH);
  }

  /**
   * @brief millis()を表示するデモ
   */
  void demo() { show(millis() % static_cast<uint32_t>(pow(10, digitCount))); }

 private:
  uint8_t vcc[8];      // Vcc vcc
  uint8_t *gnd;        // GND vcc
  uint8_t digitCount;  // digit num

  /**
   * @brief 1文字出力
   * @param num 出力値
   */
  void showSingleNum(uint8_t num) {
    static const uint8_t patternMap[] = {
        // hgfedcba
        0b00111111,  // 0
        0b00110000,  // 1
        0b01011011,  // 2
        0b01111001,  // 3
        0b01110100,  // 4
        0b01101101,  // 5
        0b01101111,  // 6
        0b00111000,  // 7
        0b01111111,  // 8
        0b01111101,  // 9
    };
    for (uint8_t i = 0; i < 8; i++)
      digitalWrite(vcc[i], bitRead(patternMap[num], i));
    delayMicroseconds(10);
    for (uint8_t i = 0; i < 8; i++) digitalWrite(vcc[i], LOW);
  }
};
