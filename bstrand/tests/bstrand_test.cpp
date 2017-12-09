
#define DEBUG

//List ADTs included below:
#include "BSTRAND.h"


//Catch testing file included below:
#define CATCH_CONFIG_MAIN
#include "catch.h"

using namespace cop3530;

bool compare(const int &a, const int &b) {
    if (a < b)
        return true;
    return false;
}

bool equals(const int &a, const int &b) {
    if (a == b)
        return true;
    return false;

}

TEST_CASE("Testing each method of the BSTRAND", "[BSTRAND]") {

    SECTION("Testing insert function and lookup function") {
        BSTRAND<int, int, compare, equals> *test_bstrand_1 = new BSTRAND<int, int, compare, equals>;

        test_bstrand_1->insert(4, 4);
        test_bstrand_1->insert(1, 1);
        test_bstrand_1->insert(3, 3);
        test_bstrand_1->insert(2, 2);
        test_bstrand_1->insert(5, 5);
        test_bstrand_1->insert(7, 7);
        test_bstrand_1->insert(6, 6);
        test_bstrand_1->insert(8, 8);
        test_bstrand_1->insert(10, 10);
        test_bstrand_1->insert(9, 9);
        test_bstrand_1->insert(11, 11);
        test_bstrand_1->insert(12, 12);
        test_bstrand_1->insert(12, 99);

        REQUIRE_THROWS(test_bstrand_1->lookup(13));

        REQUIRE(test_bstrand_1->lookup(1) == 1);
        REQUIRE(test_bstrand_1->lookup(2) == 2);
        REQUIRE(test_bstrand_1->lookup(3) == 3);
        REQUIRE(test_bstrand_1->lookup(4) == 4);
        REQUIRE(test_bstrand_1->lookup(5) == 5);
        REQUIRE(test_bstrand_1->lookup(6) == 6);
        REQUIRE(test_bstrand_1->lookup(7) == 7);
        REQUIRE(test_bstrand_1->lookup(8) == 8);
        REQUIRE(test_bstrand_1->lookup(9) == 9);
        REQUIRE(test_bstrand_1->lookup(10) == 10);
        REQUIRE(test_bstrand_1->lookup(11) == 11);
        REQUIRE(test_bstrand_1->lookup(12) == 99);

        delete test_bstrand_1;
    }

    SECTION("Testing remove function") {
        BSTRAND<int, int, compare, equals> *test_bstrand_2 = new BSTRAND<int, int, compare, equals>;
        test_bstrand_2->insert(4, 4);
        test_bstrand_2->insert(1, 1);
        test_bstrand_2->insert(3, 3);
        test_bstrand_2->insert(2, 2);
        test_bstrand_2->insert(5, 5);
        test_bstrand_2->insert(7, 7);
        test_bstrand_2->insert(6, 6);
        test_bstrand_2->insert(8, 8);
        test_bstrand_2->insert(10, 10);
        test_bstrand_2->insert(9, 9);
        test_bstrand_2->insert(11, 11);
        test_bstrand_2->insert(12, 12);

        REQUIRE(test_bstrand_2->lookup(4) == 4);
        test_bstrand_2->remove(4);
        REQUIRE_THROWS(test_bstrand_2->lookup(4) == 4);
        REQUIRE(test_bstrand_2->lookup(1) == 1);
        test_bstrand_2->remove(1);
        REQUIRE_THROWS(test_bstrand_2->lookup(1) == 1);
        REQUIRE(test_bstrand_2->lookup(3) == 3);
        test_bstrand_2->remove(3);
        REQUIRE_THROWS(test_bstrand_2->lookup(3) == 3);
        REQUIRE(test_bstrand_2->lookup(2) == 2);
        test_bstrand_2->remove(2);
        REQUIRE_THROWS(test_bstrand_2->lookup(2) == 2);
        REQUIRE(test_bstrand_2->lookup(5) == 5);
        test_bstrand_2->remove(5);
        REQUIRE_THROWS(test_bstrand_2->lookup(5) == 5);
        REQUIRE(test_bstrand_2->lookup(7) == 7);
        test_bstrand_2->remove(7);
        REQUIRE_THROWS(test_bstrand_2->lookup(7) == 7);
        REQUIRE(test_bstrand_2->lookup(6) == 6);
        test_bstrand_2->remove(6);
        REQUIRE_THROWS(test_bstrand_2->lookup(6) == 6);
        REQUIRE(test_bstrand_2->lookup(8) == 8);
        test_bstrand_2->remove(8);
        REQUIRE_THROWS(test_bstrand_2->lookup(8) == 8);
        REQUIRE(test_bstrand_2->lookup(10) == 10);
        test_bstrand_2->remove(10);
        REQUIRE_THROWS(test_bstrand_2->lookup(10) == 10);
        REQUIRE(test_bstrand_2->lookup(9) == 9);
        test_bstrand_2->remove(9);
        REQUIRE_THROWS(test_bstrand_2->lookup(9) == 9);
        REQUIRE(test_bstrand_2->lookup(11) == 11);
        test_bstrand_2->remove(11);
        REQUIRE_THROWS(test_bstrand_2->lookup(11) == 11);
        REQUIRE(test_bstrand_2->lookup(12) == 12);
        test_bstrand_2->remove(12);
        REQUIRE_THROWS(test_bstrand_2->lookup(12) == 12);

        delete test_bstrand_2;
    }

    SECTION("Testing copy constructor") {
        BSTRAND<int, int, compare, equals> *test_bstrand_3 = new BSTRAND<int, int, compare, equals>;
        test_bstrand_3->insert(4, 4);
        test_bstrand_3->insert(1, 1);
        test_bstrand_3->insert(3, 3);
        test_bstrand_3->insert(2, 2);
        test_bstrand_3->insert(5, 5);
        test_bstrand_3->insert(7, 7);
        test_bstrand_3->insert(6, 6);
        test_bstrand_3->insert(8, 8);
        test_bstrand_3->insert(10, 10);

        BSTRAND<int, int, compare, equals> *test_bstrand_4 = new BSTRAND<int, int, compare, equals>(*test_bstrand_3);

        REQUIRE(test_bstrand_4->lookup(1) == 1);
        REQUIRE(test_bstrand_4->lookup(2) == 2);
        REQUIRE(test_bstrand_4->lookup(3) == 3);
        REQUIRE(test_bstrand_4->lookup(4) == 4);
        REQUIRE(test_bstrand_4->lookup(5) == 5);
        REQUIRE(test_bstrand_4->lookup(6) == 6);
        REQUIRE(test_bstrand_4->lookup(7) == 7);

        test_bstrand_4->remove(7);

        REQUIRE(test_bstrand_3->lookup(7) == 7);

        delete test_bstrand_3;
        delete test_bstrand_4;
    }

    SECTION("Testing copy assignment operator") {
        BSTRAND<int, int, compare, equals> *test_bstrand_5 = new BSTRAND<int, int, compare, equals>;
        test_bstrand_5->insert(4, 4);
        test_bstrand_5->insert(1, 1);
        test_bstrand_5->insert(3, 3);
        test_bstrand_5->insert(2, 2);
        test_bstrand_5->insert(5, 5);
        test_bstrand_5->insert(7, 7);
        test_bstrand_5->insert(6, 6);
        test_bstrand_5->insert(8, 8);
        test_bstrand_5->insert(10, 10);

        BSTRAND<int, int, compare, equals> *test_bstrand_6 = new BSTRAND<int, int, compare, equals>;

        *test_bstrand_6 = *test_bstrand_5;

        REQUIRE(test_bstrand_6->lookup(1) == 1);
        REQUIRE(test_bstrand_6->lookup(2) == 2);
        REQUIRE(test_bstrand_6->lookup(3) == 3);
        REQUIRE(test_bstrand_6->lookup(4) == 4);
        REQUIRE(test_bstrand_6->lookup(5) == 5);
        REQUIRE(test_bstrand_6->lookup(6) == 6);
        REQUIRE(test_bstrand_6->lookup(7) == 7);

        test_bstrand_6->remove(7);

        REQUIRE(test_bstrand_5->lookup(7) == 7);
        delete test_bstrand_5;
        delete test_bstrand_6;
    }

    SECTION("Testing move constructor") {
        BSTRAND<int, int, compare, equals> *test_bstrand_7 = new BSTRAND<int, int, compare, equals>;
        test_bstrand_7->insert(4, 4);
        test_bstrand_7->insert(1, 1);
        test_bstrand_7->insert(3, 3);
        test_bstrand_7->insert(2, 2);
        test_bstrand_7->insert(5, 5);
        test_bstrand_7->insert(7, 7);
        test_bstrand_7->insert(6, 6);
        test_bstrand_7->insert(8, 8);
        test_bstrand_7->insert(10, 10);

        BSTRAND<int, int, compare, equals> *test_bstrand_8 = new BSTRAND<int, int, compare, equals>(std::move(*test_bstrand_7));

        REQUIRE(test_bstrand_8->lookup(1) == 1);
        REQUIRE(test_bstrand_8->lookup(2) == 2);
        REQUIRE(test_bstrand_8->lookup(3) == 3);
        REQUIRE(test_bstrand_8->lookup(4) == 4);
        REQUIRE(test_bstrand_8->lookup(5) == 5);
        REQUIRE(test_bstrand_8->lookup(6) == 6);
        REQUIRE(test_bstrand_8->lookup(7) == 7);
        REQUIRE(test_bstrand_8->lookup(8) == 8);
        REQUIRE(test_bstrand_8->lookup(10) == 10);

        REQUIRE_THROWS(test_bstrand_7->lookup(1) == 1);
        REQUIRE_THROWS(test_bstrand_7->lookup(2) == 2);
        REQUIRE_THROWS(test_bstrand_7->lookup(3) == 3);
        REQUIRE_THROWS(test_bstrand_7->lookup(4) == 4);
        REQUIRE_THROWS(test_bstrand_7->lookup(5) == 5);
        REQUIRE_THROWS(test_bstrand_7->lookup(6) == 6);
        REQUIRE_THROWS(test_bstrand_7->lookup(7) == 7);
        REQUIRE_THROWS(test_bstrand_7->lookup(8) == 8);
        REQUIRE_THROWS(test_bstrand_7->lookup(9) == 9);
        REQUIRE_THROWS(test_bstrand_7->lookup(10) == 10);

        delete test_bstrand_7;
        delete test_bstrand_8;
    }

    SECTION("Testing move assignment operator") {
        BSTRAND<int, int, compare, equals> *test_bstrand_9 = new BSTRAND<int, int, compare, equals>;
        test_bstrand_9->insert(4, 4);
        test_bstrand_9->insert(1, 1);
        test_bstrand_9->insert(3, 3);
        test_bstrand_9->insert(2, 2);
        test_bstrand_9->insert(5, 5);
        test_bstrand_9->insert(7, 7);
        test_bstrand_9->insert(6, 6);
        test_bstrand_9->insert(8, 8);
        test_bstrand_9->insert(10, 10);

        BSTRAND<int, int, compare, equals> *test_bstrand_10 = new BSTRAND<int, int, compare, equals>;
        *test_bstrand_10 = std::move(*test_bstrand_9);
        REQUIRE(test_bstrand_10->lookup(1) == 1);
        REQUIRE(test_bstrand_10->lookup(2) == 2);
        REQUIRE(test_bstrand_10->lookup(3) == 3);
        REQUIRE(test_bstrand_10->lookup(4) == 4);
        REQUIRE(test_bstrand_10->lookup(5) == 5);
        REQUIRE(test_bstrand_10->lookup(6) == 6);
        REQUIRE(test_bstrand_10->lookup(7) == 7);
        REQUIRE(test_bstrand_10->lookup(10) == 10);

        REQUIRE_THROWS(test_bstrand_9->lookup(1) == 1);
        REQUIRE_THROWS(test_bstrand_9->lookup(2) == 2);
        REQUIRE_THROWS(test_bstrand_9->lookup(3) == 3);
        REQUIRE_THROWS(test_bstrand_9->lookup(4) == 4);
        REQUIRE_THROWS(test_bstrand_9->lookup(5) == 5);
        REQUIRE_THROWS(test_bstrand_9->lookup(6) == 6);
        REQUIRE_THROWS(test_bstrand_9->lookup(7) == 7);
        REQUIRE_THROWS(test_bstrand_9->lookup(8) == 8);
        REQUIRE_THROWS(test_bstrand_9->lookup(9) == 9);
        REQUIRE_THROWS(test_bstrand_9->lookup(10) == 10);

        delete test_bstrand_9;
        delete test_bstrand_10;
    }

    SECTION("Testing contains()") {
        BSTRAND<int, int, compare, equals> *test_bstrand_11 = new BSTRAND<int, int, compare, equals>;

        test_bstrand_11->insert(4, 4);
        test_bstrand_11->insert(1, 1);
        test_bstrand_11->insert(3, 3);
        test_bstrand_11->insert(2, 2);
        test_bstrand_11->insert(5, 5);
        test_bstrand_11->insert(7, 7);
        test_bstrand_11->insert(6, 6);
        test_bstrand_11->insert(8, 8);
        test_bstrand_11->insert(10, 10);

        REQUIRE(test_bstrand_11->contains(4) == true);
        REQUIRE(test_bstrand_11->contains(1) == true);
        REQUIRE(test_bstrand_11->contains(3) == true);
        REQUIRE(test_bstrand_11->contains(2) == true);
        REQUIRE(test_bstrand_11->contains(5) == true);
        REQUIRE(test_bstrand_11->contains(7) == true);
        REQUIRE(test_bstrand_11->contains(6) == true);
        REQUIRE(test_bstrand_11->contains(8) == true);
        REQUIRE(test_bstrand_11->contains(10) == true);

        delete test_bstrand_11;
    }

    SECTION("Testing is_empty() function") {
        BSTRAND<int, int, compare, equals> *test_bstrand_12 = new BSTRAND<int, int, compare, equals>;

        REQUIRE(test_bstrand_12->is_empty() == true);
        test_bstrand_12->insert(1, 1);
        REQUIRE(test_bstrand_12->is_empty() == false);
        test_bstrand_12->remove(1);
        REQUIRE(test_bstrand_12->is_empty() == true);

        delete test_bstrand_12;
    }

    SECTION("Testing is_full function") {
        BSTRAND<int, int, compare, equals> *test_bstrand_13 = new BSTRAND<int, int, compare, equals>;
        REQUIRE(test_bstrand_13->is_full() == false);
        delete test_bstrand_13;
    }

    SECTION("Testing size() function") {
        BSTRAND<int, int, compare, equals> *test_bstrand_14 = new BSTRAND<int, int, compare, equals>;

        test_bstrand_14->insert(4, 4);
        test_bstrand_14->insert(1, 1);
        test_bstrand_14->insert(3, 3);
        test_bstrand_14->insert(2, 2);
        test_bstrand_14->insert(5, 5);
        test_bstrand_14->insert(7, 7);
        test_bstrand_14->insert(6, 6);
        test_bstrand_14->insert(8, 8);
        test_bstrand_14->insert(10, 10);

        REQUIRE(test_bstrand_14->size() == 9);

        delete test_bstrand_14;
    }

    SECTION("Testing clear() function") {
        BSTRAND<int, int, compare, equals> *test_bstrand_15 = new BSTRAND<int, int, compare, equals>;

        test_bstrand_15->insert(4, 4);
        test_bstrand_15->insert(1, 1);
        test_bstrand_15->insert(3, 3);
        test_bstrand_15->insert(2, 2);
        test_bstrand_15->insert(5, 5);
        test_bstrand_15->insert(7, 7);
        test_bstrand_15->insert(6, 6);
        test_bstrand_15->insert(8, 8);
        test_bstrand_15->insert(10, 10);

        test_bstrand_15->clear();

        test_bstrand_15->is_empty();

        delete test_bstrand_15;
    }

    SECTION("Testing height function") {
        BSTRAND<int, int, compare, equals> *test_bstrand_16 = new BSTRAND<int, int, compare, equals>;

        test_bstrand_16->insert(4, 4);

        REQUIRE(test_bstrand_16->height() == 0);

        delete test_bstrand_16;
    }

    SECTION("Testing balance function") {
        BSTRAND<int, int, compare, equals> *test_bstrand_17 = new BSTRAND<int, int, compare, equals>;

        test_bstrand_17->insert(4, 4);

        REQUIRE(test_bstrand_17->balance() == 0);

        delete test_bstrand_17;
    }


}
