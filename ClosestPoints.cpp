#include <algorithm>
#include <vector>
#include <iostream>
#include <cmath>
#include <iomanip>

struct point {
    double x;
    double y;
};

bool x_sort(point a, point b){ return a.x < b.x; }
bool y_sort(point a, point b){ return a.y < b.y; }

// a = x coordinate , b = y coordinate, c = count of points
void read_in_points(double& a, double& b, double& c, std::vector<point>& list) {
    for (int i = 0; i < c; ++i){
        std::cin >> a >> b;
        point spot;
        spot.x = a;
        spot.y = b;
        list.push_back(spot);
    }
}

// For Calculating the smallest distance between three points
double smallest_of_three(std::vector<point>& list){
    double first_dist = std::sqrt(std::pow((list[0].x - list[1].x), 2) + std::pow((list[0].y - list[1].y), 2));
    double second_dist = std::sqrt(std::pow((list[1].x - list[2].x), 2) + std::pow((list[1].y - list[2].y), 2));
    double third_dist = std::sqrt(std::pow((list[2].x - list[0].x), 2) + std::pow((list[2].y - list[0].y), 2));
    if (first_dist >= second_dist) {
        if (second_dist <= third_dist){ 
            //DEBUG std::cout << "Smallest distance Points(3): (" << list[1].x << "," << list[1].y << ")  & " << "(" << list[2].x << "," << list[2].y << ")\nhave a distance of " << second_dist << "\n";
            return second_dist;
        }
        else { 
            //DEBUG std::cout << "Smallest distance Points(3): (" << list[2].x << "," << list[2].y << ")  & " << "(" << list[0].x << "," << list[0].y << ")\nhave a distance of " << third_dist << "\n";
            return third_dist;
        }
    }
    else { // (first_dist <= second_dist)
        if (first_dist <= third_dist){ 
            //DEBUG std::cout << "Smallest distance Points(3): (" << list[0].x << "," << list[0].y << ")  & " << "(" << list[1].x << "," << list[1].y << ")\nhave a distance of " << first_dist << "\n";
            return first_dist;
        }
        else { 
            //DEBUG std::cout << "Smallest distance Points(3): (" << list[2].x << "," << list[2].y << ")  & " << "(" << list[0].x << "," << list[0].y << ")\nhave a distance of " << third_dist << "\n";
            return third_dist;
        }
    }
}


// For finding the closest split pair of points
// REMEMBER TO PASS IN A CHAR !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
double closest_split_pair(std::vector<point>& list, double& delta, double& mid_value, char& which_list){

    std::vector<point> interval;

    // Making the interval list for lists sorted by x
    if (which_list == 'x'){
        double mid_minus_delta = mid_value - delta;
        double mid_plus_delta = mid_value + delta;
        for (int i =0; i < list.size(); ++i){
            if (list[i].x >= mid_minus_delta && list[i].x <= mid_plus_delta){
                interval.push_back(list[i]);
            }
            if (list[i].x > mid_plus_delta) {break;}
        }
    }

    // Making the interval list for lists sorted by y
    if (which_list == 'y'){
        double  mid_minus_delta = mid_value - delta;
        double mid_plus_delta = mid_value + delta;
        for (int i =0; i < list.size(); ++i){
            if (list[i].y >= mid_minus_delta && list[i].y <= mid_plus_delta){
                interval.push_back(list[i]);
            }
            if (list[i].y > mid_plus_delta) {break;}
        }
    }

    // Searching through the newly made list to see if there were any split distances shorter than the non-split shortest distance
    double distance;
    for (int i = 0; i < interval.size(); ++i){
        for (int j = i + 1; j < i + 8 && j < interval.size(); ++j){
            distance = std::sqrt(std::pow((interval[i].x - interval[j].x), 2) + std::pow((interval[i].y - interval[j].y),2));
            if (distance < delta){
                delta = distance;
            }
        }
    }

    //DEBUG std::cout << "Returning delta(csp): " << delta << "\n";
    return delta;
}

