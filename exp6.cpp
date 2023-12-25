#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
class ClassA
{
public:
    void methodA()
    {
        cout << "Method A in ClassA\n";
    }
};
class ClassB
{
public:
    void methodB(ClassA &objA)
    {
        objA.methodA();
        cout << "Method B in ClassB\n";
    }
};
 int calculateCBO(const std::vector<std::unordered_set<std::string>> &dependencies)
{
    int cbo = 0;
    for (const auto &set : dependencies)
    {
        cbo += set.size();
    }
    return cbo;
}
int main()
{
    vector<std::unordered_set<std::string>> dependencies;
    unordered_set<std::string> dependencySet;
    dependencySet.insert("ClassA");
    dependencies.push_back(dependencySet);
    int cbo = calculateCBO(dependencies);
    cout << "Coupling Between Objects (CBO): " << cbo << endl;
    return 0;
}