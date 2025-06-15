#ifndef BINARY_READER_H
#define BINARY_READER_H

// �ǂݎ��f�[�^���i�[����\����
typedef struct {
    unsigned short value1;  // 2�o�C�g�ڂ̃f�[�^
    unsigned short value2;  // 2�o�C�g�ڂ̃f�[�^
} DataPair;

// �o�C�i���t�@�C������f�[�^��ǂݍ��ފ֐�
int readBinaryData(const char* filename, DataPair* dataArray, int dataCount);

// �f�[�^�̕\���֐�
void displayData(DataPair* dataArray, int dataCount);

#endif // BINARY_READER_H