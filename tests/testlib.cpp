#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <SingleLinkedList.hpp>

using namespace std;

TEST_CASE( "Quick check", "[main]" ) {
    nxstl::SingleLinkedList<int> lst;

    lst.append(2);
    cout << lst;

    REQUIRE(1 == lst.size());
}
