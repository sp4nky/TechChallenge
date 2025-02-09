//
//  EmployeeController.hpp
//  TechChallenge
//
//  Created by Jonathan Cabrera on 8/2/25.
//

#ifndef EmployeeController_hpp
#define EmployeeController_hpp

#include <stdio.h>
#include <list>

#include "Employee.hpp"
#include <gtest/gtest.h>

class EmployeeController
{
public:
    EmployeeController();
    ~EmployeeController(){}

    int StartTest(int argc, const char * argv[]);
private:
    std::vector<std::unique_ptr<Employee>> _employees;

    std::vector<std::unique_ptr<Employee>> _seniors;
    std::vector<std::unique_ptr<Employee>> _semis;
    std::vector<std::unique_ptr<Employee>> _juniors;
    
    void LoadData();
    
    std::vector<std::unique_ptr<Employee>> GetSneiorityVector(const std::vector<std::unique_ptr<Employee>>& employees, Employee::SeniorityE seniority);
};

#endif /* EmployeeController_hpp */
