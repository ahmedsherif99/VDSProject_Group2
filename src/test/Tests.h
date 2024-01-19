//
// Created by tobias on 21.11.16.
//

#ifndef VDSPROJECT_TESTS_H
#define VDSPROJECT_TESTS_H

#include <gtest/gtest.h>
#include "../Manager.h"

#endif

class Manager_test : public ClassProject::Manager, public ::testing::Test {
protected:
    void SetUp() override {
        test_var = new Manager;
    }

    void TearDown() override {
        delete test_var;
    }

    Manager *test_var;
};