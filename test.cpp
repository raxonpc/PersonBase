#include "gtest/gtest.h"
#include <fstream>

extern "C" {
#include "Person.h"
}

TEST(countryTests, ShouldConvertToCountry)
{
  EXPECT_EQ(COUNTRY_DENMARK, strToCountry("Denmark"));
  EXPECT_EQ(COUNTRY_DOMINICAN_REPUBLIC, strToCountry("Dominican Republic"));
  EXPECT_EQ(COUNTRY_FINLAND, strToCountry("Finland"));
  EXPECT_EQ(COUNTRY_GERMANY, strToCountry("Germany"));
  EXPECT_EQ(COUNTRY_POLAND, strToCountry("Poland")); 
  EXPECT_EQ(COUNTRY_SWEDEN, strToCountry("Sweden"));

  EXPECT_EQ(COUNTRY_UNDEFINED, strToCountry("BULBULATORAIFTGJEQAGWAEGHUIWAHGUIW"));
  EXPECT_EQ(COUNTRY_UNDEFINED, strToCountry("GJIWGUHUWWGHNUIJHIU"));
}

TEST(countryTests, ShouldConvertToStr)
{
  EXPECT_FALSE(strcmp("Denmark", countryToStr(COUNTRY_DENMARK)));
  EXPECT_FALSE(strcmp("Dominican Republic", countryToStr(COUNTRY_DOMINICAN_REPUBLIC)));
  EXPECT_FALSE(strcmp("Finland", countryToStr(COUNTRY_FINLAND)));
  EXPECT_FALSE(strcmp("Germany", countryToStr(COUNTRY_GERMANY)));
  EXPECT_FALSE(strcmp("Poland", countryToStr(COUNTRY_POLAND)));
  EXPECT_FALSE(strcmp("Sweden", countryToStr(COUNTRY_SWEDEN)));
  EXPECT_FALSE(strcmp("Undefined", countryToStr(COUNTRY_UNDEFINED)));
  EXPECT_FALSE(strcmp("Undefined", countryToStr(static_cast<Country>(-1))));
}

TEST(personTests, ShouldCheckValidity)
{
  Person person = {"Angela", "Merkel", COUNTRY_GERMANY};
  Person invalidPerson = {"John", nullptr, COUNTRY_UNDEFINED};
  EXPECT_FALSE(isPersonValid(&invalidPerson));
  EXPECT_TRUE(isPersonValid(&person));
}

TEST(personTests, ShouldWriteListToFile)
{
  Person last = { "Linus", "Torvalds", COUNTRY_FINLAND, nullptr };
  Person head = { "Angela", "Merkel", COUNTRY_GERMANY, &last };

  FILE *file = fopen("test.txt", "w");
  readPersonList(&head, file);
  fclose(file);
  std::ifstream iStr{ "test.txt" };
  std::string line1{ "Angela,Merkel,Germany" };
  std::string line2{ "Linus,Torvalds,Finland" };
  std::string temp{};
  iStr >> temp;
  EXPECT_EQ(temp, line1);
  iStr >> temp;
  EXPECT_EQ(temp, line2);
  iStr.close();
}

TEST(personTests, ShouldReadFromFile)
{
  std::string line1{ "Angela,Merkel,Germany" };
  std::string line2{ "Linus,Torvalds,Finland" };
  std::ofstream oStr{ "test1.txt" };
  oStr << line1 << '\n' << line2;
  oStr.close();

  FILE *file = fopen("test1.txt", "r");
  Person *head = readPersonListFromFile(file);

  Person headTest = { "Angela", "Merkel", COUNTRY_GERMANY };
  Person lastTest = { "Linus", "Torvalds", COUNTRY_FINLAND };

  EXPECT_FALSE(strcmp(head->name, headTest.name));
  EXPECT_FALSE(strcmp(head->surname, headTest.surname));
  EXPECT_EQ(head->country, headTest.country);

  EXPECT_FALSE(strcmp(head->next->name, lastTest.name));
  EXPECT_FALSE(strcmp(head->next->surname, lastTest.surname));
  EXPECT_EQ(head->next->country, lastTest.country);
}
