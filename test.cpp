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
