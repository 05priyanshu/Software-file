#include <iostream>
#include <vector>
class BaseClass
{
public:
    // Base class methods and members
};
class ChildClass1 : public BaseClass
{
public:
    // Child class 1 methods and members
};
class ChildClass2 : public BaseClass
{
public:
    // Child class 2 methods and members
};
class ChildClass3 : public BaseClass
{
public:
    // Child class 3 methods and members
};
// Calculate NOC metric
int calculateNOC(const std::vector<BaseClass *> &classes)
{
    return classes.size();
}
int main()
{
    // Create instances of child classes
    ChildClass1 child1;
    ChildClass2 child2;
    ChildClass3 child3;
    // Store pointers to base class objects in a vector
    std::vector<BaseClass *> classVector = {&child1, &child2, &child3};
    // Calculate and display NOC metric
    int nocValue = calculateNOC(classVector);
    std::cout << "NOC metric: " << nocValue << std::endl;
    return 0;
}