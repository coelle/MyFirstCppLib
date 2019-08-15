#define BOOST_TEST_MAIN

#include <boost/test/included/unit_test.hpp>
#include "library.h"

BOOST_AUTO_TEST_SUITE(einfacher_stringtest)

    BOOST_AUTO_TEST_CASE(addition) {
        Summierer sut;
        std::string result = sut.addition(2, 3);
        BOOST_CHECK(result == "Das ergibt 5");
    }

BOOST_AUTO_TEST_SUITE_END()