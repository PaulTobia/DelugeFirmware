#include "blocks/gain_ramp.hpp"
#include "util/functions.h"
#include <cppspec.hpp>

std::ostream& operator<<(std::ostream& os, const StereoFloatSample& sample) {
	return os << "StereoSampleFloat{" << sample.l << ", " << sample.r << "}";
}

// clang-format off
describe gain_ramp("Gain Ramp", $ {
	using namespace deluge::dsp;
	it("processes a block of mono samples", _ {
		blocks::GainRamp gain_ramp{0.0f, 1.0f};
		std::array<float, 3> in = {1.f, 1.f, 1.f};
		std::array<float, 3> out;
		gain_ramp.processBlock(in, out);
		expect(out).to_equal(std::vector<float>{0.0f, 0.5f, 1.0f});
	});

	it("processes a block of stereo samples", _ {
		blocks::GainRamp gain_ramp{0.0f, 1.0f};
		std::array<StereoFloatSample, 3> in = {StereoFloatSample{1.0f, 1.0f}, StereoFloatSample{1.0f, 1.0f}, StereoFloatSample{1.0f, 1.0f}};
		std::array<StereoFloatSample, 3> out;
		gain_ramp.processBlock(in, out);
		expect(out).to_equal(std::array{StereoFloatSample{0.0f, 0.0f}, StereoFloatSample{0.5f, 0.5f}, StereoFloatSample{1.0f, 1.0f}});
	});
});
