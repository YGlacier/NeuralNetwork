#include "pch.h"
#include "V.h"

#include <vector>


V::V(std::vector<float> vec)
{
	m_vector = vec;
}

V::V()
{
}


V& V::operator=(const V& other) 
{
	if (this != &other) {
		this->m_vector = other.m_vector;
	}
	return *this;
}

V::~V()
{
}
