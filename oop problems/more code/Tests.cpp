#include "Tests.h"


void Tests::runAllTests()
{
    test_user();
    test_null_user();
}

void Tests::test_user()
{
    std::map<std::string, unsigned int> themap;

    themap["water"] = 520;

    User testedUser(0, "Test Name", 1000);
    assert(testedUser.check_if_purchase_exists("") == true);
    testedUser.set_all_new_purchase_prices(themap);
    assert(testedUser.get_id() == 0);
    assert(testedUser.get_name() == "Test Name");
    assert(testedUser.get_account_balance() == 1000);
    std::map<std::string, unsigned int> check_map = testedUser.get_purchased_price();
    assert(themap.size() == check_map.size() && std::equal(themap.begin(), themap.end(), check_map.begin()));

    User copyTestUser(testedUser);
    assert(copyTestUser.get_id() == 0);
    assert(copyTestUser.get_name() == "Test Name");
    assert(copyTestUser.get_account_balance() == 1000);
    assert(copyTestUser.check_if_purchase_exists("water") == true);

    testedUser.add_purchase("water", 30);
    assert(testedUser.get_specific_purchase_price("water") == 550);
    testedUser.add_purchase("food", 400);
    assert(testedUser.get_specific_purchase_price("food") == 400);

    testedUser.add_to_balance(500);
    assert(testedUser.get_account_balance() == 1500);
    testedUser.substract_from_balance(500);
    assert(testedUser.get_account_balance() == 1000);
    testedUser.set_balance(1500);
    assert(testedUser.get_account_balance() == 1500);

    testedUser.set_specific_purchase_price("food", 750);
    assert(testedUser.get_specific_purchase_price("food") == 750);
    assert(testedUser.get_specific_purchase_price("food") != 400);

    testedUser.remove_purchase("food");
    assert(testedUser.check_if_purchase_exists("food") == false);
    try {
        testedUser.remove_purchase("catch me");
        assert(false);
    }
    catch (int catch_int) {
        assert(catch_int == 404);
    }
    assert(testedUser.get_total_balance_spent() == 550);
}

void Tests::test_null_user() {

    User test_null_user;
    assert(test_null_user.get_id() == NULL);
    assert(test_null_user.get_name() == "");
    assert(test_null_user.get_account_balance() == 0);

    std::map<std::string, unsigned int> check_map = test_null_user.get_purchased_price();
    assert(check_map[""] == NULL);

}
