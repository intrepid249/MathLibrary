#include "Utility.h"

template <typename T>
/**Convert degrees to radians*/
T degToRad(T degrees)
{
	return (T)(degrees * (float)_PI_OVER_180);
}

template <typename T>
/**Convert radians to degrees*/
T radToDeg(T radians)
{
	return (T)(radians * (float)_180_OVER_PI);
}

template <typename T>
/**Calculate the centre point of a vector*/
Vector2<T> LinearHalf(const Vector2<T>& p1, const Vector2<T>& p2)
{
	return Vector2<T>( (p2.x - p1.x) / 2, (p2.y - p1.y) / 2 );
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

template Vector2<float> LinearHalf<float>(const Vector2<float>& p1, const Vector2<float>& p2);
template Vector2<int> LinearHalf<int>(const Vector2<int>& p1, const Vector2<int>& p2);
template Vector2<short> LinearHalf<short>(const Vector2<short>& p1, const Vector2<short>& p2);
template Vector2<long> LinearHalf<long>(const Vector2<long>& p1, const Vector2<long>& p2);
template Vector2<double> LinearHalf<double>(const Vector2<double>& p1, const Vector2<double>& p2);