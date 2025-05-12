//
// Created by Alan Freitas on 2020-07-06.
//

#ifndef HAMZSTPLOTPLUSPLUS_STRING_FUNCTION_H
#define HAMZSTPLOTPLUSPLUS_STRING_FUNCTION_H

#include <hamzstplot/detail/config.h>
#include <hamzstplot/axes_objects/line.h>
#include <hamzstplot/core/line_spec.h>
#include <hamzstplot/util/handle_types.h>
#include <string>

namespace hamzstplot {
    class HAMZSTPLOT_EXPORTS string_function : public line {
      public:
        explicit string_function(class axes_type *parent);
        string_function(class axes_type *parent, std::string_view equation,
                        std::string_view line_spec = "");

        /// If we receive an axes_handle, we can convert it to a raw
        /// pointer because there is no ownership involved here
        template <class... Args>
        string_function(const axes_handle &parent, Args&&... args)
            : string_function(parent.get(), std::forward<Args>(args)...) {}

      public:
        std::string plot_string() override;
        std::string data_string() override;
        double xmax() override;
        double xmin() override;
        double ymax() override;
        double ymin() override;
        enum axes_object::axes_category axes_category() override;

      public:
        const std::string &equation() const;
        class string_function &equation(std::string_view equation);

      private:
        std::string equation_;
    };
} // namespace hamzstplot

#endif // HAMZSTPLOTPLUSPLUS_STRING_FUNCTION_H
