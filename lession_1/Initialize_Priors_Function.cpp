#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//initialize priors assumimg vehicle at landmark +/- 1.0 meters position stdev
std::vector<float> initialize_priors(int map_size, std::vector<float> landmark_positions,
                                     float control_stdev);
void change_value(std::vector<float> &priors, int landmark_center, float control_stdev, float normal_val);

    int main()
{

    //set standard deviation of position:
    float control_stdev = 1.0f;

    //set map horizon distance in meters
    int map_size = 25;

    //initialize landmarks
    std::vector<float> landmark_positions{5, 10, 20};

    // initialize priors
    std::vector<float> priors = initialize_priors(map_size, landmark_positions,
                                                  control_stdev);

    //print values to stdout
    for (unsigned int p = 0; p < priors.size(); p++)
    {
        std::cout << priors[p] << endl;
    }

    return 0;
};

std::vector<float> initialize_priors(int map_size, std::vector<float> landmark_positions,
                                     float control_stdev)
{

    //initialize priors assumimg vehicle at landmark +/- 1.0 meters position stdev

    //set all priors to 0.0
    std::vector<float> priors(map_size, 0.0);

    //set each landmark positon +/1 to 1.0/9.0 (9 possible postions)
    float normalization_term = landmark_positions.size() * (control_stdev * 2 + 1);
    float normal_val = 1.0f / normalization_term;
    for (size_t i = 0; i < landmark_positions.size(); i++)
    {
        int landmark_center = landmark_positions[i];
        change_value(priors, landmark_center, control_stdev, normal_val);
    }
    return priors;
}

void change_value(std::vector<float> &priors, int landmark_center, float control_stdev, float normal_val)
{
    priors[landmark_center] = normal_val;
    for (int i = 1; i <= control_stdev; ++i) {
        priors[landmark_center - i] = normal_val;
        priors[landmark_center + i] = normal_val;
    }
}