#include "gtest/gtest.h"

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