// For finding the closest non-split pair of points
double closest_pair_distance(std::vector<point>& x_list, std::vector<point>& y_list, double& delta){
    // I think it is safe to assume that both lists will always be the same size since we are splitting based on point rather than a distance
    int mid = (x_list.size() / 2);
    std::vector<point> new_bottom, new_top;
    std::vector<point> new_left, new_right;
    for (int i = 0; i < mid; ++i){
        new_left.push_back(x_list[i]);
        new_bottom.push_back(y_list[i]);
    }
    for (int i = mid; i < x_list.size(); ++i){
        new_right.push_back(x_list[i]);
        new_top.push_back(y_list[i]);
    }
    
    // Base Case of there only being 3 or 2 points
    // We need to check both the horizontally split list and the vertically split list, since we are handed two sorted lists
    if (x_list.size() <= 3){
        if (x_list.size() == 3){
            double x = smallest_of_three(x_list);
            double y = smallest_of_three(y_list);
            if (x <= y) { return x; }
            else {return y;}
        }
        else if (x_list.size() == 2){
            double x_first_dist = std::sqrt(std::pow((x_list[0].x - x_list[1].x), 2) + std::pow((x_list[0].y - x_list[1].y), 2));
            double y_first_dist = std::sqrt(std::pow((y_list[0].x - y_list[1].x), 2) + std::pow((y_list[0].y - y_list[1].y), 2));
            if (x_first_dist <= y_first_dist) {
                //DEBUG std::cout << "Smallest distance Points(2): (" << x_list[0].x << "," << x_list[0].y << ")  & " << "(" << x_list[1].x << "," << x_list[1].y << ")\nhave a distance of " << x_first_dist << "\n";
                return x_first_dist;
            }
            else {
                //DEBUG std::cout << "Smallest distance Points(2): (" << y_list[0].x << "," << y_list[0].y << ")  & " << "(" << y_list[1].x << "," << y_list[1].y << ")\nhave a distance of " << y_first_dist << "\n";
                return y_first_dist;
            }
        }
    }

    // Recursive calls to find the smallest distance between two points (not including split distances).
    // Remember the goal is to not do so many multiplications and only do multiplication when there are only 2 or 3 dots within the interval
    double x_delta_candidate = closest_pair_distance(new_left, new_bottom, delta);
    double y_delta_candidate = closest_pair_distance(new_right, new_top, delta);
    if (x_delta_candidate < delta){delta = x_delta_candidate;}
    if (y_delta_candidate < delta){delta = y_delta_candidate;}

    // Checking for any split pairs among the interval (x_bar - delta, x_bar + delta) in both lists
    double x_mid_value = x_list[mid].x;
    char x = 'x';
    double y_mid_value = y_list[mid].y;
    char y = 'y';

    x_delta_candidate = closest_split_pair(x_list, delta, x_mid_value, x); 
    if (x_delta_candidate < delta){delta = x_delta_candidate;}
    y_delta_candidate = closest_split_pair(y_list, delta, y_mid_value, y);
    if (y_delta_candidate < delta){delta = y_delta_candidate;}

    //DEBUG std::cout << "Returning delta(cpd): " << delta << "\n";
    return delta;
}


int main() {
    double a, b, c;
    double d;
    std::vector<point> x_sort_list;
    std::vector<point> y_sort_list;
    std::cin >> c;
    read_in_points(a, b, c, x_sort_list);
    y_sort_list = x_sort_list;
    

    std::sort(x_sort_list.begin(), x_sort_list.end(), x_sort);
    std::sort(y_sort_list.begin(), y_sort_list.end(), y_sort);
    
    double delta = 100000000;
    d = closest_pair_distance(x_sort_list, y_sort_list, delta);

    std::cout << std::setprecision(5) << std::fixed << d;
    return 0;
}
    
