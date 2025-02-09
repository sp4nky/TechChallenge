//
//  CEOEmployee.hpp
//  TechChallenge
//
//  Created by Jonathan Cabrera on 7/2/25.
//

#ifndef CEOEmployee_hpp
#define CEOEmployee_hpp

#include <stdio.h>

#include "Employee.hpp"

class CEOEmployee : public Employee
{
public:
    CEOEmployee(std::string name, Employee::SeniorityE = Employee::SeniorityE::Senior, Employee::RoleE = Employee::RoleE::CEO);
    
    float GetSalary() override;
    
private:
    virtual void SetSalaryData() override;

};

#endif /* CEOEmployee_hpp */
