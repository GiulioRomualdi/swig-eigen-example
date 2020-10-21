#include <foo.h>
#include <iostream>

void FooClass::setVector(const Eigen::Ref<const Eigen::Vector4d>& v)
{
    this->v = v;
    std::cout << this->v << std::endl;
}

void FooClass::printDouble(double v)
{
    std::cerr << "hello! The number is equal to "  << v << std::endl;
}
