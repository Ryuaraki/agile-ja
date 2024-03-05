#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <float.h> // DBL_EPSILON
#include <math.h>  // fabs()

/*----これらの関数を変更する必要はありません----*/

bool contains(const std::string& name, const std::vector<std::string>& list_of_names) {
    return std::find(list_of_names.begin(), list_of_names.end(), name) != list_of_names.end(); // find関数は値が存在しない場合はend()を返す
}

void add_name(const std::string& name, std::vector<std::string>& list_of_names) {
    list_of_names.push_back(name);
}

int add_two(int num) {
    return num + 2;
}

double divide_by_two(double num) {
    return num / 2;
}

std::string greeting(const std::string& name, double num) {
    std::string message {"Hello, " + name + ". It is " + std::to_string(num) + " degrees warmer today than yesterday"};
    return message;
}

/*----ここにコードを書いてください----*/
/*----難易度: 富士----*/

// `my_assert` をここに定義し、以降のテストに使用してください。
void my_assert(bool expr, std::string msg = "Test failed!") {

    if (!expr) {
        throw std::runtime_error(msg);
    }
    std::cout << "Test passed!" << std::endl;
}

// `contains` 用のテスト `test_contains` を作成してください
void test_contains () {

    std::vector<std::string> name_list {"Taro", "Jiro", "Hanako"};

    try {
        my_assert(contains("Taro", name_list) == true, "test_contains failed for the existing value.");
        my_assert(contains("Hanako", name_list) == true, "test_contains failed fot the existing value.");
        my_assert(contains("John", name_list) == false, "test_contains failied for the non-existing value.");
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}

// `add_name` 用のテスト `test_add_name` を作成してください
void test_add_name () {

    std::vector<std::string> name_list {"Taro", "Jiro", "Hanako"};
    const size_t original_size {name_list.size()};

    try {
        add_name("John", name_list);
        my_assert(name_list.size() == original_size + 1, "test_add_name failed for the size.");
        my_assert(name_list.back() == "John", "test_add_name faided for the added element.");
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}

// `add_two` 用のテスト `test_add_two` を作成してください
void test_add_two () {

    try {
        my_assert(add_two(4) == 6, "test_add_two failed for the positive value.");
        my_assert(add_two(-4) == -2, "test_add_two failed for the negative value.");
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}


// `divide_by_two` 用のテスト `test_divide_by_two` を作成してください
void test_divide_by_two () {

    try {
        my_assert(fabs(divide_by_two(4.0) - 2.0) < DBL_EPSILON, "test_divided_by_two failed for the positive value.");
        my_assert(fabs(divide_by_two(-2.0) + 1.0) < DBL_EPSILON, "test_divided_by_two failed for the negative value.");
        my_assert(fabs(divide_by_two(0.0)) < DBL_EPSILON, "test_divided_by_two failed for zero.");
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

}


// `greeting` 用のテスト `test_greeting` を作成してください
void test_greeting() {

    const std::string expected{"Hello, Taro. It is 3.000000 degrees warmer today than yesterday"};

    try {
        my_assert(greeting("Taro", 3.0) == expected, "test_greeting failed fot the current input.");
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}



int main () {

    test_contains();
    test_add_name();
    test_add_two();
    test_divide_by_two();
    test_greeting();

    return 0;
}

/*----難易度: キリマンジャロ----*/

// `my_assert` 用のテスト `test_my_assert_false` を作成し、式がfalseと評価されたときに指定したオプションの `msg` を適切に返すかどうかをチェックしてください。

// `my_assert` 用のテスト `test_my_assert_true` を作成し、式がtrueと評価されたときに適切に処理するかどうかをチェックしてください。