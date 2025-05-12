//
// Created by Alan Freitas on 20/07/20.
//

#ifndef HAMZSTPLOTPLUSPLUS_GEODATA_H
#define HAMZSTPLOTPLUSPLUS_GEODATA_H

#include <hamzstplot/detail/config.h>
#include <string>
#include <vector>

namespace hamzstplot {
    HAMZSTPLOT_EXPORTS
    std::pair<std::vector<double>, std::vector<double>> &world_map_10m();
    HAMZSTPLOT_EXPORTS
    std::pair<std::vector<double>, std::vector<double>> &world_map_50m();
    HAMZSTPLOT_EXPORTS
    std::pair<std::vector<double>, std::vector<double>> &world_map_110m();

    HAMZSTPLOT_EXPORTS
    std::tuple<std::vector<double>, std::vector<double>,
               std::vector<std::string>> &
    world_cities();

    HAMZSTPLOT_EXPORTS
    std::tuple<std::vector<double>, std::vector<double>,
               std::vector<std::string>>
    world_cities(double min_x_distance_per_char, double min_y_distance);

    HAMZSTPLOT_EXPORTS
    std::tuple<std::vector<double>, std::vector<double>>
    greedy_tsp(const std::vector<double> &x, const std::vector<double> &y,
               size_t starting_city = 0);

    HAMZSTPLOT_EXPORTS
    std::tuple<std::vector<double>, std::vector<double>, std::vector<size_t>>
    greedy_tsp_with_idx(const std::vector<double> &x,
                        const std::vector<double> &y, size_t starting_city = 0);

    HAMZSTPLOT_EXPORTS
    std::tuple<std::vector<double>, std::vector<double>,
               std::vector<std::string>>
    clear_overlapping_labels(const std::vector<double> &x,
                             const std::vector<double> &y,
                             const std::vector<std::string> &names,
                             double min_x_distance_per_char,
                             double min_y_distance);

} // namespace hamzstplot

#endif // HAMZSTPLOTPLUSPLUS_GEODATA_H
