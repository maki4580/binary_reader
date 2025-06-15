#include "binary_reader.h"
#include <stdio.h>
#include <stdlib.h>

// 1つのデータペアを読み取る関数（内部関数）
static void readDataPair(FILE* file, long offset, DataPair* dataPair) {
    // 指定された位置にシーク
    fseek(file, offset, SEEK_SET);
    
    // 2バイトずつ2つのデータを読み取る
    fread(&dataPair->value1, sizeof(unsigned short), 1, file);
    fread(&dataPair->value2, sizeof(unsigned short), 1, file);
}

// バイナリファイルからデータを読み込む関数
int readBinaryData(const char* filename, DataPair* dataArray, int dataCount) {
    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        return 1; // ファイルオープン失敗
    }

    for (int i = 0; i < dataCount; i++) {
        long offset = i * sizeof(DataPair);
        readDataPair(file, offset, &dataArray[i]);
    }

    fclose(file);
    return 0; // 正常終了
}

// データの表示関数
void displayData(DataPair* dataArray, int dataCount) {
    for (int i = 0; i < dataCount; i++) {
        printf("データ %d: value1 = %u (16進数: 0x%04X), value2 = %u (16進数: 0x%04X)\n", 
               i, dataArray[i].value1, dataArray[i].value1, 
               dataArray[i].value2, dataArray[i].value2);
    }
}