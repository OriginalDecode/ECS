#pragma once

template<typename BaseType>
class CTypeID
{
public:
	template<typename T>
	static unsigned int GetID()
	{
		static const unsigned int id = m_NextID++;
		return id;
	}
private:
	static unsigned int m_NextID;
};

template<typename BaseType>
unsigned int CTypeID<BaseType>::m_NextID = 0;