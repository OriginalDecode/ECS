#pragma once
#include "EntityTypes.h"
#include "TypeID.h"

template<typename... Args>
struct TypeList { };

template<typename... Args>
struct Requires : TypeList<Args...> { };

template<typename... Args>
struct Excludes : TypeList<Args...> { };

template<typename... Args>
static void Types(EntityComponentArray&, TypeList<Args...>) { };

template<typename T, typename... Args>
static void Types(EntityComponentArray& components, TypeList<T, Args...>)
{
	components[CTypeID<SBaseComponent>::GetID<T>()] = 1;
	Types(components, TypeList<Args...>());
};

struct CComponentFilter
{
public:
	CComponentFilter()
	{
		for (int i = 0; i < MAX_COMPONENTS_COUNT; i++)
		{
			m_Requires[i] = 0;
			m_Excludes[i] = 0;
		}
	}

	CComponentFilter(const EntityComponentArray& requiredComponents, const EntityComponentArray& excludedComponents)
		: m_Requires(requiredComponents)
		, m_Excludes(excludedComponents)
	{
	}

	bool operator==(const CComponentFilter& other)
	{
		return ((*this).m_Requires == other.m_Requires);
	}

	
	bool Compare(const EntityComponentArray& components)
	{
		for (int i = 0; i < MAX_COMPONENTS_COUNT; i++)
		{
			if (m_Requires[i] == 1 && components[i] == -1)
				return false;

			if (m_Excludes[i] == 1 && components[i] != -1)
				return false;
		}

		return true;
	}

private:
	EntityComponentArray m_Requires;
	EntityComponentArray m_Excludes;

};

template<typename RequireList, typename ExcludeList = Excludes<>>
CComponentFilter CreateFilter()
{
	EntityComponentArray requires;
	EntityComponentArray excludes;

	for (int i = 0; i < MAX_COMPONENTS_COUNT; i++)
	{
		requires[i] = 0;
		excludes[i] = 0;
	}

	Types(requires, RequireList{});
	Types(excludes, ExcludeList{});

	return CComponentFilter(requires, excludes);
}

