#include <fae/fae.hpp>

#include <cppunit/cppunit.h>

namespace
{
    
class unit_tests : public Cppunit
{
    virtual void test_list() override
    {
        test_0();
        test_1();
        test_2();
    }
    
    void test_0()
    {
        CHECKT(true);
    }

    void test_1()
    {
        CHECK(1 + 1, 2);
    }

    void test_2()
    {
        CHECKS("a", "a");
    }
};
    
}

int main()
{
    return unit_tests{}.run();
}
