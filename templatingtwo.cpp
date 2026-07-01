//Templating TWO Lab
#include <iostream>
#include <vector>
#include <functional>
#include <cassert>
#include <algorithm>

using namespace std;

template <typename T>
// fills a vector with 10 values starting from elem
vector<T> vec_fill(T elem) {
    vector<T> numbers;

    for (int i = 0; i < 10; i++) {
        numbers.push_back(elem + i);
    }
    return numbers;
}

// applies function repeatedly until predicate becomes true
template <typename T>
T until(T elem, function<T(T)> func, function<bool(T)> predicate) {
    while (!predicate(elem)) {
        elem = func(elem);
    }
    return elem;
}

// puts values in order: a = largest, b = middle, c = smallest
template <typename T>
void order(T& a, T& b, T& c) {
    if (b > a) swap(a, b);
    if (c > a) swap(a, c);
    if (c > b) swap(b, c);
}

int main() {

    //test with integers
    vector<int> v1 = vec_fill(1);
    assert(v1[0] == 1 && v1[9] == 10);
    //test with double
    vector<double> v2 = vec_fill(2.5);
    assert(v2[0] == 2.5 && v2[1] == 3.5);
    //test with characters
    vector<char> v3 = vec_fill('a');
    assert(v3[0] == 'a' && v3[1] == 'b');

    // UNTIL tests, function that doubles integer
    function<int(int)> double_num = [](int x) {
        return x * 2;
    };
    //stops when value is greater than 100
    function<bool(int)> gt_100 = [](int x) {
        return x > 100;
    };
    
    int result = until(2, double_num, gt_100);
    assert(result > 100);

    function<double(double)> add1 = [](double x) {
        return x + 1.0;
    };
    //stops when the value is greater than 10
    function<bool(double)> gt_10 = [](double x) {
        return x > 10.0;
    };
    double result2 = until(1.0, add1, gt_10);
    assert(result2 > 10.0);

    //order tests
    int a = 3, b = 9, c = 1; // integers
    order(a, b, c);
    assert(a == 9 && b == 3 && c == 1);
    //double
    double x = 2.5, y = 10.1, z = 7.3;
    order(x, y, z);
    assert(x == 10.1 && y == 7.3 && z == 2.5);
    //character
    char p = 'b', q = 'a', r = 'c';
    order(p, q, r);
    assert(p == 'c' && q == 'b' && r == 'a');
    //to make sure they all worked, this will print
    cout << "All tests passed!" << endl;
    return 0;
}