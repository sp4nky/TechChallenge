//
//  EmployeeController.cpp
//  TechChallenge
//
//  Created by Jonathan Cabrera on 8/2/25.
//

#include "EmployeeController.hpp"
#include "Employee.hpp"
#include "EngineeringEmployee.hpp"
#include "HREmployee.hpp"
#include "CEOEmployee.hpp"
#include "ArtistEmployee.hpp"
#include "DesignEmployee.hpp"
#include "PMEmployee.hpp"
#include "Constants.h"
#include "EmployeeFactory.hpp"

#include <gtest/gtest.h>

EmployeeController::EmployeeController()
{
    LoadData();
}

void EmployeeController::LoadData()
{
    size_t hr_amount = HR_JUNIOR_AMOUNT + HR_SEMI_AMOUNT + HR_SENIOR_AMOUNT;
    for (int i = 0; i < hr_amount; i++)
    {
        if (i < HR_JUNIOR_AMOUNT)
        {
            _employees.push_back(std::make_unique<HREmployee>("HR JUNIOR " + std::to_string(i), Employee::SeniorityE::Junior));
            _juniors.push_back(std::make_unique<HREmployee>("HR JUNIOR " + std::to_string(i), Employee::SeniorityE::Junior));
        }
        else if (i < HR_SEMI_AMOUNT)
        {
            _employees.push_back(std::make_unique<HREmployee>("HR SEMI " + std::to_string(i), Employee::SeniorityE::SemiSenior));
            _semis.push_back(std::make_unique<HREmployee>("HR SEMI " + std::to_string(i), Employee::SeniorityE::SemiSenior));
        }
        else
        {
            _employees.push_back(std::make_unique<HREmployee>("HR SENIOR " + std::to_string(i), Employee::SeniorityE::Senior));
            _seniors.push_back(std::make_unique<HREmployee>("HR SEMI " + std::to_string(i), Employee::SeniorityE::SemiSenior));
        }
    }
    
    size_t engineering_amount =  ENGINEERING_JUNIOR_AMOUNT + ENGINEERING_SEMI_AMOUNT + ENGINEERING_SENIOR_AMOUNT;
    for (int i = 0; i < engineering_amount; i++)
    {
        if (i < ENGINEERING_JUNIOR_AMOUNT)
        {
            _employees.push_back(std::make_unique<EngineeringEmployee>("ENGINEERING JUNIOR " + std::to_string(i), Employee::SeniorityE::Junior));
            _juniors.push_back(std::make_unique<EngineeringEmployee>("ENGINEERING JUNIOR " + std::to_string(i), Employee::SeniorityE::Junior));
        }
        else if (i < ENGINEERING_SEMI_AMOUNT)
        {
            _employees.push_back(std::make_unique<EngineeringEmployee>("ENGINEERING SEMI " + std::to_string(i), Employee::SeniorityE::SemiSenior));
            _semis.push_back(std::make_unique<EngineeringEmployee>("ENGINEERING SEMI " + std::to_string(i), Employee::SeniorityE::SemiSenior));
        }
        else
        {
            _seniors.push_back(std::make_unique<EngineeringEmployee>("ENGINEERING SENIOR " + std::to_string(i), Employee::SeniorityE::Senior));
        }
    }
    
    size_t artist_amount = ARTIST_SEMI_AMOUNT + ARTIST_SENIOR_AMOUNT;
    for (int i = 0; i < artist_amount; i++)
    {
        if (i < ARTIST_SEMI_AMOUNT)
        {
            _employees.push_back(std::make_unique<ArtistEmployee>("ARTIST SEMI " + std::to_string(i), Employee::SeniorityE::SemiSenior));
            _semis.push_back(std::make_unique<ArtistEmployee>("ARTIST SEMI " + std::to_string(i), Employee::SeniorityE::SemiSenior));
        }
        else
        {
            _employees.push_back(std::make_unique<ArtistEmployee>("ARTIST SENIOR " + std::to_string(i), Employee::SeniorityE::Senior));
            _seniors.push_back(std::make_unique<ArtistEmployee>("ARTIST SENIOR " + std::to_string(i), Employee::SeniorityE::Senior));
        }
    }
    
    size_t design_amount = DESIGN_JUNIOR_AMOUNT + DESIGN_SENIOR_AMOUNT;
    for (int i = 0; i < design_amount; i++)
    {
        if (i < DESIGN_JUNIOR_AMOUNT)
        {
            _employees.push_back(std::make_unique<DesignEmployee>("DESIGN JUNIOR " + std::to_string(i), Employee::SeniorityE::Junior));
            _juniors.push_back(std::make_unique<DesignEmployee>("DESIGN JUNIOR " + std::to_string(i), Employee::SeniorityE::Junior));
        }
        else
        {
            _employees.push_back(std::make_unique<DesignEmployee>("DESIGN SENIOR " + std::to_string(i), Employee::SeniorityE::Senior));
            _seniors.push_back(std::make_unique<DesignEmployee>("DESIGN SENIOR " + std::to_string(i), Employee::SeniorityE::Senior));
        }
    }
    
    size_t pm_amount = PM_SEMI_AMOUNT + PM_SENIOR_AMOUNT;
    for (int i = 0; i < pm_amount; i++)
    {
        if (i < PM_SEMI_AMOUNT)
        {
            _employees.push_back(std::make_unique<PMEmployee>("PM SEMI " + std::to_string(i), Employee::SeniorityE::SemiSenior));
            _semis.push_back(std::make_unique<PMEmployee>("PM SEMI " + std::to_string(i), Employee::SeniorityE::SemiSenior));
        }
        else
        {
            _employees.push_back(std::make_unique<PMEmployee>("PM SENIOR " + std::to_string(i), Employee::SeniorityE::Senior));
            _seniors.push_back(std::make_unique<PMEmployee>("PM SENIOR " + std::to_string(i), Employee::SeniorityE::Senior));
        }
    }
    
    size_t CEO_amount = CEO_AMOUNT;
    for (int i = 0; i < CEO_amount; i++)
    {
        _employees.push_back(EmployeeFactory::GetInstance()->CreateNewEmployee("CEO " + std::to_string(i)));
        _seniors.push_back(EmployeeFactory::GetInstance()->CreateNewEmployee("CEO " + std::to_string(i)));
    }
}

