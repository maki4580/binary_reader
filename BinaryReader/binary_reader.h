#ifndef BINARY_READER_H
#define BINARY_READER_H

// 読み取るデータを格納する構造体
typedef struct {
    unsigned short value1;  // 2バイト目のデータ
    unsigned short value2;  // 2バイト目のデータ
} DataPair;

// バイナリファイルからデータを読み込む関数
int readBinaryData(const char* filename, DataPair* dataArray, int dataCount);

// データの表示関数
void displayData(DataPair* dataArray, int dataCount);

#endif // BINARY_READER_H