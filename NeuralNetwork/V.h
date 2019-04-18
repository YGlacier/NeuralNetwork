#pragma once

#include <vector>
#include <iostream>

/**
　+ ベクトル加算
  - ベクトル減算
  * スカラー乗算
  % 内積

*/
class V
{
public:
	V(std::vector<float> vec);
	V(int size, float initial_data = 0.0);
	V();

	V& operator=(const V& other);

	V& operator += (const V& other);
	V& operator -= (const V& other);
	V& operator *= (const float& other);

	friend V operator+(V left_op, const V& right_op);
	friend V operator-(V left_op, const V& right_op);
	friend V operator*(V left_op, const float& right_op);
	friend float operator%(const V& left_op, const V& right_op);

	float& operator[](std::size_t idx);
	const float& operator[](std::size_t idx) const;

	size_t size();
	size_t size() const;
	
	~V();

	std::vector<float> m_vector;
private:
	
};

std::ostream& operator<<(std::ostream& os, const V& v);

