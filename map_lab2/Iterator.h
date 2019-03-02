#pragma once
#include <cstddef>

template <typename T>
class Iterator
{
public:
	virtual T operator*() const = 0;
	virtual void operator++(T) = 0;
	virtual T operator--(T) const = 0;
	virtual bool operator==(const nullptr_t) const = 0;
	virtual bool operator!=(const nullptr_t) const = 0;
};