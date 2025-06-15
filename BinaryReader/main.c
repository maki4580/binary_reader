#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binary_reader.h"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("使用方法: %s <データ数>\n", argv[0]);
        return 1;
    }

    // バイナリファイルのパスを固定
    const char* filename = "data/sample.dat";
    int dataCount = atoi(argv[1]);

    if (dataCount <= 0) {
        printf("データ数は正の整数を指定してください\n");
        return 1;
    }

    // DataPair配列のメモリ確保
    DataPair* dataArray = (DataPair*)malloc(sizeof(DataPair) * dataCount);
    if (dataArray == NULL) {
        printf("メモリ確保に失敗しました\n");
        return 1;
    }

    // バイナリデータを読み込む
    int result = readBinaryData(filename, dataArray, dataCount);
    if (result != 0) {
        printf("データの読み込みに失敗しました（エラーコード: %d）\n", result);
        free(dataArray);
        return 1;
    }

    // 読み込んだデータを表示
    displayData(dataArray, dataCount);

    // メモリ解放
    free(dataArray);

    return 0;
}