#include "measurement.h"

double average_value(const std::vector<double> data)
{
    double sum = std::accumulate(data.begin(),
        data.end(),
        0.0);
    const size_t N = data.size();
    double avg = sum / N;

    return avg;
}

double std_dev(std::vector<double> data)
{
    const size_t N = data.size();
    double avg_val = average_value(data);
    double dev_square = 0;

    for (int i = 0; i < N; i++) {
        dev_square += pow(data.at(i) - avg_val, 2);
    }
    return sqrt(dev_square / N);
}
