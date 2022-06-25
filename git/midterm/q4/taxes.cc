/*
Q4:
Bobby Bruin is trying to write a program to aclculate his taxes. The tax should be calculated by adding up all values in the `income` vector, and then subtracting all the values in the `expenses` vector, and then multilying the result by `tax_rate_`. He wrote the following code
*/

#include <vector>
#include <iostream>
// #include <functional>
#include <numeric> //accumulate

// //given TaxCalculator class:
// class TaxCalculator {
//     public:
//         float CalculateTax(std::vector<float> income, std::vector<float> expenses);
//     private:
//         float tax_rate_;
// };

//written TaxCalculator class:
class TaxCalculator {
    public:
        // //public attributes:
        // std::vector<float> income, expenses;

        // //non-parameterized constructor with defaults of zero:
        // TaxCalculator(){  
        //     income_ = {0};
        //     expenses_ = {0};
        // };

        // //parameterized constructor:
        // TaxCalculator(const std::vector<float>& income, const std::vector<float>& expenses){
        //     income_ = income;
        //     expenses_ = expenses;
        // }; 

        //method to calculate tax:
        float CalculateTax(const std::vector<float>& income, const std::vector<float>& expenses){
            float total_income = std::accumulate(income.begin(), income.end(), 0);
            float total_expenses = std::accumulate(expenses.begin(), expenses.end(), 0);
            return tax_rate_ * (total_income - total_expenses);

            //test const ... this won't work, unless we remove 'const' from parameter init in CalculateTax(): 
            //if we remove const and do this, then this will change the variable 'income' we input to this function.
            // for (int i=0; i<income.size(); i++){
            //     income[i] += 1000; //income must be a modifiable lvalue!
            // }

        };
        

    private:
        std::vector<float> income_;
        std::vector<float> expenses_;
        float tax_rate_ = 0.09;
};

int main() {
    std::vector<float> my_income = {10000, 20000, 10000};
    std::vector<float> my_expenses = {100, 200, 10, 100};

    TaxCalculator my_tax_calculator;

    auto my_tax = my_tax_calculator.CalculateTax(my_income, my_expenses);

    std::cout<<"my tax: "<<my_tax<<std::endl;
}