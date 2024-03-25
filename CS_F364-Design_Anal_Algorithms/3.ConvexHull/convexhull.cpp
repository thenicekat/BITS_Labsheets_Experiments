// The purpose of this code is to give a list of vertices which count as the convex hull for the list of vertices

#include <bits/stdc++.h>
using namespace std;
template <typename T>

float find_median(vector<T> input)
{
    // NOTE: this is not the fastest median algorithm
    // this is nlogn
    sort(input.begin(), input.end());
    return input.size() % 2 == 1 ? input[input.size() / 2] : (float)(input[input.size() / 2 - 1] + input[input.size() / 2]) / 2;
}

vector<pair<int, int>> upperbridge(vector<pair<int, int>> vertices, float median_x_coord)
{
    cout << "::> Calling the upper bridge function" << endl;
    // We should ideally take input as T the vector and L the line
    // but here we take x = mxc as the line so we just pass the median coord
    // This should return a line
    vector<pair<int, int>> candidates;
    // If there are only 2 points then that's the upper bridge
    // otherwise we need to perform prune and search
    if (vertices.size() == 2)
    {
        return vertices;
    }
    else
    {
        vector<pair<pair<int, int>, pair<int, int>>> pairs;
        sort(vertices.begin(), vertices.end());
        if (vertices.size() % 2 == 0)
        {
            for (int i = 0; i < vertices.size(); i += 2)
            {
                pairs.push_back({vertices[i], vertices[i + 1]});
            }
        }
        else
        {
            for (int i = 0; i < vertices.size() - 1; i += 2)
            {
                pairs.push_back({vertices[i], vertices[i + 1]});
            }
            candidates.push_back(vertices[vertices.size() - 1]);
        }
        cout << "::> Printing all the pairs in arbitrarily chosen pairs such that x coordinates are in increasing order" << endl;
        for (auto x : pairs)
        {
            cout << "::> (" << x.first.first << "," << x.first.second << ")"
                 << " "
                 << "(" << x.second.first << "," << x.second.second << ")"
                 << endl;
        }

        // Now we have all the pairs -> which basically are lines
        // We have a vector which stores all slopes
        vector<float> slopes;
        for (auto pai : pairs)
        {
            pair<int, int> pi = pai.first;
            pair<int, int> pj = pai.second;

            if (pi.first == pj.first)
            {
                // We use the logic that, say two points are on the same x coordinate, then the upper one will be
                // part of the candidates and we can ELIMINATE the lower one cause it cannot be an upper bridge
                if (pi.second > pj.second)
                {
                    candidates.push_back(pi);
                }
                else
                {
                    candidates.push_back(pj);
                }
            }
            else
            {
                float slope = (float)(pi.second - pj.second) / (pi.first - pj.first);
                slopes.push_back(slope);
            }
        }

        // Find median slope
        for (auto sl : slopes)
        {
            cout << "::> Slope Found: " << sl << endl;
        }
        float median_slope = find_median(slopes);
        cout << "::> Median Slope: " << median_slope << endl;

        // split the lines into small, equal and larger slope sets
        vector<pair<pair<int, int>, pair<int, int>>> small;
        vector<pair<pair<int, int>, pair<int, int>>> equal;
        vector<pair<pair<int, int>, pair<int, int>>> large;

        for (auto pai : pairs)
        {
            pair<int, int> pi = pai.first;
            pair<int, int> pj = pai.second;

            if (pi.first != pj.first)
            {
                float slope = (float)(pi.second - pj.second) / (pi.first - pj.first);
                if (slope > median_slope)
                {
                    large.push_back(pai);
                }
                else if (slope < median_slope)
                {
                    small.push_back(pai);
                }
                else
                {
                    equal.push_back(pai);
                }
            }
        }

        // as of now we split the lines into larger slope, higher slope and equal slope
        // now we need to find a supporting line with slope as median slope
        // from here what happens is that, this line becomes the highest line
        float max_intercept = INT_MIN;
        for (auto point : vertices)
        {
            max_intercept = max(max_intercept, (point.second) - (median_slope * point.first));
        }

        cout << "::> Max Intercept: " << max_intercept << endl;
        // Now we have this line we get all points on this line
        vector<pair<int, int>> points_on_max_intercept_line;
        for (auto point : vertices)
        {
            if ((point.second) - (median_slope * point.first) == max_intercept)
            {
                points_on_max_intercept_line.push_back(point);
                cout << "::> Point on Max Intercept Line: " << point.first << "," << point.second << endl;
            }
        }
        // Now we need to find minimum point and maximum point (wrt x coordinate)
        pair<int, int> point_in_max_with_min_x = points_on_max_intercept_line[0], point_in_max_with_max_x = points_on_max_intercept_line[0];
        for (auto point : points_on_max_intercept_line)
        {
            if (point.first < point_in_max_with_min_x.first)
            {
                point_in_max_with_min_x = point;
            }
            if (point.first > point_in_max_with_max_x.first)
            {
                point_in_max_with_max_x = point;
            }
        }
        // Now it's time to eliminate points from bridge
        if (point_in_max_with_min_x.first <= median_x_coord && point_in_max_with_max_x.first > median_x_coord)
        {
            return {point_in_max_with_min_x, point_in_max_with_max_x};
        }
        else if (point_in_max_with_max_x.first <= median_x_coord)
        {
            for (auto line : large)
            {
                candidates.push_back(line.second);
            }
            for (auto line : equal)
            {
                candidates.push_back(line.second);
            }
            for (auto line : small)
            {
                candidates.push_back(line.first);
                candidates.push_back(line.second);
            }
        }
        else if (point_in_max_with_max_x.first > median_x_coord)
        {
            for (auto line : small)
            {
                candidates.push_back(line.first);
            }
            for (auto line : equal)
            {
                candidates.push_back(line.first);
            }
            for (auto line : large)
            {
                candidates.push_back(line.first);
                candidates.push_back(line.second);
            }
        }
    }
    return upperbridge(candidates, median_x_coord);
}

