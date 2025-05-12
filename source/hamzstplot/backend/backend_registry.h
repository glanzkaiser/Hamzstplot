//
// Created by Alan Freitas on 26/08/20.
//

#ifndef HAMZSTPLOTPLUSPLUS_BACKEND_REGISTRY_H
#define HAMZSTPLOTPLUSPLUS_BACKEND_REGISTRY_H

#include <hamzstplot/detail/config.h>
#include <hamzstplot/backend/backend_interface.h>
#include <hamzstplot/backend/gnuplot.h>
#include <stdexcept>

namespace hamzstplot {
    template <class BACKEND_TYPE, class ... Args>
    std::shared_ptr<backend::backend_interface> create_backend(Args&&... args) {
        if constexpr (std::is_base_of_v<backend::backend_interface,
                                        BACKEND_TYPE>) {
            std::shared_ptr<BACKEND_TYPE> dp = std::make_shared<BACKEND_TYPE>(std::forward<Args>(args)...);
            std::shared_ptr<backend::backend_interface> bp =
                std::dynamic_pointer_cast<backend::backend_interface>(dp);
            return bp;
        } else {
            throw std::invalid_argument(
                std::string("The class ") + typeid(BACKEND_TYPE).name() +
                " does not derive from backend::backend_interface");
        }
    }

    HAMZSTPLOT_EXPORTS
    std::shared_ptr<backend::backend_interface> create_default_backend();
} // namespace hamzstplot

#endif // HAMZSTPLOTPLUSPLUS_BACKEND_REGISTRY_H
