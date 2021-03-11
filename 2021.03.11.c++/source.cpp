#include<iostream>
#include<fstream>
#include<iomanip>
#include<string.h>

#define MAX 16*10000
#define PATH "e:\\workplace\\gpt.img"
#define wdPATH "e:\\workplace\\gpt.dat"
using namespace std;
int value[MAX];	//存放读取的数据

/*计算文件大小*/
int getFileSize()
{
	struct stat statbuf;
	stat(PATH, &statbuf);
	int size = statbuf.st_size;
	return size;
}

/*文件写入十六进制数据*/
void wrFile()
{
	unsigned long i, j;
	i = 0, j = 0;	//控制行列
	char c;	//缓存
	unsigned long size = getFileSize();

	ifstream fin(PATH, ios::binary);
	ofstream fout(wdPATH, ios::binary);

	if (!fin)
		cout << "文件打开失败！" << endl;
	fout.setf(ios::uppercase);	//转换大写
	fout << setfill('0');	//空格用0填充

	//开始写入
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

/*扫描读取分区名和计算分区大小*/
void scanFile()
{

}

int main()
{
	wrFile();
	system("pause");
}