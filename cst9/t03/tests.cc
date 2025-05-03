#include <gtest/gtest.h>
#include <iostream>
#include <string.h>
#include <iomanip>
#include <fstream>
#include <filesystem>


void func(std::istream& cin, std::ostream& cout);

TEST(CONTEST, TASK) {
	for (const auto& file : std::filesystem::directory_iterator("./tst")) {
		std::ifstream cin;
		std::ostringstream cout;
		cin.open(file.path().string());
		func(cin, cout);
		ASSERT_EQ("NO\nYES\nNO\nYES\nYES\nNO\n", cout.str());
	}
}

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
