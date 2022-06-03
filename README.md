# DynamicDriver

### ダイナミック制御を行うクラス

- 動作例

  ![A2542_I2](https://user-images.githubusercontent.com/91818705/170850975-eebcd7bd-d813-4c47-b9d0-89223f45d978.jpg)

## Usage

- Vcc ピンを Vcc 構造体にセット後、コンストラクタの引数に実体、GNDピン(下桁から)、セット

  ```cpp
  //                        a, b, c, d, e, f, g, h
  //                        ↓  ↓  ↓  ↓  ↓  ↓  ↓  ↓
  DynamicDriver::Vcc vcc = {7, 6, 3, 4, 5, 8, 2, 9};
  DynamicDriver led(vcc, 13, 12, 11, 10);
  
  //DynamicDriver led({7, 6, 3, 4, 5, 8, 2, 9}, 13, 12, 11, 10);  //this is ok
  
  ```
- ピン番号は以下のフォーマット

  <img height=200 src="https://user-images.githubusercontent.com/91818705/170850625-cc4a0105-8c0d-46ca-a28e-d3dd373ad85f.png">

- 数字を表示

  ```cpp
  led.show(1234);
  ```

## Functions

- `DynamicDriver(const Vcc &vcc, T... gnd)`

  DynamicDriver のオブジェクトを作成

  - vcc : Vcc 構造体の実体
  - gnd : GND ピン(桁数分)

- `show(uint32_t num)`

  整数値を出力

  - num : 出力値(整数)

- `show(double num, uint8_t maxDecimalDigit = 1)`

  小数値を出力

  - num : 出力値(浮動小数)
  - maxDecimalDigit : 表示する小数の桁

- `test(uint8_t testPin)`

  出力確認用

  - testPin : 出力するピン

- `demo()`

  デモ
