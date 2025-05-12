//
// Created by Alan Freitas on 2020-07-03.
//

#ifndef MATPLOTPLUSPLUS_MATPLOT_H
#define MATPLOTPLUSPLUS_MATPLOT_H

// Common / util
#include <hamzstplot/util/common.h>
#include <hamzstplot/util/concepts.h>
#include <hamzstplot/util/geodata.h>
#include <hamzstplot/util/handle_types.h>
#include <hamzstplot/util/type_traits.h>

// Backends
#include <hamzstplot/backend/backend_interface.h>
#include <hamzstplot/backend/backend_registry.h>
#include <hamzstplot/backend/gnuplot.h>
// #include <hamzstplot/backend/opengl_3.h> // Don't include opengl by default

// Figure and axes
#include <hamzstplot/core/axes_type.h>
#include <hamzstplot/core/axis_type.h>
#include <hamzstplot/core/figure_type.h>

// Axes objects
#include <hamzstplot/axes_objects/bars.h>
#include <hamzstplot/axes_objects/box_chart.h>
#include <hamzstplot/axes_objects/circles.h>
#include <hamzstplot/axes_objects/contours.h>
#include <hamzstplot/axes_objects/error_bar.h>
#include <hamzstplot/axes_objects/filled_area.h>
#include <hamzstplot/axes_objects/function_line.h>
#include <hamzstplot/axes_objects/histogram.h>
#include <hamzstplot/axes_objects/labels.h>
#include <hamzstplot/axes_objects/line.h>
#include <hamzstplot/axes_objects/matrix.h>
#include <hamzstplot/axes_objects/network.h>
#include <hamzstplot/axes_objects/parallel_lines.h>
#include <hamzstplot/axes_objects/stair.h>
#include <hamzstplot/axes_objects/string_function.h>
#include <hamzstplot/axes_objects/surface.h>
#include <hamzstplot/axes_objects/vectors.h>

// Free-standing functions
#include <hamzstplot/freestanding/axes_functions.h>
#include <hamzstplot/freestanding/axes_lim.h>
#include <hamzstplot/freestanding/histcounts.h>
#include <hamzstplot/freestanding/plot.h>

#endif // MATPLOTPLUSPLUS_MATPLOT_H
