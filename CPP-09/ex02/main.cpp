#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <climits>

bool is_number(const char* str) {
    while (*str != '\0' && std::isdigit(*str))
        ++str;
    return (*str == '\0');
}

bool has_duplicates(const std::vector<int>& vec) {
    std::vector<int> tmp(vec);
    std::sort(tmp.begin(), tmp.end());
    return std::unique(tmp.begin(), tmp.end()) != tmp.end();
}

std::vector<size_t> generateJacobsthalOrder(size_t n) {
    std::vector<size_t> order;
    std::vector<size_t> jacobsthal;

    jacobsthal.push_back(0);
    jacobsthal.push_back(1);

    size_t i = 2;
    while (true) {
        size_t next = jacobsthal[i - 1] + 2 * jacobsthal[i - 2];
        if (next >= n)
            break;
        jacobsthal.push_back(next);
        ++i;
    }

    std::vector<bool> added(n, false);

    for (size_t j = jacobsthal.size(); j-- > 1;) {
        size_t start = jacobsthal[j - 1] + 1;
        size_t end = std::min(jacobsthal[j], n);
        for (size_t k = end; k-- > start;) {
            order.push_back(k);
            added[k] = true;
        }
    }
    for (size_t k = 0; k < n; ++k) {
        if (!added[k])
            order.push_back(k);
    }

    return order;
}


template <typename T>
void ford_johnson_sort(T& c) {
    if (c.size() <= 1) return;

    typedef typename T::value_type V;

    std::vector<std::pair<V, V> > pairs;
    V straggler;
    bool hasStraggler = false;

    for (size_t i = 0; i + 1 < c.size(); i += 2) {
        V a = c[i];
        V b = c[i + 1];
        if (a > b) std::swap(a, b);
        pairs.push_back(std::make_pair(a, b));
    }
    if (c.size() % 2 != 0) {
        hasStraggler = true;
        straggler = c[c.size() - 1];
    }

    T mainChain;
    for (size_t i = 0; i < pairs.size(); ++i)
        mainChain.push_back(pairs[i].second);

    ford_johnson_sort(mainChain);

    std::vector<size_t> insertOrder = generateJacobsthalOrder(pairs.size());
    for (size_t i = 0; i < insertOrder.size(); ++i) {
        size_t idx = insertOrder[i];
        if (idx >= pairs.size()) continue;
        V small = pairs[idx].first;
        typename T::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), small);
        mainChain.insert(pos, small);
    }

    if (hasStraggler) {
        typename T::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), straggler);
        mainChain.insert(pos, straggler);
    }

    c = mainChain;
}

template <typename T>
void print(const T& container) {
    for (typename T::const_iterator it = container.begin(); it != container.end(); ++it)
        std::cout << *it << " ";
}

template <typename Container>
double sort_and_time(Container& cont) {
    /* std::cout << "Before ";
    print(cont);
    std::cout << std::endl; */

    double timer_start = clock();
    ford_johnson_sort(cont);
    double duration = clock() - timer_start;

   /*  std::cout << "After ";
    print(cont); */
    //std::cout << std::endl;
    //std::cout << "Duration: " << duration << " us" << std::endl;
    return duration;
}

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "Usage: ./PmergeMe 1 2 3 4..." << std::endl;
        return 1;
    }

    std::vector<int> input;
    for (int i = 1; argv[i]; ++i) {
        if (!is_number(argv[i])) {
            std::cerr << "Invalid input" << std::endl;
            return 1;
        }
        input.push_back(std::atoi(argv[i]));
    }

    std::vector<int> vec = input;
    std::deque<int> deq(input.begin(), input.end());

    std::cout << "Before: ";
    print(input);
    std::cout << std::endl;

    double vec_duration = sort_and_time(vec);
    double deq_duration = sort_and_time(deq);

    std::cout << "After: ";
    print(vec); // ou deq, c’est pareil après tri
    std::cout << std::endl;

    std::cout << "Time to process a range of " << input.size()
              << " elements with std::vector : " << vec_duration << " us" << std::endl;

    std::cout << "Time to process a range of " << input.size()
              << " elements with std::deque : " << deq_duration << " us" << std::endl;

    return 0;
 //   if (has_duplicates(vec)) {
   //     std::cerr << "has duplicates" << std::endl;
   //     return 1;
   // }

   
}