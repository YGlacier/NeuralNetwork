#include "pch.h"
#include "M.h"
#include "V.h"

#include <vector>
#include <cassert>
#include <iostream>
#include <algorithm>


M::M(std::vector<V> m)
{
	this->m_matrix = m;
	assert(this->checkDimension());
}

M::M(int line, int col, int initial_data)
{
	V v(col,initial_data);
	this->m_matrix.resize(line);
	for (int i = 0; i < line; i++) {
		m_matrix[i] = v;
	}
}

M & M::operator=(const M & other)
{
	if (this != &other) {
		this->m_matrix = other.m_matrix;
	}
	return *this;
}

M & M::operator+=(const M & other)
{
	assert(this->m_matrix.size() == other.m_matrix.size());
	assert(this->m_matrix[0].size() == other.m_matrix[0].size());

	for (int i = 0; i < this->m_matrix.size(); i++) {
		for (int j = 0; j < this->m_matrix.size(); j++) {
			this->m_matrix[i][j] += other.m_matrix[i][j];
		}
	}
	return *this;
}

M & M::operator-=(const M & other)
{
	assert(this->m_matrix.size() == other.m_matrix.size());
	assert(this->m_matrix[0].size() == other.m_matrix[0].size());

	for (int i = 0; i < this->m_matrix.size(); i++) {
		for (int j = 0; j < this->m_matrix.size(); j++) {
			this->m_matrix[i][j] -= other.m_matrix[i][j];
		}
	}
	return *this;
}



V & M::operator[](std::size_t idx)
{
	return this->m_matrix[idx];
}

const V & M::operator[](std::size_t idx) const
{
	return this->m_matrix[idx];
}

std::vector<size_t> M::size()
{
	std::vector<size_t> size(2);
	size[0] = this->m_matrix.size();
	size[1] = this->m_matrix[0].size();
	return size;
}

std::vector<size_t> M::size() const
{
	std::vector<size_t> size(2);
	size[0] = this->m_matrix.size();
	size[1] = this->m_matrix[0].size();
	return size;
}

M::~M()
{
}

bool M::checkDimension()
{
	std::vector<int> dimensions;
	for (auto itr = m_matrix.begin(); itr != m_matrix.end(); itr++) {
		dimensions.push_back((int)itr->size());
	}
	return *std::max_element(dimensions.begin(), dimensions.end()) == *std::min_element(dimensions.begin(), dimensions.end());
}

M operator+(M left_op, const M & right_op)
{
	assert(left_op.m_matrix.size() == right_op.m_matrix.size());
	assert(left_op.m_matrix[0].size() == right_op.m_matrix[0].size());

	left_op += right_op;
	return left_op;
}

M operator-(M left_op, const M & right_op)
{
	assert(left_op.m_matrix.size() == right_op.m_matrix.size());
	assert(left_op.m_matrix[0].size() == right_op.m_matrix[0].size());

	left_op -= right_op;
	return left_op;
}

M operator*(const M & left_op, const M & right_op)
{
	assert(left_op.size()[1] == right_op.size()[0]);
	M result((int)left_op.size()[0], (int)right_op.size()[1]);
	for (int i = 0; i < left_op.size()[0]; i++) {
		for (int j = 0; j < right_op.size()[1]; j++) {
			float cell = 0.0;
			for (int k = 0; k < left_op.size()[1]; k++) {
				cell += (left_op[i][k] * right_op[k][j]);
			}
			result[i][j] = cell;

		}
	}
	return result;

}

V operator*(const M & left_op, const V & right_op)
{
	assert(left_op.size()[1] == right_op.size());
	V result((int)left_op.size()[0]);
	for (int i = 0; i < left_op.size()[0]; i++) {
		float cell = 0.0;
		for (int j = 0; j < left_op.size()[1]; j++) {
			cell += left_op[i][j] * right_op[j];
		}
		result[i] = cell;
	}
	return result;
}
	

std::ostream & operator<<(std::ostream & os, const M & m)
{
	for (int i = 0; i < m.m_matrix.size(); i++) {
		os << m.m_matrix[i] << std::endl;
	}
	return os;
}
