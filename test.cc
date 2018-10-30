using namespace std;
#include <iostream>
#include <stdlib.h>


class test
{
    protected:
        int m;
public:
    test();
    ~test();
};

test::test()
{
    m=7;
}


class bonjour :  test
{
private:
    /* data */
public:
    bonjour(/* args */);
    ~bonjour();
};

bonjour::bonjour(/* args */)
{
}

bonjour::~bonjour()
{
}


