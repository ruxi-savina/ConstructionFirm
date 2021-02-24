#include <iostream>
#include "Application.h"
#include "BagTest.h"

int main()
{
    Test test{};
    test.testAll();
    Bag bag{};
    Application app{bag};
    app.run();
    return 0;
}

