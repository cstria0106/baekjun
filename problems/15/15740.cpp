#include <iostream>
#include <string>
#include <vector>

std::string plus(std::string a, std::string b)
{
    a = std::string(10002 - a.length(), '0') + a;
    b = std::string(10002 - b.length(), '0') + b;

    int zero = 10001;

    std::string ret = std::string(10002, '0');
    for (int i = 10001; i >= 1; i--)
    {
        ret[i] += (a[i] + b[i] - '0' * 2);  
        if(ret[i] - '0' >= 10) {
            ret[i] -= 10;
            ret[i - 1] = '1';
        }

        if(ret[i] != '0') zero = i;
    }

    return ret.substr(zero);
}

std::string minus(std::string a, std::string b)
{
    bool b_is_bigger = false;
    if(a.length() < b.length() || (a.length() == b.length() && a < b))
    {
        b_is_bigger = true;
        std::string temp = a;
        a = b;
        b = temp;
    }

    a = std::string(10002 - a.length(), '0') + a;
    b = std::string(10002 - b.length(), '0') + b;

    int zero = 10001;

    std::string ret = std::string(10002, '0');
    for (int i = 10001; i >= 1; i--)
    {
        ret[i] += (a[i] - b[i]);  
        if(ret[i] - '0' < 0) {
            ret[i] += 10;
            ret[i - 1] = '0' - 1;
        }

        if(ret[i] != '0') zero = i;
    }

    if(b_is_bigger)
    {
        return "-" + ret.substr(zero);
    }
    return ret.substr(zero);
}

int main()
{
    std::string a, b;
    std::cin >> a >> b;

    std::string result;
    if (a[0] == '-' && b[0] != '-')
    {
        // 왼쪽만 음수일 때
        result = minus(b, a.substr(1));
    }
    else if (a[0] != '-' && b[0] == '-')
    {
        // 오른쪽만 음수일 때
        result = minus(a, b.substr(1));
    }
    else if (a[0] == '-' && b[0] == '-')
    {
        // 둘 다 음수일 때
        result = "-" + plus(a.substr(1), b.substr(1));
    }
    else
    {
        // 둘 다 양수일 때
        result = plus(a, b);
    }

    std::cout << result << std::endl;
}