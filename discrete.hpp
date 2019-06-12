//
// Created by henry on 6/10/19.
//

#ifndef INE5425X3_DISCRETE_HPP
#define INE5425X3_DISCRETE_HPP
#include <vector>
#include <utility>
#include <initializer_list>


class DiscreteDist {
public:
    using PairList = ::std::vector<::std::pair<double, double>>;
    explicit DiscreteDist(PairList items);
    DiscreteDist(std::initializer_list<std::initializer_list<double>> init);
    double operator()(double x) const;
private:
    PairList _pairs;
};

#endif //INE5425X3_DISCRETE_HPP
