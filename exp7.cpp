#include <iostream>
#include <vector>
#include <string>
using namespace std;
class MyClass
{
public:
    void method1()
    {
        complexity += 10;
    }
    void method2()
    {
        complexity += 16;
    }
    int calculateWMC()
    {
        complexity = 0;
        method1();
        method2();
        return complexity;
    }

private:
    int complexity = 0;
};
int main()
{
    MyClass myObject;
    int wmc = myObject.calculateWMC();
    cout << "Weighted Methods per Class (WMC): " << wmc << endl;
    return 0;
}