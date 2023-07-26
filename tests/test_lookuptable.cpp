#include <gtest/gtest.h>
#include "../code/lookuptable.h"

#include <fstream>
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class test_LookupTable : public ::testing::Test {
protected:
	// This function runs only once before any TEST_F function
	static void SetUpTestCase(){
		std::ofstream outgrade("./total_grade.txt");
		if(outgrade.is_open()){
			outgrade.clear();
			outgrade << (int)0;
			outgrade.close();
		}
	}

	// This function runs after all TEST_F functions have been executed
	static void TearDownTestCase(){
		std::ofstream outgrade("./total_grade.txt");
		if(outgrade.is_open()){
    		outgrade.clear();
		    outgrade << (int)std::ceil(100*total_grade/max_grade);
		    outgrade.close();

		    std::cout << "Total Grade is : " << (int)std::ceil(100*total_grade/max_grade) << std::endl;
        }
	}

	void add_points_to_grade(int points){
		if(!::testing::Test::HasFailure()){
			total_grade += points;
		}
	}

	// this function runs before every TEST_F function
	void SetUp() override {}

	// this function runs after ever TEST_F function
	void TearDown() override {
		std::ofstream outgrade("./total_grade.txt");
		if(outgrade.is_open()){
			outgrade.clear();
			outgrade << (int)std::ceil(100*total_grade/max_grade);
			outgrade.close();
		}
	}
	
	static int total_grade;
	static int max_grade;
};

int test_LookupTable::total_grade = 0;
int test_LookupTable::max_grade = 20;

// Test cases

TEST_F(test_LookupTable, TestToBinary) {
  LookupTable lt;
  string ret = lt.to_string_bin("01001001 00100000 01100001 01101101 00100000 01100001 00100000 01110100 01100101 01110011 01110100 00101110");
	cout << ret << endl;
  EXPECT_EQ(ret, "I am a test.");
  add_points_to_grade(5);
}

TEST_F(test_LookupTable, TestToDecimal) {
  LookupTable lt;
  string ret = lt.to_string_dec("73 32 97 109 32 97 32 116 101 115 116 46");
	
  EXPECT_EQ(ret, "I am a test.");
  add_points_to_grade(5);
}

TEST_F(test_LookupTable, TestToHex) {

  LookupTable lt;
  string ret = lt.to_string_hex("49 20 61 6D 20 61 20 74 65 73 74 2E");
	
  EXPECT_EQ(ret, "I am a test.");
  add_points_to_grade(5);
}

TEST_F(test_LookupTable, TestToString) {
		
  LookupTable lt;
  string ret1 = lt.to_not_string("I am a test.", "binary");
  EXPECT_EQ(ret1, "01001001 00100000 01100001 01101101 00100000 01100001 00100000 01110100 01100101 01110011 01110100 00101110 ");
  add_points_to_grade(2);

  string ret2 = lt.to_not_string("I am a test.", "decimal");
  EXPECT_EQ(ret2, "73 32 97 109 32 97 32 116 101 115 116 46 ");
  add_points_to_grade(2);

  string ret3 = lt.to_not_string("I am a test.", "hex");
  EXPECT_EQ(ret3, "49 20 61 6D 20 61 20 74 65 73 74 2E ");
  add_points_to_grade(1);
}
