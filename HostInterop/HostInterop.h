#pragma once

#include "../texthook/host.h"

using namespace System;

namespace HostInterop 
{
	public ref class Host
	{
	public:
		static bool Start() { return StartHost(); }
	};
}
