# Morse code on LED
摩尔斯电码主要参考了：  https://en.wikipedia.org/wiki/Morse_code

# How to use
更改gLedShowString内容，运行后即可看到接到D4管脚的LED按照Morse code闪烁了

更改下面的宏，可对时间进行控制：
```
#define DIT_LIGHTEN_TIME 200 // 点

#define DAH_LIGHTEN_TIME 600 // 划 3 * DIT_LIGHTEN_TIME

#define DIT_AND_DAH      DIT_LIGHTEN_TIME // 点和划之间停顿

#define LetterInterval   DAH_LIGHTEN_TIME // 字符之间的停顿

#define WordInterval     1400 // 单词之间的停顿 7 * DIT_LIGHTEN_TIME

#define NEXT_CIRCLE      4000
```
