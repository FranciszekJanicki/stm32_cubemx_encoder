#ifndef ENCODER_HPP
#define ENCODER_HPP

#include "cnt_device.hpp"
#include "utility.hpp"
#include <cmath>
#include <cstdint>
#include <optional>
#include <utility>

namespace Encoder {

    struct Encoder {
    public:
        using CNTDevice = Utility::CNTDevice;

        [[nodiscard]] std::optional<float> get_angle_degrees() const noexcept;
        [[nodiscard]] std::optional<float> get_angle_radians() const noexcept;
        [[nodiscard]] std::optional<float> get_speed_degrees(float const sampling_time) const noexcept;
        [[nodiscard]] std::optional<float> get_speed_radians(float const sampling_time) const noexcept;

        CNTDevice cnt_device{};

        std::uint32_t counts_per_pulse{};
        std::uint32_t pulses_per_360{};

    private:
        float count_to_degrees(std::uint32_t const count) const noexcept;
        float count_to_degree_diff(std::uint32_t const count_diff) const noexcept;
    };

}; // namespace Encoder

#endif // ENCODER_HPP