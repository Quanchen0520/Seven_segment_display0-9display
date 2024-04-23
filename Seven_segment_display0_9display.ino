// 定義七段顯示器的引腳陣列（對應到 a ~ g）
int seg7[] = {22, 23, 24, 25, 26, 27, 28, 29};
// 定義共陰七段顯示器編碼表
char TAB[] = {0x40, 0x79, 0x24, 0x30, 0x19, 0x12, 0x02, 0x78, 0x00, 0x18};

void setup() {
   // 設置七段顯示器的腳位為輸出
   for (int i = 0; i < 7; i++) {
     pinMode(seg7[i], OUTPUT);
   }
}

void loop() {
   // 循環顯示七段顯示器編碼表中的數字
   for (int i = 0; i < 10; i++) {
     // 將七段顯示器編碼寫入七段顯示器並顯示
     OutPort(TAB[i]);
     delay(500); // 延遲一段時間以便觀察
   }
}

// 將七段顯示器編碼寫入七段顯示器的函式
void OutPort(byte dat) {
   // 將七段顯示器編碼的每個位元寫入對應的腳位
   for (int j = 0; j < 7; j++) {
     digitalWrite(seg7[j], dat % 2);
     dat = dat / 2;
   }
}
