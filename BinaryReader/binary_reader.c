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
DataPair* readBinaryData(const char* filename, int dataCount) {
    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        printf("ファイルを開けませんでした: %s\n", filename);
        return NULL;
    }

    // データ数分の構造体配列を確保
    DataPair* dataArray = (DataPair*)malloc(dataCount * sizeof(DataPair));
    if (dataArray == NULL) {
        printf("メモリ確保に失敗しました\n");
        fclose(file);
        return NULL;
    }

    // 指定された数だけforループでデータを読み取り
    for (int i = 0; i < dataCount; i++) {
        // 各データペアの位置 (各ペアは4バイト: value1(2バイト) + value2(2バイト))
        long offset = i * sizeof(DataPair);
        
        // 専用の関数でデータを読み取る
        readDataPair(file, offset, &dataArray[i]);
    }

    fclose(file);
    return dataArray;
}

// データの表示関数
void displayData(DataPair* dataArray, int dataCount) {
    for (int i = 0; i < dataCount; i++) {
        printf("データ %d: value1 = %u (16進数: 0x%04X), value2 = %u (16進数: 0x%04X)\n", 
               i, dataArray[i].value1, dataArray[i].value1, 
               dataArray[i].value2, dataArray[i].value2);
    }
}