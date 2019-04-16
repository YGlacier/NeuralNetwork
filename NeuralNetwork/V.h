#pragma once

#include <vector>

class V
{
public:
	V(std::vector<float> vec);
	V();

	V& operator=(const V& other);
	
	~V();

	std::vector<float> m_vector;
private:
	
};