vector<pair<int, int>> lowerbridge(vector<pair<int, int>> vertices, float median_x_coord)
{
    cout << "::> Calling the lower bridge function" << endl;
    // We should ideally take input as T the vector and L the line
    // but here we take x = mxc as the line so we just pass the median coord
    // This should return a line
    vector<pair<int, int>> candidates;
    // If there are only 2 points then that's the lower bridge
    // otherwise we need to perform prune and search
    if (vertices.size() == 2)
    {
        return vertices;
    }
    else
    {
        vector<pair<pair<int, int>, pair<int, int>>> pairs;
        sort(vertices.begin(), vertices.end());
        if (vertices.size() % 2 == 0)
        {
            for (int i = 0; i < vertices.size(); i += 2)
            {
                pairs.push_back({vertices[i], vertices[i + 1]});
            }
        }
        else
        {
            for (int i = 0; i < vertices.size() - 1; i += 2)
            {
                pairs.push_back({vertices[i], vertices[i + 1]});
            }
            candidates.push_back(vertices[vertices.size() - 1]);
        }
        cout << "::> Printing all the pairs in arbitrarily chosen pairs such that x coordinates are in increasing order" << endl;
        for (auto x : pairs)
        {
            cout << "::> (" << x.first.first << "," << x.first.second << ")"
                 << " "
                 << "(" << x.second.first << "," << x.second.second << ")"
                 << endl;
        }

        // Now we have all the pairs -> which basically are lines
        // We have a vector which stores all slopes
        vector<float> slopes;
        for (auto pai : pairs)
        {
            pair<int, int> pi = pai.first;
            pair<int, int> pj = pai.second;

            if (pi.first == pj.first)
            {
                // We use the logic that, say two points are on the same x coordinate, then the lower one will be
                // part of the candidates and we can ELIMINATE the upper one cause it cannot be an lower bridge
                if (pi.second < pj.second)
                {
                    candidates.push_back(pi);
                }
                else
                {
                    candidates.push_back(pj);
                }
            }
            else
            {
                float slope = (float)(pi.second - pj.second) / (pi.first - pj.first);
                slopes.push_back(slope);
            }
        }

        // Find median slope
        for (auto sl : slopes)
        {
            cout << "::> Slope Found: " << sl << endl;
        }
        float median_slope = find_median(slopes);
        cout << "::> Median Slope: " << median_slope << endl;

        // split the lines into small, equal and larger slope sets
        vector<pair<pair<int, int>, pair<int, int>>> small;
        vector<pair<pair<int, int>, pair<int, int>>> equal;
        vector<pair<pair<int, int>, pair<int, int>>> large;

        for (auto pai : pairs)
        {
            pair<int, int> pi = pai.first;
            pair<int, int> pj = pai.second;

            if (pi.first != pj.first)
            {
                float slope = (float)(pi.second - pj.second) / (pi.first - pj.first);
                if (slope > median_slope)
                {
                    large.push_back(pai);
                }
                else if (slope < median_slope)
                {
                    small.push_back(pai);
                }
                else
                {
                    equal.push_back(pai);
                }
            }
        }

        // as of now we split the lines into larger slope, higher slope and equal slope
        // now we need to find a supporting line with slope as median slope
        // from here what happens is that, this line becomes the highest line
        // But here we take the minimum intercept
        float min_intercept = INT_MAX;
        for (auto point : vertices)
        {
            min_intercept = min(min_intercept, (point.second) - (median_slope * point.first));
        }

        cout << "::> Min Intercept: " << min_intercept << endl;
        // Now we have this line we get all points on this line
        vector<pair<int, int>> points_on_min_intercept_line;
        for (auto point : vertices)
        {
            if ((point.second) - (median_slope * point.first) == min_intercept)
            {
                points_on_min_intercept_line.push_back(point);
                cout << "::> Point on Min Intercept Line: " << point.first << "," << point.second << endl;
            }
        }

        // Now we need to find minimum point and maximum point (wrt x coordinate)
        pair<int, int> point_in_max_with_min_x = points_on_min_intercept_line[0], point_in_max_with_max_x = points_on_min_intercept_line[0];
        for (auto point : points_on_min_intercept_line)
        {
            if (point.first < point_in_max_with_min_x.first)
            {
                point_in_max_with_min_x = point;
            }
            if (point.first > point_in_max_with_max_x.first)
            {
                point_in_max_with_max_x = point;
            }
        }

        // Now it's time to eliminate points from bridge
        if (point_in_max_with_min_x.first <= median_x_coord && point_in_max_with_max_x.first > median_x_coord)
        {
            return {point_in_max_with_min_x, point_in_max_with_max_x};
        }
        else if (point_in_max_with_max_x.first > median_x_coord)
        {
            for (auto line : large)
            {
                candidates.push_back(line.second);
            }
            for (auto line : equal)
            {
                candidates.push_back(line.second);
            }
            for (auto line : small)
            {
                candidates.push_back(line.first);
                candidates.push_back(line.second);
            }
        }
        else if (point_in_max_with_max_x.first <= median_x_coord)
        {
            for (auto line : small)
            {
                candidates.push_back(line.first);
            }
            for (auto line : equal)
            {
                candidates.push_back(line.first);
            }
            for (auto line : large)
            {
                candidates.push_back(line.first);
                candidates.push_back(line.second);
            }
        }
    }
    return lowerbridge(candidates, median_x_coord);
}

