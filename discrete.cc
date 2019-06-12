//
// Created by henry on 6/10/19.
//

#include "discrete.hpp"
#include <exception>
#include <stdexcept>
#include <utility>
DiscreteDist::DiscreteDist(std::vector<std::pair<double, double>> items): _pairs(std::move(items)) {

}
double DiscreteDist::operator()(double x) const {
    if ()
}
DiscreteDist::DiscreteDist(std::initializer_list<std::initializer_list<double>> init) {
    for (auto pair: init) {
        if (pair.size() != 2) {
            throw std::invalid_argument("The discrete distribution accepts only pairs of value and accumulated "
                                        "probability");
        }
        std::initializer_list<double>::const_iterator  it = pair.begin();
        double fst =  *it;
        it++;
        double snd = *it;
        this->_pairs.push_back(std::make_pair(fst, snd));
    }

}
