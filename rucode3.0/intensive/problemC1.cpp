//
// Created by Dmitry Kochetkov on 4/19/2021.
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    long n, m, k;
    cin >> n;

    map<string, unsigned long long> cities;
    map<string, unsigned long long> people;
    map<string, string> people_location;

    for (long i = 0; i < n; i++) {
        string name, city;
        unsigned long long amount;
        cin >> name >> city >> amount;

        people[name] = amount;
        people_location[name] = city;
        if (cities.find(city) == cities.end())
            cities[city] = amount;
        else cities[city] += amount;
    }

    // хранить город с максимальным количеством денег
    string max_city;
    unsigned long long max_amount = 0;

    map<string, long> result;
    for (auto& kv: cities) {
        if (kv.second > max_amount) {
            max_city = kv.first;
            max_amount = kv.second;
        }
        result[kv.first] = 0;
    }

    result[max_city] = 1;

    cin >> m >> k;
    long last_flight_day = 0;

    for (long i = 0; i < k; i++) {
        long day;
        string name, next_city;

        std::cin >> day >> name >> next_city;
        unsigned long long amount = people[name];

        result[max_city] = day-last_flight_day;
        last_flight_day=day;

        cities[next_city] += amount;
        cities[people_location[name]] -= amount;
        if (max_city == people_location[name])
            max_amount -= amount;

        if (cities[next_city] > max_amount) {
            max_city = next_city;
            max_amount = cities[next_city];
        }
    }

    result[max_city] = last_flight_day-k+1;

    for (auto& kv: result) {
        if (kv.second != 0)
            std::cout << kv.first << " " << kv.second << std::endl;
    }

    return 0;
}