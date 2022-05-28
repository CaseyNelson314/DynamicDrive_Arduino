# DynamicDriver

## Usage

- ピン番号は以下のフォーマットでセット

  ```cpp
  |--d--|
  c     e
  |--g--|
  b     f
  |--a--|  h
  ```

- Vcc ピンは Vcc 構造体にセット

  ```cpp
  //a, b, c, d, e, f, g, hの順で
  DynamicDriver::Vcc vcc = {7, 6, 3, 4, 5, 8, 2, 9};
  ```

- 実態作成後、コンストラクタの引数にセット

  ```cpp
  DynamicDriver led(vcc, 13, 12, 11, 10);
  ```

- 以下のようにセットすることもできます

  ```cpp
  DynamicDriver led({7, 6, 3, 4, 5, 8, 2, 9}, 13, 12, 11, 10);
  ```

- 数字を表示

  ```cpp
  led.show(1234);
  ```

## FUnctions

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
