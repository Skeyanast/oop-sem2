#pragma once

template <class Type> void Swap(Type& x, Type& y)
{
	Type z = x;
	x = y;
	y = z;
}

template <class Type> void OutXY(Type& x, Type& y)
{
	std::cout << x << " " << y << std::endl;
}