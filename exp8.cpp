#include <iostream>
#include <vector>
#include <set>
using namespace std;
class ClassInfo;
class MethodInfo
{
public:
    string methodName;
    set<string> calledMethods;
};
class ClassInfo
{
public:
    string className;
    vector<MethodInfo> methods;
};
int calculateRFC(const ClassInfo &classInfo)
{
    set<string> uniqueMethods;
    for (const auto &method : classInfo.methods)
    {
        uniqueMethods.insert(method.methodName);
        for (const auto &calledMethod : method.calledMethods)
        {
            uniqueMethods.insert(calledMethod);
        }
    }
    return static_cast<int>(uniqueMethods.size());
}
int main()
{
    ClassInfo myClass;
    myClass.className = "MyClass";
    MethodInfo method1;
    method1.methodName = "method1";
    method1.calledMethods.insert("method2");
    method1.calledMethods.insert("method3");
    MethodInfo method2;
    method2.methodName = "method2";
    method2.calledMethods.insert("method1");
    MethodInfo method3;
    method3.methodName = "method3";
    myClass.methods.push_back(method1);
    myClass.methods.push_back(method2);
    myClass.methods.push_back(method3);
    int rfc = calculateRFC(myClass);
    cout << "RFC for " << myClass.className << ": " << rfc << endl;
    return 0;
}