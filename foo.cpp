#include <foo.h>
#include <iostream>

void FooClass::setVectorConstRef(const Eigen::Ref<const Eigen::Vector4d>& v)
{
    this->v = v;
    std::cout << "Method with const ref "<< this->v << std::endl;
}

void FooClass::setVectorCopy(Eigen::Ref<const Eigen::Vector4d> v)
{
    this->v = v;
    std::cout << "Method with copy "<< this->v << std::endl;
}

void FooClass::printDouble(double v)
{
    std::cerr << "hello! The number is equal to "  << v << std::endl;
}
