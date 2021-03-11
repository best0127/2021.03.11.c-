#include<iostream>
#include<fstream>
#include<iomanip>
#include<string.h>

#define MAX 16*10000
#define PATH "e:\\workplace\\gpt.img"
#define wdPATH "e:\\workplace\\gpt.dat"
using namespace std;
int value[MAX];	//��Ŷ�ȡ������

/*�����ļ���С*/
int getFileSize()
{
	struct stat statbuf;
	stat(PATH, &statbuf);
	int size = statbuf.st_size;
	return size;
}

/*�ļ�д��ʮ����������*/
void wrFile()
{
	unsigned long i, j;
	i = 0, j = 0;	//��������
	char c;	//����
	unsigned long size = getFileSize();

	ifstream fin(PATH, ios::binary);
	ofstream fout(wdPATH, ios::binary);

	if (!fin)
		cout << "�ļ���ʧ�ܣ�" << endl;
	fout.setf(ios::uppercase);	//ת����д
	fout << setfill('0');	//�ո���0���

	//��ʼд��
	while ((j * 16 + i) < size)
	{
		c = fin.get();
		value[j * 16 + i] = ((long(c)) & 0x000000ff);
		if (i == 0)
			fout << hex << setw(7) << j << "0h->";
		fout << hex << setw(2) << value[j*16+i] << " ";
		if (i++ == 15)
		{
			fout << endl;
			i = 0;
			j++;
		}
	}
	fin.close();
	fout.close();
}

/*ɨ���ȡ�������ͼ��������С*/
void scanFile()
{

}

int main()
{
	wrFile();
	system("pause");
}