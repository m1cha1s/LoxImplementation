#include <main.h>

int main()
{

    Lox::Scanner s("{}");

    int err = s.scanTokens();

    if (err)
    {
        std::cout << s.getError() << std::endl;
    }

    return 0;
}