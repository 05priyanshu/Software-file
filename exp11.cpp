#include <iostream>
#include <unordered_set>
#include <typeinfo>
class Base
{
    // Your base class implementation goes here
};
class Derived1 : public Base
{
    // Your first derived class implementation goes here
};
class Derived2 : public Derived1
{
    // Your second derived class implementation goes here
};
// Utility class to calculate DIT
class DITCalculator
{
public:
    static int calculateDIT(std::unordered_set<const std::type_info *> &visitedTypes, const std::type_info &
                                                                                          type)
    {
        // Check if the type has already been visited to avoid infinite loops in case of cyclic dependencies
        if (visitedTypes.count(&type) > 0)
        {
            return 0;
        }
        // Add the current type to the set of visited types
        visitedTypes.insert(&type);
        // Get the base type (super class)
        const std::type_info *baseType = getBaseType(type);
        // Recursively calculate the DIT for the base type
        if (baseType != nullptr)
        {
            int baseTypeDepth = calculateDIT(visitedTypes, *baseType);
            return baseTypeDepth + 1;
        }
        return 0;
    }

private:
    // Utility function to get the base type (super class) of a given type
    static const std::type_info *getBaseType(const std::type_info &derivedType)
    {
        if (derivedType == typeid(Derived2))
        {
            return &typeid(Derived1);
        }
        else if (derivedType == typeid(Derived1))
        {
            return &typeid(Base);
        }
        return nullptr;
    }
};
int main()
{
    // Add your classes to the set
    std::unordered_set<const std::type_info *> types;
    types.insert(&typeid(Base));
    types.insert(&typeid(Derived1));
    types.insert(&typeid(Derived2));
    // Add other classes as needed
    // Calculate DIT for each class
    for (const auto &type : types)
    {
        std::unordered_set<const std::type_info *> visitedTypes;
        int dit = DITCalculator::calculateDIT(visitedTypes, *type);
        std::cout << "DIT for class " << type->name() << ": " << dit << std::endl;
    }
    return 0;
}
