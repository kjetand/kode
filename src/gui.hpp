#pragma once

#if defined(_WIN32)
#include <imgui-SFML.h>
#include <imgui.h>

#include <SFML/Graphics.hpp>
#elif defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wsign-conversion"
#include <imgui-SFML.h>
#include <imgui.h>

#include <SFML/Graphics.hpp>
#pragma clang diagnostic pop
#else
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"
#pragma GCC diagnostic ignored "-Wold-style-cast"
#include <imgui-SFML.h>
#include <imgui.h>

#include <SFML/Graphics.hpp>
#pragma GCC diagnostic pop
#endif