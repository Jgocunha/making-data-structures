#include "vector.h"

struct Vector3
{
	float x, y, z;

	Vector3() 
	{
		x = 0.0f;
		y = 0.0f;
		z = 0.0f;
	}
	Vector3(float scalar)
		: x(scalar), y(scalar), z(scalar) 
	{}
	
	Vector3(float x, float y, float z) 
		: x(x), y(y), z(z) 
	{}

	Vector3(const Vector3& other)
		: x(other.x), y(other.y), z(other.z)
	{
		std::cout << "Copied!" << std::endl;
	}

	Vector3(Vector3&& other) noexcept
		: x(other.x), y(other.y), z(other.z)
	{
		std::cout << "Moved!" << std::endl;
	}

	~Vector3()
	{
		std::cout << "Destroyed!" << std::endl;
	}

	Vector3& operator=(const Vector3& other)
	{
		std::cout << "Copied!" << std::endl;
		x = other.x;
		y = other.y;
		z = other.z;
		return *this;
	}

	Vector3& operator=(Vector3&& other) noexcept
	{
		std::cout << "Moved!" << std::endl;
		x = other.x;
		y = other.y;
		z = other.z;
		return *this;
	}

	void print()
	{
		std::cout << x << ", " << y << ", " << z << std::endl;
	}
};


int vectorMain()
{
	//Vector<std::string> vector;
	//vector.pushBack("str1");
	//vector.pushBack("str2");
	//vector.pushBack("str3");
	//vector.pushBack("str4");
	//vector.pushBack("str5");

	//printVector(vector);
	
	Vector<Vector3> vector3;
	vector3.pushBack(Vector3(1.0f, 2.0f, 3.0f));
	vector3.pushBack(Vector3());
	vector3.pushBack(Vector3(4.0f));

	for(size_t i = 0; i < vector3.getSize(); i++)
		vector3[i].print();

	Vector<Vector3> vector3_2;
	vector3_2.emplaceBack(1.0f, 2.0f, 3.0f);
	vector3_2.emplaceBack();
	vector3_2.emplaceBack(4.0f);
	vector3_2.emplaceBack(3.0f, 2.0f, 1.0f);
	
	for (size_t i = 0; i < vector3_2.getSize(); i++)
		vector3_2[i].print();

	vector3_2.popBack();
	vector3_2.popBack();

	for (size_t i = 0; i < vector3_2.getSize(); i++)
		vector3_2[i].print();
	
	vector3_2.emplaceBack();
	vector3_2.emplaceBack(1.0f);
	for (size_t i = 0; i < vector3_2.getSize(); i++)
		vector3_2[i].print();

	vector3_2.clear();

	for (size_t i = 0; i < vector3_2.getSize(); i++)
		vector3_2[i].print();
	
	return 0;
}