void upperhull(pair<int, int> pmin, pair<int, int> pmax, vector<pair<int, int>> vertices)
{
    cout << "::> Running upper hull" << endl;
    // Add all the x coordinates into the vector
    vector<int> all_x_coords;
    for (auto vertice : vertices)
    {
        all_x_coords.push_back(vertice.first);
    }
    // Find median
    float median_x_coord = find_median(all_x_coords);
    // find the upper bridge line
    vector<pair<int, int>> upper_bridge = upperbridge(vertices, median_x_coord);
    cout << "::> Found Upper Bridge: " << upper_bridge[0].first << "," << upper_bridge[0].second << "->" << upper_bridge[1].first << "," << upper_bridge[1].second << endl;
}

void lowerhull(pair<int, int> pmin, pair<int, int> pmax, vector<pair<int, int>> vertices)
{
    cout << "::> Running lower hull" << endl;
    // Add all the x coordinates into the vector
    vector<int> all_x_coords;
    for (auto vertice : vertices)
    {
        all_x_coords.push_back(vertice.first);
    }
    // Find median
    float median_x_coord = find_median(all_x_coords);
    // find the lower bridge line
    vector<pair<int, int>> lower_bridge = lowerbridge(vertices, median_x_coord);
    cout << "::> Found Lower Bridge: " << lower_bridge[0].first << "," << lower_bridge[0].second << "->" << lower_bridge[1].first << "," << lower_bridge[1].second << endl;
}

