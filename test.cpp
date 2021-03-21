#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE figures

#include "../src/Figures/Trapeze.h"
#include "../src/Figures/Rhombus.h"
#include "../src/Figures/Pentagon.h"
#include "../src/Processors/ConsoleProcessor.h"
#include "../src/Processors/FileProcessor.h"
#include <sstream>
#include <memory>
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(figures)

BOOST_AUTO_TEST_CASE(trapeze) {
    {
        Point p1 = {0,0}, p2 = {1, 2}, p3 = {4, 5}, p4 = {10,0};
        BOOST_CHECK_THROW(Trapeze(p1,p2,p3,p4), std::logic_error);
    }
    {
        Point p1 = {0,0}, p2 = {0, 4}, p3 = {4, 4}, p4 = {10,0};
        BOOST_CHECK_NO_THROW(Trapeze(p1,p2,p3,p4));
    }
    {
        Point p1 = {0,0}, p2 = {0, 0}, p3 = {0, 0}, p4 = {0,0};
        BOOST_CHECK_NO_THROW(Trapeze(p1,p2,p3,p4));
    }
}

BOOST_AUTO_TEST_CASE(rhombus) {
    {
        Point p1 = {0,0}, p2 = {1, 2}, p3 = {4, 5}, p4 = {10,0};
        BOOST_CHECK_THROW(Rhombus(p1,p2,p3,p4), std::logic_error);
    }
    {
        Point p1 = {0,0}, p2 = {3, 4}, p3 = {8, 4}, p4 = {5,0};
        BOOST_CHECK_NO_THROW(Rhombus(p1,p2,p3,p4));
    }
    {
        Point p1 = {0,0}, p2 = {0, 0}, p3 = {0, 0}, p4 = {0,0};
        BOOST_CHECK_NO_THROW(Rhombus(p1,p2,p3,p4));
    }
}

BOOST_AUTO_TEST_CASE(pentagon) {
    {
        Point p1 = {0,0}, p2 = {1, 2}, p3 = {4, 5}, p4 = {10,0}, p5 = {-5, -5};
        BOOST_CHECK_NO_THROW(Pentagon(p1,p2,p3,p4,p5));
    }
}

BOOST_AUTO_TEST_CASE(console_processor) {
    std::stringstream buffer;
    std::streambuf * old = std::cout.rdbuf(buffer.rdbuf());
    std::vector<std::shared_ptr<Figure>> v;
    v.push_back(std::make_shared<Pentagon>(Point{1,2},Point{3,4},Point{5,6},Point{7,8},Point{9,10}));
    v.push_back(std::make_shared<Rhombus>(Point{0,0}, Point{3, 4}, Point{8, 4}, Point{5,0}));
    v.push_back(std::make_shared<Trapeze>(Point{0,0}, Point{0, 4}, Point{4, 4}, Point{6,0}));
    ConsoleProcessor proc;
    proc.Process(v);
    std::string output = "Pentagon, p1: 1 2, p2: 3 4, p3: 5 6, p4: 7 8, p5: 9 10\n"
                         "Rhombus, p1: 0 0, p2: 3 4, p3: 8 4, p4: 5 0\n"
                         "Trapeze, p1: 0 0, p2: 4 4, p3: 0 4, p4: 6 0\n";
    BOOST_CHECK_EQUAL(output, buffer.str());
    std::cout.rdbuf(old);
}

BOOST_AUTO_TEST_SUITE_END()