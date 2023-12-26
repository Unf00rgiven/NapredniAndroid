#pragma once
#include <../libbinderexample/BnExample.h>

namespace android {
	class Benchmark : public BnExample {
		public:
			Benchmark();
			~Benchmark();
			int exec(String16 &command);
	};
}
