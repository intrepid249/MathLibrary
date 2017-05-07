#include "Utility.h"

template <typename T>
T degToRad(T degrees)
{
	return (T)(degrees * (float)_PI_OVER_180);
}

template <typename T>
T radToDeg(T radians)
{
	return (T)(radians * (float)_180_OVER_PI);
}

template <typename T>
T LinearHalf(T x)
{
	return (T)(x * 0.5f);
}

template float degToRad<float>(float degrees);
template int degToRad<int>(int degrees);
template short degToRad<short>(short degrees);
template long degToRad<long>(long degrees);
template double degToRad<double>(double degrees);

template float radToDeg<float>(float degrees);
template int radToDeg<int>(int degrees);
template short radToDeg<short>(short degrees);
template long radToDeg<long>(long degrees);
template double radToDeg<double>(double degrees);

template float LinearHalf<float>(float degrees);
template int LinearHalf<int>(int degrees);
template short LinearHalf<short>(short degrees);
template long LinearHalf<long>(long degrees);
template double LinearHalf<double>(double degrees);