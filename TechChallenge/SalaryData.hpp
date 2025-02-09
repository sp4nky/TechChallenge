//
//  SalaryData.hpp
//  TechChallenge
//
//  Created by Jonathan Cabrera on 4/2/25.
//

#ifndef SalaryData_hpp
#define SalaryData_hpp

#include <stdio.h>

class SalaryData{
public:
    float baseSalary;
    float incrementPercentage;

    SalaryData(float salary, float increment);
};

#endif /* SalaryData_hpp */
