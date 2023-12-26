#pragma once

#include "BnExample.h"

namespace android{
	class Example: public BnExample{
		private:
			int example_value;
			void *ptr;
		public:
			Example();
			~Example();
			int getExample();
			void setExample(int value);
	};
}
