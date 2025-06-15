#include "binary_reader.h"
#include <stdio.h>
#include <stdlib.h>

// 1�̃f�[�^�y�A��ǂݎ��֐��i�����֐��j
static void readDataPair(FILE* file, long offset, DataPair* dataPair) {
    // �w�肳�ꂽ�ʒu�ɃV�[�N
    fseek(file, offset, SEEK_SET);
    
    // 2�o�C�g����2�̃f�[�^��ǂݎ��
    fread(&dataPair->value1, sizeof(unsigned short), 1, file);
    fread(&dataPair->value2, sizeof(unsigned short), 1, file);
}

// �o�C�i���t�@�C������f�[�^��ǂݍ��ފ֐�
int readBinaryData(const char* filename, DataPair* dataArray, int dataCount) {
    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        return 1; // �t�@�C���I�[�v�����s
    }

    for (int i = 0; i < dataCount; i++) {
        long offset = i * sizeof(DataPair);
        readDataPair(file, offset, &dataArray[i]);
    }

    fclose(file);
    return 0; // ����I��
}

// �f�[�^�̕\���֐�
void displayData(DataPair* dataArray, int dataCount) {
    for (int i = 0; i < dataCount; i++) {
        printf("�f�[�^ %d: value1 = %u (16�i��: 0x%04X), value2 = %u (16�i��: 0x%04X)\n", 
               i, dataArray[i].value1, dataArray[i].value1, 
               dataArray[i].value2, dataArray[i].value2);
    }
}