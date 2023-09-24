#include <iostream>
#include <string>
class solution
{
public:
    std::string a;
    std::string pigLatinReturn()
    {
        std::cout << "enter a word" << std::endl;
        std::cin >> a;
        int length = a.length();
        for (int i = 0; i < length; ++i)
        {
            if (IsVowel(a[0]))
            {
                a = a + "ay";
                return a;
            }
            else
            {
                a = a.substr(1) + a[0];
            }
        }
        return a;
    };

private:
    bool IsVowel(char b)
    {
        return b == 'a' || b == 'e' || b == 'i' || b == 'o' || b == 'u';
    }
};

int main()
{
    solution Solution;
    std::cout << Solution.pigLatinReturn();
}
