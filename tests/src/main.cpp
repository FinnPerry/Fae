#include <fae/fae.hpp>

#include <cppunit/cppunit.h>

namespace
{

class tests : public Cppunit
{
    virtual void test_list() override
    {
    }
};

}

int main()
{
    return tests{}.run();
}
