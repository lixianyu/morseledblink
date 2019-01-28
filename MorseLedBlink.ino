/*
  用LED输出摩尔斯电码：happy new year 2019!
*/

int LED_PIN = 4; // D4

char ALPHA[] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r',
      's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', 
      '!', ',', '?', '.', '\''};

char *MORSE[] = { ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..",
      "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", 
      ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----.", "-----", 
      "-.-.--", "--..--", "..--..", ".-.-.-", ".----."};

#define DIT_LIGHTEN_TIME 200 // 点
#define DAH_LIGHTEN_TIME 600 // 划 3 * DIT_LIGHTEN_TIME
#define DIT_AND_DAH      DIT_LIGHTEN_TIME // 点和划之间停顿
#define LetterInterval   DAH_LIGHTEN_TIME // 字符之间的停顿
#define WordInterval     1400 // 单词之间的停顿 7 * DIT_LIGHTEN_TIME
#define NEXT_CIRCLE      4000

int gALPHALen;
int gStringLen;
char gLedShowString[] = "happy new year 2019!";
//char gLedShowString[] = "hb sos";

void setup() {
//  Serial.begin(115200);
  // initialize digital pin LED_PIN as an output.
  pinMode(LED_PIN, OUTPUT);
  gALPHALen = sizeof(ALPHA);
//  Serial.print("gALPHALen = ");
//  Serial.println(gALPHALen);
  gStringLen = strlen(gLedShowString);
//  Serial.print("gStringLen = ");
//  Serial.println(gStringLen);
}

int gLedIdx = 0;
int gMorseIdx = -1;
void loop() {
//  Serial.print("gLedIdx = ");
//  Serial.println(gLedIdx);
  gMorseIdx = -1;
  for (int i = 0; i < gALPHALen; i++) {
    if (ALPHA[i] == gLedShowString[gLedIdx]) {
      gMorseIdx = i;
      break;
    }
  }
  
//  Serial.print("gMorseIdx = ");
//  Serial.println(gMorseIdx);
  if (gMorseIdx == -1) { // We find ' ' --- blank
//    Serial.print(' ');
    delay(WordInterval);
    doNext();
    return;
  }
//  Serial.print(ALPHA[gMorseIdx]);
  // We find next letter
  delay(LetterInterval);
  
  // 显示一个字母
  String theMorse = String(MORSE[gMorseIdx]);
  int len = theMorse.length();
  
//  Serial.print("len = ");
//  Serial.println(len);
  for (int i = 0; i < len; i++) {
    digitalWrite(LED_PIN, HIGH);
    if ('.' == theMorse.charAt(i)) {
      delay(DIT_LIGHTEN_TIME);
    } else {
      delay(DAH_LIGHTEN_TIME);
    }
    digitalWrite(LED_PIN, LOW);
    if (i >= (len - 1)) break;
    delay(DIT_AND_DAH);
  }
  
  doNext();
}

void doNext() {
  gLedIdx++;
  if (gLedIdx >= gStringLen) { // 没有更多的字符了，等待几秒，进行下一轮儿
//    Serial.println("next circle.");
    gLedIdx = 0;
    delay(NEXT_CIRCLE);
  }
}

