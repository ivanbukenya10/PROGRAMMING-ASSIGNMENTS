/*
 * Buffer Analysis
 * Creates buffers of different sizes around a center point and determines
 * which points from a given set fall within each buffer.
 * Distance is computed using the Haversine formula (great-circle distance
 * in km), which is appropriate for lat/lon coordinates.
 */
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <iomanip>

struct Point {
    std::string name;
    double lat;
    double lon;
};

const double EARTH_RADIUS_KM = 6371.0;

double toRadians(double degrees) {
    return degrees * M_PI / 180.0;
}

// Great-circle distance between two (lat, lon) points, in km
double haversineDistance(double lat1, double lon1, double lat2, double lon2) {
    double rLat1 = toRadians(lat1);
    double rLon1 = toRadians(lon1);
    double rLat2 = toRadians(lat2);
    double rLon2 = toRadians(lon2);

    double dLat = rLat2 - rLat1;
    double dLon = rLon2 - rLon1;

    double a = std::sin(dLat / 2) * std::sin(dLat / 2) +
               std::cos(rLat1) * std::cos(rLat2) *
               std::sin(dLon / 2) * std::sin(dLon / 2);
    double c = 2 * std::atan2(std::sqrt(a), std::sqrt(1 - a));

    return EARTH_RADIUS_KM * c;
}

// For each buffer size, list the points that fall within it (with distance)
std::vector<std::vector<std::pair<Point, double>>> createBuffers(
    double centerLat, double centerLon,
    std::vector<double> bufferSizesKm,
    const std::vector<Point>& points)
{
    std::sort(bufferSizesKm.begin(), bufferSizesKm.end());

    std::vector<std::vector<std::pair<Point, double>>> results(bufferSizesKm.size());

    for (const auto& point : points) {
        double dist = haversineDistance(centerLat, centerLon, point.lat, point.lon);

        for (size_t i = 0; i < bufferSizesKm.size(); ++i) {
            if (dist <= bufferSizesKm[i]) {
                results[i].push_back({point, dist});
            }
        }
    }

    return results;
}

void printResults(double centerLat, double centerLon,
                   const std::vector<double>& bufferSizesKm,
                   const std::vector<std::vector<std::pair<Point, double>>>& results)
{
    std::cout << "Center point: (" << centerLat << ", " << centerLon << ")\n\n";

    for (size_t i = 0; i < bufferSizesKm.size(); ++i) {
        std::cout << "--- Buffer: " << bufferSizesKm[i] << " km ---\n";
        if (results[i].empty()) {
            std::cout << "  (no points within this buffer)\n";
        } else {
            for (const auto& [point, dist] : results[i]) {
                std::cout << "  " << point.name << ": "
                          << std::fixed << std::setprecision(3)
                          << dist << " km from center\n";
            }
        }
        std::cout << "\n";
    }
}

int main() {
    // Example data — replace with your own center, buffer sizes, and points
    double centerLat = 0.3476;
    double centerLon = 32.5825; // example: Kampala, Uganda

    std::vector<double> bufferSizes = {1, 3, 5}; // in km

    std::vector<Point> points = {
        {"Water Point A", 0.3490, 32.5830},
        {"Water Point B", 0.3600, 32.6000},
        {"Water Point C", 0.4000, 32.6500},
        {"Water Point D", 0.3480, 32.5828}
    };

    auto results = createBuffers(centerLat, centerLon, bufferSizes, points);
    printResults(centerLat, centerLon, bufferSizes, results);

    return 0;
}
