#include "pch.h"
#include "V.h"

#include <vector>
#include <iostream>
#include <cassert>


V::V(std::vector<float> vec)
{
	m_vector = vec;
}

V::V(int size, float initial_data)
{
	m_vector.resize(size);
	for (auto itr = m_vector.begin(); itr != m_vector.end(); itr++) {
		*itr = initial_data;
	}
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

V & V::operator+=(const V & other)
{
	assert(this->m_vector.size() == other.m_vector.size());
	for (int i = 0; i < this->m_vector.size(); i++){
		this->m_vector[i] += other.m_vector[i];
	}
	return *this;
}

V & V::operator-=(const V & other)
{
	assert(this->m_vector.size() == other.m_vector.size());
	for (int i = 0; i < this->m_vector.size(); i++) {
		this->m_vector[i] -= other.m_vector[i];
	}
	return *this;
}

V & V::operator*=(const float & other)
{
	for (int i = 0; i < this->m_vector.size(); i++) {
		this->m_vector[i] *= other;
	}
	return *this;
}
	

V operator+(V left_op, const V & right_op)
{
	assert(left_op.m_vector.size() == right_op.m_vector.size());
	left_op += right_op;
	return left_op;
}

V operator-(V left_op, const V & right_op)
{
	assert(left_op.m_vector.size() == right_op.m_vector.size());
	left_op -= right_op;
	return left_op;
}

V operator*(V left_op, const float & right_op)
{
	left_op *= right_op;
	return left_op;
}

float operator%(const V & left_op, const V & right_op)
{
	assert(left_op.m_vector.size() == right_op.m_vector.size());

	float product = 0;
	for (int i = 0; i < left_op.m_vector.size(); i++) {
		product += (left_op.m_vector[i] * right_op.m_vector[i]);
	}
	return product;
}

std::ostream & operator<<(std::ostream & os, const V & v)
{
	for (auto itr = v.m_vector.begin(); itr != v.m_vector.end(); itr++) {
		os << *itr << " ";
	}
	return os;
}

float & V::operator[](std::size_t idx)
{
	return m_vector[idx];
}

const float & V::operator[](std::size_t idx) const
{
	return m_vector[idx];
}

size_t V::size()
{
	return this->m_vector.size();
}

size_t V::size() const
{
	return this->m_vector.size();
}

V::~V()
{
	std::cout << "In V destructor" << std::endl;
	delete &m_vector;
}
