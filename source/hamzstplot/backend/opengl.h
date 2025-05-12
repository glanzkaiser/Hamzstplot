//
// Created by Alan Freitas on 26/08/20.
//

#ifndef HAMZSTPLOTPLUSPLUS_OPENGL_H
#define HAMZSTPLOTPLUSPLUS_OPENGL_H

#include <hamzstplot/detail/config.h>
#include <hamzstplot/backend/opengl_embed.h>
#include <mutex>
#include <thread>

namespace hamzstplot::backend {
    class HAMZSTPLOT_EXPORTS opengl : public opengl_embed {
      public:
        opengl();
        ~opengl();

      public:
        bool new_frame() override;
        bool render_data() override;
        void show(hamzstplot::figure_type *) override;
        bool should_close() override;
        void window_title(const std::string& title) override;
        std::string window_title() override;

      public:
        static constexpr unsigned int default_screen_width = 560;
        static constexpr unsigned int default_screen_height = 420;
        static void initialize_glfw();
        static double get_time();
      private:
        GLFWwindow *window_;
        std::string window_title_;
        std::mutex this_window_in_context_;
        static bool glfw_is_initialized;
    };
} // namespace hamzstplot::backend

#endif // HAMZSTPLOTPLUSPLUS_OPENGL_H
