#include <iostream>
#include <vector>
#include <set>
using namespace std;
class MyClass
{
private:
    int variable1;
    float variable2;
    char variable3;

public:
    void method1()
    {
        variable1 = 10;
    }
    void method2()
    {
        variable2 = 3.14f;
    }
    void method3()
    {
        variable3 = 'A';
    }
    int getVariable1() const
    {
        return variable1;
    }
    float getVariable2() const
    {
        return variable2;
    }
    char getVariable3() const
    {
        return variable3;
    }
    int calculateLCOM() const
    {
        vector<set<string>> methodSets;
        for (const auto &method : {"method1", "method2", "method3"})
        {
            set<string> methodSet;
            methodSet.insert(method);
            methodSets.push_back(methodSet);
        }
        if (variable1 == 10)
        {
            methodSets[0].insert("method2");
            methodSets[0].insert("method3");
        }
        if (variable2 == 3.14f)
        {
            methodSets[1].insert("method1");
            methodSets[1].insert("method3");
        }
        if (variable3 == 'A')
        {
            methodSets[2].insert("method1");
            methodSets[2].insert("method2");
        }
        int disjointSets = 0;
        for (const auto &set : methodSets)
        {
            if (!set.empty())
            {
                disjointSets++;
            }
        }
        int lcom = methodSets.size() - disjointSets;
        return lcom;
    }
};
int main()
{
    MyClass myObject;
    int lcomValue = myObject.calculateLCOM();
    cout << "LCOM metric: " << lcomValue << std::endl;
    return 0;
}