void upperhull_wrapper(vector<pair<int, int>> coords)
{
    // Find points of least and max x coordinate - O(n)
    cout << "::> Finding points with least x coordinate and max x coordinate." << endl;
    pair<int, int> pmin = coords[0];
    pair<int, int> pmax = coords[0];
    for (auto coord : coords)
    {
        // Check min x coord
        if (coord.first < pmin.first)
        {
            pmin = coord;
        }
        // if x same take the one with highest y coordinate
        if (coord.first == pmin.first && coord.second > pmin.second)
        {
            pmin = coord;
        }

        // Check max x coord
        if (coord.first > pmax.first)
        {
            pmax = coord;
        }
        // if x same take the one with highest y coordinate
        if (coord.first == pmax.first && coord.second > pmax.second)
        {
            pmax = coord;
        }
    }
    cout << "::> P_min: " << pmin.first << ',' << pmin.second << endl;
    cout << "::> P_max: " << pmax.first << ',' << pmax.second << endl;

    cout << "::> Set T - which contains all the points between x(pmin) and x(pmax): " << endl;
    vector<pair<int, int>> T;
    T.push_back(pmin);
    T.push_back(pmax);
    for (auto coord : coords)
    {
        if (pmin.first < coord.first && coord.first < pmax.first)
        {
            T.push_back(coord);
            cout << "::> " << coord.first << "," << coord.second << endl;
        }
    }

    upperhull(pmin, pmax, T);
}

void lowerhull_wrapper(vector<pair<int, int>> coords)
{
    // Find points of least and max x coordinate - O(n)
    cout
        << "::> Finding points with least x coordinate and max x coordinate." << endl;
    pair<int, int> pmin = coords[0];
    pair<int, int> pmax = coords[0];
    for (auto coord : coords)
    {
        // Check min x coord
        if (coord.first < pmin.first)
        {
            pmin = coord;
        }
        // if x same take the one with lowest y coordinate
        if (coord.first == pmin.first && coord.second < pmin.second)
        {
            pmin = coord;
        }

        // Check max x coord
        if (coord.first > pmax.first)
        {
            pmax = coord;
        }
        // if x same take the one with lowest y coordinate
        if (coord.first == pmax.first && coord.second < pmax.second)
        {
            pmax = coord;
        }
    }
    cout << "::> P_min: " << pmin.first << ',' << pmin.second << endl;
    cout << "::> P_max: " << pmax.first << ',' << pmax.second << endl;

    cout << "::> Set T - which contains all the points between x(pmin) and x(pmax): " << endl;
    vector<pair<int, int>> T;
    T.push_back(pmin);
    T.push_back(pmax);
    for (auto coord : coords)
    {
        if (pmin.first < coord.first && coord.first < pmax.first)
        {
            T.push_back(coord);
            cout << "::> " << coord.first << "," << coord.second << endl;
        }
    }
    lowerhull(pmin, pmax, T);
}

int main()
{
    freopen("convexhull_input.txt", "r", stdin);
    freopen("convexhull_output.txt", "w", stdout);

    int counter;
    cin >> counter;

    for (int m = 0; m < counter; m++)
    {
        cout << "----------- TEST CASE " << m + 1 << " -----------" << endl;

        // Reading input - O(n)
        int numberOfInputs;
        cin >> numberOfInputs;
        cout << "::> Reading " << numberOfInputs << " number of coordinates." << endl;
        vector<pair<int, int>> coords(numberOfInputs);
        for (int i = 0; i < numberOfInputs; i++)
        {
            cin >> coords[i].first >> coords[i].second;
        }

        // UPPER HULL
        upperhull_wrapper(coords);

        // LOWER HULL
        lowerhull_wrapper(coords);

        cout
            << "--------- END TEST CASE "
            << " ---------" << endl;
    }
}