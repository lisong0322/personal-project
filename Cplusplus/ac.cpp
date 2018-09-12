#include <iostream>

#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include <string>
FILE *fp;
using namespace std;
int main()                                          ///
{
    char ch;
    char filename[1000];
    int flag = 0;
    cout << "请输入文本的路径" << endl;
    cin >> filename;
    if ((fp = fopen(filename, "r")) == NULL)
    {
        cout << "路径输入错误" << endl;
        exit(0);
    }
    int lines = 0, characters = 0, words = 0;
    while (true)
    {
        ch = fgetc(fp);
        if(ch==EOF) break;

        if (ch >=' '&&ch <= '~')
        {
            characters++;
        }
        if (ch == '\n')
        {
            lines++;
        }
        if (ch >=' '&&ch <= '~')
        {
            if (ch >= 65 && ch <= 90)
            {
                ch = ch + 32;
            }
            if (ch >= 97 && ch <= 122 && flag <= 3)
            {
                flag++;
            }

            if ((ch < 87 || ch>122) && flag <= 3)
            {
                flag = 0;
            }

            if (flag >= 4 && ch != ' ')
            {
                flag++;
            }

            if (flag >= 4 && ch == ' ')
            {
                words++;
                flag = 0;
            }
        }
    }
    cout << "characters: " << characters << endl;

    cout << "words: " << words << endl;

    cout << "lines: " << lines + 1 << endl;
}
