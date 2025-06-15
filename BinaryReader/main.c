#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binary_reader.h"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("�g�p���@: %s <�f�[�^��>\n", argv[0]);
        return 1;
    }

    // �o�C�i���t�@�C���̃p�X���Œ�
    const char* filename = "data/sample.dat";
    int dataCount = atoi(argv[1]);

    if (dataCount <= 0) {
        printf("�f�[�^���͐��̐������w�肵�Ă�������\n");
        return 1;
    }

    // DataPair�z��̃������m��
    DataPair* dataArray = (DataPair*)malloc(sizeof(DataPair) * dataCount);
    if (dataArray == NULL) {
        printf("�������m�ۂɎ��s���܂���\n");
        return 1;
    }

    // �o�C�i���f�[�^��ǂݍ���
    int result = readBinaryData(filename, dataArray, dataCount);
    if (result != 0) {
        printf("�f�[�^�̓ǂݍ��݂Ɏ��s���܂����i�G���[�R�[�h: %d�j\n", result);
        free(dataArray);
        return 1;
    }

    // �ǂݍ��񂾃f�[�^��\��
    displayData(dataArray, dataCount);

    // ���������
    free(dataArray);

    return 0;
}