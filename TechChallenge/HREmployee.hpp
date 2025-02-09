//
//  HREmployee.hpp
//  TechChallenge
//
//  Created by Jonathan Cabrera on 7/2/25.
//

#ifndef HREmployee_hpp
#define HREmployee_hpp

#include <stdio.h>

#include "Employee.hpp"

class HREmployee : public Employee
{
public:
    HREmployee(std::string name, SeniorityE level, RoleE = RoleE::Artist);
    
    float GetSalary() override;

private:
    virtual void SetSalaryData() override;
};

#endif /* HREmployee_hpp */
