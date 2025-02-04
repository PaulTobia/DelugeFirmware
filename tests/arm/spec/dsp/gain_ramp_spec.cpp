#include "blocks/gain_ramp.hpp"
#include <cppspec.hpp>

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
		std::array<StereoFloatSample, 3> in = {{1.f, 1.f}, {1.f, 1.f}, {1.f, 1.f}};
		std::array<StereoFloatSample, 3> out;
		gain_ramp.processBlock(in, out);
		expect(out).to_equal(std::array<StereoFloatSample, 3>{{0.0f, 0.0f}, {0.5f, 0.5f}, {1.0f, 1.0f}});
	});
});
