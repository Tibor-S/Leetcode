
#include <array>
#include <cstddef>
#include <functional>
#include <set>
#include <unordered_map>
#include <vector>
using std::vector;
using std::set;
using std::unordered_map;

/*
 * @lc app=leetcode id=1912 lang=cpp
 *
 * [1912] Design Movie Rental System
 */

// @lc code=start

struct Entry {
    int movie, shop, price;
    Entry(int a, int b) : movie(a), shop(b), price(0) {}
    Entry(int a, int b, int c) : movie(a), shop(b), price(c) {}
    Entry(vector<int>& v) : movie(v[1]), shop(v[0]), price(v[2]) {}
};

struct ArrayHasher {
    std::size_t operator()(const std::array<int, 2>& a) const {
        std::size_t h = 0;

        for (auto e : a) {
            h ^= std::hash<int>{}(e)  + 0x9e3779b9 + (h << 6) + (h >> 2); 
        }
        return h;
    }   
};

struct CmpSearch {
    constexpr bool operator()(const Entry &l, const Entry& r) const {
        if (l.movie == r.movie) {
            if (l.price == r.price) {
                return l.shop < r.shop;
            }
            return l.price < r.price;
        }
        return l.movie < r.movie;
    }
};

struct CmpReport {
    constexpr bool operator()(const Entry &l, const Entry& r) const {
        if (l.price == r.price) {
            if (l.shop == r.shop) {
                return l.movie < r.movie;
            }
            return l.shop < r.shop;
        }
        return l.price < r.price;
    }
};

class MovieRentingSystem {
public:
    unordered_map<int, set<Entry, CmpSearch>> searchable {};
    set<Entry, CmpReport> reportable {};
    unordered_map<std::array<int,2>, int, ArrayHasher> get_price {};

    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for (auto& entry:entries) {
            Entry re(entry);
            searchable[re.movie].insert(re);
            get_price[{re.movie, re.shop}] = re.price;
        }
    }
    
    vector<int> search(int movie) {
        vector<int> ret {};
        auto &movies = searchable[movie];
        auto it = movies.begin();
        for (int i = 0; i < 5 && it != movies.end(); i++, it++) {
            ret.push_back(it->shop);
        }
        return ret;
    }
    
    void rent(int shop, int movie) {
        Entry index = Entry(movie, shop, get_price[{movie, shop}]);
        searchable[movie].erase(index);
        reportable.insert(index);
    }
    
    void drop(int shop, int movie) {
        Entry index = Entry(movie, shop, get_price[{movie, shop}]);
        reportable.erase(index);
        searchable[movie].insert(index);
    }
    
    vector<vector<int>> report() {
        vector<vector<int>> ret {};
        auto it = reportable.begin();
        for (int i = 0; i < 5 && it != reportable.end(); i++, it++) {
            ret.push_back({it->shop, it->movie});
        }
        return ret;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */
// @lc code=end

