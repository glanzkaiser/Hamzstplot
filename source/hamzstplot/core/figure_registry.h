//
// Created by Alan Freitas on 04/08/20.
//

#ifndef HAMZSTPLOTPLUSPLUS_FIGURE_REGISTRY_H
#define HAMZSTPLOTPLUSPLUS_FIGURE_REGISTRY_H

#include <hamzstplot/detail/config.h>
#include <hamzstplot/core/figure_type.h>

namespace hamzstplot {
    using figure_handle = std::shared_ptr<figure_type>;

    /// \brief Create a new figure
    HAMZSTPLOT_EXPORTS
    figure_handle figure_no_backend(bool quiet_mode);

    /// \brief Create a new figure with a given backend
    template <class BACKEND = backend::gnuplot>
    figure_handle figure(bool quiet_mode) {
        std::shared_ptr<backend::backend_interface> b =
            create_backend<BACKEND>();
        figure_handle f = figure_no_backend(quiet_mode);
        f->backend(b);
        return f;
    }

    /// \brief Create a new figure (reactive mode)
    template <class BACKEND = backend::gnuplot> figure_handle figure() {
        /// Take default mode from backend?
        return figure<BACKEND>(false);
    }

    /// \brief Set the current figure
    HAMZSTPLOT_EXPORTS
    figure_handle figure(figure_handle h);

    /// \brief Set the current figure
    HAMZSTPLOT_EXPORTS
    figure_handle figure(class figure_type *h);

    /// \brief Get the current figure
    HAMZSTPLOT_EXPORTS
    figure_handle gcf();

    /// \brief Get current figure in quiet mode
    HAMZSTPLOT_EXPORTS
    figure_handle gcf(bool quiet);

} // namespace hamzstplot

#endif // HAMZSTPLOTPLUSPLUS_FIGURE_REGISTRY_H