int EmployeeController::StartTest(int argc, const char * argv[])
{
    ::testing::InitGoogleTest(&argc, const_cast<char**>(argv));
    return RUN_ALL_TESTS();
}

TEST(EmployeeTests, HRSeniorSalaryCalculation) {
    auto emp = EmployeeFactory::GetInstance()->CreateNewEmployee("Lucia SR", Employee::SeniorityE::Senior, Employee::RoleE::HR);
    EXPECT_FLOAT_EQ(emp->GetSalary(), 1500 * 1.05);
}

TEST(EmployeeTests, HRSemiSalaryCalculation) {
    auto emp = EmployeeFactory::GetInstance()->CreateNewEmployee("Lucia SEMI", Employee::SeniorityE::SemiSenior, Employee::RoleE::HR);
    EXPECT_FLOAT_EQ(emp->GetSalary(), 1000 * 1.02);
}

TEST(EmployeeTests, HRJuniorSalaryCalculation) {
    auto emp = EmployeeFactory::GetInstance()->CreateNewEmployee("Lucia JR", Employee::SeniorityE::Junior, Employee::RoleE::HR);
    EXPECT_FLOAT_EQ(emp->GetSalary(), 500 * 1.005);
}

TEST(EmployeeTests, EngineeringSeniorSalaryCalculation) {
    auto emp = EmployeeFactory::GetInstance()->CreateNewEmployee("Guillermo SR", Employee::SeniorityE::Senior, Employee::RoleE::Engineering);
    EXPECT_FLOAT_EQ(emp->GetSalary(), 5000 * 1.10);
}

TEST(EmployeeTests, EngineeringSemiSalaryCalculation) {
    auto emp = EmployeeFactory::GetInstance()->CreateNewEmployee("Guillermo SEMI", Employee::SeniorityE::SemiSenior, Employee::RoleE::Engineering);
    EXPECT_FLOAT_EQ(emp->GetSalary(), 3000 * 1.07);
}

TEST(EmployeeTests, EngineeringJuniorSalaryCalculation) {
    auto emp = EmployeeFactory::GetInstance()->CreateNewEmployee("Guillermo JR", Employee::SeniorityE::Junior, Employee::RoleE::Engineering);
    EXPECT_FLOAT_EQ(emp->GetSalary(), 1500 * 1.05);
}

TEST(EmployeeTests, ArtistSeniorSalaryCalculation) {
    auto emp = EmployeeFactory::GetInstance()->CreateNewEmployee("Diego SR", Employee::SeniorityE::Senior, Employee::RoleE::Artist);
    EXPECT_FLOAT_EQ(emp->GetSalary(), 2000 * 1.05);
}

TEST(EmployeeTests, ArtistSemiSalaryCalculation) {
    auto emp = EmployeeFactory::GetInstance()->CreateNewEmployee("Diego SEMI", Employee::SeniorityE::SemiSenior, Employee::RoleE::Artist);
    EXPECT_FLOAT_EQ(emp->GetSalary(), 1200 * 1.025);
}

TEST(EmployeeTests, DesignSeniorSalaryCalculation) {
    auto emp = EmployeeFactory::GetInstance()->CreateNewEmployee("Christian SR", Employee::SeniorityE::Senior, Employee::RoleE::Design);
    EXPECT_FLOAT_EQ(emp->GetSalary(), 2000 * 1.07);
}

TEST(EmployeeTests, DesignJuniorSalaryCalculation) {
    auto emp = EmployeeFactory::GetInstance()->CreateNewEmployee("Christian JR", Employee::SeniorityE::Junior, Employee::RoleE::Design);
    EXPECT_FLOAT_EQ(emp->GetSalary(), 800 * 1.04);
}

TEST(EmployeeTests, PMSeniorSalaryCalculation) {
    auto emp = EmployeeFactory::GetInstance()->CreateNewEmployee("Juan SR", Employee::SeniorityE::Senior, Employee::RoleE::PM);
    EXPECT_FLOAT_EQ(emp->GetSalary(), 4000 * 1.10);
}

TEST(EmployeeTests, PMJuniorSalaryCalculation) {
    auto emp = EmployeeFactory::GetInstance()->CreateNewEmployee("Juan SEMI", Employee::SeniorityE::SemiSenior, Employee::RoleE::PM);
    EXPECT_FLOAT_EQ(emp->GetSalary(), 2400 * 1.05);
}

TEST(EmployeeTests, CEOSalaryCalculation) {
    auto emp = EmployeeFactory::GetInstance()->CreateNewEmployee("Jorge", Employee::SeniorityE::Senior, Employee::RoleE::CEO);
    EXPECT_FLOAT_EQ(emp->GetSalary(), 20000 * 2);
}
