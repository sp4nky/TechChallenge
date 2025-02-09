//
//  Employee.hpp
//  TechChallenge
//
//  Created by Jonathan Cabrera on 4/2/25.
//

#ifndef Employee_hpp
#define Employee_hpp

#include <stdio.h>

#include "SalaryData.hpp"
#include <string>
#include "Constants.h"

class Employee {
public:
    
    enum RoleE {
        CEO,
        HR,
        Artist,
        Design,
        Engineering,
        PM
    };
    
    enum SeniorityE {
        Junior,
        SemiSenior,
        Senior
    };
    
    virtual float GetSalary();
    SeniorityE GetSeniority();
    
    virtual ~Employee() {}
    Employee(std::string name, SeniorityE seniority, RoleE role);
    
protected:
    std::string _name;
    SeniorityE _seniority;
    RoleE _role;
    SalaryData _salaryData;
    
    virtual void SetSalaryData();

};

#endif /* Employee_hpp */
