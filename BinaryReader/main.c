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

    // �o�C�i���f�[�^��ǂݍ���
    DataPair* dataArray = readBinaryData(filename, dataCount);
    if (dataArray == NULL) {
        return 1;
    }

    // �ǂݍ��񂾃f�[�^��\��
    displayData(dataArray, dataCount);

    // ���������
    free(dataArray);

    return 0;
}