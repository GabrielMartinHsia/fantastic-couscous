# Q4

Bobby Bruin is trying to write a program to calculate his taxes. The tax should be calculated by adding up all values in the `income` vector, then subtract all values in the `expenses` vector, and then multiply the result `by tax_rate_`. 

## Q4.1
There is a problem in the declaration (signature) of `CalculateTax` which can make it very slow. Can you fix it for him? Please explain your solution.

Oh. Duh. Pass by reference to avoid copying the whole damn vector for income and expenses.

## Q4.2
See `taxes.cc`:
```cpp
//method to calculate tax:
        float CalculateTax(const std::vector<float>& income, const std::vector<float>& expenses){
            float total_income = std::accumulate(income.begin(), income.end(), 0);
            float total_expenses = std::accumulate(expenses.begin(), expenses.end(), 0);
            float total_tax =  tax_rate_ * (total_income - total_expenses);
        };
```

## Q4.3:

Worst-case runtime complexity of the CalculateTax() method:

* std::accumulate(income): $O(n)$ as we must traverse the entirety of the vector and sum each element.
* std::accumulate(income): same as above, which puts as at $O(2n)$
* (total_income - total_expenses): $O(1)$
* tax_rate_ * (income - expenses): $O(1)$

So all together, we have $O(2 + 2n) \approx O(n)$

