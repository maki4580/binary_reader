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

    // バイナリデータを読み込む
    DataPair* dataArray = readBinaryData(filename, dataCount);
    if (dataArray == NULL) {
        return 1;
    }

    // 読み込んだデータを表示
    displayData(dataArray, dataCount);

    // メモリ解放
    free(dataArray);

    return 0;
}