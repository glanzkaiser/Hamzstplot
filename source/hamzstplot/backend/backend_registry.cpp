//
// Created by Alan Freitas on 26/08/20.
//

#include "backend_registry.h"

namespace hamzstplot {
    std::shared_ptr<backend::backend_interface> create_default_backend() {
        // Maybe this can change in the future depending on what
        // libraries CMake finds in the system
        return create_backend<backend::gnuplot>();
    }
} // namespace hamzstplot