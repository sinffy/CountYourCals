#include <iostream>
#include <string>
#include <vector>

double CalculateCalories()
{
    std::cout << "Specify your gender > [1 - male] [2 - female] " << std::flush;
    int gender;
    std::cin >> gender;

    std::cout << "Specify your weight > " << std::flush;
    double weight;
    std::cin >> weight;

    std::cout << "Specify your height > " << std::flush;
    double height;
    std::cin >> height;

    std::cout << "Specify your age > " << std::flush;
    int age;
    std::cin >> age;

    std::cout << "Degree of physical activity > \n[0 - sedentary work, lack of physical activity]\n[1 - 1-3 times per week]\n"
        "[2 - 3-4 times per week]\n[3 - 5-6 times per week]\n[4 - 6-7 times per week]" << std::endl;
    int activity;
    std::cin >> activity;

    double result = 0.;
    if (gender == 1)
        result = 66.5 + 13.75 * weight + 5.003 * height - 6.775 * (double)age;
    else if (gender == 2)
        result = 655.1 + 9.563 * weight + 1.85 * height - 4.676 * (double)age;
    else
        std::cout << "You enetered invalid gender.";

    double physActiv[5] = { 1.2, 1.375, 1.55, 1.7, 1.9 };

    return result * physActiv[activity];
}

struct Meals
{
    std::string Name;
    double Cals;
};

double AddMeal(std::vector<Meals>& eaten)
{
    std::cout << "Enter meal > " << std::flush;
    std::string meal;
    std::cin >> meal;

    std::cout << "Enter number of calories per 100g > " << std::flush;
    double baseNumCal;
    std::cin >> baseNumCal;

    std::cout << "Enter serving weight > " << std::flush;
    double servingWeight;
    std::cin >> servingWeight;

    double result = baseNumCal * (servingWeight/100);
    eaten.push_back({ meal, result });

    return result;
}

int main()
{
    double result = 0.;
    double eatenCal = 0.;
    std::vector<Meals> eaten;

    while (true)
    {
        std::cout << "Menu:\n\n";
        std::cout << "1. Calculate the requiered number of calories.\n";
        std::cout << "2. Add a new meal.\n";
        std::cout << "3. Print the number of calories eaten.\n";
        std::cout << "4. Exit.\n";

        std::cout << "Enter number > " << std::flush;
        int menuNum;
        std::cin >> menuNum;


        switch (menuNum)
        {
        case 1:
            std::cout << "Your daily number of calories: " << (result = CalculateCalories()) << std::endl;
            break;
        case 2:
            std::cout << "This meal contains " << (eatenCal += AddMeal(eaten)) << " calories.\n";

            if (result <= 0.2)
            {
                std::cout << "You have not calculated the daily calorie allowance.\n";
            }
            else
                std::cout << "Calories left: " << result - eatenCal << std::endl;

            if (result - eatenCal <= 0.1)
                std::cout << "STOP EATING! YOU HAVE NO CALORIES LEFT YOU FAT COCKSUCKER! >=(\n";
            break;
        case 3:
            std::cout << "Today you have eaten >\n";

            for (auto& item : eaten)
            {
                std::cout << item.Name << ": " << item.Cals << std::endl;
            }
            break;
        case 4:
            exit(0);
        default:
            break;
        }
    }
}
