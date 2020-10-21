
#include <Eigen/Dense>


class FooClass
{
    Eigen::Vector4d v;

  public:
    void setVector(const Eigen::Ref<const Eigen::Vector4d>& v);

    void printDouble(double v);
};
