#pragma once
#include <vector>
#include <array>
#define MAX_COMPONENTS_COUNT 32

struct SBaseComponent;
typedef unsigned int Entity;

typedef std::vector<SBaseComponent*> ComponentArray;
typedef std::array<int, MAX_COMPONENTS_COUNT> EntityComponentArray;
