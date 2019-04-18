#pragma once
#include <vector>
#include "V.h"

class M
{
public:
	M(std::vector<V> m);
	M(int col, int line, int initial_data = 0.0);

	M& operator=(const M& other);

	M& operator += (const M& other);
	M& operator -= (const M& other);

	friend M operator+(M left_op, const M& right_op);
	friend M operator-(M left_op, const M& right_op);

	friend M operator*(const M& left_op,const M& right_op);
	friend V operator*(const M& left_op, const V& right_op);

	V& operator[](std::size_t idx);
	const V& operator[](std::size_t idx) const;

	std::vector<size_t> size();
	std::vector<size_t> size() const;

	~M();

	std::vector<V> m_matrix;
private:
	bool checkDimension();
};

std::ostream& operator<<(std::ostream& os, const M& m);