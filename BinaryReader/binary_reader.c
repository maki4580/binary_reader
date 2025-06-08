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
DataPair* readBinaryData(const char* filename, int dataCount) {
    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        printf("�t�@�C�����J���܂���ł���: %s\n", filename);
        return NULL;
    }

    // �f�[�^�����̍\���̔z����m��
    DataPair* dataArray = (DataPair*)malloc(dataCount * sizeof(DataPair));
    if (dataArray == NULL) {
        printf("�������m�ۂɎ��s���܂���\n");
        fclose(file);
        return NULL;
    }

    // �w�肳�ꂽ������for���[�v�Ńf�[�^��ǂݎ��
    for (int i = 0; i < dataCount; i++) {
        // �e�f�[�^�y�A�̈ʒu (�e�y�A��4�o�C�g: value1(2�o�C�g) + value2(2�o�C�g))
        long offset = i * sizeof(DataPair);
        
        // ��p�̊֐��Ńf�[�^��ǂݎ��
        readDataPair(file, offset, &dataArray[i]);
    }

    fclose(file);
    return dataArray;
}

// �f�[�^�̕\���֐�
void displayData(DataPair* dataArray, int dataCount) {
    for (int i = 0; i < dataCount; i++) {
        printf("�f�[�^ %d: value1 = %u (16�i��: 0x%04X), value2 = %u (16�i��: 0x%04X)\n", 
               i, dataArray[i].value1, dataArray[i].value1, 
               dataArray[i].value2, dataArray[i].value2);
    }
}