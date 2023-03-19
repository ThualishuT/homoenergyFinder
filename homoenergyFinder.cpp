#include <bits/stdc++.h>

using namespace std;

int main()
{
    char ch;
    cout << "请指定分子轴对称性（对称s，不对称a，输入q退出）" << endl;
    while (cin >> ch)
    {
        if (ch == 's')
        {
            int n, count;
            cout << "请输入手性中心个数（输入0返回上一级菜单）：";
            while(cin >> n)
            {
                if (n == 0)
                    break;
                else
                {
                    count = 0;
                    n--;
                    bitset<10000000> b;
                    for (int i = 0; i < (1 << (n + 1)) - 1; i++)
                    {
                        if (b.test(i))
                            continue;
                        else
                        {
                            count++;
                            int rev = 0;
                            for (int j = 0; j <= n / 2; j++)
                            {
                                rev = rev | (i & (1 << (n - j))) >> (n - 2 * j) | (i & (1 << j)) << (n - 2 * j);
                            }
                            b.set(i);
                            b.set(rev);
                            for (int j = n; j >= 0; j--)
                            {
                                if (1 & (i >> j))
                                    cout << 'P';
                                else
                                    cout << 'M';
                            }
                            if (i != rev)
                            {
                                cout << " = ";
                                for (int j = n; j >= 0; j--)
                                {
                                    if (1 & (rev >> j))
                                        cout << 'P';
                                    else
                                        cout << 'M';
                                }
                            }
                            int flip = (~i) & (1 << (n + 1)) - 1;
                            if (rev != flip)
                            {
                                cout << " | ";
                                rev = 0;
                                for (int j = 0; j <= n / 2; j++)
                                {
                                    rev = rev | (flip & (1 << (n - j))) >> (n - 2 * j) | (flip & (1 << j)) << (n - 2 * j);
                                }
                                b.set(flip);
                                b.set(rev);
                                for (int j = n; j >= 0; j--)
                                {
                                    if (1 & (flip >> j))
                                        cout << 'P';
                                    else
                                        cout << 'M';
                                }
                                if (flip != rev)
                                {
                                    cout << " = ";
                                    for (int j = n; j >= 0; j--)
                                    {
                                        if (1 & (rev >> j))
                                            cout << 'P';
                                        else
                                            cout << 'M';
                                    }
                                }
                            }
                            cout << endl
                                 << endl;
                        }
                    }
                    cout << "共有" << count << "种。" << endl << endl;
                }
                cout << "请输入手性中心个数（输入0返回上一级菜单）：";
            }
        }
        else if (ch == 'a')
        {
            int n, count;
            cout << "请输入手性中心个数（输入0返回上一级菜单）：";
            while (cin >> n)
            {
                if (n == 0)
                    break;
                else
                {
                    count = 0;
                    n--;
                    bitset<10000000> b;
                    for (int i = 0; i < (1 << (n + 1)) - 1; i++)
                    {
                        if (b.test(i))
                            continue;
                        else
                        {
                            count++;
                            int flip = (~i) & (1 << (n + 1)) - 1;


                            b.set(i);
                            b.set(flip);
                            for (int j = n; j >= 0; j--)
                            {
                                if (1 & (i >> j))
                                    cout << 'P';
                                else
                                    cout << 'M';
                            }
                            cout << " | ";
                            for (int j = n; j >= 0; j--)
                            {
                                if (1 & (flip >> j))
                                    cout << 'P';
                                else
                                    cout << 'M';
                            }
                            cout << endl
                                 << endl;
                        }
                    }
                    cout << "共有" << count << "种。" << endl << endl;
                }
                cout << "请输入手性中心个数（输入0返回上一级菜单）：";
            }

        }
        else if (ch == 'q')
            return 0;
        cout << "请指定分子轴对称性（对称s，不对称a，输入q退出）" << endl;
    }
}
