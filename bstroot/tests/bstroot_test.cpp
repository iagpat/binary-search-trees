
#define DEBUG

//List ADTs included below:
#include "BSTROOT.h"


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

TEST_CASE("Testing each method of the BSTROOT", "[BSTROOT]") {

    SECTION("Testing insert function and lookup function") {
        BSTROOT<int, int, compare, equals> *test_bstroot_1 = new BSTROOT<int, int, compare, equals>;

        test_bstroot_1->insert(4, 4);
        test_bstroot_1->insert(1, 1);
        test_bstroot_1->insert(3, 3);
        test_bstroot_1->insert(2, 2);
        test_bstroot_1->insert(5, 5);
        test_bstroot_1->insert(7, 7);
        test_bstroot_1->insert(6, 6);
        test_bstroot_1->insert(8, 8);
        test_bstroot_1->insert(10, 10);
        test_bstroot_1->insert(9, 9);
        test_bstroot_1->insert(11, 11);
        test_bstroot_1->insert(12, 12);
        test_bstroot_1->insert(12, 99);

        REQUIRE_THROWS(test_bstroot_1->lookup(13));

        REQUIRE(test_bstroot_1->lookup(1) == 1);
        REQUIRE(test_bstroot_1->lookup(2) == 2);
        REQUIRE(test_bstroot_1->lookup(3) == 3);
        REQUIRE(test_bstroot_1->lookup(4) == 4);
        REQUIRE(test_bstroot_1->lookup(5) == 5);
        REQUIRE(test_bstroot_1->lookup(6) == 6);
        REQUIRE(test_bstroot_1->lookup(7) == 7);
        REQUIRE(test_bstroot_1->lookup(8) == 8);
        REQUIRE(test_bstroot_1->lookup(9) == 9);
        REQUIRE(test_bstroot_1->lookup(10) == 10);
        REQUIRE(test_bstroot_1->lookup(11) == 11);
        REQUIRE(test_bstroot_1->lookup(12) == 99);

        delete test_bstroot_1;
    }

    SECTION("Testing remove function") {
        BSTROOT<int, int, compare, equals> *test_bstroot_2 = new BSTROOT<int, int, compare, equals>;
        test_bstroot_2->insert(4, 4);
        test_bstroot_2->insert(1, 1);
        test_bstroot_2->insert(3, 3);
        test_bstroot_2->insert(2, 2);
        test_bstroot_2->insert(5, 5);
        test_bstroot_2->insert(7, 7);
        test_bstroot_2->insert(6, 6);
        test_bstroot_2->insert(8, 8);
        test_bstroot_2->insert(10, 10);
        test_bstroot_2->insert(9, 9);
        test_bstroot_2->insert(11, 11);
        test_bstroot_2->insert(12, 12);

        REQUIRE(test_bstroot_2->lookup(4) == 4);
        test_bstroot_2->remove(4);
        REQUIRE_THROWS(test_bstroot_2->lookup(4) == 4);
        REQUIRE(test_bstroot_2->lookup(1) == 1);
        test_bstroot_2->remove(1);
        REQUIRE_THROWS(test_bstroot_2->lookup(1) == 1);
        REQUIRE(test_bstroot_2->lookup(3) == 3);
        test_bstroot_2->remove(3);
        REQUIRE_THROWS(test_bstroot_2->lookup(3) == 3);
        REQUIRE(test_bstroot_2->lookup(2) == 2);
        test_bstroot_2->remove(2);
        REQUIRE_THROWS(test_bstroot_2->lookup(2) == 2);
        REQUIRE(test_bstroot_2->lookup(5) == 5);
        test_bstroot_2->remove(5);
        REQUIRE_THROWS(test_bstroot_2->lookup(5) == 5);
        REQUIRE(test_bstroot_2->lookup(7) == 7);
        test_bstroot_2->remove(7);
        REQUIRE_THROWS(test_bstroot_2->lookup(7) == 7);
        REQUIRE(test_bstroot_2->lookup(6) == 6);
        test_bstroot_2->remove(6);
        REQUIRE_THROWS(test_bstroot_2->lookup(6) == 6);
        REQUIRE(test_bstroot_2->lookup(8) == 8);
        test_bstroot_2->remove(8);
        REQUIRE_THROWS(test_bstroot_2->lookup(8) == 8);
        REQUIRE(test_bstroot_2->lookup(10) == 10);
        test_bstroot_2->remove(10);
        REQUIRE_THROWS(test_bstroot_2->lookup(10) == 10);
        REQUIRE(test_bstroot_2->lookup(9) == 9);
        test_bstroot_2->remove(9);
        REQUIRE_THROWS(test_bstroot_2->lookup(9) == 9);
        REQUIRE(test_bstroot_2->lookup(11) == 11);
        test_bstroot_2->remove(11);
        REQUIRE_THROWS(test_bstroot_2->lookup(11) == 11);
        REQUIRE(test_bstroot_2->lookup(12) == 12);
        test_bstroot_2->remove(12);
        REQUIRE_THROWS(test_bstroot_2->lookup(12) == 12);

        delete test_bstroot_2;
    }

    SECTION("Testing copy constructor") {
        BSTROOT<int, int, compare, equals> *test_bstroot_3 = new BSTROOT<int, int, compare, equals>;
        test_bstroot_3->insert(4, 4);
        test_bstroot_3->insert(1, 1);
        test_bstroot_3->insert(3, 3);
        test_bstroot_3->insert(2, 2);
        test_bstroot_3->insert(5, 5);
        test_bstroot_3->insert(7, 7);
        test_bstroot_3->insert(6, 6);
        test_bstroot_3->insert(8, 8);
        test_bstroot_3->insert(10, 10);

        BSTROOT<int, int, compare, equals> *test_bstroot_4 = new BSTROOT<int, int, compare, equals>(*test_bstroot_3);

        REQUIRE(test_bstroot_4->lookup(1) == 1);
        REQUIRE(test_bstroot_4->lookup(2) == 2);
        REQUIRE(test_bstroot_4->lookup(3) == 3);
        REQUIRE(test_bstroot_4->lookup(4) == 4);
        REQUIRE(test_bstroot_4->lookup(5) == 5);
        REQUIRE(test_bstroot_4->lookup(6) == 6);
        REQUIRE(test_bstroot_4->lookup(7) == 7);

        test_bstroot_4->remove(7);

        REQUIRE(test_bstroot_3->lookup(7) == 7);

        delete test_bstroot_3;
        delete test_bstroot_4;
    }

    SECTION("Testing copy assignment operator") {
        BSTROOT<int, int, compare, equals> *test_bstroot_5 = new BSTROOT<int, int, compare, equals>;
        test_bstroot_5->insert(4, 4);
        test_bstroot_5->insert(1, 1);
        test_bstroot_5->insert(3, 3);
        test_bstroot_5->insert(2, 2);
        test_bstroot_5->insert(5, 5);
        test_bstroot_5->insert(7, 7);
        test_bstroot_5->insert(6, 6);
        test_bstroot_5->insert(8, 8);
        test_bstroot_5->insert(10, 10);

        BSTROOT<int, int, compare, equals> *test_bstroot_6 = new BSTROOT<int, int, compare, equals>;

        *test_bstroot_6 = *test_bstroot_5;

        REQUIRE(test_bstroot_6->lookup(1) == 1);
        REQUIRE(test_bstroot_6->lookup(2) == 2);
        REQUIRE(test_bstroot_6->lookup(3) == 3);
        REQUIRE(test_bstroot_6->lookup(4) == 4);
        REQUIRE(test_bstroot_6->lookup(5) == 5);
        REQUIRE(test_bstroot_6->lookup(6) == 6);
        REQUIRE(test_bstroot_6->lookup(7) == 7);

        test_bstroot_6->remove(7);

        REQUIRE(test_bstroot_5->lookup(7) == 7);
        delete test_bstroot_5;
        delete test_bstroot_6;
    }

    SECTION("Testing move constructor") {
        BSTROOT<int, int, compare, equals> *test_bstroot_7 = new BSTROOT<int, int, compare, equals>;
        test_bstroot_7->insert(4, 4);
        test_bstroot_7->insert(1, 1);
        test_bstroot_7->insert(3, 3);
        test_bstroot_7->insert(2, 2);
        test_bstroot_7->insert(5, 5);
        test_bstroot_7->insert(7, 7);
        test_bstroot_7->insert(6, 6);
        test_bstroot_7->insert(8, 8);
        test_bstroot_7->insert(10, 10);

        BSTROOT<int, int, compare, equals> *test_bstroot_8 = new BSTROOT<int, int, compare, equals>(std::move(*test_bstroot_7));

        REQUIRE(test_bstroot_8->lookup(1) == 1);
        REQUIRE(test_bstroot_8->lookup(2) == 2);
        REQUIRE(test_bstroot_8->lookup(3) == 3);
        REQUIRE(test_bstroot_8->lookup(4) == 4);
        REQUIRE(test_bstroot_8->lookup(5) == 5);
        REQUIRE(test_bstroot_8->lookup(6) == 6);
        REQUIRE(test_bstroot_8->lookup(7) == 7);
        REQUIRE(test_bstroot_8->lookup(8) == 8);
        REQUIRE(test_bstroot_8->lookup(10) == 10);

        REQUIRE_THROWS(test_bstroot_7->lookup(1) == 1);
        REQUIRE_THROWS(test_bstroot_7->lookup(2) == 2);
        REQUIRE_THROWS(test_bstroot_7->lookup(3) == 3);
        REQUIRE_THROWS(test_bstroot_7->lookup(4) == 4);
        REQUIRE_THROWS(test_bstroot_7->lookup(5) == 5);
        REQUIRE_THROWS(test_bstroot_7->lookup(6) == 6);
        REQUIRE_THROWS(test_bstroot_7->lookup(7) == 7);
        REQUIRE_THROWS(test_bstroot_7->lookup(8) == 8);
        REQUIRE_THROWS(test_bstroot_7->lookup(9) == 9);
        REQUIRE_THROWS(test_bstroot_7->lookup(10) == 10);

        delete test_bstroot_7;
        delete test_bstroot_8;
    }

    SECTION("Testing move assignment operator") {
        BSTROOT<int, int, compare, equals> *test_bstroot_9 = new BSTROOT<int, int, compare, equals>;
        test_bstroot_9->insert(4, 4);
        test_bstroot_9->insert(1, 1);
        test_bstroot_9->insert(3, 3);
        test_bstroot_9->insert(2, 2);
        test_bstroot_9->insert(5, 5);
        test_bstroot_9->insert(7, 7);
        test_bstroot_9->insert(6, 6);
        test_bstroot_9->insert(8, 8);
        test_bstroot_9->insert(10, 10);

        BSTROOT<int, int, compare, equals> *test_bstroot_10 = new BSTROOT<int, int, compare, equals>;
        *test_bstroot_10 = std::move(*test_bstroot_9);
        REQUIRE(test_bstroot_10->lookup(1) == 1);
        REQUIRE(test_bstroot_10->lookup(2) == 2);
        REQUIRE(test_bstroot_10->lookup(3) == 3);
        REQUIRE(test_bstroot_10->lookup(4) == 4);
        REQUIRE(test_bstroot_10->lookup(5) == 5);
        REQUIRE(test_bstroot_10->lookup(6) == 6);
        REQUIRE(test_bstroot_10->lookup(7) == 7);
        REQUIRE(test_bstroot_10->lookup(10) == 10);

        REQUIRE_THROWS(test_bstroot_9->lookup(1) == 1);
        REQUIRE_THROWS(test_bstroot_9->lookup(2) == 2);
        REQUIRE_THROWS(test_bstroot_9->lookup(3) == 3);
        REQUIRE_THROWS(test_bstroot_9->lookup(4) == 4);
        REQUIRE_THROWS(test_bstroot_9->lookup(5) == 5);
        REQUIRE_THROWS(test_bstroot_9->lookup(6) == 6);
        REQUIRE_THROWS(test_bstroot_9->lookup(7) == 7);
        REQUIRE_THROWS(test_bstroot_9->lookup(8) == 8);
        REQUIRE_THROWS(test_bstroot_9->lookup(9) == 9);
        REQUIRE_THROWS(test_bstroot_9->lookup(10) == 10);

        delete test_bstroot_9;
        delete test_bstroot_10;
    }

    SECTION("Testing contains()") {
        BSTROOT<int, int, compare, equals> *test_bstroot_11 = new BSTROOT<int, int, compare, equals>;

        test_bstroot_11->insert(4, 4);
        test_bstroot_11->insert(1, 1);
        test_bstroot_11->insert(3, 3);
        test_bstroot_11->insert(2, 2);
        test_bstroot_11->insert(5, 5);
        test_bstroot_11->insert(7, 7);
        test_bstroot_11->insert(6, 6);
        test_bstroot_11->insert(8, 8);
        test_bstroot_11->insert(10, 10);

        REQUIRE(test_bstroot_11->contains(4) == true);
        REQUIRE(test_bstroot_11->contains(1) == true);
        REQUIRE(test_bstroot_11->contains(3) == true);
        REQUIRE(test_bstroot_11->contains(2) == true);
        REQUIRE(test_bstroot_11->contains(5) == true);
        REQUIRE(test_bstroot_11->contains(7) == true);
        REQUIRE(test_bstroot_11->contains(6) == true);
        REQUIRE(test_bstroot_11->contains(8) == true);
        REQUIRE(test_bstroot_11->contains(10) == true);

        delete test_bstroot_11;
    }

    SECTION("Testing is_empty() function") {
        BSTROOT<int, int, compare, equals> *test_bstroot_12 = new BSTROOT<int, int, compare, equals>;

        REQUIRE(test_bstroot_12->is_empty() == true);
        test_bstroot_12->insert(1, 1);
        REQUIRE(test_bstroot_12->is_empty() == false);
        test_bstroot_12->remove(1);
        REQUIRE(test_bstroot_12->is_empty() == true);

        delete test_bstroot_12;
    }

    SECTION("Testing is_full function") {
        BSTROOT<int, int, compare, equals> *test_bstroot_13 = new BSTROOT<int, int, compare, equals>;
        REQUIRE(test_bstroot_13->is_full() == false);
        delete test_bstroot_13;
    }

    SECTION("Testing size() function") {
        BSTROOT<int, int, compare, equals> *test_bstroot_14 = new BSTROOT<int, int, compare, equals>;

        test_bstroot_14->insert(4, 4);
        test_bstroot_14->insert(1, 1);
        test_bstroot_14->insert(3, 3);
        test_bstroot_14->insert(2, 2);
        test_bstroot_14->insert(5, 5);
        test_bstroot_14->insert(7, 7);
        test_bstroot_14->insert(6, 6);
        test_bstroot_14->insert(8, 8);
        test_bstroot_14->insert(10, 10);

        REQUIRE(test_bstroot_14->size() == 9);

        delete test_bstroot_14;
    }

    SECTION("Testing clear() function") {
        BSTROOT<int, int, compare, equals> *test_bstroot_15 = new BSTROOT<int, int, compare, equals>;

        test_bstroot_15->insert(4, 4);
        test_bstroot_15->insert(1, 1);
        test_bstroot_15->insert(3, 3);
        test_bstroot_15->insert(2, 2);
        test_bstroot_15->insert(5, 5);
        test_bstroot_15->insert(7, 7);
        test_bstroot_15->insert(6, 6);
        test_bstroot_15->insert(8, 8);
        test_bstroot_15->insert(10, 10);

        test_bstroot_15->clear();

        test_bstroot_15->is_empty();

        delete test_bstroot_15;
    }

    SECTION("Testing height function") {
        BSTROOT<int, int, compare, equals> *test_bstroot_16 = new BSTROOT<int, int, compare, equals>;

        test_bstroot_16->insert(4, 4);
        test_bstroot_16->insert(1, 1);
        test_bstroot_16->insert(3, 3);
        test_bstroot_16->insert(2, 2);
        test_bstroot_16->insert(5, 5);
        test_bstroot_16->insert(7, 7);
        test_bstroot_16->insert(6, 6);
        test_bstroot_16->insert(8, 8);
        test_bstroot_16->insert(10, 10);

        REQUIRE(test_bstroot_16->height() == 6);

        delete test_bstroot_16;
    }

    SECTION("Testing balance function") {
        BSTROOT<int, int, compare, equals> *test_bstroot_17 = new BSTROOT<int, int, compare, equals>;

        test_bstroot_17->insert(4, 4);
        test_bstroot_17->insert(1, 1);
        test_bstroot_17->insert(3, 3);
        test_bstroot_17->insert(2, 2);
        test_bstroot_17->insert(5, 5);
        test_bstroot_17->insert(7, 7);
        test_bstroot_17->insert(6, 6);
        test_bstroot_17->insert(8, 8);
        test_bstroot_17->insert(10, 10);

        REQUIRE(test_bstroot_17->balance() == 6);

        delete test_bstroot_17;
    }


}
