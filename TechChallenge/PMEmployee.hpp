//
//  PMEmployee.hpp
//  TechChallenge
//
//  Created by Jonathan Cabrera on 8/2/25.
//

#ifndef PMEmployee_hpp
#define PMEmployee_hpp

#include <stdio.h>

#include "Employee.hpp"

class PMEmployee : public Employee
{
public:
    PMEmployee(std::string name, SeniorityE level, RoleE = RoleE::PM);
    
    float GetSalary() override;

private:
    virtual void SetSalaryData() override;
};

#endif /* PMEmployee_hpp */
