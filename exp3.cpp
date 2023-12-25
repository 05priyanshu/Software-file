#include <iostream>
#include <math.h>
class COCOMOII
{
public:
    // Function to estimate effort in Person-Months
    double estimateEffort(double size, int mode)
    {
        // Basic formula: Effort = A * (Size ^ B) * EAF
        double A = 2.94;                 // Example value, would be calibrated based on the project
        double B = 1.067;                // Example value, would be calibrated based on the project
        double EAF = calculateEAF(mode); // Environmental Adjustment Factor
        double effort = A * pow(size, B) * EAF;
        return effort;
    }

private:
    // Function to calculate the Environmental Adjustment Factor (EAF)
    double calculateEAF(int mode)
    {
        // EAF is based on various factors such as personnel capability, process maturity, etc.
        // This is a simplified example, in reality, you would need to consider more factors.
        double eaf = 1.0;
        // Adjust based on the development mode
        switch (mode)
        {
        case 1: // Organic
            eaf *= 1.0;
            break;
        case 2: // Semi-Detached
            eaf *= 1.2;
            break;
        case 3: // Embedded
            eaf *= 1.5;
            break;
        default:
            std::cerr << "Invalid mode." << std::endl;
            break;
        }
        return eaf;
    }
};
int main()
{
    COCOMOII cocomo;
    double projectSize;
    int developmentMode;
    std::cout << "Enter project size (KLOC): ";
    std::cin >> projectSize;
    std::cout << "Select development mode (1 for Organic, 2 for Semi-Detached, 3 for Embedded): ";
    std::cin >> developmentMode;
    double effort = cocomo.estimateEffort(projectSize, developmentMode);
    std::cout << "Estimated effort: " << effort << " Person-Months" << std::endl;
    return 0;
}